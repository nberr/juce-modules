/*
  ==============================================================================
    BEGIN_JUCE_MODULE_DECLARATION
    ID:            juce_Spinner
    vendor:        Nicholas Berriochoa
    version:       1.0.0
    name:          Spinner
    description:   Spinner UI Component
    website:       https://nberr.io
    license:       https://github.com/nberr/juce-spinner/blob/main/LICENSE
    dependencies:
    END_JUCE_MODULE_DECLARATION
  ==============================================================================
*/

#pragma once
#define SPINNER_H_INCLUDED

#include <JuceHeader.h>

//==============================================================================
class Spinner
:   public juce::Component,
    public juce::Button::Listener,
    public juce::TextEditor::Listener
{
public:
    //==============================================================================
    Spinner();
    ~Spinner();
    
    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;
    
    //==============================================================================
    void buttonClicked(juce::Button* b) override;
    void textEditorReturnKeyPressed(juce::TextEditor& te) override;
    
    //==============================================================================
    int getValue();
    void setValue(int value);
    
private:
    //==============================================================================
    juce::TextEditor textDisplay;
    juce::ArrowButton upButton {"Up Button", 0.75, juce::Colours::black};
    juce::ArrowButton downButton {"Down Button", 0.25, juce::Colours::black};
    
    int currentValue;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Spinner)
};
