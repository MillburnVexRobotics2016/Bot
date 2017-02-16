#pragma config(Sensor, in1,    armPo,          sensorPotentiometer)
#pragma config(Sensor, in2,    sdfg,           sensorPotentiometer)
#pragma config(Sensor, in3,    asfd,           sensorPotentiometer)
#pragma config(Sensor, in4,    uguy,           sensorPotentiometer)
#pragma config(Sensor, in5,    yt,             sensorPotentiometer)
#pragma config(Sensor, in6,    oug,            sensorPotentiometer)
#pragma config(Sensor, in7,    jhb,            sensorPotentiometer)
#pragma config(Sensor, in8,    yut,            sensorPotentiometer)
#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           Claw,          tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           RightLift,     tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port4,           LeftLift,      tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port5,           SidesLift,     tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port6,           BR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           FR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           BL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           FL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,           ,             tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

#define STOP 0
#define FORWARDS 1
#define BACKWARDS 2
#define TURNLEFT 3
#define TURNRIGHT 4
#define OPENHEIGHT 2600



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

void clawclose(int power){
	motor[Claw] = power;
}
void clawopen(int power){
	motor[Claw] = -power;
}
void liftup(int power){
	motor[RightLift] = -power;
}
void liftdown(int power){
	motor[RightLift] = power;
}

task autonomous()
{
	slaveMotor(SidesLift, RightLift);
	slaveMotor(LeftLift, RightLift);

	drive(BACKWARDS);
	wait1Msec(1400);


	drive(STOP);


	int idx = 1;
	liftup(20);
	while(idx < 4){
		liftdown(127);
		wait1Msec(600);
		clawopen(60);
		liftup(40);
		drive(FORWARDS);
		wait1Msec(750);
		drive(STOP);
		wait1Msec(100);
		clawclose(127);
		wait1Msec(100);
		wait1Msec(1000);
		liftdown(100);

		//
		drive(BACKWARDS);
		wait1Msec(950);

		liftdown(127);
		clawopen(127);
		wait1Msec(400);
		drive(STOP);
		wait1Msec(500);
		clawopen(0);
		drive(STOP);

		wait1Msec(500);
		liftdown(0);
		wait1Msec(500);
		clawclose(0);
		//wait1Msec(500);
		liftup(127);
		wait1Msec(1200);
		liftup(0);
		idx++;
	}
	clawopen(45);
	drive(BACKWARDS);
	wait1Msec(300);
	drive(STOP);
	drive(FORWARDS);
	wait1Msec(650);
	drive(STOP);
	liftup(40);
	wait1Msec(300);
	drive(TURNLEFT);

	wait1Msec(450);
	drive(STOP);
	liftup(40);
	drive(FORWARDS);
	wait1Msec(850);
	clawclose(127);
	wait1Msec(900);
	liftup(0);
	liftdown(45);
	drive(STOP);
	drive(TURNRIGHT);
	wait1Msec(450);
	drive(STOP);
	drive(BACKWARDS);
	wait1Msec(300);
	liftdown(127);
	wait1Msec(750);
	drive(STOP);
	clawopen(127);
	wait1Msec(600);
	clawopen(0);
	liftup(127);
	wait1Msec(1200);
	liftdown(0);
	drive(FORWARDS);
	wait1Msec(900);
	clawclose(127);
	wait1Msec(400);
	liftup(30);
	drive(BACKWARDS);
	wait1Msec(600);
	liftup(127);
	wait1Msec(400);
	clawopen(127);
	wait1Msec(500);
	liftdown(0);



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
	slaveMotor(SidesLift, RightLift);
	slaveMotor(LeftLift, RightLift);

	int triggered = 0;

	while(true){
		motor[FL]  = vexRT[Ch1] + vexRT[Ch3];
		motor[FR] = vexRT[Ch1] - vexRT[Ch3];
		motor[BL]  = vexRT[Ch1] + vexRT[Ch3];
		motor[BR] = vexRT[Ch1] - vexRT[Ch3];
		wait1Msec(1);

		if(vexRT[Btn5U] == 1 && vexRT[Btn5D] == 0 && triggered == 0)
		{

			motor[RightLift] = 127;

			} else if(vexRT[Btn5D] == 1 && vexRT[Btn5U] == 0 && triggered == 0){

			motor[RightLift] = -127;

			}else if(triggered == 0){

			motor[RightLift] = -10;
		}

		if(vexRT[Btn6U] == 1 && vexRT[Btn6D] == 0)
		{
			motor[Claw] = 65;
		}else if(vexRT[Btn6D] == 1 && vexRT[Btn6U] == 0){
			motor[Claw] = -70;
		}else{
			motor[Claw] = 0;
		}

		if(((vexRT[Btn7D] || vexRT[Btn8D]) && SensorValue[armPo] < OPENHEIGHT-700)|| triggered == 1){
			triggered = 1;
			motor[RightLift] = 127;

			if(SensorValue[armPo] > OPENHEIGHT-700){
				motor[Claw] = -127;
			}
			if(SensorValue[armPo] > OPENHEIGHT){
				motor[RightLift] = 0;
				motor[Claw] = 0;
				triggered = 0;
			}
		}
	}
}
