/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//motor definitions
#pragma config(Motor,  port1,           frontLeft,     tmotorVex393_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port2,           backRight,     tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           claws,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           arms,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           xLeft,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           xRight,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           frontRight,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port10,          backLeft,      tmotorVex393_HBridge, openLoop, reversed, driveLeft)
//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

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

task autonomous()
{

  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}


//drive sub task\
//called in the main task
task driveM()
{
	int deadzone = 20;
	while(true)
	{
		if(vexRT[Ch3Xmtr2] > deadzone || vexRT[Ch3Xmtr2] < -(deadzone) || vexRT[Ch4Xmtr2] > deadzone || vexRT[Ch4Xmtr2] < -(deadzone)){

			if(vexRT[Ch3Xmtr2] > deadzone || vexRT[Ch3Xmtr2] < -(deadzone)){
	  		motor[frontLeft] = vexRT[Ch3Xmtr2];
	  		motor[backLeft] = vexRT[Ch3Xmtr2];
	  		motor[frontRight] = -(vexRT[Ch3Xmtr2]);
	  		motor[backRight] = -(vexRT[Ch3Xmtr2]);
	  	}

	  	if(vexRT[Ch4Xmtr2] > deadzone || vexRT[Ch4Xmtr2] < -deadzone){
	  		motor[frontLeft] += vexRT[Ch4Xmtr2];
	  		motor[backLeft] += vexRT[Ch4Xmtr2];
	  		motor[frontRight] += vexRT[Ch4Xmtr2];
	  		motor[backRight] += vexRT[Ch4Xmtr2];
	  	}

	  }else{
	  	motor[frontLeft] = motor[backLeft] = motor[frontRight] = motor[backRight] = 0;
	  }
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

task usercontrol()
{
  // User control code here, inside the loop

  int deadzone = 20;
	int scissorbase = 105;

	int screl = -5;

	int clawSpeed = 100;

	startTask(driveM);
	while(true){


	//claw and arm rotation
	  if(vexRT[Ch2] > deadzone || vexRT[Ch2] < -(deadzone)){
	  	motor[arms] = (vexRT[Ch2]/1.75);
	  }else{
	  	motor[arms] = 0;
	  }

	  if(vexRT[Btn5D]){
	  	motor[claws] = clawSpeed;
	  }
	  else if(vexRT[Btn5U]){
	  	motor[claws] = -clawSpeed;
	  }else{
	  	motor[claws] = 0;
	  }

	  bool clicked = false;
		//adjusts the speeds of the scissor lift motors
		if(vexRT[Btn8L] && clicked == false) { screl -= 5; clicked = true; } else
		if(vexRT[Btn8R] && clicked == false) { screl += 5; clicked = true; }
		else { clicked = false; }

		if(vexRT[Btn6U]){
			screl = 0;
		}
		//raises and lowers the scissor lift

		if(vexRT[Btn7L] == 1) {
			motor[xRight] = -(scissorbase + screl);
			motor[xLeft] = (scissorbase + screl);
		}
		else if(vexRT[Btn7D] == 1 ) {
			motor[xRight] = (scissorbase + screl);
			motor[xLeft] = -(scissorbase + screl);
		}else {
			motor[xLeft] = 0;
			motor[xRight] = 0;
		}
	}
}
