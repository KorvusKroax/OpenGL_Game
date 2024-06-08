#include <openGL/open_gl.h>
#include <misc/canvas.h>

class Enemy
{
    private:
        float x, y;
        int width, height;

        void show(Canvas *canvas);

    public:
        Enemy();
        Enemy(float x, float y, int width, int height);
        ~Enemy();

        void update(OpenGL *openGL, Canvas *canvas, float *speed, bool *turn, int *border);
};



class EnemyGroup
{
    private:
        Enemy *enemies;
        int enemyCountPerRow = 7;
        int enemyRowCount = 5;

        int enemyWidth = 12;
        int enemyHeight = 10;
        int spacing = 8;

        float speed = 30;

        int border = 20;

    public:
        EnemyGroup();
        ~EnemyGroup();

        void update(OpenGL *openGL, Canvas *canvas);
};
