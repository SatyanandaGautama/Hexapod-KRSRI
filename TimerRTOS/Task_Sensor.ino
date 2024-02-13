void Sensor(void *pvParameters) {
  while (1) {
    //    baca_IR(IRfront);
    //    Serial.print("IR Front : ");
    //    Serial.println(distances);
    //    baca_IR(IRback);
    //    Serial.print("IR Back : ");
    //    Serial.println(distances);
    //    Serial.print("Right Front : ");
    //    Serial.println(readPING(rightFront));
    //    Serial.print("Right Back : ");
    //    Serial.println(readPING(rightBack));
    //    Serial.print("Left Front : ");
    //    Serial.println(readPING(leftFront));
    //    Serial.print("Left Back : ");
    //    Serial.println(readPING(leftBack));
    //=====================================//
    RotateMPU(90, true);
    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 30, 28);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    yawSebelum = yaw;
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 18);
      RotJarak(leftFront, leftBack);
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
    while (distances < 12 || (steps == 0 || steps == 2)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-22, 27, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 16);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    j2 = readPING(leftBack);
    offsets = (14 - j2) * 5;
    if (offsets > 20)offsets = 20;
    if (offsets < -20)offsets = -20;
    while ((j2 < 14 + 3) || (steps == 0 || steps == 2)) { //Geser Kanan
      navigasiKanan(20, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 30, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = -((14 - j2) * 5);
      if (offsets > 20)offsets = 20;
      if (offsets < -20)offsets = -20;
    }
    while ((j2 > 14 - 3) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKiri(20, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 30, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = -((14 - j2) * 5);
      if (offsets > 20)offsets = 20;
      if (offsets < -20)offsets = -20;
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 2 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 27, 16);
      RotJarak(leftFront, leftBack);
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
    while (distances < 28) {
      navigasiMPU_Mundur(25);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-24, 27, 20, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftFront, leftBack);
    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 27, 16);
      RotJarak(leftFront, leftBack);
      xSemaphoreGive(mutex);
    }
    RotateMPU(90, true);
    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 26, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    Standby();
    RotateMPU(90, true);
    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 26, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 27, 16);
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
    offsets = (distances - 14) * 5;
    if (offsets > 20)offsets = 20;
    if (offsets < -20)offsets = -20;
    while (distances > 15) {
      navigasiMPU_Maju(20);
      //      navigasiMaju(20, offsets + 2, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(offsets, 27, 20, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      offsets = (distances - 13) * 5;
      if (offsets > 20)offsets = 20;
      if (offsets < -20)offsets = -20;
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 27, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    j2 = readPING(rightBack);
    offsets = (40 - j2) * 5;
    if (offsets > 22)offsets = 22;
    if (offsets < -22)offsets = -22;
    while ((j2 < 40 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKiri(22, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 31, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (40 - j2) * 5;
      if (offsets > 22)offsets = 22;
      if (offsets < -22)offsets = -22;
    }
    while ((j2 > 40 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      navigasiKanan(22, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 30, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (40 - j2) * 5;
      if (offsets > 22)offsets = 22;
      if (offsets < -22)offsets = -22;
    }
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 27, 16);
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
    offsets = (distances - 7) * 5;
    if (offsets > 20)offsets = 20;
    if (offsets < -20)offsets = -20;
    while (distances > 7) {
      //      navigasiMaju(20, offsets + 2, rightFront, rightBack);
      navigasiMPU_Maju(24);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(offsets, 27, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      offsets = (distances - 7) * 5;
      if (offsets > 20)offsets = 20;
      if (offsets < -20)offsets = -20;
    }
    j2 = readPING(rightBack);
    offsets = (40 - j2) * 5;
    if (offsets > 22)offsets = 22;
    if (offsets < -22)offsets = -22;
    while ((j2 < 40 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 31, 28, 0, 0, 0);
      xSemaphoreGive(mutex);
      j2 = readPING(rightBack);
      offsets = (40 - j2) * 5;
      if (offsets > 22)offsets = 22;
      if (offsets < -22)offsets = -22;
    }
    while ((j2 > 40 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 31, 28, 0, 0, 0);
      xSemaphoreGive(mutex);
      j2 = readPING(rightBack);
      offsets = (40 - j2) * 5;
      if (offsets > 22)offsets = 22;
      if (offsets < -22)offsets = -22;
    }
    RotateMPU(90, true);
    while (abs(Offset) > 2 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 30, 24);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 27, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    RotateMPU(-30, true);
    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 30, 24);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    while (1) {
      Standby();
    }
  }
}







//=== Logika Arena ===//
//=== Logika Strat sampai SZ-1 ===//
//    RotateMPU(90, true);
//    while (abs(Offset) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 20, 16);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 20, 16);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    baca_IR(IRback);
//    while (distances < 26 || (steps == 0 || steps == 2)) {
//      navigasiMaju(20, 20, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(15, 15, 6, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      baca_IR(IRback);
//    }
//    RotateMPU(-90, true);
//    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
//      GerakRotasi(Offset, 18, 18);
//      RotateMPU();
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    Standby();
//    xSemaphoreGive(mutex);
//    RotateMPU(90, true);
//    while (abs(Offset) > 1 || (steps == 0 || steps == 2)) {
//      GerakRotasi(Offset, 18, 18);
//      RotateMPU();
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 20, 16);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    j2 = readPING(rightBack);
//    offsets = (31 - j2) * 5;
//    while ( (j2 > 31 + 2) || (steps == 0 || steps == 2)) { //Geser Kanan
//      navigasiKanan(offsets, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      j2 = readPING(rightBack);
//      offsets = (31 - j2) * 5;
//    }
//    while ((j2 < 31 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
//      navigasiKiri(offsets, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      j2 = readPING(rightBack);
//      offsets = (31 - j2) * 5;
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
//    //===Jalan Pecah===//
//    while (pitch < 17 && turunMPU == false) {
//      navigasiMPU_Maju(34);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(26, 47, 32, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      if (pitch >= 17) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        turunMPU = true;
//        xSemaphoreGive(mutex);
//        break;
//      }
//    }
//    //===Jalan Turunan 1===//
//    while ((pitch >= 13 && pitch < 30) && turunMPU == true) {
//      navigasiMPU_Maju(30);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(26, 47, 32, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      if (pitch < 13) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        turunMPU = false;
//        xSemaphoreGive(mutex);
//        break;
//      }
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) >  1 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 20, 12);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    j3 = readPING(rightFront);
//    offsets = (24 - j3) * 5;
//    while ( (j3 > 24 + 2) || (steps == 0 || steps == 2)) { //Geser Kanan
//      navigasiKanan(offsets, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(offsets, 20, 22, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      offsets = (24 - j3) * 5;
//    }
//    while ((j3 < 24 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
//      navigasiKiri(offsets, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(offsets, 20, 22, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      offsets = (24 - j3) * 5;
//    }
//    read_MPU();
//    vTaskDelay(15 / portTICK_PERIOD_MS);
//    yawSebelum = yaw;
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 20, 12);
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
//    while (pitch >= 2 && stateMPU == false) {
//      navigasiMPU_Maju(40);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(20, 26, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      if (pitch < 2) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        stateMPU = true;
//        xSemaphoreGive(mutex);
//        break;
//      }
//    }
//    //===Jalan Berbatu===//
//    heightFront = -92;
//    heightMid = -92;
//    heightBack = -92;
//    baca_IR(IRfront);
//    offsets = (distances - 10) * 5;
//    if (offsets > 20)offsets = 20;
//    if (offsets < -20)offsets = -20;
//    while (distances > 10 && stateMPU == true) {
//      //      navigasiMPU_Maju(offsets * 2);
//      navigasiMaju(25, offsets + 2, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(offsets, 26, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      baca_IR(IRfront);
//      offsets = (distances - 10) * 5;
//      if (offsets > 20)offsets = 20;
//      if (offsets < -20)offsets = -20;
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 25, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    //======Geser SZ-1======//
//    j3 = readPING(rightFront);
//    offsets = (31 - j3) * 5;
//    while ((j3 > 31 + 2) || (steps == 0 || steps == 2)) { //Geser Kanan
//      navigasiKanan(offsets + 5, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(offsets, 26, 26, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      offsets = (31 - j3) * 5;
//    }
//    while ((j3 < 31 - 2) || (steps == 0 || steps == 2)) { //Geser Kiri
//      navigasiKiri(offsets + 5, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(offsets, 26, 26, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      offsets = (31 - j3) * 5;
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 1 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 26, 24);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    RotateMPU(30, true);
//    while (abs(Offset) > 3 || (steps == 0 || steps == 2)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 26, 26);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    Standby();
