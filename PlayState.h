//
//  PlayState.h
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#ifndef ____PlayState__
#define ____PlayState__

#include "State.h"

class PlayState : public State {
public:
    void update(unsigned long dt);
    void render();
};

#endif /* defined(____PlayState__) */
