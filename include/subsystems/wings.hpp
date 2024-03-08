//Last modified: 9/29/23
#include "api.h"
using namespace pros;

/**
 * Objects / Devices
 */
extern ADIDigitalOut wingSolenoidL; //Port: H
extern ADIDigitalOut wingSolenoidR; //Port: F

/**
 * Functions
 */

//Handles driver control functionality for the wings.
void wingControl();
