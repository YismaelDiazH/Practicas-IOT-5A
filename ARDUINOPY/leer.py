import serial
SerialArduino = serial.Serial(port='COM15', baudrate=9600)
while True:
    lectureSensor=SerialArduino.readline().decode('ascii')
    print(lectureSensor)
    

SerialArduino.close()
  
