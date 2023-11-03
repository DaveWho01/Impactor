#pragma once
#include <JuceHeader.h>
#include "PluginParameters.h"

class Meter : public Component, public Timer
{
public:
	Meter(float defaultAlpha = Parameters::defaultAlphaMeter);
	~Meter();

	void paint(Graphics& g) override;
	void connectTo(Atomic<float>& targetValue);

private:
	void timerCallback() override;
	float alpha;
	Atomic<float>* observedValue;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Meter)
};



class GrMeter : public Component, public Timer
{
public:
	GrMeter(float defaultAlpha = Parameters::defaultAlphaMeter);
	~GrMeter();

	void paint(Graphics& g) override;
	void connectTo(Atomic<float>& targetValue);

private:
	void timerCallback() override;
	float alpha;
	Atomic<float>* observedValue;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrMeter)
};