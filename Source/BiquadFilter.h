/*
  ==============================================================================

    BiquadFilter.h
    Created: 25 Nov 2016 7:52:17pm
    Author:  Josh Prewer

  ==============================================================================
*/

#ifndef BIQUADFILTER_H_INCLUDED
#define BIQUADFILTER_H_INCLUDED

class BiquadFilter
{
public:

    BiquadFilter();
    
    enum filterType { PEAK, LOWPASS, HIGHPASS, HIGHSHELF, LOWSHELF };
    
    float getSample();
    
    void setParameters(double frequency, double gain, double q, filterType filter);
    
    void addSample(float sample);

private:
    
    void clear();
    void caluclateCoefficients();
    
    int bufferSize = 4;
    double coeff[6];
    double fs = 44100;
    
    filterType kFilter;
    double kFrequency;
    double kGain;
    double kQ;
    
    float* xBuffer;
    float* yBuffer;

    void addToBuffer(float sample, float* buffer);
    void getReadPos();
    
    int writePos = 0;
    int readPos = 0;
    int readPosOne = 0;
    int readPosTwo = 0;
};



#endif  // BIQUADFILTER_H_INCLUDED
