/*
  ==============================================================================

    BiquadFilter.cpp
    Created: 25 Nov 2016 7:52:17pm
    Author:  Josh Prewer

  ==============================================================================
*/

#include "BiquadFilter.h"
#include <vector>
#include <cmath>
#include "../JuceLibraryCode/JuceHeader.h"

BiquadFilter::BiquadFilter()
{
    xBuffer = new float[bufferSize];
    yBuffer = new float[bufferSize];
    clear();
}

void BiquadFilter::clear()
{
    std::memset(xBuffer, 0, bufferSize);
    std::memset(yBuffer, 0, bufferSize);
}

void BiquadFilter::setParameters(double frequency, double gain, double q, filterType filter)
{
    if (kFrequency == frequency && kGain == gain && kQ == q && kFilter == filter)
    {
        return;
    }
    else
    {
        kFrequency = frequency;
        kGain = gain;
        kQ = q;
        kFilter = filter;
        
        caluclateCoefficients();
    }
}

void BiquadFilter::caluclateCoefficients()
{
    float w = 2*double_Pi*(kFrequency/fs);
    float alpha = sinf(w) / (2*kQ);
    float a = pow(10, (kGain/40));
    
    if (kFilter == LOWPASS)
    {
        coeff[0] = (1 - cosf(w)) / 2;
        coeff[1] = 1 - cosf(w);
        coeff[2] = coeff[0];
        coeff[3] = 1 + alpha;
        coeff[4] = -2 * cosf(w);
        coeff[5] = 1 - alpha;
    }
    if (kFilter == HIGHPASS)
    {
        coeff[0] = (1 + cosf(w)) / 2;
        coeff[1] = -1*(1 + cosf(w));
        coeff[2] = coeff[0];
        coeff[3] = 1 + alpha;
        coeff[4] = -2 * cosf(w);
        coeff[5] = 1 - alpha;
    }
    if (kFilter == PEAK)
    {
        coeff[0] = 1 + (alpha * a);
        coeff[1] = -2 * cosf(w);
        coeff[2] = 1 - (alpha * a);
        coeff[3] = 1 + (alpha / a);
        coeff[4] = -2 * cosf(w);
        coeff[5] = 1 - (alpha / a);
    }
}

float BiquadFilter::getSample()
{
    getReadPos();
    
    float y = (coeff[0] / coeff[3])*xBuffer[readPos] + (coeff[1] / coeff[3])*xBuffer[readPosOne] + (coeff[2] / coeff[3])*xBuffer[readPosTwo]
    - (coeff[4] / coeff[3])*yBuffer[readPosOne] - (coeff[5] / coeff[3])*yBuffer[readPosTwo];
    
    addToBuffer(y, yBuffer);
    
    return y;
}

void BiquadFilter::getReadPos()
{
    readPos = writePos;
    readPosOne = (readPos != 0 ? readPos - 1 : bufferSize - 1);
    readPosTwo = (readPosOne != 0 ? readPosOne - 1 : bufferSize - 1);
}

void BiquadFilter::addSample(float sample)
{
    addToBuffer(sample, xBuffer);
    writePos = (writePos != bufferSize - 1 ? writePos + 1 : 0);
}

void BiquadFilter::addToBuffer(float sample, float* buffer)
{
    buffer[writePos] = sample;
}
