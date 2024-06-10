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

        float quadVertices[24] =  {
            // positions    // texCoords
            -1.0f,  1.0f,   0.0f, 1.0f,     // left top
            -1.0f, -1.0f,   0.0f, 0.0f,     // left bottom
             1.0f, -1.0f,   1.0f, 0.0f,     // right bottom

            -1.0f,  1.0f,   0.0f, 1.0f,     // left top
             1.0f, -1.0f,   1.0f, 0.0f,     // right bottom
             1.0f,  1.0f,   1.0f, 1.0f      // right top
        };

        float currentTime, lastTime;

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

        OpenGL(ScreenMode screenMode, unsigned int width, unsigned int height, int *pixels, float pixelScale = 1, const char *title = "OpenGL - 2D window");
        ~OpenGL();
        void update();
        bool shouldClose();
};
