// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "MoveGrabbers.h"
#include "../OI.h"
#include "math.h"

MoveGrabbers::MoveGrabbers() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::grabbers);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	isPositionControl = true;
	m_povPrevState = -1;
}

// Called just before this Command runs the first time
void MoveGrabbers::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveGrabbers::Execute() {
	signed int pov = Robot::oi->getopStick()->GetPOV();

	if (pov == 90 && m_povPrevState != 90) {
		isPositionControl = !isPositionControl;
		if(isPositionControl){
			RobotMap::grabbersGrabberCANTalon->SetControlMode(CANSpeedController::kPosition);
			RobotMap::grabbersGrabberCANTalon->EnableControl();
		}else{
			RobotMap::grabbersGrabberCANTalon->SetControlMode(CANSpeedController::kPercentVbus);
		}
	}

	m_povPrevState = pov;

	if (isPositionControl) {
		float ModifiedOpStickZ = (Robot::oi->getOpStickZ() * -10);
		RobotMap::grabbersGrabberCANTalon->Set(
			RobotMap::grabbersGrabberCANTalon->GetPosition() + ModifiedOpStickZ);
		//printf("ModifiedStick: %f\t" , ModifiedOpStickZ);
	} else {
		RobotMap::grabbersGrabberCANTalon->Set(-1 * Robot::oi->getOpStickZ());
		if(RobotMap::grabbersGrabberCANTalon->IsFwdLimitSwitchClosed()) {
					RobotMap::grabbersGrabberCANTalon->SetPosition(0);
				printf("Inside limit: %d \n"
						, RobotMap::grabbersGrabberCANTalon->IsFwdLimitSwitchClosed());
		}
//	printf("encoder value: %d \n", RobotMap::grabbersGrabberCANTalon->GetEncPosition());
//	printf("encoder setpoint: %f \n", RobotMap::grabbersGrabberCANTalon->Get());
//
//	printf("Outside closed: %d \n", RobotMap::grabbersGrabberCANTalon->IsRevLimitSwitchClosed());

	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveGrabbers::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveGrabbers::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveGrabbers::Interrupted() {

}
