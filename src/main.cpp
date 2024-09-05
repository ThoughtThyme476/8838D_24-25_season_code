#include "main.h"
#include "robot.h"
#include "api.h"
#include "pid.h"
#include "auton.h"
//#include "odometry.h"
using namespace std;
using namespace pros;
#define target


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
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
void competition_initialize() {}

/**
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
 * task, not resume it from where it left off.
 */
void opcontrol() {
	bool arcToggle = true;
	bool tankToggle = false;
	bool PistonsForMogo = false;
	int time = 0;
while (true){
	if (con.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
		arcToggle = !arcToggle;
		tankToggle = !tankToggle;
	}
	if (tankToggle){
 LF.move(con.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
 LM.move(con.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
 LB.move(con.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
 RF.move(con.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
 RM.move(con.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
 RB.move(con.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
	}
	if (arcToggle){
 int RX = con.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
  int power = con.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
  int turn = int(abs(RX) * RX / 127);
  int left = power + turn;
  int right = power - turn;

 LF.move(left);
 LM.move(left);
 LB.move(left);
 RF.move(right);
 RM.move(right);
 RB.move(right);

	}

if (con.get_digital(E_CONTROLLER_DIGITAL_X)) { 
//	driveTurn2(175);
driveArcL(90, 700, 30000);
}
	


	
	if(con.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
		Intake.move(127) ;
		Conveyor.move(127);
	} else if (con.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
		Intake.move(-127);
		Conveyor.move(-127);
	}
	else  {
		Conveyor.move(0);
		Intake.move(0);
	}






if (con.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)){
	PistonsForMogo = !PistonsForMogo;
}
 

Mogo.set_value(PistonsForMogo);



	// driveArcL(90, 650, 30000);
// 	setPosition(0,0,0); 
// 	while(true){
// 		odometry();
// 		delay(1);
// 	}
// driveStraight(1000);
 }

pros::delay(1);
time += 1;

if (time % 50 == 0 && time % 100 !=0 && time % 150 % 150 != 0){
con.print(0, 0, "Time2 %i			", time2);
} else if (time % 50 ==0 && time % 100 != 0){
con.print(1, 0, "ERROR %f 			", float (error));
} else if (time % 50 == 0){
	con.print(2, 0, " Temp: %f 			", float (imu.get_heading()));
};
//((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((()))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))


}


