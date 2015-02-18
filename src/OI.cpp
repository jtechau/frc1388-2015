// RobotBuilder Version: 1.5
//test
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
//testComment (need some change to build)
//test
#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousMove.h"
#include "Commands/AutonomousStrafe.h"
#include "Commands/AutonomousTurn.h"
#include "Commands/ControlledDrive.h"
#include "Commands/Drive.h"
#include "Commands/EnableGyro.h"
#include "Commands/GotoManuever.h"
#include "Commands/GotoSlimTote.h"
#include "Commands/GotoTote.h"
#include "Commands/GotoTrashcan.h"
#include "Commands/GrabbersToOpen.h"
#include "Commands/MoveElevator.h"
#include "Commands/MoveGrabbers.h"
#include "Commands/SetElevatorZeroPoint.h"
#include "Commands/SetSetpoint.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	opStick = new Joystick(2);
	
	grabTrashcan = new JoystickButton(opStick, 4);
	grabTrashcan->WhenPressed(new GotoTrashcan());
	grabNormalTote = new JoystickButton(opStick, 3);
	grabNormalTote->WhenPressed(new GotoTote());
	grabSlimTote = new JoystickButton(opStick, 2);
	grabSlimTote->WhenPressed(new GotoSlimTote());
	openGrabbers = new JoystickButton(opStick, 1);
	openGrabbers->WhenPressed(new GrabbersToOpen());
	driveStick = new Joystick(1);
	
	zeroElevator = new JoystickButton(driveStick, 3);
	zeroElevator->WhenPressed(new SetElevatorZeroPoint());
	gyroReset = new JoystickButton(driveStick, 2);
	gyroReset->WhenPressed(new Drive());
	controldrivebutton = new JoystickButton(driveStick, 1);
	controldrivebutton->WhileHeld(new ControlledDrive());
     

        // SmartDashboard Buttons

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	elevatorPickup = new JoystickButton(opStick, 10);
	elevatorPickup->WhenPressed(new SetSetpoint(4.5));

	stackFirstTote = new JoystickButton(opStick, 9);
	stackFirstTote->WhenPressed(new SetSetpoint(8.7513));

	elevatorLevel2 = new JoystickButton(opStick, 5);
	elevatorLevel2->WhenPressed(new SetSetpoint(20.8513));

	elevatorLevel3 = new JoystickButton(opStick, 7);
	elevatorLevel3->WhenPressed(new SetSetpoint(32.9513));

	elevatorLevel4 = new JoystickButton(opStick, 6);
	elevatorLevel4->WhenPressed(new SetSetpoint(45.0513));

	elevatorLevel5 = new JoystickButton(opStick, 8);
	elevatorLevel5->WhenPressed(new SetSetpoint(57.1513));
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getopStick() {
	return opStick;
}

Joystick* OI::getdriveStick() {
	return driveStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

float OI::getDriveStickX(){
	return (joystickDeadband(driveStick->GetX()));
}

float OI::getDriveStickY(){
	return (joystickDeadband(driveStick->GetY()));
}

float OI::getDriveStickZ(){
	return (joystickDeadband(driveStick->GetZ()));
}

float OI::getOpStickZ(){
	return (joystickDeadband(opStick->GetZ()));
}

float OI::getOpStickX(){
	return -(joystickDeadband(opStick->GetX()));
}

float OI::getOpStickY(){
	return -(joystickDeadband(opStick->GetY()));
}

float OI::joystickDeadband(float joystickReturn){
	if(joystickReturn < 0 && joystickReturn > -0.1){
		return 0.0;
	}else if(joystickReturn > 0 && joystickReturn < 0.1){
		return 0.0;
	}
	return joystickReturn;
}
