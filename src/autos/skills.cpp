#include "main.h"

bool slapperOn = false;

void slapper() {
        while(true)
        {
            if (slapperOn && (slapperMotorL.get_efficiency() < 5 && slapperMotorL.get_efficiency() != 0))
            {
                slapperMotor.move(0);
                delay(200);
                slapperMotor.move(115);
                //controller.set_text(0, 0, "Speed adjusted");
            } else if (slapperOn) {
                slapperMotor.move(115);
            } else {
                slapperMotor.move(0);
            }

            delay(20);
        }
    }

void skillsAuto() {
    Task slapperTask(slapper);
    slapperOn = true;
    delay(1000);
    slapperOn = false;
    intakeMotor.move(-127);
    drivetrain.pid_drive_set(-20, 110, false, false);
    drivetrain.pid_wait_until(-10);
    drivetrain.pid_swing_set(ez::RIGHT_SWING, 45, 127);
    //drivetrain.pid_wait();
    drivetrain.pid_wait_until(42);
    drivetrain.pid_drive_set(-16, 110, true, true);
    drivetrain.pid_wait_until(-15);
    drivetrain.pid_turn_set(30, 110, true);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(14.5, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-60, 110, true);
    drivetrain.pid_wait();
    //slapperMotor.move(110);
    slapperOn = true;
    //delay(500);
    drivetrain.pid_drive_set(-12, 110, true, true);
    drivetrain.pid_wait();
    /*wingSolenoidR.set_value(true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-205, 60);
    drivetrain.pid_wait();
    wingSolenoidR.set_value(false);
    drivetrain.pid_turn_set(-200, 110);
    drivetrain.pid_wait();*/
    //drivetrain.pid_swing_set(ez::LEFT_SWING, -45, 110, 20);
    //drivetrain.pid_drive_set(12, 110, true, true);
    //drivetrain.pid_wait(); 
    //drivetrain.pid_turn_set(-60, 110);
    //drivetrain.pid_wait(); 
    //drivetrain.pid_drive_set(-6, 110, true, true);
    //drivetrain.pid_wait();
    delay(23000); //20000 CHANGE BACK
    slapperOn = false;
    climberMotorL.move(-127);
    climberMotorR.move(-127); 
    drivetrain.pid_drive_set(8, 110, true, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-180, 110, true);
    drivetrain.pid_wait();
    climberMotorL.move(0);
    climberMotorR.move(0);
    drivetrain.pid_drive_set(-24, 110, false, true);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-222.5, 110, true);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-82, 110, false, true);  // LONG DRIVE
    drivetrain.pid_wait();
    wingSolenoidL.set_value(true);
    wingSolenoidR.set_value(true);
    //drivetrain.pid_turn_set(-260, 110);
    //drivetrain.pid_wait();
    //drivetrain.pid_swing_set(ez::LEFT_SWING, -295, 127, 105);
    drivetrain.pid_turn_set(-265, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-26, 110, false, false);
    drivetrain.pid_wait_until(-8);
    wingSolenoidL.set_value(false);
    wingSolenoidR.set_value(false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-300, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-30, 127, false, false);
    drivetrain.pid_wait();
    //drivetrain.pid_drive_set(12, 127, false, false);
    //drivetrain.pid_wait();
    //drivetrain.pid_turn_set(-300, 110);
    //drivetrain.pid_wait();
    //drivetrain.pid_drive_set(-20, 127, false, false);
    //drivetrain.pid_wait();
    drivetrain.pid_drive_set(8, 127, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-390, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-50, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-300, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(10, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-260, 110);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(true);
    wingSolenoidR.set_value(true);
    //drivetrain.pid_swing_set(ez::RIGHT_SWING, -240, 110, 90);
    //drivetrain.pid_turn_set(-255, 110);
    drivetrain.pid_drive_set(-39, 110, true, true);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(false);
    wingSolenoidR.set_value(false);
    drivetrain.pid_turn_set(-220, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-12, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(30, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-310, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-16, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-220, 110);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(true);
    wingSolenoidR.set_value(true);
    delay(500);
    drivetrain.pid_drive_set(-48, 127, false, false);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(false);
    wingSolenoidR.set_value(false);
    //drivetrain.pid_swing_set(ez::RIGHT_SWING, -240, 127, 60);
    //drivetrain.pid_wait();
    //wingSolenoidL.set_value(false);
    //wingSolenoidR.set_value(false);
    drivetrain.pid_drive_set(32, 127, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-310, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-16, 110, false, false);
    drivetrain.pid_wait();
    /*drivetrain.pid_turn_set(-220, 110);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(true);
    wingSolenoidR.set_value(true);
    delay(500);
    drivetrain.pid_drive_set(-44, 127, false, false);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(false);
    wingSolenoidR.set_value(false);
    drivetrain.pid_drive_set(32, 127, false, false);
    drivetrain.pid_wait();*/
    drivetrain.pid_turn_set(-260, 110);
    drivetrain.pid_wait();
    //wingSolenoidL.set_value(true);
    drivetrain.pid_drive_set(-60, 127, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_set(-155, 110);
    drivetrain.pid_wait();
    //wingSolenoidR.set_value(true);
    drivetrain.pid_drive_set(-28, 127, false, false);
    drivetrain.pid_wait();
    /*drivetrain.pid_turn_set(-105, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-24, 127, false, false);
    drivetrain.pid_wait();*/
    drivetrain.pid_drive_set(12, 127, false, false);
    drivetrain.pid_wait();

    /*drivetrain.pid_drive_set(-36, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(36, 110, false, false);
    drivetrain.pid_wait();
    wingSolenoidL.set_value(false);
    wingSolenoidR.set_value(false);
    drivetrain.pid_turn_relative_set(-55, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-48, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_turn_relative_set(104, 110);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(-36, 110, false, false);
    drivetrain.pid_wait();
    drivetrain.pid_drive_set(36, 110, false, false);
    drivetrain.pid_wait();
    */
}

