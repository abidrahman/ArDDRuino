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

void NoteSprite::setX(int x) {
    this->x = (float)x;
}

void NoteSprite::setY(int y) {
    this->y = (float)y;
}



void NoteSprite::update(unsigned long dt) {
    y = y + VELOCITY * dt / 1000000;
}


