#include "main.h"
#include "okapi/api/units/QLength.hpp"
using namespace okapi;

void offensiveWP() {
    slapperMotor.move(115);
    //wingSolenoidR.set_value(true);
    drivetrain.pid_drive_set(-22, 110, false, false);
    drivetrain.pid_wait_until(-12);
    //wingSolenoidR.set_value(false);
    drivetrain.pid_swing_set(ez::LEFT_SWING, -45, 110);
    drivetrain.pid_wait_until(-42);
    slapperMotor.move(0);
    drivetrain.pid_drive_set(-13, 110, false, false);
    drivetrain.pid_wait_until(-12);
    drivetrain.pid_drive_set(12, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(60, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(12, 127, false, false);
    drivetrain.pid_wait_until(10);
    drivetrain.pid_swing_relative_set(ez::LEFT_SWING, 62, 127, 60, false);
    drivetrain.pid_wait_until(50);
    intakeMotor.move(127);
    drivetrain.pid_drive_set(17, 110, false, false);
    drivetrain.pid_wait_until(16);
    drivetrain.pid_drive_set(-2, 110, false, false);
    drivetrain.pid_wait_until(-2);
    drivetrain.pid_turn_set(225, 60);
    drivetrain.pid_wait_until(215);
    drivetrain.pid_drive_set(-8, 127, false, false);
    drivetrain.pid_wait_until(-6);
    drivetrain.pid_drive_set(28, 127, false, false);
    drivetrain.pid_wait_until(26);
    intakeMotor.move(-127);
    drivetrain.pid_drive_set(-8, 110, false, false);
    drivetrain.pid_wait();
    climberMotorL.move(90);
    climberMotorR.move(90);
    drivetrain.pid_turn_set(175, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-42, 100, false, false);
    drivetrain.pid_wait_until(-40);
    climberMotorL.move(0);
    climberMotorR.move(0);
    drivetrain.pid_wait();
    
    //drivetrain.pid_drive_set(36, 110, false, false);
    //drivetrain.pid_wait();
    /*drivetrain.pid_swing_relative_set(ez::RIGHT_SWING, 90, 110);
    drivetrain.pid_wait_until(80);
    drivetrain.pid_drive_set(6, 110, false, false);
    drivetrain.pid_wait_until(4);
    drivetrain.pid_swing_relative_set(ez::RIGHT_SWING, 90, 110);
    drivetrain.pid_wait();*/
}
