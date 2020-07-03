# Documentation

In this section of the documentation,we start by installing Webots,which is an open-source three-dimensional mobile robot simulator.

Head over to: 
    
    https://github.com/cyberbotics/webots/releases/tag/R2020a-rev1

and download the software according to your system architecture

After the installation of the Webots software youll be prompted with guide on how to the software.You can take a tour of the mavric pro demo just in case you want to get used to the software(The simulation very similar to a video game).

After you're comfortable with basic functionality of the software,create an empty project.This can be done by going to:

    Wizards -> New Project Directory

NOTE: We'll be using C++ throughout the tutorials. But the C,Python,Java and MATLAB versions are not that different

Select the Directory you would want the project files to go to followed by selecting the name of the project,in our case "diif_drive_webots".

    Remember to select Rectangular Arena in the wizard

As you can see in the STSB, you can visualize the components of your simulation.

Now lets add a more functionality to our simulation by incorporating more nodes(objects).This can be done by clicking the + sign just above the STSB.

Lets add a wooden object to the arena.This can be done by:

    Addd a node -> Proto Nodes -> objects -> factory -> containers -> WoodenBox(Solid)

Through the STSB,set the following parameters:

    translation: 0.02 0.3 -0.35
    rotation: 0 1 0 1.57
    size: 0.2 0.2 0.2
    mass: 1 (SET THIS LATER TO UNDERSTAND MASSES)

Now using Control C + Control V you can create more boxes and drag them throughout your workspace using the cursor.Place them conveniently far apart

Lets add a robot to the arena.This can be done by:

    Addd a node -> Proto Nodes -> robots -> gctronic -> e-puck -> E-puck(Robot)

Press Run Simulation to visualize the robot perform SLAM in the environment.
If you have noticed the boxes are still flying in air.This is because you haven't set the mass of the object.

Now set the mass to be 1 so that the objects fall down and you can visualize the robot perform SLAM in the environment with boxes.

Now lets add a controller to control the robot.Create it using:

    Wizards -> New Robot Controller

name to your your desired choice.We shall be using "front_command.cpp".You'll get a template of code pre-written by Webots.Let's tune it according to our needs.

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

This code simply makes the robot go forward regardless of any obstacles with 0.1 times the max set speed.

The line:  `while (robot->step(TIME_STEP) != -1);` is analogous to `rosspin`.

Now Webots doesn't know that the robot uses this front_command.So you'll have to add have to edit the controller from E-puck in the STSB and point it to "front_command.cpp". 

This completes this section of the tutorial. Please go to the next section learn more about the Webots nodes.
