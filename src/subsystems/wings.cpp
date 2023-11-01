//Last modified: 10/31/23
#include "main.h"
using namespace pros; 

/**
 * Objects / Devices
 */
ADIDigitalOut wingSolenoid(8); //Port: A

/**
 * Functions
 */
//Handles driver control functionality for the wings.
void wingControl() { 

    /**
     * Local static boolean to store whether R1 has been pressed or not.
     * static so the space for the variable is kept for the lifetime of the program, rather than getting reallocated.
     */
    static bool pressedX;

    while (true) {

        if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
            
            pressedX = !pressedX; //Set to opposite of previous variable.
        }

        if (pressedX) {
            
            //Set solenoid HIGH (5V+)
            wingSolenoid.set_value(4095);
            
        } else {
            
            //Set solenoid LOW (0V)
            wingSolenoid.set_value(0);
        } 

        delay(10);
    }
}