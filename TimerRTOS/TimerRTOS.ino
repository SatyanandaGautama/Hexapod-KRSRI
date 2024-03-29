HardwareSerial Serial2(USART2);//Serial Driver Servo
HardwareSerial Serial3(USART3);//Serial Arduino Nano
HardwareSerial Serial6(USART6);//Serial Maixbit Camera
#include <HardwareTimer.h>
#include <STM32FreeRTOS.h>
#include <semphr.h>
#define configUSE_16_BIT_TICKS  1
//HuskyLens Camera
#include "HUSKYLENS.h"
HUSKYLENS huskylens;
HUSKYLENSResult result;
//SharpIR
#define IRfront PA0 //PA0(Mau), PC5(Mau), PC4(Mau), PB0(Mau), PC2(Mau), PC1(Mau)
#define IRback PC0
//Servo
#include <Servo.h>
Servo capit1, capit2, pegangan;
int distances;
HardwareTimer Timer6(TIM6);
const uint32_t timerPeriod_us = 17000 - 1;
const int prescaler = 84 - 1; // 1 MHz
static SemaphoreHandle_t bin_sem = NULL;
static SemaphoreHandle_t mutex;
//Kamera
int pict_x = 200, pict_area, area, pict_y;//Tambah variabel area klo mau pke area //200
int pict_x_cal = 165; // Threshold nilai tengah korban di kamera
int pict_area_cal = 7500; // Threshold area blob (jarak korban) di kamera
int pict_y_cal = 0; //Ganti nilai 0 dengan nilai y ketika pas capit dengan korban
bool tengah = 0;
//Rotate MPU
bool rot = true;
int Offset, tujuan;
//MPU6050
int yaw = -1; // -1 Untuk looping menunggu kalibrasi selesai
int pitch, roll, rollAwal = 0, rollTangga = -15;
int sdtAcuan = 0, yawSebelum = 0;
//PING
uint32_t rightBack = PE11;
uint32_t rightFront = PE12;
uint32_t leftBack = PE8;
uint32_t leftFront = PE10;
int cm, duration, OffsetJarak, offsets, jBack, jFront;
//SRF-04
#define ECHO PE13
#define TRIG PE9
int jarak;
//Gerakan
bool statusGerak = false;
bool modeGerak = true;
int steps = 0;
float theta = 90;
float tAwal, degAwal;
float tAkhir, degAkhir;
//Servo Capit
float actServo, actDyn, Inc, sdtServoAwal, sdtServoAkhir, sdtDynAwal, sdtDynAkhir, tDyn = 0, tServo = 0;
int stepss = 0, sdtDyn, sdtServo;
bool moveDyn = false;
bool movePeg = false;
bool Capit = false;
//
float xFR, yFR, zFR, xFL, yFL, zFL, xBR, yBR, zBR, xBL, yBL, zBL, xRM, yRM, zRM, xLM, yLM, zLM;
float yFR_Awal, yFL_Awal, yBL_Awal, yBR_Awal, yRM_Awal, yLM_Awal, yFR_Akhir, yFL_Akhir, yBL_Akhir, yBR_Akhir, yRM_Akhir, yLM_Akhir;
float xFR_Awal, xFL_Awal, xBL_Awal, xBR_Awal, xRM_Awal, xLM_Awal, xFR_Akhir, xFL_Akhir, xBL_Akhir, xBR_Akhir, xRM_Akhir, xLM_Akhir;
float actual_xFR, actual_yFR, actual_xRM, actual_yRM, actual_xBR, actual_yBR, actual_xBL, actual_yBL, actual_xLM, actual_yLM, actual_xFL, actual_yFL;
float actual_zFR, actual_zRM, actual_zBR, actual_zFL, actual_zLM, actual_zBL;
//=====Input Trayektori Global=====//
//KANAN DEPAN (FR)
float xFR0, yFR0, xFR1, yFR1, zFR0, zFRp;
//KIRI TENGAH (LM)
float xLM0, yLM0, xLM1, yLM1, zLM0, zLMp;
//KANAN BELAKANG (BR)
float xBR0, yBR0, xBR1,  yBR1, zBR0, zBRp;
//KIRI DEPAN (FL)
float xFL0, yFL0, xFL1,  yFL1, zFL0, zFLp;
//KANAN TENGAH (RM)
float xRM0, yRM0, xRM1, yRM1, zRM0, zRMp;
//KIRI BELAKANG (BL)
float xBL0, yBL0, xBL1,  yBL1, zBL0, zBLp;
float Increment;
//Variabel simpan sudut tiap servo
int outServo[6][3];
//Variabel Invers Kinematik
const float cx = 22;
const int fm = 53;
const int tb = 70;
int heightFront = -92, heightMid = -92, heightBack = -92;//kelereng -94
float z, sdtcoxa, sdtcoxa1, sdtcoxa2, sdtcoxa3, sdtcoxa4, sdtrotate, sdtfemur, sdttibia, theta2, theta3, angle1, angle2, P, c, alas, alpha, beta;
const int legoffset[6] = {0, 45, 135, 180, 225, 315};
//Koordinat Awal (Standby) per Kaki :
const float standFR[3][1] = {{ -55}, {55}, {0}}; //
const float standRM[3][1] = {{ -76}, {0}, {0}}; //
const float standBR[3][1] = {{ -55}, { -55}, {0}};
const float standFL[3][1] = {{ 55}, {55}, {0}};
const float standLM[3][1] = {{ 76}, {0}, {0}};
const float standBL[3][1] = {{ 55}, { -55}, {0}};
float offsetCX[4] = {0};//0 = FR, 1 = BR, 2 = BL, 3 = FL
float midRightFM = 0, midRightTB = 0, midLeftFM = 0, midLeftTB = 0, rightFM = 0, rightTB = 0, leftFM = 0, leftTB = 0;
int jmlhStep;
//Gerak Rotate
float P1[3][1];
float P2[3][1];
float arahPutar;
//=====PID Variable=====//
float error, setpoint, P_control, D_control, PID_control, Time, dt, time_prev, previous_error;
float kp = 0.5;
float kd = 0;
float lebarKiri, lebarKanan, lebarTengah;
//================================================================================================================================//
bool Sensors = true;
bool stateMPU = false;
bool turunMPU = false;
float filter_weight = 1; //Untuk filter roll naik tangga = 0.2
float filtered_Roll;

void timerInterrupt() {
  BaseType_t task_woken = pdFALSE;
  // Give semaphore to tell task that new value is ready
  xSemaphoreGiveFromISR(bin_sem, &task_woken);
  // Exit from ISR (Vanilla FreeRTOS)
  portYIELD_FROM_ISR(task_woken);
}
void setup() {
  Serial.setTx(PA9);
  Serial.setRx(PA10);
  Serial.begin(9600);
  Serial2.setTx(PA2);
  Serial2.setRx(PA3);
  Serial2.begin(1000000);
  Serial3.setTx(PD8);
  Serial3.setRx(PD9);
  Serial3.begin(115200);
  //====Setup SRF04====//
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  capit1.attach(PE15); //Capit Kiri (Saat Robot ke Arah Depan)
  capit2.attach(PB11); //Capit Kanan
  pegangan.attach(PE14);
  delay(3000);
  //INGET DICOMMENT SAAT TRAINING HUSKYLENS di ROBOT
  //  //===Setup HuskyLens===//
  //  Serial6.setTx(PC6);
  //  Serial6.setRx(PC7);
  //  Serial6.begin(9600);
  //  delay(2000);
  //  while (!huskylens.begin(Serial6))
  //  {
  //    Serial.println(F("Begin failed!"));
  //    Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
  //    Serial.println(F("2.Please recheck the connection."));
  //    delay(100);
  //  }
  //  huskylens.writeAlgorithm(ALGORITHM_OBJECT_TRACKING); //Switch the algorithm to object tracking.
  //  //===Setup HuskyLens===//
  //  delay(3000);
  StandbyAwal();
  resetPID();
  delay(2000);
  kirimDynamixel(820);
  pegangan.write(72);
  capit1.write(130);  //180 Kondisi Tutup //130 Buka
  capit2.write(50);    //0 Kondisi Tutup   //50 Buka
  delay(1000);
  while (yaw < 0) {
    read_MPU();
    delay(15);
  }
  bin_sem = xSemaphoreCreateBinary();
  mutex = xSemaphoreCreateMutex();
  if (bin_sem == NULL) {
    Serial.println("Could not create Semaphore");
  }
  xTaskCreate(Sensor,
              "Sensor",
              1024,
              NULL,
              1, //Priority Lebih Rendah
              NULL);
  xTaskCreate(Kaki,
              "Kaki",
              1024, //awal 512
              NULL,
              2, //Priority Lebih Tinggi
              NULL);
  Timer6.pause(); //Stop the Timer
  Timer6.setPrescaleFactor(prescaler); //Set the prescaler to achieve 1us per tick (assuming 84MHz clock)
  Timer6.setOverflow(timerPeriod_us, MICROSEC_FORMAT);
  Timer6.attachInterrupt(timerInterrupt);
  Timer6.setMode(1, TIMER_OUTPUT_COMPARE);
  Timer6.refresh(); //Reset timer to 0
  Timer6.resume();  //Start the timer
  vTaskStartScheduler();
}

void loop() {

}
