void Sensor(void *pvParameters) {
  while (1) {
    //    RotateMPU(90);
    //    while (abs(Offset) > 2) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 15, 16);
    //      xSemaphoreGive(mutex);
    //      RotateMPU(90);
    //    }
    //    bacaIR();
    //    while (distance <= 35) {
    xSemaphoreTake(mutex, portMAX_DELAY);
    navigasiMPU(30);
    GerakDinamis_v2(15, 10, 8, lebarKiri, lebarKanan); //15,10,8
    xSemaphoreGive(mutex);
    //    readSRF04();
    //      if (distance > 35 && (steps == 1 || steps == 3)) { //Klo gamau, coba steps 2 atau 0
    //        Standby();
    //        break;
    //      }
    //    }
    //    RotateMPU(0);
    //    while (abs(Offset) > 2) {
    //      RotateMPU(0);
    //      GerakRotasi(Offset, 15, 18);
    //    }
    //    Standby();
    //    vTaskDelay(500 / portTICK_PERIOD_MS);
    //    RotateMPU(80);
    //    while (abs(Offset) > 2) {
    //      RotateMPU(90);
    //      GerakRotasi(Offset, 15, 18);
    //    }
    //    sdtAcuan = 80;
    //    while (1) {
    //      navigasiMPU(40);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      height = -100;
    //      GerakDinamis_v2(20, 37, 20, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //    }
  }
}

//Logika Rotate dengan MPU
void RotateMPU(int tujuan) { //(-)Putar Kiri, (+)Putar Kanan
  read_MPU();
  vTaskDelay(15 / portTICK_PERIOD_MS);
  Offset = tujuan - yaw;
  if (Offset < -180) {
    Offset = tujuan - yaw + 360;
  }
  if (Offset > 180) {
    Offset = tujuan - yaw - 360;
  }
}

void setAcuan(int selisih) { //NB : selisih (-) => rotate kiri, selisih (+) => rotate kanan
  read_MPU();
  vTaskDelay(15 / portTICK_PERIOD_MS);
  sdtAcuan = yaw + selisih;
  if (sdtAcuan >= 360)sdtAcuan -= 360;
  if (sdtAcuan < 0) sdtAcuan += 360;
}

void RotJarak(uint32_t PING1, uint32_t PING2 ) {
  int jActual = readPING(PING1) - readPING(PING2);
  OffsetJarak = 0 - jActual;
}

void navigasiMPU(int maxStep) {
  read_MPU();
  vTaskDelay(5 / portTICK_PERIOD_MS);
  error = sdtAcuan - yaw; //error (+) => belok kanan, error (-) => belok kiri
  if (error < -180) {
    error = sdtAcuan - yaw + 360;
  }
  if (Offset > 180) {
    error = sdtAcuan - yaw - 360;
  }
  PID_controller();
  if (PID_control >= maxStep )PID_control = maxStep;
  if (PID_control <= maxStep * -1)PID_control = maxStep * -1;
  if (PID_control > 0 ) {//PID_control(+) = belok kanan
    lebarKiri = 0;
    lebarKanan = PID_control;
  }
  else if (PID_control < 0) {//PID_control(-) = belok kiri
    lebarKiri = PID_control;
    lebarKanan = 0;
  }
  else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  time_prev = Time;
  Time = millis();
  dt = (Time - time_prev) / 1000;
  previous_error = error;
  //  Serial.print("E: ");
  //  Serial.println(error);
  //  Serial.print(", Y: ");
  //  Serial.println(yaw);
}

void navigasiPING(int maxStep, uint32_t pingFRONT, uint32_t pingBACK) {

}

int readPING(uint32_t pinData) {
  pinMode(pinData, OUTPUT);
  digitalWrite(pinData, LOW);
  vTaskDelay(1 / portTICK_PERIOD_MS); //2
  digitalWrite(pinData, HIGH);
  vTaskDelay(1 / portTICK_PERIOD_MS); //5
  digitalWrite(pinData, LOW);
  pinMode(pinData, INPUT);
  duration = pulseIn(pinData, HIGH);
  cm = duration / 29 / 2 ;
  return cm;
}

int readSRF04() {
  digitalWrite(TRIG, LOW);
  vTaskDelay(2 / portTICK_PERIOD_MS);
  digitalWrite(TRIG, HIGH);
  vTaskDelay(3 / portTICK_PERIOD_MS);
  digitalWrite(TRIG, LOW);
  int jarak = pulseIn(ECHO, HIGH);
  jarak = jarak / 58;
  return jarak;
}


void PID_controller() {
  //Proportional control
  P_control = kp * error;
  //Derivative control
  if (dt < 0.000000001) {
    dt = 0.000000001;
  }
  D_control = kd * ((error - previous_error) / dt);
  //Summing PID
  PID_control = (P_control + D_control) * 10; //Coba saja dikali 10 atau tidak (Besaran Output PID Controller)
}

void resetPID() {
  P_control = 0;
  D_control = 0;
  error = 0;
  previous_error = 0;
  PID_control = 0;
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


//====Logika Baca Jarak Sambil Jalan====//
//xSemaphoreTake(mutex, portMAX_DELAY);
//readPING(leftBack);
//readPING(leftFront);
//GerakDinamis(15, 15, 8, 0);
//xSemaphoreGive(mutex);
//bacaIR();


//===Logika Kamera===//
//    read_maix();
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    GerakDinamis(20, 20, 20, 0);
//    xSemaphoreGive(mutex);
//    bacaIR();
//NB : Baca IR ditaruh diluar mutex, gerakannya jadi agak patah patah tapi ga terlalu kelihatan dan lebih cepat geraknya

////====Logika Body Maju Ambil Korban====//
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    BodyMaju(60);
//    xSemaphoreGive(mutex);
//    if (!statusGerak) {
//      while (1) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        theta = 180;
//        xFR0 = -65,  yFR0 = 15, xFR1 = -65, yFR1 = 15, zFR0 = 0, zFRp = 0;
//        //KIRI TENGAH (LM)
//        xLM0 = 80, yLM0 = -50, xLM1 = 80, yLM1 = -50, zLM0 = 0, zLMp = 0;
//        //KANAN BELAKANG (BR)
//        xBR0 = -65, yBR0 = -100, xBR1 = -65,  yBR1 = -100, zBR0 = 0, zBRp = 0;
//        //KIRI DEPAN (FL)
//        xFL0 = 65, yFL0 = 15, xFL1 = 65,  yFL1 = 15, zFL0 = 0, zFLp = 0;
//        //KANAN TENGAH (RM)
//        xRM0 = -80, yRM0 = -50, xRM1 = -80, yRM1 = -50, zRM0 = 0, zRMp = 0;
//        //KIRI BELAKANG (BL)
//        xBL0 = 65, yBL0 = -100, xBL1 = 65,  yBL1 = -100, zBL0 = 0, zBLp = 0;
//        xSemaphoreGive(mutex);
//      }
//    }

//==Gerakan Jalan Pecah 1==//
//    navigasiMPU(0, 20);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    height = -100;
//    GerakDinamis_v2(20, 35, 22, lebarKiri, lebarKanan);
//    xSemaphoreGive(mutex);

//==Logika Standby Saat Sedang Berjalan==//
//if (NilaiSensor >= x && (steps == 1 || steps == 3)) { //Klo gamau, coba steps 2 atau 0
//  Standby();
//}

//===Logika Navigasi dengan acuan MPU===//
//    navigasiMPU(0, 18);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    GerakDinamis_v2(18, 37, 24, lebarKiri, lebarKanan);
//    xSemaphoreGive(mutex);

//===Logika Mengatur Jumlah Step Langkah===//
//jmlhStep = 0;
//while (jmlhStep < 10) {
//  navigasiMPU(0, 18);
//  xSemaphoreTake(mutex, portMAX_DELAY);
//  GerakDinamis_v2(18, 37, 24, lebarKiri, lebarKanan);
//  if (steps == 0)jmlhStep++;
//  xSemaphoreGive(mutex);
//}
