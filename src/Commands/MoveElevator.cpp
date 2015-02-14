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
#define STEP_OFFSET 4.1987
#define PLATFORM_SETDOWN -2.2
#define JOYSTICK_SCALING 0.4

MoveElevator::MoveElevator() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void MoveElevator::Initialize() {
	isPositionControl = true;
	m_povPrevState = 42069; //Scott picked this "magic" number
}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute() {
	//This first part is basically an event listener for the POV (D-Pad) of the controller

	signed int pov = Robot::oi->getopStick()->GetPOV();
	float currentPosition = RobotMap::elevatorElevatorTalon->GetEncPosition();
	switch(pov){
	case 0: // Toe dough edge detection
		RobotMap::elevatorElevatorTalon->Set((currentPosition + STEP_OFFSET));
		break;
	case 180:
		RobotMap::elevatorElevatorTalon->Set((currentPosition + PLATFORM_SETDOWN));
		break;
	case 270:
		if (m_povPrevState == 270)
			break;
		printf("isPositionControl: %d\n", isPositionControl);
		isPositionControl = !isPositionControl;
		if(isPositionControl){
			Robot::elevator->elevatorTalon->SetControlMode(CANSpeedController::kPosition);
		}else{
			Robot::elevator->elevatorTalon->SetControlMode(CANSpeedController::kPercentVbus);
		}
	}

	m_povPrevState = pov;

	//This part is for actually moving the elevator manually with a joystick

	float joystickY = Robot::oi->getOpStickY();
	float scaledJoystickY = (joystickY * JOYSTICK_SCALING);
	printf("pov: %d joystickY: %f\n", pov, joystickY);

	if(isPositionControl){
		if(joystickY != 0)
			RobotMap::elevatorElevatorTalon->Set((currentPosition + scaledJoystickY));
	}else{
		RobotMap::elevatorElevatorTalon->Set((joystickY));
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
