#include <openGL/open_gl.h>
#include <misc/canvas.h>

class Ammo
{
    private:
        float x, y;
        int width, height;
        float speed;

        void show(Canvas *canvas);

    public:
        Ammo(float x, float y, int width, int height, float speed);
        ~Ammo();

        bool update(OpenGL *openGL, Canvas *canvas);
};
