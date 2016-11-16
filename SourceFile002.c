#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           topLeftMotor1, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           topRightMotor1, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           topLeftMotor2, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           topRightMotor2, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           flippingMotorRight, tmotorNone, openLoop)
#pragma config(Motor,  port9,           flippingMotorLeft, tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){

	while(true){
		motor[leftMotor] = vexRT[Ch3] * 1.5;
		motor[rightMotor] = vexRT[Ch2] * -1.5;

		if(vexRT[Btn7U] == 1){
			motor[topLeftMotor1] = -100;
			motor[topRightMotor1] = -100;
			//motor[topLeftMotor2] = 100;
			//motor[topRightMotor2] = -100;

		}

		if(vexRT[Btn7D] == 1){
			motor[topLeftMotor1] = 100;
			motor[topRightMotor1] = 100;
			//motor[topLeftMotor2] = -100;
			//motor[topRightMotor2] = 100;

		}


	}

}