//Last modified: 10/31/23
#include "main.h"
using namespace pros;

//To-Do:
//Climber logic w/ distance sensor

/**
 * Objects / Devices
 */
Motor climberMotorL(5, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
Motor climberMotorR(6, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Distance climberDistance(7);
ADIDigitalOut climberSolenoid(7);


/**
 * Functions
 */
void climberControl() {

    while (true) 
    {
        if (controller.get_digital(E_CONTROLLER_DIGITAL_L1) == 1) 
        {
            climberMotorL.move(127);
            climberMotorR.move(127);    
        } else {
            climberMotorL.brake();
            climberMotorR.brake();
        }

        if (controller.get_digital(E_CONTROLLER_DIGITAL_L2) == 1)
        {
            climberMotorL.move(-127);
            climberMotorR.move(-127);  
        } else {
            climberMotorL.brake();
            climberMotorR.brake();
        } 
        delay(20);
    }
}