//
//  MoveTimer.cpp
//  Snake
//
//  Created by Joseph Lyons on 8/5/17.
//
//

#include "MoveTimer.hpp"

MoveTimer::MoveTimer()
{
    
}


MoveTimer::~MoveTimer()
{
    
}

void MoveTimer::startMoveTimer()
{
    startTimer(1000 / 3);
}

void MoveTimer::setSnake(Snake &input)
{
    snakePtr = &input;
}

void MoveTimer::timerCallback()
{
    snakePtr->move();
}
