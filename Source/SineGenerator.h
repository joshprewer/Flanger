/*
  ==============================================================================

    SineGenerator.h
    Created: 18 Aug 2016 11:06:07am
    Author:  Josh Prewer

  ==============================================================================
*/

#ifndef SINEGENERATOR_H_INCLUDED
#define SINEGENERATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class SineGenerator
{
public:
    
    void initialiseSine(double frequency);
    
    float updateDelta();
    
    
private:
    
    double sampleRate = 44100;
    double currentAnlge;
    double delta;
    double kFrequency;
    float sinOutput;
    
};



#endif  // SINEGENERATOR_H_INCLUDED
