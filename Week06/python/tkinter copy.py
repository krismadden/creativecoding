# from tkinter import *
# from tkinter import tkk

# root = Tk()

# root.title("First GUI")

# ttk.Button(root, text="Hello TkInter").grid()

# root.mainloop()

#!/usr/bin/python

from tkinter import *

class App:

    def __init__(self):
        self.root = Tk()
        self.root.title("First GUI???")
        self.root.minsize(width=500,height=400)
                
        # Set up basic Menu
        menubar = Menu(self.root)

        menubar.add_command(label="Button")
        
        self.root.config(menu=menubar)



app = App()

app.root.mainloop()