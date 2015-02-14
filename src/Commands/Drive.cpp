// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drive.h"
#include "ITG3200.h"

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_desiredAngle = 0;
}

// Called just before this Command runs the first time
void Drive::Initialize() {
//	m_desiredAngle = RobotMap::driveTrainGyro->GetAngleZ();
}

// Called repeatedly when this Command is scheduled to run
void
Drive::Execute() {
	float joystickX		 	= Robot::oi->getDriveStickX();
	float joystickY		 	= Robot::oi->getDriveStickY();
	float joystickZ		 	= Robot::oi->getDriveStickZ();
	float joystickAngle	 	= RobotMap::driveTrainGyro->GetAngleZ();
	float currentError   	= 0;
	float rotSpeed		 = 0;

	if (joystickZ != 0)
		{
			rotSpeed = joystickZ;
			m_rotationState = 1;
		}
	else if(m_rotationState && RobotMap::driveTrainGyro->GetRateZ() < 20) //TODO: define "20" so it is not a magic number. We might want to use a different number as well
		{
			m_desiredAngle = RobotMap::driveTrainGyro->GetNormalizedAngleZ();
			m_rotationState = 0;
		}
	if (joystickAngle > m_desiredAngle)
		{
			Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0, 0, -0.5, joystickAngle);
		}
	if (joystickAngle < m_desiredAngle)
		{
			Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0, 0, 0.5, joystickAngle);
		}
	if(joystickAngle == m_desiredAngle)
	{
		Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(joystickX, joystickY, joystickZ, joystickAngle);
		if(Robot::oi->getdriveStick()->GetRawButton(2) == true)
		{
			RobotMap::driveTrainGyro->Reset();
		}
	}
}


// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
