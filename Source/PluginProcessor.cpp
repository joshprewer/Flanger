/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "FractionalDelay.h"

//==============================================================================
FlangerAudioProcessor::FlangerAudioProcessor()
{
    
}

FlangerAudioProcessor::~FlangerAudioProcessor()
{
}

//==============================================================================
const String FlangerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FlangerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FlangerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double FlangerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FlangerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FlangerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FlangerAudioProcessor::setCurrentProgram (int index)
{
}

const String FlangerAudioProcessor::getProgramName (int index)
{
    return String();
}

void FlangerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FlangerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

	SR = getSampleRate();
    
    delayL.setBufferSize(SR);
    delayR.setBufferSize(SR);
    
    toneL.initialiseWave(1000, 0.5, SR, ToneGenerator::SAW);
    toneR.initialiseWave(1000, 0.5, SR, ToneGenerator::SAW);
}

void FlangerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FlangerAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void FlangerAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());


    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {

		lfoL.initialiseWave(rate, 1, SR, ToneGenerator::SINE);
		lfoR.initialiseWave(rate, 1, SR, ToneGenerator::SINE);

        float* channelData = buffer.getWritePointer(channel);
        
        for (int i = 0; i < buffer.getNumSamples(); i++){
                                              
            if (channel == 0){
                inputData = toneL.getValue();
                 
                LFO = (delay * (1 + lfoL.getValue() * depth)) * SR;                
				LFO = (delay == 0 ? 1 : (LFO > SR ? SR : LFO));
                
                flangedData = delayL.getSample(LFO);
                delayL.addSampleToBuffer(inputData + (feedback * flangedData));
                
				channelData[i] = (flangedData * mix) + (inputData * (1 - mix));
        
            }
            else
            {
                inputData = toneR.getValue();
                                
                LFO = (delay * (1 + lfoR.getValue() * depth)) * SR;              
				LFO = (delay == 0 ? 1 : (LFO > SR ? SR : LFO));
                
                flangedData = delayR.getSample(LFO);
                delayR.addSampleToBuffer(inputData + (feedback * flangedData));
                
                channelData[i] = (flangedData * mix) + (inputData * (1 - mix));
            }
        
        }

        // ..do something to the data...
    }
    
}

//==============================================================================
bool FlangerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FlangerAudioProcessor::createEditor()
{
    return new FlangerAudioProcessorEditor (*this);
}

//==============================================================================
void FlangerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FlangerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FlangerAudioProcessor();
}
