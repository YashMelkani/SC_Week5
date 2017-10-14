#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), driveMotor(new Jaguar(MOTORPORT)), ultrasonicSensor(new Ultrasonic(ULTRASONIC_TRIGGER, ULTRASONIC_ECHO)) {
	ultrasonicSensor->SetAutomaticMode(true);
	speed = 0;
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::MotorSpeed(double speed) {
	driveMotor->Set(speed);
}

double DriveTrain::getUltra() {
	return ultrasonicSensor->GetRangeInches();
}

DriveTrain::~DriveTrain(){
	delete ultrasonicSensor;
	delete driveMotor;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
