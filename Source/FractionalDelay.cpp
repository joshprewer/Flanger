/*
  ==============================================================================

    FractionalDelay.cpp
    Created: 18 Aug 2016 11:06:15am
    Author:  Josh Prewer

  ==============================================================================
*/

#include "FractionalDelay.h"


float processValues(float data, int delay)
{
    float outputValues;
    float m = (data - outputValues) / (delay);
    outputValues = outputValues + (m * (1/44100));
    return outputValues;
};