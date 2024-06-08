#include <openGL/open_gl.h>
#include <misc/canvas.h>
#include <ammo.h>

class Player
{
    private:
        float x, y;

        int width = 20;
        int height = 5;
        float speed = 100;

        Ammo *ammo = nullptr;

        void show(Canvas *canvas);
        void control(OpenGL *openGL, Canvas *canvas);
        void fire();

    public:
        Player(float x, float y);
        ~Player();

        bool update(OpenGL *openGL, Canvas *canvas);
};
