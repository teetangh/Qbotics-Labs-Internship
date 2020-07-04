#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>
#define TIME_STEP 64
using namespace webots;

int main(int argc, char **argv)
{
  Robot *robot = new Robot();

  DistanceSensor *ds[2];
  char dsNames[2][50] = {"diff_drive_laser_scanner_right", "diff_drive_laser_scanner_left"};
  for (int i = 0; i < 2; i++)
  {
    ds[i] = robot->getDistanceSensor(dsNames[i]);
    ds[i]->enable(TIME_STEP);
  }

  Motor *wheels[4];
  char wheels_names[4][50] = {
      "diff_drive_wheel1_device",
      "diff_drive_wheel2_device",
      "diff_drive_wheel3_device",
      "diff_drive_wheel4_device",
  };

  for (int i = 0; i < 4; i++)
  {
    wheels[i] = robot->getMotor(wheels_names[i]);
    wheels[i]->setPosition(INFINITY);
    wheels[i]->setVelocity(0.0);
  }

  int avoidObstacleCounter = 0;

  while (robot->step(TIME_STEP) != -1)
  {
    double leftSpeed = 1.0;
    double rightSpeed = 1.0;
    if (avoidObstacleCounter > 0)
    {
      avoidObstacleCounter--;
      leftSpeed = 1.0;
      rightSpeed = -1.0;
    }
    else
    {
      for (int i = 0; i < 2; i++)
      {
        if (ds[i]->getValue() < 950)
          avoidObstacleCounter = 100;
      }
    }

    wheels[0]->setVelocity(leftSpeed);
    wheels[1]->setVelocity(rightSpeed);
    wheels[2]->setVelocity(leftSpeed);
    wheels[3]->setVelocity(rightSpeed);
  };
  delete robot;
  return 0;
}
