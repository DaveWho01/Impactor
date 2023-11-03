/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...

#include "PluginParameters.h"

//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (ImpactorAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), processor(p),
      valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    inputGainSlider.reset (new juce::Slider ("Input Gain"));
    addAndMakeVisible (inputGainSlider.get());
    inputGainSlider->setRange (0, 10, 0);
    inputGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    inputGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 100, 20);
    inputGainSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x0042a2c8));
    inputGainSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x008e989b));
    inputGainSlider->addListener (this);

    inputGainSlider->setBounds (29, 157, 56, 248);

    thresholdSlider.reset (new juce::Slider ("Threshold"));
    addAndMakeVisible (thresholdSlider.get());
    thresholdSlider->setRange (0, 10, 0);
    thresholdSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    thresholdSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    thresholdSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x0042a2c8));
    thresholdSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x008e989b));
    thresholdSlider->addListener (this);

    thresholdSlider->setBounds (70, 450, 135, 112);

    ratioSlider.reset (new juce::Slider ("Ratio"));
    addAndMakeVisible (ratioSlider.get());
    ratioSlider->setRange (0, 10, 0);
    ratioSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    ratioSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    ratioSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x0042a2c8));
    ratioSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x008e989b));
    ratioSlider->addListener (this);

    ratioSlider->setBounds (205, 450, 135, 112);

    kneeSlider.reset (new juce::Slider ("Knee"));
    addAndMakeVisible (kneeSlider.get());
    kneeSlider->setRange (0, 10, 0);
    kneeSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    kneeSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    kneeSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x0042a2c8));
    kneeSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x008e989b));
    kneeSlider->addListener (this);

    kneeSlider->setBounds (340, 450, 135, 112);

    attackSlider.reset (new juce::Slider ("Attack"));
    addAndMakeVisible (attackSlider.get());
    attackSlider->setRange (0, 10, 0);
    attackSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    attackSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    attackSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x0042a2c8));
    attackSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x008e989b));
    attackSlider->addListener (this);

    attackSlider->setBounds (525, 450, 135, 112);

    releaseSlider.reset (new juce::Slider ("Release"));
    addAndMakeVisible (releaseSlider.get());
    releaseSlider->setRange (0, 10, 0);
    releaseSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    releaseSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    releaseSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x0042a2c8));
    releaseSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x008e989b));
    releaseSlider->addListener (this);

    releaseSlider->setBounds (660, 450, 135, 112);

    makeupSlider.reset (new juce::Slider ("Makeup Gain"));
    addAndMakeVisible (makeupSlider.get());
    makeupSlider->setRange (0, 10, 0);
    makeupSlider->setSliderStyle (juce::Slider::LinearVertical);
    makeupSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 100, 20);
    makeupSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x0042a2c8));
    makeupSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x008e989b));
    makeupSlider->addListener (this);

    makeupSlider->setBounds (94, 157, 56, 248);

    inputMeter.reset (new Meter());
    addAndMakeVisible (inputMeter.get());
    inputMeter->setName ("inputMeter");

    inputMeter->setBounds (859, 155, 25, 241);

    outputMeter.reset (new Meter());
    addAndMakeVisible (outputMeter.get());
    outputMeter->setName ("outputMeter");

    outputMeter->setBounds (935, 155, 25, 241);

    grMeter.reset (new GrMeter());
    addAndMakeVisible (grMeter.get());
    grMeter->setName ("grMeter");

    grMeter->setBounds (897, 155, 25, 241);

    inputMeterLabel.reset (new MeterLabel());
    addAndMakeVisible (inputMeterLabel.get());
    inputMeterLabel->setName ("inputMeterLabel");

    inputMeterLabel->setBounds (856, 399, 31, 14);

    outputMeterLabel.reset (new MeterLabel());
    addAndMakeVisible (outputMeterLabel.get());
    outputMeterLabel->setName ("outputMeterLabel");

    outputMeterLabel->setBounds (932, 399, 31, 14);

    grMeterLabel.reset (new GrMeterLabel());
    addAndMakeVisible (grMeterLabel.get());
    grMeterLabel->setName ("grMeterLabel");

    grMeterLabel->setBounds (894, 399, 31, 14);

    inputAudioVisualizer.reset (new AudioVisualizer());
    addAndMakeVisible (inputAudioVisualizer.get());
    inputAudioVisualizer->setName ("inputAudioVisualizer");

    inputAudioVisualizer->setBounds (243, 121, 514, 298);

    outputAudioVisualizer.reset (new AudioVisualizer());
    addAndMakeVisible (outputAudioVisualizer.get());
    outputAudioVisualizer->setName ("outputAudioVisualizer");

    outputAudioVisualizer->setBounds (243, 121, 514, 298);

    dryWetSlider.reset (new juce::Slider ("Drywet"));
    addAndMakeVisible (dryWetSlider.get());
    dryWetSlider->setRange (0, 10, 0);
    dryWetSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    dryWetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    dryWetSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x0042a2c8));
    dryWetSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x008e989b));
    dryWetSlider->addListener (this);

    dryWetSlider->setBounds (795, 450, 135, 112);


    //[UserPreSize]
    inputGainAttachment.reset(new SliderAttachment(valueTreeState, Parameters::nameInputGain, *inputGainSlider));
    makeupGainAttachment.reset(new SliderAttachment(valueTreeState, Parameters::nameMakeupGain, *makeupSlider));
    thresholdAttachment.reset(new SliderAttachment(valueTreeState, Parameters::nameThreshold, *thresholdSlider));
    ratioAttachment.reset(new SliderAttachment(valueTreeState, Parameters::nameRatio, *ratioSlider));
    kneeAttachment.reset(new SliderAttachment(valueTreeState, Parameters::nameKnee, *kneeSlider));
    attackAttachment.reset(new SliderAttachment(valueTreeState, Parameters::nameAttackTime, *attackSlider));
    releaseAttachment.reset(new SliderAttachment(valueTreeState, Parameters::nameReleaseTime, *releaseSlider));
    dryWetAttachment.reset(new SliderAttachment(valueTreeState, Parameters::nameDryWetRatio, *dryWetSlider));

    inputMeter->connectTo(p.inputMeterEnvelope);
    inputMeterLabel->connectTo(p.inputMeterEnvelope);

    grMeter->connectTo(p.grMeterEnvelope);
    grMeterLabel->connectTo(p.grMeterEnvelope);

    outputMeter->connectTo(p.outputMeterEnvelope);
    outputMeterLabel->connectTo(p.outputMeterEnvelope);

    inputAudioVisualizer->setColour(Colour::fromRGBA(76, 76, 90, 255));
    inputAudioVisualizer->connectTo(p.inputMeterEnvelope);

    outputAudioVisualizer->setColour(Colour::fromRGBA(254, 254, 254, 255));
    outputAudioVisualizer->connectTo(p.outputMeterEnvelope);

    this->setLookAndFeel(&impactorTheme);

    inputGainSlider->setTextValueSuffix(" dB");
    makeupSlider->setTextValueSuffix(" dB");
    thresholdSlider->setTextValueSuffix(" dB");
    ratioSlider->setTextValueSuffix(":1");
    kneeSlider->setTextValueSuffix(" dB");
    attackSlider->setTextValueSuffix(" ms");
    releaseSlider->setTextValueSuffix(" ms");
    dryWetSlider->setTextValueSuffix("%");

    //[/UserPreSize]

    setSize (1000, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

    inputGainAttachment.reset();
    makeupGainAttachment.reset();
    thresholdAttachment.reset();
    ratioAttachment.reset();
    kneeAttachment.reset();
    attackAttachment.reset();
    releaseAttachment.reset();
    dryWetAttachment.reset();

    this->setLookAndFeel(nullptr);

    //[/Destructor_pre]

    inputGainSlider = nullptr;
    thresholdSlider = nullptr;
    ratioSlider = nullptr;
    kneeSlider = nullptr;
    attackSlider = nullptr;
    releaseSlider = nullptr;
    makeupSlider = nullptr;
    inputMeter = nullptr;
    outputMeter = nullptr;
    grMeter = nullptr;
    inputMeterLabel = nullptr;
    outputMeterLabel = nullptr;
    grMeterLabel = nullptr;
    inputAudioVisualizer = nullptr;
    outputAudioVisualizer = nullptr;
    dryWetSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..



    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff191835));

    {
        int x = 0, y = 436, width = 1000, height = 4;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = 440, width = 500, height = 80;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 0.0f + x,
                                             440.0f - 440.0f + y,
                                             fillColour2,
                                             500.0f - 0.0f + x,
                                             520.0f - 440.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = 520, width = 500, height = 80;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 0.0f + x,
                                             600.0f - 520.0f + y,
                                             fillColour2,
                                             500.0f - 0.0f + x,
                                             520.0f - 520.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 500, y = 440, width = 500, height = 80;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             1000.0f - 500.0f + x,
                                             440.0f - 440.0f + y,
                                             fillColour2,
                                             500.0f - 500.0f + x,
                                             520.0f - 440.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 500, y = 520, width = 500, height = 80;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             1000.0f - 500.0f + x,
                                             600.0f - 520.0f + y,
                                             fillColour2,
                                             500.0f - 500.0f + x,
                                             520.0f - 520.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 205 - 135, y = 555, width = 135, height = 40;
        juce::String text (TRANS("THRESHOLD"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 24.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 340 - 135, y = 555, width = 135, height = 40;
        juce::String text (TRANS("RATIO"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 24.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 475 - 135, y = 555, width = 135, height = 40;
        juce::String text (TRANS("KNEE"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 24.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 660 - 135, y = 555, width = 135, height = 40;
        juce::String text (TRANS("ATTACK"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 24.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 795 - 135, y = 555, width = 135, height = 40;
        juce::String text (TRANS("RELEASE"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 24.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 0, y = 0, width = 500, height = 50;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 0.0f + x,
                                             0.0f - 0.0f + y,
                                             fillColour2,
                                             500.0f - 0.0f + x,
                                             50.0f - 0.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = 50, width = 500, height = 50;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 0.0f + x,
                                             100.0f - 50.0f + y,
                                             fillColour2,
                                             500.0f - 0.0f + x,
                                             50.0f - 50.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 500, y = 0, width = 500, height = 50;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             1000.0f - 500.0f + x,
                                             0.0f - 0.0f + y,
                                             fillColour2,
                                             500.0f - 500.0f + x,
                                             50.0f - 0.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 500, y = 50, width = 500, height = 50;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             1000.0f - 500.0f + x,
                                             100.0f - 50.0f + y,
                                             fillColour2,
                                             500.0f - 500.0f + x,
                                             50.0f - 50.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = 100, width = 1000, height = 4;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 700 - 400, y = 0, width = 400, height = 100;
        juce::String text (TRANS("IMPACTOR"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 43.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.040f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 0, y = 104, width = 500, height = 166;
        juce::Colour fillColour1 = juce::Colour (0xff0e0d1c), fillColour2 = juce::Colour (0xff191835);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 0.0f + x,
                                             104.0f - 104.0f + y,
                                             fillColour2,
                                             500.0f - 0.0f + x,
                                             270.0f - 104.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 90, y = 124, width = 70, height = 146;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             160.0f - 90.0f + x,
                                             124.0f - 124.0f + y,
                                             fillColour2,
                                             90.0f - 90.0f + x,
                                             270.0f - 124.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 20, y = 124, width = 70, height = 146;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             20.0f - 20.0f + x,
                                             124.0f - 124.0f + y,
                                             fillColour2,
                                             90.0f - 20.0f + x,
                                             270.0f - 124.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = 270, width = 500, height = 166;
        juce::Colour fillColour1 = juce::Colour (0xff0e0d1c), fillColour2 = juce::Colour (0xff191835);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 0.0f + x,
                                             436.0f - 270.0f + y,
                                             fillColour2,
                                             500.0f - 0.0f + x,
                                             270.0f - 270.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 90, y = 270, width = 70, height = 146;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             160.0f - 90.0f + x,
                                             416.0f - 270.0f + y,
                                             fillColour2,
                                             90.0f - 90.0f + x,
                                             270.0f - 270.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 20, y = 270, width = 70, height = 146;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             20.0f - 20.0f + x,
                                             416.0f - 270.0f + y,
                                             fillColour2,
                                             90.0f - 20.0f + x,
                                             270.0f - 270.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 500, y = 104, width = 500, height = 166;
        juce::Colour fillColour1 = juce::Colour (0xff0e0d1c), fillColour2 = juce::Colour (0xff191835);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             1000.0f - 500.0f + x,
                                             104.0f - 104.0f + y,
                                             fillColour2,
                                             500.0f - 500.0f + x,
                                             270.0f - 104.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 500, y = 270, width = 500, height = 166;
        juce::Colour fillColour1 = juce::Colour (0xff0e0d1c), fillColour2 = juce::Colour (0xff191835);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             1000.0f - 500.0f + x,
                                             436.0f - 270.0f + y,
                                             fillColour2,
                                             500.0f - 500.0f + x,
                                             270.0f - 270.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 20, y = 121, width = 143, height = 3;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 160, y = 124, width = 3, height = 292;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 17, y = 121, width = 3, height = 296;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 17, y = 416, width = 146, height = 3;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 156 - 66, y = 128, width = 66, height = 30;
        juce::String text (TRANS("MAKEUP"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 13.10f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 90 - 66, y = 128, width = 66, height = 30;
        juce::String text (TRANS("INPUT"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 13.10f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 90 - 66, y = 140, width = 66, height = 30;
        juce::String text (TRANS("GAIN"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 13.10f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 156 - 66, y = 140, width = 66, height = 30;
        juce::String text (TRANS("GAIN"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 13.10f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 840, y = 124, width = 70, height = 146;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             840.0f - 840.0f + x,
                                             124.0f - 124.0f + y,
                                             fillColour2,
                                             910.0f - 840.0f + x,
                                             270.0f - 124.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 910, y = 124, width = 70, height = 146;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             980.0f - 910.0f + x,
                                             124.0f - 124.0f + y,
                                             fillColour2,
                                             910.0f - 910.0f + x,
                                             270.0f - 124.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 840, y = 270, width = 70, height = 146;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             840.0f - 840.0f + x,
                                             416.0f - 270.0f + y,
                                             fillColour2,
                                             910.0f - 840.0f + x,
                                             270.0f - 270.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 910, y = 270, width = 70, height = 146;
        juce::Colour fillColour1 = juce::Colour (0xff191835), fillColour2 = juce::Colour (0xff333171);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             980.0f - 910.0f + x,
                                             416.0f - 270.0f + y,
                                             fillColour2,
                                             910.0f - 910.0f + x,
                                             270.0f - 270.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 979, y = 124, width = 3, height = 292;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 837, y = 416, width = 145, height = 3;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 837, y = 121, width = 3, height = 296;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 840, y = 121, width = 142, height = 3;
        juce::Colour fillColour = juce::Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 886 - 29, y = 128, width = 29, height = 28;
        juce::String text (TRANS("IN"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 13.10f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 924 - 29, y = 128, width = 29, height = 28;
        juce::String text (TRANS("GR"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 13.10f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 962 - 29, y = 128, width = 29, height = 28;
        juce::String text (TRANS("OUT"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 13.10f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 930 - 135, y = 555, width = 135, height = 40;
        juce::String text (TRANS("DRY/WET"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Microsoft YaHei", 24.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.061f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == inputGainSlider.get())
    {
        //[UserSliderCode_inputGainSlider] -- add your slider handling code here..
        //[/UserSliderCode_inputGainSlider]
    }
    else if (sliderThatWasMoved == thresholdSlider.get())
    {
        //[UserSliderCode_thresholdSlider] -- add your slider handling code here..
        //[/UserSliderCode_thresholdSlider]
    }
    else if (sliderThatWasMoved == ratioSlider.get())
    {
        //[UserSliderCode_ratioSlider] -- add your slider handling code here..
        //[/UserSliderCode_ratioSlider]
    }
    else if (sliderThatWasMoved == kneeSlider.get())
    {
        //[UserSliderCode_kneeSlider] -- add your slider handling code here..
        //[/UserSliderCode_kneeSlider]
    }
    else if (sliderThatWasMoved == attackSlider.get())
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == releaseSlider.get())
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
        //[/UserSliderCode_releaseSlider]
    }
    else if (sliderThatWasMoved == makeupSlider.get())
    {
        //[UserSliderCode_makeupSlider] -- add your slider handling code here..
        //[/UserSliderCode_makeupSlider]
    }
    else if (sliderThatWasMoved == dryWetSlider.get())
    {
        //[UserSliderCode_dryWetSlider] -- add your slider handling code here..
        //[/UserSliderCode_dryWetSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public juce::AudioProcessorEditor" constructorParams="ImpactorAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor(&amp;p), processor(p),&#10;valueTreeState(vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1000" initialHeight="600">
  <BACKGROUND backgroundColour="ff191835">
    <RECT pos="0 436 1000 4" fill="solid: ff42a2c8" hasStroke="0"/>
    <RECT pos="0 440 500 80" fill=" radial: 0 440, 500 520, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="0 520 500 80" fill=" radial: 0 600, 500 520, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="500 440 500 80" fill=" radial: 1000 440, 500 520, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="500 520 500 80" fill=" radial: 1000 600, 500 520, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <TEXT pos="205r 555 135 40" fill="solid: ffffffff" hasStroke="0" text="THRESHOLD"
          fontname="Microsoft YaHei" fontsize="24.0" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="340r 555 135 40" fill="solid: ffffffff" hasStroke="0" text="RATIO"
          fontname="Microsoft YaHei" fontsize="24.0" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="475r 555 135 40" fill="solid: ffffffff" hasStroke="0" text="KNEE"
          fontname="Microsoft YaHei" fontsize="24.0" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="660r 555 135 40" fill="solid: ffffffff" hasStroke="0" text="ATTACK"
          fontname="Microsoft YaHei" fontsize="24.0" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="795r 555 135 40" fill="solid: ffffffff" hasStroke="0" text="RELEASE"
          fontname="Microsoft YaHei" fontsize="24.0" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <RECT pos="0 0 500 50" fill=" radial: 0 0, 500 50, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="0 50 500 50" fill=" radial: 0 100, 500 50, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="500 0 500 50" fill=" radial: 1000 0, 500 50, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="500 50 500 50" fill=" radial: 1000 100, 500 50, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="0 100 1000 4" fill="solid: ff42a2c8" hasStroke="0"/>
    <TEXT pos="700r 0 400 100" fill="solid: ffffffff" hasStroke="0" text="IMPACTOR"
          fontname="Microsoft YaHei" fontsize="43.0" kerning="0.04" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <RECT pos="0 104 500 166" fill=" radial: 0 104, 500 270, 0=ff0e0d1c, 1=ff191835"
          hasStroke="0"/>
    <RECT pos="90 124 70 146" fill=" radial: 160 124, 90 270, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="20 124 70 146" fill=" radial: 20 124, 90 270, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="0 270 500 166" fill=" radial: 0 436, 500 270, 0=ff0e0d1c, 1=ff191835"
          hasStroke="0"/>
    <RECT pos="90 270 70 146" fill=" radial: 160 416, 90 270, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="20 270 70 146" fill=" radial: 20 416, 90 270, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="500 104 500 166" fill=" radial: 1000 104, 500 270, 0=ff0e0d1c, 1=ff191835"
          hasStroke="0"/>
    <RECT pos="500 270 500 166" fill=" radial: 1000 436, 500 270, 0=ff0e0d1c, 1=ff191835"
          hasStroke="0"/>
    <RECT pos="20 121 143 3" fill="solid: ff42a2c8" hasStroke="0"/>
    <RECT pos="160 124 3 292" fill="solid: ff42a2c8" hasStroke="0"/>
    <RECT pos="17 121 3 296" fill="solid: ff42a2c8" hasStroke="0"/>
    <RECT pos="17 416 146 3" fill="solid: ff42a2c8" hasStroke="0"/>
    <TEXT pos="156r 128 66 30" fill="solid: ffffffff" hasStroke="0" text="MAKEUP"
          fontname="Microsoft YaHei" fontsize="13.1" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="90r 128 66 30" fill="solid: ffffffff" hasStroke="0" text="INPUT"
          fontname="Microsoft YaHei" fontsize="13.1" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="90r 140 66 30" fill="solid: ffffffff" hasStroke="0" text="GAIN"
          fontname="Microsoft YaHei" fontsize="13.1" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="156r 140 66 30" fill="solid: ffffffff" hasStroke="0" text="GAIN"
          fontname="Microsoft YaHei" fontsize="13.1" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <RECT pos="840 124 70 146" fill=" radial: 840 124, 910 270, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="910 124 70 146" fill=" radial: 980 124, 910 270, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="840 270 70 146" fill=" radial: 840 416, 910 270, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="910 270 70 146" fill=" radial: 980 416, 910 270, 0=ff191835, 1=ff333171"
          hasStroke="0"/>
    <RECT pos="979 124 3 292" fill="solid: ff42a2c8" hasStroke="0"/>
    <RECT pos="837 416 145 3" fill="solid: ff42a2c8" hasStroke="0"/>
    <RECT pos="837 121 3 296" fill="solid: ff42a2c8" hasStroke="0"/>
    <RECT pos="840 121 142 3" fill="solid: ff42a2c8" hasStroke="0"/>
    <TEXT pos="886r 128 29 28" fill="solid: ffffffff" hasStroke="0" text="IN"
          fontname="Microsoft YaHei" fontsize="13.1" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="924r 128 29 28" fill="solid: ffffffff" hasStroke="0" text="GR"
          fontname="Microsoft YaHei" fontsize="13.1" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="962r 128 29 28" fill="solid: ffffffff" hasStroke="0" text="OUT"
          fontname="Microsoft YaHei" fontsize="13.1" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="930r 555 135 40" fill="solid: ffffffff" hasStroke="0" text="DRY/WET"
          fontname="Microsoft YaHei" fontsize="24.0" kerning="0.061" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
  </BACKGROUND>
  <SLIDER name="Input Gain" id="1b54ca9cd971bc60" memberName="inputGainSlider"
          virtualName="" explicitFocusOrder="0" pos="29 157 56 248" textboxhighlight="42a2c8"
          textboxoutline="8e989b" min="0.0" max="10.0" int="0.0" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="100"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Threshold" id="476b01c9ab5530da" memberName="thresholdSlider"
          virtualName="" explicitFocusOrder="0" pos="70 450 135 112" textboxhighlight="42a2c8"
          textboxoutline="8e989b" min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Ratio" id="cffa0b4c96e520e3" memberName="ratioSlider" virtualName=""
          explicitFocusOrder="0" pos="205 450 135 112" textboxhighlight="42a2c8"
          textboxoutline="8e989b" min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Knee" id="f32d72510a92de7a" memberName="kneeSlider" virtualName=""
          explicitFocusOrder="0" pos="340 450 135 112" textboxhighlight="42a2c8"
          textboxoutline="8e989b" min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Attack" id="55cf82cc1bb23671" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="525 450 135 112" textboxhighlight="42a2c8"
          textboxoutline="8e989b" min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Release" id="2e0b7920b76f247" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="660 450 135 112" textboxhighlight="42a2c8"
          textboxoutline="8e989b" min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Makeup Gain" id="586b95d7cb485131" memberName="makeupSlider"
          virtualName="" explicitFocusOrder="0" pos="94 157 56 248" textboxhighlight="42a2c8"
          textboxoutline="8e989b" min="0.0" max="10.0" int="0.0" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="100"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <GENERICCOMPONENT name="inputMeter" id="d46c7454a0dd317e" memberName="inputMeter"
                    virtualName="" explicitFocusOrder="0" pos="859 155 25 241" class="Meter"
                    params=""/>
  <GENERICCOMPONENT name="outputMeter" id="7a46aa8a32e0b601" memberName="outputMeter"
                    virtualName="" explicitFocusOrder="0" pos="935 155 25 241" class="Meter"
                    params=""/>
  <GENERICCOMPONENT name="grMeter" id="3a73b63307620fb4" memberName="grMeter" virtualName=""
                    explicitFocusOrder="0" pos="897 155 25 241" class="GrMeter" params=""/>
  <GENERICCOMPONENT name="inputMeterLabel" id="c662cce639b0c2e5" memberName="inputMeterLabel"
                    virtualName="" explicitFocusOrder="0" pos="856 399 31 14" class="MeterLabel"
                    params=""/>
  <GENERICCOMPONENT name="outputMeterLabel" id="4c296542dc455263" memberName="outputMeterLabel"
                    virtualName="" explicitFocusOrder="0" pos="932 399 31 14" class="MeterLabel"
                    params=""/>
  <GENERICCOMPONENT name="grMeterLabel" id="e40f158d5df0e1c1" memberName="grMeterLabel"
                    virtualName="" explicitFocusOrder="0" pos="894 399 31 14" class="GrMeterLabel"
                    params=""/>
  <GENERICCOMPONENT name="inputAudioVisualizer" id="ede30bdb6e219dcb" memberName="inputAudioVisualizer"
                    virtualName="" explicitFocusOrder="0" pos="243 121 514 298" class="AudioVisualizer"
                    params=""/>
  <GENERICCOMPONENT name="outputAudioVisualizer" id="ef7894979f701029" memberName="outputAudioVisualizer"
                    virtualName="" explicitFocusOrder="0" pos="243 121 514 298" class="AudioVisualizer"
                    params=""/>
  <SLIDER name="Drywet" id="d5d1fa0138d998fc" memberName="dryWetSlider"
          virtualName="" explicitFocusOrder="0" pos="795 450 135 112" textboxhighlight="42a2c8"
          textboxoutline="8e989b" min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

