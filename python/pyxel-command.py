import serial
import time


arduino = serial.Serial(port='/dev/ttyUSB0',  baudrate=115200, timeout=.1)

def write_read(x):
    arduino.write(bytes(x,  'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return  data


while True:
    num = input("Enter a number: ")
    value  = write_read(num)
    print(value)

def readserial(comport, baudrate, timestamp=False):
    while True:
        data = arduino.readline().decode().strip()
        if data and timestamp:
            timestamp = time.strftime('%H:%M:%S')
            print(f'{timestamp} > {data}')
        elif data:
            print(data)
