#pragma once

struct ColorRGBA
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
    unsigned int value;

    ColorRGBA(unsigned int _r = 0, unsigned int _g = 0, unsigned int _b = 0, unsigned int _a = 0)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
        updateValue();
    }

    void updateValue()
    {
        value = r|(g<<8)|(b<<16)|(a<<24);
    }
};

// ColorRGBA black = ColorRGBA(0, 0, 0, 255);
// ColorRGBA gray = ColorRGBA(128, 128, 128, 255);
// ColorRGBA white = ColorRGBA(255, 255, 255, 255);
// ColorRGBA red = ColorRGBA(255, 0, 0, 255);
// ColorRGBA green = ColorRGBA(0, 255, 0, 255);
// ColorRGBA blue = ColorRGBA(0, 0, 255, 255);
// ColorRGBA yellow = ColorRGBA(255, 255, 0, 255);
// ColorRGBA purple = ColorRGBA(255, 0, 255, 255);
// ColorRGBA cyan = ColorRGBA(0, 255, 255, 255);
// ColorRGBA orange = ColorRGBA(255, 128, 0, 255);
// ColorRGBA pink = ColorRGBA(255, 128, 128, 255);
// ColorRGBA brown = ColorRGBA(128, 128, 0, 255);
