#ifndef NOTESPRITE_CPP
#define NOTESPRITE_CPP

class NoteSprite
{
public:
    
	const static int RADIUS = 15;
	const static int VELOCITY = -10;

	boolean onScreen;

	int x;
	int y;

	void update(unsigned long dt);

};


#endif
