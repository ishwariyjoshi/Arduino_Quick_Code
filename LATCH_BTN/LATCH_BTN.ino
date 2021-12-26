
#define BTN_PIN  15
#define LED_BUILTIN 2


// Variables will change:
bool lastState = LOW;      // the previous state from the input pin
bool currentState;         // the current reading from the input pin
bool ledState = LOW;       // the current LED state

void setup() {

  Serial.begin(9600);

  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // read the state of the the input pin:
  currentState = digitalRead(BTN_PIN);
  delay(10);
  currentState = digitalRead(BTN_PIN);
  
  if (lastState == LOW && currentState == HIGH) {
    // toggle LED state
    if (ledState == LOW)
      ledState = HIGH;
    else if (ledState == HIGH)
      ledState = LOW;

    // control LED
    digitalWrite(LED_BUILTIN, ledState);
    Serial.println(ledState);
  }

  // save the the last state
  lastState = currentState;
}
