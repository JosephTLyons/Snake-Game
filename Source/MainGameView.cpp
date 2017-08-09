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
    gridModeIsOn = true;
    applesConstumed = 0;
    poopCountDown = randomNumberGenerator.nextInt(3) + 3;;

    //[/Constructor_pre]

    addAndMakeVisible (startGameButton = new TextButton ("startGameButton"));
    startGameButton->setButtonText (TRANS("Start Game"));
    startGameButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (420, 420);


    //[Constructor] You can add your own custom stuff here..

    randomNumberGenerator.setSeed(Time::currentTimeMillis());
    setAppleLocation();

    // Set up code to allow arrow key usage
    addKeyListener(this);
    setWantsKeyboardFocus(true);

    //[/Constructor]
}

MainGameView::~MainGameView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    startGameButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainGameView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
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

    // Paint apple
    xCoordinate = appleLocation.x - 1;
    yCoordinate = appleLocation.y - 1;

    g.setColour(Colours::red);
    g.fillRect((xCoordinate * cellPixelSize) + 2, (yCoordinate * cellPixelSize) + 2,
                cellPixelSize - 4, cellPixelSize - 4);

    // Paint snake
    g.setColour(Colours::green);

    for (int i = 0; i < snake.getSnakeCellArray()->size(); i++)
    {
        xCoordinate = (*snake.getSnakeCellArray())[i].x - 1;
        yCoordinate = (*snake.getSnakeCellArray())[i].y - 1;

        g.fillRect((xCoordinate * cellPixelSize) + 2, (yCoordinate * cellPixelSize) + 2,
                   cellPixelSize - 4, cellPixelSize - 4);
    }

    // Paint poop
    for (int i = 0; i < poopLocationArray.size(); i++)
    {
        xCoordinate = poopLocationArray[i].x - 1;
        yCoordinate = poopLocationArray[i].y - 1;

        g.setColour(Colours::brown);
        g.fillRect((xCoordinate * cellPixelSize) + 2, (yCoordinate * cellPixelSize) + 2,
                   cellPixelSize - 4, cellPixelSize - 4);
    }

    //[/UserPaint]
}

void MainGameView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    startGameButton->setBounds (160, 90, 100, 30);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainGameView::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == startGameButton)
    {
        //[UserButtonCode_startGameButton] -- add your button handler code here..

        startTimer(refreshTime);
        startGameButton->setVisible(false);

        //[/UserButtonCode_startGameButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

bool MainGameView::keyPressed (const KeyPress &key, Component *originatingComponent)
{
    if (key == KeyPress::leftKey && snake.getDirectionMoving() != left)
    {
        snake.setDirectionMoving(left);
        snake.move();

        // This effectively restarts the timer, which keeps glitches from occuring when changing directions
        // IE, double space jumps that occured previously after a movement change
        stopTimer();
        startTimer(refreshTime);

    }

    else if (key == KeyPress::upKey && snake.getDirectionMoving() != up)
    {
        snake.setDirectionMoving(up);
        snake.move();

        stopTimer();
        startTimer(refreshTime);
    }

    else if (key == KeyPress::rightKey && snake.getDirectionMoving() != right)
    {
        snake.setDirectionMoving(right);
        snake.move();

        stopTimer();
        startTimer(refreshTime);
    }

    else if (key == KeyPress::downKey && snake.getDirectionMoving() != down)
    {
        snake.setDirectionMoving(down);
        snake.move();

        stopTimer();
        startTimer(refreshTime);
    }

    repaint();

    return true;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
}

void MainGameView::timerCallback()
{
    snake.move();

    if(snake.didSnakeRunIntoHimself())
        gameOver();

//    else if(/* didSnakeRunIntoPoop */)
//       gameOver();

    else
        repaint();

    if((*snake.getSnakeCellArray())[0] == appleLocation)
    {
        snake.grow();
        setAppleLocation();

        if(--poopCountDown == 0)
        {
            poopLocationArray.add(snake.getSnakeCellArray()->getLast());
            snake.getSnakeCellArray()->removeLast();
            poopCountDown = randomNumberGenerator.nextInt(3) + 3;;
        }
    }
}

int MainGameView::getCellPixelSize()
{
    return cellPixelSize;
}

void MainGameView::gameOver()
{
    stopTimer();

    // Display "You Lost" label
    youLostLabel = new Label ("You Lost Label", TRANS("You Lost!"));
    youLostLabel->setFont (Font (22.60f, Font::plain).withTypefaceStyle ("Regular"));
    youLostLabel->setJustificationType (Justification::centred);
    youLostLabel->setEditable (false, false, false);
    youLostLabel->setColour (Label::textColourId, Colours::black);
    youLostLabel->setColour (TextEditor::textColourId, Colours::black);
    youLostLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    youLostLabel->setBounds(160, 60, 100, 30);
    youLostLabel->setVisible(true);

    // Display "Start Game" button
    startGameButton->setVisible(true);

    snake.resetSnake();
}

void MainGameView::setAppleLocation()
{
    appleLocation.setXY(randomNumberGenerator.nextInt(21) + 1,
                        randomNumberGenerator.nextInt(21) + 1);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainGameView" componentName=""
                 parentClasses="public Component, public Timer, public KeyListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="420"
                 initialHeight="420" lastSelectedTab="1">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="startGameButton" id="7734a1b05f416e14" memberName="startGameButton"
              virtualName="" explicitFocusOrder="0" pos="160 90 100 30" buttonText="Start Game"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
