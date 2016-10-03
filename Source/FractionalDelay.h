/*
  ==============================================================================

    FractionalDelay.h
    Created: 18 Aug 2016 11:06:15am
    Author:  Josh Prewer

  ==============================================================================
*/

#ifndef FRACTIONALDELAY_H_INCLUDED
#define FRACTIONALDELAY_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class FractionalDelay
{
public:
    
    FractionalDelay();
    void setBufferSize(int size);
    
    void addSampleToBuffer(float data);
    
    float getSample(float delay);
    
private:

    void clear();
    
    void getreadOffset();
    float interpolate();

    float readOffset = 0;
    float offset;
    
    int writePos = 0;
    int readPos = 0;
    
    float outputSample;
    float nextSample;
    
    int bufferSize;
    float frac;
    float* buffer;
    
};



#endif  // FRACTIONALDELAY_H_INCLUDED
