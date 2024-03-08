#include "main.h"
#include "okapi/api/units/QLength.hpp"
using namespace okapi;

void pidBench() {
    drivetrain.pid_swing_set(ez::LEFT_SWING, 90, 110);
    drivetrain.pid_wait();

    /*
    drivetrain.set_drive_pid(72, 110);
    drivetrain.wait_drive();
    drivetrain.set_turn_pid(-178, 110);
    drivetrain.wait_drive();
    drivetrain.set_drive_pid(120, 110);
    drivetrain.wait_drive();
    drivetrain.set_turn_pid(-268, 110);
    drivetrain.wait_drive();
    drivetrain.set_drive_pid(72, 110);
    drivetrain.wait_drive();
    drivetrain.set_turn_pid(-358, 110);
    drivetrain.wait_drive();
    drivetrain.set_drive_pid(12, 110);
    */
}