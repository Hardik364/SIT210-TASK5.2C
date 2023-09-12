# Task 5.2 C - hardik Bajaj

# import the libraries
from tkinter import *
import tkinter.font
from gpiozero import LED
import RPi.GPIO as GPIO

# set up the harware
GPIO.setmode(GPIO.BOARD)
GPIO.setup(3,GPIO.OUT)
GPIO.setup(5,GPIO.OUT)
GPIO.setup(8,GPIO.OUT)

# set up the window
win = Tk()
win.title("Led toggler")
myFont = tkinter.font.Font(family = 'Helvetica', size = 12, weight = "bold")

# Define the function that will be called when the option is selected
def selLed():
    selection = "You selected the LED " + str(var.get())
    label.config(text = selection)
    # Based on the selected option turn the LED ON or OFF
    if var.get() == 1:
        #led.off()
        GPIO.output(3,GPIO.HIGH)
        GPIO.output(5,GPIO.LOW)
        GPIO.output(8,GPIO.LOW)
    elif var.get() == 2:
        #led.on()
        GPIO.output(3,GPIO.LOW)
        GPIO.output(5,GPIO.HIGH)
        GPIO.output(8,GPIO.LOW)
    elif var.get() == 3:
        #led.on()
        GPIO.output(3,GPIO.LOW)
        GPIO.output(5,GPIO.LOW)
        GPIO.output(8,GPIO.HIGH)
        
# Finally clean up everything when window is closed        
def close():
    GPIO.cleanup()
    win.destroy()
    
# Define the variable which will be used to set index of the led in the window
var = IntVar()

# Set up three radio button options which will call function selLed when selected
buttonOne = Radiobutton(win, text="Green", variable=var, value=1, command=selLed)
buttonOne.pack( anchor = W )

buttonOneTwo = Radiobutton(win, text="Yellow", variable=var, value=2,command=selLed)
buttonOneTwo.pack( anchor = W )

buttonOneThree = Radiobutton(win, text="Red", variable=var, value=3, command=selLed)
buttonOneThree.pack( anchor = W)

# Label to display which option is selected
label = Label(win)
label.pack()

# Clean up when the window is closed. And stay in loop wiht main loop
win.protocol("WM_DELETE_WINDOW", close)
win.mainloop()