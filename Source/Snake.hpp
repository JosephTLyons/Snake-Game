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
    
    Point<int> newPoint;
    
    // Left = 0, Up = 1, Right = 2, Down = 3
    int directionMoving;
    
public:
    Snake();
    
    Array<Point<int>>* getSnakeCellArray();
    void move();
    void grow();
    bool didSnakeRunIntoHimself();
    void setDirectionMoving(const int &input);
    int getDirectionMoving();
    
};

#endif /* Snake_hpp */
