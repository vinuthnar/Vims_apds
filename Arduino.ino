#define LED_PIN 6
#define LDR_PIN A0
#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 7

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600); // Communication with Python
}

void loop() {
  // VMIS: Control LED margin lights based on visibility
  int lightIntensity = analogRead(LDR_PIN);
  if (lightIntensity < 300) {  
    digitalWrite(LED_PIN, HIGH); // Turn on LED in low-light conditions
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // APDS: Detect Potholes
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;  

  if (distance < 10) { // Pothole detected
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("POTHOLE_DETECTED");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // APDS: Listen for Python alert for animal detection
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    if (receivedChar == 'A') { // 'A' signal from Python for animal detected
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("ANIMAL_DETECTED");
      delay(2000); // Alert duration
      digitalWrite(BUZZER_PIN, LOW);
    }
  }

  delay(500);
}
