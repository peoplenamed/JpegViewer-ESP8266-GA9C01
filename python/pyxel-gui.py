# IMPORTANT! MUST INSTALL EMOJI LIBRARY IN UBUNTU!
# sudo apt-get install -y ttf-ancient-fonts-symbola

import serial
import tkinter as tk
from tkinter import ttk
import time
import threading
import serial.tools.list_ports


class Application(tk.Tk):
    FONT = "Ubuntu 16"
    FONT_EMPHASIS = "Ubuntu 16 bold"
    BAUD_RATE_LIST = [300, 1200, 1800, 2400, 4800, 7200, 9600, 14400, 19200, 38400, 57600, 74880, 115200, 230400, 250000, 500000, 1000000, 2000000]
    COM_PORT_LIST = ["/dev/ttyUSB0", "/dev/ttyUSB1", "/dev/ttyUSB2", "/dev/ttyUSB3", "/dev/ttyUSB4", "/dev/ttyS0", "/dev/ttyS1", "/dev/ttyS2", "/dev/ttyS3", "/dev/ttyS4", "/dev/ttyS5", "/dev/ttyS6", "/dev/ttyS7", "COM1", "COM2", "COM3", "COM4"]
    WIDTH = 900
    HEIGHT = 900

    def __init__(self):
        super().__init__()
        # self.getSerialPorts()
        self.title("Pyxel GUI")
        self.default_com = "/dev/ttyUSB0"
        self.connected = False
        self.dataBuffer = []
        self.secondaryBuffer = []
        self.createCanvas()
        self.setupPort()
        self.setupBaud()
        self.setupConnectButton()
        self.setupSerialOutputTextArea()
        self.setupSendButtons()
        self.setupTextInput()


    def createCanvas(self):
        self.canvas = tk.Canvas(self, width=self.WIDTH, height=self.HEIGHT)
        self.canvas.pack()

    def setupPort(self):
        self.portLabel = tk.Label(self, text="Port", font=self.FONT)
        self.portLabel.place(anchor="n", relx=0.04, rely=0.0, relwidth=0.25, relheight=0.05)

        self.portVal = tk.StringVar(self)
        self.portVal.set(self.COM_PORT_LIST[0])

        self.portMenu = tk.OptionMenu(self, self.portVal, *self.COM_PORT_LIST)
        self.portMenu.config(font=self.FONT)
        self.portMenu.place(anchor="n", relx=0.20, rely=0.00, relwidth=0.25, relheight=0.05)

    def setupBaud(self):
        self.baudLabel = tk.Label(self, text="@", font=self.FONT)
        self.baudLabel.place(anchor="n", relx=0.35, rely=0.00, relwidth=0.05, relheight=0.05)

        self.baudRateVal = tk.StringVar(self)
        self.baudRateVal.set(self.BAUD_RATE_LIST[12])

        self.baudMenu = tk.OptionMenu(self, self.baudRateVal, *self.BAUD_RATE_LIST)
        self.baudMenu.config(font=self.FONT)
        self.baudMenu.place(anchor="n", relx=0.5, rely=0.00, relwidth=0.25, relheight=0.05)

    def setupConnectButton(self):
        self.connectButton = tk.Button(self, text="Connect", font=self.FONT_EMPHASIS, command=self.openSerialConnection)
        self.connectButton.place(anchor="n", relx=0.9, rely=0.0, relwidth=0.19, relheight=0.05)

    def setupSerialOutputTextArea(self):
        self.serialOutput = tk.Text(self, width=40, height=10, font=self.FONT, state="disabled")
        self.serialOutput.place(anchor="n", relx=0.5, rely=0.05, relwidth=1, relheight=0.82)

    def setupSendButtons(self):
        self.sendButton = tk.Button(self, text="Send", font=self.FONT_EMPHASIS, command=lambda: self.sendSerial(False))
        self.sendButton.place(anchor="n", relx=0.92, rely=0.875, relwidth=0.15, relheight=0.06)

        self.sendWrappedButton = tk.Button(self, text="<Send>", font=self.FONT_EMPHASIS, command=lambda: self.sendSerial(True))
        self.sendWrappedButton.place(anchor="n", relx=0.92, rely=0.935, relwidth=0.15, relheight=0.06)

    def setupTextInput(self):
        self.dataInput = tk.Entry(self, font=self.FONT, justify="center")
        self.dataInput.place(anchor="n", relx=0.41, rely=0.875, relwidth=0.8, relheight=0.1)
        self.dataInput.bind("<Return>", self.sendEvent)
        self.dataInput.bind("<KeyRelease>", self.updateIdleTasks)

    def updateIdleTasks(self, event):
        self.update_idletasks()

    def sendEvent(self, event):
        self.sendSerial(True)
        return "break"

    # def getSerialPorts(self):
    #     self.COM_PORT_LIST = serial.tools.list_ports.comports()
    #     return self.COM_PORT_LIST


    def setGUI(self):
        while True:
            try:
                if len(self.secondaryBuffer) < len(self.dataBuffer) and self.serialConnection != None:
                    self.serialOutput.configure(state="normal")
                    self.serialOutput.insert("end", self.dataBuffer[len(self.dataBuffer)-1] + "\n")
                    self.serialOutput.see("end")
                    self.serialOutput.configure(state="disabled")
                    self.secondaryBuffer.append(self.dataBuffer[len(self.dataBuffer)-1]) 
            except:
                pass


    def listenSerial(self):
        while True:
            if self.serialConnection != None:
                try:
                    self.received = self.serialConnection.readline().decode().replace("\n", "")
                    self.consologger("🐢  " + str(self.received))
                except:
                    pass


    def openSerialConnection(self):
        if (self.connected == False):
            self.comPort = self.portVal.get()
            self.baudRate = self.baudRateVal.get()
            self.connectButton["text"] = "Disconnect"
            try:
                self.serialConnection = serial.Serial(self.comPort, self.baudRate)
                self.after(750, self.startThreads)
                self.connected = True
                response = "🤖  Successfully connected to " + str( self.comPort) + str(" @ " + self.baudRate)
                self.consologger(response)
            except Exception as e:
                print("💥ERROR💥 ", e)
                self.connectButton["text"] = "Connect"
                self.connected = False
        elif self.connected == True:
            self.serialConnection.close()
            self.connectButton["text"] = "Connect"
            self.connected = False
            self.consologger("🤖  ☠️☠️☠️ Serial disconnected. ☠️☠️☠️")

    def consologger(self, str):
        self.dataBuffer.append(str.replace(" T: ", ""))
        print(str.replace(" T: ", ""))

    def startThreads(self):
        self.listenSerialThread = threading.Thread(target=self.listenSerial)
        self.listenSerialThread.daemon = True
        self.listenSerialThread.start()

        self.setGUIThread = threading.Thread(target=self.setGUI)
        self.setGUIThread.daemon = True
        self.setGUIThread.start()


    def sendSerial(self, wrapped):
        self.sendDataString = self.dataInput.get()
        if wrapped:
            self.sendDataString = "<" + self.sendDataString + ">"

        if self.connected:
            self.consologger("🤓  " + str(self.sendDataString))
            self.serialConnection.write(self.sendDataString.encode())
        else:
            self.consologger("🤖  NOT CONNECTED! ")
            print("🤖  🤓 Meh, what do I care?")
            print("🤖  Starting connection...")
            self.openSerialConnection()
            print("🤖  What does Star Trek 🌌")
            print("🤖    and toilet paper 🧻")
            print("🤖     have in common?")
            print("🤖  🖖 They both wipe Klingons off Uranus. 🖖")
            self.sendSerial(True)

app = Application()
app.resizable(True, True)

app.mainloop()