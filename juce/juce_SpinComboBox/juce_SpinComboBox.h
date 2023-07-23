/*
  ==============================================================================

    juce_SpinComboBox.h
    Created: 20 May 2022 3:30:45pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once
#define SPINCOMBOBOX_H_INCLUDED

#include <JuceHeader.h>

//==============================================================================
class SpinComboBox
:   public juce::Component,
    public juce::ComboBox::Listener,
    public juce::Button::Listener
{
public:
//==============================================================================
    SpinComboBox();
    ~SpinComboBox();
    
    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;
    
    //==============================================================================
    void buttonClicked(juce::Button* b) override;
    void comboBoxChanged(juce::ComboBox* cb) override;
    
    //==============================================================================
    juce::ComboBox* getComboBox();
    
private:
    //==============================================================================
    bool hasEnabledItems();
    int getNextEnabledIndex();
    int getPreviousEnabledIndex();
    
    juce::ComboBox comboBox;
    juce::ArrowButton prevButton;
    juce::ArrowButton nextButton;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SpinComboBox)
};
