import tkinter as tk
import serial
import time

ARDUINO_PORT = "COM4"
BAUD_RATE = 115200

ser = serial.Serial(ARDUINO_PORT, BAUD_RATE, timeout=1)
time.sleep(2)   #waiting time to reset arduino


def move_motor():
    ser.write(b"MOVE\n")
    print ("Command sent: MOVE")

root = tk.Tk()

move_button = tk.Button(root, text="Move", command=move_motor, font=("Arial", 20))
move_button.pack(padx=50, pady=50)

root.mainloop()