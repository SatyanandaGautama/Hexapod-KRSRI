void Rotate(float rot) {
  rot = rot / 180 * M_PI;
  float rotasi[3][3] = { { cos(rot), -sin(rot), 0 },
    { sin(rot), cos(rot), 0 },
    { 0, 0, 1 }
  };
  float P1[3][1] = { 0 };
  float P2[3][1] = { 0 };
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
      xFL_Awal = round((P1[0][0]));  //FL
      yFL_Awal = round((P1[1][0]));  //FL
      xLM_Awal = round((P2[0][0]));  //LM
      yLM_Awal = round((P2[1][0]));  //LM
    }
    if (rot < 0) {
      xFL_Akhir = round((P1[0][0]));  //FL
      yFL_Akhir = round((P1[1][0]));  //FL
      xLM_Akhir = round((P2[0][0]));  //LM
      yLM_Akhir = round((P2[1][0]));  //LM
    }
  }
  if (arahPutar > 0) {
    if (rot < 0) {
      xFL_Awal = round((P1[0][0]));  //FL
      yFL_Awal = round((P1[1][0]));  //FL
      xLM_Awal = round((P2[0][0]));  //LM
      yLM_Awal = round((P2[1][0]));  //LM
    }
    if (rot >= 0) {
      xFL_Akhir = round((P1[0][0]));  //FL
      yFL_Akhir = round((P1[1][0]));  //FL
      xLM_Akhir = round((P2[0][0]));  //LM
      yLM_Akhir = round((P2[1][0]));  //LM
    }
  }
}

void GerakRotasi(float degree, float tinggi, float speeds) {  //Sudut + (putar kanan), sudut - (putar kiri)
  if (degree > 30) degree = 30;
  if (degree < -30) degree = -30;
  arahPutar = degree;
  Increment = 180 / speeds;
  if (!statusGerak) {
    switch (steps) {
      case 0:
        degAwal = 0 + Increment;
        degAkhir = 180;
        Rotate(degree / 2);
        Rotate(-1 * (degree / 2));
        //KANAN DEPAN (FR)
        xFR0 = -(xFL_Akhir), yFR0 = yFL_Akhir, xFR1 = -(xFL_Awal), yFR1 = yFL_Awal, zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Awal, yLM0 = yLM_Awal, xLM1 = xLM_Akhir, yLM1 = yLM_Akhir, zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = -(xFL_Awal), yBR0 = -(yFL_Awal), xBR1 = -(xFL_Akhir), yBR1 = -(yFL_Akhir), zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Akhir, yFL0 = yFL_Akhir, xFL1 = xFL_Awal, yFL1 = yFL_Awal, zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -(xLM_Awal), yRM0 = yLM_Awal, xRM1 = -(xLM_Akhir), yRM1 = yLM_Akhir, zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xFL_Awal, yBL0 = -(yFL_Awal), xBL1 = xFL_Akhir, yBL1 = -(yFL_Akhir), zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        degAwal = 90 + Increment;
        degAkhir = 90;
        //        Rotate(degree / 2);
        //        Rotate(-1 * (degree / 2));
        //KANAN DEPAN (FR)
        xFR0 = -(xFL_Awal), yFR0 = yFL_Awal, xFR1 = -(xFL_Akhir), yFR1 = yFL_Akhir, zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Akhir, yLM0 = yLM_Akhir, xLM1 = xLM_Awal, yLM1 = yLM_Awal, zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -(xFL_Akhir), yBR0 = -(yFL_Akhir), xBR1 = -(xFL_Awal), yBR1 = -(yFL_Awal), zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Awal, yFL0 = yFL_Awal, xFL1 = xFL_Akhir, yFL1 = yFL_Akhir, zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = -(xLM_Akhir), yRM0 = yLM_Akhir, xRM1 = -(xLM_Awal), yRM1 = yLM_Awal, zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = xFL_Akhir, yBL0 = -(yFL_Akhir), xBL1 = xFL_Awal, yBL1 = -(yFL_Awal), zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2:
        degAwal = 0 + Increment;
        degAkhir = 180;
        Rotate(degree / 2);
        Rotate(-1 * (degree / 2));
        //KANAN DEPAN (FR)
        xFR0 = -(xFL_Awal), yFR0 = yFL_Awal, xFR1 = -(xFL_Akhir), yFR1 = yFL_Akhir, zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Akhir, yLM0 = yLM_Akhir, xLM1 = xLM_Awal, yLM1 = yLM_Awal, zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = -(xFL_Akhir), yBR0 = -(yFL_Akhir), xBR1 = -(xFL_Awal), yBR1 = -(yFL_Awal), zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Awal, yFL0 = yFL_Awal, xFL1 = xFL_Akhir, yFL1 = yFL_Akhir, zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = -(xLM_Akhir), yRM0 = yLM_Akhir, xRM1 = -(xLM_Awal), yRM1 = yLM_Awal, zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = xFL_Akhir, yBL0 = -(yFL_Akhir), xBL1 = xFL_Awal, yBL1 = -(yFL_Awal), zBL0 = 0, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 3:
        degAwal = 90 + Increment;
        degAkhir = 90;
        //        Rotate(degree / 2);
        //        Rotate(-1 * (degree / 2));
        //KANAN DEPAN (FR)
        xFR0 = -(xFL_Akhir), yFR0 = yFL_Akhir, xFR1 = -(xFL_Awal), yFR1 = yFL_Awal, zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = xLM_Awal, yLM0 = yLM_Awal, xLM1 = xLM_Akhir, yLM1 = yLM_Akhir, zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = -(xFL_Awal), yBR0 = -(yFL_Awal), xBR1 = -(xFL_Akhir), yBR1 = -(yFL_Akhir), zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = xFL_Akhir, yFL0 = yFL_Akhir, xFL1 = xFL_Awal, yFL1 = yFL_Awal, zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = -(xLM_Awal), yRM0 = yLM_Awal, xRM1 = -(xLM_Akhir), yRM1 = yLM_Akhir, zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = xFL_Awal, yBL0 = -(yFL_Awal), xBL1 = xFL_Akhir, yBL1 = -(yFL_Akhir), zBL0 = 0, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    steps++;
    if (steps > 3) steps = 0;
  }
}

void Standby() {
  steps = 0;
  theta = 0;
  degAkhir = 0;
  //KANAN DEPAN (FR)
  xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 55, zFRp = 0;
  //KIRI TENGAH (LM)
  xLM0 = 75, yLM0 = 0, xLM1 = 75, yLM1 = 0, zLMp = 0;
  //KANAN BELAKANG (BR)
  xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -55, zBRp = 0;
  //KIRI DEPAN (FL)
  xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 55, zFLp = 0;
  //KANAN TENGAH (RM)
  xRM0 = -75, yRM0 = 0, xRM1 = -75, yRM1 = 0, zRMp = 0;
  //KIRI BELAKANG (BL)
  xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -55, zBLp = 0;
  modeGerak = true;
  statusGerak = false;
}

void StandbyTangga() {
  steps = 0;
  theta = 0;  degAkhir = 0;
  degAwal = 0;
  Increment = 10;
  //KANAN DEPAN (FR)
  xFR0 = -55, yFR0 = 55, xFR1 = -55, yFR1 = 55, zFRp = 0;
  //KIRI TENGAH (LM)
  xLM0 = 75, yLM0 = 0, xLM1 = 75, yLM1 = 0, zLMp = 0;
  //KANAN BELAKANG (BR)
  xBR0 = -55, yBR0 = -55, xBR1 = -55, yBR1 = -55, zBRp = 0;
  //KIRI DEPAN (FL)
  xFL0 = 55, yFL0 = 55, xFL1 = 55, yFL1 = 55, zFLp = 0;
  //KANAN TENGAH (RM)
  xRM0 = -75, yRM0 = 0, xRM1 = -75, yRM1 = 0, zRMp = 0;
  //KIRI BELAKANG (BL)
  xBL0 = 55, yBL0 = -55, xBL1 = 55, yBL1 = -55, zBLp = 0;
  modeGerak = true;
  statusGerak = true;
}

void StandbyAwal() {
  FR(-55, 55, 20);
  RM(-75, 0, 20);
  BR(-55, -55, 20);
  BL(55, -55, 20);
  LM(75, 0, 20);
  FL(55, 55, 20);
  KirimIntruksiGerak(512);
  delay(500);
  FR(-55, 55, 0);
  RM(-75, 0, 0);
  BR(-55, -55, 0);
  BL(55, -55, 0);
  LM(75, 0, 0);
  FL(55, 55, 0);
  KirimIntruksiGerak(512);
}

void naikTangga() {
  read_MPU();
  vTaskDelay(15 / portTICK_PERIOD_MS);
  offsetCX[2] = 24; //Coxa BL //25
  offsetCX[3] = -24; //Coxa FL //-22
  rightFM = 39; //Femur FR & BR //40
  rightTB = 34; //Tibia FR & BR 36
  rightFM_FR = 36;
  leftFM_FL = 20;
  leftFM = 18; //Femur FL & BL //12 Naik(+) //15 //18
  leftTB = 16; //Tibia FL & BL //9 Masuk(+) //13 //16
  midRightFM = 48; //Femur RM //50
  midRightTB = 58; //Tibia RM
  midLeftFM = 18; //Femur LM //14 //16 //18 good (Makin besar makin naik)
  midLeftTB = -9; //Tibia LM //11 (Makin kecil makin masuk)
}

//  //  read_MPU();
//  //  vTaskDelay(15 / portTICK_PERIOD_MS);
//  offsetCX[2] = 24; //Coxa BL //25
//  offsetCX[3] = -20; //Coxa FL //-22
//  rightFM = 39; //Femur FR & BR //40
//  rightTB = 36; //Tibia BR 36
//  //  rightFM_FR = 40;
//  //  rightTB_FR = 40; //Tibia FR
//  leftFM = 19; //Femur FL & BL //12 Naik(+) //15 //18
//  leftTB = 15; //Tibia FL & BL //9 Masuk(+) //13 //16
//  midRightFM = 49; //Femur RM //50
//  midRightTB = 58; //Tibia RM
//  midLeftFM = 18; //Femur LM //14 //16 //18 good (Makin besar makin naik)
//  midLeftTB = -9; //Tibia LM //11 (Makin kecil makin masuk)
