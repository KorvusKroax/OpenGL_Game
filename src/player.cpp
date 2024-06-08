#include <player.h>

Player::Player(float x, float y)
{
    this->x = x;
    this->y = y;
}

Player::~Player() { }

bool Player::update(OpenGL *openGL, Canvas *canvas)
{
    show(canvas);
    control(openGL, canvas);

    if (ammo) {
        if (!ammo->update(openGL, canvas)) {
            ammo = nullptr;
        }
    }

    return true;
}

void Player::show(Canvas *canvas)
{
    canvas->drawRectangle((int)x - (width >> 1), (int)y - (height >> 1), width, height, ColorRGBA(255, 255, 255, 255));
}

void Player::control(OpenGL *openGL, Canvas *canvas)
{
    if (glfwGetKey(openGL->window, GLFW_KEY_RIGHT) == GLFW_PRESS && x < canvas->width - 1) x += speed * openGL->deltaTime;
    if (glfwGetKey(openGL->window, GLFW_KEY_LEFT) == GLFW_PRESS && x > 0) x -= speed * openGL->deltaTime;
    if (glfwGetKey(openGL->window, GLFW_KEY_SPACE) == GLFW_PRESS) fire();
}

void Player::fire()
{
    ammo = new Ammo(x, y, 0, 5, 300);
}
