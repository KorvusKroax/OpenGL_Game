#include <openGL/open_gl.h>
#include <misc/canvas.h>

class Ammo
{
    private:
        void show(Canvas *canvas);

    public:
        float x, y, w, h, speed;

        Ammo(float x, float y, float w, float h, float speed);
        ~Ammo();

        bool update(OpenGL *openGL, Canvas *canvas);
};
