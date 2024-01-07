#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace window {
    static int WIN_WIDTH = 800;
    static int WIN_HEIGHT = 600;
    static std::string WIN_TITLE = "GladeEngine";
    static color::Color WIN_COLOR = {0.2f, 0.3f, 0.3f, 1.0f};

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        (void)window;
        glViewport(0, 0, width, height);
    }

    static void processInput(GLFWwindow *window)
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
}

class Window {
    public:
        Window() {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            window_ = glfwCreateWindow(window::WIN_WIDTH, window::WIN_HEIGHT, window::WIN_TITLE.c_str(), NULL, NULL);
            if (window_ == NULL)
            {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                exit(-1);
            }
            glfwMakeContextCurrent(window_);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cout << "Failed to initialize GLAD" << std::endl;
                exit(-1);
            }

            glViewport(0, 0, window::WIN_WIDTH, window::WIN_HEIGHT);
            glfwSetFramebufferSizeCallback(window_, window::framebuffer_size_callback); 
        }

        ~Window() {
            glfwTerminate();
        }

        void run() {
            while(!glfwWindowShouldClose(window_))
            {
                //process
                window::processInput(window_);

                //render
                glClearColor(window::WIN_COLOR.r, window::WIN_COLOR.g, window::WIN_COLOR.b, window::WIN_COLOR.a);
                glClear(GL_COLOR_BUFFER_BIT);

                glfwSwapBuffers(window_);
                glfwPollEvents();
            }
        }

    private:
        GLFWwindow* window_;
};