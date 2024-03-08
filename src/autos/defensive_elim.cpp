#include "main.h"
#include "okapi/api/units/QLength.hpp"
using namespace okapi;


//GARBAGE DO NOT USE!!!!!!!!!!!!
void defensiveElim() {
    /*drivetrain.pid_drive_set(-24, 110, false, false);
    drivetrain.pid_wait_until(-10);
    drivetrain.pid_swing_set(ez::RIGHT_SWING, 45, 127);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-24, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(14, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(0, 110, true);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(10, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-85, 110, true);
    drivetrain.pid_wait();
    intakeMotor.move(127);
    drivetrain.pid_drive_set(60, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(140, 100, true);
    drivetrain.pid_wait();
    delay(200);
    intakeMotor.move(-127);
    delay(1500);
    drivetrain.pid_turn_set(-40, 110, true);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(true);
    wingSolenoidR.set_value(true);
    delay(200);
    drivetrain.pid_drive_set(-32, 110, true, true);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(false);
    wingSolenoidR.set_value(false);
    drivetrain.pid_drive_set(6, 110, true, true);
    drivetrain.pid_wait();
    */
    /*drivetrain.pid_drive_set(-10, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-220, 110, true);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(24, 110, true, true);
    drivetrain.pid_wait();*/

    
}

    /* oLD CODE TROLL
    wingSolenoid.set_value(4095);
    drivetrain.pid_drive_set(-60, 110);
    drivetrain.pid_wait();
    wingSolenoid.set_value(0);
    drivetrain.pid_swing_set(ez::RIGHT_SWING, 35, 127);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-80, 127);
    drivetrain.pid_wait_until(-30);
    drivetrain.pid_drive_set(50,110);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(0, 110);
    drivetrain.pid_drive_set(35,110);
    drivetrain.pid_wait();
    //drivetrain.pid_turn_set(0, 110);
    //drivetrain.pid_wait();
    //drivetrain.pid_drive_set(-65,110);
    //drivetrain.pid_wait();
    drivetrain.pid_swing_set(ez::LEFT_SWING, 135, 110);
    climberMotorL.move(80);
    climberMotorR.move(80);  
    drivetrain.pid_wait();
    climberMotorL.move(0);
    climberMotorR.move(0);  
    drivetrain.pid_drive_set(-200, 127);
    */    