void Sensor(void *pvParameters) {
  while (1) {
    if (rot == true) {
      Rotate(90);
      while (abs(Offset) > 1) {
        Rotate(90);
        GerakRotasi(Offset, 20, 22);
      }
      Standby();
      read_MPU();
      Serial.print("YAW Putar 1 : ");
      Serial.println(yaw);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      Rotate(180);
      while (abs(Offset) > 1) {
        Rotate(180);
        GerakRotasi(Offset, 20, 22);
      }
      Standby();
      read_MPU();
      Serial.print("YAW Putar 2 : ");
      Serial.println(yaw);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      Rotate(270);
      while (abs(Offset) > 1) {
        Rotate(270);
        GerakRotasi(Offset, 20, 22);
      }
      rot = false;
    }
    Standby();
    read_MPU();
    readPING(leftBack);
    Serial.print("YAW Putar 3 : ");
    Serial.println(yaw);
    vTaskDelay(5 / portTICK_PERIOD_MS);
  }
}

//Logika Rotate
//(-)Putar Kiri, (+)Putar Kanan
void Rotate(int tujuan) {
  read_MPU();
  Serial.print("YAW: ");
  Serial.println(yaw);
  Offset = tujuan - yaw;
  if (abs(Offset) > 180) {
    Offset = tujuan - yaw - 360;
  }
  //  Serial.print("OFFSET: ");
  //  Serial.println(Offset);
}

void jalanLurus() {
  float sdtbelok = 5;
  //  ReadPING_1();
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
void readPING(int pinData) {
  pinMode(pinData, OUTPUT);
  digitalWrite(pinData, LOW);
  delay(7);
  digitalWrite(pinData, HIGH);
  delay(7);
  digitalWrite(pinData, LOW);
  pinMode(pinData, INPUT);
  duration = pulseIn(pinData, HIGH);
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
