#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightWheel,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           middleWheel,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftWheel,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           turbine1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           turbine2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           turbine3,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ballShootLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ballShootRight, tmotorVex393_MC29, openLoop)
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

#define CHONE vexRT[Ch1] //channels are on the controller
#define CHTWO vexRT[Ch2]
#define CHTHREE vexRT[Ch3]
#define CHFOUR vexRT[Ch4]

#define FULLPWR 127
#define HALFPWR 63
#define QTRPWR 32








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

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    //motor power levels range from -127 (full reverse) to 0 (stopped) to 127 (full power)

    //int rightPwr = CHTWO * .54;
    //sets each of the wheel/chassis motors to a channel on the joystick
		motor[leftWheel] =  -CHTWO;
		motor[rightWheel] =  CHTWO;
		//straifing
		motor[middleWheel] = CHFOUR;

		//turning
		if (vexRT[Btn7L] == 1)
		{
			motor[leftWheel] = FULLPWR;
		//motor[rightWheel] = CHTHREE;
		}
		else if (vexRT[Btn7D] == 1)
		{
			motor[leftWheel] = -FULLPWR;
		}



		//turbine/intake control
		if (vexRT[Btn8D] == 1)
		{
			//turn turbines in the forward direction to intake balls
			motor[turbine1] = -FULLPWR;
			motor[turbine2] = FULLPWR; //the motor is already flipped on the bot
			motor[turbine3] = -FULLPWR;
		}
		else if (vexRT[Btn8L] == 1)
	  {
	  	//turn turbines in the opposite direction to spit any balls out
		 motor[turbine1] = FULLPWR;
		 motor[turbine2] = -FULLPWR; //the motor is already flipped on the bot
		 motor[turbine3] = FULLPWR;
  	}
		else
		{
			motor [turbine1] = 0;
			motor [turbine2] = 0;
			motor [turbine3] = 0;
  	}


  	//ball shooter control
  	if( vexRT[Btn5U] == 1 || vexRT[Btn6U] == 1)
    {
    	motor[ballShootLeft] = FULLPWR;
    	motor[ballShootRight] = FULLPWR;
    }
    else if ( vexRT[Btn5D] == 1 || vexRT[Btn6D] == 1)
    {
    	motor[ballShootLeft] = -FULLPWR;
    	motor[ballShootRight] = -FULLPWR;
  	}
  	else
  	{
  		motor[ballShootLeft] = 0;
  		motor[ballShootRight] = 0;
  	}



  	//claw control
  	if ( vexRT[Btn7U] == 1)
  	{
  		//go backward
  		resetTimer(T1);
  		while (time1[T1] < 375) //for 3/4 of half a second
  		{
  			motor[leftWheel] = FULLPWR;
  			motor[rightWheel] = -FULLPWR;
  		}

  		//use claw to flip
  		resetTimer(T1);
  		while (time1[T1] < 500) //for half a second
  		{
  			motor[claw] = -FULLPWR;
  		}

  	}
  	else if (vexRT[Btn7R] == 1)
  	{
  		motor[claw] = FULLPWR;
  	}
  	else
  	{
  		motor[claw] = 0;
  	}




  }
}
