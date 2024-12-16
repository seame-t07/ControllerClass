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

        // Map actions to the buttons on the gamepad
        Actions forwardActions;
        forwardActions.onPress = moveForward;
        forwardActions.onRelease = stopMovement;

        Actions backwardActions;
        backwardActions.onPress = moveBackward;
        backwardActions.onRelease = stopMovement;

        Actions leftActions;
        leftActions.onPress = turnLeft;
        leftActions.onRelease = centerSteering;

        Actions rightActions;
        rightActions.onPress = turnRight;
        rightActions.onRelease = centerSteering;

        // Assign actions to the corresponding buttons
        controller.setButtonAction(SDL_CONTROLLER_BUTTON_A, forwardActions);   // A button for forward
        controller.setButtonAction(SDL_CONTROLLER_BUTTON_B, backwardActions);  // B button for backward
        controller.setButtonAction(SDL_CONTROLLER_BUTTON_X, leftActions);      // X button for left
        controller.setButtonAction(SDL_CONTROLLER_BUTTON_Y, rightActions);     // Y button for right
    
        int leftValue = controlle.getAxisValue(SDL_CONTROLLER_AXIS_LEFTY);
        int rightValue = controller.getAxisValue(SDL_CONTROLLER_AXIS_RIGHTX);

        if (leftValue == 0) {
            stopMovement();
        } else {
            moveForwardBack(leftValue);
        }

        if (rightValue == 0) {
            centerSteering();
        } else {
            turnLeftRight(rightValue);
        }

        // Start listening for gamepad events
        controller.listen();

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

