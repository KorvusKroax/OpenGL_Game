#include <openGL/open_gl.h>
#include <misc/canvas.h>

class Enemy
{
    private:
        float x, y;
        Sprite *sprite;

        void show(Canvas *canvas);

    public:
        Enemy();
        Enemy(float x, float y, Sprite *sprite);
        ~Enemy();

        void update(OpenGL *openGL, Canvas *canvas, float speed, bool *turn, int *border);
};



class EnemyGroup
{
    private:
        Enemy *enemies;
        int enemyCountPerRow = 11;
        int enemyRowCount = 5;

        Sprite *enemySprite;
        float speed = 10;

        int border = 8;

    public:
        EnemyGroup(int x, int y, Sprite *enemySprite);
        ~EnemyGroup();

        void update(OpenGL *openGL, Canvas *canvas);
};
