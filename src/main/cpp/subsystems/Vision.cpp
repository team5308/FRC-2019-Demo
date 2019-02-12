/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Liu                                                          */
/* Date: 2019/01/23                                                           */
/* Filename: Vision.cpp                                               */
/* Project: FRC-2019-Demo                                                     */
/*----------------------------------------------------------------------------*/

#include "subsystems/Vision.h"

void print(cv::Point p)
{
  printf("x:%d y:%d ",p.x, p.y);
}

Vision::Vision() : Subsystem("ExampleSubsystem") {
  printf("init Vision!\n");
  cam = frc::CameraServer::GetInstance()->StartAutomaticCapture("Cam", 0);
  cam.SetResolution(640,480);
  cvSink = frc::CameraServer::GetInstance()->GetVideo();
  outputStream = frc::CameraServer::GetInstance()->PutVideo("Rectangle", 640, 480);

}

void Vision::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Vision::Periodic()
{
  if(false){
  if(cvSink.GrabFrame(img)!=0)
  {
    cv::GaussianBlur(img, img, cv::Size(9,9), 0);
    cv::cvtColor(img, hsv_img, cv::COLOR_BGR2HSV);
    cv::inRange(hsv_img, cv::Scalar(20, 60, 0), cv::Scalar(40, 255, 255),hsv_img);
    cv::findContours(hsv_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    
    for(auto& cont: contours)
    {
      
    }


    outputStream.PutFrame(hsv_img);
  }
    printf("Fucking Suc!\n");
  }
  else
  {
    printf("Fucking Failed!]\n");
  }
}