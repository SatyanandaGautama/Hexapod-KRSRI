void Rotate(float rot) {
  rot = rot / 180 * M_PI;
  float rotasi[3][3] = {{cos(rot), -sin(rot), 0},
    {sin(rot), cos(rot), 0},
    {0, 0, 1}
  };
  float P1[3][1] = {0};
  float P2[3][1] = {0};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      for (int k = 0; k < 2; k++) {
        P1[i][j] += rotasi[i][k] * standFL[k][j];
        P2[i][j] += rotasi[i][k] * standLM[k][j];
      }
    }
  }
  if (arahPutar < 0) {
    if (rot >= 0) {
      xFL_Awal = round((P1[0][0]));//FL
      yFL_Awal = round((P1[1][0]));//FL
      xLM_Awal = round((P2[0][0]));//LM
      yLM_Awal = round((P2[1][0]));//LM
    }
    if (rot < 0) {
      xFL_Akhir = round((P1[0][0]));//FL
      yFL_Akhir = round((P1[1][0]));//FL
      xLM_Akhir = round((P2[0][0]));//LM
      yLM_Akhir = round((P2[1][0]));//LM
    }
  }
  if (arahPutar > 0) {
    if (rot < 0) {
      xFL_Awal = round((P1[0][0]));//FL
      yFL_Awal = round((P1[1][0]));//FL
      xLM_Awal = round((P2[0][0]));//LM
      yLM_Awal = round((P2[1][0]));//LM
    }
    if (rot >= 0) {
      xFL_Akhir = round((P1[0][0]));//FL
      yFL_Akhir = round((P1[1][0]));//FL
      xLM_Akhir = round((P2[0][0]));//LM
      yLM_Akhir = round((P2[1][0]));//LM
    }
  }
}

void GerakRotasi(float degree, float tinggi, float speeds) { //Sudut + (putar kanan), sudut - (putar kiri)
  if (degree > 30)degree = 30;
  if (degree < -30)degree = -30;
  arahPutar = degree;
  Increment = 180 / speeds;
  if (!statusGerak) {
    switch (steps) {
      case 0 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        Rotate(degree);
        Rotate(-1 * (degree));
        //KANAN DEPAN (FR)
        xFR0 = -(xFL_Akhir),  yFR0 =  yFL_Akhir, xFR1 = -(xFL_Awal), yFR1 = yFL_Awal, zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Awal,  yLM0 =  yLM_Awal, xLM1 = xLM_Akhir, yLM1 = yLM_Akhir, zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = -(xFL_Awal),  yBR0 =  -(yFL_Awal), xBR1 = -(xFL_Akhir), yBR1 = -(yFL_Akhir), zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Akhir,  yFL0 =  yFL_Akhir, xFL1 = xFL_Awal, yFL1 = yFL_Awal, zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -(xLM_Awal),  yRM0 =  yLM_Awal, xRM1 = -(xLM_Akhir), yRM1 = yLM_Akhir, zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xFL_Awal,  yBL0 = -(yFL_Awal), xBL1 =  xFL_Akhir, yBL1 = -(yFL_Akhir), zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        degAwal = 90 + Increment;
        degAkhir = 90;
        //KANAN DEPAN (FR)
        xFR0 = -(xFL_Awal),  yFR0 =  yFL_Awal, xFR1 = -(xFL_Akhir), yFR1 = yFL_Akhir, zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Akhir,  yLM0 =  yLM_Akhir, xLM1 = xLM_Awal, yLM1 = yLM_Awal, zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -(xFL_Akhir),  yBR0 =  -(yFL_Akhir), xBR1 = -(xFL_Awal), yBR1 = -(yFL_Awal), zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Awal,  yFL0 =  yFL_Awal, xFL1 = xFL_Akhir, yFL1 = yFL_Akhir, zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = -(xLM_Akhir),  yRM0 =  yLM_Akhir, xRM1 = -(xLM_Awal), yRM1 = yLM_Awal, zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = xFL_Akhir,  yBL0 = -(yFL_Akhir), xBL1 =  xFL_Awal, yBL1 = -(yFL_Awal), zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        Rotate(degree);
        Rotate(-1 * (degree));
        //KANAN DEPAN (FR)
        xFR0 = -(xFL_Awal),  yFR0 =  yFL_Awal, xFR1 = -(xFL_Akhir), yFR1 = yFL_Akhir, zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Akhir,  yLM0 =  yLM_Akhir, xLM1 = xLM_Awal, yLM1 = yLM_Awal, zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -(xFL_Akhir),  yBR0 =  -(yFL_Akhir), xBR1 = -(xFL_Awal), yBR1 = -(yFL_Awal), zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Awal,  yFL0 =  yFL_Awal, xFL1 = xFL_Akhir, yFL1 = yFL_Akhir, zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = -(xLM_Akhir),  yRM0 =  yLM_Akhir, xRM1 = -(xLM_Awal), yRM1 = yLM_Awal, zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = xFL_Akhir,  yBL0 = -(yFL_Akhir), xBL1 =  xFL_Awal, yBL1 = -(yFL_Awal), zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 3 :
        degAwal = 90 + Increment;
        degAkhir = 90;
        //KANAN DEPAN (FR)
        xFR0 = -(xFL_Akhir),  yFR0 =  yFL_Akhir, xFR1 = -(xFL_Awal), yFR1 = yFL_Awal, zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Awal,  yLM0 =  yLM_Awal, xLM1 = xLM_Akhir, yLM1 = yLM_Akhir, zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = -(xFL_Awal),  yBR0 =  -(yFL_Awal), xBR1 = -(xFL_Akhir), yBR1 = -(yFL_Akhir), zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Akhir,  yFL0 =  yFL_Akhir, xFL1 = xFL_Awal, yFL1 = yFL_Awal, zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -(xLM_Awal),  yRM0 =  yLM_Awal, xRM1 = -(xLM_Akhir), yRM1 = yLM_Akhir, zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xFL_Awal,  yBL0 = -(yFL_Awal), xBL1 =  xFL_Akhir, yBL1 = -(yFL_Akhir), zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    steps++;
    if (steps > 3) steps = 0;
  }
}

void Standby() {
  //KANAN DEPAN (FR)
  xFR0 = -65,  yFR0 = 65, xFR1 = -65, yFR1 = 65, zFR0 = 0, zFRp = 0;
  //KIRI TENGAH (LM)
  xLM0 = 80, yLM0 = 0, xLM1 = 80, yLM1 = 0, zLM0 = 0, zLMp = 0;
  //KANAN BELAKANG (BR)
  xBR0 = -65, yBR0 = -65, xBR1 = -65,  yBR1 = -65, zBR0 = 0, zBRp = 0;
  //KIRI DEPAN (FL)
  xFL0 = 65, yFL0 = 65, xFL1 = 65,  yFL1 = 65, zFL0 = 0, zFLp = 0;
  //KANAN TENGAH (RM)
  xRM0 = -80, yRM0 = 0, xRM1 = -80, yRM1 = 0, zRM0 = 0, zRMp = 0;
  //KIRI BELAKANG (BL)
  xBL0 = 65, yBL0 = -65, xBL1 = 65,  yBL1 = -65, zBL0 = 0, zBLp = 0;
}
