#include <ammo.h>

Ammo::Ammo(float x, float y, float w, float h, float speed)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
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
    canvas->drawRectangle(int(x - w * .5f), int(y - h * .5f), w, h, ColorRGBA(255, 255, 255, 255));
}
