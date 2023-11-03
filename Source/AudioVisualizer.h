#pragma once
#include <JuceHeader.h>
#include "PluginParameters.h"

class AudioVisualizer : public Component, public Timer
{
public:
	AudioVisualizer();
	~AudioVisualizer();

	void paint(Graphics& g) override;
	void connectTo(Atomic<float>& targetValue);
	void updateWaveValues();
	void setColour(Colour colour);

private:

	void timerCallback() override;

	Colour waveformColour;
	Atomic<float>* observedValue;
	int waveWinSize;
	float* waveValues;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioVisualizer)
};