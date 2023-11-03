#include "MeterLabel.h"

MeterLabel::MeterLabel()
{
	observedValue = nullptr;
	startTimerHz(METER_LABEL_FPS);
}

MeterLabel::~MeterLabel()
{
	stopTimer();
}

void MeterLabel::paint(Graphics& g)
{
	auto W = getWidth();
	auto H = getHeight();


	if (observedValue != nullptr)
	{
		auto valueSnapshot = Decibels::gainToDecibels(observedValue->get());
		String toDisplay = (valueSnapshot < -48.0f) ? " -Inf" : String(valueSnapshot).dropLastCharacters(3);
		g.setColour(Colours::white);
		g.drawText(toDisplay, 0, 0, W, H*0.7f, Justification::centredLeft, false);
	}
}

void MeterLabel::connectTo(Atomic<float>& targetValue)
{
	observedValue = &targetValue;
}

void MeterLabel::timerCallback()
{
	repaint();
}





GrMeterLabel::GrMeterLabel()
{
	observedValue = nullptr;
	startTimerHz(METER_LABEL_FPS);
}

GrMeterLabel::~GrMeterLabel()
{
	stopTimer();
}

void GrMeterLabel::paint(Graphics& g)
{
	auto W = getWidth();
	auto H = getHeight();


	if (observedValue != nullptr)
	{
		auto valueSnapshot = -Decibels::gainToDecibels(observedValue->get());
		String toDisplay = (valueSnapshot == 0.0f) ? " ---" : String(valueSnapshot).dropLastCharacters(3);
		g.setColour(Colours::white);
		g.drawText(toDisplay, 0, 0, W, H * 0.7f, Justification::centredLeft, false);
	}
}

void GrMeterLabel::connectTo(Atomic<float>& targetValue)
{
	observedValue = &targetValue;
}

void GrMeterLabel::timerCallback()
{
	repaint();
}