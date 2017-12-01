from pygame_functions import *

pygame.display.set_caption("Phone Drop")

screenSize(750,750)
setBackgroundColour((68,201,211))


surface = makeSprite("images/grass.png")  # create the sprite object
moveSprite(surface, 0, 650)                     # move it into position. It is not visible yet
showSprite(surface)                             # display it

phone = makeSprite("images/iphone.png",)        # create the sprite object
transformSprite(phone, 0, 0.3)
addSpriteImage(phone,"images/iphone2.png") # add the crashed image
moveSprite(phone, 280, 0)
showSprite(phone)                              # display it

luckColor = "yellow"
luckLabel = makeLabel("Luck: 50", 28, 10, 10, luckColor)
showLabel(luckLabel)

ypos = 0
yspeed = 0
upthrust = 0
luck = 50

while True:
    if keyPressed("up") and luck > 0:       # only allow thrust if some fuel exists
        upthrust = 2
        luck = luck - 1                     # remove some fuel
        if luck < 10:
            luckColor = "red"              # Warning for low fuel

        changeLabel(luckLabel,"Fuel: " + str(int(luck)), luckColor)  # Update the label
    else:
        upthrust = 0

    ypos += yspeed
    moveSprite(phone, 280, ypos)
    yspeed += 1 - upthrust      # add a bit of acceleration due to gravity
    

    if touching(phone, surface):
        ypos = 650 - 150        # place the lander on the surface
        if yspeed > 10:
            changeSpriteImage(phone, 1)
            transformSprite(phone, 0, 0.3)
        yspeed = 0              # stop the movement


    tick(30)