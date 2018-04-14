#define LIGHT_SENSOR0 A0
#define LIGHT_SENSOR1 A1
#define LIGHT_SENSOR2 A2
#define LIGHT_SENSOR3 A3
#define LIGHT_SENSOR4 A4
#define LIGHT_SENSOR5 A5

const int id = 0;

String inputString = "";
boolean isStringComplete = false;

boolean isSensing = false;
boolean isSendId = false;


void setup() {
  Serial.begin(115200);
}


void loop() {

  if (isStringComplete) {
    if (inputString == "b" || inputString == "B") {
      isSensing = true;
    }
    else if (inputString == "e" || inputString == "E") {
      isSensing = false;
    }
    else if (inputString == "i" || inputString == "I") {
      isSendId = true;
    }
    inputString = "";
    isStringComplete = false;
  }

  if (isSendId) {
    Serial.print("ID");
    Serial.print(",");
    Serial.println(id);
    isSendId = false;
  }

  if (isSensing) {
    int sensorValue0 = analogRead(LIGHT_SENSOR0);
    int sensorValue1 = analogRead(LIGHT_SENSOR1);
    int sensorValue2 = analogRead(LIGHT_SENSOR2);
    int sensorValue3 = analogRead(LIGHT_SENSOR3);
    int sensorValue4 = analogRead(LIGHT_SENSOR4);
    int sensorValue5 = analogRead(LIGHT_SENSOR5);
    Serial.print("VAL");
    Serial.print(",");
    Serial.print(sensorValue0);
    Serial.print(",");
    Serial.print(sensorValue1);
    Serial.print(",");
    Serial.print(sensorValue2);
    Serial.print(",");
    Serial.print(sensorValue3);
    Serial.print(",");
    Serial.print(sensorValue4);
    Serial.print(",");
    Serial.println(sensorValue5);
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
