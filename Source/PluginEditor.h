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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "ImpactorTheme.h"
#include "Meter.h"
#include "MeterLabel.h"
#include "AudioVisualizer.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditor  : public juce::AudioProcessorEditor,
                      public juce::Slider::Listener
{
public:
    //==============================================================================
    PluginEditor (ImpactorAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~PluginEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    ImpactorAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;

    std::unique_ptr<SliderAttachment> inputGainAttachment;
    std::unique_ptr<SliderAttachment> makeupGainAttachment;
    std::unique_ptr<SliderAttachment> thresholdAttachment;
    std::unique_ptr<SliderAttachment> ratioAttachment;
    std::unique_ptr<SliderAttachment> kneeAttachment;
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;
    std::unique_ptr<SliderAttachment> dryWetAttachment;

    ImpactorTheme impactorTheme;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> inputGainSlider;
    std::unique_ptr<juce::Slider> thresholdSlider;
    std::unique_ptr<juce::Slider> ratioSlider;
    std::unique_ptr<juce::Slider> kneeSlider;
    std::unique_ptr<juce::Slider> attackSlider;
    std::unique_ptr<juce::Slider> releaseSlider;
    std::unique_ptr<juce::Slider> makeupSlider;
    std::unique_ptr<Meter> inputMeter;
    std::unique_ptr<Meter> outputMeter;
    std::unique_ptr<GrMeter> grMeter;
    std::unique_ptr<MeterLabel> inputMeterLabel;
    std::unique_ptr<MeterLabel> outputMeterLabel;
    std::unique_ptr<GrMeterLabel> grMeterLabel;
    std::unique_ptr<AudioVisualizer> inputAudioVisualizer;
    std::unique_ptr<AudioVisualizer> outputAudioVisualizer;
    std::unique_ptr<juce::Slider> dryWetSlider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

