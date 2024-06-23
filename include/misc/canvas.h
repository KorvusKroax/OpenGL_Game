#pragma once

#include <misc/sprite_sheet.h>
#include <misc/color_rgba.h>
#include <misc/vector2_int.h>

#include <cstdlib>
#include <string.h>

class Canvas
{
    public:
        unsigned int width;
        unsigned int height;
        int *pixels;

        Canvas();
        Canvas(unsigned int width, unsigned int height);
        ~Canvas();

        void clearCanvas();
        void fillCanvas(ColorRGBA color);

        void setPixel(Vector2Int p, ColorRGBA color);
        void setPixel(int x, int y, ColorRGBA color);
        void setPixel(int x, int y, int value);
        unsigned int getPixel(Vector2Int p);
        unsigned int getPixel(int x, int y);

        void drawRectangle(int x, int y, int w, int h, ColorRGBA color, bool centered = false);

        void drawLine(Vector2Int p1, Vector2Int p2, ColorRGBA color);
        void drawLine(int x1, int y1, int x2, int y2, ColorRGBA color);
        void drawLine_unsafe(int x1, int y1, int x2, int y2, ColorRGBA color);

        void drawCircle(Vector2Int p, int r, ColorRGBA color);
        void drawCircle(int x, int y, int r, ColorRGBA color);

        void floodFill(int x, int y, ColorRGBA color);
        void spanFill(int x, int y, ColorRGBA color);

        // void drawImage(int x, int y, const char *fileName);
        void drawSprite(int x, int y, Sprite *sprite, bool centered = false);
};
