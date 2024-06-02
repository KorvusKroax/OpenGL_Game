#include <openGL/open_gl.h>
#include <misc/canvas.h>
#include <player.h>
#include <enemy.h>

// #include <iostream>
// #include <chrono>

double mouseX, mouseY;

void update(OpenGL *openGL, Canvas *canvas);
void show(Canvas *canvas);
void control(OpenGL *openGL);

int main()
{
    Canvas canvas = Canvas(320, 200);
    OpenGL openGL = OpenGL(canvas.width, canvas.height, 4, canvas.pixels);

    Player player = Player(canvas.width * .5f, 20, 20, 5, 100);
    Enemy enemy = Enemy(30, canvas.height - 20, 10, 10, 50);

    while (!openGL.shouldClose())
    {
        canvas.clearCanvas();

        player.update(&openGL, &canvas);
        enemy.update(&openGL, &canvas);

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

// void _show()
// {
//     auto startTime = std::chrono::high_resolution_clock::now();

//     show();

//     auto finishTime = std::chrono::high_resolution_clock::now();
//     auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
//     std::cout << microseconds.count() << "µs (" << (float)microseconds.count() / 1000 << "ms)" << std::endl;
// }

void control(OpenGL *openGL)
{
    if (glfwGetKey(openGL->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(openGL->window, true);
    }

    glfwGetCursorPos(openGL->window, &mouseX, &mouseY);
    mouseX = mouseX / openGL->pixelScale;
    mouseY = openGL->height - mouseY / openGL->pixelScale;
}
