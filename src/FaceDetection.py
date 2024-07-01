import serial
import cv2 as cv
import time
from serial.tools import list_ports

ports = list(list_ports.comports())
for port in ports:
    print(port.device)

portName = "/dev/ttyACM0"

arduinoData = serial.Serial(portName, 9600)

print(cv.__version__)

def send_coordinates_to_arduino(x, y, w, h):
    # Convert the coordinates to a string and send it to Arduino
    coordinates = f"{x+w/2},{y+h/2}\r"
    arduinoData.write(coordinates.encode())
    print(f"X{x+w/2}Y{y+h/2}\n")

def FaceDetection():
    # x_rotate = 0
    # y_rotate = 0

    capture = cv.VideoCapture(0, cv.CAP_V4L2) #Change the number for the camera that you are using, 0 is for the internal laptop camera, 1 is for an external webcam
    face_cascade = cv.CascadeClassifier(cv.data.haarcascades + 'haarcascade_frontalface_default.xml')
    while True:
        isTrue, frame = capture.read()
        # print(len(frame[1]))
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.05, 8, minSize= (120,120))

        for (x,y,w,h) in faces:
            cv.rectangle(frame, (x,y), (x+w, y+h), (0,255,0), 5)

            print(f"x={x}, y={y}, w={w}, h={h}")
            send_coordinates_to_arduino(x, y, w ,h)
        
        cv.imshow("Video", frame)

        if cv.waitKey(20) & 0xFF == ord('d'):
            break

        # send_coordinates_to_arduino(x_rotate, y_rotate ,10 ,10)
        # x_rotate += 2
        # y_rotate += 2

        # if(x_rotate > 80):
        #     x_rotate = 0
        
        # if(y_rotate > 180):
        #     y_rotate = 0
        
        # time.sleep(1)
    capture.release()
    cv.destroyAllWindows()


if __name__ == '__main__':
    FaceDetection()