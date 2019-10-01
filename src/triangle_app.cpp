#include "triangle_app.hpp"

#include <exception>
#include <iostream>
#include <vector>


namespace vkt {

void TriangleApp::run()
{
    init_window();
    init_vulkan();
    main_loop();
    cleanup();
}

void TriangleApp::init_window()
{
    glfwInit();
    /// Tell GLFW to not create OpenGl context.
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window_ = glfwCreateWindow(width_, height_, "Vulkan Triangle", nullptr, nullptr);
}

void TriangleApp::print_extensions()
{
    uint32_t count = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr);

    std::vector<VkExtensionProperties> extensions(count);
    vkEnumerateInstanceExtensionProperties(nullptr, &count, extensions.data());

    std::cout << "Available Vulkan extensions:\n";
    for (auto &extension : extensions) {
        std::cout << "\t" << extension.extensionName << "\n";
    }
}

void TriangleApp::create_vulkan_instance()
{
    print_extensions();

    VkApplicationInfo app_info = {};
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName = "Vulkan Triangle App";
    app_info.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    app_info.pEngineName = "No Engine";
    app_info.engineVersion = VK_MAKE_VERSION(0, 1, 0);
    app_info.apiVersion = VK_API_VERSION_1_1;

    VkInstanceCreateInfo create_info = {};
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo = &app_info;

    /// Vulkan is a platform agnostic API, so it needs extensions to interface with the window system.
    /// GLFW provides built-in function that returns the needed extensions.
    uint32_t glfw_extension_count = 0;
    const char **glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
    create_info.enabledExtensionCount = glfw_extension_count;
    create_info.ppEnabledExtensionNames = glfw_extensions;

    create_info.enabledLayerCount = 0;

    if (vkCreateInstance(&create_info, nullptr, &instance_) != VK_SUCCESS) {
        throw std::runtime_error("failed to create Vulkan instance");
    }
}

void TriangleApp::init_vulkan()
{
    create_vulkan_instance();
}

void TriangleApp::main_loop()
{
    while (!glfwWindowShouldClose(window_)) {
        glfwPollEvents();
    }
}

void TriangleApp::cleanup()
{
    vkDestroyInstance(instance_, nullptr);
    glfwDestroyWindow(window_);
    glfwTerminate();
}

}
