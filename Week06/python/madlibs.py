from tkinter import *
import tkSimpleDialog
import tkMessageBox

#set up our GUIs
root = Tk()
# w = Label(root, text="I don't know how to get rid of this.")
# w.pack()

#Welcome the user
tkMessageBox.showinfo("Welcome", "Let's Play a Game!")

tkMessageBox.showinfo("Game", "We are going to play Madlibs!")

#get user info
one = tkSimpleDialog.askstring("1/20", "Enter a noun")
two = tkSimpleDialog.askstring("2/20", "Enter a part of the body")
three = tkSimpleDialog.askstring("3/20", "Enter a plural noun")
four = tkSimpleDialog.askstring("4/20", "Enter an adjective")
five = tkSimpleDialog.askstring("5/20", "Enter an adverb")
six = tkSimpleDialog.askstring("6/20", "Enter a person in room")
seven = tkSimpleDialog.askstring("7/20", "Enter a noun")
eight = tkSimpleDialog.askstring("8/20", "Enter a plural noun")
nine = tkSimpleDialog.askstring("9/20", "Enter a person in room")
ten = tkSimpleDialog.askstring("10/20", "Enter an adjective")
eleven = tkSimpleDialog.askstring("11/20", "Enter a celebrity")
twelve = tkSimpleDialog.askstring("12/20", "Enter a person in room (female)")
thirteen = tkSimpleDialog.askstring("13/20", "Enter a part of the body")
fourteen = tkSimpleDialog.askstring("14/20", "Enter an adjective")
fifteen = tkSimpleDialog.askstring("15/20", "Enter an adjective")
sixteen = tkSimpleDialog.askstring("16/20", "Enter a verb ending in -ing")
seventeen = tkSimpleDialog.askstring("17/20", "Enter a part of the body (plural)")
eighteen = tkSimpleDialog.askstring("18/20", "Enter an adjective")
nineteen = tkSimpleDialog.askstring("19/20", "Enter a noun")
twenty = tkSimpleDialog.askstring("20/20", "Enter a plural noun")

#Process information
output = "I've always wanted to enter the school talent %s but the thought of being on stage makes my " %(one)
output += "%s tremble with fear. This year, I decided to face my " %(two)
output += "%s and entered the " %(three)
output += "%s content. The competition was " %(four)
output += "%s fierce. " %(five)
output += "%s road a/an " %(six)
output += "%s while juggling " %(seven)
output += "%s. " %(eight)
output += "%s did a/an " %(nine)
output += "%s impersonation of " %(ten)
output += "%s. And " %(eleven)
output += "%s sang her " %(twelve)
output += "%s out with a/an " %(thirteen)
output += "%s rendition of '" %(fourteen)
output += "%s Days are Here Again.' Finally, it was my turn. I did a dance routine that had the audience " %(fifteen)
output += "%s in their seats. Afterward, I closed my eyes and crossed my " %(sixteen)
output += "%s for good luck. Suddenly I heard the principal say, 'And this year's " %(seventeen)
output += "%s winner is...' -- and it was me! When he handed me the " %(eighteen)
output += "%s shaped trophy, I held it up triumpantly and said 'This is for all the little " %(nineteen)
output += "%s that helped me along the way!" %(twenty)




#Produce the output

tkMessageBox.showinfo("Story", output)


#Thank the user
tkMessageBox.showinfo("Thanks", "Thank you for your participation")