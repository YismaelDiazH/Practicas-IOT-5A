import serial
SerialArduino = serial.Serial(port='COM18', baudrate=9600)
while True:
    lectureSensor=SerialArduino.readline().decode('ascii')
    print(lectureSensor)
    with open('C:/Users/Yismael/Music/ARDUINOPY/datosExamen.txt','a') as f:
        f.write(lectureSensor)