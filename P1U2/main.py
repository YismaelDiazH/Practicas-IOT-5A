import serial, time
SerialArduino = serial.Serial('COM15', 9600)
time.sleep(2)
SerialArduino.write(b'0')
SerialArduino.close()