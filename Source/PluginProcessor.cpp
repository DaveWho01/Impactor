#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "PluginParameters.h"

//==============================================================================
ImpactorAudioProcessor::ImpactorAudioProcessor()
     : AudioProcessor (BusesProperties()
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                       .withInput  ("SideChain", juce::AudioChannelSet::stereo(), false)
                       ),
    parameters(*this, nullptr, "ImpactorParameters", Parameters::createParameterLayout())
{
    Parameters::addListenerToAllParameters(parameters, this);
}

ImpactorAudioProcessor::~ImpactorAudioProcessor()
{
}

//==============================================================================
const juce::String ImpactorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ImpactorAudioProcessor::acceptsMidi() const
{
    return false;
}

bool ImpactorAudioProcessor::producesMidi() const
{
    return false;
}

bool ImpactorAudioProcessor::isMidiEffect() const
{
    return false;
}

double ImpactorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ImpactorAudioProcessor::getNumPrograms()
{
    return 1;
}

int ImpactorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ImpactorAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String ImpactorAudioProcessor::getProgramName (int index)
{
    return {};
}

void ImpactorAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void ImpactorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    auxBuffer.setSize(2, samplesPerBlock);
    auxBuffer.clear();
    inputGain.prepareToPlay(sampleRate);
    dryWet.prepareToPlay(sampleRate, samplesPerBlock);
    peakDetector.prepareToPlay(sampleRate);
    gainComputer.prepareToPlay(sampleRate);
    gainControl.prepareToPlay(sampleRate);
    makeupGain.prepareToPlay(sampleRate);

    inputMeterEnvelope.set(0.0f);
    grMeterEnvelope.set(0.0f);
    outputMeterEnvelope.set(0.0f);
}

void ImpactorAudioProcessor::releaseResources()
{
    inputGain.releaseResources();
    dryWet.releaseResources();
    peakDetector.releaseResources();
    auxBuffer.setSize(0, 0);
    gainComputer.releaseResources();
    gainControl.releaseResources();
    makeupGain.releaseResources();
}

bool ImpactorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    if (layouts.inputBuses[1] != juce::AudioChannelSet::mono()
        && layouts.inputBuses[1] != juce::AudioChannelSet::stereo()
        && layouts.inputBuses[1] != juce::AudioChannelSet::disabled())
        return false;
    
    return true;
}

void ImpactorAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto numSamples = buffer.getNumSamples();
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    auto mainBuffer = getBusBuffer(buffer, true, 0);
    auto scBuffer = getBusBuffer(buffer, true, 1);
    
    dryWet.copyDrySignal(mainBuffer);

    inputGain.processBlock(mainBuffer);
    
    // Input Metering
    inputMeterEnvelope.set(jmax(inputMeterEnvelope.get(), mainBuffer.getMagnitude(0, numSamples)));

    AudioBuffer<float>& scSource = scBuffer.getNumChannels() ? scBuffer : mainBuffer;
    const int numScChannels = scSource.getNumChannels();

    auxBuffer.clear();
    for (int ch = 0; ch < numScChannels; ++ch)
        auxBuffer.addFrom(ch, 0, scSource, ch, 0, numSamples, 1.0f);
    
    peakDetector.processBlock(auxBuffer);
    
    gainComputer.processBlock(auxBuffer);

    gainControl.processBlock(mainBuffer, auxBuffer);
    
    // Gain reduction Metering
    grMeterEnvelope.set(auxBuffer.getMagnitude(0, auxBuffer.getNumSamples()));
    

    makeupGain.processBlock(mainBuffer);
    
    // Output Metering
    outputMeterEnvelope.set(jmax(outputMeterEnvelope.get(), mainBuffer.getMagnitude(0, numSamples)));
    
    dryWet.merge(mainBuffer);
;}

//==============================================================================
bool ImpactorAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* ImpactorAudioProcessor::createEditor()
{
    return new PluginEditor(*this, parameters);
}

//==============================================================================
void ImpactorAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void ImpactorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(ValueTree::fromXml(*xmlState));
}

void ImpactorAudioProcessor::parameterChanged(const String& paramID, float newValue)
{
    if (paramID == Parameters::nameAttackTime)
        peakDetector.setAttack(newValue);

    if (paramID == Parameters::nameReleaseTime)
        peakDetector.setRelease(newValue);

    if (paramID == Parameters::nameInputGain)
        inputGain.setGain(newValue);

    if (paramID == Parameters::nameMakeupGain)
        makeupGain.setGain(newValue);

    if (paramID == Parameters::nameThreshold)
        gainComputer.setThreshold(newValue);

    if (paramID == Parameters::nameRatio)
        gainComputer.setRatio(newValue);

    if (paramID == Parameters::nameKnee)
        gainComputer.setKnee(newValue);

    if (paramID == Parameters::nameDryWetRatio)
        dryWet.setDryWetRatio(newValue);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ImpactorAudioProcessor();
}
