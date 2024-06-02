#include <enemy.h>

Enemy::Enemy() { }

Enemy::Enemy(float x, float y, float w, float h, float speed)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->speed = speed;
}

Enemy::~Enemy() { }

EnemyState Enemy::update(OpenGL *openGL, Canvas *canvas)
{
    x += speed * openGL->deltaTime;
    show(canvas);

    return (x <= 0 || x >= canvas->width - 1) ? TURN : MOVE;
}

void Enemy::show(Canvas *canvas)
{
    canvas->drawRectangle(int(x - w * .5f), int(y - h * .5f), w, h, ColorRGBA(255, 255, 255, 255));
}

void Enemy::setSpeed(float speed)
{
    this->speed = speed;
}



EnemyRow::EnemyRow() { }

EnemyRow::EnemyRow(float x, float y, float w, float h, float speed)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->speed = speed;

    enemies = new Enemy[enemyCount];

    for (int i = 0; i < enemyCount; i++) {
        float xx = this->x + (this->w + spacing) * i;
        enemies[i] = Enemy(xx, this->y, this->w, this->h, this->speed);
    }
}

EnemyRow::~EnemyRow() { }

EnemyState EnemyRow::update(OpenGL *openGL, Canvas *canvas)
{
    bool isTurn = false;
    for (int i = 0; i < enemyCount; i++) {
        isTurn = isTurn || enemies[i].update(openGL, canvas) == TURN;
    }

    return isTurn ? TURN : MOVE;
}

void EnemyRow::setSpeed(float speed)
{
    for (int i = 0; i < enemyCount; i++) {
        enemies[i].setSpeed(speed);
    }
}



EnemyBlock::EnemyBlock(float x, float y, float w, float h, float speed)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->speed = speed;

    enemyRows = new EnemyRow[enemyRowCount];

    for (int i = 0; i < enemyRowCount; i++) {
        float yy = this->y + (this->h + spacing) * i;
        enemyRows[i] = EnemyRow(this->x, yy, this->w, this->h, this->speed);
    }
}

EnemyBlock::~EnemyBlock() { }

void EnemyBlock::update(OpenGL *openGL, Canvas *canvas)
{
    bool isTurn = false;
    for (int i = 0; i < enemyRowCount; i++) {
        isTurn = isTurn || enemyRows[i].update(openGL, canvas) == TURN;
    }

    if (isTurn) {
        speed *= -1;
        for (int i = 0; i < enemyRowCount; i++) {
            enemyRows[i].setSpeed(speed);
        }
    }
}
