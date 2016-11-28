#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           topLeftMotor1, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           topRightMotor1, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           topLeftMotor2, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           topRightMotor2, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           flippingMotorRight, tmotorNone, openLoop)
#pragma config(Motor,  port9,           flippingMotorLeft, tmotorNone, openLoop)

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

// Variables !!!!!!!!!!!!!!!!!!!!!!!!!!!!

//**Up means Positive **Down means negative
int armSpeedUp = 50;
int armSpeedDown = -50;

//basicMovement()
int controlSensitivityUp = 1.5;
int controlSensitivityDown = -1.5;

int stop_motor = 0;


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

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous(){

}
//This is for the wheels to move
void basicMovement(){
  motor[leftMotor] = vexRT[Ch3] * controlSensitivityUp;
  motor[rightMotor] = vexRT[Ch2] * controlSensitivityDown;
}

//creates a speed code for all the motors of the arm
void createMovementSpeed(int a, int b, int c, int d){
  motor[topLeftMotor1] = a;
  motor[topRightMotor1] = b;
  motor[topLeftMotor2] = c;
  motor[topRightMotor2] = d;
}

//takes in the int values and creates speed code
void armMoveUp(){
  createMovementSpeed(armSpeedUp,armSpeedDown,armSpeedUp,armSpeedDown);
}

void armMoveDown(){
  createMovementSpeed(armSpeedDown,armSpeedUp,armSpeedDown,armSpeedUp);
}

void armMoveStop(){
  createMovementSpeed(stop_motor,stop_motor,stop_motor,stop_motor);
}


void armMovement(){

  if(vexRT[Btn7U] == 1){

    armMoveUp();

  } else if(vexRT[Btn7D] == 1){

    armMoveDown();

  } else if(vexRT[Btn7U] == 0){

    armMoveStop();

  } else if(vexRT[Btn7D] == 0){

    armMoveStop();

  } 
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol(){
  // User control code here, inside the loop

  while (true){

    //wheels
    basicMovement();

    //arm
    armMovement();

  }
}
