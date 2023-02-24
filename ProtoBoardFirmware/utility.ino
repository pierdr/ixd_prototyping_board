void initSerial()
{
  Serial.begin(115200);
}
void initAnalogSensors()
{
  // initialize the buttons and analog sensors
  for (int i = 0; i < NUM_ANALOG_SENSORS; i++) {
    analogSensorsValues[i] = 0;
  }
}
void initButtons()
{
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);
  pinMode(BUTTON_4, INPUT);
  pinMode(BUTTON_5, INPUT);
}
void initLEDs()
{
  pinMode(BUTTON_1, OUTPUT);
  pinMode(BUTTON_2, OUTPUT);
  pinMode(BUTTON_3, OUTPUT);
  pinMode(BUTTON_4, OUTPUT);
  pinMode(BUTTON_5, OUTPUT);

  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    digitalWrite(BUTTONS[i], HIGH);
    delay(250);
    digitalWrite(BUTTONS[i], LOW);
  }

}
void initSlideSwitch()
{
  pinMode(SLIDE_SWITCH, INPUT);
  if (digitalRead(SLIDE_SWITCH) == HIGH)
  {
    isKeyboard = true;
    Keyboard.begin(KeyboardLayout_en_US);
  }
  else
  {
    isKeyboard = false;
  }
}
void readButtons()
{
  Serial.print("\tBUTTON_1:");
  Serial.print(digitalRead(BUTTON_1));
  delay(1);

  Serial.print("\tBUTTON_2:");
  Serial.print(digitalRead(BUTTON_2));
  delay(1);

  Serial.print("\tBUTTON_3:");
  Serial.print(digitalRead(BUTTON_3));
  delay(1);

  Serial.print("\tBUTTON_4:");
  Serial.print(digitalRead(BUTTON_4));
  delay(1);

  Serial.print("\tBUTTON_5:");
  Serial.print(digitalRead(BUTTON_5));
  delay(1);
}
void readLightSensor() {
  Serial.print("\tLight Sensor:");
  Serial.print(analogRead(PIN_LIGHT_SENSOR));
}
void keyboardUpdateEncoder()
{
  encoderPosition = myEnc.read();
  if (encoderPosition != oldPosition) {
    if (isKeyboard)
    {
      if (oldPosition > encoderPosition)
      {
        Keyboard.write(KEY_LEFT_ARROW);
      }
      else
      {
        Keyboard.write(KEY_RIGHT_ARROW);
      }
    }
    oldPosition = encoderPosition;
  }
}
void keyboardUpdateButtons()
{
  if (isKeyboard)
  {
    for (int i = 0; i < NUM_BUTTONS; i++) {
      buttonStates[i] = digitalRead(BUTTONS[i]);
      if (buttonStates[i] == HIGH && (millis() - lastDebounceTime[i]) > debounceDelay) {
        Keyboard.press(KEYS[i]);
        lastDebounceTime[i] = millis();
      }
      if (buttonStates[i] == LOW) {
        Keyboard.release(KEYS[i]);
      }
    }
  }
}
