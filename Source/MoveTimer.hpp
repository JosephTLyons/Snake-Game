//
//  MoveTimer.hpp
//  Snake
//
//  Created by Joseph Lyons on 8/5/17.
//
//

#ifndef MoveTimer_hpp
#define MoveTimer_hpp

#include "../JuceLibraryCode/JuceHeader.h"
#include "Snake.hpp"

class MoveTimer : private Timer
{
private:
    Snake *snakePtr;
public:
    MoveTimer();
    ~MoveTimer();
    
    void startMoveTimer();
    void setSnake(Snake &input);
    void timerCallback() override;
};

#endif /* MoveTimer_hpp */
