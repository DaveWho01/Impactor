#pragma once

#include <JuceHeader.h>
#include "Detector.h"
#include "GainStage.h"
#include "GainComputer.h"
#include "GainControl.h"
#include "DryWet.h"



class ImpactorAudioProcessor  : public juce::AudioProcessor, public AudioProcessorValueTreeState::Listener
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    ImpactorAudioProcessor();
    ~ImpactorAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    Atomic<float> inputMeterEnvelope;
    Atomic<float> outputMeterEnvelope;
    Atomic<float> grMeterEnvelope;

private:
    
    void parameterChanged(const String& paramID, float newValue) override;
    AudioProcessorValueTreeState parameters;

    AudioBuffer<float> auxBuffer;

    GainStage inputGain;
    Detector peakDetector;
    GainComputer gainComputer;
    GainControl gainControl;
    GainStage makeupGain;
    DryWet dryWet;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImpactorAudioProcessor)
};
