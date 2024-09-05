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
extern pros::Motor Intake;
extern pros::Motor Conveyor;
extern pros::ADIDigitalOut Mogo;
extern pros::Controller con; 
extern pros::Imu imu;

#endif