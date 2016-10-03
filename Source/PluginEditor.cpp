/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
FlangerAudioProcessorEditor::FlangerAudioProcessorEditor (FlangerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    depthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    depthSlider.setRange(0, 100, 1);
    depthSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 40, 25);
    depthSlider.setTextValueSuffix("%");
    depthSlider.setValue(50);
    
    addAndMakeVisible(&depthSlider);
    
    depthLabel.setText("Depth", dontSendNotification);
    depthLabel.attachToComponent(&depthSlider, false);
    depthLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&depthLabel);
    
    depthSlider.addListener(this);
    

    rateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    rateSlider.setRange(0, 5, 0.05);
    rateSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    rateSlider.setTextValueSuffix("Hz");
    rateSlider.setValue(2.5);
    
    addAndMakeVisible(&rateSlider);
    
    rateLabel.setText("Rate", dontSendNotification);
    rateLabel.attachToComponent(&rateSlider, false);
    rateLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&rateLabel);
    
    rateSlider.addListener(this);
    
    mixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    mixSlider.setRange(0, 100, 1);
    mixSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 40, 25);
    mixSlider.setTextValueSuffix("%");
    mixSlider.setValue(50);
    
    addAndMakeVisible(&mixSlider);
    
    mixLabel.setText("Mix", dontSendNotification);
    mixLabel.attachToComponent(&mixSlider, false);
    mixLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&mixLabel);
    
    mixSlider.addListener(this);
    
    delaySlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delaySlider.setRange(0.04, 15, 0.1);
    delaySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    delaySlider.setTextValueSuffix("ms");
    delaySlider.setValue(7.5);
    
    addAndMakeVisible(&delaySlider);
    
    delayLabel.setText("Delay", dontSendNotification);
    delayLabel.attachToComponent(&delaySlider, false);
    delayLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&delayLabel);
    
    delaySlider.addListener(this);
    
    
    feedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    feedbackSlider.setRange(0, 100, 1);
    feedbackSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    feedbackSlider.setTextValueSuffix("ms");
    feedbackSlider.setValue(50);
    
    addAndMakeVisible(&feedbackSlider);
    
    feedbackLabel.setText("Feedback", dontSendNotification);
    feedbackLabel.attachToComponent(&feedbackSlider, false);
    feedbackLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&feedbackLabel);
    
    feedbackSlider.addListener(this);

    
}

FlangerAudioProcessorEditor::~FlangerAudioProcessorEditor()
{
}

//==============================================================================
void FlangerAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
}

void FlangerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    depthSlider.setBounds(20, (getHeight() / 2) - 25, 75, 75);
    rateSlider.setBounds(95, (getHeight() / 2) - 25, 75, 75);
    mixSlider.setBounds(170, (getHeight() / 2) - 25, 75, 75);
    delaySlider.setBounds(245, (getHeight() / 2) - 25, 75, 75);
    feedbackSlider.setBounds(320, (getHeight() / 2) - 25, 75, 75);
}

void FlangerAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    processor.depth = depthSlider.getValue() / 100;
    processor.rate = rateSlider.getValue();
    processor.mix = mixSlider.getValue() / 100;
    processor.delay = delaySlider.getValue() / 1000;
    processor.feedback = feedbackSlider.getValue() / 1000;
}
