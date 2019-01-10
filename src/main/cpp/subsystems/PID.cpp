/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Li                                                          */
/* Date: 2019/01/08                                                           */
/* Filename: PID.cpp                                                          */
/* Project: FRC-2019-Demo                                                     */
/*----------------------------------------------------------------------------*/


#include "subsystems/PID.h"

PID::PID() : Subsystem("PID") 
{

}

PID::PID(int kP, int kI, int kD) : Subsystem("PID"), kP(kP), kI(kI),kD(kD)
{

}

void PID::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void PID::enable()
{
  while(this->targetPhase < this->cPhase)
  {
    this->step();
  }
}

void PID::step()
{
  
}
