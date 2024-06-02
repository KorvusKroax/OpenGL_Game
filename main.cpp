#include <openGL/open_gl.h>
#include <misc/canvas.h>
#include <player.h>
#include <enemy.h>

double mouseX, mouseY;

void update(OpenGL *openGL, Canvas *canvas);
void show(Canvas *canvas);
void control(OpenGL *openGL);

int main()
{
    Canvas canvas = Canvas(320, 200);
    OpenGL openGL = OpenGL(canvas.width, canvas.height, 4, canvas.pixels);

    Player player = Player(canvas.width * .5f, 20, 20, 5, 100);
    EnemyBlock enemyBlock = EnemyBlock();

    while (!openGL.shouldClose())
    {
        canvas.clearCanvas();

        player.update(&openGL, &canvas);
        enemyBlock.update(&openGL, &canvas);

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
