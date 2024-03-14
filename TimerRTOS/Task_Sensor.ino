void Sensor(void *pvParameters) {
  while (1) {
    baca_IR(IRfront);
    //    //========= Dari Start sampai SZ-1 ============//
    //    RotateMPU(90, true);
    //    while (abs(Offset) > 0 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 20, 16);
    //      xSemaphoreGive(mutex);
    //      RotateMPU();
    //    }
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 20, 16);
    //      RotJarak(rightFront, rightBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    //===Maju Dari Start===//
    //    baca_IR(IRback);
    //    while (distances < 26 || (steps == 1 || steps == 3)) {
    //      navigasiMaju(20, 20, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(15, 15, 6, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      baca_IR(IRback);
    //    }
    //    RotateMPU(-90, true);
    //    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
    //      GerakRotasi(Offset, 20, 16);
    //      RotateMPU();
    //    }
    //    xSemaphoreTake(mutex, portMAX_DELAY);
    //    Standby();
    //    xSemaphoreGive(mutex);
    //    RotateMPU(88, true);
    //    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
    //      GerakRotasi(Offset, 20, 16);
    //      RotateMPU();
    //    }
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 20, 16);
    //      RotJarak(rightFront, rightBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    jBack = readPING(rightBack);
    //    offsets = (21 - jBack) * 5;
    //    while ((jBack > 21 + 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
    //      navigasiKanan(offsets, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      jBack = readPING(rightBack);
    //      offsets = (21 - jBack) * 5;
    //    }
    //    while ((jBack < 21 - 1) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //      navigasiKiri(offsets, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      jBack = readPING(rightBack);
    //      offsets = (21 - jBack) * 5;
    //    }
    //    read_MPU();
    //    vTaskDelay(15 / portTICK_PERIOD_MS);
    //    yawSebelum = yaw;
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
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
    //    //===Jalan Pecah===//
    //    while (pitch > -16 && turunMPU == false) {
    //      navigasiMPU_Maju(34);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(22, 47, 34, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      if (pitch <= -16) {
    //        xSemaphoreTake(mutex, portMAX_DELAY);
    //        turunMPU = true;
    //        xSemaphoreGive(mutex);
    //        break;
    //      }
    //    }
    //    //===Jalan Turunan 1 (Memastikan agar lewat dari Jalan Pecah)===//
    //    while ((pitch <= -13 && pitch > -38) && turunMPU == true) {
    //      navigasiMPU_Maju(34);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(22, 47, 34, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      if (pitch > -13) {
    //        xSemaphoreTake(mutex, portMAX_DELAY);
    //        turunMPU = false;
    //        xSemaphoreGive(mutex);
    //        break;
    //      }
    //    }
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 35, 16);
    //      RotJarak(rightFront, rightBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    //===Geser Turunan 1===//
    //    jFront = readPING(rightFront);
    //    offsets = (21 - jFront) * 5;
    //    while ((jFront > 21 + 2) || (steps == 1 || steps == 3)) { //Geser Kanan
    //      navigasiKanan(offsets, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(offsets, 35, 22, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      offsets = (21 - jFront) * 5;
    //    }
    //    while ((jFront < 21 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //      navigasiKiri(offsets, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(offsets, 35, 22, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      offsets = (21 - jFront) * 5;
    //    }
    //    read_MPU();
    //    vTaskDelay(15 / portTICK_PERIOD_MS);
    //    yawSebelum = yaw;
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 35, 16);
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
    //    heightFront = -92;
    //    heightMid = -90;
    //    heightBack = -77;
    //    //===Jalan Turunan 2===//
    //    while (pitch <= -2 && stateMPU == false) {
    //      navigasiMPU_Maju(25);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(20, 35, 24, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      if (pitch >= -2) {
    //        xSemaphoreTake(mutex, portMAX_DELAY);
    //        stateMPU = true;
    //        xSemaphoreGive(mutex);
    //      }
    //    }
    //    //===Jalan Berbatu Menuju SZ-1===//
    //    heightFront = -92;
    //    heightMid = -92;
    //    heightBack = -92;
    //    baca_IR(IRfront);
    //    offsets = (distances - 4) * 5;
    //    if (offsets > 20) offsets = 20;
    //    if (offsets < -20) offsets = -20;
    //    while (distances > 4 && stateMPU == true) {
    //      //      navigasiMPU_Maju(offsets * 2);
    //      navigasiMaju(25, 22, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(offsets, 33, 26, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      baca_IR(IRfront);
    //      offsets = (distances - 4) * 5;
    //      if (offsets > 20) offsets = 20;
    //      if (offsets < -20) offsets = -20;
    //    }
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 35, 20);
    //      RotJarak(rightFront, rightBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    //======Geser SZ-1======//
    //    jFront = readPING(rightFront);
    //    offsets = (10 - jFront) * 5;
    //    while ((jFront > 10 + 2) || (steps == 1 || steps == 3)) {  //Geser Kanan
    //      navigasiKanan(offsets + 5, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(offsets, 35, 26, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      offsets = (10 - jFront) * 5;
    //    }
    //    while ((jFront < 10 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //      navigasiKiri(offsets + 5, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(offsets, 35, 26, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      offsets = (10 - jFront) * 5;
    //    }
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 35, 20);
    //      RotJarak(rightFront, rightBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    //====Rotate SZ-1====//
    //    RotateMPU(90, true);
    //    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 35, 34);
    //      xSemaphoreGive(mutex);
    //      RotateMPU();
    //    }
    //    RotJarak(leftFront, leftBack);
    //    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 35, 20);
    //      RotJarak(leftFront, leftBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    //====Geser SZ-1====//
    //    jFront = readPING(leftFront);
    //    while ((jFront < 9 - 2) || (steps == 1 || steps == 3)) {  //Geser Kanan
    //      navigasiKanan(22, leftFront, leftBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(22, 34, 32, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //    }
    //    while ((jFront > 9 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //      navigasiKiri(22, leftFront, leftBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(22, 34, 32, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //    }
    //    read_MPU();
    //    vTaskDelay(15 / portTICK_PERIOD_MS);
    //    sdtAcuan = yaw;
    //    //===Mundur SZ-1===//
    //    baca_IR(IRfront);
    //    while (distances < 15 || (steps == 1 || steps == 3)) {
    //      navigasiMPU_Mundur(22);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(-20, 35, 36, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      baca_IR(IRfront);
    //    }
    //    RotJarak(leftFront, leftBack);
    //    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 34, 26);
    //      RotJarak(leftFront, leftBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    //===Rotate dan taruh korban SZ-1===//
    //    RotateMPU(-27, true);
    //    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 34, 34);
    //      xSemaphoreGive(mutex);
    //      RotateMPU();
    //    }
    //    Standby();
    //    while (1) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      taruhKorban1(30);
    //      xSemaphoreGive(mutex);
    //      if (Capit == false) {
    //        break;
    //      }
    //    }
    //    RotateMPU(32, true);
    //    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 34, 34);
    //      xSemaphoreGive(mutex);
    //      RotateMPU();
    //    }
    //    RotJarak(leftFront, leftBack);
    //    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 34, 20);
    //      RotJarak(leftFront, leftBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    //==================================================================================================//
    //
    //    //================Dari SZ-1 Menuju SZ-2==============//
    //    sdtAcuan = yaw;
    //    baca_IR(IRfront);
    //    while (distances < 31 || (steps == 1 || steps == 3)) {
    //      navigasiMPU_Mundur(22);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(-20, 32, 24, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      baca_IR(IRfront);
    //    }
    //    RotJarak(leftFront, leftBack);
    //    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 30, 18);
    //      RotJarak(leftFront, leftBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    RotateMPU(88, true);
    //    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 28, 26);
    //      xSemaphoreGive(mutex);
    //      RotateMPU();
    //    }
    //    xSemaphoreTake(mutex, portMAX_DELAY);
    //    Standby();
    //    xSemaphoreGive(mutex);
    //    capit1.write(179);  //180 Kondisi Tutup //130 Buka
    //    capit2.write(1);
    //    RotateMPU(88, true);
    //    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 28, 26);
    //      xSemaphoreGive(mutex);
    //      RotateMPU();
    //    }
    //    jBack = readPING(rightBack);
    //    offsets = (20 - jBack) * 5;
    //    if (offsets > 22) offsets = 22;
    //    if (offsets < -22) offsets = -22;
    //    while ((jBack < 20 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //      navigasiKiri(22, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(offsets, 28, 24, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      offsets = (20 - jBack) * 5;
    //      if (offsets > 22) offsets = 22;
    //      if (offsets < -22) offsets = -22;
    //    }
    //    while ((jBack > 20 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //      navigasiKanan(22, rightFront, rightBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(offsets, 28, 24, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      offsets = (20 - jBack) * 5;
    //      if (offsets > 22) offsets = 22;
    //      if (offsets < -22) offsets = -22;
    //    }
    //    read_MPU();
    //    vTaskDelay(15 / portTICK_PERIOD_MS);
    //    yawSebelum = yaw;
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 28, 20);
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
    //    baca_IR(IRfront);
    //    //    offsets = (distances - 13) * 5;
    //    //    if (offsets > 22) offsets = 22;
    //    //    if (offsets < -22) offsets = -22;
    //    while (distances > 13) {
    //      navigasiMPU_Maju(24);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(22, 26, 20, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      baca_IR(IRfront);
    //      //      offsets = (distances - 13) * 5;
    //      //      if (offsets > 22) offsets = 22;
    //      //      if (offsets < -22) offsets = -22;
    //      //      if (distances <= 13) break;
    //    }
    //    RotJarak(rightFront, rightBack);
    //    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 30, 18);
    //      RotJarak(rightFront, rightBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    read_MPU();
    //    vTaskDelay(15 / portTICK_PERIOD_MS);
    //    yawSebelum = yaw;
    //    RotateMPU(88, true);
    //    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 30, 40);
    //      xSemaphoreGive(mutex);
    //      RotateMPU();
    //    }
    //    sdtAcuan = yawSebelum;
    //    while (sdtAcuan == yawSebelum) {
    //      read_MPU();
    //      vTaskDelay(15 / portTICK_PERIOD_MS);
    //      sdtAcuan = yaw;
    //    }
    //    sdtAcuan = yaw;
    //    baca_IR(IRfront);
    //    while (distances < 15 || (steps == 1 || steps == 3)) { //awalnya 17
    //      navigasiMPU_Mundur(22);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakDinamis(-22, 31, 34, lebarKiri, lebarKanan);
    //      xSemaphoreGive(mutex);
    //      baca_IR(IRfront);
    //    }
    //    jBack = readPING(leftBack);
    //    while ((jBack > 9 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //      navigasiKiri(22, leftFront, leftBack);
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakGeser(22, 35, 34, lebarKiri, lebarKanan, lebarTengah);
    //      xSemaphoreGive(mutex);
    //      baca_IR(IRfront);
    //      if (distances < 13) {
    //        while (distances < 14 || (steps == 1 || steps == 3)) {
    //          navigasiMPU_Mundur(20);
    //          xSemaphoreTake(mutex, portMAX_DELAY);
    //          GerakDinamis(-20, 35, 34, lebarKiri, lebarKanan);
    //          xSemaphoreGive(mutex);
    //          baca_IR(IRfront);
    //          if (distances >= 13) break;
    //        }
    //      }
    //    }
    //    jFront = readPING(leftFront);
    //    if (jFront > 9) {
    //      jBack = readPING(leftBack);
    //      while ((jBack > 9 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //        navigasiKiri(22, leftFront, leftBack);
    //        xSemaphoreTake(mutex, portMAX_DELAY);
    //        GerakGeser(22, 35, 34, lebarKiri, lebarKanan, lebarTengah);
    //        xSemaphoreGive(mutex);
    //        baca_IR(IRfront);
    //        if (distances < 13) {
    //          while (distances < 14 || (steps == 1 || steps == 3)) {
    //            navigasiMPU_Mundur(20);
    //            xSemaphoreTake(mutex, portMAX_DELAY);
    //            GerakDinamis(-20, 35, 34, lebarKiri, lebarKanan);
    //            xSemaphoreGive(mutex);
    //            baca_IR(IRfront);
    //            if (distances >= 13) break;
    //          }
    //        }
    //      }
    //    }
    //    RotJarak(leftFront, leftBack);
    //    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(OffsetJarak, 30, 24);
    //      RotJarak(leftFront, leftBack);
    //      xSemaphoreGive(mutex);
    //    }
    //    RotateMPU(-21, true);
    //    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      GerakRotasi(Offset, 30, 32);
    //      xSemaphoreGive(mutex);
    //      RotateMPU();
    //    }
    //    Standby();
    //    while (1) {
    //      xSemaphoreTake(mutex, portMAX_DELAY);
    //      taruhKorban2(25);
    //      xSemaphoreGive(mutex);
    //      if (Capit == false) {
    //        break;
    //      }
    //    }
    //    while (1) {
    //      Standby();
    //    }
    //== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == //
  }
}



//=== Logika Arena ===//
