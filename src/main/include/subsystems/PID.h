/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Liu                                                          */
/* Date: 2019/01/08                                                           */
/* Filename: PID.h                                                            */
/* Project: FRC-2019-Demo                                                     */
/*----------------------------------------------------------------------------*/


#pragma once

#include <vector>

#include <frc/commands/Subsystem.h>

class PID : public frc::Subsystem {

 private:
  double realDisM; // real Dis
  double R2Ph; // realDis * R2Ph = targetPhase - basePhase

  int basePhase; // Phase reader at the beginning
  int targetPhase; // Target End Phase
  int cPhase; // current distance

  std::vector<int> err;

  int kP,kI,kD;

  int idx;

 public:
  PID();
  PID(int, int, int );

  void enable();
  void step();

  void InitDefaultCommand() override;
};
