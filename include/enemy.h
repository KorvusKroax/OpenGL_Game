#include <openGL/open_gl.h>
#include <misc/canvas.h>

enum EnemyState { MOVE, TURN, DIE };

class Enemy
{
    private:
        void show(Canvas *canvas);

    public:
        float x, y, w, h, speed;

        Enemy();
        Enemy(float x, float y, float w, float h, float speed);
        ~Enemy();

        EnemyState update(OpenGL *openGL, Canvas *canvas);
        void setSpeed(float speed);
};

class EnemyRow
{
    private:
        float x, y, w, h, speed;
        Enemy *enemies;
        int enemyCount = 8;
        float spacing = 10;

    public:
        EnemyRow();
        EnemyRow(float x, float y, float w, float h, float speed);
        ~EnemyRow();

        EnemyState update(OpenGL *openGL, Canvas *canvas);
        void setSpeed(float speed);
};

class EnemyBlock
{
    private:
        float x, y, w, h, speed;
        EnemyRow *enemyRows;
        int enemyRowCount = 5;
        float spacing = 10;

    public:
        EnemyBlock(float x, float y, float w, float h, float speed);
        ~EnemyBlock();

        void update(OpenGL *openGL, Canvas *canvas);
};
