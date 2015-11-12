#ifndef ____MenuState__
#define ____MenuState__

#include "State.h"

class MenuState : public State {
public:
    void update(unsigned long dt);
    void render();
};

#endif /* defined(____MenuState__) */
