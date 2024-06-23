#define STB_IMAGE_IMPLEMENTATION

#include <openGL/open_gl.h>
#include <misc/canvas.h>
#include <player.h>
#include <enemy.h>

const unsigned int CANVAS_WIDTH = 224; // 8 * 28
const unsigned int CANVAS_HEIGHT = 256; // 8 * 32
const float PIXEL_SCALE = 3;

double mouseX, mouseY;

void update(OpenGL *openGL, Canvas *canvas);
void show(Canvas *canvas);
void control(OpenGL *openGL);

int main()
{
    Canvas canvas = Canvas(CANVAS_WIDTH, CANVAS_HEIGHT);
    OpenGL openGL = OpenGL(WINDOWED, canvas.width, canvas.height, canvas.pixels, PIXEL_SCALE);

    SpriteSheet spriteSheet = SpriteSheet("Green_Marble_Alien_Face_128x128.png");

    Sprite playerSprite = spriteSheet.getSprite(32, 32, 20, 5);
    Sprite ammoSprite = spriteSheet.getSprite(16, 96, 1, 5);
    Player player = Player(canvas.width >> 1, 20, &playerSprite, &ammoSprite);

    Sprite enemySprite = spriteSheet.getSprite(64, 64, 16, 16);
    EnemyGroup enemyGroup = EnemyGroup(canvas.width >> 1, canvas.height - (canvas.height / 3), &enemySprite);

    while (!openGL.shouldClose())
    {
        canvas.clearCanvas();

        player.update(&openGL, &canvas);
        enemyGroup.update(&openGL, &canvas);

        update(&openGL, &canvas);

        openGL.update();
    }

    return 0;
}

void update(OpenGL *openGL, Canvas *canvas)
{
    show(canvas);
    control(openGL);
}

void show(Canvas *canvas)
{
    canvas->drawCircle(mouseX, mouseY, 3, ColorRGBA(0, 255, 255, 255));
}

void control(OpenGL *openGL)
{
    if (glfwGetKey(openGL->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(openGL->window, true);
    }

    glfwGetCursorPos(openGL->window, &mouseX, &mouseY);
    mouseX = mouseX / openGL->pixelScale;
    mouseY = openGL->height - mouseY / openGL->pixelScale;
}
