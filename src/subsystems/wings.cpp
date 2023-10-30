//Last modified: 9/29/23
#include "main.h"
using namespace pros; 

/**
 * Objects / Devices
 */
ADIDigitalOut wingSolenoid(1); //Port: A

/**
 * Functions
 */
//Handles driver control functionality for the wings.
void wingControl() { 

    /**
     * Local static boolean to store whether R1 has been pressed or not.
     * static so the space for the variable is kept for the lifetime of the program, rather than getting reallocated.
     */
    static bool pressedR1;

    while (true) {

        if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
            
            pressedR1 = !pressedR1; //Set to opposite of previous variable.
        }

        if (pressedR1) {
            
            //Set solenoid HIGH (5V+)
            wingSolenoid.set_value(4095);
            
        } else {
            
            //Set solenoid LOW (0V)
            wingSolenoid.set_value(0);
        } 

        delay(10);
    }
}