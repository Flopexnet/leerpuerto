#Este codigo conecta la RPI al puerto serial de Arduino
# Python 2.27
from serial import *
from Tkinter import *

locations=['/dev/ttyUSB2','/dev/ttyUSB3',  
'/dev/ttyS0','/dev/ttyS1','/dev/ttyS2','/dev/ttyS3','/dev/ttyACM0','/dev/ttyACM1','/dev/ttyACM2','/dev/ttyACM3']


for device in locations:    
    try:    
        print "Conectando...",device


	serialPort = device
	baudRate = 9600
	ser = Serial(serialPort , baudRate, timeout=0, writeTimeout=0) 

	print 'Conexion establecida'  
        break  
    except:    
        print "La conexion a fallado",device

# Crea la ventana con TkInter
root = Tk()
root.wm_title("Reading Serial") # titulo de la ventana
root.geometry("400x350") # tamaño de la caja
root.config(bg ="#037481") # color de la caja


# Toma el texto de la salida del puerto serial y lo pone en la caja de texto
log = Text ( root, width=10, height=1, takefocus=0, font=('Tempus Sans ITC', 30, 'bold'))
log.pack()

 # bufer de dato
serBuffer = ""

def readSerial():
    while True:
        c = ser.read() # toma el dato de la salida del arduino
        
        # si hay dato
        if len(c) == 0:
            break
        
        # obtiene el dato desde afuera de la funcion
        global serBuffer
        
        # Comprobar si el caracter es un limitador
        if c == '\r':
            c = '' 
            
        if c == '\n':
            serBuffer += "\n" # agregar una nueva linea al buffer
            log.insert('0.0', serBuffer)
            serBuffer = "" # Vaciar buffer
        else:
            serBuffer += c # agregar al buffer
    
    root.after(10, readSerial) # revisar el puerto serial nuevamente
root.after(100, readSerial)

root.mainloop()
