#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>
#include <webots/Keyboard.hpp>
#include <webots/GPS.hpp>
#include <webots/InertialUnit.hpp>

#define TIME_STEP 64
using namespace webots;

int main(int argc, char const *argv[])
{
  Robot *robot = new Robot();
  Keyboard kb;
  DistanceSensor *ds[2];
  char dsNames[2][50] = {"diff_drive_laser_scanner_right", "diff_drive_laser_scanner_left"};

  for (int i = 0; i < 2; i++)
  {
    ds[i] = robot->getDistanceSensor(dsNames[i]);
    ds[i]->enable(TIME_STEP);
  }

  GPS *gp = robot->getGPS("diff_drive_gps");
  gp->enable(TIME_STEP);

  InertialUnit *iu;
  iu = robot->getInertialUnit("diff_drive_imu");
  iu->enable(TIME_STEP);

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

  kb.enable(TIME_STEP);
  double leftSpeed = 0.0;
  double rightSpeed = 0.0;

  while (robot->step(TIME_STEP) != -1)
  {
    int key = kb.getKey();

    if (key == 315)
    {
      leftSpeed = 1.0;
      rightSpeed = 1.0;
    }
    else if (key == 317)
    {
      leftSpeed = -1.0;
      rightSpeed = -1.0;
    }
    else if (key == 316)
    {
      leftSpeed = 1.0;
      rightSpeed = -1.0;
    }
    else if (key == 314)
    {
      leftSpeed = -1.0;
      rightSpeed = 1.0;
    }
    else
    {
      leftSpeed = 0;
      rightSpeed = 0;
    }

    std::cout << "*************************" << std::endl;

    std::cout << ds[0]->getValue() << "=Right Sensor" << std::endl;
    std::cout << ds[1]->getValue() << "=Left Sensor" << std::endl;

    std::cout << "X: " << gp->getValues()[0] << std::endl;
    std::cout << "Y: " << gp->getValues()[1] << std::endl;
    std::cout << "Z: " << gp->getValues()[2] << std::endl;

    std::cout << "Angle X: " << iu ->getRollPitchYaw()[0] << std::endl;
    std::cout << "Angle Y: " << iu ->getRollPitchYaw()[1] << std::endl;
    std::cout << "Angle Z: " << iu ->getRollPitchYaw()[2] << std::endl;

    std::cout << "*************************" << std::endl;
    wheels[0]->setVelocity(leftSpeed);
    wheels[1]->setVelocity(rightSpeed);
    wheels[2]->setVelocity(leftSpeed);
    wheels[3]->setVelocity(rightSpeed);
  }

  delete robot;
  return 0;
}
