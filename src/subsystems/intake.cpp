//Last modified: 10/31/23
#include "main.h"
using namespace pros;

/**
 * Objects / Devices
 */
Motor intakeMotor(3, E_MOTOR_GEARSET_36, false);

/**
 * Functions
 */
void intakeControl() {
    
    static bool R2Pressed;
    static bool R1Pressed;

    while(true){

        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
    
            R2Pressed = !R2Pressed;
            R1Pressed = false;
        }
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
            
            R1Pressed = !R1Pressed;
            R2Pressed = false;
        }

        if(R2Pressed) {

            intakeMotor.move(-127);
        } else if (R1Pressed){

            intakeMotor.move(127);
        } else {

            intakeMotor.brake();
        }
    }
    
}