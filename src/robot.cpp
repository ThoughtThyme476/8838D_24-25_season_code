#include "api.h"
#include "main.h"
#include "robot.h"
#include "pros/motors.h"
using namespace pros;

#define LF_PORT 1 //correct
#define LM_PORT 2 //correct 
#define LB_PORT 3 //correct
#define RF_PORT 4 //correct
#define RM_PORT 5 //correct
#define RB_PORT 6 //correct    
#define IMU_PORT 7 // plugged in




//#define
pros::Imu imu (IMU_PORT);
pros::Motor LF (LF_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor RF (RF_PORT, pros::E_MOTOR_GEARSET_06,false);
pros::Motor LM (LM_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor RM (RM_PORT, pros::E_MOTOR_GEARSET_06,false);
pros::Motor LB (LB_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor RB (RB_PORT, pros::E_MOTOR_GEARSET_06,false);
//sensor
//pros::Optical Eyesight (OPTICAL_PORT);
//pros::ADIAnalogIn DistanceSense ('G');

//pneumatic example
//pros::ADIDigitalOut Mogo ('A', false);

pros::ADIDigitalIn selec ('D');
pros::Controller con (pros::E_CONTROLLER_MASTER);



