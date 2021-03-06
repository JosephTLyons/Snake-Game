/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Snake.hpp"
#include "DirectionMovementEnum.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainGameView  : public Component,
                      public Timer,
                      public KeyListener,
                      public ButtonListener
{
public:
    //==============================================================================
    MainGameView ();
    ~MainGameView();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void timerCallback() override;
    int getCellPixelSize();
    bool keyPressed (const KeyPress &key, Component *originatingComponent) override;
    void gameOver();
    void setAppleLocation();

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    int cellPixelSize;
    Snake snake;
    float refreshTime;
    bool gridModeIsOn;

    Random randomNumberGenerator;
    Point<int> appleLocation;
    unsigned int applesConstumed;
    unsigned int poopCountDown;
    Array<Point<int>> poopLocationArray;

    // Used for painting snake, apple, and poop locations
    int xCoordinate, yCoordinate;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> startGameButton;
    ScopedPointer<Label> youLostLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainGameView)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
