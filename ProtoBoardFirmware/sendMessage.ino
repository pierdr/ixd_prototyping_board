
void sendSerialMessage() {
  if (millis() - lastSentSerial > serialDelay)
  {
    // send the button states
    Serial.print("B");
    for (int i = 0; i < NUM_BUTTONS; i++) {
      Serial.print(buttonStates[i]);
      Serial.print(",");
    }
  
    // send the analog sensor values
    Serial.print("A");
    for (int i = 0; i < NUM_ANALOG_SENSORS; i++) {
      Serial.print(analogSensorsValues[i]);
      Serial.print(",");
    }
  
    // send the encoder value
    Serial.print("E");
    Serial.println(encoderPosition);
    lastSentSerial = millis();
  }
}
