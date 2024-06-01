#pragma once

#include <open_gl.h>
#include <canvas.h>

#include <iostream>
#include <chrono>

class Game
{
    private:
        void processInput(OpenGL *openGL);
        void processDisplay(Canvas *canvas);

    public:
        Game();
        ~Game();
};
