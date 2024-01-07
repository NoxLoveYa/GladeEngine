#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace window {
    static int WIN_WIDTH = 800;
    static int WIN_HEIGHT = 600;
    static std::string WIN_TITLE = "GladeEngine";

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        (void)window;
        glViewport(0, 0, width, height);
    }
}