#include <openGL/open_gl.h>
#include <misc/canvas.h>

class Enemy
{
    private:
        void show(Canvas *canvas);

    public:
        float x, y, w, h, speed;

        Enemy(float x, float y, float w, float h, float speed);
        ~Enemy();

        void update(OpenGL *openGL, Canvas *canvas);
};
