#include "main.h"

using namespace okapi;

void defensiveWP() {
    intakeMotor.move(-127);
    slapperMotor.move(115);
    drivetrain.pid_drive_set(-22, 110, false, false);
    drivetrain.pid_wait_until(-12);
    drivetrain.pid_swing_set(ez::RIGHT_SWING, 45, 110);
    //drivetrain.pid_wait();
    drivetrain.pid_wait_until(42);
    slapperMotor.move(0);
    drivetrain.pid_drive_set(-16, 110, true, true);
    drivetrain.pid_wait_until(-15);
    //drivetrain.pid_wait();
    //drivetrain.pid_drive_set(4, 110, true, true);
    //drivetrain.pid_wait();
    drivetrain.pid_drive_set(3, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(30, 110, true);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(14.5, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(0, 110, true);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(true);
    drivetrain.pid_drive_set(24, 110, true, true);
    drivetrain.pid_wait();
    //drivetrain.pid_turn_set(-540, 127);
    //drivetrain.pid_wait_until(-185);
    //drivetrain.pid_wait();
    //drivetrain.pid_drive_set(-16, 110, false, false);
    //drivetrain.pid_wait();
    //drivetrain.pid_turn_set(-205, 60);
    //drivetrain.pid_swing_set(ez::LEFT_SWING, -190, 110);
    //drivetrain.pid_swing_set(ez::RIGHT_SWING, 140, 127);
    //drivetrain.pid_wait();
    //drivetrain.pid_turn_set(-200, 110);
    //drivetrain.pid_wait();
    //drivetrain.pid_drive_set(-20, 110, true, true);
    //drivetrain.pid_wait();
    wingSolenoidL.set_value(false);
    drivetrain.pid_turn_set(-42, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(36.5, 110, true, true);
    drivetrain.pid_wait();    
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