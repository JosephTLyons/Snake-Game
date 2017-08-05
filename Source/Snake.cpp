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
}

Array<Point<int>>* Snake::getSnakeCellArray()
{
    return &snakeCellArray;
}
