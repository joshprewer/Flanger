/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class FlangerAudioProcessorEditor  : public AudioProcessorEditor , private Slider::Listener
{
public:
    FlangerAudioProcessorEditor (FlangerAudioProcessor&);
    ~FlangerAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FlangerAudioProcessor& processor;
    
    void sliderValueChanged (Slider* slider) override;
    
    Slider depthSlider;
    Label depthLabel;
    
    Slider rateSlider;
    Label rateLabel;
    
    Slider mixSlider;
    Label mixLabel;
    
    Slider delaySlider;
    Label delayLabel;

    Slider feedbackSlider;
    Label feedbackLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlangerAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
