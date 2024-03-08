//Last modified: 10/31/23
#include "main.h"
using namespace pros; 

/**
 * Objects / Devices
 */
ADIDigitalOut wingSolenoidL(8); //Port: H
ADIDigitalOut wingSolenoidR(6); //Port: F

/**
 * Functions
 */
//Handles driver control functionality for the wings.
void wingControl() { 

    /**
     * Local static boolean to store whether X has been pressed or not.
     * static so the space for the variable is kept for the lifetime of the program, rather than getting reallocated.
     */
    static bool pressedX;
    static bool pressedLeft;
    static bool pressedRight;

    while (true) {

        if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
            
            pressedX = !pressedX; //Set to opposite of previous variable.
            pressedLeft = false;
            pressedRight = false;
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            
            pressedLeft = !pressedLeft; //Set to opposite of previous variable.
            pressedRight = false;
            pressedX = false;
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            
            pressedRight = !pressedRight; //Set to opposite of previous variable.
            pressedLeft = false;
            pressedX = false;
        }

        if (pressedX) {
            
            //Set solenoid HIGH (5V+)
            wingSolenoidL.set_value(4095);
            wingSolenoidR.set_value(4095);
        } else if (pressedLeft) {
            
            //Set solenoid LOW (0V)
            wingSolenoidR.set_value(4095);
            climberSolenoid.set_value(false);
        } else if (pressedRight) {
            wingSolenoidL.set_value(4095);
            climberSolenoid.set_value(false);
        } else {
            wingSolenoidL.set_value(0);
            wingSolenoidR.set_value(0);
            climberSolenoid.set_value(true);
        }

        delay(10);
    }
}