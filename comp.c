#pragma config(Sensor, in1,    armPo,          sensorPotentiometer)
#pragma config(Motor,  port2,           BL,            tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           FL,            tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port4,           TLArms,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           TRArms,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           BArms,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Claws,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           BR,            tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port9,           FR,            tmotorVex393_MC29, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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

//Drive function for the autonomous section
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
		motor[FR] = -speed;
		motor[BL] = -speed;
		motor[BR] = speed;
		}else if(direction == 4){
		//turn right
		motor[FL] = -speed;
		motor[FR] = speed;
		motor[BL] = speed;
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
	motor[Claws] = power;
}
void clawopen(int power){
	motor[Claws] = -power;
}
void liftup(int power){
	motor[BArms] = -power;
}
void liftdown(int power){
	motor[BArms] = power;
}

//autonomous code here
task autonomous()
{
	slaveMotor(TLArms, BArms);
	slaveMotor(TRArms, BArms);
	drive(FORWARDS);
	wait1Msec(1200);
	drive(STOP);

	clawopen(100);
	wait1Msec(1000);
	liftup(35);

	drive(FORWARDS);
	wait1Msec(100);
	drive(STOP);


	wait1Msec(200);
	drive(TURNLEFT); //turns left
	wait1Msec(1160);
	drive(STOP);

	drive(BACKWARDS);
	wait1Msec(750);
	liftup(127);
	wait1Msec(650); //lift first time
	drive(STOP);


	clawclose(70);
	wait1Msec(500);
	liftup(0);
	wait1Msec(500);
	clawopen(0);

	liftdown(127);
	wait1Msec(2000);
	liftdown(0); //stop going up

	//drive(TURNRIGHT);
	//wait1Msec(250);
	//drive(STOP);

	drive(FORWARDS);
	wait1Msec(1300);
	drive(STOP);

	clawopen(127);
	wait1Msec(800);
	liftup(56);

	//

	drive(BACKWARDS);
	wait1Msec(1600);
	drive(STOP);

	clawclose(127);
	wait1Msec(600);
	clawclose(0);
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

//drive sub task
//called in the main task
task driveM()
{
	int tval;
	int fval;

	int deadzone = 20;
	while(true)
	{
		tval = 0;
		fval = 0;

		if(
			abs(vexRT[Ch1]) > deadzone || abs(vexRT[Ch4]) > deadzone){
			if(abs(vexRT[Ch1]) > abs(vexRT[Ch4])){
				fval = -vexRT[Ch1];
			}
			else
			{
				fval = -vexRT[Ch4];
			}
			}else{
			fval = 0;
		}

		if(abs(vexRT[Ch3]) > deadzone){
			tval = vexRT[Ch3];
			}else{
			tval = 0;
		}

		if(fval != 0 || tval != 0){

			int L = -fval + tval;

			int R = -fval - tval;

			L=-fval+tval;

			R=-fval-tval;

			if(L > 127)
				L = 127;

			if(L < -127)
				L = -127;

			if(R > 127)
				R = 127;

			if(R < -127)
				R = -127;

			motor[FL] = L;
			motor[BL] = L;
			motor[FR] = R;
			motor[BR] = R;
			}else{
			motor[FL] = motor[BL] = motor[FR] = motor[BR] = 0;
		}
	}
}


task usercontrol()
{
	//starts the seperate drive task, so as to avoid any lag issues
	startTask(driveM);
	//slaves all arm controls to the BArms name, all arm movements should happen at the same time
	slaveMotor(TLArms, BArms);
	slaveMotor(TRArms, BArms);
	//float desiredPos Btn7U
	int triggered = 0;
	int controls = 0;
	int hold = 0;
	//resetSensor(in1);
	int armd1, armd2, armu1, armu2, clawo1, clawo2, clawc1, clawc2;
	//if(controls == 0){
		armd1 = Btn5D;
		armd2 = Btn8D;
		armu1 = Btn5U;
		armu2 = Btn8L;
		clawo1 = Btn6D;
		clawo2 = Btn8U;
		clawc1 = Btn6U;
		clawc2 = Btn8R;
		//}else{
		//armd1 = Btn5U;
		//armd2 = Btn8D;
		//armu1 = Btn7L;
		//armu2 = Btn8L;
		//clawo1 = Btn6D;
		//clawo2 = Btn8U;
		//clawc1 = Btn6U;
		//clawc2 = Btn8R;
//	}
	while(true)
	{

		//main arm up down

		//arm notes
		//a negative value sends arm up, positive down
		//armPo is the shaft encoder for the arms, values go from 0 to about 4000, actually allows 265 degrees of movement for the axle
		//up
		if((vexRT[armd1] || vexRT[armd2]) && triggered == 0){
			motor[BArms] = -127;
			}else if((vexRT[armu1] || vexRT[armu2]) && triggered == 0){
			//down
			motor[BArms] = 127;
			//}else if(triggered == 0 && SensorValue[armPo] > 150){
			//	motor[BArms] = 20;
			}else if(triggered == 0){
			motor[BArms] = 0;
		}
		//claw open and close
		if((vexRT[clawo1] || vexRT[clawo2])){
			motor[Claws] = 127;
			}else if(vexRT[clawc1] || vexRT[clawc2]){
			motor[Claws] = -127;
			}else{
			motor[Claws] = 0;
		}

		//auto throw over the fence
		int height = 3250;
		if(((vexRT[Btn7D] || vexRT[Btn8D]) && SensorValue[armPo] < height - 1000)|| triggered == 1)
		{
			triggered = 1;
			motor[BArms] = -127;
			if(SensorValue[armPo] > height - 1200){
				motor[Claws] = 127;
			}
			if(SensorValue[armPo] > height){
				motor[Claws] = 0;
				motor[BArms] = 0;
				triggered = 0;
			}
		}

		if(vexRT(Btn7L) || vexRT(Btn8L)){
			 hold = 1200 - SensorValue(armPo);
			 if(hold > 0)
			   motor[BArms] = -hold;
		}

		if(vexRT(Btn7U) == 1){
			motor[Claws] = 0;
			motor[BArms] = 0;
			triggered = 0;
			motor[FL] = 0;
			motor[BL] = 0;
			motor[FR] = 0;
			motor[BR] = 0;
		}

		if(vexRT[Btn8DXmtr2]){
			if(SensorValue[armPo] < 300){
				motor[BArms] = 40;
			}
			else if(SensorValue[armPo] > 275){
				motor[BArms] = 0;
			}
		}


	}
}
