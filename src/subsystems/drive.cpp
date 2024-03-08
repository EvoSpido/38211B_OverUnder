//Last modified: 10/31/23
#include "main.h"
using namespace pros;

/**
 * Objects / Devices
 */
Drive drivetrain({1, -2}, {-9, 10}, 8, 3.25, 600, 1.6); //~~should be 1.67~~ nvm should be 1.6 lol

/**
 * Functions
 */
void driveControl() {

    while(true) {
        
        drivetrain.opcontrol_arcade_standard(ez::SPLIT);

        /*int current = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

        int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        //current = (pow(current, 1.5))*(current/abs(current));

        //if (current < -127)
        //    current = -127;
        //if (current > 127)
        //    current = 127;

        //if (difference > 0) {
        //    current += 10;
        //} else if (difference < 0) {
        //    current -= 10;            
        //}

        int left = turn + current;
        int right = turn - current;
        
        drivetrain.set_tank(left, right);
        */
        delay(10);
    }
}