#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Modules

# Constants
import scene
import director
import sys
import pygame
from pygame.locals import *
import os

# Classes
# ---------------------------------------------------------------------


class Scene(scene.Scene):
    """ Welcome screen of the game, the first one to be loaded."""
    

    def __init__(self, director):

        self.text = 'You are iPhone.'
        self.ty = 450
        self.screen = pygame.display.set_mode((1000,563))
        self.size = 50
        self.color = (0, 000, 000)
        self.font_type = "fonts/roboto/Roboto-Light.ttf"
        self.changeScene = False
        self.sceneMessage = "scene3"
        self.sceneActive = True
        self.red = (250,100,150)
        self.highlightPos = "1"
        self.hightlightX = 250 - 100*1.3/2


        self.bg = pygame.image.load(os.path.join("images", "screen2.png"))

        self.phone1 = pygame.image.load(os.path.join("images", "iphone.png"))
        self.phone1 = pygame.transform.scale(self.phone1, (100, 200))
        self.phone2 = pygame.image.load(os.path.join("images", "iphone.png"))
        self.phone2 = pygame.transform.scale(self.phone2, (100, 200))
        self.phone3 = pygame.image.load(os.path.join("images", "iphone.png"))
        self.phone3 = pygame.transform.scale(self.phone3, (100, 200))


        #fadeout
        self.phone1opacity = 256;
        self.phone2opacity = 256;
        self.phone3opacity = 256;
        self.opacity = 256;

        #fade
        self.last = pygame.time.get_ticks()
        self.cooldown = 10 #300 = 0.3 seconds 
        self.opacitydecrease = 30


        #here??????
        #self.director = director.Director(self)

        scene.Scene.__init__(self, director)

        #are these needed?

        self.screen.blit(self.bg, (0,0))

        pygame.draw.rect(self.screen,self.red,(self.hightlightX,100-200*0.3/2,100*1.3,200*1.3))

        #replace the screen.blit(happy, (100, 100)) with a call to blit_alpha(screen, happy, (100, 100), 128)
        # self.screen.blit(self.phone1, (250 - self.phone2.get_rect().width/2,100))
        # self.screen.blit(self.phone2, (500 - self.phone2.get_rect().width/2,100))
        # self.screen.blit(self.phone3, (750 - self.phone2.get_rect().width/2,100))

        self.blit_alpha(self.screen, self.phone1, (250 - self.phone2.get_rect().width/2,100), self.phone1opacity)
        self.blit_alpha(self.screen, self.phone2, (500 - self.phone2.get_rect().width/2,100), self.phone2opacity)
        self.blit_alpha(self.screen, self.phone3, (750 - self.phone2.get_rect().width/2,100), self.phone3opacity)

        

        self.text_to_screen(self.screen, self.text, self.ty, self.size, self.color, self.font_type)



       
    def on_update(self):
        pass

    def on_event(self):
        pass

    def on_draw(self, screen):
        # pass

        if self.director.highlightPos == "1":
            self.hightlightX = 250 - 100*1.3/2
        elif self.director.highlightPos == "2":
            self.hightlightX = 500 - 100*1.3/2
        elif self.director.highlightPos == "3":
            self.hightlightX = 750 - 100*1.3/2

        if self.opacity > 0:
            now = pygame.time.get_ticks()
            if now - self.last >= self.cooldown:
                self.last = now
                self.opacity -= self.opacitydecrease
                if self.director.highlightPos == "1":
                    self.phone1opacity = 256
                    self.phone2opacity = self.opacity
                    self.phone3opacity = self.opacity
                elif self.director.highlightPos == "2":
                    self.phone1opacity = self.opacity
                    self.phone2opacity = 256
                    self.phone3opacity = self.opacity
                elif self.director.highlightPos == "3":
                    self.phone1opacity = self.opacity
                    self.phone2opacity = self.opacity
                    self.phone3opacity = 256

        self.screen.blit(self.bg, (0,0))

        pygame.draw.rect(self.screen,self.red,(self.hightlightX,100-200*0.3/2,100*1.3,200*1.3))

        self.blit_alpha(self.screen, self.phone1, (250 - self.phone2.get_rect().width/2,100), self.phone1opacity)
        self.blit_alpha(self.screen, self.phone2, (500 - self.phone2.get_rect().width/2,100), self.phone2opacity)
        self.blit_alpha(self.screen, self.phone3, (750 - self.phone2.get_rect().width/2,100), self.phone3opacity)

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



    def blit_alpha(self, target, source, location, opacity):
        x = location[0]
        y = location[1]
        temp = pygame.Surface((source.get_width(), source.get_height())).convert()
        temp.blit(target, (-x, -y))
        temp.blit(source, (0, 0))
        temp.set_alpha(opacity)        
        target.blit(temp, location)

# ---------------------------------------------------------------------

# Functions
# ---------------------------------------------------------------------



# ---------------------------------------------------------------------

def main():
	pass

if __name__ == '__main__':
	main()


