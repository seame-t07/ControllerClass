#include "Controller.hpp"
#include "JetCar.hpp"
#include <iostream>

JetCar car;

// Functions to control the car
void moveForward() {
    car.setMotorSpeed(100);
    std::cout << "Car moving forward" << std::endl;
}

void moveBackward() {
    car.setMotorSpeed(-100);
    std::cout << "Car moving backward" << std::endl;
}

void stopMovement() {
    car.setMotorSpeed(0);
    std::cout << "Car stopped" << std::endl;
}

void turnLeft() {
    car.setServoAngle(-45);
    std::cout << "Car turning left" << std::endl;
}

void turnRight() {
    car.setServoAngle(45);
    std::cout << "Car turning right" << std::endl;
}

void centerSteering() {
    car.setServoAngle(0);
    std::cout << "Car steering centered" << std::endl;
}

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

