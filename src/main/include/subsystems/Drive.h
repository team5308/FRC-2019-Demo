/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Li                                                          */
/* Date: 2019/01/08                                                           */
/* Filename: DriveSubSystem.h                                                 */
/* Project: FRC-2019-Demo                                                     */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/commands/Subsystem.h"
#include  "ytz_5308.h"
#include "rev/CANSparkMax.h"

class Drive : public frc::Subsystem {
 public:

 static void init();

 static bool isExcute;

 static std::shared_ptr<rev::CANSparkMax> sparkMax1;
 static std::shared_ptr<rev::CANSparkMax> sparkMax2;
 static std::shared_ptr<rev::CANSparkMax> sparkMax3;

 static std::shared_ptr<rev::CANSparkMax> sparkMax4;
 static std::shared_ptr<rev::CANSparkMax> sparkMax5;
 static std::shared_ptr<rev::CANSparkMax> sparkMax6;

 static std::shared_ptr<frc::SpeedControllerGroup> leftGroup;
 static std::shared_ptr<frc::SpeedControllerGroup> rightGroup;


  Drive();
  void InitDefaultCommand() override;
  void Periodic() override;

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
