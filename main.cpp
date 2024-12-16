#include "Controller.hpp"
#include "JetCar.hpp"
#include <iostream>

JetCar car;

// Functions to control the car
void moveForwardBack(int speed) {
    car.setMotorSpeed(speed);
}

void stopMovement() {
    car.setMotorSpeed(0);
}

void turnLeftRight(int angle) {
    car.setServoAngle(angle);
}

void centerSteering() {
    car.setServoAngle(0);
}

int main() {
    try {
        Controller controller;

        // Associa funções aos eixos do controle
        controller.setAxisAction(SDL_CONTROLLER_AXIS_LEFTY, moveForwardBack);
        controller.setAxisAction(SDL_CONTROLLER_AXIS_RIGHTX, turnLeftRight);

        // Escuta eventos do controle
        controller.listen();

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
