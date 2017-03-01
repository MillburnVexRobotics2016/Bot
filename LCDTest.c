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

int Program = 1;

#define LEFTBTN 1
#define CENTERBTN 2
#define RIGHTBTN 3

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

  int minScreen = 1;

  int currScreen = 1;

  int maxScreens = 3;

  bLCDBacklight = true;

  while(vrDisabled)
  {
  	//Changes screen left
  	if(nLCDButtons == LEFTBTN)
  	{
  		if(currScreen == minScreen)
  		{
  			currScreen = maxScreens;
  			wait1Msec(250);
  		}
  		else
  		{
  			currScreen --;
  			wait1Msec(250);
  		}
  	}
  	//changes screen right
  	else if(nLCDButtons == RIGHTBTN)
  	{
  		if(currScreen == maxScreens)
  		{
  			currScreen = minScreen;
  			wait1Msec(250);
  		}
  		else
  		{
  			currScreen ++;
  			wait1Msec(250);
  		}
  	}

  	//displays an autonomous code on the screen, showing its name, number, and whether its selected or not( [1] = selected)
  	//screen #1
  	if(currScreen == 1 && Program == 1)
  	{
  		displayLCDCenteredString(0, "Right Side");
  		displayLCDCenteredString(1, "[1]");
  	}
  	else if(currScreen == 1 && Program != 1)
  	{
  		displayLCDCenteredString(0, "Right Side");
  		displayLCDCenteredString(1, "1");
  		//selection code
  		if(nLCDButtons == CENTERBTN)
  		{
  			Program = currScreen;
  			displayLCDCenteredString(0, "Auton #");
  			displayNextLCDNumber(currScreen);
  			displayLCDCenteredString(1, "selected");
  			wait1Msec(1000);
  		}
  	}
  	//Screen #2
  	else if(currScreen == 2 && Program == 2)
  	{
  		displayLCDCenteredString(0, "Left Side");
  		displayLCDCenteredString(1, "[2]");
  	}
  	else if(currScreen == 2 && Program != 2)
  	{
  		displayLCDCenteredString(0, "Left Side");
  		displayLCDCenteredString(1, "2");
  		if(nLCDButtons == CENTERBTN)
  		{
  			Program = currScreen;
  			displayLCDCenteredString(0, "Auton # ");
  			displayNextLCDNumber(currScreen);
  			displayLCDCenteredString(1, "selected");
  			wait1Msec(1000);
  		}
  	}
  	//screen #3
  	else if(currScreen == 3 && Program == 3)
  	{
  		displayLCDCenteredString(0, "Straight Auton");
  		displayLCDCenteredString(1, "[3]");
  	}
  	else if(currScreen == 3 && Program != 3)
  	{
  		displayLCDCenteredString(0, "Straight Auton");
  		displayLCDCenteredString(1, "3");
  		if(nLCDButtons == CENTERBTN)
  		{
  			Program = currScreen;
  			displayLCDCenteredString(0, "Auton # ");
  			displayNextLCDNumber(currScreen);
  			displayLCDCenteredString(1, "selected");
  			wait1Msec(1000);
  		}
  	}
}


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
  if(Program == 1)
  {
  	//do right side autonomous
	}
	else if(Program == 2)
	{
		//do left side autonomous
	}
	else if(Program == 3)
	{
		//do straight autonomous
	}
  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
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

  while (true)
  {

  	clearLCDLine(0);
  	clearLCDLine(1);

  	displayLCDString(0, 0, "Primary: ");


  }
}
