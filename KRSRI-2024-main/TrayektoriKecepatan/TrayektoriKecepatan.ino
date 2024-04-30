#include <HardwareTimer.h>
HardwareSerial Serial2(USART2);
HardwareTimer Timer6(TIM6);
String LEDStat = "OFF";
// Timer period (in microseconds) for 20 ms
const uint32_t timerPeriod_us = 20000 - 1;
const int prescaler = 84 - 1; // 1 MHz
// Input Trayektori Global
//KANAN DEPAN (FR)
volatile float xFR0, yFR0, xFR1, yFR1, zFR0, zFRp;
//KIRI TENGAH (LM)
volatile float xLM0, yLM0, xLM1, yLM1, zLM0, zLMp;
//KANAN BELAKANG (BR)
volatile float xBR0, yBR0, xBR1,  yBR1, zBR0, zBRp;
//KIRI DEPAN (FL)
volatile float xFL0, yFL0, xFL1,  yFL1, zFL0, zFLp;
//KANAN TENGAH (RM)
volatile float xRM0, yRM0, xRM1, yRM1, zRM0, zRMp;
//KIRI BELAKANG (BL)
volatile float xBL0, yBL0, xBL1,  yBL1, zBL0, zBLp;
volatile float Increment;
volatile float t = 0.5;
volatile bool statusGerak = false;
// Variabel simpan sudut tiap servo
volatile int outServo[6][3];
//Variabel Invers Kinematik
int jumlahLangkah = 0;
float cx = 22;
int fm = 58;
int tb = 80;
int height = -95;
float z, sdtcoxa, sdtcoxa1, sdtcoxa2, sdtcoxa3, sdtcoxa4, sdtrotate, sdtfemur, sdttibia, theta2, theta3, angle1, angle2, P, c, alas, alpha, beta;
int legoffset[6] = {0, 45, 135, 180, 225, 315};
volatile bool state = true;
volatile bool cekT = false;
//Koordinat Awal (Standby) per Kaki :
float standFR[3][1] = {{ -60}, {60}, {0}};
float standRM[3][1] = {{ -85}, {0}, {0}};
float standBR[3][1] = {{ -60}, { -60}, {0}};
float standFL[3][1] = {{ 60}, {60}, {0}};
float standLM[3][1] = {{ 85}, {0}, {0}};
float standBL[3][1] = {{ 60}, { -60}, {0}};

void setup() {
  pinMode(PA1, OUTPUT);
  Serial.setTx(PA9);
  Serial.setRx(PA10);
  Serial2.setTx(PA2);
  Serial2.setRx(PA3);
  Serial.begin(9600);
  Serial2.begin(1000000);
  delay(2000) ;
  Timer6.pause(); //Stop the Timer
  Timer6.setPrescaleFactor(prescaler); // Set the prescaler to achieve 1us per tick (assuming 84MHz clock)
  Timer6.setOverflow(timerPeriod_us, MICROSEC_FORMAT);
  Timer6.setMode(1, TIMER_OUTPUT_COMPARE);
  Timer6.attachInterrupt(timer6Interrupt);
  Timer6.refresh(); //Reset Timer to 0
  Timer6.resume(); //Start the Timer
  //  Standby();
}

void loop() {
  //    if (cekT) {
  //      Timer6.pause();
  //      ts = t;
  //      cekT = false;
  //      Timer6.refresh();
  //      Timer6.resume();
  //      Serial.println("Standby");
  //      if (jumlahLangkah > 6 && ts >= 0.5) {
  //        Serial.println("Standby FX");
  //        while (1) {
  //          Standby();
  //        }
  //      }
  //    }
  //    else {
  //  GerakDinamis(0, 30, 30, 0.125);
  //  }
}

void timer6Interrupt() {
  //  Trayektori();
  //  KirimIntruksiGerak(0);
  ToggleLED();
}
void gerak() {
  //  steps 1 : //R=turun,L=seret
  //  simpan/hitung lebar langkah
  //  t = 0.5
  //  takhir = 1

  //  steps 2 : //R=seret,L=naik
  //  t = 0
  //  takhir = 0.5

  //  steps 3 : //R=seret,L=turun
  //  simpan/hitung lebar langkah baru
  //  t = 0.5
  //  takhir = 1

  //  steps 4 : //R=naik,L=seret
  //  t = 0
  //  takhir = 0.5
  //  Standby atau ubah mode gerak saat t=0.5
}

void rotate() {
  //  steps 1 : //R=turun,L=seret
  //  simpan/hitung lebar rotate baru
  //  Rotasi(-1*rotdeg)
  //  Rotasi(rotdeg)
  //  t = 0.5
  //  takhir = 1

  //  steps 2 : //R=seret,L=naik
  //  t = 0
  //  takhir = 0.5

  //  steps 3 : //R=seret,L=turun
  //  simpan/hitung lebar rotate baru
  //  Rotasi(-1*rotdeg)
  //  Rotasi(rotdeg)
  //  t = 0.5
  //  takhir = 1

  //  steps 4 : //R=naik,L=seret
  //  t = 0
  //  takhir = 0.5
}
void GerakRotasi(float rot, float speeds) {
  Increment = speeds;
  if (!statusGerak) {
    rot = rot / 180 * M_PI;
    Serial.print("SUDUT ROTASI dalam Rad:");
    Serial.println(rot);
    float rotasi[3][3] = {{cos(rot), -sin(rot), 0},
      {sin(rot), cos(rot), 0},
      {0, 0, 1}
    };
    float P1[3][1] = {0};
    float P2[3][1] = {0};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 1; j++) {
        for (int k = 0; k < 3; k++) {
          P1[i][j] += rotasi[i][k] * standFL[k][j];
          P2[i][j] += rotasi[i][k] * standLM[k][j];
        }
      }
    }
    float x1 = round((P1[0][0]));
    float y1 = round((P1[1][0]));
    float z1 = round((P1[2][0]));
    float x2 = round((P2[0][0]));
    float y2 = round((P2[1][0]));
    float z2 = round((P2[2][0]));
    Serial.println("TITIK TUJUAN SIDE :");
    Serial.print("X' :");
    Serial.println(x1);
    Serial.print("Y' :");
    Serial.println(y1);
    Serial.print("Z' :");
    Serial.println(z1);
    Serial.println("TITIK TUJUAN MID :");
    Serial.print("X' :");
    Serial.println(x2);
    Serial.print("Y' :");
    Serial.println(y2);
    Serial.print("Z' :");
    Serial.println(z2);
    statusGerak = true;
  }
}

void GerakDinamis(float lebarX, float lebarY, float tinggi, float speeds) { //lebarY : 30 (maju) -30 (mundur), lebarX : 30 (kanan) -30 (kiri);
  static int steps = 0;
  Increment = speeds;
  if (!statusGerak) {
    switch (steps) {
      case 0 :
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0] - lebarX,  yFR0 = standFR[1][0] + lebarY, xFR1 = standFR[0][0] + lebarX , yFR1 = standFR[1][0] - lebarY , zFR0 = 0, zFRp = tinggi;
        //KIRI TENGAH (LM)
        xLM0 = standLM[0][0] - lebarX,  yLM0 = standLM[1][0] - lebarY, xLM1 = standLM[0][0] + lebarX, yLM1 = standLM[1][0] + lebarY, zLM0 = 0, zLMp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0] - lebarX,  yBR0 = standBR[1][0] - lebarY, xBR1 = standBR[0][0] + lebarX, yBR1 = standBR[1][0] + lebarY, zBR0 = 0, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0] + lebarX,  yFL0 = standFL[1][0] + lebarY , xFL1 = standFL[0][0] - lebarX , yFL1 = standFL[1][0] - lebarY, zFL0 = 0, zFLp = 0;
        //KANAN TENGAH (RM)
        xRM0 = standRM[0][0] + lebarX,  yRM0 = standRM[1][0] + lebarY, xRM1 = standRM[0][0] - lebarX , yRM1 = standRM[1][0] - lebarY, zRM0 = 0, zRMp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0] + lebarX,  yBL0 = standBL[1][0] - lebarY, xBL1 = standBL[0][0] - lebarX , yBL1 = standBL[1][0] + lebarY, zBL0 = 0, zBLp = 0;
        statusGerak = true;
        //        st += 1;
        break;
      case 1 :
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0] + lebarX,  yFR0 = standFR[1][0] - lebarY, xFR1 = standFR[0][0] - lebarX, yFR1 = standFR[1][0] + lebarY , zFR0 = 0, zFRp = 0;
        //KIRI TENGAH (LM)
        xLM0 = standLM[0][0] + lebarX,  yLM0 = standLM[1][0] + lebarY, xLM1 = standLM[0][0] - lebarX, yLM1 = standLM[1][0] - lebarY, zLM0 = 0, zLMp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0] + lebarX,  yBR0 = standBR[1][0] + lebarY, xBR1 = standBR[0][0] - lebarX, yBR1 = standBR[1][0] - lebarY, zBR0 = 0, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0] - lebarX,  yFL0 = standFL[1][0] - lebarY , xFL1 = standFL[0][0] + lebarX, yFL1 = standFL[1][0] + lebarY, zFL0 = 0, zFLp = tinggi;
        //KANAN TENGAH (RM)
        xRM0 = standRM[0][0] - lebarX,  yRM0 = standRM[1][0] - lebarY, xRM1 = standRM[0][0] + lebarX, yRM1 = standRM[1][0] + lebarY, zRM0 = 0, zRMp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0] - lebarX,  yBL0 = standBL[1][0] + lebarY, xBL1 = standBL[0][0] + lebarX, yBL1 = standBL[1][0] - lebarY, zBL0 = 0, zBLp = tinggi;
        statusGerak = true;
        break;
    }
    steps++;
    if (steps > 1) steps = 0;
  }
}

void Trayektori() {
  float zFR1 = (zFRp - 0.25 * zFR0) / 0.75;
  float zBL1 = (zBLp - 0.25 * zBL0) / 0.75;
  float zFL1 = (zFLp - 0.25 * zFL0) / 0.75;
  float zBR1 = (zBRp - 0.25 * zBR0) / 0.75;
  float zLM1 = (zLMp - 0.25 * zLM0) / 0.75;
  float zRM1 =  (zRMp - 0.25 * zRM0) / 0.75;
  float a, b, c, d;
  float xFR, yFR, zFR, xFL, yFL, zFL, xBR, yBR, zBR, xBL, yBL, zBL, xRM, yRM, zRM, xLM, yLM, zLM;
  if (t <= 1) {
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
    cekT = true;
  }
  else if (t > 1) {
    t = 0; //Untuk Increment Tujuan Selanjutnya
    statusGerak = false;
  }
}

void Standby() {
  //KANAN DEPAN (FR)
  xFR0 = -60,  yFR0 = 60, xFR1 = -60, yFR1 = 60, zFR0 = 0, zFRp = 0;
  //KIRI TENGAH (LM)
  xLM0 = 85, yLM0 = 0, xLM1 = 85, yLM1 = 0, zLM0 = 0, zLMp = 0;
  //KANAN BELAKANG (BR)
  xBR0 = -60, yBR0 = -60, xBR1 = -60,  yBR1 = -60, zBR0 = 0, zBRp = 0;
  //KIRI DEPAN (FL)
  xFL0 = 60, yFL0 = 60, xFL1 = 60,  yFL1 = 60, zFL0 = 0, zFLp = 0;
  //KANAN TENGAH (RM)
  xRM0 = -85, yRM0 = 0, xRM1 = -85, yRM1 = 0, zRM0 = 0, zRMp = 0;
  //KIRI BELAKANG (BL)
  xBL0 = 60, yBL0 = -60, xBL1 = 60,  yBL1 = -60, zBL0 = 0, zBLp = 0;
  t = 0.5;
}

void ToggleLED() {
  if (LEDStat == "ON") {
    digitalWrite(PA1, LOW);
    LEDStat = "OFF";
    return;
  }
  if (LEDStat == "OFF") {
    digitalWrite(PA1, HIGH);
    LEDStat = "ON";
    return;
  }
}
