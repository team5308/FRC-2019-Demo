/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Liu                                                          */
/* Date: 2019/01/08                                                           */
/* Filename: DriveSubSystem.cpp                                               */
/* Project: FRC-2019-Demo                                                     */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drive.h"

#include "RobotMap.h"


// begin define

bool Drive::isExcute = false;

std::shared_ptr<rev::SparkMax> Drive::sparkMax1;
std::shared_ptr<rev::CANSparkMax> Drive::sparkMax2;
std::shared_ptr<rev::CANSparkMax> Drive::sparkMax3;

std::shared_ptr<rev::CANSparkMax> Drive::sparkMax4;
std::shared_ptr<rev::CANSparkMax> Drive::sparkMax5;
std::shared_ptr<rev::CANSparkMax> Drive::sparkMax6;

std::shared_ptr<frc::SpeedControllerGroup> Drive::leftGroup;
std::shared_ptr<frc::SpeedControllerGroup> Drive::rightGroup;

std::shared_ptr<frc::Joystick> Drive::joy1;
std::shared_ptr<frc::Joystick> Drive::joy2;

void Drive::init()
{
  if(isExcute)  return;
  else isExcute = true;

  sparkMax1.reset(new rev::SparkMax(0));

  
  joy1.reset(new frc::Joystick(0));
  joy2.reset(new frc::Joystick(1));
}

Drive::Drive() : frc::Subsystem("Drive") 
{
  Drive::init();
}

void Drive::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Drive::Periodic() 
{

  double l = joy1->GetY();
  printf("%f\n",l);
  sparkMax1 -> Set(l);
  // leftGroup->Set(joy1.GetX());
  // rightGroup->Set(joy2.GetX());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
