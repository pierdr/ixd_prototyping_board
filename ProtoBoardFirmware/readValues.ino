void serialUpdateButtons()
{
  // Check the buttons and update their states in the buttonsArray
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int buttonState = digitalRead(BUTTONS[i]);
    if (buttonStates[i] != buttonState && (millis() - lastDebounceTime[i]) > debounceDelay) {
      buttonStates[i] = buttonState;
      sendSerialMessage();
      lastDebounceTime[i] = millis();
    }
  }
}

void serialUpdateAnalogSensors()
{
  // Check the analog sensors and update their values in the analogSensorsArray
  for (int i = 0; i < NUM_ANALOG_SENSORS; i++) {
    int sensorValue = analogRead(ANALOG_SENSORS[i]);
    if (analogSensorsValues[i] != sensorValue) {
      analogSensorsValues[i] = sensorValue;
      sendSerialMessage();
    }
  }
}
void serialUpdateEncoder()
{
  encoderPosition = myEnc.read();
  if (encoderPosition != oldPosition) {
    sendSerialMessage();
  }
  oldPosition = encoderPosition;
}
