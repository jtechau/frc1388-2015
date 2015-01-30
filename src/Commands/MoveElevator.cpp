// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "MoveElevator.h"

MoveElevator::MoveElevator() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void MoveElevator::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute() {
	float joystickY = Robot::oi->getOpStickY();
//todo: move this code into the elevator subsystem and change the reset command so if the elevator stops in the middle because of an autonomous code mistake the elevator will still be able to zero itself.
	if(joystickY < 0 && RobotMap::elevatorElevatorBottomLimit->Get()){
		RobotMap::elevatorElevatorTalon->Set(0.0);
	}else if(joystickY > 0 && RobotMap::elevatorElevatorTopLimit->Get()){
		RobotMap::elevatorElevatorTalon->Set(0.0);
	}else{
		RobotMap::elevatorElevatorTalon->Set(joystickY);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveElevator::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted() {

}
