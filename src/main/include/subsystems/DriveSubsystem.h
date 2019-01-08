/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Li                                                          */
/* Date: 2019/01/08                                                           */
/* Filename: DriveSubSystem.h                                                 */
/* Project: FRC-2019-Demo                                                     */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

class DriveSubsystem : public frc::Subsystem {
 public:
  DriveSubsystem();
  void InitDefaultCommand() override;
  void Periodic() override;

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
