#include "MoveUntilWall.h"

MoveUntilWall::MoveUntilWall(double stoppingDistance) {
	distanceToTravel = stoppingDistance;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveUntilWall::Initialize() {
	Requires(driveTrain);
}

// Called repeatedly when this Command is scheduled to run
void MoveUntilWall::Execute() {
	CommandBase::driveTrain->MotorSpeed(0.4);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUntilWall::IsFinished() {
	if(CommandBase::driveTrain->getUltra() > distanceToTravel) {
			return false;
		}
		else {
			return true;
		}
}

// Called once after isFinished returns true
void MoveUntilWall::End() {
	CommandBase::driveTrain->MotorSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveUntilWall::Interrupted() {

}
