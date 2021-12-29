/*State detection at once only. button configured as pull-up which is Active Low Logic*/

#define pinButton 4
#define pinLed 2
bool previous_state;

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  previous_state = digitalRead(pinButton);
}

void loop() {
  bool new_state = digitalRead(pinButton);
  if (new_state == LOW && previous_state == HIGH) {
    Serial.println("PRESSED");
    digitalWrite(pinLed, HIGH);
  } if (new_state == HIGH && previous_state == LOW) {
    Serial.println("RELEASED");
    digitalWrite(pinLed, LOW);
  }
  previous_state = new_state;
  delay(20);

}
