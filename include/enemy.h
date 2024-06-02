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
        int enemyCount = 7;
        float spacing = 10;

    public:
        EnemyRow(float x, float y, float w, float h, float speed);
        ~EnemyRow();

        void update(OpenGL *openGL, Canvas *canvas);
};
