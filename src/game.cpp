#include <game.h>
#include <player.h>

Game::Game()
{
    Canvas canvas = Canvas(320, 200);
    OpenGL openGL = OpenGL(canvas.width, canvas.height, 4, canvas.pixels);

    Player player = Player(100, 50);

    while (!openGL.shouldClose())
    {
        canvas.clearCanvas();

        player.show(&canvas);

        player.processInput(&openGL);

        openGL.update();
    }
}

Game::~Game() { }
