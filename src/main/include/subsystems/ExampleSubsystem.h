/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

#include <frc/WPILib.h>

#include "subsystems/Vision.h"

#include "BasicPID.h"

class ExampleSubsystem : public frc::Subsystem {
 public:
  ExampleSubsystem();
  void InitDefaultCommand() override;
  void Periodic() override;
  
  static std::shared_ptr<frc::Joystick> joystick1;
  static std::shared_ptr<frc::Joystick> joystick2;

  static std::shared_ptr<WPI_TalonSRX>  TalonSRX1;
  static std::shared_ptr<WPI_VictorSPX>  VictorSPX2;
  static std::shared_ptr<frc::SpeedControllerGroup> SpeedControllerGroup1;

  static std::shared_ptr<WPI_TalonSRX>  TalonSRX3;
  static std::shared_ptr<WPI_VictorSPX>  VictorSPX4;
  static std::shared_ptr<frc::SpeedControllerGroup> SpeedControllerGroup2;

  static std::shared_ptr<frc::DifferentialDrive>  m_robotDrive;


  static std::shared_ptr<NetworkTable> limelight;
  
  static std::shared_ptr<frc::DigitalInput> magLimitSwitch;
  float tx;
  float ty;

  static std::shared_ptr<frc::JoystickButton> joyButton;

  BasicPID visionPID;
  BasicPID hatchPID;

 private:
 void hatchPIDTest();

  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
