#include <ammo.h>

Ammo::Ammo(float x, float y, int width, int height, float speed)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = speed;
}

Ammo::~Ammo() { }

bool Ammo::update(OpenGL *openGL, Canvas *canvas)
{
    if (y > canvas->height) return false;

    y += speed * openGL->deltaTime;
    show(canvas);

    return true;
}

void Ammo::show(Canvas *canvas)
{
    canvas->drawRectangle((int)x - (width >> 1), (int)y - (height >> 1), width, height, ColorRGBA(255, 255, 255, 255));
}
