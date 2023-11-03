#include "ImpactorTheme.h"

ImpactorTheme::ImpactorTheme()
{
}

ImpactorTheme::~ImpactorTheme()
{
}

void ImpactorTheme::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& s)
{
	const auto radius = jmin(width, height) * 0.5f * SCALE_TO_KNOB_RATIO * BORDER_WIDTH * 0.5f;
	const auto centreX = x + width * 0.5f;
	const auto centreY = y + height * 0.5f;
	const auto rx = centreX - radius;
	const auto ry = centreY - radius;
	const auto rw = radius * 2.0f;

	const Colour knobColour = Colour::fromRGBA(167, 166, 195, 255);
	const Colour borderKnobColour = Colour::fromRGBA(18, 17, 47, 255);

	g.setColour(knobColour);
	g.fillEllipse(rx, ry, rw, rw);

	g.setColour(borderKnobColour);
	g.drawEllipse(rx, ry, rw, rw, BORDER_WIDTH);

	Path p;
	const auto pointerRadius = radius * 0.1f;
	p.addEllipse(radius * 0.4f, radius * 0.4f, pointerRadius * 2, pointerRadius * 2);

	const auto angle = jmap(sliderPosProportional, rotaryStartAngle+10.6f, rotaryEndAngle+9.8f);
	p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
	g.fillPath(p);
}

void ImpactorTheme::drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider& s)
{
	g.setColour(Colour::fromRGBA(167, 166, 195, 255));
	g.drawRoundedRectangle(width * 0.47f, height * 0.1f, width * 0.06f, height * 0.93f, 2.0f, 1.5f);

	Path p;
	g.setColour(Colours::white);
	p.addEllipse(width * 0.375f, height * 0.05f, width * 0.25f, width * 0.25f);

	const auto deltaY = jmap(sliderPos, 12.0f, 216.0f, 1.0f, height*0.47f);
	p.applyTransform(AffineTransform::translation(0.0f, deltaY).translated(0.0f, deltaY));

	g.fillPath(p);
}
