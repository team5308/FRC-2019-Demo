/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ExampleSubsystem.h"

#include "RobotMap.h"

std::shared_ptr<frc::Joystick> ExampleSubsystem::joystick1;

std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::TalonSRX1;
std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::TalonSRX2;
std::shared_ptr<frc::SpeedControllerGroup> ExampleSubsystem::SpeedControllerGroup1;

std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::TalonSRX3;
std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::TalonSRX4;
std::shared_ptr<frc::SpeedControllerGroup> ExampleSubsystem::SpeedControllerGroup2;

std::shared_ptr<frc::DifferentialDrive> ExampleSubsystem::m_robotDrive;

ExampleSubsystem::ExampleSubsystem() : frc::Subsystem("ExampleSubsystem") {
  joystick1.reset(new frc::Joystick(0));

  TalonSRX1.reset(new WPI_TalonSRX(0));
  TalonSRX2.reset(new WPI_TalonSRX(1));
  //2 spx follow 2 srx mastermode
  TalonSRX3.reset(new WPI_TalonSRX(2));
  TalonSRX4.reset(new WPI_TalonSRX(3));

  SpeedControllerGroup1 = std::make_shared<frc::SpeedControllerGroup>(*TalonSRX1, *TalonSRX2);
  SpeedControllerGroup2 = std::make_shared<frc::SpeedControllerGroup>(*TalonSRX3, *TalonSRX4);

  //frc::DifferentialDrive m_robotDrive{SpeedControllerGroup1, SpeedControllerGroup2};
  m_robotDrive.reset(new frc::DifferentialDrive(*SpeedControllerGroup1, *SpeedControllerGroup2));

}

void ExampleSubsystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void ExampleSubsystem::Periodic(){
  m_robotDrive -> ArcadeDrive(-joystick1->GetX(), joystick1->GetX());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

