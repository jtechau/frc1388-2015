// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::elevatorElevatorTalon = NULL;
Encoder* RobotMap::elevatorElevatorEncoder = NULL;
DigitalInput* RobotMap::elevatorElevatorTopLimit = NULL;
DigitalInput* RobotMap::elevatorElevatorBottomLimit = NULL;
SpeedController* RobotMap::driveTrainLeftfronttalon = NULL;
SpeedController* RobotMap::driveTrainRightfronttalon = NULL;
SpeedController* RobotMap::driveTrainLeftbacktalon = NULL;
SpeedController* RobotMap::driveTrainRightbacktalon = NULL;
RobotDrive* RobotMap::driveTrainRobotDrive41 = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	elevatorElevatorTalon = new Talon(6);
	lw->AddActuator("Elevator", "ElevatorTalon", (Talon*) elevatorElevatorTalon);
	
	elevatorElevatorEncoder = new Encoder(0, 1, false, Encoder::k4X);
	lw->AddSensor("Elevator", "ElevatorEncoder", elevatorElevatorEncoder);
	elevatorElevatorEncoder->SetDistancePerPulse(1.0);
        elevatorElevatorEncoder->SetPIDSourceParameter(Encoder::kRate);
	elevatorElevatorTopLimit = new DigitalInput(2);
	lw->AddSensor("Elevator", "ElevatorTopLimit", elevatorElevatorTopLimit);
	
	elevatorElevatorBottomLimit = new DigitalInput(3);
	lw->AddSensor("Elevator", "ElevatorBottomLimit", elevatorElevatorBottomLimit);
	
	driveTrainLeftfronttalon = new Talon(3);
	lw->AddActuator("DriveTrain", "Leftfronttalon", (Talon*) driveTrainLeftfronttalon);
	
	driveTrainRightfronttalon = new Talon(2);
	lw->AddActuator("DriveTrain", "Rightfronttalon", (Talon*) driveTrainRightfronttalon);
	
	driveTrainLeftbacktalon = new Talon(1);
	lw->AddActuator("DriveTrain", "Leftbacktalon ", (Talon*) driveTrainLeftbacktalon);
	
	driveTrainRightbacktalon = new Talon(0);
	lw->AddActuator("DriveTrain", "Rightbacktalon ", (Talon*) driveTrainRightbacktalon);
	
	driveTrainRobotDrive41 = new RobotDrive(driveTrainLeftfronttalon, driveTrainLeftbacktalon,
              driveTrainRightfronttalon, driveTrainRightbacktalon);
	
	driveTrainRobotDrive41->SetSafetyEnabled(true);
        driveTrainRobotDrive41->SetExpiration(0.1);
        driveTrainRobotDrive41->SetSensitivity(0.5);
        driveTrainRobotDrive41->SetMaxOutput(1.0);

        driveTrainRobotDrive41->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
