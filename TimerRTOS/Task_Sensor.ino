void Sensor(void *pvParameters) {
  while (1) {
    //========= Dari Start sampai SZ-1 ============//
    RotateMPU(90, true);
    while (abs(Offset) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 20, 16);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //===Maju Dari Start===//
    baca_IR(IRback);
    while (distances < 26 || (steps == 1 || steps == 3)) {
      navigasiMaju(20, 20, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(15, 15, 6, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
    }

    RotateMPU(-90, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      GerakRotasi(Offset, 20, 16);
      RotateMPU();
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Standby();
    xSemaphoreGive(mutex);
    RotateMPU(88, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      GerakRotasi(Offset, 20, 16);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    j2 = readPING(rightBack);
    offsets = (21 - j2) * 5;
    while ((j2 > 21 + 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      j2 = readPING(rightBack);
      offsets = (21 - j2) * 5;
    }
    while ((j2 < 21 - 1) || (steps == 1 || steps == 3)) {  //Geser Kiri
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
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
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
    while (pitch > -16 && turunMPU == false) {
      navigasiMPU_Maju(34);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(22, 47, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch <= -16) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        turunMPU = true;
        xSemaphoreGive(mutex);
        break;
      }
    }
    //===Jalan Turunan 1 (Memastikan agar lewat dari Jalan Pecah)===//
    while ((pitch <= -14 && pitch > -35) && turunMPU == true) {
      navigasiMPU_Maju(34);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(22, 47, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch > -14) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        turunMPU = false;
        xSemaphoreGive(mutex);
        break;
      }
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 25, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //===Geser Turunan 1===//
    j3 = readPING(rightFront);
    offsets = (21 - j3) * 5;
    while ((j3 > 21 + 2) || (steps == 1 || steps == 3)) { //Geser Kanan
      navigasiKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 20, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (21 - j3) * 5;
    }
    while ((j3 < 21 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 25, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (21 - j3) * 5;
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 25, 16);
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
      GerakDinamis(20, 38, 20, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch >= -2) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        stateMPU = true;
        xSemaphoreGive(mutex);
      }
    }
    //===Jalan Berbatu Menuju SZ-1===//
    heightFront = -92;
    heightMid = -92;
    heightBack = -92;
    baca_IR(IRfront);
    offsets = (distances - 4) * 5;
    if (offsets > 20) offsets = 20;
    if (offsets < -20) offsets = -20;
    while (distances > 4 && stateMPU == true) {
      //      navigasiMPU_Maju(offsets * 2);
      navigasiMaju(25, 22, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(offsets, 31, 24, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      offsets = (distances - 4) * 5;
      if (offsets > 20) offsets = 20;
      if (offsets < -20) offsets = -20;
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 20);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //======Geser SZ-1======//
    j3 = readPING(rightFront);
    offsets = (10 - j3) * 5;
    while ((j3 > 10 + 2) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(offsets + 5, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 32, 24, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (10 - j3) * 5;
    }
    while ((j3 < 10 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(offsets + 5, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 32, 24, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (10 - j3) * 5;
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 20);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //====Rotate SZ-1====//
    RotateMPU(90, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 32, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 18);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    //====Geser SZ-1====//
    j3 = readPING(leftFront);
    while ((j3 < 9 - 2) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 34, 30, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((j3 > 9 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 34, 30, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    //===Mundur SZ-1===//
    baca_IR(IRfront);
    while (distances < 12 || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-20, 32, 36, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 26);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    //===Rotate dan taruh korban SZ-1===//
    RotateMPU(-32, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 32, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Standby();
    //    while ((moveServ || moveDyn) || movePeg) {
    //      if (moveServ) {
    //        capit1.write(moveCapit(130 , 179, 20));
    //        capit2.write(moveCapit(50 , 1, 20));
    //      }
    //      if (movePeg) {
    //        pegangan.write(movePegangan(50 , 72, 20));
    //      }
    //      if (moveDyn) {
    //        kirimDynamixel(512, moveDynamixel(240, 110, 200));
    //      }
    //    }
    //    while ((moveServ == false || moveDyn == false) || movePeg == false) {
    //      if (moveServ) {
    //        capit1.write(moveCapit(179 , 130, 20));
    //        capit2.write(moveCapit(1 , 50, 20));
    //      }
    //      if (movePeg) {
    //        pegangan.write(movePegangan(72 , 50, 20));
    //      }
    //      if (moveDyn) {
    //        kirimDynamixel(512, moveDynamixel(110, 240, 200));
    //      }
    //    }
    xSemaphoreGive(mutex);
    RotateMPU(32, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 32, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 20);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    //==================================================================================================//

    //================Dari SZ-1 Menuju SZ-2==============//
    sdtAcuan = yaw;
    baca_IR(IRfront);
    while (distances < 31 || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-20, 32, 24, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 18);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    RotateMPU(88, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 26, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Standby();
    xSemaphoreGive(mutex);
    RotateMPU(88, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 26, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    j2 = readPING(rightBack);
    offsets = (20 - j2) * 5;
    if (offsets > 22) offsets = 22;
    if (offsets < -22) offsets = -22;
    while ((j2 < 20 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 28, 24, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (20 - j2) * 5;
      if (offsets > 22) offsets = 22;
      if (offsets < -22) offsets = -22;
    }
    while ((j2 > 20 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKanan(22, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 28, 24, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (20 - j2) * 5;
      if (offsets > 22) offsets = 22;
      if (offsets < -22) offsets = -22;
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
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
    if (offsets > 22) offsets = 22;
    if (offsets < -22) offsets = -22;
    while (distances > 12) {
      navigasiMPU_Maju(23);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(offsets, 26, 20, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      offsets = (distances - 12) * 5;
      if (offsets > 22) offsets = 22;
      if (offsets < -22) offsets = -22;
      if (distances <= 12) break;
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 18);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotateMPU(89, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
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
    while (distances < 17 || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-22, 31, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    j2 = readPING(leftBack);
    while ((j2 > 9 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 35, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      if (distances < 13) {
        while (distances < 14 || (steps == 1 || steps == 3)) {
          navigasiMPU_Mundur(20);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(-20, 35, 34, lebarKiri, lebarKanan);
          xSemaphoreGive(mutex);
          baca_IR(IRfront);
          if (distances >= 13) break;
        }
      }
    }
    j3 = readPING(leftFront);
    if (j3 > 9) {
      j2 = readPING(leftBack);
      while ((j2 > 9 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
        navigasiKiri(22, leftFront, leftBack);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(22, 35, 34, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRfront);
        if (distances < 13) {
          while (distances < 14 || (steps == 1 || steps == 3)) {
            navigasiMPU_Mundur(20);
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakDinamis(-20, 35, 34, lebarKiri, lebarKanan);
            xSemaphoreGive(mutex);
            baca_IR(IRfront);
            if (distances >= 13) break;
          }
        }
      }
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 24);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    RotateMPU(-20, true);
    while (abs(Offset) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 30, 32);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    while (1) {
      Standby();
    }
    //== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == //
  }
}



//=== Logika Arena ===//
