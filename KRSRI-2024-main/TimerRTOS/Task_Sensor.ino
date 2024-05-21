void Sensor(void *pvParameters) {
  while (1) {
    //    Coding Gerak dari Start sampai SZ - 2 + Deteksi Korban 1
    //    == == == == = Dari Start sampai SZ - 1 == == == == == == //
    while (ButtonState == 1) {
      ButtonState = digitalRead(Button);
      if (ButtonState == 0) {
        display.clearDisplay();
        break;
      }
    }
    dist = readPING(rightBack);
    dist1 = readPING(leftBack);
    if (dist > dist1) {
      RotateMPU(90, true);
      while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakRotasi(Offset, 20, 16);
        xSemaphoreGive(mutex);
        RotateMPU();
      }
    } else {
      RotateMPU(-90, true);
      while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakRotasi(Offset, 20, 16);
        xSemaphoreGive(mutex);
        RotateMPU();
      }
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 25, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    //===Maju Dari Start===//
    baca_IR(IRback);
    filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
    while ((filtered_IR < 31) || (steps == 1 || steps == 3)) {
      navigasiMaju(20, 20, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(15, 12, 4, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
    }
    // memastikan lewat home
    while ((distances < 31) || (steps == 1 || steps == 3)) {
      navigasiMaju(20, 20, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(15, 12, 4, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
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
    jmlhStep = 0;
    huskylens.request();
    if (huskylens.available()) {
      while (jmlhStep < 1) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        if (steps == 0 && statusGerak == false) {
          jmlhStep++;
        }
        GerakDinamis(7, 17, 26, 0, 0);
        xSemaphoreGive(mutex);
      }
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
            BodyMaju(70);
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
      RotateMPU(-14, true);
      while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
        GerakRotasi(Offset, 18, 24);
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
              BodyMaju(70);
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
          GerakRotasi(10, 15, 26);  //8,17,30
          xSemaphoreGive(mutex);
          huskylens.request();
          if (huskylens.available()) {
            while (Sensors == true) {
              read_maix();
              if (result.xCenter > 172) {
                while (result.xCenter > 172 || (steps == 1 || steps == 3)) {
                  xSemaphoreTake(mutex, portMAX_DELAY);
                  GerakRotasi(5, 15, 30);  //36
                  xSemaphoreGive(mutex);
                  read_maix();
                }
              } else if (result.xCenter < 166) {
                while (result.xCenter < 166 || (steps == 1 || steps == 3)) {
                  xSemaphoreTake(mutex, portMAX_DELAY);
                  GerakRotasi(-5, 15, 30);  //36
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
                  GerakDinamis(-7, 15, 26, 0, 0);
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
                  BodyMaju(70);
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
    }
    //== = Test Gerakan Ambil Korban K1 == =  //
    RotateMPU(90, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      GerakRotasi(Offset, 25, 16);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 25, 16);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    jBack = readPING(rightBack);
    offsets = (16 - jBack) * 5;
    while ((jBack > 16 + 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan_pingKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 27, 18, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      jBack = readPING(rightBack);
      offsets = (16 - jBack) * 5;  //21
    }
    while ((jBack < 16 - 1) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri_pingKanan(offsets, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 27, 18, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      jBack = readPING(rightBack);
      offsets = (16 - jBack) * 5;
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
    //===Jalan Pecah===//
    while (pitch > -16 && turunMPU == false) {
      navigasiMPU_Maju(34);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(23, 47, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch <= -16) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        turunMPU = true;
        xSemaphoreGive(mutex);
        break;
      }
    }
    //===Jalan Turunan 1 (Memastikan agar lewat dari Jalan Pecah)===//
    while ((pitch <= -15 && pitch > -27) && turunMPU == true) {  //+ depan naikk - depan Turun //
      navigasiMPU_Maju(34);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(25, 47, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch > -15) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        turunMPU = false;
        xSemaphoreGive(mutex);
        break;
      }
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 40, 18);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
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
    heightFR = -92;
    heightRM = -90;
    heightBR = -77;
    heightFL = -92;
    heightLM = -90;
    heightBL = -77;
    //===Jalan Turunan 2===//
    while (pitch <= -1 && stateMPU == false) {
      navigasiMPU_Maju(25);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(25, 41, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (pitch >= -1) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        stateMPU = true;
        xSemaphoreGive(mutex);
      }
    }
    //== = Jalan Berbatu Menuju SZ - 1 == =  //
    heightFR = -92;
    heightRM = -92;
    heightBR = -92;
    heightFL = -92;
    heightLM = -92;
    heightBL = -92;
    baca_IR(IRfront);
    while (distances > 4 && stateMPU == true) {
      navigasiMPU_Maju(24);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(24, 37, 22, lebarKiri, lebarKanan);
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
      navigasiKanan_pingKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 35, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri_pingKiri(22, leftFront, leftBack);
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
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 28);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    jFront = readPING(leftFront);
    while ((jFront < 9) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan_pingKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 34, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri_pingKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 34, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    //===Rotate dan taruh korban SZ-1===//
    RotateMPU(-15, true);
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
    RotateMPU(17, true);  //22
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 34, 32);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 24);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    jFront = readPING(leftFront);
    while ((jFront < 9 - 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan_pingKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri_pingKiri(22, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(16, 34, 28, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 24);
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
    heightFR = -94;
    heightRM = -94;
    heightBR = -94;
    heightFL = -94;
    heightLM = -94;
    heightBL = -94;
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
      GerakRotasi(OffsetJarak, 35, 24);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    sdtAcuan = yawSebelum;
    while (sdtAcuan == yawSebelum) {
      read_MPU();
      vTaskDelay(15 / portTICK_PERIOD_MS);
      sdtAcuan = yaw;
    }
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
      GerakRotasi(OffsetJarak, 35, 22);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    heightFR = -92;
    heightRM = -92;
    heightBR = -92;
    heightFL = -92;
    heightLM = -92;
    heightBL = -92;
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
    heightFR = -94;
    heightRM = -94;
    heightBR = -94;
    heightFL = -94;
    heightLM = -94;
    heightBL = -94;
    dist = readPING(belakang);
    while (dist > 8 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-12, 34, 28, 0, 0);
      xSemaphoreGive(mutex);
      dist = readPING(belakang);
    }
    dist = readPING(belakang);
    while (dist < 6 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-14, 34, 28, 0, 0);
      xSemaphoreGive(mutex);
      dist = readPING(belakang);
    }
    heightFR = -92;
    heightRM = -92;
    heightBR = -92;
    heightFL = -92;
    heightLM = -92;
    heightBL = -92;
    Sensors = true;
    //===Test Gerakan Ambil Korban K2===//
    huskylens.request();
    if (huskylens.available()) {
      while (Sensors == true) {
        read_maix();
        if (result.xCenter > 175) {
          while (result.xCenter > 175 || (steps == 1 || steps == 3)) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakRotasi(12, 28, 40);
            xSemaphoreGive(mutex);
            read_maix();
          }
        } else if (result.xCenter < 169) {
          while (result.xCenter < 169 || (steps == 1 || steps == 3)) {
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
            BodyMaju_K2(70);
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
      RotateMPU(-23, true);
      while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakRotasi(Offset, 34, 30);  //34
        xSemaphoreGive(mutex);
        RotateMPU();
      }
      huskylens.request();
      if (huskylens.available()) {
        while (Sensors == true) {
          read_maix();
          if (result.xCenter > 175) {
            while (result.xCenter > 175 || (steps == 1 || steps == 3)) {
              xSemaphoreTake(mutex, portMAX_DELAY);
              GerakRotasi(12, 28, 40);
              xSemaphoreGive(mutex);
              read_maix();
            }
          } else if (result.xCenter < 169) {
            while (result.xCenter < 169 || (steps == 1 || steps == 3)) {
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
              BodyMaju_K2(70);
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
                  BodyMundur_K2(40);
                  xSemaphoreGive(mutex);
                  if (Capit == false) {
                    break;
                  }
                }
                readSRF();
                while (jarak > 3) {
                  xSemaphoreTake(mutex, portMAX_DELAY);
                  BodyMaju_K2(70);
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
          }
        }
      }
    }
    heightFR = -92;
    heightRM = -92;
    heightBR = -92;
    heightFL = -92;
    heightLM = -92;
    heightBL = -92;
    //===Test Gerakan Ambil Korban K2===//
    tujuan = sdtfix + 182;
    RotateMPU();  //110
    while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 35, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }

    //======================================//
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 22);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    jBack = readPING(rightBack);
    while ((jBack < 18 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri_pingKanan(24, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 35, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    while ((jBack > 18 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKanan_pingKanan(24, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 35, 26, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 26);
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
    bodyKanan.write(20);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    // Mencoba Gerak Lurus
    baca_IR(IRfront);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 7) || (steps == 1 || steps == 3)) {  //Asli 13
      baca_IR(IRright);
      if (distances < 14) {
        while (distances < 27 || (steps == 1 || steps == 3)) {
          navigasiMPU_Kiri(30);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakGeser(30, 44, 30, lebarKiri, lebarKanan, lebarTengah);
          xSemaphoreGive(mutex);
          baca_IR(IRright);
          if (distances >= 27) break;
        }
      }
      navigasiMPU_Maju(26);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(26, 38, 30, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    baca_IR(IRfront);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 7) || (steps == 1 || steps == 3)) {  //Asli 13
      baca_IR(IRright);
      if (distances < 14) {
        while (distances < 27 || (steps == 1 || steps == 3)) {
          navigasiMPU_Kiri(30);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakGeser(30, 44, 30, lebarKiri, lebarKanan, lebarTengah);
          xSemaphoreGive(mutex);
          baca_IR(IRright);
          if (distances >= 27) break;
        }
      }
      navigasiMPU_Maju(26);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(26, 38, 30, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    bodyKanan.write(180);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    RotateMPU(90, true);
    while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 35, 26);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    sdtAcuan = yaw;
    heightFR = -92;
    heightRM = -92;
    heightBR = -92;
    heightFL = -92;
    heightLM = -92;
    heightBL = -92;
    jBack = readPING(leftBack);
    jFront = readPING(leftFront);
    while ((jBack > 10 || jFront > 10) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri_pingKiri(18, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(18, 32, 26, lebarKiri, lebarKanan, lebarTengah);  //22 36 38
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      if (distances < 15) {
        while (distances < 17 || (steps == 1 || steps == 3)) {
          navigasiMPU_Mundur(18);
          xSemaphoreTake(mutex, portMAX_DELAY);
          GerakDinamis(-18, 32, 26, lebarKiri, lebarKanan);
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
        navigasiKiri_pingKiri(18, leftFront, leftBack);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(18, 32, 26, lebarKiri, lebarKanan, lebarTengah);  //22, 40, 36
        xSemaphoreGive(mutex);
        baca_IR(IRfront);
        if (distances < 15) {
          while (distances < 17 || (steps == 1 || steps == 3)) {
            navigasiMPU_Mundur(18);
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakDinamis(-18, 32, 26, lebarKiri, lebarKanan);
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
    while (distances < 15 || (steps == 1 || steps == 3)) {  //awalnya 15
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-20, 32, 24, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    baca_IR(IRfront);
    while (distances > 17 || (steps == 1 || steps == 3)) {  //awalnya 15
      navigasiMPU_Maju(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 32, 24, lebarKiri, lebarKanan);
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
    RotateMPU(15, true);
    while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 32, 34);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 34, 24);
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
    baca_IR(IRfront);
    while ((distances < 27) || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-22, 35, 24, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    jBack = readPING(leftBack);
    jFront = readPING(leftFront);
    while ((jBack < 18 || jFront < 18) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKanan_pingKiri(20, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(-20, 30, 24, lebarKiri, lebarKanan, lebarTengah);  //22, 40, 36
      xSemaphoreGive(mutex);
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 16);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    baca_IR(IRfront);
    //    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((distances < 52) || (steps == 1 || steps == 3)) {  //43
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-22, 28, 20, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      //      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 18);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    RotateMPU(-90, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 28, 22);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    sdtAcuan = yaw;
    xSemaphoreTake(mutex, portMAX_DELAY);
    bodyKanan.write(5);
    stop = true;
    xSemaphoreGive(mutex);
    while (stop == true) {
      baca_IR(IRright);
      filtered_IRdepan = ((1 - 0.6) * filtered_IRdepan) + (0.6 * distances);
      while ((filtered_IRdepan < 51) || (steps == 1 || steps == 3)) {  //Asli 13
        navigasiMPU_Kiri(24);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(24, 28, 26, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRright);
        filtered_IRdepan = ((1 - 0.6) * filtered_IRdepan) + (0.6 * distances);
        if (filtered_IRdepan >= 51) {
          stop = false;
        }
      }
    }
    stop = true;
    xSemaphoreTake(mutex, portMAX_DELAY);
    bodyKanan.write(180);
    xSemaphoreGive(mutex);
    baca_IR(IRfront);
    while ((distances < 27) || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-22, 28, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    yawSebelum = yaw;
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 28, 22);
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
    xSemaphoreTake(mutex, portMAX_DELAY);
    bodyKanan.write(0);
    xSemaphoreGive(mutex);
    baca_IR(IRright);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 0) && stop) {
      baca_IR(IRright);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
      while ((filtered_IR < 37) || (steps == 1 || steps == 3)) {  //Asli 13
        navigasiMPU_Kiri(26);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(22, 48, 34, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRright);
        filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
        if (filtered_IR >= 37) {
          stop = false;
        }
      }
    }
    stop = true;
    bodyKanan.write(180);
    bodyKiri.write(140);
    vTaskDelay(30 / portTICK_PERIOD_MS);
    baca_IR(IRleft);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 5) || (steps == 1 || steps == 3)) { //7
      navigasiMPU_Kiri(26);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 48, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      baca_IR(IRleft);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    bodyKiri.write(0);
    xSemaphoreGive(mutex);
    baca_IR(IRfront);
    filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    while ((filtered_IR > 6) || (steps == 1 || steps == 3)) {  //Asli 13
      navigasiMPU_Maju(23);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(23, 37, 28, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 37, 24);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    //====================================================================//
    //===Test Gerakan Naik Tangga===//
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    while ((filtered_Roll < 13 && sdtRollTangga) || (steps == 1 || steps == 3)) {
      GerakSebelumTangga();
    }
    sdtRollTangga = false;
    read_MPU();
    vTaskDelay(10 / portTICK_PERIOD_MS);
    while (roll > -11 && sdtRollTangga == false) {
      GerakanNaikTangga();
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    jmlhStep = 10;
    xSemaphoreGive(mutex);
    while (1) {
      GerakanAfterTangga(5, 20, 5, 20, 39, 28, 0, 0, 0);
      if (sdtRollAfterTangga == false) break;
    }
    //===Gerakan Ambil korban 5===//
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    afterTangga();
    while (1) {
      afterTangga();
      navigasiMPU_Kiri(22);
      filtered_Roll = ((1 - 0.7) * filtered_Roll) + (0.7 * roll);
      if ((filtered_Roll >= 7) || (steps == 1 || steps == 3)) {
        break;
      }
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 37, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    bodyKiri.write(60);
    xSemaphoreGive(mutex);
    baca_IR(IRleft);
    filtered_IR = ((1 - 0.4) * filtered_IR) + (0.4 * distances);
    while ((filtered_IR > 15) || (steps == 1 || steps == 3)) {  //Asli 13
      navigasiMPU_Kiri(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(22, 37, 34, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      baca_IR(IRleft);
      filtered_IR = ((1 - 0.4) * filtered_IR) + (0.4 * distances);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    bodyKiri.write(0);
    xSemaphoreGive(mutex);
    baca_IR(IRfront);
    filtered_IRdepan = ((1 - 0.8) * filtered_IRdepan) + (0.8 * distances);
    while (filtered_IRdepan < 5 || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(12);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-12, 37, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IRdepan = ((1 - 0.8) * filtered_IRdepan) + (0.8 * distances);
    }
    heightFR = -89;
    heightRM = -93;
    heightBR = -98;
    heightFL = -89;
    heightLM = -93;
    heightBL = -98;
    RotateMPU(-96, true);
    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 36, 36);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 24);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    baca_IR(IRfront);
    filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
    while (filtered_IR > 16 || (steps == 1 || steps == 3)) {
      navigasiMPU_Maju(22);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(22, 37, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 26);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    jFront = readPING(rightFront);
    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan_pingKanan(20, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(-20, 36, 36, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      jFront = readPING(rightFront);
    }
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 28);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    baca_IR(IRfront);
    filtered_IR = distances;
    filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
    while (filtered_IR > 15 || (steps == 1 || steps == 3)) {
      navigasiMPU_Maju(20);  //22
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 35, 34, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
    }
    jFront = readPING(rightFront);
    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kanan
      navigasiKanan_pingKanan(20, rightFront, rightBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(-20, 36, 36, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      jFront = readPING(rightFront);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    Sensors = true;
    xSemaphoreGive(mutex);
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 28);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    Sensors = true;
    huskylens.request();
    if (huskylens.available()) {
      while (Sensors == true) {
        read_maix();
        if (result.xCenter > 177) {
          while (result.xCenter > 177 || (steps == 1 || steps == 3)) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakRotasi(5, 25, 36);
            xSemaphoreGive(mutex);
            read_maix();
          }
        } else if (result.xCenter < 171) {
          while (result.xCenter < 171 || (steps == 1 || steps == 3)) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            GerakRotasi(-5, 25, 36);
            xSemaphoreGive(mutex);
            read_maix();
          }
        } else {
          heightFR = -92;
          heightRM = -92;
          heightBR = -92;
          heightFL = -92;
          heightLM = -92;
          heightBL = -92;
          Standby();
          while (1) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            BodyMundur_K5(40);
            xSemaphoreGive(mutex);
            if (Capit == false) {
              break;
            }
          }
          readSRF();
          while (jarak > 3) {
            xSemaphoreTake(mutex, portMAX_DELAY);
            BodyMaju_K5(70);
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
            BodyBalik_K5(25);
            xSemaphoreGive(mutex);
            if (Capit == false) {
              Sensors = false;
              break;
            }
          }
        }
      }
    } else {
      RotateMPU(23, true);
      while (abs(Offset) > 4 || (steps == 1 || steps == 3)) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakRotasi(Offset, 35, 38);
        xSemaphoreGive(mutex);
        RotateMPU();
      }
      Sensors = true;
      huskylens.request();
      if (huskylens.available()) {
        while (Sensors == true) {
          read_maix();
          if (result.xCenter > 176) {
            while (result.xCenter > 176 || (steps == 1 || steps == 3)) {
              xSemaphoreTake(mutex, portMAX_DELAY);
              GerakRotasi(5, 25, 36);
              xSemaphoreGive(mutex);
              read_maix();
            }
          } else if (result.xCenter < 171) {
            while (result.xCenter < 171 || (steps == 1 || steps == 3)) {
              xSemaphoreTake(mutex, portMAX_DELAY);
              GerakRotasi(-5, 25, 36);
              xSemaphoreGive(mutex);
              read_maix();
            }
          } else {
            heightFR = -92;
            heightRM = -92;
            heightBR = -92;
            heightFL = -92;
            heightLM = -92;
            heightBL = -92;
            Standby();
            while (1) {
              xSemaphoreTake(mutex, portMAX_DELAY);
              BodyMundur_K5(40);
              xSemaphoreGive(mutex);
              if (Capit == false) {
                break;
              }
            }
            readSRF();
            while (jarak > 3) {
              xSemaphoreTake(mutex, portMAX_DELAY);
              BodyMaju_K5(70);
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
              BodyBalik_K5(25);
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
    // // //=== Gerakan Ambil korban 5 ===//
    RotJarak(rightFront, rightBack);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 35, 28);
      RotJarak(rightFront, rightBack);
      xSemaphoreGive(mutex);
    }
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    heightFR = -89;
    heightRM = -93;
    heightBR = -98;
    heightFL = -89;
    heightLM = -93;
    heightBL = -98;
    RotateMPU(-92, true);
    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 36, 36);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    bodyKanan.write(70);
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    jmlhStep = 3;
    while (1) {
      navigasiMPU_Maju(10);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis_afterK5(10, 37, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      if (afterK5 == false)break;
    }
    heightFR = -72;
    heightRM = -72;
    heightBR = -72;
    heightFL = -100;
    heightLM = -100;
    heightBL = -100;
    stop = true;
    while (stop == true) {
      baca_IR(IRright);
      filtered_IR = distances;
      filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
      while ((filtered_IR <= 20) || (steps == 1 || steps == 3)) {  //Asli 22
        navigasiMPU_Kiri(17);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(17, 37, 38, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRright);
        filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
        if (filtered_IR >= 20) {
          stop = false;
        }
      }
      while ((filtered_IR >= 21) || (steps == 1 || steps == 3)) {  //Asli 26
        navigasiMPU_Kanan(17);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(-17, 37, 38, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRright);
        filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
        if (filtered_IR <= 21) {
          stop = false;
        }
      }
    }
    bodyKanan.write(180);
    baca_IR(IRback);
    filtered_IRdepan = ((1 - 0.6) * filtered_IRdepan) + (0.6 * distances);
    while (filtered_IRdepan < 5 || (steps == 1 || steps == 3)) {
      navigasiMPU_Maju(24);  //24
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(24, 37, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IRdepan = ((1 - 0.6) * filtered_IRdepan) + (0.6 * distances);
    }
    RotJarakIR_1();
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 28);
      RotJarakIR_1();
      xSemaphoreGive(mutex);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    baca_IR(IRback);
    filtered_IRdepan = ((1 - 0.6) * filtered_IRdepan) + (0.6 * distances);
    while (filtered_IRdepan < 8 || (steps == 1 || steps == 3)) {
      navigasiMPU_Maju(20);  //24
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 37, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IRdepan = ((1 - 0.6) * filtered_IRdepan) + (0.6 * distances);
    }
    RotJarakIR_2();
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 28);
      RotJarakIR_2();
      xSemaphoreGive(mutex);
    }
    bodyKanan.write(70);
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    stop = true;
    while (stop == true) {
      baca_IR(IRright);
      filtered_IR = distances;
      filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
      while ((filtered_IR >= 22) || (steps == 1 || steps == 3)) {  //Asli 26
        navigasiMPU_Kanan(15);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(-15, 37, 38, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRright);
        filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
        if (filtered_IR <= 22) {
          stop = false;
        }
      }
      while ((filtered_IR <= 20) || (steps == 1 || steps == 3)) {  //Asli 23
        navigasiMPU_Kiri(16);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(16, 37, 38, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRright);
        filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
        if (filtered_IR >= 20) {
          stop = false;
        }
      }
    }
    bodyKanan.write(180);
    RotJarakIR_2();
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 28);
      RotJarakIR_2();
      xSemaphoreGive(mutex);
    }
    baca_IR(IRback);
    filtered_IRdepan = ((1 - 0.6) * filtered_IRdepan) + (0.6 * distances);
    while (filtered_IRdepan < 14 || (steps == 1 || steps == 3)) {
      navigasiMPU_Maju(20);  //24
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 37, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      filtered_IRdepan = ((1 - 0.6) * filtered_IRdepan) + (0.6 * distances);
    }
    RotJarakIR_3();
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 28);
      RotJarakIR_3();
      xSemaphoreGive(mutex);
    }
    bodyKanan.write(70);
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    stop = true;
    while (stop == true) {
      baca_IR(IRright);
      filtered_IR = distances;
      filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
      while ((filtered_IR >= 21) || (steps == 1 || steps == 3)) {  //Asli 26
        navigasiMPU_Kanan(15);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(-15, 37, 38, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRright);
        filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
        if (filtered_IR <= 21) {
          stop = false;
        }
      }
      RotJarakIR_3();
      while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakRotasi(OffsetJarak, 30, 28);
        RotJarakIR_3();
        xSemaphoreGive(mutex);
      }
      while ((filtered_IR <= 20) || (steps == 1 || steps == 3)) {  //Asli 23
        navigasiMPU_Kiri(15);
        xSemaphoreTake(mutex, portMAX_DELAY);
        GerakGeser(15, 37, 38, lebarKiri, lebarKanan, lebarTengah);
        xSemaphoreGive(mutex);
        baca_IR(IRright);
        filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
        if (filtered_IR >= 20) {
          stop = false;
        }
      }
    }
    bodyKanan.write(180);
    RotJarakIR_3();
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 30, 28);
      RotJarakIR_3();
      xSemaphoreGive(mutex);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    offsetCX[0] = -5;
    offsetCX[1] = 5;
    offsetCX[2] = -5;
    offsetCX[3] = 5;
    baca_IR(IRfront);
    filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
    while (filtered_IR > 5 || (steps == 1 || steps == 3)) {
      navigasiMPU_Maju(20);  //24
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(20, 37, 32, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRfront);
      filtered_IR = ((1 - 0.6) * filtered_IR) + (0.6 * distances);
    }
    offsetCX[0] = 0;  //Coxa BL //25
    offsetCX[1] = 0;  //Coxa FL //-22
    offsetCX[2] = 0;  //Coxa BL //25
    offsetCX[3] = 0;  //Coxa FL //-22
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 18);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    heightFR = -92;
    heightRM = -92;
    heightBR = -92;
    heightFL = -92;
    heightLM = -92;
    heightBL = -92;
    RotateMPU(90, true);
    while (abs(Offset) > 2 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(Offset, 20, 24);
      xSemaphoreGive(mutex);
      RotateMPU();
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 18);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    xSemaphoreTake(mutex, portMAX_DELAY);
    read_MPU();
    vTaskDelay(15 / portTICK_PERIOD_MS);
    sdtAcuan = yaw;
    xSemaphoreGive(mutex);
    baca_IR(IRback);
    offsets = (11 - distances) * 5;
    if (offsets > 11) offsets = 20;
    if (offsets < -11) offsets = -20;
    while (distances < 11 || (steps == 1 || steps == 3)) {
      navigasiMPU_Maju(20);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(offsets, 25, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      offsets = (11 - distances) * 5;
      if (offsets > 11) offsets = 20;
      if (offsets < -11) offsets = -20;
    }
    while (distances > 11 || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(20);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(offsets, 25, 22, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
      offsets = (11 - distances) * 5;
      if (offsets > 11) offsets = 20;
      if (offsets < -11) offsets = -20;
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 24);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    jBack = readPING(leftBack);
    offsets = (jBack - 17) * 5;
    if (offsets > 17) offsets = 15;
    if (offsets < -17) offsets = -15;
    while ((jBack > 18) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKiri_pingKiri(18, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 25, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (jBack - 17) * 5;
      if (offsets > 17) offsets = 15;
      if (offsets < -17) offsets = -15;
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 24);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    jBack = readPING(leftBack);
    offsets = (jBack - 17) * 5;
    if (offsets > 17) offsets = 15;
    if (offsets < -17) offsets = -15;
    while ((jBack < 18) || (steps == 1 || steps == 3)) {  //Geser Kiri
      navigasiKanan_pingKiri(18, leftFront, leftBack);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakGeser(offsets, 25, 22, lebarKiri, lebarKanan, lebarTengah);
      xSemaphoreGive(mutex);
      offsets = (jBack - 17) * 5;
      if (offsets > 17) offsets = 15;
      if (offsets < -17) offsets = -15;
    }
    RotJarak(leftBack, leftFront);
    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakRotasi(OffsetJarak, 20, 24);
      RotJarak(leftBack, leftFront);
      xSemaphoreGive(mutex);
    }
    Standby();
    while (1) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      taruhKorban5(35);
      xSemaphoreGive(mutex);
      if (Capit == false) {
        break;
      }
    }
    baca_IR(IRback);
    while (distances > 4 || (steps == 1 || steps == 3)) {
      navigasiMPU_Mundur(25);
      xSemaphoreTake(mutex, portMAX_DELAY);
      GerakDinamis(-25, 20, 14, lebarKiri, lebarKanan);
      xSemaphoreGive(mutex);
      baca_IR(IRback);
    }
    Standby();
    while (1) {
      xSemaphoreTake(mutex, portMAX_DELAY);
      CapitBack_K5(20);
      xSemaphoreGive(mutex);
      if (Capit == false) {
        break;
      }
    }
    while (1) {
      Standby();
    }
    //    //== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == //
  }
}
