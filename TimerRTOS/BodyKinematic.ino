void BodyMaju(int speeds) {//gerakan saat ambil korban
  if (!statusGerak) {
    Capit = true;
    Increment = 180 / speeds;
    Inc = 180 / speeds;
    switch (stepss) {
      case 0: //Body & Capit Maju
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //KANAN DEPAN (FR)
        xFR0 = -55,  yFR0 = 105, xFR1 = -55, yFR1 = 10, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = -45, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55,  yBR1 = -86, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55,  yFL1 = 10, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = -45, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55,  yBL1 = -86, zBLp = 0;
        sdtServoAwal = 59, sdtServoAkhir = 59;//??
        sdtDynAwal = 120, sdtDynAkhir = 120;//??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        //KANAN DEPAN (FR)
        xFR0 = -55,  yFR0 = 10, xFR1 = -55, yFR1 = 10, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = -45, xLM1 = 76, yLM1 = -45, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -86, xBR1 = -55,  yBR1 = -86, zBRp = 0; //BR MAKS 105
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 10, xFL1 = 55,  yFL1 = 10, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = -45, xRM1 = -76, yRM1 = -45, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -86, xBL1 = 55,  yBL1 = -86, zBLp = 0;
        sdtServoAwal = 59, sdtServoAkhir = 59;//??
        sdtDynAwal = 120, sdtDynAkhir = 120;//??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss ++;
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
      case 0: //Capit Korban
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        capit1.write(179);
        capit2.write(1);
        //KANAN DEPAN (FR)
        xFR0 = xFR,  yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR,  yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL,  yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL,  yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 59, sdtServoAkhir = 59;
        sdtDynAwal = 120, sdtDynAkhir = 120;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 1: //Pegangan Naik
        //KANAN DEPAN (FR)
        xFR0 = xFR,  yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR,  yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL,  yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL,  yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 59, sdtServoAkhir = 120;
        sdtDynAwal = 120, sdtDynAkhir = 120;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 2: //Naikkan Capit
        //KANAN DEPAN (FR)
        xFR0 = xFR,  yFR0 = yFR, xFR1 = xFR, yFR1 = yFR, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = xLM, yLM1 = yLM, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = xBR,  yBR1 = yBR, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = xFL,  yFL1 = yFL, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = xRM, yRM1 = yRM, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = xBL,  yBL1 = yBL, zBLp = 0;
        sdtServoAwal = 120, sdtServoAkhir = 82;
        sdtDynAwal = 120, sdtDynAkhir = 240;
        modeGerak = true;
        statusGerak = true;
        moveDyn = true;
        movePeg = true;
        break;
      case 3: //Body Balik
        //KANAN DEPAN (FR)
        xFR0 = xFR,  yFR0 = yFR, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM, yLM0 = yLM, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = xBR, yBR0 = yBR, xBR1 = -55,  yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL, yFL0 = yFL, xFL1 = 55,  yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = xRM, yRM0 = yRM, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xBL, yBL0 = yBL, xBL1 = 55,  yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;//??
        sdtDynAwal = 240, sdtDynAkhir = 240;//??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 4:
        //KANAN DEPAN (FR)
        xFR0 = -55,  yFR0 = 55, xFR1 = -55, yFR1 = 55, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55,  yBR1 = -55, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55,  yFL1 = 55, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55,  yBL1 = -55, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;//??
        sdtDynAwal = 240, sdtDynAkhir = 240;//??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss ++;
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
      case 0: //Body Mundur
        theta = 0;
        degAwal = 0;
        degAkhir = 180;
        //KANAN DEPAN (FR)
        xFR0 = -55,  yFR0 = 55, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 0, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -55, xBR1 = -55,  yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 55, xFL1 = 55,  yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 0, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -55, xBL1 = 55,  yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 82;//??
        sdtDynAwal = 240, sdtDynAkhir = 240;//??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1: //Turun Capit
        //KANAN DEPAN (FR)
        xFR0 = -55,  yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55,  yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55,  yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55,  yBL1 = -5, zBLp = 0;
        sdtServoAwal = 82, sdtServoAkhir = 59;//??
        sdtDynAwal = 240, sdtDynAkhir = 120;//??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2:
        //KANAN DEPAN (FR)
        xFR0 = -55,  yFR0 = 105, xFR1 = -55, yFR1 = 105, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = 76, yLM0 = 50, xLM1 = 76, yLM1 = 50, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -55, yBR0 = -5, xBR1 = -55,  yBR1 = -5, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = 55, yFL0 = 105, xFL1 = 55,  yFL1 = 105, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -76, yRM0 = 50, xRM1 = -76, yRM1 = 50, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = 55, yBL0 = -5, xBL1 = 55,  yBL1 = -5, zBLp = 0;
        sdtServoAwal = 59, sdtServoAkhir = 59;//??
        sdtDynAwal = 120, sdtDynAkhir = 120;//??
        moveDyn = true;
        movePeg = true;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    stepss ++;
    if (stepss > 3) {
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

void YawKanan(int speeds) {
  //  if (!statusGerak) {
  theta = 0;
  Increment = 180 / speeds;
  degAwal = 0;
  degAkhir = 180;
  //KANAN DEPAN (FR)
  xFR0 = -55,  yFR0 = 55, xFR1 = -100.4, yFR1 = 19.2, zFRp = 0;
  //KIRI TENGAH (LM)
  xLM0 = 75, yLM0 = 0, xLM1 = 70, yLM1 = 40, zLMp = 0;
  //KANAN BELAKANG (BR)
  xBR0 = -55, yBR0 = -55, xBR1 = -1.4,  yBR1 = -75.2, zBRp = 0;
  //KIRI DEPAN (FL)
  xFL0 = 55, yFL0 = 55, xFL1 = 1.4,  yFL1 = 75.2, zFLp = 0;
  //KANAN TENGAH (RM)
  xRM0 = -75, yRM0 = 0, xRM1 = -70, yRM1 = -40, zRMp = 0;
  //KIRI BELAKANG (BL)
  xBL0 = 55, yBL0 = -55, xBL1 = 100.4,  yBL1 = -19.2, zBLp = 0;
  modeGerak = true;
  statusGerak = true;
  //}
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
//1. Rotate hingga korban berada di tengah
//1. Body Mundur(Awal dan Tujuan Fix)
//3. Turunkan Capit
//4. Body Maju ambil korban (Awal = Posisi x,y terakhir sebelum break rotasi Yaw, Tujuan = Awal + Maju Maksimal) hingga jarak sesuai (langsung break)
