#include "Controller.hpp"
#include "JetCar.hpp"
#include <iostream>

JetCar car;


int main() {
    try {
        Controller controller;
        // Start listening for gamepad events
        controller.listen();

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

