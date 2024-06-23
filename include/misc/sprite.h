#pragma once

class Sprite
{
    public:
        unsigned int width;
        unsigned int height;
        int *pixels;

        Sprite() { }

        ~Sprite() { delete[] pixels; }

        Sprite(int width, int height, int *pixels)
        {
            this->width = width;
            this->height = height;
            this->pixels = pixels;
        }
};
