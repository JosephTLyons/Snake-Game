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
    
    snakeCellArray.add(Point<int> (11, 12));
    snakeCellArray.add(Point<int> (11, 13));
    snakeCellArray.add(Point<int> (11, 14));
    snakeCellArray.add(Point<int> (11, 15));
    snakeCellArray.add(Point<int> (11, 16));
    snakeCellArray.add(Point<int> (11, 17));
    snakeCellArray.add(Point<int> (11, 18));
    snakeCellArray.add(Point<int> (11, 19));
    
    
    // Start off moving left
    directionMoving = 0;
}

Array<Point<int>>* Snake::getSnakeCellArray()
{
    return &snakeCellArray;
}

void Snake::move()
{
    if(directionMoving == 0)
    {
        newPoint.setXY(snakeCellArray[0].getX() - 1, snakeCellArray[0].getY());
        snakeCellArray.insert(0, newPoint);
    }
    
    // Up
    else if(directionMoving == 1)
    {
        newPoint.setXY(snakeCellArray[0].getX(), snakeCellArray[0].getY() - 1);
        snakeCellArray.insert(0, newPoint);
    }
    
    // Right
    else if(directionMoving == 2)
    {
        newPoint.setXY(snakeCellArray[0].getX() + 1, snakeCellArray[0].getY());
        snakeCellArray.insert(0, newPoint);
    }
    
    // Down
    else
    {
        newPoint.setXY(snakeCellArray[0].getX(), snakeCellArray[0].getY() + 1);
        snakeCellArray.insert(0, newPoint);
    }
    
    snakeCellArray.removeLast();
}

void Snake::addUnit()
{
    
}

void Snake::setDirectionMoving(const int &input)
{
    directionMoving = input;
}


int Snake::getDirectionMoving()
{
    return directionMoving;
}

