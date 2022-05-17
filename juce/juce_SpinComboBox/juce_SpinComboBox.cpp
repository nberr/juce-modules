/*
  ==============================================================================
    Spinner.cpp
    Created: 10 May 2022 8:39:03pm
    Author:  Nicholas Berriochoa
  ==============================================================================
*/

#ifdef SPINNER_H_INCLUDED
    #error "incorrect use of cpp file"
#endif

#include "juce_Spinner.h"

//==============================================================================
Spinner::Spinner()
{
    currentValue = 0;
    
    textDisplay.setText(juce::String(currentValue));
    textDisplay.addListener(this);
    addAndMakeVisible(textDisplay);
    
    upButton.addListener(this);
    addAndMakeVisible(upButton);
    
    downButton.addListener(this);
    addAndMakeVisible(downButton);
}

Spinner::~Spinner()
{
    
}

//==============================================================================
void Spinner::paint(juce::Graphics& g)
{
    
}

void Spinner::resized()
{
    textDisplay.setBounds(0, 0, getWidth() * 0.75, getHeight());
    upButton.setBounds(textDisplay.getRight(), 0, getWidth() * 0.25, getHeight()*0.5f);
    downButton.setBounds(textDisplay.getRight(), upButton.getBottom(), getWidth() * 0.25, getHeight() * 0.5);
}

//==============================================================================
void Spinner::buttonClicked(juce::Button* b)
{
    if (b == &upButton) {
        currentValue++;
        textDisplay.setText(juce::String(currentValue));
    }
    else if (b == &downButton) {
        currentValue--;
        textDisplay.setText(juce::String(currentValue));
    }
}

void Spinner::textEditorReturnKeyPressed(juce::TextEditor& te)
{
    if (&te == &textDisplay) {
        
    }
}

//==============================================================================
int Spinner::getValue()
{
    return currentValue;
}

void Spinner::setValue(int value)
{
    
}
