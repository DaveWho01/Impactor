#pragma once
#include <JuceHeader.h>
#include "PluginParameters.h"

class DryWet
{
public:
	DryWet(float defaultDWRatio = Parameters::defaultDWRatio);
	~DryWet();

	void prepareToPlay(const double sr, const int maxNumSamples);
	void releaseResources();
	void copyDrySignal(const AudioBuffer<float>& buffer);
	void merge(AudioBuffer<float> buffer);
	void setDryWetRatio(const float newValue);


private:

	void updateInternalState();

	float dryWetRatio;

	SmoothedValue<float, ValueSmoothingTypes::Linear> dryLevel;
	SmoothedValue<float, ValueSmoothingTypes::Linear> wetLevel;

	AudioBuffer<float> drySignal;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DryWet)
};