void BodyMaju(int speeds, int panjang) {//gerakan saat ambil korban
  if (!statusGerak) {
    theta = 0;
    Increment = 180 / speeds;
    degAwal = 0;
    degAkhir = 180;
    //KANAN DEPAN (FR)
    xFR0 = xFR,  yFR0 = yFR, xFR1 = xFR, yFR1 = yFR - panjang, zFRp = 0;
    //KIRI TENGAH (LM)
    xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM - panjang, zLMp = 0;
    //KANAN BELAKANG (BR)
    xBR0 = xBR, yBR0 = yBR, xBR1 = xBR,  yBR1 = yBR - panjang, zBRp = 0;
    //KIRI DEPAN (FL)
    xFL0 = xFL, yFL0 = yFL, xFL1 = xFL,  yFL1 = yFL - panjang, zFLp = 0;
    //KANAN TENGAH (RM)
    xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM - panjang, zRMp = 0;
    //KIRI BELAKANG (BL)
    xBL0 = xBL, yBL0 = yBL, xBL1 = xBL,  yBL1 = yBL - panjang, zBLp = 0;
    modeGerak = true;
    statusGerak = true;
  }
}

void BodyMundur(int speeds) {
  if (!statusGerak) {
    theta = 0;
    Increment = 180 / speeds;
    degAwal = 0;
    degAkhir = 180;
    //KANAN DEPAN (FR)
    xFR0 = -55,  yFR0 = 65, xFR1 = -65, yFR1 = 15, zFRp = 0;
    //KIRI TENGAH (LM)
    xLM0 = 80, yLM0 = 0, xLM1 = 80, yLM1 = -50, zLMp = 0;
    //KANAN BELAKANG (BR)
    xBR0 = -65, yBR0 = -65, xBR1 = -65,  yBR1 = -100, zBRp = 0;
    //KIRI DEPAN (FL)
    xFL0 = 65, yFL0 = 65, xFL1 = 65,  yFL1 = 15, zFLp = 0;
    //KANAN TENGAH (RM)
    xRM0 = -80, yRM0 = 0, xRM1 = -80, yRM1 = -50, zRMp = 0;
    //KIRI BELAKANG (BL)
    xBL0 = 65, yBL0 = -65, xBL1 = 65,  yBL1 = -100, zBLp = 0;
    modeGerak = true;
    statusGerak = true;
  }
}

void YawKanan(int speeds) {
  if (!statusGerak) {
    theta = 0;
    Increment = 180 / speeds;
    degAwal = 0;
    degAkhir = 180;
    //KANAN DEPAN (FR)
    xFR0 = -55,  yFR0 = 65, xFR1 = -65, yFR1 = 15, zFRp = 0;
    //KIRI TENGAH (LM)
    xLM0 = 80, yLM0 = 0, xLM1 = 80, yLM1 = -50, zLMp = 0;
    //KANAN BELAKANG (BR)
    xBR0 = -65, yBR0 = -65, xBR1 = -65,  yBR1 = -100, zBRp = 0;
    //KIRI DEPAN (FL)
    xFL0 = 65, yFL0 = 65, xFL1 = 65,  yFL1 = 15, zFLp = 0;
    //KANAN TENGAH (RM)
    xRM0 = -80, yRM0 = 0, xRM1 = -80, yRM1 = -50, zRMp = 0;
    //KIRI BELAKANG (BL)
    xBL0 = 65, yBL0 = -65, xBL1 = 65,  yBL1 = -100, zBLp = 0;
    modeGerak = true;
    statusGerak = true;
  }
}

void YawKiri(int speeds) {
  if (!statusGerak) {
    theta = 0;
    Increment = 180 / speeds;
    degAwal = 0;
    degAkhir = 180;
    //KANAN DEPAN (FR)
    xFR0 = -65,  yFR0 = 65, xFR1 = -65, yFR1 = 15, zFRp = 0;
    //KIRI TENGAH (LM)
    xLM0 = 80, yLM0 = 0, xLM1 = 80, yLM1 = -50, zLMp = 0;
    //KANAN BELAKANG (BR)
    xBR0 = -65, yBR0 = -65, xBR1 = -65,  yBR1 = -100, zBRp = 0;
    //KIRI DEPAN (FL)
    xFL0 = 65, yFL0 = 65, xFL1 = 65,  yFL1 = 15, zFLp = 0;
    //KANAN TENGAH (RM)
    xRM0 = -80, yRM0 = 0, xRM1 = -80, yRM1 = -50, zRMp = 0;
    //KIRI BELAKANG (BL)
    xBL0 = 65, yBL0 = -65, xBL1 = 65,  yBL1 = -100, zBLp = 0;
    modeGerak = true;
    statusGerak = true;
  }
}

//Gerakan pengambilan korban :
//1. Body Mundur(Awal dan Tujuan Fix)
//2. Body Rotasi Yaw sesuai Sudut Max yang telah ditentukan (Awal dan Tujuan Fix), hingga korban berada di tengah (langsung break)
//3. Turunkan Capit
//4. Body Maju ambil korban (Awal = Posisi x,y terakhir sebelum break rotasi Yaw, Tujuan = Awal + Maju Maksimal) hingga jarak sesuai (langsung break)
