//
//  Snake.cpp
//  Snake
//
//  Created by Joseph Lyons on 8/5/17.
//
//

#include "Snake.hpp"
#include "DirectionMovementEnum.h"

Snake::Snake()
{
    // Create head
    head.setXY(11, 11);
    snakeCellArray.add(head);
    
    // Initial direction of travel
    directionMoving = up;
}

Array<Point<int>>* Snake::getSnakeCellArray()
{
    return &snakeCellArray;
}

void Snake::move()
{
    if(directionMoving == left)
    {
        newPoint.setXY(snakeCellArray[0].getX() - 1, snakeCellArray[0].getY());
        
        if (newPoint.x == 0)
            newPoint.setX(21);
        
        snakeCellArray.insert(0, newPoint);
    }
    
    else if(directionMoving == up)
    {
        newPoint.setXY(snakeCellArray[0].getX(), snakeCellArray[0].getY() - 1);
        
        if (newPoint.y == 0)
            newPoint.setY(21);
        
        snakeCellArray.insert(0, newPoint);
    }
    
    else if(directionMoving == right)
    {
        newPoint.setXY(snakeCellArray[0].getX() + 1, snakeCellArray[0].getY());
        
        if (newPoint.x == 22)
            newPoint.setX(1);
        
        snakeCellArray.insert(0, newPoint);
    }
    
    // Down
    else
    {
        newPoint.setXY(snakeCellArray[0].getX(), snakeCellArray[0].getY() + 1);
        
        if (newPoint.y == 22)
            newPoint.setY(1);
        
        snakeCellArray.insert(0, newPoint);
    }
    
    snakeCellArray.removeLast();
}

void Snake::grow()
{
    Point<int> lastSnakeUnit(snakeCellArray.getLast().x, snakeCellArray.getLast().y);
    
    snakeCellArray.insert(snakeCellArray.size(), lastSnakeUnit);
}

void Snake::resetSnake()
{
    snakeCellArray.clear();
    snakeCellArray.add(head);
}

bool Snake::didSnakeRunIntoHimself()
{
    for (int i = 1; i < snakeCellArray.size(); i++)
    {
        if (snakeCellArray[0] == snakeCellArray[i])
            return true;
    }
           
    return false;
}

void Snake::setDirectionMoving(const int &input)
{
    directionMoving = input;
}


int Snake::getDirectionMoving()
{
    return directionMoving;
}

