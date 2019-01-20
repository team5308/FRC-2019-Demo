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

std::shared_ptr<rev::CANSparkMax> Drive::sparkMax1;
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

  sparkMax1.reset(new rev::CANSparkMax(1, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  sparkMax2.reset(new rev::CANSparkMax(2, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  sparkMax3.reset(new rev::CANSparkMax(3, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  
  sparkMax4.reset(new rev::CANSparkMax(4, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  sparkMax5.reset(new rev::CANSparkMax(5, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  sparkMax6.reset(new rev::CANSparkMax(6, rev::CANSparkMaxLowLevel::MotorType::kBrushless));

  leftGroup  = std::make_shared<frc::SpeedControllerGroup>(*sparkMax1, *sparkMax2, *sparkMax3);
  rightGroup = std::make_shared<frc::SpeedControllerGroup>(*sparkMax4, *sparkMax5, *sparkMax6);

  joy1.reset(new frc::Joystick(0));
  joy2.reset(new frc::Joystick(1));
}

Drive::Drive() : frc::Subsystem("Drive") 
{
  
}

void Drive::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Drive::Periodic() 
{
  leftGroup->Set(joy1->GetX());
  rightGroup->Set(joy2->GetX());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
