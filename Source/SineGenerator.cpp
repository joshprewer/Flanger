/*
  ==============================================================================

    SineGenerator.cpp
    Created: 18 Aug 2016 11:06:07am
    Author:  Josh Prewer

  ==============================================================================
*/

#include "SineGenerator.h"

void SineGenerator::initialiseSine(double frequency)
{
    kFrequency = frequency;
    double cyclesPerSample = kFrequency / sampleRate;
    delta = cyclesPerSample * 2 * double_Pi;
}


float SineGenerator::updateDelta()
{
    currentAnlge += delta;
    sinOutput = std::sin(currentAnlge);
    return sinOutput;
}

