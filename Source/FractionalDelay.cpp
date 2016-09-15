/*
  ==============================================================================

    FractionalDelay.cpp
    Created: 18 Aug 2016 11:06:15am
    Author:  Josh Prewer

  ==============================================================================
*/

#include "FractionalDelay.h"
#include <vector>


FractionalDelay::FractionalDelay()
{
    index = 0;
    bufferSize = 0;
    
}

void FractionalDelay::setBufferSize(int size)
{
    bufferSize = size;
    buffer = new float[bufferSize];
}

float FractionalDelay::processValues(float data, int delay)
{
 
    float m = (data - buffer[index]) / (delay - index);
    float c = data - (m * delay);
    
    for (int i = index; i <= delay; i++)
    {
        float lineData = buffer[i] + (m * (i) + c);
        
        if (i == 0)
        {
            buffer[0] = lineData;
        }
        else
        {
            buffer[i] = lineData;
        }
        
    }
    
    index++;
    return buffer[index];
    
};
