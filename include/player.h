#include <openGL/open_gl.h>
#include <misc/canvas.h>
#include <ammo.h>

class Player
{
    private:
        float x, y, w, h, speed;
        Ammo *ammo = nullptr;

        void show(Canvas *canvas);

        void control(OpenGL *openGL, Canvas *canvas);
        void fire();

    public:
        Player(float x, float y, float w, float h, float speed);
        ~Player();

        bool update(OpenGL *openGL, Canvas *canvas);
};
