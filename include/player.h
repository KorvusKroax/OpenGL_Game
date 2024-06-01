// #include <iostream>

#include <open_gl.h>
#include <canvas.h>

class Player
{
    private:
        void fire();

    public:
        int x, y;

        Player(int x, int y);
        ~Player();
        void show(Canvas *canvas);
        void processInput(OpenGL *openGL);
};
