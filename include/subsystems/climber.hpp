//Last modified: 10/31/23
#include "api.h"
using namespace pros;

/**
 * Objects / Devices
 */
extern Motor climberMotorL;
extern Motor climberMotorR;
extern Distance climberDistance;
extern ADIDigitalOut climberSolenoid;

/**
 * Functions
 */
void climberControl();
void ratchetControl();