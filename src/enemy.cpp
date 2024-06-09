#include <enemy.h>



Enemy::Enemy() { }

Enemy::Enemy(float x, float y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Enemy::~Enemy() { }

void Enemy::update(OpenGL *openGL, Canvas *canvas, float *speed, bool *turn, int *border)
{
    x += (*speed) * openGL->deltaTime;
    *turn = (*turn) || x + (canvas->width >> 1) <= (*border) || x + (canvas->width >> 1) >= canvas->width - 1 - (*border);
    show(canvas);
}

void Enemy::show(Canvas *canvas)
{
    canvas->drawRectangle(
        (int)x - (width >> 1) + (canvas->width >> 1),
        (int)y - (height >> 1) + (canvas->height >> 1),
        width, height,
        ColorRGBA(255, 255, 255, 255));

    canvas->setPixel((int)x + (canvas->width >> 1), (int)y + (canvas->height >> 1), ColorRGBA(255, 255, 255, 255));
}



// ------------------------------------------------------------------------------------------------------------------------------------------------------

EnemyGroup::EnemyGroup()
{
    enemies = new Enemy[enemyCountPerRow * enemyRowCount];

    int halfWidth = ((enemyWidth + spacing) * (enemyCountPerRow - 1)) >> 1;
    int halfHeight = ((enemyHeight + spacing) * (enemyRowCount - 1)) >> 1;

    for (int j = 0; j < enemyRowCount; j++) {
        for (int i = 0; i < enemyCountPerRow; i++) {
            enemies[i + j * enemyCountPerRow] = Enemy(
                (enemyWidth + spacing) * i - halfWidth,
                (enemyHeight + spacing) * j - halfHeight,
                enemyWidth, enemyHeight);
        }
    }
}

EnemyGroup::~EnemyGroup() { }

void EnemyGroup::update(OpenGL *openGL, Canvas *canvas)
{
    canvas->drawLine(border, 0, border, canvas->height - 1, ColorRGBA(255, 0, 0, 255));
    canvas->drawLine(canvas->width - 1 - border, 0, canvas->width - 1 - border, canvas->height - 1, ColorRGBA(255, 0, 0, 255));

    bool turn = false;
    for (int i = 0; i < enemyCountPerRow * enemyRowCount; i++) {
        enemies[i].update(openGL, canvas, &speed, &turn, &border);
    }
    if (turn) speed *= -1;
}
