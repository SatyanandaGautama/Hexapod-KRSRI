void Sensor(void *pvParameters) {
  while (1) {
    GerakRotasi(20, 20, 22);                           //15 & 14//17 & 18 (lumayan stabil)
    vTaskDelay(5 / portTICK_PERIOD_MS);
  }
}
//Logika Rotate
//offset = tujuan - sekarang
//jika offset > 180
//offset = tujuan - sekarang - 360
//- kiri, + kanan
void jalanLurus() {
  float sdtbelok = 5;
  ReadPING_1();
  error = jarak[0] - 5;
  PIDJarak();
  longStep = pid_output;
  if (longStep >= sdtbelok)longStep = sdtbelok;
  else if (longStep <= sdtbelok * -1)longStep = sdtbelok * -1;
  //  Serial.print("error = ");
  //  Serial.println(error);
  //  Serial.print("longStep = ");
  //  Serial.println(longStep);
}
void ReadPING_1() {
  pinMode(PE12, OUTPUT);
  digitalWrite(PE12, LOW);
  delay(7);
  digitalWrite(PE12, HIGH);
  delay(7);
  digitalWrite(PE12, LOW);
  pinMode(PE12, INPUT);
  duration = pulseIn(PE12, HIGH);
  cm = duration / 29 / 2 ;
  jarak[0] = cm;
  //  Serial.print("PING 1 : ");
  //  Serial.println(jarak[0]);
}
void PIDJarak() {
  P_control = kp * error;
  I_control = I_control + (ki * error);
  if (I_control > 3) {
    I_control = 3;
  }
  else if (I_control < -3) {
    I_control = -3;
  }
  D_control = kd * (error - previous_error);
  pid_output = P_control + I_control + D_control;
  previous_error = error;
}
void resetPID() {
  P_control = 0;
  I_control = 0;
  D_control = 0;
  error = 0;
  previous_error = 0;
  pid_output = 0;
}
