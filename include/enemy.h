#include <openGL/open_gl.h>
#include <misc/canvas.h>

class Enemy
{
    private:
        void show(Canvas *canvas);

    public:
        float x, y, w, h, speed;

        Enemy();
        Enemy(float x, float y, float w, float h, float speed);
        ~Enemy();

        void update(OpenGL *openGL, Canvas *canvas);
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

        void update(OpenGL *openGL, Canvas *canvas);
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
