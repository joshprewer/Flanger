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

void FractionalDelay::addSampleToBuffer(float data)
{
    buffer[writePos] = data;
    writePos = (writePos != bufferSize - 1 ? writePos + 1 : 0);
}


float FractionalDelay::getSample(float delay)
{
    offset = delay;
    getreadOffset();
    
    return interpolate();
}


void FractionalDelay::getreadOffset()
{
    readOffset = writePos - offset;
    readOffset = (readOffset >= 0 ? (readOffset < bufferSize ? readOffset : readOffset - bufferSize)
                  : readOffset + bufferSize);
    
}

float FractionalDelay::interpolate()
{
    readPos = (int) readOffset;
    frac = readOffset - readPos;
    nextSample = (readPos != bufferSize - 1 ? buffer[readPos+1] : buffer[0]);
    return outputSample = buffer[readPos] + frac * (nextSample - buffer[readPos]);
    
}