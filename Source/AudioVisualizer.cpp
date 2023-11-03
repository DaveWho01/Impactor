#include "AudioVisualizer.h"

AudioVisualizer::AudioVisualizer()
{
    waveWinSize = 256;
    waveValues = new float[waveWinSize];
    observedValue = nullptr;
    startTimerHz(FPS);
    std::fill(waveValues, waveValues + waveWinSize, 0);
}

AudioVisualizer::~AudioVisualizer()
{
    //delete[] waveValues;
    stopTimer();
}

void AudioVisualizer::paint(Graphics& g)
{
    float halfH = getHeight() * 0.5f;
    g.setColour(waveformColour);

    float fadeOutPercentage = 0.23f;

    int fadeOutStart = static_cast<int>(waveWinSize * fadeOutPercentage);
    int fadeOutEnd = waveWinSize - fadeOutStart;
    float opacity = 1.0f;

    for (int i = 0; i < waveWinSize; ++i)
    {
        auto rectHeight = jmap(waveValues[i], 0.0f, 1.0f, 0.0f, halfH);
        
        if (i < fadeOutStart)
        {
            opacity = static_cast<float>(i) / fadeOutStart;
        }
        else if (i >= fadeOutEnd)
        {
            opacity = 1.0f - static_cast<float>(i - fadeOutEnd) / fadeOutStart;
        }
        
        g.setOpacity(opacity);
        g.drawRect(i * 2.0f, halfH - rectHeight, 2.0f, rectHeight * 2);
    }
}

void AudioVisualizer::connectTo(Atomic<float>& targetValue)
{
    observedValue = &targetValue;
}

void AudioVisualizer::updateWaveValues()
{
    for (int i = 0; i < waveWinSize - 1; ++i)
        waveValues[i] = waveValues[i + 1];


    waveValues[waveWinSize - 1] = observedValue->get();
}

void AudioVisualizer::setColour(Colour newColour)
{
    waveformColour = newColour;
}

void AudioVisualizer::timerCallback()
{
    updateWaveValues();
    repaint();
}
