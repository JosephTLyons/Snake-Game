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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainGameView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainGameView::MainGameView ()
{
    //[Constructor_pre] You can add your own custom stuff here..

    cellPixelSize = 20;
    refreshTime = 1000 / 4;
    gridModeIsOn = false;

    //[/Constructor_pre]

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (420, 420);


    //[Constructor] You can add your own custom stuff here..

    startTimer(refreshTime);

    //[/Constructor]
}

MainGameView::~MainGameView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainGameView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..

    g.setColour(Colours::black);

    for (int i = cellPixelSize; i < getWidth(); i += cellPixelSize)
    {
        g.drawLine(i, 0, i, getHeight());
    }

    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..

    if(gridModeIsOn)
    {
        // Paint grid
        g.setColour(Colours::black);
        
        for (int i = cellPixelSize; i < getWidth(); i += cellPixelSize)
        {
            g.drawLine(i, 0, i, getHeight());
        }
        
        for (int i = cellPixelSize; i < getHeight(); i += cellPixelSize)
        {
            g.drawLine(0, i, getWidth(), i);
        }
    }

    // Paint snake
    g.setColour(Colours::green);
    int x, y;
    
    for (int i = 0; i < snake.getSnakeCellArray()->size(); i++)
    {
        x = (*snake.getSnakeCellArray())[i].x - 1;
        y = (*snake.getSnakeCellArray())[i].y - 1;

        g.fillRect((x * cellPixelSize) + 2, (y * cellPixelSize) + 2,
                   cellPixelSize - 4, cellPixelSize - 4);
    }

    //[/UserPaint]
}

void MainGameView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (352, 368, 30, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainGameView::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        //[/UserButtonCode_textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

bool MainGameView::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...

    if (key == KeyPress::leftKey && snake.getDirectionMoving() != left)
    {
        snake.setDirectionMoving(left);
        snake.move();
        
        // This effectively restarts the timer, which keeps glitches from occuring when changing directions
        // IE, double space jumps that occured previously after a movement change
        startTimer(refreshTime);
    }

    else if (key == KeyPress::upKey && snake.getDirectionMoving() != up)
    {
        snake.setDirectionMoving(up);
        snake.move();
        startTimer(refreshTime);
    }

    else if (key == KeyPress::rightKey && snake.getDirectionMoving() != right)
    {
        snake.setDirectionMoving(right);
        snake.move();
        startTimer(refreshTime);
    }

    else if (key == KeyPress::downKey && snake.getDirectionMoving() != down)
    {
        snake.setDirectionMoving(down);
        snake.move();
        startTimer(refreshTime);
    }
    
    repaint();

    return true;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MainGameView::timerCallback()
{
    snake.move();

    repaint();
}

int MainGameView::getCellPixelSize()
{
    return cellPixelSize;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainGameView" componentName=""
                 parentClasses="public Component, public Timer" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="420" initialHeight="420"
                 lastSelectedTab="0">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="new button" id="7734a1b05f416e14" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="352 368 30 24" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
