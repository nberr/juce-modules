/*
  ==============================================================================
    BEGIN_JUCE_MODULE_DECLARATION

    ID:            nberr_Marquee
    vendor:        Nicholas Berriochoa
    version:       1.0.0
    name:          Marquee
    description:   Marquee or "scrolling text" JUCE component
    website:       https://nberr.io
    license:       https://github.com/nberr/juce-marquee/blob/main/LICENSE

    dependencies:

    END_JUCE_MODULE_DECLARATION


  ==============================================================================
*/

#pragma once
#define MARQUEE_H_INCLUDED

#include <JuceHeader.h>

//==============================================================================
class Marquee
:   public juce::Label,
    public juce::Timer
{
public:
    //==============================================================================
    enum ScrollDirection {
        HorizonalLeft,
        HorizonalRight,
        VerticalDown,
        VerticalUp
    };
    
    //==============================================================================
    Marquee(const juce::String& text = juce::String(), ScrollDirection direction = HorizonalLeft, int speed = 1, bool shouldPause = false);
    ~Marquee();
    
    //==============================================================================
    void paint(juce::Graphics& g) override;
    void timerCallback() override;
    
    //==============================================================================
    void setScrollDirection(ScrollDirection direction);
    ScrollDirection getScrollDirection();
    
    void setScrollSpeed(int speed);
    int getScrollSpeed();
    
    //==============================================================================
    void setShouldPause(bool shouldPause);
    bool getPauseEnabled();
    
    void setPauseTime(int time);
    int getPauseTime();
    
private:
    //==============================================================================
    void tick();
    
    //==============================================================================
    ScrollDirection scrollDirection;
    int scrollSpeed;

    int textX = 0;
    int textY = 0;
    
    //==============================================================================
    bool pauseEnabled;
    int pauseTime = 0;
    int currentTime = 0;
    
    //==============================================================================
    bool shouldRepeat;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Marquee)
};
