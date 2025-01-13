#include "Controller.hpp"
#include "JetCar.hpp"
#include <iostream>

JetCar car;

void moveLeftandRight(int value) {
     
    float fvalue = value * 1.0;// + 6900;
  //  fvalue -= -129.0;
    std::cout << "Before: " << fvalue << std::endl;
    fvalue = fvalue / 32000.0 * 45;
    std::cout << "Axis moved to " << fvalue << std::endl;
    car.setServoAngle(fvalue);
}

void moveForwardandBackward(int value) {
    
    value -= 16319;

 
    value = (value / 165) * -1;
    
    std::cout << "Axis moved to " << value << std::endl;
    car.setMotorSpeed(value);
}

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

