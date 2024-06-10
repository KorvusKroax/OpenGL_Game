#include <openGL/open_gl.h>
#include <misc/canvas.h>
#include <player.h>
#include <enemy.h>

const unsigned int CANVAS_WIDTH = 320;
const unsigned int CANVAS_HEIGHT = 200;
const float PIXEL_SCALE = 3;

double mouseX, mouseY;

void update(OpenGL *openGL, Canvas *canvas);
void show(Canvas *canvas);
void control(OpenGL *openGL);

int main()
{
    Canvas canvas = Canvas(CANVAS_WIDTH, CANVAS_HEIGHT);
    OpenGL openGL = OpenGL(FULLSCREEN, canvas.width, canvas.height, canvas.pixels, PIXEL_SCALE);

    Player player = Player(canvas.width >> 1, 20);
    EnemyGroup enemyGroup = EnemyGroup();

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
    canvas->drawCircle((int)mouseX, (int)mouseY, 3, ColorRGBA(0, 255, 255, 255));
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
