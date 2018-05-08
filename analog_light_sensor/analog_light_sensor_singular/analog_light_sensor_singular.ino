#define LIGHT_SENSOR A0

String inputString = "";
boolean isStringComplete = false;

boolean isSensing = false;


void setup() {
  Serial.begin(115200);
}


void loop() {

   Serial.println("aaaa");
    delay(1);
  
  if (isStringComplete) {
    if (inputString == "B" || inputString == "b") {
      isSensing = true;
    }
    else if (inputString == "E" || inputString == "e") {
      isSensing = false;
    }
    inputString = "";
    isStringComplete = false;
  }

  if (isSensing) {
    int sensorValue = analogRead(LIGHT_SENSOR);
    Serial.println(sensorValue);
    delay(1);
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
