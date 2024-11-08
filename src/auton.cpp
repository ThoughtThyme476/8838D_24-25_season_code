#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "pid.h"
using namespace std;
using namespace pros;


void autonomous() {


//Red left side
    
if(atn == 0){ //change to 0
driveStraight2(-450);
driveTurn2(90);
driveStraight2(-175);
Conveyor.move(-127);
delay(500);
driveStraight2(500);




//

// driveStraight2(200);
// driveTurn2(-90);
// driveTurn2(-20);
// Conveyor.move(127);
// driveTurn2(-45);





// driveStraight2(150);
// delay(300);
//lift
// delay(300);
// driveStraightSlow(225, 50);
//lift
// delay(200);
// driveClampS(-1500,100, 50);
// driveTurn2(170);
// driveStraightC(300);
// driveArcLF(40, 150, 3000);

////////////////////////////////Old Auton
// driveStraightSlow(-650, 70);
// driveTurn2(40);
// driveClampS(-700, 100, 50);
// delay(300);
// driveTurn2(95);
// Conveyor.move(-127);
// Intake.move(-127);
// driveStraightSlow(800, 60);
// imu.tare();
// driveTurn2(80);
// driveStraightSlow(525, 70);
// delay(400);
// Conveyor.move(127);
// Intake.move(127);
// delay(300);
// Conveyor.move(-127);
// Intake.move(-127);
// driveTurn2(35);
// driveStraightSlow(90, 25);
// imu.tare();
// driveTurn2(150);
// imu.tare();
// driveTurn2(25);
// Intake.move(127);
// Conveyor.move(127);
// driveStraightSlow(2250, 70);
// imu.tare();
// delay(300);
// driveTurn2(-120);
// driveStraight(400);
///////////////////////////////////////

// delay(1485);
// Conveyor.move(0);
// delay(100);
// Conveyor.move(-50);
// delay(100);
// Conveyor.move(0);
// delay(100);
// Conveyor.move(110);

}





//Blue right side

      if(atn == 1) {

      }
//red right side// not done yet // simple one 

      if(atn == 2){ 
        driveStraightC(-1200);
        driveTurn2(-35);
        driveClampS(-450, 10, 80);
        Conveyor.move(127);
        driveTurn2(10);
        Conveyor.move(-127);
        driveStraight(900);
        delay(400);
        Conveyor.move(0);
        driveTurn2(150);
        driveStraight2(-500);
        Mogo.set_value(false); 
        driveStraight2(850);
        driveTurn2(-110);
        driveClampS(-1000, 50, 90);
        Conveyor.move(-127);
        delay(700);
        imu.tare();
        driveTurn2(-90);
        driveStraight2(600);
        
        // driveTurn2(-40);
        // Conveyor.move(127);
        // delay(150);
        // driveTurn2(160);
        // Conveyor.move(0);
        // driveClampS(200, 0, 95);
        // Conveyor.move(127);






        // driveStraight2(100);
        // Conveyor.move(127);
        // driveTurn2(90);
        // Mogo.set_value(false);
        // Conveyor.move(127);
        // driveStraight2(250);
        // driveTurn2(-45);
        // driveClampS(-400, 100, 90);
        // Conveyor.move(127);
        // driveTurn2(90);
        // driveStraightSlow(200, 80);

      
    //    driveStraightC(-1750);
    //    driveStraightSlow(-250, 50);
    //    driveTurn2(50);
    //    driveClampS(-250,50,30);



      }

//blue left side// not done // simple one

      if(atn == 3){
        //    driveClampS(-1000, 100, 90);
        // driveStraight2(-100);
        // Conveyor.move(127);
        // driveTurn2(-90);
        // Mogo.set_value(false);
        // Conveyor.move(127);
        // driveStraight2(-250);
        // driveTurn2(45);
        // driveClampS(400, 100, 90);
        // Conveyor.move(127);
        // driveTurn2(-90);
        // driveStraightSlow(-200, 80);
      }

//red left side// not done // elims

    if(atn == 4){

    }

//blue right side // not done /// elims

    if(atn == 5) {

    }
    
//red right side // not done // elims

    if(atn == 6) {
    //     driveClampS(1000, 100, 90);
    //     driveStraight2(100);
    //     Conveyor.move(127);
    //     driveTurn2(90);
    //     Mogo.set_value(false);
    //     Conveyor.move(127);
    //     driveStraight2(250);
    //     driveTurn2(-45);
    //     driveClampS(-400, 100, 90);
    //     Conveyor.move(127);
    //    driveTurn2(-30);
    //    Doinker.set_value(true);
    //    driveStraight2(1000);
    //    driveTurn2(160);
      
    }

//blue left side // not done // elims

    if(atn == 7) {
    //     driveClampS(-1000, 100, 90);
    //     driveStraight2(-100);
    //     Conveyor.move(127);
    //     driveTurn2(-90);
    //     Mogo.set_value(false);
    //     Conveyor.move(127);
    //     driveStraight2(-250);
    //     driveTurn2(45);
    //     driveClampS(400, 100, 90);
    //     Conveyor.move(127);
    //    driveTurn2(30);
    //    Doinker.set_value(true);
    //    driveStraight2(-1000);
    //    driveTurn2(-160);
    }

//skills // not done

    if(atn == 8)  {

    }
//safety/ drive foward
    if(atn == 9){
    }


// dirve very slowly with drive straight slow into the 2 stack ring, (like 30%) Then go backward and raise lift and touch ladder

// driveStraightSlow(-800, 100);
// delay(400);
// driveStraightSlow(-800, 35);
// //delay(100);
// //driveStraightSlow(-1200, 40);
// //driveTurn2(10);
// //driveClamp(-500, -200);
// driveTurn2(23);
// delay(200);
// driveStraightSlow(-300, 80);
// driveStraightSlow(-150, 25);
// Mogo.set_value(true);
}

