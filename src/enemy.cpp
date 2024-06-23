#include <enemy.h>

Enemy::Enemy() { }

Enemy::Enemy(float x, float y, Sprite *sprite)
{
    this->x = x;
    this->y = y;
    this->sprite = sprite;
}

Enemy::~Enemy() { }

void Enemy::update(OpenGL *openGL, Canvas *canvas, float speed, bool *turn, int *border)
{
    x += (speed * openGL->deltaTime);
    *turn = (*turn) || x <= (sprite->width >> 1) || x > canvas->width - (sprite->width >> 1);
    show(canvas);
}

void Enemy::show(Canvas *canvas)
{
    canvas->drawSprite(x, y, sprite, true);
}



// ------------------------------------------------------------------------------------------------------------------------------------------------------

EnemyGroup::EnemyGroup(int x, int y, Sprite *enemySprite)
{
    enemies = new Enemy[enemyCountPerRow * enemyRowCount];

    int halfWidth = (enemySprite->width * enemyCountPerRow) >> 1;
    int halfHeight = (enemySprite->height * enemyRowCount) >> 1;

    for (int j = 0; j < enemyRowCount; j++) {
        for (int i = 0; i < enemyCountPerRow; i++) {
            enemies[i + j * enemyCountPerRow] = Enemy(
                x - halfWidth + enemySprite->width * i,
                y - halfHeight + enemySprite->height * j,
                enemySprite);
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
        enemies[i].update(openGL, canvas, speed, &turn, &border);
    }
    if (turn) speed *= -1;
}
