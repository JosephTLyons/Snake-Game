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

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->addListener (this);

    addAndMakeVisible (textButton2 = new TextButton ("new button"));
    textButton2->addListener (this);

    addAndMakeVisible (textButton3 = new TextButton ("new button"));
    textButton3->addListener (this);

    addAndMakeVisible (textButton4 = new TextButton ("new button"));
    textButton4->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (420, 420);


    //[Constructor] You can add your own custom stuff here..

    addKeyListener (keyListener);

    //[/Constructor]
}

MainGameView::~MainGameView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;
    textButton2 = nullptr;
    textButton3 = nullptr;
    textButton4 = nullptr;


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

    textButton->setBounds (272, 360, 40, 24);
    textButton2->setBounds (304, 328, 40, 24);
    textButton3->setBounds (336, 360, 40, 24);
    textButton4->setBounds (304, 392, 40, 24);
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

        snake.setDirectionMoving(left);
        snake.move();
        repaint();

        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..

        snake.setDirectionMoving(up);
        snake.move();
        repaint();

        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3)
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..

        snake.setDirectionMoving(right);
        snake.move();
        repaint();

        //[/UserButtonCode_textButton3]
    }
    else if (buttonThatWasClicked == textButton4)
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..

        snake.setDirectionMoving(down);
        snake.move();
        repaint();

        //[/UserButtonCode_textButton4]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="420" initialHeight="420" lastSelectedTab="2">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="new button" id="4882f1220db3feb6" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="272 360 40 24" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="ce57f112cc041ac0" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="304 328 40 24" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a0dee57e89f4893" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="336 360 40 24" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="7719c1dc995e0c3c" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="304 392 40 24" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
