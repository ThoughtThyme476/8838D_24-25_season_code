#include "api.h"
#include "main.h"
#include "robot.h"
#include "pros/motors.h"
using namespace pros;

#define LF_PORT 1 //correct
#define RF_PORT 3 //correct 
#define LM_PORT 2 //correct
#define RM_PORT 5 //correct
#define LB_PORT 13 //correct
#define RB_PORT 7 //correct    
#define IMU_PORT 12 // plugged in
// #define INTAKE_PORT 8 //front roller
#define CONVEYOR_PORT 8 //hooks 
#define SNAKE_PORT 11 //lift
#define OPTICAL_PORT 19 // color switch, mabye 



//#define
pros::Imu imu (IMU_PORT);
pros::Motor LF (LF_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor RF (RF_PORT, pros::E_MOTOR_GEARSET_06,false);
pros::Motor LM (LM_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor RM (RM_PORT, pros::E_MOTOR_GEARSET_06,false);
pros::Motor LB (LB_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor RB (RB_PORT, pros::E_MOTOR_GEARSET_06,false);
// pros::Motor Intake(INTAKE_PORT, pros::E_MOTOR_GEARSET_06);
pros::Motor Conveyor(CONVEYOR_PORT, pros::E_MOTOR_GEARSET_06);
pros::Optical Eyesight (OPTICAL_PORT);
pros::Motor Snake(SNAKE_PORT, pros::E_MOTOR_GEARSET_18, false);
pros::ADIDigitalOut Mogo ('D', false);
pros::ADIDigitalOut DaSorter ('B', false);
pros::ADIDigitalOut Doinker ('G', false);
pros::ADIDigitalIn selec ('A');
//pros::ADIAnalogIn DistanceSense ('A');
pros::Controller con (pros::E_CONTROLLER_MASTER);



