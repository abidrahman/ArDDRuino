#ifndef NOTESPRITE_CPP
#define NOTESPRITE_CPP

class NoteSprite
{
public:
    
	NoteSprite (int x, int y) {
        this->x;
        this->y;
	};
	
	void update (unsigned long dt);
	void render ();
	const static int RADIUS = 15;
	int x;
	int y;
	const static int vy = -10;
};


#endif
