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

 }
//red right side

    if(atn == 1) {

    }
//blue right side// not done

      if(atn == 2){
    
        }

//blue left side // not done

    if(atn == 3) {

    }
    
//red left side // not done // elims

    if(atn == 4) {
    
    }

//red right side // not done // elims

    if(atn == 5) {

    }

//blue right side // not done // elims
    if(atn == 6)  {

    }
//blue left side // not done // elims
    if(atn == 7){
       
    }
//skills/ not done
    if(atn == 8){
      
    }
//safety
    if(atn == 9){
        driveStraight2(600);
    }

}

