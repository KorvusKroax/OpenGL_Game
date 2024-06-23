#include <openGL/open_gl.h>
#include <misc/canvas.h>
#include <misc/sprite.h>
#include <ammo.h>

class Player
{
    private:
        float x, y;
        Sprite *sprite;
        float speed = 100;

        Sprite *ammoSprite;
        Ammo *ammo = nullptr;

        void show(Canvas *canvas);
        void control(OpenGL *openGL, Canvas *canvas);
        void fire();

    public:
        Player(float x, float y, Sprite *sprite, Sprite *ammoSprite);
        ~Player();

        bool update(OpenGL *openGL, Canvas *canvas);
};
