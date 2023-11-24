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
    modeGerak == false;
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
  }
  else if (theta > degAkhir) {
    theta = degAwal; //Untuk Increment Tujuan Selanjutnya
    statusGerak = false;
  }
}


void TrayektoriBezier() { //Cubic Bezier Curve
  float zFR1 = (zFRp - 0.25 * zFR0) / 0.75;
  float zBL1 = (zBLp - 0.25 * zBL0) / 0.75;
  float zFL1 = (zFLp - 0.25 * zFL0) / 0.75;
  float zBR1 = (zBRp - 0.25 * zBR0) / 0.75;
  float zLM1 = (zLMp - 0.25 * zLM0) / 0.75;
  float zRM1 =  (zRMp - 0.25 * zRM0) / 0.75;
  float a, b, c, d;
  float xFR, yFR, zFR, xFL, yFL, zFL, xBR, yBR, zBR, xBL, yBL, zBL, xRM, yRM, zRM, xLM, yLM, zLM;
  if (t <= tAkhir) {
    a = (1 - t) * (1 - t) * (1 - t);
    b = 3 * t * (1 - t) * (1 - t);
    c = 3 * t * t * (1 - t);
    d = t * t * t;
    /////////// KANAN ATAS (RM)////////////////////
    xFR = a * xFR0 + b * xFR0 + c * xFR1 + d * xFR1;
    yFR = a * yFR0 + b * yFR0 + c * yFR1 + d * yFR1;
    zFR = a * zFR0 + b * zFR1 + c * zFR1 + d * zFR0;
    /////////// KIRI TENGAH (LM)////////////////////
    xLM = a * xLM0 + b * xLM0 + c * xLM1 + d * xLM1;
    yLM = a * yLM0 + b * yLM0 + c * yLM1 + d * yLM1;
    zLM = a * zLM0 + b * zLM1 + c * zLM1 + d * zLM0;
    /////////// KANAN BELAKANG (BR)////////////////
    xBR = a * xBR0 + b * xBR0 + c * xBR1 + d * xBR1;
    yBR = a * yBR0 + b * yBR0 + c * yBR1 + d * yBR1;
    zBR = a * zBR0 + b * zBR1 + c * zBR1 + d * zBR0;
    /////////// KIRI DEPAN (FL)////////////////
    xFL = a * xFL0 + b * xFL0 + c * xFL1 + d * xFL1;
    yFL = a * yFL0 + b * yFL0 + c * yFL1 + d * yFL1;
    zFL = a * zFL0 + b * zFL1 + c * zFL1 + d * zFL0;
    /////////// KANAN TENGAH (RM)////////////////////
    xRM = a * xRM0 + b * xRM0 + c * xRM1 + d * xRM1;
    yRM = a * yRM0 + b * yRM0 + c * yRM1 + d * yRM1;
    zRM = a * zRM0 + b * zRM1 + c * zRM1 + d * zRM0;
    /////////// KIRI BELAKANG (BL)////////////////
    xBL = a * xBL0 + b * xBL0 + c * xBL1 + d * xBL1;
    yBL = a * yBL0 + b * yBL0 + c * yBL1 + d * yBL1;
    zBL = a * zBL0 + b * zBL1 + c * zBL1 + d * zBL0;
    //////////////////////////////////////////////
    FR(xFR, yFR, zFR);
    RM(xRM, yRM, zRM);
    BR(xBR, yBR, zBR);
    BL(xBL, yBL, zBL);
    LM(xLM, yLM, zLM);
    FL(xFL, yFL, zFL);
    t += Increment;
  }
  else if (t > tAkhir) {
    t = tAwal; //Untuk Increment Tujuan Selanjutnya
    statusGerak = false;
  }
}
