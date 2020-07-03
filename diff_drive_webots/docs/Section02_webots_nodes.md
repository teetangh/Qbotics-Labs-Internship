In the last section of the documentation we saw that our webot robot was moving only forward using the forward command cplusplus template that we just created. In this section of the documentation we shall understand webots nodes and construct a few of them on our own.
Now we'll create a new we;ll create a new webots world and save it in a new file

    (save02_webots_nodes.wbt).  

Now we shall create our own arena. Begin by deleting the floor that we had Received from the rectangular Arena in the wizard .Now begin by creating a new node select Proto then object then floor then rectangular Arena (solids)

Now set the parameters of the floor:
    
    Size: 2 2
    tile Size:0.5 0.5

Now add a custom node called solid from the add node menu and select shape from it Under the shape menu that geometry and followed sphere. Set  the appearance to pbr appearance.
Not in the base colour of the object and set its colour to Green by setting the RGB values to

	baseColor: 0 1 0 

 you can see that the ball is shining. To remove the shining property of the ball set the metalness to 0 and  roughness to 1. 
	
    metalness: 0
 	roughness: 1
  
Notice that webots provide an amazing feature of naming objects and properties so that we can use them later on.Notice the blank form at the bottom of the screen having DEF as the option. This WEbots feature that allows you to use the typedef keyword you mentioned in the DEF area to be used again. As an example we begin by naming Ball1_Solid.

Now Although we have a ball-like looking object.The physics and bounding properties of the ball  haven't been set.this can be done under the solid menu of the ball  by selecting bounding object use ball Physics Physics 

    boundingObject USE ball
    physics Physics



Now change the properties of the ball by setting the radius to 0.12 and subdivisions to 2 This can be found under the geometry sub-menu.Note this can ridiculously explode the computational resources of your system.Keep in mind the graphics processing required by the webots software is very heavy and you might want to keep the subdivisions as low as possible So be careful and try to keep the subdivision as low as possible.

    radius: 0.12
    subdivisions: 2 

Now you can create a second ball and name it Ball2_Solid.This can be done with control C + control V. To prevent the overlapping of the ball move one ball away from another Ball by just dragging the ball using your mouse cursor.
	
Now we need to create boundary walls for the entire scenery. Begin by selecting add from the add button not in the webots  menu.Now select children under the sub menu select shape under the sub-sub-menu. 
		
    Solid -> Children -> Shape .
    Shape -> Box 

Since we're dealing with the boundary wall, it helps to imagine how a boundary wall would actually look like. As before, set the appearance to PBR appearance. Set the size of the wall to:

    size : 0.2 0.1 0.05

We need to translate the boundary wall from the centre of the scene to the edge of the scene. This can be accomplished by setting the translational parameters of the solid we are currently dealing with to 0 0.5 and 1.

    Solid:
        translation:  0 0.5 1

	
Create a typedef for this wall and name at Wall1_solid.This would help in creation of the  other 3 walls  around the scenery. Also remember to use wall as its childrenSet the translational parameters to: 

    Solid:
        translation:  0 0.5 -1
    Children:
        USE Wall
    DEF:
        Wall2_Solid

We have now created 2 opposite walls but we also need to create two walls for the other two sides of the square arena. For this you need to set rotational parameters to the wall as well.

    Solid:
        translation:  1 0.5 0
    rotation:  0 1 0 -1.57
    Children:
        USE Wall
    DEF:
        Wall3_Solid

Similarly, for the fourth wall:

        
    Solid:
        translation:  -1 0.5 0
    rotation:  0 1 0 -1.57
    Children:
        USE Wall
    DEF:
        Wall3_Solid 

Voila!  you just created  four bounding walls for the given arena. As you can see all the four walls are connected and any changes made to a singular wall will be reflected in all the other walls. This can be verified by changing the property of any wall Like  changing the colour from metallic to White and  this will also change the same for all the other walls. As a bonus exercise you can add  base colour map and set it to image texture. Now from the urls menu select red brick wall.

    baseColourMap:  image texture
    URL: red brick wall 

Now you can proceed on to the next section of the documentation which will discuss on field of view functionalities of the webots software.
