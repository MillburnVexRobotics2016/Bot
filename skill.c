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

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                         Driver Skills Template
//
// This is a template for the driver skills competition. It is identical in structure to
// the standard competition template except that the two "#pragma' statements above (and
// copied below) adjust the time limits for the competition.
//				#pragma autonomousDuration(0)
//				#pragma userControlDuration(60)
// The autonomous duration for "Driver Skills" is zero; i.e. there is no autonomous phase.
// The user control duration is 60 seconds
//
// NOTE: The above two pragmas only impact the Crystal implementation. For systems using
//       VEXNET, the VEXNET system ignores these statements as it has the durations
//       for the competition built-in.
//
// Whenever this user program is run, the duration is automatically sent to the VEX master
// processor. The master CPU will only accept these commands once per power=on cycle. So, it's
// best to power cycle your VEX to ensure that they get recognized in case you were
// previously running a standard competition program with different durations.
//
// Testing Via Crystals:
// ====================
//
// The procedure to test a Driver Skills program using the crystals is as follows:
//
// 1. Turn off power to the Crystal transmitter/joysticks.
//
// 2. Turn on your VEX so that the Driver Skills program is running.
//
// 3. Driver skills program segment of your program will start running. At the end of 60
//    seconds the VEX Master CPU will turn off the motors.
//
// 4. Repeat the above sequence
//
//
// Testing Via VEXNET Using VEXNET Competition Switch
// ==================================================
//
// The procedure to test a Driver Skills program using VEXNET Competition Switch is as follows:
//
// 1. Set the two switches on the Competition switch to "DISABLE" and "USER CONTROL"
//
// 2. Start the Driver skills program
//
// 3. Set Switch to ENABLE from DISABLE
//
// 4. You need to manually time the 60 second duration.
//
// 5. Set Switch to DISABLE
//
// 6. Repeat from step (3) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
//
// Testing Via VEXNET Using ROBOTC IDE
// ==================================================
//
// It is not necessary to own a VEXNET switch. ROBOTC has a test window that allows the same functionality.
// The test window has three buttons for "DISABLE", "AUTONOMOUS", "USER CONTROL".
//
// 1. Open the ROBOTC Debugger. Then open the "Competition Control" Debugger window.
//
// 2. Start your Driver Skills program running.
//
// 3. Click the "DISABLED" button on the "Competition Control" window.
//
// 4. Click the "USER CONTROL" button on the "Competition Control" window.
//
// 5. You need to manually time the 60 second duration.
//
// 6. Click the "DISABLED" button on the "Competition Control" window.
//
// 7. Repeat from step (4) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
/////////////////////////////////////////////////////////////////////////////////////////

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
		motor[FL] = -speed;
		motor[FR] = -speed;
		motor[BL] = -speed;
		motor[BR] = -speed;
		}else if(direction == 4){
		//turn right
		motor[FL] = speed;
		motor[FR] = speed;
		motor[BL] = speed;
		motor[BR] = speed;
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
	motor[RightInside] = -power;
}
void liftdown(int power){
	motor[RightInside] = power;
}

task autonomous()
{
	slaveMotor(LeftInside, RightInside);
	slaveMotor(LeftOutside, RightInside);
	slaveMotor(RightOutside, RightInside);
	slaveMotor(LeftClaw, RightClaw);

	drive(BACKWARDS);
	wait1Msec(1500);


	drive(STOP);


	int idx = 1;
	liftup(20);
	while(idx < 4){
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
	liftup(0)
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

		if(vexRT[Btn5U] == 1 && vexRT[Btn5D] == 0 && triggered == 0)
		{

			motor[RightOutside] = 127;

			} else if(vexRT[Btn5D] == 1 && vexRT[Btn5U] == 0 && triggered == 0){

			motor[RightOutside] = -127;

			}else if(triggered == 0){

			motor[RightOutside] = -10;
		}

		if(vexRT[Btn6U] == 1 && vexRT[Btn6D] == 0)
		{
			motor[RightClaw] = 50;
		}else if(vexRT[Btn6D] == 1 && vexRT[Btn6U] == 0){
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
