/*
  ==============================================================================

    Marquee.cpp
    Created: 7 May 2022 8:39:03pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#ifdef MARQUEE_H_INCLUDED
    #error "incorrect use of cpp file"
#endif

#include "nberr_Marquee.h"

//==============================================================================
Marquee::Marquee(const juce::String& text, ScrollDirection direction, int speed, bool shouldPause)
{
    setText(text, juce::NotificationType::dontSendNotification);
    
    scrollDirection = direction;
    
    assert(speed > -1);
    scrollSpeed = speed;
    
    pauseEnabled = shouldPause;
    
    startTimer(10);
}

Marquee::~Marquee()
{
    
}

//==============================================================================
void Marquee::paint(juce::Graphics& g)
{
    g.setColour(findColour(juce::Label::textColourId));
    g.drawText(getText(), textX, textY, getFont().getStringWidth(getText()), getHeight(), getJustificationType());
}

void Marquee::timerCallback()
{
    if (pauseEnabled) {
        
        if (currentTime > 0) {
            currentTime--;
            return;
        }
        
    }
    tick();
    
    repaint();
}

//==============================================================================
void Marquee::setScrollDirection(ScrollDirection direction)
{
    scrollDirection = direction;
}

Marquee::ScrollDirection Marquee::getScrollDirection()
{
    return scrollDirection;
}

void Marquee::setScrollSpeed(int speed)
{
    assert(speed > -1);
    scrollSpeed = speed;
}

int Marquee::getScrollSpeed()
{
    return scrollSpeed;
}

//==============================================================================
void Marquee::setShouldPause(bool shouldPause)
{
    pauseEnabled = shouldPause;
}

bool Marquee::getPauseEnabled()
{
    return pauseEnabled;
}

void Marquee::setPauseTime(int time)
{
    assert(time > -1);
    pauseTime = time;
}

int Marquee::getPauseTime()
{
    return pauseTime;
}

//==============================================================================
void Marquee::tick()
{
    switch (scrollDirection) {
       
        case Marquee::ScrollDirection::HorizonalLeft:
            
            textX -= scrollSpeed;
            
            if (textX == 0) {
                currentTime = pauseTime;
            }
            
            if (textX < -getFont().getStringWidth(getText())) {
                textX = getWidth();
            }
            
            break;
            
        case Marquee::ScrollDirection::HorizonalRight:
            
            textX += scrollSpeed;
            if (textX > getWidth()) {
                textX = -getFont().getStringWidth(getText());
            }
            
            break;
            
        case Marquee::ScrollDirection::VerticalDown:
            
            textY += scrollSpeed;
            if (textY > getHeight()) {
                textY = -getHeight();
            }
            
            break;
            
        case Marquee::ScrollDirection::VerticalUp:
            
            textY -= scrollSpeed;
            if (textY < -getHeight()) {
                textY = getHeight();
            }
            
            break;
            
        default:
            jassertfalse;
            break;
    }
}
