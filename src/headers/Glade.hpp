#pragma once

#include <iostream>


#ifdef _WIN32
    #include <glad.h> // Include glad.h on Windows
#else
    #include <glad/glad.h> // Include glad/glad.h on other platforms
#endif

#ifdef _WIN32
    #include <glfw3.h> // Include glad.h on Windows
#else
    #include <GLFW/glfw3.h> // Include glad/glad.h on other platforms
#endif

#include "Color.hpp"
#include "Window.hpp"

namespace glade {
    static Window* window = nullptr;

    static int init() {
        int success = 0;

        window = new Window();
        window->run();

        return success;
    }
}