import cv2
import serial
import time

# Initialize Serial Communication with Arduino
arduino = serial.Serial('COM3', 9600) # Change COM port based on your setup
time.sleep(2) # Allow time for connection

# Load pre-trained Haarcascade for animal detection
animal_cascade = cv2.CascadeClassifier('haarcascade_frontalcatface.xml') # Example animal detector

# Start video capture
cap = cv2.VideoCapture(0)

def detect_animal(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    animals = animal_cascade.detectMultiScale(gray, 1.1, 4)

    for (x, y, w, h) in animals:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 3)
        print("Animal Detected! Sending alert to Arduino...")
        arduino.write(b'A') # Send alert signal to Arduino

    return frame

while True:
    ret, frame = cap.read()
    if not ret:
        break
    
    frame = detect_animal(frame)
    cv2.imshow('Animal Detection', frame)

    # Listen for pothole alerts from Arduino
    if arduino.inWaiting() > 0:
        alert_msg = arduino.readline().decode('utf-8').strip()
        if alert_msg == "POTHOLE_DETECTED":
            print("⚠️ Pothole detected! Alerting driver...")

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
