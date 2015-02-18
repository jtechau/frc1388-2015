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
#define JOYSTICK_SCALING 3000
#define ELEVATOR_CONSTANT_FORCE 0.01
#define ELEVATOR_PULSES_PER_INCH ((float) (512) * (32/14) * 1.12)

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
	RobotMap::elevatorElevatorTalon->SetControlMode(CANTalon::kPosition);
}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute() {
	//This first part is basically an event listener for the POV (D-Pad) of the controller

	signed int pov = Robot::oi->getopStick()->GetPOV();
	double currentPosition = (RobotMap::elevatorElevatorTalon->GetPosition());
	float setpoint = 0;
	switch(pov){
	case 0: // Toe dough edge detection
		setpoint = currentPosition + STEP_OFFSET * ELEVATOR_PULSES_PER_INCH;
		RobotMap::elevatorElevatorTalon->Set(setpoint);
		break;
	case 180:
		setpoint = currentPosition + PLATFORM_SETDOWN * ELEVATOR_PULSES_PER_INCH;
		RobotMap::elevatorElevatorTalon->Set(setpoint);
		break;
	case 270:
		if (m_povPrevState == 270)
			break;

//		printf("isPositionControl: %d\n", isPositionControl);
		isPositionControl = !isPositionControl;
		if(isPositionControl){
			Robot::elevator->elevatorTalon->SetControlMode(CANSpeedController::kPosition);
			Robot::elevator->elevatorTalon->ClearIaccum();
		}else{
			Robot::elevator->elevatorTalon->SetControlMode(CANSpeedController::kPercentVbus);
		}
	}

	m_povPrevState = pov;

	//This part is for actually moving the elevator manually with a joystick

	float joystickZ = Robot::oi->getOpStickZ();
	float scaledJoystickZ = (joystickZ * JOYSTICK_SCALING);

	static bool bStop = false;

	if(isPositionControl){
		setpoint = currentPosition + scaledJoystickZ;
		if (scaledJoystickZ != 0){ // prevents drifting
			bStop = true;
			RobotMap::elevatorElevatorTalon->Set(setpoint);
			printf("Setpoint: %f, %f, %f\n", setpoint, currentPosition, scaledJoystickZ);
		}else{
			if(bStop){
				RobotMap::elevatorElevatorTalon->Set(currentPosition);
				RobotMap::elevatorElevatorTalon->ClearIaccum();
				bStop = false;
			}
		}
	}else{

		if(joystickZ <= 0.0){
			RobotMap::elevatorElevatorTalon->Set((joystickZ + ELEVATOR_CONSTANT_FORCE));
		}else{

			RobotMap::elevatorElevatorTalon->Set(joystickZ);
		}
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
