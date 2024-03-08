//Last modified: 10/30/23
#include "main.h"
using namespace okapi;
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {   

    drivetrain.opcontrol_curve_buttons_toggle(false);

    //initalize ratchet to start down
    //Set solenoid HIGH
    climberSolenoid.set_value(true);

    //initialize the break modes for various motors
    drivetrain.drive_brake_set(MOTOR_BRAKE_BRAKE);
    climberMotorL.set_brake_mode(MOTOR_BRAKE_BRAKE);
    climberMotorR.set_brake_mode(MOTOR_BRAKE_BRAKE);

    //drivetrain.initialize();
    drivetrain.drive_imu_calibrate(false);
    drivetrain.drive_sensor_reset();

    //initialize the EZ-Template PID values

    drivetrain.pid_targets_reset();
    drivetrain.drive_imu_reset();
    drivetrain.drive_sensor_reset();
    drivetrain.pid_drive_exit_condition_set(200_ms,  1_in, 500_ms, 3_in, 150_ms, 750_ms);
    drivetrain.pid_swing_exit_condition_set(300_ms,  3_deg, 500_ms, 7_deg, 150_ms, 750_ms);
    drivetrain.pid_turn_exit_condition_set(300_ms,  3_deg, 500_ms, 7_deg, 150_ms, 750_ms);

    //drivetrain.set_slew_min_power(110, 110);
    //drivetrain.set_slew_distance(6, 6);
    drivetrain.pid_heading_constants_set(10, 0, 20); //10, 0, 0, 0
    drivetrain.pid_drive_constants_set(8.5, 0.0, 6.75); //0.19, 0.0015, 6.7, 20   -- 0.6, 0.0015, 8.5
    drivetrain.pid_turn_constants_set(6.5, 0.075, 70, 15);
    drivetrain.pid_swing_constants_set(6, 0.050, 55.0, 0); // 3, 0.1, 22
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

    selector::init();
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

    selector::init();
    //ez::as::initialize();

    /*
    ez::as::auton_selector.autons_add({
    Auton("Defensive WP", defensiveWP),
    //Auton("Defensive Elim", defensiveElim),
    Auton("Offensive WP", offensiveWP),
    Auton("Skills", skillsAuto)
    });
    */
}

/*
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

    display();

    //defensiveWP();
    //offensiveWP();
    //skillsAuto();

    //ez::as::auton_selector.selected_auton_call();

    if (selector::auton == 1) {
        //troll - doesnt do anything
    } else if (selector::auton == 2) {
        defensiveWP();
    } else if (selector::auton == 3) {
        offensiveWP();
    } else if (selector::auton == 0) {
        skillsAuto();
    }

    //skillsAuto();
    //offensiveWP();
    //defensiveWP();
    //defensiveElim();
    //pidBench();

    
    
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.a
 */
void opcontrol() {    
    display();
    
    /*
    drivetrain.pid_tuner_print_brain_set(true);
    drivetrain.pid_tuner_print_terminal_set(true);

    drivetrain.pid_tuner_enable();
    
    while(true) {
        if (controller.get_digital_new_press(DIGITAL_B)) 
            pidBench();
        drivetrain.pid_tuner_iterate();
        drivetrain.opcontrol_arcade_standard(ez::SPLIT);
        pros::delay(20);
    }
    */
    //pros::lcd::clear();

    //Task displayTaskdisplay(display);

    Task wingControlTask(wingControl);
    Task driveControlTask(driveControl);
    Task climberControlTask(climberControl);
    Task intakeControlTask(intakeControl);
    Task flywheelControlTask(slapperControl);
    Task ratchetControlTask(ratchetControl);
    
}
