//Last modified: 10/31/23
#include "main.h"
using namespace pros;

//To-Do:
//Climber logic w/ distance sensor -- DONE

/**
 * Objects / Devices
 */
Motor climberMotorL(5, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
Motor climberMotorR(6, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Distance climberDistance(7);
ADIDigitalOut climberSolenoid(7);

static bool pressedUP = false;

/**
 * Functions
 */
void climberControl() {

    /**
     * Local static boolean to store whether X has been pressed or not.
     * static so the space for the variable is kept for the lifetime of the program, rather than getting reallocated.
     */
    

    while (true) 
    {
        if (controller.get_digital(E_CONTROLLER_DIGITAL_L1) == 1) 
        {
            climberMotorL.move(127);
            climberMotorR.move(127);    
        } else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2) == 1){
            climberMotorL.move(-127);
            climberMotorR.move(-127);  
        } else {
            climberMotorL.brake();
            climberMotorR.brake();
        }

        
        if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
            
            pressedUP = !pressedUP; //Set to opposite of previous variable.
        }

        /*if (pressedUP) {
            
            //Set solenoid HIGH (5V+)
            climberSolenoid.set_value(0);
            
        } else {
            
            //Set solenoid LOW (0V)
            climberSolenoid.set_value(4096);
        } */
        
        delay(20);
    }
}

void ratchetControl() {

    while(true) {

        if (climberDistance.get() <= 30) {
            climberSolenoid.set_value(false);
            delay(500);
            break;
        }

        delay(20);
    }
    
}