 **Vehicle Margin Indicating System (VMIS) & Animal & Pothole Detection System (APDS)**

**Road Safety System – VMIS & APDS**  
 
Road accidents caused by **poor visibility, unexpected obstacles, and deteriorating road conditions** pose serious risks. This project introduces **two safety systems** to reduce accident rates:  

1. **Vehicle Margin Indicating System (VMIS)** – Uses **margin-indicating lights** to improve vehicle visibility in foggy or low-light conditions, helping prevent rear-end collisions.  
2. **Animal & Pothole Detection System (APDS)** – Utilizes **infrared cameras, ultrasonic sensors, and LiDAR** to detect animals and potholes in real time, providing instant alerts to the driver.  

**Features**  
✅ VMIS enhances vehicle visibility and prevents rear-end collisions.  
✅ APDS detects potholes and animals, sending real-time alerts.  
✅ Uses **infrared cameras, ultrasonic sensors, and LiDAR** for accuracy.  
✅ Can be integrated into **modern vehicles** for enhanced safety.  


**Technologies Used**  
**Hardware:** Infrared Cameras, Ultrasonic Sensors, LiDAR, Arduino  
**Software:** Arduino IDE (for microcontroller), Python (for image processing & alerts)  
**Libraries:** OpenCV (for object detection), NumPy, Serial Communication  


## **System Architecture**  

### **1. Vehicle Margin Indicating System (VMIS)**
- **Purpose:** Enhances vehicle visibility in **low-light/foggy** conditions.  
- **Working:** LED strip lights on the vehicle**illuminate its boundaries**, making it more visible to others.  
- **Components Used:**  
  - Arduino  
  - LED Strips  
  - LDR (Light Dependent Resistor) for detecting low visibility  

**2. Animal & Pothole Detection System (APDS)**
**Purpose:** Detects **animals & potholes** on roads using **infrared cameras & ultrasonic sensors**.  
**Working:**  
  - **Camera captures the road** → Uses OpenCV for **animal detection**  
  - **Ultrasonic sensor detects potholes** → Alerts driver if depth is significant  
  - **LiDAR (optional)** for more accurate object detection.

**Videos output link**

https://drive.google.com/drive/folders/1S1JBAdjyYV650NgbE4GMEKWBHpaqtt_u


**Output / Expected Results**

✅ **VMIS**  
- LED lights turn **ON in low-light** conditions and **OFF in daylight.**  

✅ **APDS**  
- **Animal detection**: Displays a **green box** around detected animals.  
- **Pothole detection**: Alerts driver via **buzzer** when pothole is detected.  

