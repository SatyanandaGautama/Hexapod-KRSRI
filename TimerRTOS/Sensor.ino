void RotateMPU(int selisih = 0, bool rot = false) { //(-)Putar Kiri, (+)Putar Kanan
  if (rot) {
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    tujuan = yaw + selisih;
    if (tujuan >= 360)tujuan -= 360;
    if (tujuan < 0) tujuan += 360;
  }
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

void RotJarak(uint32_t PING1, uint32_t PING2 ) {
  OffsetJarak = (readPING(PING1) - readPING(PING2)) * 1.7;
}

//void RotJarak(uint32_t PING1, uint32_t PING2, int t, int s, bool mpu) {//PING1 = depan, PING2 = belakang, mpu = true (Baca MPU)
//  if (mpu) {
//    read_MPU();
//    vTaskDelay(15 / portTICK_PERIOD_MS);
//    yawSebelum = yaw;
//    OffsetJarak = (readPING(PING1) - readPING(PING2)) * 1.7;
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, t, s);
//      OffsetJarak = (readPING(PING1) - readPING(PING2)) * 1.7;
//      xSemaphoreGive(mutex);
//    }
//    sdtAcuan = yawSebelum;
//    while (sdtAcuan == yawSebelum) {
//      read_MPU();
//      vTaskDelay(15 / portTICK_PERIOD_MS);
//      sdtAcuan = yaw;
//    }
//    sdtAcuan = yaw;
//  }
//  else {
//    OffsetJarak = (readPING(PING1) - readPING(PING2)) * 1.7;
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, t, s);
//      OffsetJarak = (readPING(PING1) - readPING(PING2)) * 1.7;
//      xSemaphoreGive(mutex);
//    }
//  }
//}

void navigasiMPU_Maju(int maxStep) {
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
    lebarKanan = PID_control;
    lebarKiri = 0;
  }
  else if (PID_control < 0) {//PID_control(-) = belok kiri
    lebarKanan = 0;
    lebarKiri = PID_control;
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

void navigasiMPU_Mundur(int maxStep) {
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
    lebarKanan = 0;
    lebarKiri = PID_control;
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
  //  Serial.print("E: ");
  //  Serial.println(error);
  //  Serial.print(", Y: ");
  //  Serial.println(yaw);
}

void navigasiMPU_Kiri(int maxStep) {
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
    lebarTengah = PID_control;
  }
  else if (PID_control < 0) {//PID_control(-) = belok kiri
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
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

void navigasiMPU_Kanan(int maxStep) {
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
  j3 = readPING(pingFront);
  j2 = readPING(pingBack);
  error = j3 - j2;
  //  if (error != 0) { //error (+) => belok kanan, error (-) => belok kiri
  PID_controller();
  if (PID_control >= maxStep )PID_control = maxStep;
  if (PID_control <= maxStep * -1)PID_control = maxStep * -1;
  if (PID_control > 0 ) {//PID_control(+) = belok kanan
    lebarKanan = PID_control;
    lebarKiri = 0;
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
  //}
  //else if ( error == 0 && (j3 >= setpoint + 4 || j3 <= setpoint - 4)) {
  //  offsets = setpoint - j3;
  //  while ( j3 > setpoint + 2) {//Geser Kanan
  //    xSemaphoreTake(mutex, portMAX_DELAY);
  //    GerakGeser(offsets, 20, 12, 0, 0, 0);
  //    xSemaphoreGive(mutex);
  //    j3 = readPING(pingFront);
  //    offsets = setpoint - j3;
  //  }
  //  while (j3 < setpoint - 2) {//Geser Kiri
  //    xSemaphoreTake(mutex, portMAX_DELAY);
  //    GerakGeser(offsets, 20, 12, 0, 0, 0);
  //    xSemaphoreGive(mutex);
  //    j3 = readPING(pingFront);
  //    offsets = setpoint - j3;
  //  }
  //}
}

void navigasiMundur(int setpoint, int maxStep, uint32_t pingFront, uint32_t pingBack) {
  j3 = readPING(pingFront);
  j2 = readPING(pingBack);
  error = j3 - j2;
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  //  if (error != 0) { //error (+) => belok kanan, error (-) => belok kiri
  PID_controller();
  if (PID_control >= maxStep )PID_control = maxStep;
  if (PID_control <= maxStep * -1)PID_control = maxStep * -1;
  if (PID_control > 0 ) {//PID_control(+) = belok kanan
    lebarKiri = 0;
    lebarKanan = (PID_control) * -1;
  }
  else if (PID_control < 0) {//PID_control(-) = belok kiri
    lebarKiri = (PID_control) * -1;
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
  //  }
  //  else if ( error == 0 && (j3 >= 20 || j3 <= 10)) {
  //    offsets = setpoint - j3;
  //    while ( j3 > setpoint + 2) {//Geser Kanan
  //      xSemaphoreTake(mutex, portMAX_DELAY);
  //      GerakGeser(offsets, 20, 20, 0, 0, 0);
  //      xSemaphoreGive(mutex);
  //      j3 = readPING(pingFront);
  //      offsets = setpoint - j3;
  //    }
  //    while (j3 < setpoint - 2) {//Geser Kiri
  //      xSemaphoreTake(mutex, portMAX_DELAY);
  //      GerakGeser(offsets, 20, 20, 0, 0, 0);
  //      xSemaphoreGive(mutex);
  //      j3 = readPING(pingFront);
  //      offsets = setpoint - j3;
  //    }
  //  }
}

void navigasiKanan(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  j3 = readPING(pingFront);
  j2 = readPING(pingBack);
  error = j3 - j2;
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
  j3 = readPING(pingFront);
  j2 = readPING(pingBack);
  error = j3 - j2;
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
  cm = duration / 58;
  return cm;
}

//void readSRF_Front() {
//  digitalWrite(TRIG, LOW);
//  vTaskDelay(2 / portTICK_PERIOD_MS);
//  digitalWrite(TRIG, HIGH);
//  vTaskDelay(5 / portTICK_PERIOD_MS);
//  digitalWrite(TRIG, LOW);
//  jarak = pulseIn(ECHO_Front, HIGH);
//  jarak = jarak / 58;
//  //  Serial.println(jarak);
//}
//
//void readSRF_Back() {
//  digitalWrite(TRIG, LOW);
//  vTaskDelay(1 / portTICK_PERIOD_MS);
//  digitalWrite(TRIG, HIGH);
//  vTaskDelay(2 / portTICK_PERIOD_MS);
//  digitalWrite(TRIG, LOW);
//  jarak = pulseIn(ECHO_Back, HIGH);
//  jarak = jarak / 58;
//  //  Serial.println(jarak);
//}

void baca_IR(uint32_t PinIR) {
  distances = IR(PinIR);
  //  filtered_IR = ((1 - filter_weight) * filtered_IR) + (filter_weight * distances);
  //  Serial.println(distances);
  vTaskDelay(2 / portTICK_PERIOD_MS);
}

int IR(uint32_t _irPin) {
  int ir_val[25]; int distanceCM;
  for (int i = 0; i < 25; i++) {
    ir_val[i] = analogRead(_irPin);
  }
  sort(ir_val, 25);
  distanceCM = 27.728 * pow(map(ir_val[25 / 2], 0,
                                1023, 0, 5000) / 1000.0, -1.2045);
  return distanceCM;
}

void sort(int a[], int lebar) {
  for (int i = 0; i < (lebar - 1); i++) {
    bool flag = true;
    for (int o = 0; o < (lebar - (i + 1)); o++) {
      if (a[o] > a[o + 1]) {
        int t = a[o];
        a[o] = a[o + 1];
        a[o + 1] = t;
        flag = false;
      }
    }
    if (true) break;
  }
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

void beforeTangga() {
  read_MPU();
  vTaskDelay(15 / portTICK_PERIOD_MS);
  filtered_Roll = ((1 - filter_weight) * filtered_Roll) + (filter_weight * roll);
  offsetCX[2] = map(filtered_Roll, rollAwal, rollTangga, 0, 30);
  offsetCX[3] = map(filtered_Roll, rollAwal, rollTangga, 0, -34);
  rightFM = map(filtered_Roll, rollAwal, rollTangga, 0, 37);
  rightTB = map(filtered_Roll, rollAwal, rollTangga, 0, 37);
  leftFM = map(filtered_Roll, rollAwal, rollTangga, 0, 25);
  leftTB = map(filtered_Roll, rollAwal, rollTangga, 0, 12);//
  midRightFM = map(filtered_Roll, rollAwal, rollTangga, 0, 46);
  midRightTB = map(filtered_Roll, rollAwal, rollTangga, 0, 58);
  midLeftFM = map(filtered_Roll, rollAwal, rollTangga, 0, 10);
  midLeftTB = map(filtered_Roll, rollAwal, rollTangga, 0, -16);//
}

void afterTangga() {
  read_MPU();
  vTaskDelay(15 / portTICK_PERIOD_MS);
  filtered_Roll = ((1 - filter_weight) * filtered_Roll) + (filter_weight * roll);
  offsetCX[2] = map(filtered_Roll, rollTangga, rollAwal, 30, 0);
  offsetCX[3] = map(filtered_Roll, rollTangga, rollAwal, -34, 0);
  rightFM = map(filtered_Roll, rollTangga, rollAwal, 37, 0);
  rightTB = map(filtered_Roll, rollTangga, rollAwal, 37, 0);
  leftFM = map(filtered_Roll, rollTangga, rollAwal, 12, 0);
  leftTB = map(filtered_Roll, rollTangga, rollAwal, 7, 0);//
  midRightFM = map(filtered_Roll, rollTangga, rollAwal, 46, 0);
  midRightTB = map(filtered_Roll, rollTangga, rollAwal, 58, 0);
  midLeftFM = map(filtered_Roll, rollTangga, rollAwal, 8, 0);
  midLeftTB = map(filtered_Roll, rollTangga, rollAwal, -14, 0);//
}

//===Gerakan Naik Tangga===//
void GerakSebelumTangga() {
  beforeTangga();
  xSemaphoreTake(mutex, portMAX_DELAY);
  GerakNaikTangga(5, 20, 5, 20, 45, 30, 0, 0, 0);
  xSemaphoreGive(mutex);
}

void GerakNaikTangga() {
  naikTangga();
  xSemaphoreTake(mutex, portMAX_DELAY);
  GerakNaikTangga(5, 28, 5, 28, 35, 28, 0, 0, 0);
  xSemaphoreGive(mutex);
}

void GerakSetelahTangga() {
  afterTangga();
  xSemaphoreTake(mutex, portMAX_DELAY);
  GerakNaikTangga(5, 28, 5, 28, 35, 28, 0, 0, 0);
  xSemaphoreGive(mutex);
}

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

//===Navigasi MPU + Sharp IR===//
//    navigasiMPU_Kiri(15);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    GerakGeser(15, 20, 15, lebarKiri, lebarKanan, lebarTengah);
//    xSemaphoreGive(mutex);
//    baca_IR();

//===Navigasi PING + Sharp IR===//
//    navigasiMaju(20, 15, rightFront, rightBack);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    GerakDinamis(15, 15, 8, lebarKiri, lebarKanan);
//    xSemaphoreGive(mutex);
//    baca_IR();

//===Logika Naik Tangga===//
//while (roll > -15) {
//  TransisiNaikTangga();
//}
//while (1) {
//  GerakNaikTangga();
//}
