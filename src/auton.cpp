#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "pid.h"
using namespace std;
using namespace pros;


void autonomous() {


//red left
 if(atn == 0){
    imu.tare();
    driveStraight2(-400);
    driveTurn2(90);
    driveStraightSlow(-200, 50);
    Conveyor.move(100);
    delay(100);
    Conveyor.move(0);
    delay(200);
    Conveyor.move(-127);
    delay(750);
    Conveyor.move(0);
    imu.tare();
    driveStraightSlow(700, 80);
    driveTurn2(90);
    driveStraightSlow(-530, 80);
    driveTurn2(150);
    driveClampS(-1000, 100, 90);
    driveTurn2(-100);
    Conveyor.move(-127);
    delay(100);
    driveStraightSlow(800, 60);
    driveTurn2(-10);
    delay(300);
    driveStraightSlow(500, 50);
    driveStraight2(-200);
    driveTurn2(-30);
    driveStraightSlow(350, 50);


    // driveTurn2(-40);
    // delay(100);
    // driveStraightSlow(175, 80);
    // driveStraight(-300);
    // driveTurn(10);
    // driveStraight2(1200);
    
        // Conveyor.move(0);
        // driveStraight2(-420);
        // driveTurn2(90);
        // driveStraightSlow(-200, 40);
        // delay(500);
        // Conveyor.move(-127);
        // delay(750);
        // driveStraight2(350);
        // Conveyor.move(0);
        // imu.tare();
        // driveTurn2(134);
        // driveClampS(-1590, 100, 60);
        // driveTurn2(-96);
        // Conveyor.move(-127);
        // delay(500);
        // driveStraight(1000);
        // imu.tare();
        // driveTurn2(110);
        // driveStraightSlow(600, 50);
        // driveStraight2(-200);
        // imu.tare();
        // driveTurn2(-70);
        // driveStraight2(300);
        

        //driveTurn2(-125);
        //
        //driveClampS(-1600, 100, 70);
        //driveTurn2(0);
        //Conveyor.move(-127);
        //driveStraight2(765);



 }
//Blue right side

      if(atn == 1) {

      }
//red right side 

      if(atn == 2){ 
        driveStraightC(-1200);
        driveTurn2(-35);
        driveClampS(-450, 10, 80);
        Conveyor.move(127);
        driveTurn2(10);
        Conveyor.move(-127);
        driveStraight(800);
        delay(300);
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
        
      


      }

//blue left side// not done

      if(atn == 3){
        driveStraightC(-1200);
        driveTurn2(35);
        driveClampS(-450, 10, 80);
        Conveyor.move(127);
        driveTurn2(-10);
        Conveyor.move(-127);
        driveStraight(800);
        delay(300);
        Conveyor.move(0);
        driveTurn2(-150);
        driveStraight2(-500);
        Mogo.set_value(false); 
        driveStraight2(850);
        driveTurn2(110);
        driveClampS(-1000, 50, 90);
        Conveyor.move(-127);
        delay(700);
        imu.tare();
        driveTurn2(90);
        driveStraight2(600);
      }

//red left side// not done

      if(atn == 4){
    

        }






//blue right side // not done /// elims

    if(atn == 5) {

    }
    
//red right side // not done // elims

    if(atn == 6) {
   
      
    }

//blue left side // not done // elims

    if(atn == 7) {

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

