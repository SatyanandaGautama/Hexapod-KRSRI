void testSharp() {
  int jarak = analogRead(PA0);
  int IRRangeVal = 27.728 * pow(map(jarak, 0, 1023, 0, 5000) / 1000.0, -1.2045);
  Serial.print("sensor ");
  Serial.println(IRRangeVal);
}

void RotateMPU(int selisih = 0, bool rot = false) {  //(-)Putar Kiri, (+)Putar Kanan
  if (rot) {
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    tujuan = yaw + selisih;
    if (tujuan >= 360) tujuan -= 360;
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



void RotJarak(uint32_t PING1, uint32_t PING2) {
  jFront = readPING(PING1);
  jBack = readPING(PING2);
  filtered_jFront = ((1 - weight_PING) * filtered_jFront) + (weight_PING * jFront);
  filtered_jBack = ((1 - weight_PING) * filtered_jBack) + (weight_PING * jBack);
  OffsetJarak = (round(filtered_jFront) - round(filtered_jBack)) * 3;  //2.5
  if (OffsetJarak > 25) OffsetJarak = 25;
  if (OffsetJarak < -25) OffsetJarak = -25;
}
void RotJarakIR(int inc) {
  baca_IR(IRbackgroan);
  filtered_Rg = distances;
  //  filtered_Rg = ((1 - 0.6) * filtered_Rg) + (0.6 * distances);
  // Serial.print("M : ");
  // Serial.println(filtered_Rg);
  baca_IR(IRback);
  filtered_Rb = distances;
  // filtered_Rb = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
  // Serial.print("B : ");
  // Serial.println(filtered_Rb);
  filtered_Rb += inc;
  //  filtered_Rb = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
  // Serial.print("B : ");
  // Serial.println(filtered_Rb);
  OffsetJarak = (filtered_Rg - filtered_Rb) * 3;  //2.5
  if (OffsetJarak > 15) OffsetJarak = 15;
  if (OffsetJarak < -15) OffsetJarak = -15;
}

void RotJarakIR_1() {
  baca_IR(IRbackgroan);
  filtered_Rg = distances;
  //  filtered_Rg = ((1 - 0.6) * filtered_Rg) + (0.6 * distances);
  // Serial.print("M : ");
  // Serial.println(filtered_Rg);
  baca_IR(IRback);
  filtered_Rb = distances;
  // filtered_Rb = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
  // Serial.print("B : ");
  // Serial.println(filtered_Rb);
  filtered_Rb += 2;
  //  filtered_Rb = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
  // Serial.print("B : ");
  // Serial.println(filtered_Rb);
  OffsetJarak = (filtered_Rg - filtered_Rb) * 3;  //2.5
  if (OffsetJarak > 15) OffsetJarak = 15;
  if (OffsetJarak < -15) OffsetJarak = -15;
}

void RotJarakIR_2() {
  baca_IR(IRbackgroan);
  filtered_Rg = distances;
  //  filtered_Rg = ((1 - 0.6) * filtered_Rg) + (0.6 * distances);
  // Serial.print("M : ");
  // Serial.println(filtered_Rg);
  baca_IR(IRback);
  filtered_Rb = distances;
  // filtered_Rb = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
  // Serial.print("B : ");
  // Serial.println(filtered_Rb);
  filtered_Rb += 3;
  //  filtered_Rb = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
  // Serial.print("B : ");
  // Serial.println(filtered_Rb);
  OffsetJarak = (filtered_Rg - filtered_Rb) * 3;  //2.5
  if (OffsetJarak > 15) OffsetJarak = 15;
  if (OffsetJarak < -15) OffsetJarak = -15;
}

void RotJarakIR_3() {
  baca_IR(IRbackgroan);
  filtered_Rg = distances;
  //  filtered_Rg = ((1 - 0.6) * filtered_Rg) + (0.6 * distances);
  // Serial.print("M : ");
  // Serial.println(filtered_Rg);
  baca_IR(IRback);
  filtered_Rb = distances;
  // filtered_Rb = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
  // Serial.print("B : ");
  // Serial.println(filtered_Rb);
  filtered_Rb += 7;
  //  filtered_Rb = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
  // Serial.print("B : ");
  // Serial.println(filtered_Rb);
  OffsetJarak = (filtered_Rg - filtered_Rb) * 3;  //2.5
  if (OffsetJarak > 15) OffsetJarak = 15;
  if (OffsetJarak < -15) OffsetJarak = -15;
}

void navigasiMPU_Maju_versiCepat(int maxStep) {
  read_MPU();
  vTaskDelay(10 / portTICK_PERIOD_MS);
  error = sdtAcuan - yaw;  //error (+) => belok kanan, error (-) => belok kiri
  if (error < -180) {
    error = sdtAcuan - yaw + 360;
  }
  if (error > 180) {
    error = sdtAcuan - yaw - 360;
  }
  PID_controller_cepat();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKanan = PID_control;
    lebarKiri = 0;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKanan = 0;
    lebarKiri = PID_control;
  } else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //  Serial.print("E: ");
  //  Serial.println(error);
  //  Serial.print(", Y: ");
  //  Serial.println(yaw);
}

void navigasiMPU_Maju(int maxStep) {
  read_MPU();
  vTaskDelay(10 / portTICK_PERIOD_MS);
  error = sdtAcuan - yaw;  //error (+) => belok kanan, error (-) => belok kiri
  if (error < -180) {
    error = sdtAcuan - yaw + 360;
  }
  if (error > 180) {
    error = sdtAcuan - yaw - 360;
  }
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKanan = PID_control;
    lebarKiri = 0;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKanan = 0;
    lebarKiri = PID_control;
  } else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //  Serial.print("E: ");
  //  Serial.println(error);
  //  Serial.print(", Y: ");
  //  Serial.println(yaw);
}

void navigasi_K4(int maxStep) {
  read_maix();
  x1 = result.xCenter;
  error = x1 - x0;  //error (+) => belok kanan, error (-) => belok kiri
  if (error < -50) {
    error = -50;
  }
  if (error > 50) {
    error = 50;
  }
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKanan = PID_control;
    lebarKiri = 0;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKanan = 0;
    lebarKiri = PID_control;
  } else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //  Serial.print("E: ");
  //  Serial.println(error);
  //  Serial.print(", Y: ");
  //  Serial.println(yaw);
}

void navigasiMPU_Mundur(int maxStep) {
  read_MPU();
  vTaskDelay(10 / portTICK_PERIOD_MS);
  error = sdtAcuan - yaw;  //error (+) => belok kanan, error (-) => belok kiri
  if (error < -180) {
    error = sdtAcuan - yaw + 360;
  }
  if (error > 180) {
    error = sdtAcuan - yaw - 360;
  }
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKanan = 0;
    lebarKiri = PID_control;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKiri = 0;
    lebarKanan = PID_control;
  } else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //  Serial.print("E: ");
  //  Serial.println(error);
  //  Serial.print(", Y: ");
  //  Serial.println(yaw);
}

void navigasiMPU_Kiri(int maxStep) {
  read_MPU();
  vTaskDelay(10 / portTICK_PERIOD_MS);
  error = sdtAcuan - yaw;  //error (+) => belok kanan, error (-) => belok kiri
  if (error < -180) {
    error = sdtAcuan - yaw + 360;
  }
  if (error > 180) {
    error = sdtAcuan - yaw - 360;
  }
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  } else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //  Serial.print("E: ");
  //  Serial.println(error);
  //  Serial.print(", Y: ");
  //  Serial.println(yaw);
}

void navigasiMPU_Kanan(int maxStep) {
  read_MPU();
  vTaskDelay(10 / portTICK_PERIOD_MS);
  error = sdtAcuan - yaw;  //error (+) => belok kanan, error (-) => belok kiri
  if (error < -180) {
    error = sdtAcuan - yaw + 360;
  }
  if (error > 180) {
    error = sdtAcuan - yaw - 360;
  }
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  } else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //  Serial.print("E: ");
  //  Serial.println(error);
  //  Serial.print(", Y: ");
  //  Serial.println(yaw);
}

void navigasiMaju(int setpoint, int maxStep, uint32_t pingFront, uint32_t pingBack) {
  jFront = readPING(pingFront);
  jBack = readPING(pingBack);
  error = jFront - jBack;
  //  if (error != 0) { //error (+) => belok kanan, error (-) => belok kiri
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKanan = PID_control;
    lebarKiri = 0;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKiri = PID_control;
    lebarKanan = 0;
  } else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //    Serial.print("E: ");
  //    Serial.println(error);
}

void navigasiMundur(int setpoint, int maxStep, uint32_t pingFront, uint32_t pingBack) {
  jFront = readPING(pingFront);
  jBack = readPING(pingBack);
  error = jFront - jBack;
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  //  if (error != 0) { //error (+) => belok kanan, error (-) => belok kiri
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKiri = 0;
    lebarKanan = (PID_control) * -1;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKiri = (PID_control) * -1;
    lebarKanan = 0;
  } else {
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //    Serial.print("E: ");
  //    Serial.println(error);
}

void navigasiKanan(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  jFront = readPING(pingFront);
  jBack = readPING(pingBack);
  error = jFront - jBack;
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  } else {
    lebarTengah = 0;
    lebarKiri = 0;
    lebarKanan = 0;
  }
  previous_error = error;
  //    Serial.print("E: ");
  //    Serial.println(error);
}

void navigasiKiri(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  jFront = readPING(pingFront);
  jBack = readPING(pingBack);
  error = jBack - jFront;  //jFront - jBack
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  } else {
    lebarTengah = 0;
    lebarKiri = 0;
    lebarKanan = 0;
  }
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

void readSRF() {
  digitalWrite(TRIG, LOW);
  vTaskDelay(2 / portTICK_PERIOD_MS);
  digitalWrite(TRIG, HIGH);
  vTaskDelay(5 / portTICK_PERIOD_MS);
  digitalWrite(TRIG, LOW);
  jarak = pulseIn(ECHO, HIGH);
  jarak = jarak / 58;
  //  Serial.println(jarak);
}

void baca_IR(uint32_t PinIR) {
  distances = IR(PinIR);
  //  Serial.println(distances);
  vTaskDelay(2 / portTICK_PERIOD_MS);
}

int IR(uint32_t _irPin) {
  int ir_val[25];
  int distanceCM;
  for (int i = 0; i < 25; i++) {
    ir_val[i] = analogRead(_irPin);
  }
  sort(ir_val, 25);
  distanceCM = 27.728 * pow(map(ir_val[25 / 2], 0, 1023, 0, 5000) / 1000.0, -1.2045);
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
  D_control = kd * (error - previous_error);
  //Summing PID
  PID_control = (P_control + D_control) * 10;  //Coba saja dikali 10 atau tidak (Besaran Output PID Controller)
}

void PID_controller_cepat() {
  //Proportional control
  P_control = 0.15 * error;
  //Derivative control
  D_control = 0.001 * (error - previous_error);
  //Summing PID
  PID_control = (P_control + D_control) * 10;  //Coba saja dikali 10 atau tidak (Besaran Output PID Controller)
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
  if (filtered_Roll > 13) {
    offsetCX[2] = 27;   //Coxa BL //25
    offsetCX[3] = -20;  //Coxa FL //-22
    rightFM = 39;       //Femur FR & BR //40
    rightTB = 34;       //Tibia FR & BR // 34
    rightFM_FR = 36;
    leftFM_FL = 27;
    leftFM = 27;      //Femur FL & BL //12 Naik(+) //15 //18
    leftTB = 14;      //Tibia FL & BL //9 Masuk(+) //13 //16
    midRightFM = 48;  //Femur RM //50
    midRightTB = 58;  //Tibia RM
    midLeftFM = 18;   //Femur LM //14 //16 //18 good (Makin besar makin naik)
    midLeftTB = -9;   //Tibia LM //11 (Makin kecil makin masuk)
  } else if (filtered_Roll < 0) {
    offsetCX[2] = 0;  //Coxa BL //25
    offsetCX[3] = 0;  //Coxa FL //-22
    rightFM = 0;      //Femur FR & BR //40
    rightTB = 0;      //Tibia FR & BR
    rightFM_FR = 0;
    leftFM_FL = 0;
    leftFM = 0;      //Femur FL & BL //12 Naik(+) //15 //18
    leftTB = 0;      //Tibia FL & BL //9 Masuk(+) //13 //16
    midRightFM = 0;  //Femur RM //50
    midRightTB = 0;  //Tibia RM
    midLeftFM = 0;   //Femur LM //14 //16 //18 good (Makin besar makin naik)
    midLeftTB = 0;
  } else {
    offsetCX[2] = map(filtered_Roll, rollAwal, rollTangga, 2, 27);
    offsetCX[3] = map(filtered_Roll, rollAwal, rollTangga, -2, -25);
    rightFM = map(filtered_Roll, rollAwal, rollTangga, 0, 39);
    rightTB = map(filtered_Roll, rollAwal, rollTangga, 0, 34);  //34
    rightFM_FR = map(filtered_Roll, rollAwal, rollTangga, 0, 36);
    leftFM_FL = map(filtered_Roll, rollAwal, rollTangga, 0, 27);
    leftFM = map(filtered_Roll, rollAwal, rollTangga, 0, 27);      //25 //26
    leftTB = map(filtered_Roll, rollAwal, rollTangga, 0, 14);      //16 //15
    midRightFM = map(filtered_Roll, rollAwal, rollTangga, 0, 48);  //48
    midRightTB = map(filtered_Roll, rollAwal, rollTangga, 0, 58);
    midLeftFM = map(filtered_Roll, rollAwal, rollTangga, 4, 24);    //20
    midLeftTB = map(filtered_Roll, rollAwal, rollTangga, -2, -12);  //11
  }
}
//===Gerakan Naik Tangga===//
void GerakSebelumTangga() {
  beforeTangga();
  //  xSemaphoreTake(mutex, portMAX_DELAY);
  GerakNaikTangga(5, 23, 5, 23, 54, 40, 0, 0, 0);  //4,21,6,20
  //  xSemaphoreGive(mutex);
}


void afterTangga() {
  offsetCX[2] = 0;  //Coxa BL //25
  offsetCX[3] = 0;  //Coxa FL //-22
  rightFM = 0;      //Femur FR & BR //40
  rightTB = 0;      //Tibia FR & BR
  leftFM = 0;       //Femur FL & BL //12 Naik(+) //15 //18
  leftTB = 0;       //Tibia FL & BL //9 Masuk(+) //13 //16
  midRightFM = 0;   //Femur RM //50
  midRightTB = 0;   //Tibia RM
  midLeftFM = 0;    //Femur LM //14 //16 //18 good (Makin besar makin naik)
  midLeftTB = 0;
}

void navigasiKanan_pingKanan(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  jFront = readPING(pingFront);
  jBack = readPING(pingBack);
  error = jFront - jBack;
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  } else {
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

void navigasiKiri_pingKiri(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  jFront = readPING(pingFront);
  jBack = readPING(pingBack);
  error = jBack - jFront;  //jFront - jBack
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  } else {
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

void navigasiKanan_pingKiri(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  jFront = readPING(pingFront);
  jBack = readPING(pingBack);
  error = jFront - jBack;
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarTengah = -PID_control;
    lebarKiri = 0;
    lebarKanan = -PID_control;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarKiri = PID_control;
    lebarKanan = 0;
    lebarTengah = PID_control;
  } else {
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

void navigasiKiri_pingKanan(int maxStep, uint32_t pingFront, uint32_t pingBack) {
  jFront = readPING(pingFront);
  jBack = readPING(pingBack);
  error = jFront - jBack;  //jFront - jBack
  //  xSemaphoreGive(mutex); //Untuk SRF04 di SemaphoreGive di comment
  PID_controller();
  if (PID_control >= maxStep) PID_control = maxStep;
  if (PID_control <= maxStep * -1) PID_control = maxStep * -1;
  if (PID_control > 0) {  //PID_control(+) = belok kanan
    lebarKiri = 0;
    lebarKanan = PID_control;
    lebarTengah = PID_control;
  } else if (PID_control < 0) {  //PID_control(-) = belok kiri
    lebarTengah = -PID_control;
    lebarKiri = -PID_control;
    lebarKanan = 0;
  } else {
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

void GerakanNaikTangga() {
  naikTangga();
  //  xSemaphoreTake(mutex, portMAX_DELAY);
  GerakNaikTangga(5, 28, 5, 28, 40, 30, 0, 0, 0);
  //  xSemaphoreGive(mutex);
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
//while (roll < 15 && sdtRollTangga) {
//  GerakSebelumTangga();
//  if (roll >= 15) {
//    sdtRollTangga = false;
//    break;
//  }
//}
//
//while (roll >= 15 && sdtRollTangga == false) {
//  GerakNaikTangga();
//}

void BacaSensor() {
  baca_IR(IRfront);
  Serial.print("IR Front : ");
  Serial.println(distances);
  baca_IR(IRback);
  Serial.print("IR Back : ");
  Serial.println(distances);
  Serial.print("Right Front : ");
  Serial.println(readPING(rightFront));
  Serial.print("Right Back : ");
  Serial.println(readPING(rightBack));
  Serial.print("Left Front : ");
  Serial.println(readPING(leftFront));
  Serial.print("Left Back : ");
  Serial.println(readPING(leftBack));
  Serial.print("Back : ");
  Serial.println(readPING(belakang));
  read_MPU();
  vTaskDelay(15 / portTICK_PERIOD_MS);
  Serial.print("Yaw :");
  Serial.println(yaw);
  Serial.print("Pitch :");
  Serial.println(yaw);
  // while (1) {
  //   xSemaphoreTake(mutex, portMAX_DELAY);
  //   bacaTOFDepan();
  //   xSemaphoreGive(mutex);
  //   xSemaphoreTake(mutex, portMAX_DELAY);
  //   bacaTOFKanan();
  //   xSemaphoreGive(mutex);
  //   xSemaphoreTake(mutex, portMAX_DELAY);
  //   bacaTOFKiri();
  //   xSemaphoreGive(mutex);
  //   xSemaphoreTake(mutex, portMAX_DELAY);
  //   bacaTOFBelakang();
  //   xSemaphoreGive(mutex);
  // }
}

//    bodyKanan.write(70);
//    baca_IR(IRright);
//    Serial.print("R : ");
//    Serial.println(distances);
//    baca_IR(IRback);
//    Serial.print("B : ");
//    Serial.println(distances);
//    RotJarakIR();
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 25, 26);
//      RotJarakIR();
//      xSemaphoreGive(mutex);
//    }
//    while (1) {
//      Standby();
//    }
//    baca_IR(IRbackgroan);
//    Serial.print("M : ");
//    Serial.println(distances);
