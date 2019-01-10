/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Liu                                                         */
/* Date: 2019/01/10                                                           */
/* Filename: PID.cpp                                                          */
/* Project: FRC-2019-Demo                                                     */
/*----------------------------------------------------------------------------*/


#include "subsystems/PID.h"

PID::PID() : Subsystem("PID") 
{

}

PID::PID(double kP, double kI, double kD) : Subsystem("PID"), kP(kP), kI(kI),kD(kD)
{

}

void PID::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void PID::updCurPhase()
{
  // Ju Ti Shi Xian
}

void PID::enable()
{
  while(this->targetPhase < this->cPhase)
  {
    this->step();
  }
}

void PID::step()
{
  updCurPhase();
  cDelPhase = cPhase - basePhase;
  float speed = kP * cDelPhase + kI * errD;

  output(speed);

  errD += cDelPhase;
  idx++;
}


bool PID::output(double para)
{
  std::cout << "para: " << para <<"\noutput() need to be implemented.\n";
  return false;
}
