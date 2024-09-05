#include "main.h"
#include "robot.h"
#include "api.h"
#include "pid.h"

using namespace pros;
using namespace c;
using namespace std;

double vKp;
double vKi;
double vKd;
double prevPower;
double currentpower;
double prevError;
double h;
double power;
float error;
int integral;
int derivitive;
int time2;
//Round two of variables. :/
double vKp2;
double vKi2;
double vKd2;
double prevPower2;
double currentpower2;
double prevError2;
double h2;
double power2;
float error2;
int integral2;
int derivitive2;
int time3;
// round three of variables 
double vKp3;
double vKi3;
double vKd3;
double prevPower3;
double currentpower3;
double prevError3;
double h3;
double power3;
float error3;
int integral3;
int derivitive3;
int time4;

void setConstants(double kp, double ki, double kd){

    vKp = kp;
    vKi = ki;
    vKd = kd;
}
 void resetEncoders(){

    LF.tare_position();
    LB.tare_position();
    LM.tare_position();
    RF.tare_position();
    RM.tare_position();
    RB.tare_position();

 }

void chasMove(int voltageLF, int voltageLM, int voltageLB, int voltageRF, int voltageRM, int voltageRB){

    LF.move(voltageLF);
    RF.move(voltageRF);
    LM.move(voltageLM);
    RM.move(voltageRM);
    LB.move(voltageLB);
    RB.move(voltageRB);

}

double calcPID(double target, double input, int integralKI, int maxIntegral){

    int integral;
    prevError = error;
    error = target - input;

    if(abs(error) < integralKI){
        integral += error; 
    }
    else{
        integral = 0;
    }
    if(integral >= 0){
        integral = min(integral, maxIntegral);
    }
    else{
        integral = max(integral, -maxIntegral);
    }
    derivitive = error - prevError;

    power = (vKp * error) + (vKi * integral) + (vKd * derivitive);

    return power;

    
}

double calcPID2(double target2, double input2, int integralKI2, int maxIntegral2){

    int integral2;
    prevError2 = error2;
    error2 = target2 - input2;

    if(abs(error2) < integralKI2){
        integral2 += error2;
    }
    else{
        integral2 = 0;
    }
    if(integral2 >= 0){
        integral2 = min(integral2, maxIntegral2);
    }
    else{
        integral2 = max(integral2, -maxIntegral2);
    }
    derivitive2 = error2 - prevError2;

    power2 = (vKp * error2) + (vKi * integral2) + (vKd * derivitive2);

    return power2;

}

double calcPID3(double target3, double input3, int integralKI3, int maxIntegral3){

    int integral3;
    prevError3 = error3;
    error3 = target3 - input3;

    if(abs(error3) < integralKI3){
        integral3 += error3;
    }
    else{
        integral3 = 0;
    }
    if(integral3 >= 0){
        integral3 = min(integral3, maxIntegral3);
    }
    else{
        integral3 = max(integral3, -maxIntegral3);
    }
    derivitive3 = error3 - prevError3;

    power3 = (vKp * error3) + (vKi * integral3) + (vKd * derivitive3);

    return power3;

}

void driveStraight(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000067183 * pow(x,5)) + (0.0000000004403 * pow(x,4)) + (-0.00000099119 * pow(x,3)) + (0.000800677 * pow(x,2)) + (0.3149 * x) + 347.405;

    imu.tare();

    

    double voltage;
    double encoderAVG;
    int count = 0;
    double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    if(init_heading > 180){
        init_heading = init_heading - 360;
    }

    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
         setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
      
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
           init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    } else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) && (position < 0)){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        
        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
            break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
             con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}


 void driveTurn(int target){

    double voltage;
    double position;
    int count = 0;
    time2 = 0;
    int timeout = 1000000;
    double x = 0;
    double variKD = 0;
    double variKP = 0;
    x = double(abs(target));
    variKD = ((-0.000000010414) * pow(x,5)) + (0.00000436151 * pow(x,4)) + (-0.000635881 * pow(x,3)) + (0.0378021 * pow(x,2)) + (-0.805858 * x) + 69.3766;
    variKP = ((0.00000000017809) * pow(x,5)) + (-0.000000087322 * pow(x,4)) + (0.000015948* pow(x,3)) + (-0.00128717 * pow(x,2)) + (0.041072 * x) + 6.7388;
    setConstants(variKP, TURN_KI, variKD);
    timeout = (0.00000017585*pow(x,5)) + (0.0000801483*pow(x,4)) + (0.0128744*pow(x,3)) + (0.83763*pow(x,2)) + (-13.6245*(x)) + 476.675;
    imu.tare_heading();

    while(true) { 
        position = imu.get_heading();

        if (position > 180){
            position = ((360 - position) * -1);

        }
        voltage = calcPID(target, position, TURN_INTEGRAL_KI, TURN_MAX_INTEGRAL);

        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

        // break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(2,0, "Time2: %f           ", float(time2));
        }
        
        time2 += 10;
        delay(10); 
    }
        LF.brake();
        LM.brake();
        LB.brake();
        RF.brake();
        RM.brake();
        RB.brake();

}

 void driveTurn2(int target){
    int turnv;
    double voltage;
    double position;
    int count = 0;
    time2 = 0;

    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }

    int timeout = 1000000;
    double x = 0;
    double variKD = 0;
    double variKP = 0;
    x = double(abs(turnv));
    timeout = (0.00000017585*pow(x,5)) + (0.0000801483*pow(x,4)) + (0.0128744*pow(x,3)) + (0.83763*pow(x,2)) + (-13.6245*(x)) + 476.675;
    variKD = ((-0.000000010414) * pow(x,5)) + (0.00000436151 * pow(x,4)) + (-0.000635881 * pow(x,3)) + (0.0378021 * pow(x,2)) + (-0.805858 * x) + 69.3766;
    variKP = ((0.00000000017809) * pow(x,5)) + (-0.000000087322 * pow(x,4)) + (0.000015948* pow(x,3)) + (-0.00128717 * pow(x,2)) + (0.041072 * x) + 6.7388;
    setConstants(variKP, TURN_KI, variKD);
    while(true) { 
    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }
        voltage = calcPID(target, position, TURN_INTEGRAL_KI, TURN_MAX_INTEGRAL);

        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

            break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        time2 += 10;
        delay(10); 
    }
        LF.brake();
        LM.brake();
        LB.brake();
        RF.brake();
        RM.brake();
        RB.brake();

}

void driveStraight2(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
     timeout = (-0.000000000000067183 * pow(x,5)) + (0.0000000004403 * pow(x,4)) + (-0.00000099119 * pow(x,3)) + (0.000800677 * pow(x,2)) + (0.3149 * x) + 347.405;

    double voltage;
    double encoderAVG;
    int count = 0;
    double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(init_heading > 180) {
    init_heading = (360 - init_heading);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
            init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    } else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) && (position < 0)){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}

void driveStraightC(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
     timeout = (-0.000000000000067183 * pow(x,5)) + (0.0000000004403 * pow(x,4)) + (-0.00000099119 * pow(x,3)) + (0.000800677 * pow(x,2)) + (0.3149 * x) + 347.405;
 if (target > 0){
    target = target + 500;
 } else{
    target = target - 500;
 }
    double voltage;
    double encoderAVG;
    int count = 0;
    double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;
    bool over = false;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(init_heading > 180) {
    init_heading = (360 - init_heading);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
            init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    } else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) && (position < 0)){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if(target > 0){
            if((encoderAVG - (target-500)) > 0){
                over = true;
            }
        } else if(((target+500) - encoderAVG) > 0){
        over = true;
        }

        if(over || time2 > timeout){
            break;
        }



        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}

void driveArcL(double theta, double radius, int timeout){
// bool over = false; 
// setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

double ltarget = 0; 
double rtarget = 0;
double pi = 3.14159265359;
// . I'm sorry :/ Now deal with pi. cole. why the sigma are you doing this - carlos
double init_heading = imu.get_heading();

if(init_heading > 180){
    init_heading = init_heading - 360;
}
int time = 0;
int count = 0;
resetEncoders();



ltarget = double((theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 570 ));

while(true){

setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
double encoderAvgL = LF.get_position(); 
double encoderAvgR = RB.get_position();
 int voltageL = calcPID(ltarget, encoderAvgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageL > 127){
        voltageL = 127;
    }else if(voltageL < -127){
        voltageL = -127;
    }

    int voltageR = calcPID2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127){
        voltageR = 127;
    }else if(voltageR < -127){
        voltageR = -127;
    }

double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}

if((leftcorrect < 0) && (position > 0)){
        if((position - leftcorrect ) >= 180){
            leftcorrect = leftcorrect + 360;
            position = imu.get_heading();
        }
    } else if((leftcorrect > 0) && (position < 0)){
        if ((leftcorrect - position) && (position < 0)){
            position = imu.get_heading();
        }
     }
    setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
    int fix = calcPID3((init_heading + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);

              
        chasMove( (voltageL + fix), (voltageL + fix), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
        if ((abs(ltarget - encoderAvgL) <= 4) && (abs(rtarget - encoderAvgR) <= 4) ) count++;
        if (count >= 20 || time > timeout){
            break;
        }

     if(time % 50 == 0 && time % 100 != 0 && time % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time));
        }
         if(time % 50 == 0 && time % 100 != 0){
            con.print(2,0, "Voltage: %f           ",float(voltageL));
        }
         if(time % 50 == 0){
            con.print(1,0, "leftcorrect: %f           ", float(leftcorrect));
        }
        

        time+= 10;
        delay(10);


    }
}


void driveArcR(double theta, double radius, int timeout){
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);


double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
double init_heading = imu.get_heading();
if(init_heading > 180){
    init_heading = init_heading - 360;
}
int count = 0;
time2 = 0;
resetEncoders();

rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 570)); 


////////////
while (true){

if(init_heading > 180){
    init_heading = init_heading - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}
double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
double encoderAVGR = (RB.get_position() + RB.get_position()) /2;
double rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);

if((rightcorrect < 0) && (position > 0)){
        if((position - rightcorrect) >= 180){
            rightcorrect = rightcorrect + 360;
            position = imu.get_heading();
        }
    } else if((rightcorrect > 0) && (position < 0)){
        if ((rightcorrect - position) >= 180){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
       
         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
    if (voltageL > 127){
        voltageL = 127;
    }else if(voltageL < -127){
        voltageL = -127;
    }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127){
        voltageR = 127;
    }else if(voltageR < -127){
        voltageR = -127;
    }
    
    setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((init_heading + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);


    chasMove( (voltageL + fix), (voltageL + fix ), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
    if ((abs(ltarget - encoderAVGL) <= 4) && (abs(rtarget - encoderAVGR)<= 4)) count++;
    if (count >= 20  || time2 > timeout){
       break;
    }
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "position: %f           ", float(position));
        }else if(time2 % 50 == 0){
            con.print(2,0, "init_heading: %f         ", float(init_heading + rightcorrect));
        }
        time2 += 10;
        delay(10);
    }   
}

void driveArcLF(double theta, double radius, int timeout){

setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

double ltarget = 0; 
double rtarget = 0;
double ltargetF = 0; 
double rtargetF = 0;
double pi = 3.14159265359;
// . I'm sorry :/ Now deal with pi. 
double init_heading = imu.get_heading();
int time = 0;
int count = 0;
bool over = false;
resetEncoders();
ltargetF = double(( theta/360) *2 * pi * radius);
rtargetF = double((theta / 360) * 2 * pi *(radius + 750 ));
theta = theta + 45;
ltarget = double(( theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 750 ));
while(true){

if(init_heading > 180){
    init_heading = init_heading - 360;
}
double position = imu.get_heading();


if(position > 180){
    position = position - 360;
}
double encoderAvgL = LF.get_position(); 
double encoderAvgR = RB.get_position();
double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);

if((leftcorrect < 0) && (position > 0)){
        if((position - leftcorrect ) >= 180){
            leftcorrect = leftcorrect + 360;
            position = imu.get_heading();
        }
    } else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) && (position < 0)){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
 
    int voltageL = calcPID(ltarget, encoderAvgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageL > 127){
        voltageL = 127;
    }else if(voltageL < -127){
        voltageL = -127;
    }

    int voltageR = calcPID2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127){
        voltageR = 127;
    }else if(voltageR < -127){
        voltageR = -127;
    }

 setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((init_heading + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);

        chasMove( (voltageL + fix), (voltageL + fix), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
        if (theta > 0){
            if ((encoderAvgL - ltargetF) > 0){
                over = true;
            }
        } else {
            if ((ltargetF - encoderAvgL)>0){
                over = true;
            }
        }

        if (over || time > timeout){
            break;
        }

     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        

        time+= 10;
        delay(10);


    }
}


void driveArcRF(double theta, double radius, int timeout){
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
bool over = false;
double ltargetF = 0;
double rtargetF = 0;
double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
// . I'm sorry :/ Now deal with pi. 
double init_heading = imu.get_heading();
if(init_heading > 180){
    init_heading = init_heading - 360;
}
int count = 0;
int time2 = 0;
resetEncoders();
rtargetF = double((theta/360) *2 * pi * radius);
ltargetF= double((theta / 360) * 2 * pi *(radius + 750)); 
theta = theta + 45;
rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 750)); 

while (true){

if(init_heading > 180){
    init_heading = init_heading - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}

if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
            init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    } else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) && (position < 0)){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
         double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
         double encoderAVGR = (RB.get_position() + RB.get_position()) /2;
         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
    if (voltageL > 127){
        voltageL = 127;
    } else if(voltageL < -127){
        voltageL = -127;
    }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127){
        voltageR = 127;
    }else if(voltageR < -127){
        voltageR = -127;
    }
    double rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);
        setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((init_heading + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);


    chasMove( (voltageL - fix), (voltageL - fix ), (voltageL - fix), (voltageR + fix), (voltageR + fix), (voltageR + fix));
   if (theta > 0){
    if ((encoderAVGR - (rtargetF)) > 0){
        over = true;
    }
   } else {
    if(((rtarget) - encoderAVGR) > 0){
        over = true;
    }
   }
    if (over || time2 > timeout){
        break;
    }
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "encodeR %f           ", float(encoderAVGR));
        }else if(time2 % 50 == 0){
            con.print(2,0, "encodeL: %f         ", float(encoderAVGL));
        }
        time2 += 10;
        delay(10);
    }   
}