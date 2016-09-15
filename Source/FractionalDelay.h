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
    
    float processValues(float data, int delay);
    
private:
    
    
    int index;
    int bufferSize;
    float* buffer;
    float outputValues = 0;
    
};



#endif  // FRACTIONALDELAY_H_INCLUDED
