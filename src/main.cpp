#include <iostream>
#include "headers/Glade.hpp"

int main() {
    //init the engine
    glade::init();

    //clean up
    delete glade::window;
    
    return 0;
}