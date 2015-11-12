#ifndef ____MenuState__
#define ____MenuState__

struct Joystick {
    int delta_vert;
    int delta_horiz;
    boolean pushed;
};

void updateMenuState(unsigned long dt);
void renderMenuState(Adafruit_ST7735 &tft, Joystick joystick);

#endif /* defined(____MenuState__) */
