//Last modified: 10/31/23
#include "main.h"
using namespace pros;

/**
 * Objects / Devices
 */
Drive drivetrain({-1, 2}, {-9, 10}, 8, 3.25, 600, 0.6);

/**
 * Functions
 */
void driveControl() {

    static int current = 0;

    while(true) {
        
        int target = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        
        int difference = target - current;
        int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

        if (difference > 0) {
            current += 10;
        } else if (difference < 0) {
            current -= 10;            
        }

        int left = current + turn;
        int right = current - turn;
        
        drivetrain.set_tank(left, right);

        delay(10);
    }
}