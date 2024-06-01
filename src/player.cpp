#include <player.h>

Player::Player(int x, int y)
{
    this->x = x;
    this->y = y;
}

Player::~Player() { }

void Player::show(Canvas *canvas)
{
    canvas->drawRectangle(x, y, 20, 5, ColorRGBA(255, 0, 0, 255));
    // canvas->drawLine(x, y, x+10, y+5, ColorRGBA(0, 255, 255, 255));
}

void Player::processInput(OpenGL *openGL)
{
    if (glfwGetKey(openGL->window, GLFW_KEY_RIGHT) == GLFW_PRESS) x++;
    if (glfwGetKey(openGL->window, GLFW_KEY_LEFT) == GLFW_PRESS) x--;
    if (glfwGetKey(openGL->window, GLFW_KEY_SPACE) == GLFW_PRESS) fire();
}

void Player::fire()
{
    std::cout << "FIRE!" << std::endl;
}
