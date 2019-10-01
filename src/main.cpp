#include <iostream>

#include "triangle_app.hpp"


int main()
{
    vkt::TriangleApp triangle_app;

    try {
        triangle_app.run();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
