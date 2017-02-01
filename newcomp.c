#pragma config(Sensor, in1,    armPo,          sensorPotentiometer)
#pragma config(Motor,  port1,           BL,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           FL,            tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           LeftOutside,   tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           LeftInside,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LeftClaw,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RightClaw,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RightInside,   tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           RightOutside,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           FR,            tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port10,          BR,            tmotorVex393_HBridge, openLoop)
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

#define STOP 0
#define FORWARDS 1
#define BACKWARDS 2
#define TURNLEFT 3
#define TURNRIGHT 4


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
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
void drive(int direction){
	int speed = 100;
	if(direction == 1){
		//forwards
		motor[FL] = speed;
		motor[FR] = -speed;
		motor[BL] = speed;
		motor[BR] = -speed;
		}else if(direction == 2){
		//backwards
		motor[FL] = -speed;
		motor[FR] = speed;
		motor[BL] = -speed;
		motor[BR] = speed;
		}else if(direction == 3){
		//turn left
		motor[FL] = speed;
		motor[FR] = speed;
		motor[BL] = speed;
		motor[BR] = speed;
		}else if(direction == 4){
		//turn right
		motor[FL] = -speed;
		motor[FR] = -speed;
		motor[BL] = -speed;
		motor[BR] = -speed;
		}else{
		//stop
		speed = 0;
		motor[FL] = speed;
		motor[FR] = speed;
		motor[BL] = speed;
		motor[BR] = speed;
	}
}


//void off {
//	motor[FL] = 0;
//	motor[FR] = 0;
//	motor[BL] = 0;
//	motor[BR] = 0;
//}

//float getDesiredClawPos(){
//	float min = 1600;
//	if(SensorValue(armPo) < min)return -1;
//	float percent = armPo - min;
//	float max = 2900-min;
//	percent = percent/max;
//	return (percent > 1) ? 1 : percent;
//}

void clawclose(int power){
	motor[RightClaw] = power;
}
void clawopen(int power){
	motor[RightClaw] = -power;
}
void liftup(int power){
	motor[RightInside] = power;
}
void liftdown(int power){
	motor[RightInside] =-power;
}

void b(){

	drive(BACKWARDS);
	wait1Msec(1200);
	clawclose(127);
	wait1Msec(300);
	clawclose(0);
	liftup(127)
	wait1Msec(700);
	liftup(0);
	liftdown(127);
	wait1Msec(200);
	liftdown(0);
	drive(STOP);
	wait1Msec(500);
	liftup(127);
	wait1Msec(1200);
	liftup(0);
	clawopen(127);
	wait1Msec(400);
	clawopen(0);

}

void a(){
	liftdown(20);

	drive(FORWARDS);
	wait1Msec(1230);
	drive(STOP);

	clawclose(100);
	wait1Msec(1000);
	liftup(50);

	drive(FORWARDS);
	wait1Msec(100);
	drive(STOP);


	wait1Msec(200);
	drive(TURNLEFT); //turns left
	wait1Msec(650);
	drive(STOP);

	drive(BACKWARDS);
	wait1Msec(600);
	liftup(127);
	wait1Msec(250); //lift first time



	clawopen(127);
	wait1Msec(500);
	drive(STOP);
	wait1Msec(700);
	liftup(0);
	clawclose(85);
	wait1Msec(500);


	liftdown(127);
	wait1Msec(600);
	clawclose(0);
	wait1Msec(600);
	liftdown(0); //stop going up

	//drive(TURNRIGHT);
	//wait1Msec(250);
	//drive(STOP);
	liftdown(20)
	drive(FORWARDS);
	wait1Msec(300);
	clawopen(90);
	wait1Msec(840);

	drive(STOP);


	clawclose(127);
	liftdown(0)
	wait1Msec(1000);
	liftup(56);

	//
	wait1Msec(400);
	drive(BACKWARDS);
	wait1Msec(1000);
	clawopen(127);
	wait1Msec(650);
	drive(STOP);
	wait1Msec(900);

	clawopen(0);
	liftdown(0);
}

task autonomous()
{
	slaveMotor(LeftInside, RightInside);
	slaveMotor(LeftOutside, RightInside);
	slaveMotor(RightOutside, RightInside);
	slaveMotor(LeftClaw, RightClaw);

	a();


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

task usercontrol()
{
	// User control code here, inside the loop
	slaveMotor(LeftInside, RightOutside);
	slaveMotor(LeftOutside, RightOutside);
	slaveMotor(RightInside,RightOutside);
	slaveMotor(LeftClaw, RightClaw);

	int triggered = 0;

	while(true){
		motor[FL]  = vexRT[Ch1] + vexRT[Ch3];
		motor[FR] = vexRT[Ch1] - vexRT[Ch3];
		motor[BL]  = vexRT[Ch1] + vexRT[Ch3];
		motor[BR] = vexRT[Ch1] - vexRT[Ch3];
		wait1Msec(1);

		if(VexRT[Btn5U] == 1 && VexRT[Btn5D] == 0 && triggered == 0)
		{

			motor[RightOutside] = 127;

			} else if(VexRT[Btn5D] == 1 && VexRT[Btn5U] == 0 && triggered == 0){

			motor[RightOutside] = -127;

			}else if(triggered == 0){

			motor[RightOutside] = -10;
		}

		if(VexRT[Btn6U] == 1 && VexRT[Btn6D] == 0)
		{
			motor[RightClaw] = 50;
		}else if(VexRT[Btn6D] == 1 && VexRT[Btn6U] == 0){
			motor[RightClaw] = -80;
		}else{
			motor[RightClaw] = motor[LeftClaw] = 0;
		}

		int pos = 3600;

		if(((vexRT[Btn7D] || vexRT[Btn8D]) && SensorValue[armPo] < pos-700)|| triggered == 1){
			triggered = 1;
			motor[LeftOutside] = motor[RightInside] = 127;
			motor[RightOutside] = motor[LeftInside] = 127;

			if(SensorValue[armPo] > pos-700){
				motor[RightClaw] = motor[LeftClaw] = -127;
			}
			if(SensorValue[armPo] > pos){
				motor[LeftOutside] = motor[RightInside] = 0;
				motor[RightOutside] = motor[LeftInside] = 0;
				motor[RightClaw] = motor[LeftClaw] = 0;
				triggered = 0;
			}
		}

	}

}