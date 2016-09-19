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
    clear();
}

void FractionalDelay::clear()
{
    std::memset(buffer, 0, bufferSize);
}

void FractionalDelay::addSampleToBuffer(float data, int delay)
{
    
    if(index == bufferSize)
        index = 0;
    
    getBufferIndex(index);
    processValues(data, delay);
   
}

void FractionalDelay::getBufferIndex(int index)
{
    if (index == 0)
        bufferIndex = bufferSize;
    else
        bufferIndex = index - 1;
}

float FractionalDelay::getSample()
{
    index++;
    getBufferIndex(index);
    return buffer[bufferIndex];
}

void FractionalDelay::processValues(float data, int delay)
{
    float m = (data - buffer[bufferIndex]) / delay;
    
    buffer[index] = buffer[bufferIndex] + m;
};


