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
    void clear();
    
    void getBufferIndex(int index);
    
    void addSampleToBuffer(float data, int delay);
    void processValues(float data, int delay);
    
    float getSample();
    
private:
    
    int index;
    int bufferIndex;
    int bufferSize;
    float* buffer;
    
};



#endif  // FRACTIONALDELAY_H_INCLUDED
