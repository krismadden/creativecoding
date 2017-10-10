# import sys
# if sys.version_info[0] < 3:
#     import Tkinter as tk     ## Python 2.x
# else:
#     import tkinter as tk     ## Python 3.x

import tkinter as tk     ## Python 3.x

class App(tk.Frame):
    def __int__(self, master):
        tk.Frame.__init__(self, master)
        self.pack()
        self.master.title("Hello World")
        self.minsize(width=500,height=400)

        tk.Label(self, text="This is your first GUI.(highfive)").pack()

if __name__ == '__main__':
    root = tk.Tk()
    app = App(root)
    app.mainloop()