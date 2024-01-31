void Kaki(void *pvParameters) {
  while (1) {
    xSemaphoreTake(bin_sem, portMAX_DELAY);
    if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
      TrayektoriSinus();
      if (!isnan(sdtcoxa) && !isnan(sdtfemur) && !isnan(sdttibia)) {
        KirimIntruksiGerak(0);
      }
      if (Sensors) {
        Sensors = false;
      }
      xSemaphoreGive(mutex);
    }
    vTaskDelay(17 / portTICK_PERIOD_MS);
  }
}

//=========Gerak Dinamis======//
void TransformasiGerak(float lebarY, float lbrKiri, float lbrKanan) {
  //Kanan maju duluan && Belok Kanan = lbr(+), Belok kiri = lbr(-)
  //KANAN DEPAN (FR)
  yFR_Awal = (standFR[1][0] - lebarY) + lbrKanan, yFR_Akhir = (standFR[1][0] + lebarY) - lbrKanan;
  //KIRI TENGAH (LM)
  yLM_Awal = (standLM[1][0] - lebarY) - lbrKiri, yLM_Akhir = (standLM[1][0] + lebarY) + lbrKiri;
  //KANAN BELAKANG (BR)
  yBR_Awal = (standBR[1][0] - lebarY) + lbrKanan, yBR_Akhir = (standBR[1][0] + lebarY) - lbrKanan;
  //KIRI DEPAN (FL)
  yFL_Awal = (standFL[1][0] + lebarY) + lbrKiri, yFL_Akhir = (standFL[1][0] - lebarY) - lbrKiri;
  //KANAN TENGAH (RM)
  yRM_Awal = (standRM[1][0] + lebarY) - lbrKanan, yRM_Akhir = (standRM[1][0] - lebarY) + lbrKanan;
  //KIRI BELAKANG (BL)
  yBL_Awal = (standBL[1][0] + lebarY) + lbrKiri, yBL_Akhir = (standBL[1][0] - lebarY) - lbrKiri;
}

void GerakDinamis(float Lebar, float tinggi, float speeds, float lKiri, float lKanan) { //lebarY : maju (+), mundur (-)
  Increment = 180 / speeds;
  if (!statusGerak) {
    switch (steps) {
      case 0 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGerak(Lebar, lKiri, lKanan);
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
        break;
      case 1:
        degAwal = 90 + Increment;
        degAkhir = 90;
        TransformasiGerak(Lebar, lKiri, lKanan);
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
        break;
      case 2 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGerak(Lebar, lKiri, lKanan);
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
        break;
      case 3 :
        degAwal = 90 + Increment;
        degAkhir = 90;
        TransformasiGerak(Lebar, lKiri, lKanan);
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
        break;
    }
    steps++;
    if (steps > 3) steps = 0;
  }
}

void TransformasiGeser(float lebarX, float lbrKiri, float lbrKanan, float lbrTengah) {
  //KANAN DEPAN (FR)
  xFR_Awal = (standFR[0][0] - lebarX) + lbrKanan, xFR_Akhir = (standFR[0][0] + lebarX) - lbrKanan;
  //KIRI TENGAH (LM)
  xLM_Awal = (standLM[0][0] - lebarX) + lbrTengah, xLM_Akhir = (standLM[0][0] + lebarX) - lbrTengah; //+ lbrKiri;
  //KANAN BELAKANG (BR)
  xBR_Awal = (standBR[0][0] - lebarX) + lbrKiri, xBR_Akhir = (standBR[0][0] + lebarX) - lbrKiri;
  //KIRI DEPAN (FL)
  xFL_Awal = (standFL[0][0] + lebarX) - lbrKanan, xFL_Akhir = (standFL[0][0] - lebarX) + lbrKanan;
  //KANAN TENGAH (RM)
  xRM_Awal = (standRM[0][0] + lebarX) - lbrTengah, xRM_Akhir = (standRM[0][0] - lebarX) + lbrTengah; //+ lbrKanan;
  //KIRI BELAKANG (BL)
  xBL_Awal = (standBL[0][0] + lebarX) - lbrKiri, xBL_Akhir = (standBL[0][0] - lebarX) + lbrKiri;
}

void GerakGeser(float Lebar, float tinggi, float speedsss, float lKiri, float lKanan, float lTengah) { //Geser Kiri = Lebar(+), Geser Kanan = Lebar(-)
  if (Lebar > 25)Lebar = 25;
  if (Lebar < -25)Lebar = -25;
  lTengah = lTengah / 2;
  Increment = 180 / speedsss;
  if (!statusGerak) {
    switch (steps) {
      case 0 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGeser(Lebar, lKiri, lKanan, lTengah);
        //KANAN DEPAN (FR)
        xFR0 = xFR_Awal,  yFR0 =  standFR[1][0], xFR1 = xFR_Akhir, yFR1 = standFR[1][0], zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Awal,  yLM0 =  standLM[1][0], xLM1 = xLM_Akhir, yLM1 = standLM[1][0], zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = xBR_Awal,  yBR0 =  standBR[1][0], xBR1 = xBR_Akhir, yBR1 = standBR[1][0], zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Awal,  yFL0 =  standFL[1][0], xFL1 = xFL_Akhir, yFL1 = standFL[1][0], zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM_Awal,  yRM0 =  standRM[1][0], xRM1 = xRM_Akhir, yRM1 = standRM[1][0], zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL_Awal,  yBL0 = standBL[1][0], xBL1 = xBL_Akhir, yBL1 = standBL[1][0], zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        degAwal = 90 + Increment;
        degAkhir = 90;
        TransformasiGeser(Lebar, lKiri, lKanan, lTengah);
        //KANAN DEPAN (FR)
        xFR0 = xFR_Akhir,  yFR0 =  standFR[1][0], xFR1 = xFR_Awal, yFR1 = standFR[1][0], zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Akhir,  yLM0 =  standLM[1][0], xLM1 = xLM_Awal, yLM1 = standLM[1][0], zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR_Akhir,  yBR0 =  standBR[1][0], xBR1 = xBR_Awal, yBR1 = standBR[1][0], zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Akhir,  yFL0 =  standFL[1][0], xFL1 = xFL_Awal, yFL1 = standFL[1][0], zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = xRM_Akhir,  yRM0 =  standRM[1][0], xRM1 = xRM_Awal, yRM1 = standRM[1][0], zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = xBL_Akhir, yBL0 = standBL[1][0], xBL1 =  xBL_Awal, yBL1 = standBL[1][0], zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGeser(Lebar, lKiri, lKanan, lTengah);
        //KANAN DEPAN (FR)
        xFR0 = xFR_Akhir,  yFR0 =  standFR[1][0], xFR1 = xFR_Awal, yFR1 = standFR[1][0], zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Akhir,  yLM0 =  standLM[1][0], xLM1 = xLM_Awal, yLM1 = standLM[1][0], zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR_Akhir,  yBR0 =  standBR[1][0], xBR1 = xBR_Awal, yBR1 = standBR[1][0], zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Akhir,  yFL0 =  standFL[1][0], xFL1 = xFL_Awal, yFL1 = standFL[1][0], zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = xRM_Akhir,  yRM0 =  standRM[1][0], xRM1 = xRM_Awal, yRM1 = standRM[1][0], zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = xBL_Akhir, yBL0 = standBL[1][0], xBL1 =  xBL_Awal, yBL1 = standBL[1][0], zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 3 :
        degAwal = 90 + Increment;
        degAkhir = 90;
        TransformasiGeser(Lebar, lKiri, lKanan, lTengah);
        //KANAN DEPAN (FR)
        xFR0 = xFR_Awal,  yFR0 =  standFR[1][0], xFR1 = xFR_Akhir, yFR1 = standFR[1][0], zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Awal,  yLM0 =  standLM[1][0], xLM1 = xLM_Akhir, yLM1 = standLM[1][0], zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = xBR_Awal,  yBR0 =  standBR[1][0], xBR1 = xBR_Akhir, yBR1 = standBR[1][0], zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Awal,  yFL0 =  standFL[1][0], xFL1 = xFL_Akhir, yFL1 = standFL[1][0], zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM_Awal,  yRM0 =  standRM[1][0], xRM1 = xRM_Akhir, yRM1 = standRM[1][0], zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL_Awal,  yBL0 = standBL[1][0], xBL1 = xBL_Akhir, yBL1 = standBL[1][0], zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    steps++;
    if (steps > 3) steps = 0;
  }
}

//Untuk Rintangan Naik Tangga
//Asumsi Geser Kiri
void TransformasiGeser_v2(float KeluarRight, float MasukRight, float KeluarLeft, float MasukLeft, float lbrKiri, float lbrKanan, float lbrTengah) {
  //KANAN DEPAN (FR)
  xFR_Awal = (standFR[0][0] - MasukRight) + lbrKanan, xFR_Akhir = (standFR[0][0] + KeluarRight) - lbrKanan;
  //KANAN TENGAH (RM)
  xRM_Awal = (standRM[0][0] + MasukRight) - lbrTengah, xRM_Akhir = (standRM[0][0] - KeluarRight) + lbrTengah;
  //KANAN BELAKANG (BR)
  xBR_Awal = (standBR[0][0] - MasukRight) + lbrKiri, xBR_Akhir = (standBR[0][0] + KeluarRight) - lbrKiri;
  //KIRI DEPAN (FL)
  xFL_Awal = (standFL[0][0] + MasukLeft) - lbrKanan, xFL_Akhir = (standFL[0][0] - KeluarLeft) + lbrKanan;
  //KIRI TENGAH (LM)
  xLM_Awal = (standLM[0][0] - MasukLeft) + lbrTengah, xLM_Akhir = (standLM[0][0] + KeluarLeft) - lbrTengah;
  //KIRI BELAKANG (BL)
  xBL_Awal = (standBL[0][0] + MasukLeft) - lbrKiri, xBL_Akhir = (standBL[0][0] - KeluarLeft) + lbrKiri;
}

void GerakGeser_v2(float KeluarKanan, float MasukKanan, float KeluarKiri, float MasukKiri, float tinggi, float speedsss, float lKiri, float lKanan, float lTengah) { //Geser Kiri = Lebar(+), Geser Kanan = Lebar(-)
  lTengah = lTengah / 2;
  Increment = 180 / speedsss;
  if (!statusGerak) {
    switch (steps) {
      case 0 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGeser_v2(KeluarKanan, MasukKanan, KeluarKiri, MasukKiri, lKiri, lKanan, lTengah);
        //KANAN DEPAN (FR)
        xFR0 = xFR_Awal,  yFR0 =  standFR[1][0], xFR1 = xFR_Akhir, yFR1 = standFR[1][0], zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Awal,  yLM0 =  standLM[1][0], xLM1 = xLM_Akhir, yLM1 = standLM[1][0], zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = xBR_Awal,  yBR0 =  standBR[1][0], xBR1 = xBR_Akhir, yBR1 = standBR[1][0], zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Awal,  yFL0 =  standFL[1][0], xFL1 = xFL_Akhir, yFL1 = standFL[1][0], zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM_Awal,  yRM0 =  standRM[1][0], xRM1 = xRM_Akhir, yRM1 = standRM[1][0], zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL_Awal,  yBL0 = standBL[1][0], xBL1 = xBL_Akhir, yBL1 = standBL[1][0], zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        degAwal = 90 + Increment;
        degAkhir = 90;
        TransformasiGeser_v2(KeluarKanan, MasukKanan, KeluarKiri, MasukKiri, lKiri, lKanan, lTengah);
        //KANAN DEPAN (FR)
        xFR0 = xFR_Akhir,  yFR0 =  standFR[1][0], xFR1 = xFR_Awal, yFR1 = standFR[1][0], zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Akhir,  yLM0 =  standLM[1][0], xLM1 = xLM_Awal, yLM1 = standLM[1][0], zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR_Akhir,  yBR0 =  standBR[1][0], xBR1 = xBR_Awal, yBR1 = standBR[1][0], zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Akhir,  yFL0 =  standFL[1][0], xFL1 = xFL_Awal, yFL1 = standFL[1][0], zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = xRM_Akhir,  yRM0 =  standRM[1][0], xRM1 = xRM_Awal, yRM1 = standRM[1][0], zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = xBL_Akhir, yBL0 = standBL[1][0], xBL1 =  xBL_Awal, yBL1 = standBL[1][0], zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGeser_v2(KeluarKanan, MasukKanan, KeluarKiri, MasukKiri, lKiri, lKanan, lTengah);
        //KANAN DEPAN (FR)
        xFR0 = xFR_Akhir,  yFR0 =  standFR[1][0], xFR1 = xFR_Awal, yFR1 = standFR[1][0], zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Akhir,  yLM0 =  standLM[1][0], xLM1 = xLM_Awal, yLM1 = standLM[1][0], zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR_Akhir,  yBR0 =  standBR[1][0], xBR1 = xBR_Awal, yBR1 = standBR[1][0], zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Akhir,  yFL0 =  standFL[1][0], xFL1 = xFL_Awal, yFL1 = standFL[1][0], zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = xRM_Akhir,  yRM0 =  standRM[1][0], xRM1 = xRM_Awal, yRM1 = standRM[1][0], zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = xBL_Akhir, yBL0 = standBL[1][0], xBL1 =  xBL_Awal, yBL1 = standBL[1][0], zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 3 :
        degAwal = 90 + Increment;
        degAkhir = 90;
        TransformasiGeser_v2(KeluarKanan, MasukKanan, KeluarKiri, MasukKiri, lKiri, lKanan, lTengah);
        //KANAN DEPAN (FR)
        xFR0 = xFR_Awal,  yFR0 =  standFR[1][0], xFR1 = xFR_Akhir, yFR1 = standFR[1][0], zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Awal,  yLM0 =  standLM[1][0], xLM1 = xLM_Akhir, yLM1 = standLM[1][0], zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = xBR_Awal,  yBR0 =  standBR[1][0], xBR1 = xBR_Akhir, yBR1 = standBR[1][0], zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Awal,  yFL0 =  standFL[1][0], xFL1 = xFL_Akhir, yFL1 = standFL[1][0], zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM_Awal,  yRM0 =  standRM[1][0], xRM1 = xRM_Akhir, yRM1 = standRM[1][0], zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL_Awal,  yBL0 = standBL[1][0], xBL1 = xBL_Akhir, yBL1 = standBL[1][0], zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    steps++;
    if (steps > 3) steps = 0;
  }
}
