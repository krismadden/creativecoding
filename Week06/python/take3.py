from tkinter import *
import tkSimpleDialog
import tkMessageBox

#set up our GUIs
root = Tk()
w = Label(root, text="My Program")
w.pack()

#Welcome the user
tkMessageBox.showinfo("Welcome", "You are being welcomed.")