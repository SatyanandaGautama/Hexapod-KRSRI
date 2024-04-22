void Sensor(void *pvParameters) {
  while (1) {
    //    Coding Gerak dari Start sampai SZ - 2 + Deteksi Korban 1
    //    == == == == = Dari Start sampai SZ - 1 == == == == == == //
    RotateMPU(90, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 22, 18);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 25, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //===Maju Dari Start===//
    baca_IR(IRback);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR < 29) || (steps == 1 || steps == 3)) {
      navigasiMaju(20, 20, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(10, 10, 4, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    RotateMPU(-91, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      GerakRotasi(Offset, 22, 22);
      RotateMPU();
    }
    dist = readPING(belakang);
    while (dist > 4 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-15, 20, 18, 0, 0);
      xSemaphoreGive(mutex);
      dist = readPING(belakang);
    }
    RotateMPU(-12, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      GerakRotasi(Offset, 18, 28);
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
    //== = Test Gerakan Ambil Korban K1 == =  //
    RotateMPU(90, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      GerakRotasi(Offset, 25, 16);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 22, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    jBack = readPING(rightBack);
    offsets = (21 - jBack) * 5;
    while ((jBack > 21 + 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 15, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      jBack = readPING(rightBack);
      offsets = (21 - jBack) * 5;
    }
    while ((jBack < 21 - 1) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 15, 22, lebarKiri, lebarKanan, lebarTengah);
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
    while ((pitch <= -15 && pitch > -23) && turunMPU == true) {  //+ depan naikk - depan Turun
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
      GerakRotasi(OffsetJarak, 40, 18);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //===Geser Turunan 1===//
    jFront = readPING(rightFront);
    offsets = (15 - jFront) * 5;
    while ((jFront > 15 + 2) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 40, 20, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (15 - jFront) * 5;
    }
    while ((jFront < 15 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 40, 20, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (15 - jFront) * 5;
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 40, 18);
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
      GerakDinamis(22, 38, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch >= -1) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        stateMPU = true;
        xSemaphoreGive(mutex);
      }
    }
    //== = Jalan Berbatu Menuju SZ - 1 == =  //
    heightFront = -92;
    heightMid = -92;
    heightBack = -92;
    baca_IR(IRfront);
    while (distances > 4 && stateMPU == true) {
      navigasiMPU_Maju(24);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(26, 37, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 37, 24);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    //====Rotate SZ-1====//
    RotateMPU(88, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 36, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 36, 26);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    //====Geser SZ-1====//
    jFront = readPING(leftFront);
    while ((jFront < 9) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 35, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 35, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 26);
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
      navigasiMPU_Mundur(28);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-26, 36, 35, lebarKiri, lebarKanan);
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
    while ((jFront < 9) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 34, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 34, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    //===Rotate dan taruh korban SZ-1===//
    RotateMPU(-16, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 34, 32);
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
    RotateMPU(22, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 34, 32);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 26);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    jFront = readPING(leftFront);
    while ((jFront < 9 - 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 26);
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
      GerakDinamis(-22, 40, 30, lebarKiri, lebarKanan);  //-21, 37, 28
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
      //      Serial.println(filtered_IR);
      if (filtered_IR < 25) {
        while (filtered_IR < 25) {
          navigasiMPU_Maju(22);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(22, 40, 30, lebarKiri, lebarKanan);  //-20, 36, 28
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
    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 26);
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
      GerakDinamis(-22, 40, 30, lebarKiri, lebarKanan);  //-20, 36, 28
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
      //      Serial.println(filtered_IR);
      if (filtered_IR < 25) {
        while (filtered_IR < 25) {
          navigasiMPU_Maju(22);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(22, 40, 30, lebarKiri, lebarKanan);  //-20, 36, 28
          xSemaphoreGive(mutex);
          baca_IR(IRback);
          filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
        }
      }
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 26);
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
      GerakRotasi(Offset, 32, 28);
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
      GerakRotasi(Offset, 34, 34);
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
    heightFront = -92;
    heightMid = -92;
    heightBack = -92;
    //===Test Gerakan Ambil Korban K2===//
    tujuan = sdtfix + 182;
    RotateMPU();  //110
    while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 35, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 22);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    jBack = readPING(rightBack);
    while ((jBack < 18 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(24, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 35, 24, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jBack > 18 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKanan(24, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 35, 24, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 22);
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
    bodyKanan.write(0);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    // Mencoba Gerak Lurus
    baca_IR(IRfront);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 7) || (steps == 1 || steps == 3)) {  //Asli 13
      baca_IR(IRright);
      if (distances < 14) {
        while (distances < 19 || (steps == 1 || steps == 3)) {
          navigasiMPU_Kiri(29);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakGeser(27, 40, 32, lebarKiri, lebarKanan, lebarTengah);
          xSemaphoreGive(mutex);
          baca_IR(IRright);
          if (distances >= 19) break;
        }
      }
      navigasiMPU_Maju(26);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(24, 40, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    baca_IR(IRfront);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 7) || (steps == 1 || steps == 3)) {  //Asli 13
      baca_IR(IRright);
      if (distances < 14) {
        while (distances < 19 || (steps == 1 || steps == 3)) {
          navigasiMPU_Kiri(29);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakGeser(27, 40, 32, lebarKiri, lebarKanan, lebarTengah);
          xSemaphoreGive(mutex);
          baca_IR(IRright);
          if (distances >= 19) break;
        }
      }
      navigasiMPU_Maju(26);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(24, 40, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    bodyKanan.write(360);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    RotateMPU(90, true);
    while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 35, 28);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    sdtAcuan = yaw;
    heightFront = -92;
    heightMid = -92;
    heightBack = -92;
    jBack = readPING(leftBack);
    jFront = readPING(leftFront);
    while ((jBack > 10 || jFront > 10) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri(18, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 35, 28, lebarKiri, lebarKanan, lebarTengah);  //22 36 38
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      if (distances < 15) {
        while (distances < 17 || (steps == 1 || steps == 3)) {
          navigasiMPU_Mundur(18);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(-18, 35, 28, lebarKiri, lebarKanan);
          xSemaphoreGive(mutex);
          baca_IR(IRfront);
          if (distances >= 17) break;
        }
      }
    }
    jFront = readPING(leftFront);
    if (jFront > 9) {
      jBack = readPING(leftBack);
      while ((jBack > 10 || jFront > 10) || (steps == 1 || steps == 3)) {  //Geser Kiri
        navigasiKiri(18, leftFront, leftBack);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(18, 35, 28, lebarKiri, lebarKanan, lebarTengah);  //22, 40, 36
        xSemaphoreGive(mutex);
        baca_IR(IRfront);
        if (distances < 15) {
          while (distances < 17 || (steps == 1 || steps == 3)) {
            navigasiMPU_Mundur(18);
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakDinamis(-18, 35, 28, lebarKiri, lebarKanan);
            xSemaphoreGive(mutex);
            baca_IR(IRfront);
            if (distances >= 17) break;
          }
        }
      }
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 24);
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
      GerakDinamis(-20, 35, 24, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    baca_IR(IRfront);
    while (distances > 15 || (steps == 1 || steps == 3)) {  //awalnya 15
      navigasiMPU_Maju(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 35, 24, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 24);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    RotateMPU(-15, true);
    while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 32, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    //Taruh Korban 2//
    Standby();
    while (1) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      taruhKorban2(25);
      xSemaphoreGive(mutex);
      if (Capit == false) {
        break;
      }
    }
    // Akhir coba gerakan






    // //////////////////////////////////////////////////////////////////////////////////////////////////////////
    // RotateMPU(15, true);
    // while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
    //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   GerakRotasi(Offset, 32, 34);
    //   xSemaphoreGive(mutex);
    //   RotateMPU();
    // }
    // read_MPU();
    // vTaskDelay(15 / portTICK_PERIOD_MS);
    // yawSebelum = yaw;
    // RotJarak(rightFront, rightBack);
    // while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
    //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   GerakRotasi(OffsetJarak, 34, 26);
    //   RotJarak(rightFront, rightBack);
    //   xSemaphoreGive(mutex);
    // }
    // sdtAcuan = yawSebelum;
    // while (sdtAcuan == yawSebelum) {
    //   read_MPU();
    //   vTaskDelay(15 / portTICK_PERIOD_MS);
    //   sdtAcuan = yaw;
    // }
    // sdtAcuan = yaw;
    // baca_IR(IRback);
    // // filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    // while (distances > 4 || (steps == 1 || steps == 3)) {
    //   navigasiMPU_Mundur(24);
    //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   GerakDinamis(-22, 28, 24, lebarKiri, lebarKanan);
    //   xSemaphoreGive(mutex);
    //   baca_IR(IRback);
    //   // filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    //   // if (distances > 25) {
    //   //   jBack = readPING(leftBack);
    //   //   jFront = readPING(leftFront);
    //   //   while ((jBack > 11 || jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //   //     navigasiKiri(20, leftFront, leftBack);
    //   //     xSemaphoreTake(mutex, portMAX_DELAY);
    //   //     GerakGeser(18, 30, 26, lebarKiri, lebarKanan, lebarTengah);  //22, 40, 36
    //   //     xSemaphoreGive(mutex);
    //   //   }
    // }
    // jBack = readPING(leftBack);
    // jFront = readPING(leftFront);
    // while ((jBack < 14 || jFront < 14) || (steps == 1 || steps == 3)) {  //Geser Kiri
    //   navigasiKanan(20, leftBack, leftFront);
    //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   GerakGeser(-18, 30, 22, lebarKiri, lebarKanan, lebarTengah);  //22, 40, 36
    //   xSemaphoreGive(mutex);
    // }
    // RotJarak(leftBack, leftFront);
    // while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
    //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   GerakRotasi(OffsetJarak, 30, 22);
    //   RotJarak(leftBack, leftFront);
    //   xSemaphoreGive(mutex);
    // }
    // read_MPU();
    // vTaskDelay(15 / portTICK_PERIOD_MS);
    // yawSebelum = yaw;
    // RotateMPU(-90, true);
    // while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
    //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   GerakRotasi(Offset, 25, 22);
    //   xSemaphoreGive(mutex);
    //   RotateMPU();
    // }
    // sdtAcuan = yawSebelum;
    // while (sdtAcuan == yawSebelum) {
    //   read_MPU();
    //   vTaskDelay(15 / portTICK_PERIOD_MS);
    //   sdtAcuan = yaw;
    // }
    // baca_IR(IRback);
    // while (distances > 4 || (steps == 1 || steps == 3)) {
    //   navigasiMPU_Mundur(25);
    //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   GerakDinamis(-25, 30, 22, lebarKiri, lebarKanan);
    //   xSemaphoreGive(mutex);
    //   baca_IR(IRback);
    // }
    while (1) {
      Standby();
    }
    //== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == //
  }
}
