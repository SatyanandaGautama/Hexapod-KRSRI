void Sensor(void *pvParameters) {
  while (1) {
    RotateMPU(90);
    while (abs(Offset) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 20, 18);
      xSemaphoreGive(mutex);
      RotateMPU(90);
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    readSRF04();
    while (jarak < 56 || (steps == 0 || steps == 2)) {
      if (Sensors) {
        navigasiMaju(15, 30, rightFront, rightBack);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakDinamis(15, 15, 8, lebarKiri, lebarKanan);
        xSemaphoreGive(mutex);
      }
      else {
        readSRF04();
        xSemaphoreTake(mutex, portMAX_DELAY);
        Sensors = true;
        xSemaphoreGive(mutex);
      }
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Standby();
    xSemaphoreGive(mutex);
    RotateMPU(0);
    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
      RotateMPU(0);
      GerakRotasi(Offset, 18, 18);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Standby();
    xSemaphoreGive(mutex);
    RotateMPU(90);
    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
      RotateMPU(90);
      GerakRotasi(Offset, 18, 18);
    }
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 15, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    sdtAcuan = yawSebelum;
    while (sdtAcuan == yawSebelum) {
      read_MPU();
      vTaskDelay(15 / portTICK_PERIOD_MS);
      sdtAcuan = yaw;
    }
    sdtAcuan = yaw;
    while (pitch < 16) {
      height = -100;
      navigasiMPU(44);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(22, 42, 30, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
    }
    height = -95;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 15, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    j2 = readPING(rightFront);
    while ( j2 > 17) {//Geser Kanan
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 20, 20, 0, 0, 0);
      xSemaphoreGive(mutex);
      j2 = readPING(rightFront);
      offsets = setpoint - j2;
    }
    while (j2 < 13) {//Geser Kiri
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 20, 20, 0, 0, 0);
      xSemaphoreGive(mutex);
      j2 = readPING(rightFront);
      offsets = setpoint - j2;
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 15, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    sdtAcuan = yawSebelum;
    while (sdtAcuan == yawSebelum) {
      read_MPU();
      vTaskDelay(15 / portTICK_PERIOD_MS);
      sdtAcuan = yaw;
    }
    sdtAcuan = yaw;
    while (pitch > 3 && stateMPU == false) {
      navigasiMPU(40);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 25, 18, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch <= 3) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        stateMPU = true;
        xSemaphoreGive(mutex);
        break;
      }
    }
    read_MPU();
    while (pitch <= 3 && stateMPU == true) {
      while (1) {
        Serial.println("S");
        Standby();
      }
    }
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
  xSemaphoreTake(mutex, portMAX_DELAY);
  sdtAcuan = yaw + selisih;
  if (sdtAcuan >= 360)sdtAcuan -= 360;
  if (sdtAcuan < 0) sdtAcuan += 360;
  xSemaphoreGive(mutex);
}

void RotJarak(uint32_t PING1, uint32_t PING2 ) {
  OffsetJarak = (readPING(PING1) - readPING(PING2)) * 1.7;
}

void navigasiMPU(int maxStep) {
  read_MPU();
  vTaskDelay(15 / portTICK_PERIOD_MS);
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

void navigasiMaju(int setpoint, int maxStep, uint32_t pingFront, uint32_t pingBack) {
  int j1 = readPING(pingFront);
  j2 = readPING(pingBack);
  error = j1 - j2;
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  if (error != 0) { //error (+) => belok kanan, error (-) => belok kiri
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
    //    Serial.print("E: ");
    //    Serial.println(error);
  }
  else if ( error == 0 && (j1 >= 20 || j1 <= 10)) {
    offsets = setpoint - j1;
    while ( j1 > setpoint + 2) {//Geser Kanan
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 20, 20, 0, 0, 0);
      xSemaphoreGive(mutex);
      j1 = readPING(pingFront);
      offsets = setpoint - j1;
    }
    while (j1 < setpoint - 2) {//Geser Kiri
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 20, 20, 0, 0, 0);
      xSemaphoreGive(mutex);
      j1 = readPING(pingFront);
      offsets = setpoint - j1;
    }
  }
}

void navigasiMundur(int setpoint, int maxStep, uint32_t pingFront, uint32_t pingBack) {
  int j1 = readPING(pingFront);
  j2 = readPING(pingBack);
  error = j1 - j2;
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  if (error != 0) { //error (+) => belok kanan, error (-) => belok kiri
    PID_controller();
    if (PID_control >= maxStep )PID_control = maxStep;
    if (PID_control <= maxStep * -1)PID_control = maxStep * -1;
    if (PID_control > 0 ) {//PID_control(+) = belok kanan
      lebarKiri = PID_control;
      lebarKanan = 0;
    }
    else if (PID_control < 0) {//PID_control(-) = belok kiri
      lebarKiri = 0;
      lebarKanan = PID_control;
    }
    else {
      lebarKiri = 0;
      lebarKanan = 0;
    }
    time_prev = Time;
    Time = millis();
    dt = (Time - time_prev) / 1000;
    previous_error = error;
    //    Serial.print("E: ");
    //    Serial.println(error);
  }
  //  else if ( error == 0 && (j1 >= 20 || j1 <= 10)) {
  //    offsets = setpoint - j1;
  //    while ( j1 > setpoint + 2) {//Geser Kanan
  //      xSemaphoreTake(mutex, portMAX_DELAY);
  //      GerakGeser(offsets, 20, 20, 0, 0, 0);
  //      xSemaphoreGive(mutex);
  //      j1 = readPING(pingFront);
  //      offsets = setpoint - j1;
  //    }
  //    while (j1 < setpoint - 2) {//Geser Kiri
  //      xSemaphoreTake(mutex, portMAX_DELAY);
  //      GerakGeser(offsets, 20, 20, 0, 0, 0);
  //      xSemaphoreGive(mutex);
  //      j1 = readPING(pingFront);
  //      offsets = setpoint - j1;
  //    }
  //  }
}

void navigasiKanan(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  int j1 = readPING(pingFront);
  j2 = readPING(pingBack);
  error = j1 - j2;
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  PID_controller();
  if (PID_control >= maxStep )PID_control = maxStep;
  if (PID_control <= maxStep * -1)PID_control = maxStep * -1;
  if (PID_control > 0 ) {//PID_control(+) = belok kanan
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  }
  else if (PID_control < 0) {//PID_control(-) = belok kiri
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  }
  else {
    lebarTengah = 0;
    lebarKiri = 0;
    lebarKanan = 0;
  }
  time_prev = Time;
  Time = millis();
  dt = (Time - time_prev) / 1000;
  previous_error = error;
  //    Serial.print("E: ");
  //    Serial.println(error);
}

void navigasiKiri(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  int j1 = readPING(pingFront);
  j2 = readPING(pingBack);
  error = j1 - j2;
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  PID_controller();
  if (PID_control >= maxStep )PID_control = maxStep;
  if (PID_control <= maxStep * -1)PID_control = maxStep * -1;
  if (PID_control > 0 ) {//PID_control(+) = belok kanan
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  }
  else if (PID_control < 0) {//PID_control(-) = belok kiri
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  }
  else {
    lebarTengah = 0;
    lebarKiri = 0;
    lebarKanan = 0;
  }
  time_prev = Time;
  Time = millis();
  dt = (Time - time_prev) / 1000;
  previous_error = error;
  //    Serial.print("E: ");
  //    Serial.println(error);
}

int readPING(uint32_t pinData) {
  pinMode(pinData, OUTPUT);
  digitalWrite(pinData, LOW);
  vTaskDelay(2 / portTICK_PERIOD_MS);
  digitalWrite(pinData, HIGH);
  vTaskDelay(3 / portTICK_PERIOD_MS);
  digitalWrite(pinData, LOW);
  pinMode(pinData, INPUT);
  duration = pulseIn(pinData, HIGH);
  cm = duration / 29 / 2 ;
  return cm;
}

void readSRF04() {
  digitalWrite(TRIG, LOW);
  vTaskDelay(1 / portTICK_PERIOD_MS);
  digitalWrite(TRIG, HIGH);
  vTaskDelay(2 / portTICK_PERIOD_MS);
  digitalWrite(TRIG, LOW);
  jarak = pulseIn(ECHO, HIGH);
  jarak = jarak / 58;
  //  Serial.println(jarak);
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

//====Logika Navigasi PING + Baca IR====//
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    navigasiPING(14, 30, rightFront, rightBack);
//    GerakDinamis(15, 20, 16, lebarKiri, lebarKanan);
//    xSemaphoreGive(mutex);
//    bacaIR();

//===Logika Kamera===//
//    read_maix();
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    GerakDinamis(20, 20, 20, 0);
//    xSemaphoreGive(mutex);
//    bacaIR();
//NB : Baca IR ditaruh diluar mutex, gerakannya jadi agak patah patah tapi ga terlalu kelihatan dan lebih cepat geraknya

//====Logika Body Maju Ambil Korban====//
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
//    GerakDinamis(20, 35, 22, lebarKiri, lebarKanan);
//    xSemaphoreGive(mutex);

//==Logika Standby Saat Sedang Berjalan==//
//if (NilaiSensor >= x && (steps == 1 || steps == 3)) { //Klo gamau, coba steps 2 atau 0
//  Standby();
//}

//===Logika Navigasi dengan acuan MPU===//
//    navigasiMPU(0, 18);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    GerakDinamis(18, 37, 24, lebarKiri, lebarKanan);
//    xSemaphoreGive(mutex);

//===Logika Mengatur Jumlah Step Langkah===//
//    jmlhStep = 0;
//    while (jmlhStep < 6) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      if (steps == 0 && statusGerak == false) {
//        jmlhStep++;
//      }
//      GerakDinamis(20, 20, 26, 0, 0);
//      xSemaphoreGive(mutex);
//    }
//}

//===Logika Rotate Pakai Jarak Buat Ngelurusin Orientasi===//
//RotJarak(rightFront, rightBack);
//while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//  xSemaphoreTake(mutex, portMAX_DELAY);
//  GerakRotasi(OffsetJarak, 28, 22);
//  RotJarak(rightFront, rightBack);
//  xSemaphoreGive(mutex);
//}

//===Logika Jalan Pakai Jarak Buat Ngelurusin Orientasi===//
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    navigasiPING(15, 30, rightFront, rightBack);
//    GerakDinamis(15, 20, 18, lebarKiri, lebarKanan);
//    xSemaphoreGive(mutex);

//===Test Logika di Arena===//


//===LOGIKA NAVIGASI PING + SRF04===//
//    readSRF04();
//    while (jarak < 53 || (steps == 0 || steps == 2)) {
//      if (Sensors) {
//        navigasiPING(14, 30, rightFront, rightBack);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakDinamis(15, 27, 16, lebarKiri, lebarKanan);
//        xSemaphoreGive(mutex);
//      }
//      else {
//        readSRF04();
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        Sensors = true;
//        xSemaphoreGive(mutex);
//      }

//===LOGIKA NAVIGASI MPU + SRF04===//
//    if (Sensors) {
//      navigasiMPU(36);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(18, 30, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//    }
//    else {
//      readSRF04();
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      Sensors = true;
//      xSemaphoreGive(mutex);
//    }
