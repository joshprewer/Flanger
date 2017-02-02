/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "FractionalDelay.h"
#include "toneGenerator.h"


//==============================================================================
/**
*/
class FlangerAudioProcessor  : public AudioProcessor 
{
public:
    //==============================================================================
    FlangerAudioProcessor();
    ~FlangerAudioProcessor();

	float depth = 0.43;
	float rate = 2.5;
	float mix = 0.4;
	float delay = 0.0093;
	float feedback = 0.5;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) ;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    
private:
    
    ToneGenerator lfoL;
    ToneGenerator lfoR;
    ToneGenerator toneL;
    ToneGenerator toneR;

    FractionalDelay delayL;
    FractionalDelay delayR;
    
	double SR;

    float LFO;
	int lfoSize = 20;

    float inputData;
    float flangedData;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlangerAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
