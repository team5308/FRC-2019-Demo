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

inline double dabs(double x)
{
  return x<1?1.0/x:x;
}

int Vision::dx;
int Vision::dy;

Vision::Vision() : Subsystem("Vision") {
  printf("init Vision!\n");
  cam = frc::CameraServer::GetInstance()->StartAutomaticCapture("Cam", 0);
  cam.SetResolution(640,480);
  cvSink = frc::CameraServer::GetInstance()->GetVideo();
  outputStream = frc::CameraServer::GetInstance()->PutVideo("Rectangle", 640, 480);
  testStream = frc::CameraServer::GetInstance()->PutVideo("test", 640, 480);
}

void Vision::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Vision::handleData()
{
  bool paraMode = false;
  while(true){
  if(cvSink.GrabFrame(img)!=0)
  {
   // printf("Begin Gaussian Blur\n");
    //cv::GaussianBlur(img, img, cv::Size(9,9), 0);
    printf("End Gaussian Blur\n");
    printf("Begin cvtColor\n");
    cv::cvtColor(img, hsv_img, cv::COLOR_BGR2HSV);
    printf("End cvtColor\n");
    printf("Begin inRange\n");
    cv::inRange(hsv_img, cv::Scalar(20, 60, 0), cv::Scalar(40, 255, 255),hsv_img);
    printf("End inRange\n");
    printf("Begin findContours\n");
    cv::findContours(hsv_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    printf("End findContours\n");
    dx = 0;
    for(auto& cont: contours)
    {
      cv::Rect newRect = cv::boundingRect(cont);
      if(newRect.height <= 640*0.2 || newRect.width <= 480* 0.2 || dabs(newRect.width*1.0/newRect.height)>=1.5)
      {
        continue;
      }
      int centX = newRect.x+newRect.width/2;
      int centY = newRect.y+newRect.height/2;
      dx = centX - 320;
      dy = centY - 240;

      if(!paraMode){
        cv::rectangle(img, newRect, cv::Scalar(0,0,200),2);
        cv::line(img, cv::Point(centX-5, centY), cv::Point(centX+5, centY), cv::Scalar(0,0,200), 2);
        cv::line(img, cv::Point(centX, centY-5), cv::Point(centX, centY+5), cv::Scalar(0,0,200), 2);
        printf("dx: %d, dy:%d\n",dx,dy);
      }
    }
    if(!paraMode){
    cv::line(img, cv::Point(320, 220), cv::Point(320, 260), cv::Scalar(0,200,0), 2);
    cv::line(img, cv::Point(300, 240), cv::Point(340, 240), cv::Scalar(0,200,0), 2);
    }

    outputStream.PutFrame(img);
    testStream.PutFrame(hsv_img);
    printf("Fucking Suc!\n");
  }
}
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
      cv::Rect newRect = cv::boundingRect(cont);
      if(newRect.height <= 640*0.2 || newRect.width <= 480* 0.2 || dabs(newRect.width*1.0/newRect.height)>=1.5)
      {
        continue;
      }
      cv::rectangle(img, newRect, cv::Scalar(0,0,200),2);
      cv::line(img, cv::Point(newRect.x+newRect.width/2-5, newRect.y+newRect.height/2), cv::Point(newRect.x+newRect.width/2+5, newRect.y+newRect.height/2), cv::Scalar(0,0,200), 2);
      cv::line(img, cv::Point(newRect.x+newRect.width/2, newRect.y+newRect.height/2-5), cv::Point(newRect.x+newRect.width/2, newRect.y+newRect.height/2+5), cv::Scalar(0,0,200), 2);
    }
    
    cv::line(img, cv::Point(320, 220), cv::Point(320, 260), cv::Scalar(0,200,0), 2);
    cv::line(img, cv::Point(300, 240), cv::Point(340, 240), cv::Scalar(0,200,0), 2);


    outputStream.PutFrame(img);
    printf("Fucking Suc!\n");
  }
  else
  {
    printf("Fucking Failed!]\n");
  }
  }
}

double Vision::GetDX()
{
  return dx * 1.0;
}

double Vision::GetDY()
{
  return dy * 1.0;
}