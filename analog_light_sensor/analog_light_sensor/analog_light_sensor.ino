// defines
#define LIGHT_SENSOR0 A0
#define LIGHT_SENSOR1 A1
#define LIGHT_SENSOR2 A2
#define LIGHT_SENSOR3 A3
#define LIGHT_SENSOR4 A4
#define LIGHT_SENSOR5 A5

// serial event variables
String inputString = "";
boolean isStringComplete = false;

String mode = "";
int threshold[6] ={1000,1000,1000,1000,1000,1000};


void setup() {
  Serial.begin(115200);
}


void loop() {

  if (isStringComplete) {
    if (inputString == "b" || inputString == "B") {
      mode = "isSensing";
    }
    else if (inputString == "e" || inputString == "E") {
      mode = "";
    }
    else if (inputString == "i" || inputString == "I") {
      mode = "getId";
    }
    inputString = "";
    isStringComplete = false;
  }

  
}


void changeThreshold(int lightId, int threshold) {
  if(lightId >= 0 && lightId < 6) {
  }
}


void changeThreshold(int threshold) {
  
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
