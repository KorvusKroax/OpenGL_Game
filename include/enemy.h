#include <openGL/open_gl.h>
#include <misc/canvas.h>

class Enemy
{
    private:
        float x, y;

        float width = 10;
        float height = 10;
        float speed = 50;

        void show(Canvas *canvas);

    public:
        Enemy();
        Enemy(int x, int y);
        ~Enemy();

        int update(OpenGL *openGL, Canvas *canvas);
        void changeDirection();
};



class EnemyRow
{
    private:
        float width;

        Enemy *enemies;
        int enemyCount = 8;

    public:
        EnemyRow();
        EnemyRow(float y, float enemyWidth = 10, float spacing = 10);
        ~EnemyRow();

        bool update(OpenGL *openGL, Canvas *canvas);
        void changeDirection();
};



class EnemyBlock
{
    private:
        float height;

        EnemyRow *enemyRows;
        int rowCount = 5;

    public:
        EnemyBlock(float enemyHeight = 10, float spacing = 10);
        ~EnemyBlock();

        void update(OpenGL *openGL, Canvas *canvas);
};
