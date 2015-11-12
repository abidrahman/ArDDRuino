/*
 * Routine for drawing an image patch from the SD card to the LCD display.
 */

#ifndef _LCD_IMAGE_H
#define _LCD_IMAGE_H

typedef struct {
  char *file_name;
  uint16_t ncols;
  uint16_t nrows;
} lcd_image_t;

/* Draws the referenced image to the LCD screen.
 *
 * img           : the image to draw
 * tft           : the initialized tft struct
 * icol, irow    : the upper-left corner of the image patch to draw
 * scol, srow    : the upper-left corner of the screen to draw to
 * width, height : controls the size of the patch drawn.
 */
void lcd_image_draw(lcd_image_t *img, Adafruit_ST7735 *tft,
		    uint16_t icol, uint16_t irow, 
		    uint16_t scol, uint16_t srow, 
		    uint16_t width, uint16_t height);

#endif
