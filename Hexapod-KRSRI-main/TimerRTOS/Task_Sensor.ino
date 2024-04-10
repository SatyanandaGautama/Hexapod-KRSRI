void Sensor(void *pvParameters) {
  while (1) {
    //    Coding Gerak dari Start sampai SZ - 2 + Deteksi Korban 1
    //    == == == == = Dari Start sampai SZ - 1 == == == == == == //
    RotateMPU(90, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
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
    while ((distances < 27 || distances > 28) || (steps == 1 || steps == 3)) {
      navigasiMaju(20, 20, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(15, 15, 6, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
    }
    RotateMPU(-91, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      GerakRotasi(Offset, 20, 34);
      RotateMPU();
    }
    dist = readPING(belakang);
    while (dist > 4 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-15, 15, 26, 0, 0);
      xSemaphoreGive(mutex);
      dist = readPING(belakang);
    }
    RotateMPU(-10, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      GerakRotasi(Offset, 18, 30);
      RotateMPU();
    }
    //===Test Gerakan Ambil Korban K1===//
    huskylens.request();
    if (huskylens.available()) {
      while (Sensors == true) {
        read_maix();
        if (result.xCenter > 172) {
          while (result.xCenter > 172 || (steps == 1 || steps == 3)) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakRotasi(5, 15, 30);
            xSemaphoreGive(mutex);
            read_maix();
          }
        } else if (result.xCenter < 166) {
          while (result.xCenter < 166 || (steps == 1 || steps == 3)) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakRotasi(-5, 15, 30);
            xSemaphoreGive(mutex);
            read_maix();
          }
        } else {
          Standby();
          while (1) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            BodyMundur(25);
            xSemaphoreGive(mutex);
            if (Capit == false) {
              break;
            }
          }
          readSRF();
          while (jarak > 3) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            BodyMaju(80);
            xSemaphoreGive(mutex);
            if (Capit == false) break;
            readSRF();
          }
          Capit = false;
          tServo = 0;
          tDyn = 0;
          statusGerak = false;
          xSemaphoreTake(mutex, portMAX_DELAY);
          stepss = 0;
          xSemaphoreGive(mutex);
          while (1) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            BodyBalik(25);
            xSemaphoreGive(mutex);
            if (Capit == false) {
              Sensors = false;
              break;
            }
          }
        }
      }
    } else {
      while (Sensors == true) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakRotasi(8, 17, 40);
        xSemaphoreGive(mutex);
        huskylens.request();
        if (huskylens.available()) {
          while (Sensors == true) {
            read_maix();
            if (result.xCenter > 172) {
              while (result.xCenter > 172 || (steps == 1 || steps == 3)) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                GerakRotasi(5, 15, 36);
                xSemaphoreGive(mutex);
                read_maix();
              }
            } else if (result.xCenter < 166) {
              while (result.xCenter < 166 || (steps == 1 || steps == 3)) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                GerakRotasi(-5, 15, 36);
                xSemaphoreGive(mutex);
                read_maix();
              }
            } else {
              jmlhStep = 0;
              while (jmlhStep < 2) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                if (steps == 0 && statusGerak == false) {
                  jmlhStep++;
                }
                GerakDinamis(-7, 15, 36, 0, 0);
                xSemaphoreGive(mutex);
              }
              statusGerak = false;
              while (1) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                BodyMundur(25);
                xSemaphoreGive(mutex);
                if (Capit == false) {
                  break;
                }
              }
              readSRF();
              while (jarak > 3) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                BodyMaju(80);
                xSemaphoreGive(mutex);
                if (Capit == false) break;
                readSRF();
              }
              Capit = false;
              tServo = 0;
              tDyn = 0;
              statusGerak = false;
              xSemaphoreTake(mutex, portMAX_DELAY);
              stepss = 0;
              xSemaphoreGive(mutex);
              while (1) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                BodyBalik(25);
                xSemaphoreGive(mutex);
                if (Capit == false) {
                  Sensors = false;
                  break;
                }
              }
            }
          }
        }
      }
    }
    //===Test Gerakan Ambil Korban K1===//
    RotateMPU(90, true);
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
    jBack = readPING(rightBack);
    offsets = (21 - jBack) * 5;
    while ((jBack > 21 + 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      jBack = readPING(rightBack);
      offsets = (21 - jBack) * 5;
    }
    while ((jBack < 21 - 1) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 15, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      jBack = readPING(rightBack);
      offsets = (21 - jBack) * 5;
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
    while ((pitch <= -15 && pitch > -20) && turunMPU == true) {  //+ depan naikk - depan Turun
      navigasiMPU_Maju(34);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(22, 47, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch > -15) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        turunMPU = false;
        xSemaphoreGive(mutex);
        break;
      }
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 18);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //===Geser Turunan 1===//
    jFront = readPING(rightFront);
    offsets = (15 - jFront) * 5;
    while ((jFront > 15 + 2) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 35, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (15 - jFront) * 5;
    }
    while ((jFront < 15 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 35, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (15 - jFront) * 5;
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 18);
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
    while (pitch <= -1 && stateMPU == false) {
      navigasiMPU_Maju(25);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 35, 24, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch >= -1) {
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
    //    offsets = (distances - 4) * 5;
    //    if (offsets > 20) offsets = 20;
    //    if (offsets < -20) offsets = -20;
    while (distances > 4 && stateMPU == true) {
      navigasiMPU_Maju(24);
      //      navigasiMaju(25, 22, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(22, 34, 26, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      //      offsets = (distances - 4) * 5;
      //      if (offsets > 20) offsets = 20;
      //      if (offsets < -20) offsets = -20;
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 22);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //====Rotate SZ-1====//
    RotateMPU(88, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 35, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 26);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    //====Geser SZ-1====//
    jFront = readPING(leftFront);
    while ((jFront < 9) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 9) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 28);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    sdtAcuan = yawSebelum;
    while (sdtAcuan == yawSebelum) {
      read_MPU();
      vTaskDelay(15 / portTICK_PERIOD_MS);
      sdtAcuan = yaw;
    }
    sdtAcuan = yaw;
    sdtMaju = yaw;
    //===Mundur SZ-1===//
    baca_IR(IRfront);
    while (distances < 15 || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-21, 34, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 28);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    jFront = readPING(leftFront);
    while ((jFront < 9 - 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 9 + 1) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    //===Rotate dan taruh korban SZ-1===//
    RotateMPU(-18, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 35, 40);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    Standby();
    while (1) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      taruhKorban1(30);
      xSemaphoreGive(mutex);
      if (Capit == false) {
        break;
      }
    }
    RotateMPU(18, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 35, 40);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 28);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    jFront = readPING(leftFront);
    while ((jFront < 9 - 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 9 + 1) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 30);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    sdtAcuan = yawSebelum;
    while (sdtAcuan == yawSebelum) {
      read_MPU();
      vTaskDelay(15 / portTICK_PERIOD_MS);
      sdtAcuan = yaw;
    }
    //    sdtAcuan = yaw;
    sdtAcuan = sdtMaju;
    sdtfix = yaw;
    //== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==  //
    heightFront = -94;
    heightMid = -94;
    heightBack = -94;
    // //====Gerakan Ambil Korban 2 sampai taruh safety zone 2====//
    //================Dari SZ-1 Menuju SZ-2==============//
    baca_IR(IRback);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 26 || filtered_IR < 25) || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-21, 37, 28, lebarKiri, lebarKanan); //-20, 36, 28
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
      //      Serial.println(filtered_IR);
      if (filtered_IR < 25) {
        while (filtered_IR < 25) {
          navigasiMPU_Maju(22);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(21, 37, 28, lebarKiri, lebarKanan); //-20, 36, 28
          xSemaphoreGive(mutex);
          baca_IR(IRback);
          filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
        }
      }
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 30);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    sdtAcuan = yawSebelum;
    while (sdtAcuan == yawSebelum) {
      read_MPU();
      vTaskDelay(15 / portTICK_PERIOD_MS);
      sdtAcuan = yaw;
    }
    //    sdtAcuan = yaw;
    sdtAcuan = sdtMaju;
    baca_IR(IRback);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 26 || filtered_IR < 25) || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-21, 37, 28, lebarKiri, lebarKanan); //-20, 36, 28
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
      //      Serial.println(filtered_IR);
      if (filtered_IR < 25) {
        while (filtered_IR < 25) {
          navigasiMPU_Maju(22);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(21, 37, 28, lebarKiri, lebarKanan); //-20, 36, 28
          xSemaphoreGive(mutex);
          baca_IR(IRback);
          filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
        }
      }
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 28);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    heightFront = -92;
    heightMid = -92;
    heightBack = -92;
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    tujuan = sdtfix + 90;
    RotateMPU();
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 32, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    heightFront = -94;
    heightMid = -94;
    heightBack = -94;
    dist = readPING(belakang);
    while (dist > 7 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-12, 34, 30, 0, 0);
      xSemaphoreGive(mutex);
      dist = readPING(belakang);
    }
    heightFront = -92;
    heightMid = -92;
    heightBack = -92;
    RotateMPU(-23, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 34, 36);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    Sensors = true;
    //===Test Gerakan Ambil Korban K2===//
    huskylens.request();
    if (huskylens.available()) {
      while (Sensors == true) {
        read_maix();
        if (result.xCenter > 174) {
          while (result.xCenter > 174 || (steps == 1 || steps == 3)) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakRotasi(12, 28, 40);
            xSemaphoreGive(mutex);
            read_maix();
          }
        } else if (result.xCenter < 168) {
          while (result.xCenter < 168 || (steps == 1 || steps == 3)) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakRotasi(-12, 28, 40);
            xSemaphoreGive(mutex);
            read_maix();
          }
        } else {
          Standby();
          while (1) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            BodyMundur_K2(50);
            xSemaphoreGive(mutex);
            if (Capit == false) {
              break;
            }
          }
          readSRF();
          while (jarak > 3) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            BodyMaju_K2(80);
            xSemaphoreGive(mutex);
            if (Capit == false) break;
            readSRF();
          }
          Capit = false;
          tServo = 0;
          tDyn = 0;
          statusGerak = false;
          xSemaphoreTake(mutex, portMAX_DELAY);
          stepss = 0;
          xSemaphoreGive(mutex);
          while (1) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            BodyBalik_K2(25);
            xSemaphoreGive(mutex);
            if (Capit == false) {
              Sensors = false;
              break;
            }
          }
        }
      }
    } else {
      while (Sensors == true) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakRotasi(16, 28, 40);
        xSemaphoreGive(mutex);
        huskylens.request();
        if (huskylens.available()) {
          while (Sensors == true) {
            read_maix();
            if (result.xCenter > 174) {
              while (result.xCenter > 174 || (steps == 1 || steps == 3)) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                GerakRotasi(12, 28, 40);
                xSemaphoreGive(mutex);
                read_maix();
              }
            } else if (result.xCenter < 168) {
              while (result.xCenter < 168 || (steps == 1 || steps == 3)) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                GerakRotasi(-12, 28, 40);
                xSemaphoreGive(mutex);
                read_maix();
              }
            } else {
              Standby();
              while (1) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                BodyMundur_K2(50);
                xSemaphoreGive(mutex);
                if (Capit == false) {
                  break;
                }
              }
              readSRF();
              while (jarak > 3) {
                xSemaphoreTake(mutex, portMAX_DELAY);
                BodyMaju_K2(80);
                xSemaphoreGive(mutex);
                if (Capit == false) break;
                readSRF();
              }
              Capit = false;
              tServo = 0;
              tDyn = 0;
              statusGerak = false;
              xSemaphoreTake(mutex, portMAX_DELAY);
              stepss = 0;
              xSemaphoreGive(mutex);
              while (1) {
                (mutex, portMAX_DELAY);
                BodyBalik_K2(25);
                xSemaphoreGive(mutex);
                if (Capit == false) {
                  Sensors = false;
                  break;
                }
              }
            }
          }
        }
      }
    }
    heightFront = -94;
    heightMid = -94;
    heightBack = -94;
    //===Test Gerakan Ambil Korban K2===//
    tujuan = sdtfix + 185;
    RotateMPU();//110
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 35, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      RotJarak(rightFront, rightBack);
      GerakRotasi(OffsetJarak, 32, 28);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    jBack = readPING(rightBack);
    while ((jBack < 20 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(24, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 35, 30, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jBack > 20 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKanan(24, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 35, 30, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 30);
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
    heightMid = -92;
    heightBack = -92;
    baca_IR(IRfront);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 13 || filtered_IR < 12) || (steps == 1 || steps == 3)) {  //Asli 13
      navigasiMPU_Maju(26);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(24, 40, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
      //      Serial.println(filtered_IR);
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 36, 30);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    baca_IR(IRfront);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 13 || filtered_IR < 12) || (steps == 1 || steps == 3)) {  //Asli 13
      navigasiMPU_Maju(26);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(24, 40, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 36, 30);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotateMPU(90, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 36, 34);
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
    while (distances < 17 || (steps == 1 || steps == 3)) {  //awalnya 15
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-22, 31, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    jBack = readPING(leftBack);
    jFront = readPING(leftFront);
    while ((jBack > 9 || jFront > 9) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(24, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 40, 36, lebarKiri, lebarKanan, lebarTengah);//22 36 38
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      if (distances < 14) {
        while (distances < 14 || (steps == 1 || steps == 3)) {
          navigasiMPU_Mundur(22);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(-18, 32, 36, lebarKiri, lebarKanan);
          xSemaphoreGive(mutex);
          baca_IR(IRfront);
          if (distances >= 14) break;
        }
      }
    }
    jFront = readPING(leftFront);
    if (jFront > 9) {
      jBack = readPING(leftBack);
      while ((jBack > 9 || jFront > 9) || (steps == 1 || steps == 3)) {  //Geser Kiri
        navigasiKiri(24, leftFront, leftBack);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(22, 40, 36, lebarKiri, lebarKanan, lebarTengah); //22, 40, 36
        xSemaphoreGive(mutex);
        baca_IR(IRfront);
        if (distances < 14) {
          while (distances < 14 || (steps == 1 || steps == 3)) {
            navigasiMPU_Mundur(22);
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakDinamis(-18, 31, 36, lebarKiri, lebarKanan);
            xSemaphoreGive(mutex);
            baca_IR(IRfront);
            if (distances >= 14) break;
          }
        }
      }
    }
    heightFront = -92;
    heightMid = -92;
    heightBack = -92;
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 26);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    baca_IR(IRfront);
    while (distances < 14 || (steps == 1 || steps == 3)) {  //awalnya 15
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-20, 30, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 26);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    RotateMPU(-15, true);
    while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 30, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    Standby();
    while (1) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      taruhKorban2(25);
      xSemaphoreGive(mutex);
      if (Capit == false) {
        break;
      }
    }
    while (1) {
      Standby();
    }
    //== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == //
  }
}
