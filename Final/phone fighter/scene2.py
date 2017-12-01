#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Modules

# Constants
import scene
import sys
import pygame
from pygame.locals import *
import os

# Classes
# ---------------------------------------------------------------------


class Scene(scene.Scene):
    """ Welcome screen of the game, the first one to be loaded."""
    

    def __init__(self, director):

        self.text = 'Press s to start and r to reset'
        self.ty = 450
        self.screen = pygame.display.set_mode((1000,563))
        self.size = 50
        self.color = (0, 000, 000)
        self.font_type = "fonts/roboto/Roboto-Light.ttf"
        self.changeScene = False
        self.sceneMessage = "scene2"
        self.sceneActive = True


        self.bg = pygame.image.load(os.path.join("images", "start_screen.png"))
        # self.mouse.set_visible(0)

        scene.Scene.__init__(self, director)

        self.screen.blit(self.bg, (0,0))
        self.text_to_screen(self.screen, self.text, self.ty, self.size, self.color, self.font_type)
        

       
    def on_update(self):
        pass

    def on_event(self):
        pass

    def on_draw(self, screen):
        pass

    def text_to_screen(self, screen, text, y, size, color, font_type):
        try:

            text = str(text)
            font = pygame.font.Font(font_type, size)
            text = font.render(text, True, color)
            x = 500 - text.get_rect().width/2
            self.screen.blit(text, (x, y))

        except Exception as e:
            print('Font Error, saw it coming')
            raise e

# ---------------------------------------------------------------------

# Functions
# ---------------------------------------------------------------------



# ---------------------------------------------------------------------

def main():
	pass

if __name__ == '__main__':
	main()


