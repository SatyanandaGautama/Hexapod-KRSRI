void bacaIR() {
  int cm = sensor.readRangeContinuousMillimeters() / 10;
  //  Serial.println("IR");
  //  Serial.print("Distance: ");
  //  Serial.println(cm);
  vTaskDelay(2 / portTICK_PERIOD_MS);
  //  if (sensor.timeoutOccurred()) {
  //    Serial.print(" TIMEOUT");
  //  }
}
