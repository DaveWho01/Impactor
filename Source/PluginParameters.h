#pragma once
#include <JuceHeader.h>

#define FPS				25
#define METER_LABEL_FPS	10
#define RELEASE_TIME	0.7f
#define DB_FLOOR		-48.0f

namespace Parameters
{
	static const float defaultAlphaAttack = 0.9132f;
	static const float defaultAlphaRelease = 0.9998f;
	static const float defaultInputGain = 1.0f; // Linear
	static const float defaultMakeupGain = 1.0f; // Linear
	static const float defaultThreshold = 0.0f; // dB
	static const float defaultRatio = 1.0f;
	static const float defaultKnee = 0.0f; // dB
	static const float defaultDWRatio = 1.0f;

	static const double initSampleRate = 0.0;
	static const float initSamplePeak = 0.0f;

	static const float defaultAlphaMeter = 0.0f;

	static const String nameAttackTime = "AT";
	static const String nameReleaseTime = "RT";
	static const String nameInputGain = "IG";
	static const String nameMakeupGain = "MG";
	static const String nameThreshold = "TS";
	static const String nameRatio = "RA";
	static const String nameKnee = "KN";
	static const String nameDryWetRatio = "DW";

	static AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
	{
		std::vector<std::unique_ptr<RangedAudioParameter>> params;

		params.push_back(std::make_unique<AudioParameterFloat>(nameAttackTime, "Attack Time (ms)", NormalisableRange<float>(0.05f, 250.0f, 0.01f, 0.35f), 0.05f));
		params.push_back(std::make_unique<AudioParameterFloat>(nameReleaseTime, "Release Time (ms)", NormalisableRange<float>(10.0f, 3000.0f, 0.1f, 0.3f), 150.0f));
		params.push_back(std::make_unique<AudioParameterFloat>(nameInputGain, "Input Gain", NormalisableRange<float>(-48.0f, 6.0f, 0.1f, 1.5f), 0.0f));
		params.push_back(std::make_unique<AudioParameterFloat>(nameThreshold, "Threshold (dB)", NormalisableRange<float>(-60.0f, 0.0f, 0.1f, 2.0f), 0.0f));
		params.push_back(std::make_unique<AudioParameterFloat>(nameRatio, "Ratio", NormalisableRange<float>(1.0f, 30.0f, 0.01f, 0.5f), 1.0f));
		params.push_back(std::make_unique<AudioParameterFloat>(nameKnee, "Knee (dB)", NormalisableRange<float>(0.0f, 50.0f, 0.01f, 0.5f), 0.0f));
		params.push_back(std::make_unique<AudioParameterFloat>(nameMakeupGain, "Makeup Gain (dB)", NormalisableRange<float>(0.0f, 15.0f, 0.1f, 0.8f), 0.0f));
		params.push_back(std::make_unique<AudioParameterFloat>(nameDryWetRatio, "Dry/Wet", 0.0f, 100.0f, 100.0f));

		return { params.begin(), params.end() };
	}

	static void addListenerToAllParameters(AudioProcessorValueTreeState& valueTreeState, AudioProcessorValueTreeState::Listener* listener)
	{
		std::unique_ptr<XmlElement> xml(valueTreeState.copyState().createXml());

		for (auto element : xml->getChildWithTagNameIterator("PARAM"))
		{
			const String& id = element->getStringAttribute("id");
			valueTreeState.addParameterListener(id, listener);
		}
	}
}