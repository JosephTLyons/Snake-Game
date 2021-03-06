//
//  Snake.hpp
//  Snake
//
//  Created by Joseph Lyons on 8/5/17.
//
//

#ifndef Snake_hpp
#define Snake_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class Snake
{
private:
    Array<Point<int>> snakeCellArray;
    Point<int> head;
    Point<int> newPoint;
    
    // Left = 0, Up = 1, Right = 2, Down = 3
    int directionMoving;
    
public:
    Snake();
    
    Array<Point<int>>* getSnakeCellArray();
    void move(const int &direction);
    void grow();
    void resetSnake();
    
    bool didSnakeRunIntoHimself();
    
    int getDirectionMoving() const;
    
};

#endif /* Snake_hpp */
