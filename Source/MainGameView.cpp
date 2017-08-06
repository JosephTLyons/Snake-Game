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

    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (420, 420);


    //[Constructor] You can add your own custom stuff here..

    startTimer(1000 / 3);

    //[/Constructor]
}

MainGameView::~MainGameView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



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

    // Paint snake
    g.setColour(Colours::green);

    for (int i = 0; i < snake.getSnakeCellArray()->size(); i++)
    {
        int x = (*snake.getSnakeCellArray())[i].x - 1;
        int y = (*snake.getSnakeCellArray())[i].y - 1;

        g.fillRect(x * cellPixelSize, y * cellPixelSize, cellPixelSize, cellPixelSize);
    }

    //[/UserPaint]
}

void MainGameView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

bool MainGameView::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...

    if (key == KeyPress::leftKey)
    {
        snake.setDirectionMoving(left);
        snake.move();
    }

    else if (key == KeyPress::upKey)
    {
        snake.setDirectionMoving(up);
        snake.move();
    }

    else if (key == KeyPress::rightKey)
    {
        snake.setDirectionMoving(right);
        snake.move();
    }

    else if (key == KeyPress::downKey)
    {
        snake.setDirectionMoving(down);
        snake.move();
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
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
