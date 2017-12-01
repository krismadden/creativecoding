# -*- encoding: utf-8 -*-

class Scene:
    """Represents a scene of the game.
 
     Scenes must be created inheriting this class attributes
     in order to be used afterwards as menus, introduction screens,
     etc."""


    def __init__(self, director):
        self.director = director
        self.changeScene = False
        self.sceneMessage = "None" #name of scene goes in here
        #self.sceneActive = False # this constantly resets this to false

    def on_update(self):
        "Called from the director and defined on the subclass."
        raise NotImplemented("on_update abstract method must be defined in subclass.")

    def on_event(self, event):
        "Called when a specific event is detected in the loop."
        raise NotImplemented("on_event abstract method must be defined in subclass.")

    def on_draw(self, screen):
        "Called when you want to draw the screen."
        raise NotImplemented("on_draw abstract method must be defined in subclass.")