#pragma config(Motor,  port1,           frontRight,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           forkLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           forkRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           xLeft,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           xRight,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int forkTime = 2000;
	int xTime = 2000;

/** lifts forklift */
if(vexRT[Btn7U] ) {
motor[forkLeft] = 65;
motor[forkRight] = -65;
wait1Msec (forkTime);

}

/** brings it down forklift */
if(vexRT[btn7R] ) {
motor[forkleft] = -65;
motor[forkRight] = 65;
wait1msec (forkTime);



}

if(vexRT[btn7L] ) {
	motor[xLeft] = -65;
	motor[xRight] = 65;
	wait1msec (xTime);
}

if(vexRT[btn7L] ) {
	motor[xLeft] = 65;
	motor[xRight] = -65;
	wait1msec (xTi




	me);
}
