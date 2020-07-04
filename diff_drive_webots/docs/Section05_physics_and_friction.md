In this section of the documentation we shall learn how to create friction for our environment and also for objects inside it.`If you haven't touched the bounding object parameters and the physics properties of the walls and the spheres earlier in the tutorial, you can set it now`, as we will play around with our environment in this section of the documentation.
Set the dumbbell physics as:

        boundingObject: Use G0
        Physics: Use Physics
        mass: 5
        Contact_material: db_contact_material


We also have to set the contact material of the dumbbell and the environment so that we can control the friction as per our choice.
As you can see in the above snippet contact material has been set to db_contact_material.
 
That handles the dumbbell part of the friction. Now we have to adjust the environment according to our needs.Are doing this go to the world in perfect contact properties to contact properties and the material2 to db_contact_material.

        World Info:
                Contact_Properties:
                        material2:
                        db_contact_material

	
Set the coulomb friction to your desired value, for example 0 if you want frictionless surface and 1 if you want there to be friction in the playground.It can actually be set to a float value 

        Coloumbfriction: 0 

Now use `control + alt` and drag using cursor to apply a force on the dumbbell and drag it along the environment also making sure that the walls had physics earlier or else the dumbbell will go out of scope.Play around with dumbbell with and without friction to get an idea of the Physics of the environment.

 congratulations for making it to the end of the section and proceed onto the next section for creating our very own `differential drive in Webots`.