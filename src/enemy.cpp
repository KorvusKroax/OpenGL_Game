#include <enemy.h>

Enemy::Enemy(float x, float y, float w, float h, float speed)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->speed = speed;
}

Enemy::~Enemy() { }

void Enemy::update(OpenGL *openGL, Canvas *canvas)
{
    if (x < 0 || x > canvas->width - 1) speed *= -1;
    x += speed * openGL->deltaTime;
    show(canvas);
}



void Enemy::show(Canvas *canvas)
{
    canvas->drawRectangle(int(x - w * .5f), int(y - h * .5f), w, h, ColorRGBA(255, 255, 255, 255));
}
