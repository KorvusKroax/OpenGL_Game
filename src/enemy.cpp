#include <enemy.h>

Enemy::Enemy() { }

Enemy::Enemy(int x, int y)
{
    this->x = x;
    this->y = y;
}

Enemy::~Enemy() { }

int Enemy::update(OpenGL *openGL, Canvas *canvas)
{
    x += speed * openGL->deltaTime;
    show(canvas);

    if (canvas->width * .5f + x <= 0 || canvas->width * .5f + x >= canvas->width - 1) {
        return 1; // turn
    }

    return 0;
}

void Enemy::show(Canvas *canvas)
{
    canvas->drawRectangle(
        int(canvas->width * .5f + x - width * .5f),
        int(canvas->height * .5f + y - height * .5f),
        width, height, ColorRGBA(255, 255, 255, 255));
}

void Enemy::changeDirection()
{
    speed *= -1;
}



EnemyRow::EnemyRow() { }

EnemyRow::EnemyRow(float y, float enemyWidth, float spacing)
{
    enemies = new Enemy[enemyCount];

    width = (enemyWidth + spacing) * enemyCount;
    for (int i = 0; i < enemyCount; i++) {
        enemies[i] = Enemy((enemyWidth + spacing) * i - width * .5f, y);
    }
}

EnemyRow::~EnemyRow() { }

bool EnemyRow::update(OpenGL *openGL, Canvas *canvas)
{
    bool isTurn = 0;
    for (int i = 0; i < enemyCount; i++) {
        if (enemies[i].update(openGL, canvas)) {
            isTurn = true;
        }
    }

    return isTurn;
}

void EnemyRow::changeDirection()
{
    for (int i = 0; i < enemyCount; i++) {
        enemies[i].changeDirection();
    }
}



EnemyBlock::EnemyBlock(float enemyHeight, float spacing)
{
    enemyRows = new EnemyRow[rowCount];

    height = (enemyHeight + spacing) * rowCount;
    for (int i = 0; i < rowCount; i++) {
        enemyRows[i] = EnemyRow((enemyHeight + spacing) * i - height * .5f);
    }
}

EnemyBlock::~EnemyBlock() { }

void EnemyBlock::update(OpenGL *openGL, Canvas *canvas)
{
    bool isTurn = false;
    for (int i = 0; i < rowCount; i++) {
        if (enemyRows[i].update(openGL, canvas)) {
            isTurn = true;
        }
    }

    if (isTurn) {
        for (int i = 0; i < rowCount; i++) {
            enemyRows[i].changeDirection();
        }
    }
}
