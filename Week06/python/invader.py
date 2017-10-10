#!/usr/bin/env python

import pygame, sys

#allows us to get mouse and key pesses
from pygame.locals import *


#helps limit framerate to 60 frames per second max
clock = pygame.time.Clock()
screen = pygame.display.set_mode((800,600))

#hides cursor
pygame.mouse.set_visible(0)

#create object
ship = pygame.image.load("images/ship.png")
#top of the image
ship_top = screen.get_height() - ship.get_height()
ship_left = screen.get_width()/2 - ship.get_width()/2

#not actually necessary because of fill below
screen.blit(ship, (ship_left,ship_top))

#shooting
shot = pygame.image.load("images/shot.png")
shoot_y = 0


while True:
	clock.tick(60)
	#make screen black
	screen.fill((0,0,0))

	x,y = pygame.mouse.get_pos()

	screen.blit(ship, (x-ship.get_width()/2,ship_top))
	

	for event in pygame.event.get():
		#when clicking x on window, exit game
		if event.type == pygame.QUIT:
			sys.exit()
		elif event.type == MOUSEBUTTONDOWN:
			shoot_y = 500
			shoot_x = x ##left/right of cursor

	if shoot_y > 0:
		screen.blit(shot, (shoot_x, shoot_y))
		shoot_y -= 10 ##each loop it moves up 10 pixels

	#pygame.display.flip() ##same enough as update()
	pygame.display.update()