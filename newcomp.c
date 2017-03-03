#pragma config(Sensor, in1,    armPo,          sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  encoderL,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  encoderR,       sensorQuadEncoder)
#pragma config(Motor,  port2,           FL,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           BL,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           FR,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           BR,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           LA,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RA,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LC,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RC,            tmotorVex393_MC29, openLoop)
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

int Mode = 0;
int Type = 0;
int Side = 0;


#define STOP 0
#define FORWARDS 1
#define BACKWARDS 2
#define TURNLEFT 3
#define TURNRIGHT 4
#define OPENHEIGHT 3315
#define LEFTBTN 1
#define CENTERBTN 2
#define REGULAR 1
#define COUNTER 2
#define LEFTSIDE 1
#define RIGHTSIDE 2
#define BOX 1
#define STRAIGHTBACK 2
#define CIRC 4


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
	SensorValue[gyro] = 0;
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
	int speed = 90;
	if(direction == 1){
		//forwards
		motor[FL] = speed;
		motor[FR] = speed;
		}else if(direction == 2){
		//backwards
		motor[FL] = -speed;
		motor[FR] = -speed;
		}else if(direction == 3){
		//turn left
		motor[FL] = -speed;
		motor[FR] = speed;
		}else if(direction == 4){
		//turn right
		motor[FL] = speed;
		motor[FR] = -speed;
		}else{
		//stop
		speed = 0;
		motor[FL] = speed;
		motor[FR] = speed;
	}
}




void clawclose(int power){
	motor[RC] = -power;
	motor[LC] = -power;
}
void clawopen(int power){
	motor[RC] = power;
	motor[LC] = power;
}


void liftup(int power){
	motor[RA] = power;
}
void liftdown(int power){
	motor[RA] =-power;
}

void b(){

	drive(BACKWARDS);
	wait1Msec(1200);
	clawclose(127);
	wait1Msec(300);
	clawclose(0);
	liftup(127);
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
	wait1Msec(1100);
	drive(STOP);

	clawopen(100);
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
	wait1Msec(30);
	liftup(127); //lift first time
	wait1Msec(550);



	clawclose(127);
	wait1Msec(200);
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
	liftdown(20);
	drive(FORWARDS);
	wait1Msec(700);
	clawopen(90);
	wait1Msec(840);


	drive(STOP);


	clawopen(127);
	liftdown(0);
	wait1Msec(1000);
	liftup(56);

	//
	wait1Msec(400);
	drive(BACKWARDS);

	wait1Msec(1200);
	drive(STOP);
	wait1Msec(300);
	clawclose(127);
	wait1Msec(650);
	drive(STOP);
	wait1Msec(900);

	clawopen(0);
	liftdown(0);
}

void c(){
	clawopen(127);
	wait1Msec(2000);
	clawopen(0);
	clawclose(127);
	wait1Msec(2000);
	clawopen(0);
}

void leftStars(){
	liftdown(50);
	drive(FORWARDS); //drives forwards for one second
	wait1Msec(140);
	drive(STOP);

	clawopen(400);
	wait1Msec(400;
	clawopen(0);

	while(abs(SensorValue[gyro]) < 460){

	drive(TURNRIGHT);

	}
	drive(STOP);





	wait1Msec(200); //closes the claw to grab stars
	clawopen(0);

	clawopen(30); // constantly closes claw to keep them secured

	drive(FORWARDS);
	wait1Msec(1300);
	clawopen(127);
	wait1Msec(400); //Goes forward
	drive(STOP);

	clawopen(120);
	wait1Msec(700);
	liftup(0);

	drive(BACKWARDS);
	wait1Msec(1400);
	drive(STOP);



	liftup(100);
	wait1Msec(500);
	liftup(0);
	liftdown(20);
	wait1Msec(300);
	liftup(0);

	liftup(20);

	while(abs(SensorValue[gyro]) < 1300){

	drive(TURNRIGHT);

	}
	drive(STOP);
	liftup(0);

	drive(BACKWARDS);
	wait1Msec(800);
	liftup(127); //lift first time
	wait1Msec(452);

	clawclose(127);
	wait1Msec(300);
	wait1Msec(200);
	drive(STOP);
	liftup(0);
	liftdown(127);
	wait1Msec(1000);
	liftdown(0);
	drive(FORWARDS);
	wait1Msec(600);
	drive(STOP);
	drive(TURNLEFT);
	wait1Msec(400);
	drive(STOP);

	drive(FORWARDS);
	wait1Msec(600);
	drive(STOP);
	clawopen(127);
	wait1Msec(1500);

	drive(TURNRIGHT);
	wait1Msec(350);
	drive(STOP);


	drive(BACKWARDS);
	wait1Msec(500);
	liftup(127); //lift first time
	wait1Msec(452);

	clawclose(127);
	wait1Msec(300);
	wait1Msec(200);
	drive(STOP);
	liftdown(127);
	wait1Msec(500);

	drive(BACKWARDS);
	wait1Msec(800);
	liftup(127); //lift first time
	wait1Msec(452);

	clawclose(127);
	wait1Msec(300);
	wait1Msec(200);
	drive(STOP);
	liftup(0);
	liftdown(127);





}

void boxStars(){
	liftdown(50);
	drive(FORWARDS); //drives forwards for one second
	wait1Msec(850);
	drive(20);

	clawopen(127);
	wait1Msec(1000); //Goes forward

	liftup(30);
	wait1Msec(300);

	while(abs(SensorValue[gyro]) < 270){

		drive(TURNRIGHT);

	}
	wait1Msec(400);

	drive(BACKWARDS);
	wait1Msec(800);
	drive(STOP);
	while(SensorValue[armPo] < OPENHEIGHT){
		liftup(127); //lift first time
	}


	clawclose(127);
	wait1Msec(300);
	wait1Msec(200);
	drive(STOP);
	liftup(0);


	liftdown(127);
	wait1Msec(1000);
	liftdown(30);

	clawopen(40);
	drive(FORWARDS);
	wait1Msec(1100);
	clawopen(127);
	drive(STOP);
	wait1Msec(1500);
	clawopen(60);

	drive(BACKWARDS);
	wait1Msec(1200);
	drive(STOP);
	while(SensorValue[armPo] < OPENHEIGHT){
		liftup(127); //lift first time
	}


	clawclose(127);
	wait1Msec(300);
	drive(STOP);
	wait1Msec(200);
	liftup(0);





}

void forwardstar(){
		drive(BACKWARDS);
		wait1Msec(700);
		clawopen(127);
		wait1Msec(300);
		clawclose(0);
		while(SensorValue[armPo] < OPENHEIGHT){
			liftup(127);
		}
		drive(STOP);
		clawopen(127);
		wait1Msec(200);
		clawopen(0);


}


task autonomous()
{
	slaveMotor(LA, RA);
	slaveMotor(LC, RC);

	slaveMotor(BR, FR);
	slaveMotor(BL, FL);
	//slaveMotor(LeftClaw, RightClaw);

	boxstars();


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
	slaveMotor(LA, RA);
	slaveMotor(LC, RC);

	slaveMotor(BR, FR);
	slaveMotor(BL, FL);

	int triggered = 0;

	while(true){
		motor[FR]  = -vexRT[Ch1] + vexRT[Ch3];
		motor[FL] = vexRT[Ch1] + vexRT[Ch3];
		//wait1Msec(1);




		if(vexRT[Btn5U] == 1 && vexRT[Btn5D] == 0 && triggered == 0)
		{
			motor[RA] = 100;
		}
		else if(vexRT[Btn5D] == 1 && vexRT[Btn5U] == 0 && triggered == 0)
		{
			motor[RA] = -100;
		}
		else if(triggered == 0)
		{
			motor[RA] = -10;
		}

		if(vexRT[Btn6U] == 1 && vexRT[Btn6D] == 0)
		{
			motor[RC] = 80;
		}
		else if(vexRT[Btn6D] == 1 && vexRT[Btn6U] == 0)
		{
			motor[RC] = -80;
		}
		else
		{
			motor[RC] = 0;
		}

		if(((vexRT[Btn7D] || vexRT[Btn8D]) && SensorValue[armPo] < OPENHEIGHT-700)|| triggered == 1)
		{
			triggered = 1;
			motor[RA] = 127;
			if(SensorValue[armPo] < OPENHEIGHT - 850){
				motor[RC] = 60;
		}
			if(SensorValue[armPo] >= OPENHEIGHT - 850)
			{
				motor[RC] = -127;
			}
			if(SensorValue[armPo] >= OPENHEIGHT){
				motor[RA] = 0;
				motor[RC] = 0;
				triggered = 0;
			}
		}

	}

}
