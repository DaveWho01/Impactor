#pragma once
#include <JuceHeader.h>
#include "PluginParameters.h"

class MeterLabel : public Component, public Timer
{
public:

	MeterLabel();
	~MeterLabel();

	void paint(Graphics& g) override;
	void connectTo(Atomic<float>& targetValue);

private:

	void timerCallback() override;

	Atomic<float>* observedValue;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MeterLabel)
};


class GrMeterLabel : public Component, public Timer
{
public:

	GrMeterLabel();
	~GrMeterLabel();

	void paint(Graphics& g) override;
	void connectTo(Atomic<float>& targetValue);

private:

	void timerCallback() override;

	Atomic<float>* observedValue;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrMeterLabel)
};