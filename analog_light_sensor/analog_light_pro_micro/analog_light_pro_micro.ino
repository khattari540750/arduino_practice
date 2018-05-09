//! deviceID ( please select num )
const byte deviceId = 1;

//! system variables
boolean isSensing = false;

//! serial read variables
String inputString = "";
boolean isStringComplete = false;

//! LED variables
#define LED_PIN 17
bool blinkState = false;

//! packet structure for InvenSense teapot demo
uint8_t sendPacket[6] = { deviceId, 0, 0, 0, 0, '\n' };


//! =============================================================================
//! ===                                SETUP                                  ===
//! =============================================================================

void setup() {
  Serial1.begin(38400);
}


//! =============================================================================
//! ===                                LOOP                                   ===
//! =============================================================================

void loop() {

  //! get serial read
  while (Serial1.available()) {
    char inChar = (char)Serial1.read();
    if (inChar == '\n' || inChar == '\r') {
      isStringComplete = true;
    }
    else {
      inputString += inChar;
    }
  }
  if (isStringComplete) {
    if (inputString == "SENSING_START" || inputString == "sensing_start") {
      isSensing = true;
    }
    else if (inputString == "SENSING_STOP" || inputString == "sensing_stop") {
      isSensing = false;
    }
    inputString = "";
    isStringComplete = false;
  }

  //! sensing start
  if (isSensing) {
    unsigned int val0 = analogRead(A0);
    unsigned int val1 = analogRead(A1);
    unsigned int val2 = analogRead(A2);
    unsigned int val3 = analogRead(A3);
    
    val0 = map(val0, 0, 1023, 0, 255);
    val1 = map(val1, 0, 1023, 0, 255);
    val2 = map(val2, 0, 1023, 0, 255);
    val3 = map(val3, 0, 1023, 0, 255);

    sendPacket[1] = val0;
    sendPacket[2] = val1;
    sendPacket[3] = val2;
    sendPacket[4] = val3;
    Serial1.write(sendPacket, 6);

    //! blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
  } else {
    digitalWrite(LED_PIN, true);
  }
  delay(10);
}
