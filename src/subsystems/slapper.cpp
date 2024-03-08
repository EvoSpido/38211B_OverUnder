//Last modified: 10/31/23
#include "main.h"
#include "pros/misc.h"
#include <string>
using namespace pros;

/**
 * Objects / Devices
 */
Motor slapperMotorL(7, E_MOTOR_GEAR_GREEN, false); // 5.5W
Motor slapperMotorR(11, E_MOTOR_GEAR_GREEN, true);  // 11W
Motor_Group slapperMotor({slapperMotorL, slapperMotorR});

bool pressedA = false;

int speed = 115;
string speedString = to_string(speed);

/**
 * Functions
 */
void slapperControl() { 

    slapperMotor.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);

    while (true) 
    {
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            pressedA = !pressedA;
        }

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
            speed++;
            speedString = to_string(speed);
            controller.set_text(0, 0, speedString);
            slapperMotorL.move(speed);
            slapperMotorR.move(speed);
        }

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            speed--;
            speedString = to_string(speed);
            controller.set_text(0, 0, speedString);
            slapperMotorL.move(speed);
            slapperMotorR.move(speed);
        }

        if (pressedA && (slapperMotorL.get_efficiency() < 5 && slapperMotorL.get_efficiency() != 0))
        {
            slapperMotor.move(0);
            delay(200);
            slapperMotor.move(speed);
            //controller.set_text(0, 0, "Speed adjusted");
        } else if (pressedA)
        {
            slapperMotor.move(speed);
        } else {
            slapperMotor.move(0);
        }
        
    }

    delay(20);
}