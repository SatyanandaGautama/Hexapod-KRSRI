void BodyMaju(float speedss) {//gerakan saat ambil korban
  if (!statusGerak) {
    theta = 0;
    Increment = 180 / speedss;
    degAwal = 0;
    degAkhir = 180;
    //KANAN DEPAN (FR)
    xFR0 = -65,  yFR0 = 65, xFR1 = -65, yFR1 = 15, zFR0 = 0, zFRp = 0;
    //KIRI TENGAH (LM)
    xLM0 = 80, yLM0 = 0, xLM1 = 80, yLM1 = -50, zLM0 = 0, zLMp = 0;
    //KANAN BELAKANG (BR)
    xBR0 = -65, yBR0 = -65, xBR1 = -65,  yBR1 = -100, zBR0 = 0, zBRp = 0;
    //KIRI DEPAN (FL)
    xFL0 = 65, yFL0 = 65, xFL1 = 65,  yFL1 = 15, zFL0 = 0, zFLp = 0;
    //KANAN TENGAH (RM)
    xRM0 = -80, yRM0 = 0, xRM1 = -80, yRM1 = -50, zRM0 = 0, zRMp = 0;
    //KIRI BELAKANG (BL)
    xBL0 = 65, yBL0 = -65, xBL1 = 65,  yBL1 = -100, zBL0 = 0, zBLp = 0;
    modeGerak = true;
    statusGerak = true;
  }
}
