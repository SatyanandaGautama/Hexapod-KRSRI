HardwareSerial Serial3(USART3);

int yaw = -1; // -1 Untuk looping menunggu kalibrasi selesai
int pitch, roll = 0;

void setup() {
  Serial.setTx(PA9);
  Serial.setRx(PA10);
  Serial.begin(115200);

  Serial3.setTx(PD8);
  Serial3.setRx(PD9);
  Serial3.begin(115200);

  delay(3000);

  while (yaw == -1) {
    read_maix();
    delay(200);
    Serial.println("N");
  }
}

void read_maix() {
  // Serial2.println("Trigger Maix");
  Serial3.write('1'); // trigger maix buat ngirim data
  // Serial2.println("Data Masuk");
  // Serial2.println(Serial.available());

  String yawT = "";
  String pitchT = "";
  String rollT = "";

  int i = 0;
  while (Serial3.available()) {
    if (i == 0) {
      char c = Serial3.read();
      if (c == '|') {
        i += 1;
      } else {
        yawT += c;
        if (yawT.length() > 3) {
          Serial.println("Invalid MPU Value"); // Karena value yaw maksimal 360, jika lebih dari 3 digit maka Serial yang diterima bukan value YPR.
          while (Serial.available()) {
            Serial3.read();
          }
          return;
        }
      }
    } else if (i == 1) {
      char c = Serial3.read();
      if (c == '|') {
        i += 2;
      } else {
        pitchT += c;
      }
    } else {
      char c = Serial3.read();
      rollT += c;
    }
  }

  if (yawT != "" && pitchT != "" && rollT != "") {
    Serial.print("ypr: \t");
    Serial.print(yawT);
    Serial.print("\t");
    Serial.print(pitchT);
    Serial.print("\t");
    Serial.println(rollT);
    Serial3.flush();

    yaw = yawT.toInt();
    pitch = pitchT.toInt();
    roll = rollT.toInt();
  }

}

void loop() {
  read_maix();
  delay(200);
}
