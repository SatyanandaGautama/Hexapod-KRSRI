  // // Ganti Mode Kamera
  //   huskylens.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION);
  //   vTaskDelay(15 / portTICK_PERIOD_MS);
  //   stop = true;
  //   bodyKanan.write(180);
  //   bodyKiri.write(140);
  //   vTaskDelay(30 / portTICK_PERIOD_MS);
  //   baca_IR(IRleft);
  //   filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
  //   Sensors = true;
  //   while ((filtered_IR > 8) || (steps == 1 || steps == 3)) {
  //     if (filtered_IR < 25) {
  //       huskylens.request();
  //       if (huskylens.available()) {
  //         dist = readPING(belakang);
  //         while (dist > 8) {
  //           navigasiMPU_Mundur(23);
  //           xSemaphoreTake(mutex, portMAX_DELAY);
  //           GerakDinamis(23, 37, 28, lebarKiri, lebarKanan);
  //           xSemaphoreGive(mutex);
  //           dist = readPING(belakang);
  //         }
  //         Standby();
  //         while (1) {
  //           xSemaphoreTake(mutex, portMAX_DELAY);
  //           TurunCapit(30, 25);
  //           xSemaphoreGive(mutex);
  //           if (Capit == false) {
  //             break;
  //           }
  //         }
  //         while (Sensors == true) {
  //           // while (dist < 20) {
  //           //   navigasi_K4(23);
  //           //   xSemaphoreTake(mutex, portMAX_DELAY);
  //           //   GerakDinamis(23, 37, 28, lebarKiri, lebarKanan);
  //           //   xSemaphoreGive(mutex);
  //           //   dist = readPING(belakang);
  //           // }
  //           readSRF();
  //           while (jarak > 3) {
  //             navigasi_K4(23);
  //             xSemaphoreTake(mutex, portMAX_DELAY);
  //             GerakDinamis(23, 37, 34, lebarKiri, lebarKanan);
  //             xSemaphoreGive(mutex);
  //             readSRF();
  //           }
  //           xSemaphoreTake(mutex, portMAX_DELAY);
  //           BodyMaju_K2(70);
  //           xSemaphoreGive(mutex);
  //           Capit = false;
  //           tServo = 0;
  //           tDyn = 0;
  //           statusGerak = false;
  //           xSemaphoreTake(mutex, portMAX_DELAY);
  //           stepss = 0;
  //           xSemaphoreGive(mutex);
  //           while (1) {
  //             xSemaphoreTake(mutex, portMAX_DELAY);
  //             BodyBalik_K2(25);
  //             xSemaphoreGive(mutex);
  //             if (Capit == false) {
  //               Sensors = false;
  //               break;
  //             }
  //           }
  //         }
  //       }
  //     }  //7

  //     navigasiMPU_Kiri(26);
  //     xSemaphoreTake(mutex, portMAX_DELAY);
  //     GerakGeser(22, 48, 34, lebarKiri, lebarKanan, lebarTengah);
  //     xSemaphoreGive(mutex);
  //     baca_IR(IRleft);
  //     filtered_IR = ((1 - weight) * filtered_IR) + (weight * distances);
  //   }