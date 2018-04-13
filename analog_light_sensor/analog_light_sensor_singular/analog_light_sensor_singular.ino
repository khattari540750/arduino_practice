#define LIGHT_SENSOR A0

String inputString = "";
boolean isStringComplete = false;

boolean isSensing = false;


void setup() {
  Serial.begin(115200);
}


void loop() {
  if (isStringComplete) {
    if (inputString == "P" || inputString == "p") {
      isSensing = true;
    }
    else if (inputString == "S" || inputString == "s") {
      isSensing = false;
    }
    inputString = "";
    isStringComplete = false;
  }

  if (isSensing) {
    int sensorValue = analogRead(LIGHT_SENSOR);
    Serial.println(sensorValue);
    delay(10);
  }
}


void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n' || inChar == '\r') {
      isStringComplete = true;
    }
    else {
      inputString += inChar;
    }
  }
}
