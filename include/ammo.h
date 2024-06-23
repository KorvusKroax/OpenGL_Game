#include <openGL/open_gl.h>
#include <misc/canvas.h>

class Ammo
{
    private:
        float x, y;
        Sprite *sprite;
        float speed;

        void show(Canvas *canvas);

    public:
        Ammo(float x, float y, Sprite *sprite, float speed);
        ~Ammo();

        bool update(OpenGL *openGL, Canvas *canvas);
};
