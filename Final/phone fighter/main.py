#!/usr/bin/env python3
# -*- coding: utf-8 -*-
 
# Modules
import pygame
import director
import scene_home

from pygame_functions import *
# import scene2

def main():
    dir = director.Director()
    scene = scene_home.SceneHome(dir)
    dir.change_scene(scene)
    dir.loop()

    #pygame.mouse.set_cursor(*pygame.cursors.arrow)

if __name__ == '__main__':
    pygame.init()
    main()
