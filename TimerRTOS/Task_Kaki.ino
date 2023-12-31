void Kaki(void *pvParameters) {
  while (1) {
    xSemaphoreTake(bin_sem, portMAX_DELAY);
    if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
      TrayektoriSinus();
      if (!isnan(sdtcoxa) && !isnan(sdtfemur) && !isnan(sdttibia)) {
        KirimIntruksiGerak(0);
      }
      xSemaphoreGive(mutex);
    }
    //    else {
    //      Serial.println("NULL");
    //      mut = true;
    //    }
    vTaskDelay(17 / portTICK_PERIOD_MS);
  }
}

void TransformasiGerak(float lebarY, float lbr) {
  //Kanan maju duluan && Belok Kanan = lbr(+), Belok kiri = lbr(-)
  //KANAN DEPAN (FR)
  yFR_Awal = (standFR[1][0] - lebarY) + lbr, yFR_Akhir = (standFR[1][0] + lebarY) - lbr;
  //KIRI TENGAH (LM)
  yLM_Awal = (standLM[1][0] - lebarY) - lbr, yLM_Akhir = (standLM[1][0] + lebarY) + lbr;
  //KANAN BELAKANG (BR)
  yBR_Awal = (standBR[1][0] - lebarY) + lbr, yBR_Akhir = (standBR[1][0] + lebarY) - lbr;
  //KIRI DEPAN (FL)
  yFL_Awal = (standFL[1][0] + lebarY) + lbr, yFL_Akhir = (standFL[1][0] - lebarY) - lbr;
  //KANAN TENGAH (RM)
  yRM_Awal = (standRM[1][0] + lebarY) - lbr, yRM_Akhir = (standRM[1][0] - lebarY) + lbr;
  //KIRI BELAKANG (BL)
  yBL_Awal = (standBL[1][0] + lebarY) + lbr, yBL_Akhir = (standBL[1][0] - lebarY) - lbr;
}

//======Gerak Dinamis versi Trayektori Sinus======//
void GerakDinamis(float Lebar, float tinggi, float speeds, float PanjangLangkah) { //lebarY : maju (+), mundur (-)
  Increment = 180 / speeds;
  if (!statusGerak) {
    switch (steps) {
      case 0 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGerak(Lebar, PanjangLangkah);
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0],  yFR0 =  yFR_Awal, xFR1 = standFR[0][0] , yFR1 = yFR_Akhir, zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = standLM[0][0],  yLM0 =  yLM_Awal, xLM1 = standLM[0][0] , yLM1 = yLM_Akhir, zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0],  yBR0 =  yBR_Awal, xBR1 = standBR[0][0], yBR1 = yBR_Akhir, zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0],  yFL0 =  yFL_Awal, xFL1 = standFL[0][0], yFL1 = yFL_Akhir, zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = standRM[0][0],  yRM0 =  yRM_Awal, xRM1 = standRM[0][0], yRM1 = yRM_Akhir, zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0],  yBL0 = yBL_Awal, xBL1 =  standBL[0][0], yBL1 = yBL_Akhir, zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        //        Serial.println("1");
        break;
      case 1:
        degAwal = 90 + Increment;
        degAkhir = 90;
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0],  yFR0 =  yFR_Akhir, xFR1 = standFR[0][0] , yFR1 = yFR_Awal, zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = standLM[0][0],  yLM0 =  yLM_Akhir, xLM1 = standLM[0][0] , yLM1 = yLM_Awal, zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0],  yBR0 =  yBR_Akhir, xBR1 = standBR[0][0], yBR1 = yBR_Awal, zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0],  yFL0 =  yFL_Akhir, xFL1 = standFL[0][0], yFL1 = yFL_Awal, zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = standRM[0][0],  yRM0 =  yRM_Akhir, xRM1 = standRM[0][0], yRM1 = yRM_Awal, zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0],  yBL0 = yBL_Akhir, xBL1 =  standBL[0][0], yBL1 = yBL_Awal, zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        //        Serial.println("2");
        break;
      case 2 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGerak(Lebar, PanjangLangkah);
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0],  yFR0 =  yFR_Akhir, xFR1 = standFR[0][0] , yFR1 = yFR_Awal, zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = standLM[0][0],  yLM0 =  yLM_Akhir, xLM1 = standLM[0][0] , yLM1 = yLM_Awal, zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0],  yBR0 =  yBR_Akhir, xBR1 = standBR[0][0], yBR1 = yBR_Awal, zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0],  yFL0 =  yFL_Akhir, xFL1 = standFL[0][0], yFL1 = yFL_Awal, zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = standRM[0][0],  yRM0 =  yRM_Akhir, xRM1 = standRM[0][0], yRM1 = yRM_Awal, zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0],  yBL0 = yBL_Akhir, xBL1 =  standBL[0][0], yBL1 = yBL_Awal, zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        //        Serial.println("3");
        break;
      case 3 :
        degAwal = 90 + Increment;
        degAkhir = 90;
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0],  yFR0 =  yFR_Awal, xFR1 = standFR[0][0] , yFR1 = yFR_Akhir, zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = standLM[0][0],  yLM0 =  yLM_Awal, xLM1 = standLM[0][0] , yLM1 = yLM_Akhir, zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0],  yBR0 =  yBR_Awal, xBR1 = standBR[0][0], yBR1 = yBR_Akhir, zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0],  yFL0 =  yFL_Awal, xFL1 = standFL[0][0], yFL1 = yFL_Akhir, zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = standRM[0][0],  yRM0 =  yRM_Awal, xRM1 = standRM[0][0], yRM1 = yRM_Akhir, zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0],  yBL0 = yBL_Awal, xBL1 =  standBL[0][0], yBL1 = yBL_Akhir, zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        //        Serial.println("4");
        break;
    }
    steps++;
    if (steps > 3) steps = 0;
  }
}

//======Gerak Dinamis versi Trayektori Beizer======//
//void GerakDinamis(float Lebar, float tinggi, float speeds, float PanjangLangkah) { //lebarY : 30 (maju) -30 (mundur)
//  Increment = 1 / speeds;
//  if (!statusGerak) {
//    switch (steps) {
//      case 0 :
//        tAwal = 0 + Increment;
//        tAkhir = 1;
//        TransformasiGerak(Lebar, PanjangLangkah);
//        //KANAN DEPAN (FR)
//        xFR0 = standFR[0][0],  yFR0 =  yFR_Awal, xFR1 = standFR[0][0] , yFR1 = yFR_Akhir, zFR0 = 0, zFRp = tinggi;
//        //KIRI TENGAH (LM)
//        xLM0 = standLM[0][0],  yLM0 =  yLM_Awal, xLM1 = standLM[0][0] , yLM1 = yLM_Akhir, zLM0 = 0, zLMp = tinggi;
//        //KANAN BELAKANG (BR)
//        xBR0 = standBR[0][0],  yBR0 =  yBR_Awal, xBR1 = standBR[0][0], yBR1 = yBR_Akhir, zBR0 = 0, zBRp = tinggi;
//        //KIRI DEPAN (FL)
//        xFL0 = standFL[0][0],  yFL0 =  yFL_Awal, xFL1 = standFL[0][0], yFL1 = yFL_Akhir, zFL0 = 0, zFLp = 0;
//        //KANAN TENGAH (RM)
//        xRM0 = standRM[0][0],  yRM0 =  yRM_Awal, xRM1 = standRM[0][0], yRM1 = yRM_Akhir, zRM0 = 0, zRMp = 0;
//        //KIRI BELAKANG (BL)
//        xBL0 = standBL[0][0],  yBL0 = yBL_Awal, xBL1 =  standBL[0][0], yBL1 = yBL_Akhir, zBL0 = 0, zBLp = 0;
//        statusGerak = true;
//        modeGerak = true;
//        break;
//      case 1:
//        tAwal = 0.5 + Increment;
//        tAkhir = 0.5;
//        //KANAN DEPAN (FR)
//        xFR0 = standFR[0][0],  yFR0 =  yFR_Akhir, xFR1 = standFR[0][0] , yFR1 = yFR_Awal, zFR0 = 0, zFRp = 0;
//        //KIRI TENGAH (LM)
//        xLM0 = standLM[0][0],  yLM0 =  yLM_Akhir, xLM1 = standLM[0][0] , yLM1 = yLM_Awal, zLM0 = 0, zLMp = 0;
//        //KANAN BELAKANG (BR)
//        xBR0 = standBR[0][0],  yBR0 =  yBR_Akhir, xBR1 = standBR[0][0], yBR1 = yBR_Awal, zBR0 = 0, zBRp = 0;
//        //KIRI DEPAN (FL)
//        xFL0 = standFL[0][0],  yFL0 =  yFL_Akhir, xFL1 = standFL[0][0], yFL1 = yFL_Awal, zFL0 = 0, zFLp = tinggi;
//        //KANAN TENGAH (RM)
//        xRM0 = standRM[0][0],  yRM0 =  yRM_Akhir, xRM1 = standRM[0][0], yRM1 = yRM_Awal, zRM0 = 0, zRMp = tinggi;
//        //KIRI BELAKANG (BL)
//        xBL0 = standBL[0][0],  yBL0 = yBL_Akhir, xBL1 =  standBL[0][0], yBL1 = yBL_Awal, zBL0 = 0, zBLp = tinggi;
//        statusGerak = true;
//        modeGerak = true;
//        break;
//      case 2 :
//        tAwal = 0 + Increment;
//        tAkhir = 1;
//        TransformasiGerak(Lebar, PanjangLangkah);
//        //KANAN DEPAN (FR)
//        xFR0 = standFR[0][0],  yFR0 =  yFR_Akhir, xFR1 = standFR[0][0] , yFR1 = yFR_Awal, zFR0 = 0, zFRp = 0;
//        //KIRI TENGAH (LM)
//        xLM0 = standLM[0][0],  yLM0 =  yLM_Akhir, xLM1 = standLM[0][0] , yLM1 = yLM_Awal, zLM0 = 0, zLMp = 0;
//        //KANAN BELAKANG (BR)
//        xBR0 = standBR[0][0],  yBR0 =  yBR_Akhir, xBR1 = standBR[0][0], yBR1 = yBR_Awal, zBR0 = 0, zBRp = 0;
//        //KIRI DEPAN (FL)
//        xFL0 = standFL[0][0],  yFL0 =  yFL_Akhir, xFL1 = standFL[0][0], yFL1 = yFL_Awal, zFL0 = 0, zFLp = tinggi;
//        //KANAN TENGAH (RM)
//        xRM0 = standRM[0][0],  yRM0 =  yRM_Akhir, xRM1 = standRM[0][0], yRM1 = yRM_Awal, zRM0 = 0, zRMp = tinggi;
//        //KIRI BELAKANG (BL)
//        xBL0 = standBL[0][0],  yBL0 = yBL_Akhir, xBL1 =  standBL[0][0], yBL1 = yBL_Awal, zBL0 = 0, zBLp = tinggi;
//        statusGerak = true;
//        modeGerak = true;
//        break;
//      case 3 :
//        tAwal = 0.5 + Increment;
//        tAkhir = 0.5;
//        //KANAN DEPAN (FR)
//        xFR0 = standFR[0][0],  yFR0 =  yFR_Awal, xFR1 = standFR[0][0] , yFR1 = yFR_Akhir, zFR0 = 0, zFRp = tinggi;
//        //KIRI TENGAH (LM)
//        xLM0 = standLM[0][0],  yLM0 =  yLM_Awal, xLM1 = standLM[0][0] , yLM1 = yLM_Akhir, zLM0 = 0, zLMp = tinggi;
//        //KANAN BELAKANG (BR)
//        xBR0 = standBR[0][0],  yBR0 =  yBR_Awal, xBR1 = standBR[0][0], yBR1 = yBR_Akhir, zBR0 = 0, zBRp = tinggi;
//        //KIRI DEPAN (FL)
//        xFL0 = standFL[0][0],  yFL0 =  yFL_Awal, xFL1 = standFL[0][0], yFL1 = yFL_Akhir, zFL0 = 0, zFLp = 0;
//        //KANAN TENGAH (RM)
//        xRM0 = standRM[0][0],  yRM0 =  yRM_Awal, xRM1 = standRM[0][0], yRM1 = yRM_Akhir, zRM0 = 0, zRMp = 0;
//        //KIRI BELAKANG (BL)
//        xBL0 = standBL[0][0],  yBL0 = yBL_Awal, xBL1 =  standBL[0][0], yBL1 = yBL_Akhir, zBL0 = 0, zBLp = 0;
//        statusGerak = true;
//        modeGerak = true;
//        break;
//    }
//    steps++;
//    if (steps > 3) steps = 0;
//  }
//}
