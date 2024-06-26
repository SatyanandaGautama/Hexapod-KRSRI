void BodyMaju(int speeds) {  //gerakan saat ambil korban
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body & Capit Maju
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 10, zFRp = 0;  //Coba ganti 5 atau 0
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = -45, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -86, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 10, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = -45, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -86, zBLp = 0;
        sdtServoAwal = 22, sdtServoAkhir = 22;  //??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        Increment = 180 / 3;
        Inc = 180 / 3;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 10, xFR1 = -55, yFR1 = 10, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = -45, xLM1 = 76, yLM1 = -45, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -86, xBR1 = -55, yBR1 = -86, zBRp = 0;  //BR MAKS 105
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 10, xFL1 = 55, yFL1 = 10, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = -45, xRM1 = -76, yRM1 = -45, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -86, xBL1 = 55, yBL1 = -86, zBLp = 0;
        sdtServoAwal = 22, sdtServoAkhir = 22;  //??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 2) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyBalik(int speeds) {
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:
        Increment = 180 / 10;
        Inc = 180 / 10;
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //        capit1.write(170);  // 167 tutup 135 buka
        capit2.write(8);  // 8 tutup 40 buka
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 22, sdtServoAkhir = 22;
        sdtDynAwal = 132, sdtDynAkhir = 132;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 1:  //Pegangan Naik
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 22, sdtServoAkhir = 120;
        sdtDynAwal = 132, sdtDynAkhir = 132;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 2:  //Naikkan Capit
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 120, sdtServoAkhir = 82;
        sdtDynAwal = 132, sdtDynAkhir = 240;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 3:  //Body Balik
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = -55, yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = 55, yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = 55, yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 4:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 5) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyMundur(int speeds) {
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body Mundur
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        capit2.write(45);
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:  //Turun Capit
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 22;  //59
        sdtDynAwal = 240, sdtDynAkhir = 132;    //120
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 22, sdtServoAkhir = 22;  //12??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //140??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 3) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyMaju_K2(int speeds) {  //gerakan saat ambil korban
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body & Capit Maju
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 0, zFRp = 0;  //10
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = -55, zLMp = 0;  //45
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -86, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = -55, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -86, zBLp = 0;
        sdtServoAwal = 23, sdtServoAkhir = 23;  //24
        sdtDynAwal = 133, sdtDynAkhir = 133;    //135
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        Increment = 180 / 3;
        Inc = 180 / 3;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 0, xFR1 = -55, yFR1 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = -55, xLM1 = 76, yLM1 = -55, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -86, xBR1 = -55, yBR1 = -86, zBRp = 0;  //BR MAKS 105
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 0, xFL1 = 55, yFL1 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = -55, xRM1 = -76, yRM1 = -55, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -86, xBL1 = 55, yBL1 = -86, zBLp = 0;
        sdtServoAwal = 23, sdtServoAkhir = 23;  //??
        sdtDynAwal = 133, sdtDynAkhir = 133;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 2) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyBalik_K2(int speeds) {
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:
        Increment = 180 / 10;
        Inc = 180 / 10;
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //        capit1.write(170);  // 167 tutup 135 buka
        capit2.write(8);  // 8 tutup 40 buka
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 23, sdtServoAkhir = 23;
        sdtDynAwal = 133, sdtDynAkhir = 133;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 1:  //Pegangan Naik
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 23, sdtServoAkhir = 120;
        sdtDynAwal = 133, sdtDynAkhir = 133;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 2:  //Naikkan Capit
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 120, sdtServoAkhir = 82;
        sdtDynAwal = 133, sdtDynAkhir = 240;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 3:  //Body Balik
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = -55, yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = 55, yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = 55, yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 4:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 5) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyMundur_K2(int sdtCapit, int speeds) {
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body Mundur
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        capit2.write(sdtCapit);
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:  //Turun Capit
        Increment = 180 / 34;
        Inc = 180 / 34;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 24;  //??
        sdtDynAwal = 240, sdtDynAkhir = 135;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 23, sdtServoAkhir = 23;  //10??
        sdtDynAwal = 133, sdtDynAkhir = 133;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 3) {
      Capit = false;
      stepss = 0;
    }
  }
}

void TurunCapit(int sdtCapit, int speeds) {
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body Mundur
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        capit2.write(sdtCapit);
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:  //Turun Capit
        Increment = 180 / 34;
        Inc = 180 / 34;
        sdtServoAwal = 82, sdtServoAkhir = 24;  //??
        sdtDynAwal = 240, sdtDynAkhir = 135;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2:
        Increment = 180 / 2;
        Inc = 180 / 2;
        sdtServoAwal = 23, sdtServoAkhir = 23;  //10??
        sdtDynAwal = 133, sdtDynAkhir = 133;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 3) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyMaju_K5(int speeds) {  //gerakan saat ambil korban
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body & Capit Maju
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 0, zFRp = 0;  //10
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = -55, zLMp = 0;  //45
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -86, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = -55, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -86, zBLp = 0;
        sdtServoAwal = 17, sdtServoAkhir = 17;  //??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 0, xFR1 = -55, yFR1 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = -55, xLM1 = 76, yLM1 = -55, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -86, xBR1 = -55, yBR1 = -86, zBRp = 0;  //BR MAKS 105
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 0, xFL1 = 55, yFL1 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = -55, xRM1 = -76, yRM1 = -55, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -86, xBL1 = 55, yBL1 = -86, zBLp = 0;
        sdtServoAwal = 17, sdtServoAkhir = 17;  //??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 2) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyBalik_K5(int speeds) {
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:
        Increment = 180 / 10;
        Inc = 180 / 10;
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //        capit1.write(170);  // 167 tutup 135 buka
        capit2.write(8);  // 8 tutup 40 buka
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 17, sdtServoAkhir = 17;
        sdtDynAwal = 132, sdtDynAkhir = 132;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 1:  //Pegangan Naik
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 17, sdtServoAkhir = 120;
        sdtDynAwal = 132, sdtDynAkhir = 132;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 2:  //Naikkan Capit
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR, yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL, yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL, yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 120, sdtServoAkhir = 82;
        sdtDynAwal = 132, sdtDynAkhir = 240;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 3:  //Body Balik
        //KANAN DEPAN (FR)
        xFR0 = xFR, yFR0 = yFR, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = -55, yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = 55, yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = 55, yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 4:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 5) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyMundur_K5(int speeds) {
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body Mundur
        capit2.write(52);
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:  //Turun Capit
        Increment = 180 / 34;
        Inc = 180 / 34;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 17;  //59
        sdtDynAwal = 240, sdtDynAkhir = 132;    //120
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 17, sdtServoAkhir = 17;  //12??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //140??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 3) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyMundur_K5Coba(int speeds) {
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body Mundur
        capit2.write(52);
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;  //??
        sdtDynAwal = 240, sdtDynAkhir = 240;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:  //Turun Capit
        Increment = 180 / 28;
        Inc = 180 / 28;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 17;  //59
        sdtDynAwal = 240, sdtDynAkhir = 132;    //120
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55, yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55, yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55, yBL1 = -5, zBLp = 0;
        sdtServoAwal = 17, sdtServoAkhir = 17;  //12??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //140??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 3) {
      Capit = false;
      stepss = 0;
    }
  }
}

void BodyMaju_K5Coba(int speeds) {  //gerakan saat ambil korban
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0:  //Body & Capit Maju
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 0, zFRp = 0;  //10
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = -55, zLMp = 0;  //45
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -86, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = -55, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -86, zBLp = 0;
        sdtServoAwal = 17, sdtServoAkhir = 17;  //??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        Increment = 180 / 2;
        Inc = 180 / 2;
        //KANAN DEPAN (FR)
        xFR0 = -55, yFR0 = 0, xFR1 = -55, yFR1 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = -55, xLM1 = 76, yLM1 = -55, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -86, xBR1 = -55, yBR1 = -86, zBRp = 0;  //BR MAKS 105
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 0, xFL1 = 55, yFL1 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = -55, xRM1 = -76, yRM1 = -55, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -86, xBL1 = 55, yBL1 = -86, zBLp = 0;
        sdtServoAwal = 17, sdtServoAkhir = 17;  //??
        sdtDynAwal = 132, sdtDynAkhir = 132;    //??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss++;
    if (stepss > 2) {
      Capit = false;
      stepss = 0;
    }
  }
}


//Test gerak body mundur + turun capit:
//if (modeGerak) {
//  while (1) {
//    xSemaphoreTake(mutex, portMAX_DELAY);
//    BodyMundur(30);
//    if (Capit == false) {
//      statusGerak = false;
//      modeGerak = false;
//      break;
//    }
//    xSemaphoreGive(mutex);
//  }
//}



//Gerakan pengambilan korban :
//1. Rotate hingga korban berada di tengah
//1. Body Mundur(Awal dan Tujuan Fix)
//3. Turunkan Capit
//4. Body Maju ambil korban (Awal = Posisi x,y terakhir sebelum break rotasi Yaw, Tujuan = Awal + Maju Maksimal) hingga jarak sesuai (langsung break)
