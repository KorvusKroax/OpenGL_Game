#pragma once

#include <openGL/glad/glad.h>
#include <openGL/GLFW/glfw3.h>
#include <openGL/shader.h>

enum ScreenMode {
    WINDOWED,
    FULLSCREEN
};

class OpenGL
{
    private:
        unsigned int quadVAO;
        unsigned int quadVBO;
        unsigned int framebuffer;
        unsigned int textureColorbuffer;
        unsigned int renderbuffer;
        Shader *quadShader;

        float currentTime, lastTime;
        float aspectRatio = 1;

        void initWindowed();
        void initFullscreen();
        void initQuad();
        void terminate();

    public:
        unsigned int width;
        unsigned int height;
        float pixelScale;
        int *pixels = nullptr;
        const char *title;
        GLFWwindow *window;

        float deltaTime;

        OpenGL(unsigned int width, unsigned int height, float pixelScale, int *pixels, ScreenMode screenMode = WINDOWED, const char *title = "OpenGL - 2D window");
        ~OpenGL();
        void update();
        bool shouldClose();
};
