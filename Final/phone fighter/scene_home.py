#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Modules

# Constants
import scene
import director
import scene2

import pygame, sys
from pygame.locals import *
import os
import time
import timeit
from timeit import default_timer
from datetime import datetime


# Classes
# ---------------------------------------------------------------------

class SceneHome(scene.Scene):
    """ Welcome screen of the game, the first one to be loaded."""

    def __init__(self, director):
        self.screen = pygame.display.set_mode((1000,563))
        self.font_type = "fonts/roboto/Roboto-Light.ttf"
        self.start_time = time.clock()
        self.dir = director
        self.changeScene = False
        self.sceneMessage = "None"
        #self.text_to_screen(self.screen, "hi mom " + str(duration), 0, 0, 50, (0,0,0), self.font_type)

        scene.Scene.__init__(self, director)

       
    def on_update(self):
        pass

    def on_event(self):
        pass

    def on_draw(self, screen):
        #pass
        # countdown(5)

        thetime = int(time.clock() - self.start_time)
        if(thetime >= 1):
            self.changeScene = True
            self.sceneMessage = "scene2"
            # self.dir.scene_2 = scene2.Scene2(self.dir)
            # self.dir.change_to_scene(self.dir,"scene2")
            # change_scene(scene2.Scene2)

            #print("hi dad")



        self.bg = pygame.image.load(os.path.join("images", "screen0.png"))
        self.screen.blit(self.bg, (0,0))

        self.loading = pygame.image.load(os.path.join("images", "loading.gif"))
        self.screen.blit(self.loading, (110,110))


        duration = datetime.time(datetime.now())
        self.text_to_screen(self.screen, "restarting " + str(thetime), 0, 0, 50, (0,0,0), self.font_type)

    def text_to_screen(self, screen, text, x, y, size, color, font_type):
        try:

            text = str(text)
            font = pygame.font.Font(font_type, size)
            text = font.render(text, True, color)
            self.screen.blit(text, (x, y))

        except Exception as e:
            print('Font Error, saw it coming')
            raise e


# ---------------------------------------------------------------------

# Functions
# ---------------------------------------------------------------------

def hello():
    print("hello, world")

# def countdown(t):
#     while t:
#         mins, secs = divmod(t, 60)
#         timeformat = '{:02d}:{:02d}'.format(mins, secs)
#         print(timeformat, end='\r')
#         time.sleep(1)
#         t -= 1
#     print('Goodbye!\n\n\n\n\n')



# ---------------------------------------------------------------------

def main():
	#pass
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			if event.key == K_q:
				self.change_scene(self, scene2)
				print("hi mom")

if __name__ == '__main__':
    main()

