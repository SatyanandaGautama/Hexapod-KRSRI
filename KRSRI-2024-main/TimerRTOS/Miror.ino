//=== MIROR FIX ===//
//    while (ButtonState == 1) {
//      ButtonState = digitalRead(Button);
//      dist = readPING(rightBack);
//      dist1 = readPING(leftBack);
//      if (ButtonState == 0) {
//        display.clearDisplay();
//        break;
//      }
//    }
//    dist = readPING(rightFront);
//    dist1 = readPING(leftFront);
//    if (dist > dist1) {
//      RotateMPU(90, true);
//      while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakRotasi(Offset, 18, 10);
//        xSemaphoreGive(mutex);
//        RotateMPU();
//      }
//    } else {
//      RotateMPU(-90, true);
//      while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakRotasi(Offset, 18, 10);
//        xSemaphoreGive(mutex);
//        RotateMPU();
//      }
//    }
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 18, 12);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(15 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFBelakang();
//    xSemaphoreGive(mutex);
//    while (TOFBelakang < 52 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      navigasiMPU_Maju_versiCepat(15);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(15, 12, 4, lebarKiri, lebarKanan);  //18,16,6 dibawah 16 patah"
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//    }
//    // memastikan lewat home
//    stop = true;
//    while (stop == true) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//      if (TOFBelakang > 51 && TOFBelakang < 54) {
//        stop = false;
//      }
//      while ((TOFBelakang < 51) || (steps == 1 || steps == 3)) {
//        navigasiMaju(15, 20, rightFront, rightBack);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakDinamis(15, 20, 22, lebarKiri, lebarKanan);
//        xSemaphoreGive(mutex);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        bacaTOFBelakang();
//        xSemaphoreGive(mutex);
//      }
//      while ((TOFBelakang > 54) || (steps == 1 || steps == 3)) {
//        navigasiMaju(15, 20, rightFront, rightBack);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakDinamis(-15, 20, 22, lebarKiri, lebarKanan);
//        xSemaphoreGive(mutex);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        bacaTOFBelakang();
//        xSemaphoreGive(mutex);
//      }
//    }
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 18, 10);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    read_MPU();
//    vTaskDelay(15 / portTICK_PERIOD_MS);
//    yawAwal = yaw;
//    RotateMPU(91, true);
//    while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
//      GerakRotasi(Offset, 18, 12);
//      RotateMPU();
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFBelakang();
//    xSemaphoreGive(mutex);
//    while (TOFBelakang > 5 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-15, 18, 12, 0, 0);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//    }
//    while (NewDataReady_6 == 0 || NewDataReady_5 == 0) {
//      RotJarakTOF();
//    }
//    RotJarakTOF();
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 32, 32);
//      xSemaphoreGive(mutex);
//      RotJarakTOF();
//    }
//    jmlhStep = 0;
//    huskylens.request();
//    if (huskylens.available()) {
//      while (jmlhStep < 2) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        if (steps == 0 && statusGerak == false) {
//          jmlhStep++;
//        }
//        GerakDinamis(5, 17, 20, 0, 0);
//        xSemaphoreGive(mutex);
//      }
//      while (Sensors == true) {
//        read_maix();
//        if (result.xCenter > 161) {
//          while (result.xCenter > 161 || (steps == 1 || steps == 3)) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            GerakRotasi(5, 15, 16);  //26
//            xSemaphoreGive(mutex);
//            read_maix();
//          }
//        } else if (result.xCenter < 155) {
//          while (result.xCenter < 155 || (steps == 1 || steps == 3)) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            GerakRotasi(-5, 15, 16);  //26
//            xSemaphoreGive(mutex);
//            read_maix();
//          }
//        } else {
//          Standby();
//          while (1) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            BodyMundur_K2(45, 15);
//            capit2.write(45);
//            xSemaphoreGive(mutex);
//            if (Capit == false) {
//              break;
//            }
//          }
//          readSRF();
//          while (jarak > 3) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            BodyMaju_K2(70);
//            xSemaphoreGive(mutex);
//            if (Capit == false) break;
//            readSRF();
//          }
//          Capit = false;
//          tServo = 0;
//          tDyn = 0;
//          statusGerak = false;
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          stepss = 0;
//          xSemaphoreGive(mutex);
//          while (1) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            BodyBalik_K2(20);
//            xSemaphoreGive(mutex);
//            if (Capit == false) {
//              Sensors = false;
//              break;
//            }
//          }
//        }
//      }
//    } else {
//      RotateMPU(14, true);
//      while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
//        GerakRotasi(Offset, 18, 20);
//        RotateMPU();
//      }
//      //===Test Gerakan Ambil Korban K1===//
//      huskylens.request();
//      if (huskylens.available()) {
//        while (Sensors == true) {
//          read_maix();
//          if (result.xCenter > 161) {  //172
//            while (result.xCenter > 161 || (steps == 1 || steps == 3)) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              GerakRotasi(5, 15, 16);
//              xSemaphoreGive(mutex);
//              read_maix();
//            }
//          } else if (result.xCenter < 155) {  //166
//            while (result.xCenter < 155 || (steps == 1 || steps == 3)) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              GerakRotasi(-5, 15, 16);
//              xSemaphoreGive(mutex);
//              read_maix();
//            }
//          } else {
//            Standby();
//            while (1) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              BodyMundur_K2(45, 15);
//              capit2.write(45);
//              xSemaphoreGive(mutex);
//              if (Capit == false) {
//                break;
//              }
//            }
//            readSRF();
//            while (jarak > 3) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              BodyMaju_K2(70);
//              xSemaphoreGive(mutex);
//              if (Capit == false) break;
//              readSRF();
//            }
//            Capit = false;
//            tServo = 0;
//            tDyn = 0;
//            statusGerak = false;
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            stepss = 0;
//            xSemaphoreGive(mutex);
//            while (1) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              BodyBalik_K2(20);
//              xSemaphoreGive(mutex);
//              if (Capit == false) {
//                Sensors = false;
//                break;
//              }
//            }
//          }
//        }
//      } else {
//        while (Sensors == true) {
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          GerakRotasi(-7, 15, 14);  //7,15,20
//          xSemaphoreGive(mutex);
//          huskylens.request();
//          if (huskylens.available()) {
//            while (Sensors == true) {
//              read_maix();
//              if (result.xCenter > 161) {
//                while (result.xCenter > 161 || (steps == 1 || steps == 3)) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  GerakRotasi(5, 15, 16);  //36
//                  xSemaphoreGive(mutex);
//                  read_maix();
//                }
//              } else if (result.xCenter < 157) {
//                while (result.xCenter < 157 || (steps == 1 || steps == 3)) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  GerakRotasi(-5, 15, 16);  //36
//                  xSemaphoreGive(mutex);
//                  read_maix();
//                }
//              } else {
//                jmlhStep = 0;
//                while (jmlhStep < 2) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  if (steps == 0 && statusGerak == false) {
//                    jmlhStep++;
//                  }
//                  GerakDinamis(-10, 15, 20, 0, 0);
//                  xSemaphoreGive(mutex);
//                }
//                statusGerak = false;
//                while (1) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  BodyMundur_K2(45, 15);
//                  capit2.write(45);
//                  xSemaphoreGive(mutex);
//                  if (Capit == false) {
//                    break;
//                  }
//                }
//                readSRF();
//                while (jarak > 3) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  BodyMaju_K2(70);
//                  xSemaphoreGive(mutex);
//                  if (Capit == false) break;
//                  readSRF();
//                }
//                Capit = false;
//                tServo = 0;
//                tDyn = 0;
//                statusGerak = false;
//                xSemaphoreTake(mutex, portMAX_DELAY);
//                stepss = 0;
//                xSemaphoreGive(mutex);
//                while (1) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  BodyBalik_K2(20);
//                  xSemaphoreGive(mutex);
//                  if (Capit == false) {
//                    Sensors = false;
//                    break;
//                  }
//                }
//              }
//            }
//          }
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          read_MPU();
//          xSemaphoreGive(mutex);
//          if (yaw == yawAwal) {
//            Sensors = false;
//            cactch = false;
//          }
//        }
//      }
//    }
//    //== = Test Gerakan Ambil Korban K1 == =  //
//    if (cactch == true) {
//      RotateMPU(-90, true);
//      while (abs(Offset) > 1 || (steps == 1 || steps == 3)) {
//        GerakRotasi(Offset, 27, 14);
//        RotateMPU();
//      }
//    }
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 25, 12);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    jBack = readPING(leftBack);
//    while ((jBack > 16 + 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
//      navigasiKiri_pingKiri(10, leftFront, leftBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(10, 25, 14, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      jBack = readPING(leftBack);
//    }
//    while ((jBack < 16 - 1) || (steps == 1 || steps == 3)) {  //Geser Kiri
//      navigasiKanan_pingKiri(10, leftFront, leftBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(10, 25, 14, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      jBack = readPING(leftBack);
//    }
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 25, 16);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 25, 12);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    //===Jalan Pecah===//
//    while (pitch > -15 && turunMPU == false) {
//      navigasiMPU_Maju(25);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(25, 49, 26, lebarKiri, lebarKanan);  //23, 47, 30
//      xSemaphoreGive(mutex);
//      if (pitch <= -15) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        turunMPU = true;
//        xSemaphoreGive(mutex);
//        break;
//      }
//    }
//    read_MPU();
//    vTaskDelay(15 / portTICK_PERIOD_MS);
//    //===Jalan Turunan 1 (Memastikan agar lewat dari Jalan Pecah)===//
//    while ((pitch <= -15 && pitch > -22) && turunMPU == true) {  //+ depan naikk - depan Turun //
//      navigasiMPU_Maju(25);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(25, 49, 26, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      if (pitch > -15) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        turunMPU = false;
//        xSemaphoreGive(mutex);
//        break;
//      }
//    }
//    heightFR = -92;
//    heightRM = -90;
//    heightBR = -77;
//    heightFL = -92;
//    heightLM = -90;
//    heightBL = -77;
//    //===Jalan Turunan 2===//
//    while (pitch <= -1 && stateMPU == false) {
//      navigasiMPU_Maju(28);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(25, 41, 18, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      if (pitch >= -1) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        stateMPU = true;
//        xSemaphoreGive(mutex);
//      }
//    }
//    //== = Jalan Berbatu Menuju SZ - 1 == =  //
//    heightFR = -92;
//    heightRM = -92;
//    heightBR = -92;
//    heightFL = -92;
//    heightLM = -92;
//    heightBL = -92;
//    stop = true;
//    while (stop == true) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//      while (TOFDepan > 6 && stateMPU == true) {
//        navigasiMPU_Maju(20);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakDinamis(24, 37, 18, lebarKiri, lebarKanan);
//        xSemaphoreGive(mutex);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        bacaTOFDepan();
//        xSemaphoreGive(mutex);
//        if (TOFDepan <= 6) {
//          stop = false;
//        }
//      }
//    }
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 37, 20);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    //====Rotate SZ-1====//
//    RotateMPU(-87, true);
//    while (abs(Offset) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 36, 22);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 36, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    //====Geser SZ-1====//
//    jFront = readPING(rightFront);
//    while ((jFront < 9) || (steps == 1 || steps == 3)) {  //Geser Kanan
//      navigasiKiri_pingKanan(26, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(18, 35, 20, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//    }
//    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
//      navigasiKanan_pingKanan(26, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-18, 35, 20, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 22);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    sdtMaju = yaw;
//    xSemaphoreGive(mutex);
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 22);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    sdtMaju = yaw;
//    xSemaphoreGive(mutex);
//    //===Mundur SZ-1===//
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan < 26 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Mundur(32);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-26, 38, 26, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 24);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 24);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    jFront = readPING(rightFront);
//    while ((jFront < 9) || (steps == 1 || steps == 3)) {  //Geser Kanan
//      navigasiKiri_pingKanan(18, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(18, 34, 24, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//    }
//    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
//      navigasiKanan_pingKanan(18, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-18, 34, 24, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 24);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    //===Rotate dan taruh korban SZ-1===//
//    RotateMPU(15, true);
//    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 34, 28);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    Standby();
//    while (1) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      taruhKorban1(22);
//      xSemaphoreGive(mutex);
//      if (Capit == false) {
//        break;
//      }
//    }
//    RotateMPU(-17, true);  //22
//    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 34, 28);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    jFront = readPING(rightFront);
//    while ((jFront < 10 - 1) || (steps == 1 || steps == 3)) {  //Geser Kanan
//      navigasiKiri_pingKanan(22, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(16, 34, 24, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//    }
//    while ((jFront > 11) || (steps == 1 || steps == 3)) {  //Geser Kiri
//      navigasiKanan_pingKanan(22, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-16, 34, 24, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = sdtMaju;
//    sdtfix = yaw;
//    xSemaphoreGive(mutex);
//    //== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==  //
//    heightFR = -92;
//    heightRM = -92;
//    heightBR = -92;
//    heightFL = -92;
//    heightLM = -92;
//    heightBL = -92;
//    // //====Gerakan Ambil Korban 2 sampai taruh safety zone 2====//
//    //================Dari SZ-1 Menuju SZ-2==============//
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFBelakang();
//    xSemaphoreGive(mutex);
//    while ((TOFBelakang > 40 || TOFBelakang < 38) || (steps == 1 || steps == 3)) {
//      navigasiMPU_Mundur(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-22, 42, 20, lebarKiri, lebarKanan);  //-21, 37, 28
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//      if (TOFBelakang < 38) {
//        while (TOFBelakang < 38) {
//          navigasiMPU_Maju(22);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          GerakDinamis(22, 42, 20, lebarKiri, lebarKanan);  //-20, 36, 28
//          xSemaphoreGive(mutex);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          bacaTOFBelakang();
//          xSemaphoreGive(mutex);
//        }
//      }
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 35, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 35, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFBelakang();
//    xSemaphoreGive(mutex);
//    while ((TOFBelakang > 40 || TOFBelakang < 38) || (steps == 1 || steps == 3)) {
//      navigasiMPU_Mundur(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-22, 42, 20, lebarKiri, lebarKanan);  //-20, 36, 28
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//      if (TOFBelakang < 38) {
//        while (TOFBelakang < 38) {
//          navigasiMPU_Maju(22);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          GerakDinamis(22, 42, 20, lebarKiri, lebarKanan);  //-20, 36, 28
//          xSemaphoreGive(mutex);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          bacaTOFBelakang();
//          xSemaphoreGive(mutex);
//        }
//      }
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 35, 18);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    heightFR = -92;
//    heightRM = -92;
//    heightBR = -92;
//    heightFL = -92;
//    heightLM = -92;
//    heightBL = -92;
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    tujuan = sdtfix - 95;
//    yawAwal = sdtfix - 165;  //135
//    xSemaphoreGive(mutex);
//    RotateMPU();
//    while (abs(Offset) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 32, 24);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    while (NewDataReady_6 == 0 || NewDataReady_5 == 0) {
//      RotJarakTOF();
//    }
//    RotJarakTOF();
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 32, 32);
//      xSemaphoreGive(mutex);
//      RotJarakTOF();
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    heightFR = -94;
//    heightRM = -94;
//    heightBR = -94;
//    heightFL = -94;
//    heightLM = -94;
//    heightBL = -94;
//    stop = true;
//    while (stop == true) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//      while (TOFBelakang > 10 || (steps == 1 || steps == 3)) {
//        navigasiMPU_Mundur(12);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakDinamis(-12, 32, 22, lebarKiri, lebarKanan);
//        xSemaphoreGive(mutex);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        bacaTOFBelakang();
//        xSemaphoreGive(mutex);
//      }
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//      while (TOFBelakang < 8 || (steps == 1 || steps == 3)) {
//        navigasiMPU_Maju(12);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakDinamis(22, 32, 22, lebarKiri, lebarKanan);
//        xSemaphoreGive(mutex);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        bacaTOFBelakang();
//        xSemaphoreGive(mutex);
//      }
//      if (TOFBelakang >= 8 && TOFBelakang <= 10) {
//        stop = false;
//      }
//    }
//    heightFR = -92;
//    heightRM = -92;
//    heightBR = -92;
//    heightFL = -92;
//    heightLM = -92;
//    heightBL = -92;
//    Sensors = true;
//    cactch = true;
//    //===Test Gerakan Ambil Korban K2===//
//    huskylens.request();
//    if (huskylens.available()) {
//      while (Sensors == true) {
//        read_maix();
//        if (result.xCenter > 161) {
//          while (result.xCenter > 161 || (steps == 1 || steps == 3)) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            GerakRotasi(12, 28, 36);
//            xSemaphoreGive(mutex);
//            read_maix();
//          }
//        } else if (result.xCenter < 155) {
//          while (result.xCenter < 155 || (steps == 1 || steps == 3)) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            GerakRotasi(-12, 28, 36);
//            xSemaphoreGive(mutex);
//            read_maix();
//          }
//        } else {
//          Standby();
//          while (1) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            BodyMundur_K2(52, 50);
//            xSemaphoreGive(mutex);
//            if (Capit == false) {
//              break;
//            }
//          }
//          readSRF();
//          while (jarak > 3) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            BodyMaju_K2(70);
//            xSemaphoreGive(mutex);
//            if (Capit == false) break;
//            readSRF();
//          }
//          Capit = false;
//          tServo = 0;
//          tDyn = 0;
//          statusGerak = false;
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          stepss = 0;
//          xSemaphoreGive(mutex);
//          while (1) {
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            BodyBalik_K2(25);
//            xSemaphoreGive(mutex);
//            if (Capit == false) {
//              Sensors = false;
//              break;
//            }
//          }
//        }
//      }
//    } else {
//      RotateMPU(28, true);
//      while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakRotasi(Offset, 34, 26);  //34
//        xSemaphoreGive(mutex);
//        RotateMPU();
//      }
//      huskylens.request();
//      if (huskylens.available()) {
//        while (Sensors == true) {
//          read_maix();
//          if (result.xCenter > 161) {
//            while (result.xCenter > 161 || (steps == 1 || steps == 3)) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              GerakRotasi(12, 28, 36);
//              xSemaphoreGive(mutex);
//              read_maix();
//            }
//          } else if (result.xCenter < 155) {
//            while (result.xCenter < 155 || (steps == 1 || steps == 3)) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              GerakRotasi(-12, 28, 36);
//              xSemaphoreGive(mutex);
//              read_maix();
//            }
//          } else {
//            Standby();
//            while (1) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              BodyMundur_K2(52, 50);
//              xSemaphoreGive(mutex);
//              if (Capit == false) {
//                break;
//              }
//            }
//            readSRF();
//            while (jarak > 3) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              BodyMaju_K2(70);
//              xSemaphoreGive(mutex);
//              if (Capit == false) break;
//              readSRF();
//            }
//            Capit = false;
//            tServo = 0;
//            tDyn = 0;
//            statusGerak = false;
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            stepss = 0;
//            xSemaphoreGive(mutex);
//            while (1) {
//              xSemaphoreTake(mutex, portMAX_DELAY);
//              BodyBalik_K2(25);
//              xSemaphoreGive(mutex);
//              if (Capit == false) {
//                Sensors = false;
//                break;
//              }
//            }
//          }
//        }
//      } else {
//        while (Sensors == true) {
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          GerakRotasi(-16, 28, 36);
//          xSemaphoreGive(mutex);
//          huskylens.request();
//          if (huskylens.available()) {
//            while (Sensors == true) {
//              read_maix();
//              if (result.xCenter > 161) {
//                while (result.xCenter > 161 || (steps == 1 || steps == 3)) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  GerakRotasi(12, 28, 36);
//                  xSemaphoreGive(mutex);
//                  read_maix();
//                }
//              } else if (result.xCenter < 155) {
//                while (result.xCenter < 155 || (steps == 1 || steps == 3)) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  GerakRotasi(-12, 28, 36);
//                  xSemaphoreGive(mutex);
//                  read_maix();
//                }
//              } else {
//                Standby();
//                while (1) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  BodyMundur_K2(52, 40);
//                  xSemaphoreGive(mutex);
//                  if (Capit == false) {
//                    break;
//                  }
//                }
//                readSRF();
//                while (jarak > 3) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  BodyMaju_K2(70);
//                  xSemaphoreGive(mutex);
//                  if (Capit == false) break;
//                  readSRF();
//                }
//                Capit = false;
//                tServo = 0;
//                tDyn = 0;
//                statusGerak = false;
//                xSemaphoreTake(mutex, portMAX_DELAY);
//                stepss = 0;
//                xSemaphoreGive(mutex);
//                while (1) {
//                  xSemaphoreTake(mutex, portMAX_DELAY);
//                  BodyBalik_K2(25);
//                  xSemaphoreGive(mutex);
//                  if (Capit == false) {
//                    Sensors = false;
//                    break;
//                  }
//                }
//              }
//            }
//          }
//          //menambahkan validasi jika korban tidak terdeteksi
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          read_MPU();
//          xSemaphoreGive(mutex);
//          if (yaw == yawAwal) {
//            Sensors = false;
//            cactch = false;
//          }
//        }
//      }
//    }
//    heightFR = -92;
//    heightRM = -92;
//    heightBR = -92;
//    heightFL = -92;
//    heightLM = -92;
//    heightBL = -92;
//    //===Test Gerakan Ambil Korban K2===//
//    if (cactch == true) {
//      tujuan = sdtfix - 180;
//      RotateMPU();  //110
//      while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakRotasi(Offset, 35, 22);
//        xSemaphoreGive(mutex);
//        RotateMPU();
//      }
//    }
//    //======================================//
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 18);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    jBack = readPING(leftBack);
//    while ((jBack < 18 - 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
//      navigasiKanan_pingKiri(24, leftFront, leftBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-22, 35, 22, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//    }
//    while ((jBack > 18 + 2) || (steps == 1 || steps == 3)) {  //Geser Kiri
//      navigasiKiri_pingKiri(24, leftFront, leftBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(22, 35, 22, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 35, 22);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    bodyKiri.write(160);
//    vTaskDelay(15 / portTICK_PERIOD_MS);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while ((TOFDepan > 11) || (steps == 1 || steps == 3)) {  //Asli 13
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFKiri();
//      xSemaphoreGive(mutex);
//      if (TOFKiri < 22) {
//        while (TOFKiri < 29 || (steps == 1 || steps == 3)) {
//          navigasiMPU_Kanan(30);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          GerakGeser(-30, 44, 24, lebarKiri, lebarKanan, lebarTengah);
//          xSemaphoreGive(mutex);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          bacaTOFKiri();
//          xSemaphoreGive(mutex);
//          if (TOFKiri >= 29) break;
//        }
//      }
//      navigasiMPU_Maju(26);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(26, 42, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while ((TOFDepan > 10) || (steps == 1 || steps == 3)) {  //Asli 13
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFKiri();
//      xSemaphoreGive(mutex);
//      if (TOFKiri < 22) {
//        while (TOFKiri < 29 || (steps == 1 || steps == 3)) {
//          navigasiMPU_Kanan(30);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          GerakGeser(-30, 44, 24, lebarKiri, lebarKanan, lebarTengah);
//          xSemaphoreGive(mutex);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          bacaTOFKiri();
//          xSemaphoreGive(mutex);
//          if (TOFKiri >= 29) break;
//        }
//      }
//      navigasiMPU_Maju(26);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(26, 42, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    bodyKiri.write(0);
//    vTaskDelay(15 / portTICK_PERIOD_MS);
//    RotateMPU(-90, true);
//    while (abs(Offset) > 5 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 35, 22);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    sdtAcuan = yaw;
//    heightFR = -92;
//    heightRM = -92;
//    heightBR = -92;
//    heightFL = -92;
//    heightLM = -92;
//    heightBL = -92;
//    jBack = readPING(rightBack);
//    jFront = readPING(rightFront);
//    while ((jBack > 10 || jFront > 10) || (steps == 1 || steps == 3)) {  //Geser Kiri
//      navigasiKanan_pingKanan(18, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-18, 32, 22, lebarKiri, lebarKanan, lebarTengah);  //22 36 38
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//      if (TOFDepan < 24) {
//        while (TOFDepan < 26 || (steps == 1 || steps == 3)) {
//          navigasiMPU_Mundur(18);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          GerakDinamis(-18, 32, 22, lebarKiri, lebarKanan);
//          xSemaphoreGive(mutex);
//          xSemaphoreTake(mutex, portMAX_DELAY);
//          bacaTOFDepan();
//          xSemaphoreGive(mutex);
//          if (TOFDepan >= 26) break;
//        }
//      }
//    }
//    jFront = readPING(rightFront);
//    if (jFront > 9) {
//      jBack = readPING(rightBack);
//      while ((jBack > 10 || jFront > 10) || (steps == 1 || steps == 3)) {  //Geser Kiri
//        navigasiKanan_pingKanan(18, rightFront, rightBack);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakGeser(-18, 32, 22, lebarKiri, lebarKanan, lebarTengah);  //22, 40, 36
//        xSemaphoreGive(mutex);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        bacaTOFDepan();
//        xSemaphoreGive(mutex);
//        if (TOFDepan < 24) {
//          while (TOFDepan < 26 || (steps == 1 || steps == 3)) {
//            navigasiMPU_Mundur(18);
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            GerakDinamis(-18, 32, 22, lebarKiri, lebarKanan);
//            xSemaphoreGive(mutex);
//            xSemaphoreTake(mutex, portMAX_DELAY);
//            bacaTOFDepan();
//            xSemaphoreGive(mutex);
//            if (TOFDepan >= 26) break;
//          }
//        }
//      }
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 30, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan < 24 || (steps == 1 || steps == 3)) {  //awalnya 15
//      navigasiMPU_Mundur(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-18, 32, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan > 26 || (steps == 1 || steps == 3)) {  //awalnya 15
//      navigasiMPU_Maju(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(18, 32, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan < 22 || (steps == 1 || steps == 3)) {  //awalnya 15
//      navigasiMPU_Mundur(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-18, 32, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan > 26 || (steps == 1 || steps == 3)) {  //awalnya 15
//      navigasiMPU_Maju(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(18, 32, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 35, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 35, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    RotateMPU(14, true);
//    while (abs(Offset) > 4 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 32, 30);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    //Taruh Korban 2//
//    Standby();
//    while (1) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      taruhKorban2(22);
//      xSemaphoreGive(mutex);
//      if (Capit == false) {
//        break;
//      }
//    }
//    //Akhir coba gerakan
//    RotateMPU(-15, true);
//    while (abs(Offset) > 4 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 32, 30);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 34, 20);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while ((TOFDepan < 50) || (steps == 1 || steps == 3)) {
//      navigasiMPU_Mundur(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-22, 38, 20, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    jBack = readPING(rightBack);
//    jFront = readPING(rightFront);
//    while ((jBack < 20 || jFront < 20) || (steps == 1 || steps == 3)) {  //Geser Kiri
//      navigasiKiri_pingKanan(20, rightFront, rightBack);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(20, 35, 20, lebarKiri, lebarKanan, lebarTengah);  //22, 40, 36
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 30, 12);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 2 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 30, 12);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while ((TOFDepan < 64) || (steps == 1 || steps == 3)) {  //43
//      navigasiMPU_Mundur(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-22, 30, 20, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 30, 14);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    while ((TOFDepan < 65) || (steps == 1 || steps == 3)) {  //43
//      navigasiMPU_Mundur(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-22, 30, 20, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 1 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 30, 14);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    RotateMPU(90, true);
//    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 25, 16);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    sdtAcuan = yaw;
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bodyKiri.write(175);
//    xSemaphoreGive(mutex);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFKiri();
//    xSemaphoreGive(mutex);
//    stop = true;
//    while (stop == true) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFKiri();
//      xSemaphoreGive(mutex);
//      while ((TOFKiri < 71) || (steps == 1 || steps == 3)) {  //Asli 54
//        navigasiMPU_Kanan(24);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        GerakGeser(-24, 28, 22, lebarKiri, lebarKanan, lebarTengah);
//        xSemaphoreGive(mutex);
//        xSemaphoreTake(mutex, portMAX_DELAY);
//        bacaTOFKiri();
//        xSemaphoreGive(mutex);
//        if (TOFKiri >= 71) {
//          stop = false;
//        }
//      }
//    }
//    bodyKiri.write(0);
//    while (NewDataReady_1 == 0) {
//      bacaTOFDepan();
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan < 41 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Mundur(22);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-22, 28, 18, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    while (NewDataReady_4 == 0) {
//      bacaTOFBelakang();
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFBelakang();
//    xSemaphoreGive(mutex);
//    while (TOFBelakang > 7 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Mundur(15);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-15, 28, 22, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 28, 18);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    RotateMPU(90, true);
//    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 25, 16);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 28, 18);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    while (NewDataReady_2 == 0) {
//      bacaTOFKanan();
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFKanan();
//    xSemaphoreGive(mutex);
//    while (TOFKanan > 7 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Kanan(15);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-15, 28, 22, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFKanan();
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 28, 18);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFBelakang();
//    xSemaphoreGive(mutex);
//    while (TOFBelakang < 48 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Maju(25);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(25, 48, 34, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFKanan();
//    xSemaphoreGive(mutex);
//    while (TOFKanan > 7 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Kanan(15);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-15, 28, 22, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFKanan();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFBelakang();
//    xSemaphoreGive(mutex);
//    while (TOFBelakang < 48 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Maju(25);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(25, 48, 34, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//    }
//    while (NewDataReady_1 == 0) {
//      bacaTOFDepan();
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan > 10 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Maju(25);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(25, 48, 32, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFKanan();
//    xSemaphoreGive(mutex);
//    while (TOFKanan > 7 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Kanan(15);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-15, 28, 22, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFKanan();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan > 10 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Maju(25);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(25, 48, 32, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFKanan();
//    xSemaphoreGive(mutex);
//    while (TOFKanan > 6 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Kanan(15);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakGeser(-15, 32, 24, lebarKiri, lebarKanan, lebarTengah);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFKanan();
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(rightFront, rightBack);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 28, 18);
//      RotJarak(rightFront, rightBack);
//      xSemaphoreGive(mutex);
//    }
//    RotateMPU(90, true);
//    while (abs(Offset) > 3 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(Offset, 32, 20);
//      xSemaphoreGive(mutex);
//      RotateMPU();
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFDepan();
//    xSemaphoreGive(mutex);
//    while (TOFDepan > 8 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Maju(25);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(15, 32, 24, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFDepan();
//      xSemaphoreGive(mutex);
//    }
//    RotJarak(leftBack, leftFront);
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 28, 18);
//      RotJarak(leftBack, leftFront);
//      xSemaphoreGive(mutex);
//    }
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    bacaTOFBelakang();
//    xSemaphoreGive(mutex);
//    while (TOFBelakang > 10 || (steps == 1 || steps == 3)) {
//      navigasiMPU_Mundur(24);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakDinamis(-22, 32, 24, lebarKiri, lebarKanan);
//      xSemaphoreGive(mutex);
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      bacaTOFBelakang();
//      xSemaphoreGive(mutex);
//    }
//    while (NewDataReady_6 == 0 || NewDataReady_5 == 0) {
//      RotJarakTOF();
//    }
//    RotJarakTOF();
//    while (abs(OffsetJarak) > 0 || (steps == 1 || steps == 3)) {
//      xSemaphoreTake(mutex, portMAX_DELAY);
//      GerakRotasi(OffsetJarak, 32, 32);
//      xSemaphoreGive(mutex);
//      RotJarakTOF();
//    }
//    //===Test Gerakan Naik Tangga===//
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    read_MPU();
//    vTaskDelay(20 / portTICK_PERIOD_MS);
//    sdtAcuan = yaw;
//    xSemaphoreGive(mutex);
//    while ((filtered_Roll < 13 && sdtRollTangga) || (steps == 1 || steps == 3)) {
//      GerakSebelumTangga();
//    }
//    sdtRollTangga = false;
//    read_MPU();
//    vTaskDelay(10 / portTICK_PERIOD_MS);
//    while (roll > -11 && sdtRollTangga == false) {
//      GerakanNaikTangga();
//    }
