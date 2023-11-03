#include "Meter.h"

// Meter implementation
Meter::Meter(float defaultAlpha)
	:	alpha(defaultAlpha)
{
	alpha = exp(-1.0f / (FPS * RELEASE_TIME));
	observedValue = nullptr;
	startTimerHz(FPS);
}

Meter::~Meter()
{
	stopTimer();
}

void Meter::paint(Graphics& g)
{
	auto W = getWidth();
	auto H = getHeight();
	auto halfW = W * 0.5f;

	g.fillAll(Colour::fromRGB(19, 18, 35));
	g.setColour(Colour::fromRGB(66, 162, 203));
	g.drawRect(0, 0, W, H);


	if (observedValue != nullptr)
	{
		auto valueSnapshot = observedValue->get();
		observedValue->set(valueSnapshot * alpha);

		auto peak = Decibels::gainToDecibels(valueSnapshot, DB_FLOOR);
		auto lowerBarHeight = jmap(jmin(peak, 0.0f), DB_FLOOR, 0.0f, 0.0f, H * 0.8f - 2.0f);
		auto higherBarHeight = jmin(H * 0.2f - 2.0f, jmap(jmax(peak, 0.0f), 0.0f, 6.0f, 0.0f, H * 0.2f));
		auto underZero = Colour::fromRGB(23, 252, 3);
		auto overZero = Colour::fromRGB(252, 3, 3);
		auto singleBarWidth = halfW - 3.0f;

		g.setColour(overZero);																	// over 0 dB
		g.fillRect(2.0f, H * 0.2f - higherBarHeight, singleBarWidth, higherBarHeight);			// sx
		g.fillRect(halfW + 1.0f, H * 0.2f - higherBarHeight, singleBarWidth, higherBarHeight);	// dx

		g.setColour(underZero);																	// under 0 dB
		g.fillRect(2.0f, H - lowerBarHeight - 2.0f, singleBarWidth, lowerBarHeight);			// sx
		g.fillRect(halfW + 1.0f, H - lowerBarHeight - 2.0f, singleBarWidth, lowerBarHeight);	// dx
		
	}
}

void Meter::connectTo(Atomic<float>& targetValue)
{
	observedValue = &targetValue;
}

void Meter::timerCallback()
{
	repaint();
}


// grMeter implementation
GrMeter::GrMeter(float defaultAlpha)
	: alpha(defaultAlpha)
{
	alpha = exp(-1.0f / (FPS * RELEASE_TIME));
	observedValue = nullptr;
	startTimerHz(FPS);
}

GrMeter::~GrMeter()
{
	stopTimer();
}

void GrMeter::paint(Graphics& g)
{
	auto W = getWidth();
	auto H = getHeight();
	auto halfW = W * 0.5f;

	g.fillAll(Colour::fromRGB(19, 18, 35));
	g.setColour(Colour::fromRGB(66, 162, 203));
	g.drawRect(0, 0, W, H);

	if (observedValue != nullptr)
	{
		auto valueSnapshot = observedValue->get();
		observedValue->set(valueSnapshot * alpha);
		
		auto peak = Decibels::gainToDecibels(valueSnapshot, DB_FLOOR);
		Logger::outputDebugString(String(peak));
		auto barHeight = jmap(peak, 0.0f, -48.0f, 0.0f, H * 1.0f);
		auto singleBarWidth = halfW - 3.0f;

		g.setColour(Colour::fromRGB(23, 252, 3));																			// over 0 dB
		g.fillRect(2.0f, 2.0f, singleBarWidth, barHeight);			// sx
		g.fillRect(halfW + 1.0f, 2.0f, singleBarWidth, barHeight);	// dx
	
	}
}

void GrMeter::connectTo(Atomic<float>& targetValue)
{
	observedValue = &targetValue;
}

void GrMeter::timerCallback()
{
	repaint();
}