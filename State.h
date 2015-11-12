//
//  State.h
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#ifndef ____State__
#define ____State__

class State {
public:
    virtual void update(unsigned long dt) = 0;
    virtual void render() = 0;
};



#endif /* defined(____State__) */
