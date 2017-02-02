/*
  ==============================================================================

    toneGenerator.h
    Created: 4 Oct 2016 1:09:28pm
    Author:  Josh Prewer

  ==============================================================================
*/

#ifndef TONEGENERATOR_H_INCLUDED
#define TONEGENERATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class ToneGenerator
{
public:
    
    ToneGenerator();
    
    enum Waveshape {SINE, SAW, SQUARE, TRIANGLE};
    
    void initialiseWave(double frequency, float amplitude, double sr, Waveshape wave);
    
    float getValue();
    
private:
    
    float sineWave();
    float sawWave();
    float sqrWave();
    float triWave();
    
    Waveshape kWave;
    double kFrequency;
    float kAmplitude;
    double kSR;
    
    float m;
    float n;
    int tick = 0;
    float output;
    float currentAngle = 0;
};




#endif  // TONEGENERATOR_H_INCLUDED
