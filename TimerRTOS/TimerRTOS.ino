HardwareSerial Serial2(USART2);//Serial Driver Servo
HardwareSerial Serial3(USART3);//Serial Arduino Nano
HardwareSerial Serial6(USART6);//Serial Maixbit Camera
#include <HardwareTimer.h>
#include <STM32FreeRTOS.h>
#include <semphr.h>
#define configUSE_16_BIT_TICKS  1
//======Sensor IR ToF=====//
#include <Wire.h>
#include <VL53L0X.h>
VL53L0X sensor;
//========================//
HardwareTimer Timer6(TIM6);
const uint32_t timerPeriod_us = 17000 - 1;
const int prescaler = 84 - 1; // 1 MHz
static SemaphoreHandle_t bin_sem = NULL;
static SemaphoreHandle_t mutex;
//bool mut = false;
//Kamera
int pict_x = 200, pict_area, area, pict_y;//Tambah variabel area klo mau pke area //200
int pict_x_cal = 165; // Threshold nilai tengah korban di kamera
int pict_area_cal = 7500; // Threshold area blob (jarak korban) di kamera
int pict_y_cal = 0; //Ganti nilai 0 dengan nilai y ketika pas capit dengan korban
bool tengah = 0;
//Rotate MPU
bool rot = true;
int Offset, Tujuan;
//MPU6050
int yaw = -1; // -1 Untuk looping menunggu kalibrasi selesai
int pitch, roll = 0;
//PING
uint32_t leftBack = PE11;
uint32_t leftFront = PE12;
int jarak;
double duration, cm;
//Gerakan
bool statusGerak = false;
bool modeGerak = true;
static int steps = 0;
float theta = 90;
float tAwal, degAwal;
float tAkhir, degAkhir;
//Servo Capit
float act, sdtServo, Inc, t = 0;
//
float xFR, yFR, zFR, xFL, yFL, zFL, xBR, yBR, zBR, xBL, yBL, zBL, xRM, yRM, zRM, xLM, yLM, zLM;
float yFR_Awal, yFL_Awal, yBL_Awal, yBR_Awal, yRM_Awal, yLM_Awal, yFR_Akhir, yFL_Akhir, yBL_Akhir, yBR_Akhir, yRM_Akhir, yLM_Akhir;
float xFR_Awal, xFL_Awal, xBL_Awal, xBR_Awal, xRM_Awal, xLM_Awal, xFR_Akhir, xFL_Akhir, xBL_Akhir, xBR_Akhir, xRM_Akhir, xLM_Akhir;
float actual_xFR, actual_yFR, actual_xRM, actual_yRM, actual_xBR, actual_yBR, actual_xBL, actual_yBL, actual_xLM, actual_yLM, actual_xFL, actual_yFL;
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
const int fm = 58;
const int tb = 80;
int height = -95;
float z, sdtcoxa, sdtcoxa1, sdtcoxa2, sdtcoxa3, sdtcoxa4, sdtrotate, sdtfemur, sdttibia, theta2, theta3, angle1, angle2, P, c, alas, alpha, beta;
const int legoffset[6] = {0, 45, 135, 180, 225, 315};
//Koordinat Awal (Standby) per Kaki :
const float standFR[3][1] = {{ -65}, {65}, {0}};
const float standRM[3][1] = {{ -80}, {0}, {0}};
const float standBR[3][1] = {{ -65}, { -65}, {0}};
const float standFL[3][1] = {{ 65}, {65}, {0}};
const float standLM[3][1] = {{ 80}, {0}, {0}};
const float standBL[3][1] = {{ 65}, { -65}, {0}};
//Gerak Rotate
float P1[3][1];
float P2[3][1];
float arahPutar;
//=====PID Variable=====//
//==========PID=========//
float error, setpoint, P_control, D_control, PID_control, Time, dt, time_prev, previous_error;
float kp = 0.5;
float kd = 0;
float lebarKiri, lebarKanan;
//================================================================================================================================//
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
  Serial.begin(115200);
  Serial2.setTx(PA2);
  Serial2.setRx(PA3);
  Serial2.begin(1000000);
  Serial3.setTx(PD8);
  Serial3.setRx(PD9);
  Serial3.begin(115200);
  Serial6.setTx(PC6);
  Serial6.setRx(PC7);
  Serial6.begin(115200);
  delay(2000);
  //====Setup IR====//
  Wire.setSDA(PC9);
  Wire.setSCL(PA8);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
  //================//
  delay(1000);
  FR(-65, 65, 0);
  RM(-80, 0, 0);
  BR(-65, -65, 0);
  BL(65, -65, 0);
  LM(80, 0, 0);
  FL(65, 65, 0);
  KirimIntruksiGerak(0);
  resetPID()
  delay(4000);
  while (yaw < 0) {
    read_MPU();
    delay(10);
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
              1024,
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
