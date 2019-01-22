/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ExampleSubsystem.h"

#include "RobotMap.h"

std::shared_ptr<frc::Joystick> ExampleSubsystem::joystick1;
std::shared_ptr<frc::Joystick> ExampleSubsystem::joystick2;

std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::TalonSRX1;
std::shared_ptr<WPI_VictorSPX> ExampleSubsystem::VictorSPX2;
std::shared_ptr<frc::SpeedControllerGroup> ExampleSubsystem::SpeedControllerGroup1;

std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::TalonSRX3;
std::shared_ptr<WPI_VictorSPX> ExampleSubsystem::VictorSPX4;
std::shared_ptr<frc::SpeedControllerGroup> ExampleSubsystem::SpeedControllerGroup2;

std::shared_ptr<frc::DifferentialDrive> ExampleSubsystem::m_robotDrive;

std::shared_ptr<NetworkTable> ExampleSubsystem::limelight = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

std::shared_ptr<frc::DigitalInput> ExampleSubsystem::magLimitSwitch;

ExampleSubsystem::ExampleSubsystem() : frc::Subsystem("ExampleSubsystem") {
  joystick1.reset(new frc::Joystick(0));
  joystick2.reset(new frc::Joystick(1));

  TalonSRX1.reset(new WPI_TalonSRX(4));
  VictorSPX2.reset(new WPI_VictorSPX(3));
  //2 spx follow 2 srx mastermode
  TalonSRX3.reset(new WPI_TalonSRX(1));
  VictorSPX4.reset(new WPI_VictorSPX(2));

  SpeedControllerGroup1 = std::make_shared<frc::SpeedControllerGroup>(*TalonSRX1, *VictorSPX2);
  SpeedControllerGroup2 = std::make_shared<frc::SpeedControllerGroup>(*TalonSRX3, *VictorSPX4);

  //frc::DifferentialDrive m_robotDrive{SpeedControllerGroup1, SpeedControllerGroup2};
  m_robotDrive.reset(new frc::DifferentialDrive(*SpeedControllerGroup1, *SpeedControllerGroup2));

  magLimitSwitch.reset(new frc::DigitalInput(5));
}

void ExampleSubsystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

inline double abs(double x) 
{
  if(x<0)return -x;
  else return x;
}

double suoqu(double x)
{
  if(abs(x) <= 0.14)  return 0.0;
  else return x;
}

void ExampleSubsystem::Periodic(){
 // SpeedControllerGroup1 -> Set(-joystick1->GetY());
 // SpeedControllerGroup2 -> Set(joystick2->GetY());
 tx = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", 0.0);
 ty = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0.0);
  // printf("tx: %2.4f, ty: %2.4f\n", tx, ty);
  // //SpeedControllerGroup1 -> Set(0.01*tx); 
  // //SpeedControllerGroup2 -> Set(0.01*tx);

  // if(magLimitSwitch->Get())
  // {
  //   printf("Mag Get True!\n");
  // }



  // while(abs(tx) >= 5)
  // {
  //   SpeedControllerGroup1 -> Set(0.15); 
  //   SpeedControllerGroup2 -> Set(0.15);
  // }
  // SpeedControllerGroup2 -> Set(0.09*tx);
 // m_robotDrive -> ArcadeDrive(suoqu(joystick1->GetY()), suoqu(joystick1->GetX()));
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

