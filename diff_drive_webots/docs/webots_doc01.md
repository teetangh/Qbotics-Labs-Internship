# Documentation

In this section of the documentation,we start by installing Webots,which is an open-source three-dimensional mobile robot simulator.

Head over to: 
    
    https://github.com/cyberbotics/webots/releases/tag/R2020a-rev1

and download the software according to your system architecture

After the installation of the Webots software youll be prompted with guide on how to the software.You can take a tour of the mavric pro demo just in case you want to get used to the software(The simulation very similar to a video game).

After you're comfortable with basic functionality of the software,create an empty project.This can be done by going to:

    Wizards -> New Project Directory

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

