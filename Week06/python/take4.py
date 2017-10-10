from tkinter import *
import tkSimpleDialog
import tkMessageBox

#set up our GUIs
root = Tk()
# w = Label(root, text="I don't know how to get rid of this.")
# w.pack()

#Welcome the user
tkMessageBox.showinfo("Welcome", "You are being welcomed.")

#get user info
name = tkSimpleDialog.askstring("Name", "What is your name?")
age = tkSimpleDialog.askinteger("Age", "How old are you?")

#Process information
output = "Hello %s. I hope you're doing fine today." %(name)
output += "\nOur records indicate that you are %d years old." %(age)

#Produce the output

tkMessageBox.showinfo("Results", output)


#Thank the user
tkMessageBox.showinfo("Thanks", "Thank you for your participation")