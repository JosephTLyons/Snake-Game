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
    
public:
    Snake();
    Array<Point<int>>* getSnakeCellArray();
};

#endif /* Snake_hpp */
