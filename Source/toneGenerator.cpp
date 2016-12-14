/*
  ==============================================================================

    toneGenerator.cpp
    Created: 4 Oct 2016 1:09:28pm
    Author:  Josh Prewer

  ==============================================================================
*/

#include "toneGenerator.h"


ToneGenerator::ToneGenerator()
{
    output = 0;
}

void ToneGenerator::initialiseWave(double frequency, float amplitude, double sr, Waveshape wave)
{
    kFrequency = frequency;
    kAmplitude = amplitude;
    kSR = sr;
    kWave = wave;
    if (kAmplitude > 1)
        kAmplitude = 1;
}

float ToneGenerator::getValue()
{
    if(kWave == SINE)
        return sineWave();
    if(kWave == SAW)
        return sawWave();
    if(kWave == SQUARE)
        return sqrWave();
    if(kWave == TRIANGLE)
        return triWave();
    
    else return 0;
}

float ToneGenerator::sineWave()
{
    float delta = (kFrequency / kSR) * 2 * double_Pi;
    currentAngle += delta;
    output = std::sin(currentAngle);
    return output;
}

float ToneGenerator::sawWave()
{
    m = kAmplitude / (kSR / kFrequency);
    
    if(output >= kAmplitude)
        output = - kAmplitude;
    
    output += m;
    
    return output;
}

float ToneGenerator::sqrWave()
{
    m  = (int) (kSR / (kFrequency));
    
    if(tick < (m / 2))
    {
        output = kAmplitude;
    }
    else
    {
        output = -kAmplitude;
    }
    
    if(tick >= m)
        tick = 0;
    else tick += 1;
    
    return output;
}

float ToneGenerator::triWave()
{
    m = kAmplitude / ((kSR / kFrequency) / 4);
    n = (int) (kSR / kFrequency);
    
    if(tick < (n / 4) || tick > ((3 * n) / 4))
    {
        output += m;
    }
    else
    {
        output -= m;
    }
    
    if(tick > n)
        tick = 0;
    else tick += 1;
    
    return output;
}


