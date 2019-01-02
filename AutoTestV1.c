#pragma config(Sensor, in1,    lineTrackFront, sensorLineFollower)
#pragma config(Sensor, in2,    lineTrackBack,  sensorLineFollower)
#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightWheel,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           middleWheel,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftWheel,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           turbine1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           turbine2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           turbine3,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ballShootLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ballShootRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rampAdjust,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define FULLPWR 127
#define HALFPWR 63
#define QTRPWR 32

//create functions up here

//begins ball shooting sequence. MUST INCLUDE TIMING IN MAIN METHOD (or code into the ballShoot later)
void ballShoot()
{
	//turns turbines in the intake direction
	motor[turbine1] = -FULLPWR;
	motor[turbine2] = -FULLPWR; //the motor is already flipped on the bot
	motor[turbine3] = FULLPWR;

	//shoots balls
	//TEST IF THIS IS IN THE RIGHT DIRECTION OR NOT
	motor[ballShootLeft] = FULLPWR;
  motor[ballShootRight] = FULLPWR;
}

//begins cap flipping sequence when called NO TIMING NECESSARY
void capFlip()
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



task main()
{

}
