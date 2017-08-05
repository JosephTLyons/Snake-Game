//
//  Snake.cpp
//  Snake
//
//  Created by Joseph Lyons on 8/5/17.
//
//

#include "Snake.hpp"

Snake::Snake()
{
    // Create head
    Point<int> head(11, 11);
    snakeCellArray.add(head);
    
    // Start off moving left
    directionMoving = 0;
}

Array<Point<int>>* Snake::getSnakeCellArray()
{
    return &snakeCellArray;
}

void Snake::move()
{
    for(int i = 0; i < snakeCellArray.size(); i++)
    {
        // Left
        if(directionMoving == 0)
        {
            snakeCellArray[i].setX(snakeCellArray[i].getX() - 1);
        }
        
        // Up
        else if(directionMoving == 1)
        {
            snakeCellArray[i].setY(snakeCellArray[i].getY() - 1);
        }
        
        // Right
        else if(directionMoving == 2)
        {
            snakeCellArray[i].setX(snakeCellArray[i].getX() + 1);
        }
        
        // Down
        else
        {
            snakeCellArray[i].setY(snakeCellArray[i].getY() + 1);
        }
    }
}

void Snake::setDirectionMoving(const int &input)
{
    directionMoving = input;
}


int Snake::getDirectionMoving()
{
    return directionMoving;
}

