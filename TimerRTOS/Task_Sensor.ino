void Sensor(void *pvParameters) {
  while (1) {
    xSemaphoreTake(mutex, portMAX_DELAY);
    GerakDinamis(15, 10, 10, 0);
    xSemaphoreGive(mutex);
  }
}

//Logika Rotate
//(-)Putar Kiri, (+)Putar Kanan
void RotateMPU(int tujuan) {
  read_MPU();
  vTaskDelay(15 / portTICK_PERIOD_MS);
  //  Serial.print("YAW: ");
  //  Serial.println(yaw);
  Offset = tujuan - yaw;
  if (Offset < -180) {
    Offset = tujuan - yaw + 360;
  }
  if (Offset > 180) {
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


//===Logika Baca Jarak Sambil Jalan===//
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    readPING(leftBack);
//    readPING(leftFront);
//    GerakDinamis(15, 15, 8, 0);
//    xSemaphoreGive(mutex);
//    bacaIR();


//===Logika Kamera===//
//    read_maix();
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    GerakDinamis(20, 20, 20, 0);
//    xSemaphoreGive(mutex);
//    bacaIR();
//NB : Baca IR ditaruh diluar mutex, gerakannya jadi agak patah patah tapi ga terlalu kelihatan dan lebih cepat geraknya
