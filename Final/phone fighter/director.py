# -*- encoding: utf-8 -*-
 
# Modules
import pygame, sys
from pygame.locals import *
import scene_home 
import scene2, scene3, scene4 

from pygame_functions import *

class Director:
    """Represents the main object of the game.
 
    The Director object keeps the game on, and takes care of updating it,
    drawing it and propagate events.
 
    This object must be used with Scene objects that are defined later."""
 
    def __init__(self):
        self.screen = pygame.display.set_mode((640, 480))
        pygame.display.set_caption("Street Cred")
        # self.scene = None
        # self.fullscreen = False
        self.quit_flag = False
        self.clock = pygame.time.Clock()
        pygame.mouse.set_visible(0)
        self.highlightPos = "1"

    def loop(self):
        "Main game loop."
 
        while not self.quit_flag:
            time = self.clock.tick(60)
 
            # Exit events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.quit()
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        self.quit()
                    if event.key == K_q:
                        self.scene_2 = scene2.Scene(self)
                        self.change_scene(self.scene_2)
                        print("hi mom")
                    if event.key == K_r:
                        self.scene_home = scene_home.SceneHome(self)
                        self.change_scene(self.scene_home)
                        print("hi mom")
                    if event.key == K_s:
                        print(self.scene_2.sceneActive)
                        if self.scene_2.sceneActive:
                            self.scene_2.sceneActive = False
                            self.scene_3 = scene3.Scene(self)
                            self.change_scene(self.scene_3)
                            self.scene.sceneMessage = "scene3"
                        elif self.scene_3.sceneActive:
                            self.scene_3.sceneActive = False
                            self.scene_4 = scene4.Scene(self)
                            self.change_scene(self.scene_4)
                            self.scene.sceneMessage = "scene4"
                            self.highlightPos = self.scene_3.highlightPos
                            print(self.scene_3.highlightPos)
                    if event.key == K_0:
                        if self.scene_3.sceneActive:
                            if self.scene_3.highlightPos == "1":
                                self.scene_3.highlightPos = "2"
                            elif self.scene_3.highlightPos == "2":
                                self.scene_3.highlightPos = "3"
                            elif self.scene_3.highlightPos == "3":
                                self.scene_3.highlightPos = "1"
                    if event.key == K_9:
                        if self.scene_3.sceneActive:
                            if self.scene_3.highlightPos == "1":
                                self.scene_3.highlightPos = "3"
                            elif self.scene_3.highlightPos == "2":
                                self.scene_3.highlightPos = "1"
                            elif self.scene_3.highlightPos == "3":
                                self.scene_3.highlightPos = "2"

 
            # Detect events
            # self.scene.on_event()
 
            # Update scene
            self.scene.on_update()
 
            # Draw the screen
            self.scene.on_draw(self.screen)
            pygame.display.flip()
            if self.scene.changeScene == True :
                if self.scene.changeScene == "None":
                    pass
                elif self.scene.sceneMessage == "scene2":
                    self.scene_2 = scene2.Scene(self)
                    self.change_scene(self.scene_2)

            
 
    def change_scene(self, scene):
        "Changes the current scene."
        self.scene = scene

    def quit(self):
        self.quit_flag = True
