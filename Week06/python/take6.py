from tkinter import *

def main():
	root = Tk()
	root.title("Not My First Tkinter App")
	root.minsize(width=300, height=300)
	root.maxsize(width=500, height=500)

	#width for button is in characters not pixels
	button = Button(root, text="Click Me!", width=30, height=3)
	# this .pack is what actually displays your button
	button.pack()

	root.mainloop()

if __name__ == '__main__':
	main()