/*
  ==============================================================================

    SineGenerator.cpp
    Created: 18 Aug 2016 11:06:07am
    Author:  Josh Prewer

  ==============================================================================
*/

#include "SineGenerator.h"

SineGenerator::SineGenerator()
{

    double cyclesPerSample = frequency / sampleRate;
    delta = cyclesPerSample * 2 * double_Pi;
    
}

int SineGenerator::updateDelta()
{
    currentAnlge += delta;
    lfoOutput = roundToInt(661.5 + (661.5 * std::sin(currentAnlge)));
    return lfoOutput;
}

