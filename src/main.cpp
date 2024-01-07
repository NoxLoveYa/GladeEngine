#include <iostream>
#include "headers/Glade.hpp"

int main() {
    printf("Hello World!\n");
    glade::init();
    delete glade::window;
    return 0;
}