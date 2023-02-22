import serial, time
SerialArduino = serial.Serial('COM15', 9600)
time.sleep(2)
while 1==1:
    binario=SerialArduino.readline().decode('ascii')
    binario = int(binario,2)
    binario = str(binario
    )
    print(binario)
    SerialArduino.write(binario.encode('ascii'))
SerialArduino.close()


