// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "../OI.h"
#include "ControlledDrive.h"

ControlledDrive::ControlledDrive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ControlledDrive::Initialize() {
	float joystickX = Robot::oi->getDriveStickX();
	float joystickY = Robot::oi->getDriveStickY();
	float joystickZ = Robot::oi->getDriveStickZ();
	if ( joystickY > 0)
	{
		if(Robot::driveTrain->driveencoder->GetRate() == 0)
			{
				Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0, 0.5, 0, 0);
			}
	}
	if ( joystickY < 0)
	{
		if (Robot::driveTrain->driveencoder->GetRate() == 0)
			{
				Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian( 0, -0.5, 0, 0);
			}
	}
	if ( joystickX > 0)
	{
		if(Robot::driveTrain->driveencoder->GetRate() == 0)
			{
				Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0.5, 0, 0, 0);
			}
	}
	if ( joystickX < 0)
	{
		if(Robot::driveTrain->driveencoder->GetRate() == 0)
			{
				Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(-0.5, 0, 0, 0);
			}
	}
	if(Robot::driveTrain->driveencoder->GetRate() > 0 or Robot::driveTrain->driveencoder->GetRate() < 0)
	{
		Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(joystickX, joystickY, joystickZ, 0);
	}
}

// Called repeatedly when this Command is scheduled to run
void ControlledDrive::Execute() {
	float joystickX = Robot::oi->getDriveStickX();
	float joystickY = Robot::oi->getDriveStickY();
	float joystickZ = Robot::oi->getDriveStickZ();
		if ( joystickY > 0)
		{
			if(Robot::driveTrain->driveencoder->GetRate() == 0)
				{
					Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0, 0.5, 0, 0);
				}
		}
		if ( joystickY < 0)
		{
			if (Robot::driveTrain->driveencoder->GetRate() == 0)
				{
					Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian( 0, -0.5, 0, 0);
				}
		}
		if ( joystickX > 0)
		{
			if(Robot::driveTrain->driveencoder->GetRate() == 0)
				{
					Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0.5, 0, 0, 0);
				}
		}
		if ( joystickX < 0)
		{
			if(Robot::driveTrain->driveencoder->GetRate() == 0)
				{
					Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(-0.5, 0, 0, 0);
				}
		}
		if(Robot::driveTrain->driveencoder->GetRate() > 0 or Robot::driveTrain->driveencoder->GetRate() < 0)
		{
			Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(joystickX, joystickY, joystickZ, 0);
		}
	}

// Make this return true when this Command no longer needs to run execute()
bool ControlledDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlledDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlledDrive::Interrupted() {

}
