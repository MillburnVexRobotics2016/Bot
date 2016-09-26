#pragma config(Motor,  port2,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           forkLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           forkRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           xLeft,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           xRight,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           frontRight,    tmotorVex393_MC29, openLoop, reversed, encoderPort, None)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int forkTime = 1200;
	int xTime = 2000;
	while(true)
	{
		//processJoysticks();
		motor[frontLeft] = vexRT[Ch3];
	  motor[backLeft] = vexRT[Ch3];

	  motor[frontRight] = vexRT[Ch3];
	  motor[backRight] = vexRT[Ch3];

	  motor[frontLeft] =+ vexRT[Ch1];
	  motor[backLeft] =+ vexRT[Ch1];

	  motor[frontRight] =+ -vexRT[Ch1];
	  motor[backRight] =+ -vexRT[Ch1];

		/** lifts forklift */
		if(vexRT[Btn7U] == 1 ) {
			motor[forkLeft] = 65;
			motor[forkRight] = -65;
			motor[forkLeft] = motor[forkRight] = 0;
		}
		else if(vexRT[Btn7R] == 1) {
			motor[forkLeft] = -65;
			motor[forkRight] = 65;
			motor[forkLeft] = motor[forkRight] = 0;
		}
		else{
			motor[forkLeft] = 0;
			motor[forkRight] = 0;
		}





		if(vexRT[Btn7L] == 1) {
			motor[xLeft] = -50;
			motor[xRight] = 40;

		}
		else if(vexRT[Btn7D] == 1) {
			motor[xLeft] = 50;
			motor[xRight] = -40;

		}else{
		  motor[xLeft] = 0;
		  motor[xRight] = 0;
	  }
	}
}
