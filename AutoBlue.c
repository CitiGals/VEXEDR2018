#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightWheel,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftWheel,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rampAdjust,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           turbine1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           turbine2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           turbine3,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ballShootLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ballShootRight, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define FULLPWR 127
#define HALFPWR 63
#define QTRPWR 32





task main()
{
	//going forward
	motor[leftWheel] = -FULLPWR;
	motor[rightWheel] = FULLPWR;
	wait1Msec(3300);

	//stops to hit flag
	motor[leftWheel] = 0;
	motor[rightWheel] = 0;
	wait1Msec(1000);

	motor[claw] = FULLPWR;
	wait1Msec(500);
	motor[claw] = 0;
	wait1Msec(1);

	//backs up from flag
	motor[leftWheel] = FULLPWR;
	motor[rightWheel] = -FULLPWR;
	wait1Msec(1900);

	//turn towards cap
	motor[leftWheel] = FULLPWR;
	motor[rightWheel] = FULLPWR;
	wait1Msec(800);

	//move forward to cap
	motor[leftWheel] = -FULLPWR;
	motor[rightWheel] = FULLPWR;
	wait1Msec(1200);

	motor[leftWheel] = 0;
	motor[rightWheel] = 0;
	wait1Msec(1);

	//flip cap
	motor[claw] = -FULLPWR;
	wait1Msec(3000);

	motor[claw] = 0;
	wait1Msec(500);

}
