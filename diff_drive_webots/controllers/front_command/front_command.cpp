#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;
#define TIME_STEP 64
#define MAX_SPEED 6.28

int main(int argc, char **argv)
{

  Robot *robot = new Robot();

  Motor *leftMotor = robot->getMotor("left wheel motor");
  Motor *rightMotor = robot->getMotor("right wheel motor");

  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);

  leftMotor->setVelocity(0.1 * MAX_SPEED);
  rightMotor->setVelocity(0.1 * MAX_SPEED);

  while (robot->step(TIME_STEP) != -1);
  delete robot;
  return 0;
}
