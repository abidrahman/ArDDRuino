#include "NoteSprite.h"

int NoteSprite::getNote() {
    return note;
}

int NoteSprite::getX() {
    return (int)x;
}

int NoteSprite::getY() {
    return (int)y;
}

void NoteSprite::update(unsigned long dt) {
    y = y + VELOCITY * dt / 1000000;
}


