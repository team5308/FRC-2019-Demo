/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <frc/WPILib.h>

#include <vector>

class Vision : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  cs::UsbCamera cam;
  cs::CvSink cvSink;
  cs::CvSource outputStream;
  cs::CvSource testStream;
  cv::Mat img;
  cv::Mat hsv_img;
  // cv::OutputArrayOfArrays contoursArray;
  std::vector< std::vector<cv::Point> > contours;
  static int dx, dy;

  // cv::OutputArray hireArray;
 public:
  Vision();
  void InitDefaultCommand() override;
  void Periodic() override;

  void handleData();

  static double GetDX();
  static double GetDY();

  
};
