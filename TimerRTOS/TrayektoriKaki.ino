void TrayektoriSinus() {
  if (modeGerak == true) {
    actual_xFR = ((xFR1 - xFR0) / 10) * 2;
    actual_yFR = ((yFR1 - yFR0) / 10) * 2;
    actual_xLM = ((xLM1 - xLM0) / 10) * 2;
    actual_yLM = ((yLM1 - yLM0) / 10) * 2;
    actual_xBR = ((xBR1 - xBR0) / 10) * 2;
    actual_yBR = ((yBR1 - yBR0) / 10) * 2;
    actual_xFL = ((xFL1 - xFL0) / 10) * 2;
    actual_yFL = ((yFL1 - yFL0) / 10) * 2;
    actual_xRM = ((xRM1 - xRM0) / 10) * 2;
    actual_yRM = ((yRM1 - yRM0) / 10) * 2;
    actual_xBL = ((xBL1 - xBL0) / 10) * 2;
    actual_yBL = ((yBL1 - yBL0) / 10) * 2;
    modeGerak = false;
  }
  if (theta <= degAkhir) {
    //KANAN ATAS
    xFR = xFR0 + (((actual_xFR * theta) / 360)) * 10;
    yFR = yFR0 + (((actual_yFR * theta) / 360)) * 10;
    zFR = zFRp * sin(theta * (M_PI / 180));
    //KIRI TENGAH
    xLM = xLM0 + (((actual_xLM * theta) / 360)) * 10;
    yLM = yLM0 + (((actual_yLM * theta) / 360)) * 10;
    zLM = zLMp * sin(theta * (M_PI / 180));
    //KANAN BAWAH
    xBR = xBR0 + (((actual_xBR * theta) / 360)) * 10;
    yBR = yBR0 + (((actual_yBR * theta) / 360)) * 10;
    zBR = zBRp * sin(theta * (M_PI / 180));
    //KIRI ATAS
    xFL = xFL0 + (((actual_xFL * theta) / 360)) * 10;
    yFL = yFL0 + (((actual_yFL * theta) / 360)) * 10;
    zFL = zFLp * sin(theta * (M_PI / 180));
    //KANAN TENGAH
    xRM = xRM0 + (((actual_xRM * theta) / 360)) * 10;
    yRM = yRM0 + (((actual_yRM * theta) / 360)) * 10;
    zRM = zRMp * sin(theta * (M_PI / 180));
    //KIRI BAWAH
    xBL = xBL0 + (((actual_xBL * theta) / 360)) * 10;
    yBL = yBL0 + (((actual_yBL * theta) / 360)) * 10;
    zBL = zBLp * sin(theta * (M_PI / 180));
    FR(xFR, yFR, zFR);
    RM(xRM, yRM, zRM);
    BR(xBR, yBR, zBR);
    BL(xBL, yBL, zBL);
    LM(xLM, yLM, zLM);
    FL(xFL, yFL, zFL);
    theta += Increment;
    if (theta > degAkhir) {
      theta = degAwal; //Untuk Increment Tujuan Selanjutnya
      statusGerak = false;
    }
  }
  //  Serial.print("x:");
  //  Serial.println(xLM);
  //  Serial.print("y:");
  //  Serial.println(yRM);
  //  Serial.print("z:");
  //  Serial.println(zRM);
}

//void TrayektoriLinier() {
//  actual_xFR = ((xFR1 - xFR0) / 10) * 2;
//  actual_yFR = ((yFR1 - yFR0) / 10) * 2;
//  actual_xLM = ((xLM1 - xLM0) / 10) * 2;
//  actual_yLM = ((yLM1 - yLM0) / 10) * 2;
//  actual_xBR = ((xBR1 - xBR0) / 10) * 2;
//  actual_yBR = ((yBR1 - yBR0) / 10) * 2;
//  actual_xFL = ((xFL1 - xFL0) / 10) * 2;
//  actual_yFL = ((yFL1 - yFL0) / 10) * 2;
//  actual_xRM = ((xRM1 - xRM0) / 10) * 2;
//  actual_yRM = ((yRM1 - yRM0) / 10) * 2;
//  actual_xBL = ((xBL1 - xBL0) / 10) * 2;
//  actual_yBL = ((yBL1 - yBL0) / 10) * 2;
//  actual_zFR = ((zFRp - zFR0) / 10) * 2;
//  actual_zRM = ((zRMp - zRM0) / 10) * 2;
//  actual_zBR = ((zBRp - zBR0) / 10) * 2;
//  actual_zFL = ((zFLp - zFL0) / 10) * 2;
//  actual_zLM = ((zLMp - zLM0) / 10) * 2;
//  actual_zBL = ((zBLp - zBL0) / 10) * 2;
//  if (theta <= degAkhir) {
//    //KANAN ATAS
//    xFR = xFR0 + (((actual_xFR * theta) / 360)) * 10;
//    yFR = yFR0 + (((actual_yFR * theta) / 360)) * 10;
//    zFR = zFR0 + (((actual_zFR * theta) / 360)) * 10;
//    //KIRI TENGAH
//    xLM = xLM0 + (((actual_xLM * theta) / 360)) * 10;
//    yLM = yLM0 + (((actual_yLM * theta) / 360)) * 10;
//    zLM = zLM0 + (((actual_zLM * theta) / 360)) * 10;
//    //KANAN BAWAH
//    xBR = xBR0 + (((actual_xBR * theta) / 360)) * 10;
//    yBR = yBR0 + (((actual_yBR * theta) / 360)) * 10;
//    zBR = zBR0 + (((actual_zBR * theta) / 360)) * 10;
//    //KIRI ATAS
//    xFL = xFL0 + (((actual_xFL * theta) / 360)) * 10;
//    yFL = yFL0 + (((actual_yFL * theta) / 360)) * 10;
//    zFL = zFL0 + (((actual_zFL * theta) / 360)) * 10;
//    //KANAN TENGAH
//    xRM = xRM0 + (((actual_xRM * theta) / 360)) * 10;
//    yRM = yRM0 + (((actual_yRM * theta) / 360)) * 10;
//    zRM = zRM0 + (((actual_zRM * theta) / 360)) * 10;
//    //KIRI BAWAH
//    xBL = xBL0 + (((actual_xBL * theta) / 360)) * 10;
//    yBL = yBL0 + (((actual_yBL * theta) / 360)) * 10;
//    zBL = zBL0 + (((actual_zBL * theta) / 360)) * 10;
//    FR(xFR, yFR, zFR);
//    RM(xRM, yRM, zRM);
//    BR(xBR, yBR, zBR);
//    BL(xBL, yBL, zBL);
//    LM(xLM, yLM, zLM);
//    FL(xFL, yFL, zFL);
//    theta += Increment;
//    if (theta > degAkhir) {
//      statusGerak = false;
//    }
//  }
//}
