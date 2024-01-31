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
    while (jarak < 55 || (steps == 0 || steps == 2)) {
      if (Sensors) {
        navigasiMaju(20, 15, rightFront, rightBack);
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

    j2 = readPING(rightBack);
    offsets = 20 - j2;
    while ( j2 > 22) {//Geser Kanan
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 17, 12, 0, 0, 0);
      xSemaphoreGive(mutex);
      j2 = readPING(rightBack);
      offsets = 20 - j2;
    }
    while (j2 < 18) {//Geser Kiri
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 17, 12, 0, 0, 0);
      xSemaphoreGive(mutex);
      j2 = readPING(rightBack);
      offsets = setpoint - j2;
    }
    //===Jalan Pecah===//
    while (pitch < 16) {
      navigasiMPU_Maju(32);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(24, 44, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch >= 16) {
        break;
      }
    }

    //


    //

    //===Jalan Turunan===//
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    while (pitch > 3 && stateMPU == false) {
      navigasiMaju(20, 15, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 20, 15, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch <= 3) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        stateMPU = true;
        xSemaphoreGive(mutex);
        break;
      }
    }
    //===Jalan Berbatu===//
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    while (pitch <= 3 && stateMPU == true) {
      while (1) {
        Standby();
      }
    }
  }
}


//=== Logika Arena ===//
//    RotateMPU(90);
//    while (abs(Offset) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 20, 18);
//      xSemaphoreGive(mutex);
//      RotateMPU(90);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 20, 16);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    readSRF04();
//    while (jarak < 56 || (steps == 0 || steps == 2)) {
//      if (Sensors) {
//        navigasiMaju(15, 30, rightFront, rightBack);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakDinamis(15, 15, 8, lebarKiri, lebarKanan);
//        xSemaphoreGive(mutex);
//      }
//      else {
//        readSRF04();
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        Sensors = true;
//        xSemaphoreGive(mutex);
//      }
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    Standby();
//    xSemaphoreGive(mutex);
//    RotateMPU(0);
//    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
//      RotateMPU(0);
//      GerakRotasi(Offset, 18, 18);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    Standby();
//    xSemaphoreGive(mutex);
//    RotateMPU(90);
//    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
//      RotateMPU(90);
//      GerakRotasi(Offset, 18, 18);
//    }
//    yawSebelum = yaw;
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 15, 16);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    sdtAcuan = yawSebelum;
//    while (sdtAcuan == yawSebelum) {
//      read_MPU();
//      vTaskDelay(15 / portTICK_PERIOD_MS);
//      sdtAcuan = yaw;
//    }
//    sdtAcuan = yaw;
//    while (pitch < 17) {
//      height = -100;
//      navigasiMPU_Maju(44);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(22, 42, 30, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//    }
//    height = -95;
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 15, 16);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    j2 = readPING(rightFront);
//    while ( j2 > 17) {//Geser Kanan
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(offsets, 20, 20, 0, 0, 0);
//      xSemaphoreGive(mutex);
//      j2 = readPING(rightFront);
//      offsets = setpoint - j2;
//    }
//    while (j2 < 13) {//Geser Kiri
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(offsets, 20, 20, 0, 0, 0);
//      xSemaphoreGive(mutex);
//      j2 = readPING(rightFront);
//      offsets = setpoint - j2;
//    }
//    read_MPU();
//    vTaskDelay(15 / portTICK_PERIOD_MS);
//    yawSebelum = yaw;
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 15, 16);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    sdtAcuan = yawSebelum;
//    while (sdtAcuan == yawSebelum) {
//      read_MPU();
//      vTaskDelay(15 / portTICK_PERIOD_MS);
//      sdtAcuan = yaw;
//    }
//    sdtAcuan = yaw;
//    while (pitch > 3 && stateMPU == false) {
//      navigasiMPU_Maju(40);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(20, 25, 18, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      if (pitch <= 3) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        stateMPU = true;
//        xSemaphoreGive(mutex);
//        break;
//      }
//    }
//    read_MPU();
//    while (pitch <= 3 && stateMPU == true) {
//      while (1) {
//        Serial.println("S");
//        Standby();
//      }
//    }
