#include <ammo.h>

Ammo::Ammo(float x, float y, Sprite *sprite, float speed)
{
    this->x = x;
    this->y = y;
    this->sprite = sprite;
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
    canvas->drawSprite(x, y, sprite, true);
}
