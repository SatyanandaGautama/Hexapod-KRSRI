void Sensor(void *pvParameters) {
  while (1) {
    GerakDinamis(15, 15, 8, 0);
    Serial.println("P1");
    readPING(leftBack);
    Serial.println("P2");
    readPING(leftFront);
    bacaIR();
  }
}

void bacaIR() {
  int distance = sensor.readRangeContinuousMillimeters();
  int cm = distance / 10;
  Serial.println("IR");
  vTaskDelay(7 / portTICK_PERIOD_MS);
  //  Serial.print("Distance: ");
  //  Serial.print(cm);
  //  if (sensor.timeoutOccurred()) {
  //    Serial.print(" TIMEOUT");
  //  }
}

//Logika Rotate
//(-)Putar Kiri, (+)Putar Kanan
void RotateMPU(int tujuan) {
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
  //  error = jarak[0] - 5;
  PIDJarak();
  longStep = pid_output;
  if (longStep >= sdtbelok)longStep = sdtbelok;
  else if (longStep <= sdtbelok * -1)longStep = sdtbelok * -1;
  //  Serial.print("error = ");
  //  Serial.println(error);
  //  Serial.print("longStep = ");
  //  Serial.println(longStep);
}

int readPING(uint32_t pinData) {
  pinMode(pinData, OUTPUT);
  digitalWrite(pinData, LOW);
  vTaskDelay(2 / portTICK_PERIOD_MS); //2
  digitalWrite(pinData, HIGH);
  vTaskDelay(5 / portTICK_PERIOD_MS); //5
  digitalWrite(pinData, LOW);
  pinMode(pinData, INPUT);
  duration = pulseIn(pinData, HIGH);
  cm = duration / 29 / 2 ;
  jarak = cm;
  return jarak;
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

//====Rotate Logic====//
//    if (rot == true) {
//      RotateMPU(90);
//      while (abs(Offset) > 1) {
//        RotateMPU(90);
//        GerakRotasi(Offset, 20, 22);
//      }
//      Standby();
//      read_MPU();
//      Serial.print("YAW Putar 1 : ");
//      Serial.println(yaw);
//      vTaskDelay(1000 / portTICK_PERIOD_MS);
//      RotateMPU(180);
//      while (abs(Offset) > 1) {
//        RotateMPU(180);
//        GerakRotasi(Offset, 20, 22);
//      }
//      Standby();
//      read_MPU();
//      Serial.print("YAW Putar 2 : ");
//      Serial.println(yaw);
//      vTaskDelay(1000 / portTICK_PERIOD_MS);
//      RotateMPU(270);
//      while (abs(Offset) > 1) {
//        RotateMPU(270);
//        GerakRotasi(Offset, 20, 22);
//      }
//      rot = false;
//    }
//    Standby();
//    read_MPU();
//    Serial.print("YAW Putar 3 : ");
//    Serial.println(yaw);
