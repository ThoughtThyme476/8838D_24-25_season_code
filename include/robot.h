#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

#ifndef ROBOTH
#define ROBOTH
extern pros::Motor LF;
extern pros::Motor RF;
extern pros::Motor LM;
extern pros::Motor RM;
extern pros::Motor LB;
extern pros::Motor RB;
extern pros::Motor hooks;
// extern pros::Motor Ladybrown;
// extern pros::ADIDigitalOut Mogo;
// extern pros::ADIDigitalOut Intakepiston;
// extern pros::ADIDigitalOut Doinker;
extern pros::Controller con; 
extern pros::Imu imu;
extern pros::ADIDigitalIn selec;

#endif