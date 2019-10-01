#pragma once

/// GLFW will initialize vulkan.
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


namespace vkt {

class TriangleApp {
public:
    void run();

private:
    void init_window();

    void print_extensions();
    void create_vulkan_instance();
    void init_vulkan();

    void main_loop();

    void cleanup();

private:
    static constexpr int width_ = 800;
    static constexpr int height_ = 600;

    GLFWwindow *window_;
    VkInstance instance_;
};

}
