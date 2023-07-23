/*
  ==============================================================================

    juce_SpinComboBox.cpp
    Created: 20 May 2022 3:30:45pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "juce_SpinComboBox.h"

SpinComboBox::SpinComboBox()
:   prevButton("PrevButton", 0.5f, juce::Colours::black),
    nextButton("NextButton", 0.f, juce::Colours::black)
{
    prevButton.addListener(this);
    addAndMakeVisible(prevButton);
    
    comboBox.addListener(this);
    addAndMakeVisible(comboBox);
    
    nextButton.addListener(this);
    addAndMakeVisible(nextButton);
}

SpinComboBox::~SpinComboBox()
{
    
}

//==============================================================================
void SpinComboBox::paint(juce::Graphics& g)
{
    
}

void SpinComboBox::resized()
{
    prevButton.setBounds(0, 0, getHeight(), getHeight());
    comboBox.setBounds(prevButton.getRight(), 0, getWidth() - (getHeight() * 2), getHeight());
    nextButton.setBounds(comboBox.getRight(), 0, getHeight(), getHeight());
}
    
//==============================================================================
void SpinComboBox::buttonClicked(juce::Button* b)
{
    if (b == &nextButton) {
        
        if (hasEnabledItems()) {
            comboBox.setSelectedItemIndex(getNextEnabledIndex());
        }
        
    }
    else if (b == &prevButton) {
        
        if (hasEnabledItems()) {
            comboBox.setSelectedItemIndex(getPreviousEnabledIndex());
        }
        
    }
}

void SpinComboBox::comboBoxChanged(juce::ComboBox* cb)
{
    
}

//==============================================================================
juce::ComboBox* SpinComboBox::getComboBox()
{
    return &comboBox;
}

//==============================================================================
bool SpinComboBox::hasEnabledItems()
{
    for (int item_id = 1; item_id <= comboBox.getNumItems(); item_id++) {
        
        if (comboBox.isItemEnabled(item_id)) {
            return true;
        }
        
    }
    
    return false;
}

int SpinComboBox::getNextEnabledIndex()
{
    int min_value = 0;
    int max_value = comboBox.getNumItems() - 1;
    int new_value = comboBox.getSelectedItemIndex();
    
    for (int i = 0; i < comboBox.getNumItems(); i++) {
        
        new_value++;
        if (new_value > max_value) {
            new_value = min_value;
        }
        
        if (comboBox.isItemEnabled(new_value + 1)) {
            break;
        }
        
    }
    
    return new_value;
}

int SpinComboBox::getPreviousEnabledIndex()
{
    int min_value = 0;
    int max_value = comboBox.getNumItems() - 1;
    int new_value = comboBox.getSelectedItemIndex();
   
    for (int i = 0; i < comboBox.getNumItems(); i++) {
        
        new_value--;
        if (new_value < min_value) {
            new_value = max_value;
        }
        
        if (comboBox.isItemEnabled(new_value + 1)) {
            break;
        }
        
    }
    
    return new_value;
}
