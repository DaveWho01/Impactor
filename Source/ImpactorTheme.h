#pragma once
#include <JuceHeader.h>

#define BORDER_WIDTH 1.5f
#define SCALE_TO_KNOB_RATIO 0.85f

class ImpactorTheme : public LookAndFeel_V4
{
public:

	ImpactorTheme();
	~ImpactorTheme();
	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, 
		float sliderPosProportional, float rotaryStartAngle,
		float rotaryEndAngle, Slider& s) override;

	void drawLinearSlider(Graphics& g, int x, int y, int width, int height,
		float sliderPos, float minSliderPos, float maxSliderPos,
		const Slider::SliderStyle, Slider& s) override;

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImpactorTheme)
};