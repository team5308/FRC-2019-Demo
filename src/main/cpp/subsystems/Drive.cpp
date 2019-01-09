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

std::shared_ptr<rev::CANSparkMax> Drive::sparkMax1;
std::shared_ptr<rev::CANSparkMax> Drive::sparkMax2;
std::shared_ptr<rev::CANSparkMax> Drive::sparkMax3;

std::shared_ptr<rev::CANSparkMax> Drive::sparkMax4;
std::shared_ptr<rev::CANSparkMax> Drive::sparkMax5;
std::shared_ptr<rev::CANSparkMax> Drive::sparkMax6;

std::shared_ptr<frc::SpeedControllerGroup> Drive::leftGroup;
std::shared_ptr<frc::SpeedControllerGroup> Drive::rightGroup;

void Drive::init()
{
  sparkMax1.reset(new rev::CANSparkMax(1));
  sparkMax2.reset(new rev::CANSparkMax(2));
  sparkMax3.reset(new rev::CANSparkMax(3));
  
  sparkMax4.reset(new rev::CANSparkMax(4));
  sparkMax5.reset(new rev::CANSparkMax(5));
  sparkMax6.reset(new rev::CANSparkMax(6));

  leftGroup  = std::make_shared<frc::SpeedControllerGroup>(*sparkMax1, *sparkMax2, *sparkMax3);

  rightGroup = std::make_shared<frc::SpeedControllerGroup>(*sparkMax4, *sparkMax5, *sparkMax6);


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
  
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
