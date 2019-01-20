/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Li                                                          */
/* Date: 2019/01/08                                                           */
/* Filename: DriveSubSystem.h                                                 */
/* Project: FRC-2019-Demo                                                     */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include  "ytz_5308.h"
#include "rev/CANSparkMax.h"

class Drive : public frc::Subsystem {
 public:

 static void init();

 static bool isExcute;

 static std::shared_ptr<>;

 static std::shared_ptr<frc::SpeedControllerGroup> leftGroup;
 static std::shared_ptr<frc::SpeedControllerGroup> rightGroup;

 static std::shared_ptr<frc::Joystick> joy1;
 static std::shared_ptr<frc::Joystick> joy2;


  Drive();
  void InitDefaultCommand() override;
  void Periodic() override;

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
