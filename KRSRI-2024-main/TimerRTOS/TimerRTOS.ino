//===OLED Display===//
#include <vl53l0x_class.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels
#define OLED_RESET 0      // Reset pin # (or -1 if sharing Arduino reset pin)
#include <Wire.h>

//============ TOF =================== //
#define XSHUT_depan PC4
#define XSHUT_kanan PC0
#define XSHUT_kiri PC5
#define XSHUT_belakang PA0 //A0
// #define XSHUT_belakangKanan PE10
// #define XSHUT_belakangKiri PE10
// Create components.
TwoWire WIRE1(PC9, PA8);                          //SDA=PB11 & SCL=PB10
VL53L0X sensor_vl53l0x_1(&WIRE1, XSHUT_depan);    //XSHUT=PE11
VL53L0X sensor_vl53l0x_2(&WIRE1, XSHUT_kanan);  //XSHUT=PE12
VL53L0X sensor_vl53l0x_3(&WIRE1, XSHUT_kiri);
VL53L0X sensor_vl53l0x_4(&WIRE1, XSHUT_belakang);

uint32_t distance_top_1;
uint32_t distance_top_2;
uint32_t distance_top_3;
uint32_t distance_top_4;
int TOFDepan, TOFKanan, TOFKiri, TOFBelakang;
int s = 1;
//============ TOF =================== //

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &WIRE1, OLED_RESET);
//===OLED Display===//
#define Lampu PB9
#define Button PB12
HardwareSerial Serial2(USART2);  //Serial Driver Servo
HardwareSerial Serial3(USART3);  //Serial Arduino Nano
HardwareSerial Serial6(USART6);  //Serial Maixbit Camera
#include <HardwareTimer.h>
#include <STM32FreeRTOS.h>
#include <semphr.h>
#define configUSE_16_BIT_TICKS 1
//HuskyLens Camera
#include "HUSKYLENS.h"
HUSKYLENS huskylens;
HUSKYLENSResult result;
int x0 = 158, x1;
//SharpIR
#define IRfront PA0  //PA0(Mau), PC5(Mau), PC4(Mau), PB0(Mau), PC2(Mau), PC1(Mau)
#define IRback PC0
#define IRright PC4
#define IRleft PC5
#define IRbackgroan PC2
//Servo
#include <Servo.h>
Servo capit1, capit2, pegangan, bodyKanan, bodyKiri;
int distances;
HardwareTimer Timer6(TIM6);
const uint32_t timerPeriod_us = 22000 - 1;
const int prescaler = 84 - 1;  // 1 MHz
static SemaphoreHandle_t bin_sem = NULL;
static SemaphoreHandle_t mutex;
// ToF
uint32_t jarakTof;
int distanceTof;
uint32_t jarakTof1;
int distanceTof1;
int status;
//Rotate MPU
bool rot = true;
int Offset, tujuan;
//MPU6050
int yaw = -1;  // -1 Untuk looping menunggu kalibrasi selesai
int yawAwal = 0;
int pitch, roll, rollAwal = 0, rollTangga = 13;
int sdtAcuan = 0, yawSebelum = 0;
//PING
uint32_t belakang = PE15;
uint32_t rightBack = PE11;
uint32_t rightFront = PE12;
uint32_t leftBack = PE8;    //E8
uint32_t leftFront = PE10;  //E10
int cm, duration, OffsetJarak, offsets, jBack, jFront;
//SRF-04
#define ECHO PB0
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
float xBR0, yBR0, xBR1, yBR1, zBR0, zBRp;
//KIRI DEPAN (FL)
float xFL0, yFL0, xFL1, yFL1, zFL0, zFLp;
//KANAN TENGAH (RM)
float xRM0, yRM0, xRM1, yRM1, zRM0, zRMp;
//KIRI BELAKANG (BL)
float xBL0, yBL0, xBL1, yBL1, zBL0, zBLp;
float Increment;
//Variabel simpan sudut tiap servo
int outServo[6][3];
//Variabel Invers Kinematik
const float cx = 22;
const int fm = 53;
const int tb = 70;
int heightFR = -92, heightRM = -92, heightBR = -92, heightFL = -92, heightLM = -92, heightBL = -92;
float z, sdtcoxa, sdtcoxa1, sdtcoxa2, sdtcoxa3, sdtcoxa4, sdtrotate, sdtfemur, sdttibia, theta2, theta3, angle1, angle2, P, c, alas, alpha, beta;
const int legoffset[6] = { 0, 45, 135, 180, 225, 315 };
//Koordinat Awal (Standby) per Kaki :
const float standFR[3][1] = { { -55 }, { 55 }, { 0 } };
const float standRM[3][1] = { { -76 }, { 0 }, { 0 } };
const float standBR[3][1] = { { -55 }, { -55 }, { 0 } };
const float standFL[3][1] = { { 55 }, { 55 }, { 0 } };
const float standLM[3][1] = { { 76 }, { 0 }, { 0 } };
const float standBL[3][1] = { { 55 }, { -55 }, { 0 } };
float offsetCX[4] = { 0 };  //0 = FR, 1 = BR, 2 = BL, 3 = FL
float leftFM_FL = 0, midRightFM = 0, midRightTB = 0, midLeftFM = 0, midLeftTB = 0, rightFM = 0, rightTB = 0, leftFM = 0, leftTB = 0, rightTB_FR = 0, rightFM_FR = 0;
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
bool cactch = true;
float filtered_Roll = 0;
float filtered_IR = 0;
float filtered_IRdepan = 0;
float filtered_jFront = 0;
float filtered_jBack = 0;
float filtered_Rg = 0;
float filtered_Rb = 0;
int sdtfix;
int dist, dist1;
float weight = 0.4, weight_PING = 0.6;
int sdtMaju, ButtonState = 1;
bool stop = true;
bool sdtRollTangga = true;
bool sdtRollAfterTangga = true;
float filter_weight = 0.23;  //Untuk filter roll naik tangga = 0.2
bool afterK5 = true;

void timerInterrupt() {
  BaseType_t task_woken = pdFALSE;
  // Give semaphore to tell task that new value is ready
  xSemaphoreGiveFromISR(bin_sem, &task_woken);
  // Exit from ISR (Vanilla FreeRTOS)
  portYIELD_FROM_ISR(task_woken);
}

void setup() {
  Serial2.setTx(PA2);
  Serial2.setRx(PA3);
  Serial2.begin(1000000);
  delay(500);
  Serial3.setTx(PD8);
  Serial3.setRx(PD9);
  Serial3.begin(115200);
  Serial.setTx(PA9);
  Serial.setRx(PA10);
  Serial.begin(9600);
  WIRE1.begin();
  delay(2000);
  //===OLED Setup===//
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //==== ToF Setup====//
  //=== Configure VL53L0X components. ===//
  sensor_vl53l0x_1.begin();//Depan
  sensor_vl53l0x_2.begin();//Kanan
  sensor_vl53l0x_3.begin();//Kiri
  sensor_vl53l0x_4.begin();//Belakang
  //=== Switch off VL53L0X components. ===//
  sensor_vl53l0x_1.VL53L0X_Off();//Depan
  sensor_vl53l0x_2.VL53L0X_Off();//Kanan
  sensor_vl53l0x_3.VL53L0X_Off();//Kiri
  sensor_vl53l0x_4.VL53L0X_Off();//Belakang
  //=== Initialize VL53L0X components. ===//
  status = sensor_vl53l0x_1.InitSensor(0x10);
  if (status) {
    Serial.println("Init sensor_vl53l0x_1 failed...");
  }
  status = sensor_vl53l0x_2.InitSensor(0x13);
  if (status) {
    Serial.println("Init sensor_vl53l0x_2 failed...");
  }
  status = sensor_vl53l0x_3.InitSensor(0x16);
  if (status) {
    Serial.println("Init sensor_vl53l0x_3 failed...");
  }
  status = sensor_vl53l0x_4.InitSensor(0x19); //0x19
  if (status) {
    Serial.println("Init sensor_vl53l0x_4 failed...");
  }
  SetupSingleShot(sensor_vl53l0x_1);
  SetupSingleShot(sensor_vl53l0x_2);
  SetupSingleShot(sensor_vl53l0x_3);
  SetupSingleShot(sensor_vl53l0x_4);
  //============ TOF =======================
  delay(100);
  //====Setup SRF04====//
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(Button, INPUT);
  pinMode(Lampu, OUTPUT);
  //  capit1.attach(PE15);//Capit Kiri (Saat Robot ke Arah Depan)
  capit2.attach(PB11);  //Capit Kanan
  bodyKanan.attach(PE13);
  bodyKiri.attach(PE7);
  pegangan.attach(PE14);
  kirimDynamixel(820);  //820 //450
  pegangan.write(72);   //72 //17
  //  capit1.write(135);  // 165 tutup 135 buka
  capit2.write(40);      // 8 tutup 40 buka
  bodyKanan.write(180);  //180 posisi atas //140
  bodyKiri.write(0);     //0 posisi atas //60
  delay(500);
  // INGET DICOMMENT SAAT TRAINING HUSKYLENS di ROBOT
  // === Setup HuskyLens ===  //
  Serial6.setTx(PC6);
  Serial6.setRx(PC7);
  Serial6.begin(9600);
  delay(500);
  while (!huskylens.begin(Serial6)) {
    Serial.println(F("Begin failed!"));
    Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
    Serial.println(F("2.Please recheck the connection."));
    delay(100);
  }
  huskylens.writeAlgorithm(ALGORITHM_OBJECT_TRACKING);  //Switch the algorithm to object tracking.
  delay(1000);
  //===Setup HuskyLens===//
  //===Standby Tangga===//
  // naikTangga();
  // FR(-55, 55, 0);
  // RM(-75, 0, 0);
  // BR(-55, -55, 0);
  // BL(55, -55, 0);
  // LM(75, 0, 0);
  // FL(55, 55, 0);
  // KirimIntruksiGerak(512);
  //===Standby Tangga===//
  StandbyAwal();
  delay(1500);
  resetPID();
  //============================================//
  display.clearDisplay();
  display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 31, WHITE);
  display.drawPixel(127, 31, WHITE);
  display.setTextSize(1);       // set ukuran huruf
  display.setTextColor(WHITE);  // set warna huruf
  display.setCursor(38, 8);
  display.print("CALIBRATE");
  display.setTextSize(1);       // set ukuran huruf
  display.setTextColor(WHITE);  // set warna huruf
  display.setCursor(56, 16);
  display.print("MPU");
  display.display();
  while (yaw < 0) {
    read_MPU();
    delay(15);
  }
  display.clearDisplay();
  display.setTextSize(2);       // set ukuran huruf, sesuaikan jika perlu
  display.setTextColor(WHITE);  // set warna huruf
  display.setCursor(40, 8);     // atur posisi kursor (x, y)
  display.print("DONE");
  display.display();
  //  delay(3000);
  bin_sem = xSemaphoreCreateBinary();
  mutex = xSemaphoreCreateMutex();
  if (bin_sem == NULL) {
    Serial.println("Could not create Semaphore");
  }
  xTaskCreate(Sensor,
              "Sensor",
              1024,
              NULL,
              1,  //Priority Lebih Rendah
              NULL);
  xTaskCreate(Kaki,
              "Kaki",
              512,  //awal 512
              NULL,
              2,  //Priority Lebih Tinggi
              NULL);
  Timer6.pause();                       //Stop the Timer
  Timer6.setPrescaleFactor(prescaler);  //Set the prescaler to achieve 1us per tick (assuming 84MHz clock)
  Timer6.setOverflow(timerPeriod_us, MICROSEC_FORMAT);
  Timer6.attachInterrupt(timerInterrupt);
  Timer6.setMode(1, TIMER_OUTPUT_COMPARE);
  Timer6.refresh();  //Reset timer to 0
  Timer6.resume();   //Start the timer
  vTaskStartScheduler();
}

void loop() {
}
