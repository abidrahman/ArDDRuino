//
//  ScoreState.h
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#ifndef ____ScoreState__
#define ____ScoreState__

#include "State.h"

class ScoreState : public State {
public:
    void update(unsigned long dt);
    void render();
};

#endif /* defined(____ScoreState__) */
