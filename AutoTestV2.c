#pragma config(Sensor, in1,    lineTrackFront, sensorLineFollower)
#pragma config(Sensor, in2,    lineTrackBack,  sensorLineFollower)
#pragma config(Sensor, dgtl1,  ultrasonicIN,   sensorSONAR_inch)
#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightWheel,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           middleWheel,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftWheel,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           turbine1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           turbine2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           turbine3,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           catapult,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ballShootRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rampAdjust,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define FULLPWR 127
#define HALFPWR 63
#define QTRPWR 32





task main()
{
	motor[leftWheel] = -FULLPWR;
	motor[rightWheel] = FULLPWR;
	wait1Msec(5000);

	motor[leftWheel] = 0;
	motor[rightWheel] = 0;

	motor[claw] = FULLPWR;
	wait1Msec(1000);

	motor[claw] = 0;
	wait1Msec(500);

	motor[claw] = -FULLPWR;
	wait1Msec(1000);


}
