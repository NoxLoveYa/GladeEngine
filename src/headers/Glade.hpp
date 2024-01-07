#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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