#include "Controller.hpp"
#include "JetCar.hpp"
#include <iostream>

void moveLeftandRight(int value) {
    std::cout << "Axis moved to " << value << std::endl;
    car.setServoAngle(value);
}

void moveForwardandBackward(int value) {
    std::cout << "Axis moved to " << value << std::endl;
    car.setMotorSpeed(value);
}

JetCar car;


int main() {
    try {
        Controller controller;
        // Start listening for gamepad events

        controller.setAxisAction(SDL_CONTROLLER_AXIS_LEFTX, moveLeftandRight);
        controller.setAxisAction(5, moveForwardandBackward);

        controller.listen();

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

