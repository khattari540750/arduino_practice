//! system
boolean isSensing = false;

//! LED
#define LED_PIN 17
bool blinkState = false;


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

  int inputchar;
  inputchar = Serial1.read();

  if (inputchar != -1 ) {
    switch (inputchar) {
      case 'u':
        isSensing = true;
        break;
      case 'i':
        isSensing = false;
        break;
    }
  } else {
  }

  //! sensing start
  if (isSensing) {
    unsigned int val0 = analogRead(A0);
    unsigned int val1 = analogRead(A1);
    unsigned int val2 = analogRead(A2);
    unsigned int val3 = analogRead(A3);
    Serial1.print(val0);
    Serial1.print(',');
    Serial1.print(val1);
    Serial1.print(',');
    Serial1.print(val2);
    Serial1.print(',');
    Serial1.println(val3);

    //! blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
  } else {
    digitalWrite(LED_PIN, true);
  }
  delay(10);
}
