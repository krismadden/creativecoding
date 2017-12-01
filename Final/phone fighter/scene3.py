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

        self.text = 'Select Your Character'
        self.ty = 450
        self.screen = pygame.display.set_mode((1000,563))
        self.size = 50
        self.color = (0, 000, 000)
        self.font_type = "fonts/roboto/Roboto-Light.ttf"
        self.changeScene = False
        self.sceneMessage = "scene3"
        self.sceneActive = True
        self.blue = (100,100,250)
        self.highlightPos = "1"
        self.hightlightX = 250 - 100*1.3/2

        #here???????
        


        self.bg = pygame.image.load(os.path.join("images", "screen2.png"))

        self.phone1 = pygame.image.load(os.path.join("images", "iphone.png"))
        self.phone1 = pygame.transform.scale(self.phone1, (100, 200))
        self.phone2 = pygame.image.load(os.path.join("images", "iphone.png"))
        self.phone2 = pygame.transform.scale(self.phone2, (100, 200))
        self.phone3 = pygame.image.load(os.path.join("images", "iphone.png"))
        self.phone3 = pygame.transform.scale(self.phone3, (100, 200))



        scene.Scene.__init__(self, director)

        #are these needed?

        self.screen.blit(self.bg, (0,0))

        pygame.draw.rect(self.screen,self.blue,(self.hightlightX,100-200*0.3/2,100*1.3,200*1.3))

        self.screen.blit(self.phone1, (250 - self.phone2.get_rect().width/2,100))
        self.screen.blit(self.phone2, (500 - self.phone2.get_rect().width/2,100))
        self.screen.blit(self.phone3, (750 - self.phone2.get_rect().width/2,100))

        

        self.text_to_screen(self.screen, self.text, self.ty, self.size, self.color, self.font_type)
        

       
    def on_update(self):
        pass
        # if self.highlightPos == "1":
        #     self.hightlightX = 100-200*0.3/2
        #     print("1")
        # elif self.highlightPos == "2":
        #     self.hightlightX = 500 - 100*1.3/2
        #     print("1")
        # elif self.highlightPos == "3":
        #     self.hightlightX = 750 - 100*1.3/2
        #     print("1")

    def on_event(self):
        pass

    def on_draw(self, screen):
        # pass

        if self.highlightPos == "1":
            self.hightlightX = 250 - 100*1.3/2
        elif self.highlightPos == "2":
            self.hightlightX = 500 - 100*1.3/2
        elif self.highlightPos == "3":
            self.hightlightX = 750 - 100*1.3/2

        self.screen.blit(self.bg, (0,0))

        pygame.draw.rect(self.screen,self.blue,(self.hightlightX,100-200*0.3/2,100*1.3,200*1.3))

        self.screen.blit(self.phone1, (250 - self.phone2.get_rect().width/2,100))
        self.screen.blit(self.phone2, (500 - self.phone2.get_rect().width/2,100))
        self.screen.blit(self.phone3, (750 - self.phone2.get_rect().width/2,100))

        self.text_to_screen(self.screen, self.text, self.ty, self.size, self.color, self.font_type)

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


