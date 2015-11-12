#ifndef NOTESPRITE_CPP
#define NOTESPRITE_CPP

class NoteSprite
{
	public:
	NoteSprite (int x, int y) {
		this.x = x;
		this.y = y;
		
	};
	
	void update (int dt);
	void render ();
	int x;
	int y;
	int vy;
};


#endif