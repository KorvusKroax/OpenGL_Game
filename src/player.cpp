#include <player.h>

Player::Player(float x, float y, Sprite *sprite, Sprite *ammoSprite)
{
    this->x = x;
    this->y = y;
    this->sprite = sprite;
    this->ammoSprite = ammoSprite;
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
    canvas->drawSprite(x, y, sprite, true);
}

void Player::control(OpenGL *openGL, Canvas *canvas)
{
    if (glfwGetKey(openGL->window, GLFW_KEY_RIGHT) == GLFW_PRESS && x < canvas->width - 1) x += speed * openGL->deltaTime;
    if (glfwGetKey(openGL->window, GLFW_KEY_LEFT) == GLFW_PRESS && x > 0) x -= speed * openGL->deltaTime;
    if (glfwGetKey(openGL->window, GLFW_KEY_SPACE) == GLFW_PRESS) fire();
}

void Player::fire()
{
    ammo = new Ammo(x, y, ammoSprite, 300);
}
