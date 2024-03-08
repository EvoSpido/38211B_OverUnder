#pragma once

#include <string>

//selector configuration
#define HUE 200
#define DEFAULT 1
#define AUTONS "Do Nothing", "Defensive WP", "Offensive WP"

namespace selector{

extern int auton;
const char *b[] = {AUTONS, ""};
void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b);

}
