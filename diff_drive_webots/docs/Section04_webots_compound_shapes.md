In the section of the documentation we shall learn how to create compound shapes out of the Webots software.Let's start by creating a dumbbell. This can be accomplished by using one cylinder in metal and two metallic spheres at the opposing ends.

Create a solid in the environment. This can be done by adding it as a custom node as we learnt in the earlier tutorials. Latest children and add groups to its children. under the group make for the children and select one shape and two transforms. the final skeleton hierarchy should look as follows :
	
    Solid:
        children:
            Group:
                children:
                    Shape
                        Cylinder
                    Transform
                        Shape
                            Cylinder(DEF Globe)
                    Transform
                        USE Globe(To be defined later)

Now set the cylinder properties with radius at 0.01 and height at 0.1 and appearance to PBR appearance.Also set an arbitrary translation so it does not appear to collide with other objects. 

	Solid:
	    Translation: 0.36 0.2 0
	    G0 Group
		    Shape
            Appearance:
                PBR appearance
                geometry:Cylinder
                    Height: 0.1
                    Radius: 0.01
            DEF: GO

Now also set the bounding object with  bonding properties as G0 and physics as physics

	boundingObject USE G0
	Physics: Physics


Now define the first transform shape to be a sphere and call it globe as its typedef name.

        Transform
            Translation: 0 0.5 0
            Appearance:
                PBR appearance
            geometry:Sphere
                Radius: 0.04
                Subdivisions:2  
            DEF: Globe

Now create the second sphere and make its children use globe properties. Thus the properties are replicated and a huge amount of effort is saved.

Congratulations on creating a first compound shape now you can proceed on to adding physics and section to this compound object 


 

