//leftmotor1
//leftmotor2
//rightmotor1
//rightmotor2
//clawright
//clawleft
//topleftMotor
//topleftMotor

// This code is for the VEX
cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

// Variables !!!!!!!!!!!!!!!!!!!!!!!!!!!!

///helperMode starts On
bool helperMode_on = false;

//basicMovement()
int controlSensitivity = 1.5;

//claw speeds
int openClawSpeed = 100;
int closeClawSpeed = 100;

//armSpeed FYI:: 2 and 4 were reversed
int armSpeedOpen = 127;
int armSpeedClose = -127;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(){
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

//This is for the wheels to move
void basicMovement(){
  motor[leftMotor1] = vexRT[Ch1] * controlSensitivity;
  motor[leftMotor2] = vexRT[Ch1] * controlSensitivity;

  motor[rightMotor1] = vexRT[Ch2] * controlSensitivity;
  motor[rightMotor2] = vexRT[Ch2] * controlSensitivity;
}

void createMovementArmSpeed(int speed){
  motor[topLeftMotor] = speed;
  motor[topRightMotor] = speed;

}

void armUp(){
	createMovementSpeed(armSpeedOpen);
}

void armDown(){
	createMovementSpeed(armSpeedClose);
}

void armStop(){
	createMovementSpeed(armSpeedStop);
}


void clawOpen(){
	motor[clawLeft] = openClawSpeed;
	motor[clawRight] = openClawSpeed;
}

void clawClose(){
	motor[clawLeft] = closeClawSpeed;
	motor[clawRight] = closeClawSpeed;
}

void clawStop(){
	motor[clawLeft] = 0;
	motor[clawRight] = 0;
}

void basicArmAndClaw(){
	if(vexRT[Ch3] >= 80){
		armUp();
	}
	else if(vexRT[Ch3] <= -80){
		armDown();
	}
	else if((vexRT[Ch3] >= -80) && (vexRT[Ch3] <= 80)){
		armStop();
	}
	else if(vexRT[Ch4] >= 80){
		clawOpen();
	}
	else if(vexRT[Ch4] <= -80){
		clawClose();
	}
	else if((vexRT[Ch4] >= -80) && (vexRT[Ch4] <= 80)){
		clawStop();
	}
}

void helperModeOn(){
	if(helperMode_on == false){
		helperMode_on = true;
	}
}

void helperModeOff(){
	if(helperMode_on == true){
		helperMode_on = false;
	}
}

void helperModeActivate(){
	if(vexRT[Btn8L] == 1){

    	helperModeOff();

  	}
  	else if(vexRT[Btn8R] == 1){

  		helperModeOn();

  	}
}

void helperMode(){
	//user control help code for multiple controls

	if(vexRT[Btn7D] == 1){

	}
	else if(vexRT[Btn7U] == 1){

	}
	else if(vexRT[Btn6U] == 1){

	}
	else if(vexRT[Btn6D] == 1){

	}
	else if(vexRT[Btn5U] == 1){

	}
	else if(vexRT[Btn5D] == 1){

	}
}
void manualMode(){

  //wheels
  basicMovement();

  //armsAndClaw
  basicArmAndClaw();

	//all buttons need to be click no auto moves

	if(vexRT[Btn7D] == 1){

	}
	else if(vexRT[Btn7U] == 1){

	}
	else if(vexRT[Btn6U] == 1){

	}
	else if(vexRT[Btn6D] == 1){

	}
	else if(vexRT[Btn5U] == 1){

	}
	else if(vexRT[Btn5D] == 1){

	}
}

task autonomous(){
	// <!----!!!!!!!!! Need to make it for both side !!! based on the schedule
	// Definitely would want the side near the hanging-->

	//open the wrap

	//pick up the cube

	//drop the cube

	//knock stars over 3 in the front

	//go back

	//open claw

	//move to the right !!! or left

	//knock stars over in the middle
}

task usercontrol(){
  // User control code here, inside the loop

  while (true){
  	//check for button activition clicks
  	helperModeActivate();
  	if(helperMode_on == true){
  		helperMode();
  	} else {
  		manualMode();
  	}

  }
}
