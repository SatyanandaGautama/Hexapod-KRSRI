void Sensor(void *pvParameters) {
  while (1) {
    //=== Logika Strat sampai SZ-1 ===//
    RotateMPU(90, true);
    while (abs(Offset) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 20, 16);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    baca_IR(IRback);
    while (distances < 26 || (steps == 0 || steps == 2)) {
      navigasiMaju(20, 20, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(15, 15, 6, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
    }
    RotateMPU(-90, true);
    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
      GerakRotasi(Offset, 18, 18);
      RotateMPU();
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Standby();
    xSemaphoreGive(mutex);
    RotateMPU(88, true);
    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
      GerakRotasi(Offset, 18, 18);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    j2 = readPING(rightBack);
    offsets = (21 - j2) * 5;
    while ( (j2 > 21 + 2) || (steps == 0 || steps == 2)) { //Geser Kanan
      navigasiKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      j2 = readPING(rightBack);
      offsets = (21 - j2) * 5;
    }
    while ((j2 < 21 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKiri(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      j2 = readPING(rightBack);
      offsets = (21 - j2) * 5;
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
    //===Jalan Pecah===//
    while (pitch > -17 && turunMPU == false) {
      navigasiMPU_Maju(34);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(26, 47, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch <= -17) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        turunMPU = true;
        xSemaphoreGive(mutex);
        break;
      }
    }
    //===Jalan Turunan 1===//
    while ((pitch <= -15 && pitch > -30) && turunMPU == true) {
      navigasiMPU_Maju(30);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(26, 47, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch > -15) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        turunMPU = false;
        xSemaphoreGive(mutex);
        break;
      }
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) >  1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 12);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    j3 = readPING(rightFront);
    offsets = (20 - j3) * 5;
    while ( (j3 > 20 + 2) || (steps == 0 || steps == 2)) { //Geser Kanan
      navigasiKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 20, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (20 - j3) * 5;
    }
    while ((j3 < 20 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKiri(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 20, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (20 - j3) * 5;
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 12);
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
    heightFront = -92;
    heightMid = -90;
    heightBack = -77;
    //===Jalan Turunan 2===//
    while (pitch <= -2 && stateMPU == false) {
      navigasiMPU_Maju(25);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 26, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch > -2) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        stateMPU = true;
        xSemaphoreGive(mutex);
        break;
      }
    }
    //===Jalan Berbatu===//
    heightFront = -92;
    heightMid = -92;
    heightBack = -92;
    baca_IR(IRfront);
    offsets = (distances - 4) * 5;
    if (offsets > 20)offsets = 20;
    if (offsets < -20)offsets = -20;
    while (distances > 4 && stateMPU == true) {
      //      navigasiMPU_Maju(offsets * 2);
      navigasiMaju(25, offsets + 2, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(offsets, 26, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      offsets = (distances - 4) * 5;
      if (offsets > 20)offsets = 20;
      if (offsets < -20)offsets = -20;
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 25, 20);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //======Geser SZ-1======//
    j3 = readPING(rightFront);
    offsets = (13 - j3) * 5;
    while ((j3 > 13 + 2) || (steps == 0 || steps == 2)) { //Geser Kanan
      navigasiKanan(offsets + 5, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 26, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (13 - j3) * 5;
    }
    while ((j3 < 13 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKiri(offsets + 5, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 26, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (13 - j3) * 5;
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 26, 24);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    RotateMPU(90, true);
    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 27, 32);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 26, 24);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    j3 = readPING(leftFront);
    while ((j3 < 10 - 2) || (steps == 0 || steps == 2)) { //Geser Kanan
      navigasiKanan(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 30, 30, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((j3 > 10 + 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 30, 30, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    heightFront = -94;
    heightMid = -94;
    heightBack = -94;
    sdtAcuan = yaw;
    baca_IR(IRfront);
    while (distances < 11 || (steps == 0 || steps == 2)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-20, 30, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 26, 24);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    RotateMPU(-32, true);
    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 27, 30);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Standby();
    xSemaphoreGive(mutex);
    RotateMPU(32, true);
    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 27, 30);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 27, 24);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    //==========SZ-1 sampai SZ-2=========//
    sdtAcuan = yaw;
    baca_IR(IRfront);
    while (distances < 31 || (steps == 0 || steps == 2)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-20, 30, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 18);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    RotateMPU(88, true);
    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 26, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Standby();
    xSemaphoreGive(mutex);
    RotateMPU(88, true);
    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 26, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    j2 = readPING(rightBack);
    offsets = (20 - j2) * 5;
    if (offsets > 22)offsets = 22;
    if (offsets < -22)offsets = -22;
    while ((j2 < 20 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKiri(22, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 28, 24, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (20 - j2) * 5;
      if (offsets > 22)offsets = 22;
      if (offsets < -22)offsets = -22;
    }
    while ((j2 > 20 + 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKanan(22, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 28, 24, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (20 - j2) * 5;
      if (offsets > 22)offsets = 22;
      if (offsets < -22)offsets = -22;
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 28, 20);
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
    baca_IR(IRfront);
    offsets = (distances - 12) * 5;
    if (offsets > 22)offsets = 22;
    if (offsets < -22)offsets = -22;
    while (distances > 12) {
      navigasiMPU_Maju(23);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(offsets, 26, 20, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      offsets = (distances - 12) * 5;
      if (offsets > 22)offsets = 22;
      if (offsets < -22)offsets = -22;
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 18);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotateMPU(89, true);
    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 30, 40);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    sdtAcuan = yawSebelum;
    while (sdtAcuan == yawSebelum) {
      read_MPU();
      vTaskDelay(15 / portTICK_PERIOD_MS);
      sdtAcuan = yaw;
    }
    sdtAcuan = yaw;
    baca_IR(IRfront);
    while (distances < 17) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-22, 31, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    j2 = readPING(leftBack);
    while ((j2 < 9 - 2) || (steps == 0 || steps == 2)) { //Geser Kanan
      navigasiKanan(20, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(20, 36, 32, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((j2 > 9 + 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKiri(18, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 37, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      if (distances < 13) {
        while (distances < 13 || (steps == 0 || steps == 2)) {
          navigasiMPU_Mundur(20);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(-20, 37, 34, lebarKiri, lebarKanan);
          xSemaphoreGive(mutex);
          baca_IR(IRfront);
          if (distances >= 13)break;
        }
      }
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 24);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    RotateMPU(-20, true);
    while (abs(Offset) > 2 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 30, 32);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    while (1) {
      Standby();
    }
  }
}

//=== Logika Arena ===//
