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

        void update(OpenGL *openGL, Canvas *canvas, float speed, bool *turn, int *border);
};



class EnemyGroup
{
    private:
        Enemy *enemies;
        int enemyCountPerRow = 11;
        int enemyRowCount = 5;

        int enemyWidth = 16;
        int enemyHeight = 16;

        float speed = 10;

        int border = 8;

    public:
        EnemyGroup(int x, int y);
        ~EnemyGroup();

        void update(OpenGL *openGL, Canvas *canvas);
};
