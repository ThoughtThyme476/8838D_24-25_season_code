#include "api.h"
#include "main.h"
#include "okapi/api.hpp"


#ifndef PIDH
#define PIDH

extern float error;
extern int time2;
extern void driveStraight(int target);
extern void driveTurn(int target);
extern void driveTurn2(int target);
extern void driveStraight2(int target);
extern void driveStraightC(int target);
extern void driveArcL(double theta, double radius, int timeout);
extern void driveArcR(double theta, double radius, int timeout);
extern void driveArcLF(double theta, double radius, int timeout);
extern void driveArcRF(double theta, double radius, int timeout);

// straight stuff
#define STRAIGHT_KP 4//3
#define STRAIGHT_KI 0
#define STRAIGHT_KD .5
#define STRAIGHT_INTEGRAL_KI 40
#define STRAIGHT_MAX_INTEGRAL 14.5

// turn stuff
#define TURN_KP 7.25
#define TURN_KI 0
#define TURN_KD 61
#define TURN_INTEGRAL_KI 30
#define TURN_MAX_INTEGRAL 25


//arc turn stiff
//#define driveArcL 10
#define HEADING_KP 8.25
#define HEADING_KI 0
#define HEADING_KD 0
#define HEADING_MAX_INTEGRAL 0
#define HEADING_INTEGRAL_KI 0

#define ARC_HEADING_KP 4
#define ARC_HEADING_KI 0.01
#define ARC_HEADING_KD 2
#define ARC_HEADING_MAX_INTEGRAL 0
#define ARC_HEADING_INTEGRAL_KI 0




#endif