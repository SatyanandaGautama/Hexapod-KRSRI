float moveDynamixel(float sdtAwal, float sdtTujuan, float kecepatan) { //Kecepatan (Jumlah Titik) = Kecepatan Saat body maju ambil korban.
  if (t <= 180) {
    Inc = 180 / kecepatan;
    act = ((sdtTujuan - sdtAwal) / 10) * 2;
    sdtServo = (sdtAwal + (((act * t) / 360)) * 10) * 3.41;
    t += Inc;
    if (t > 180)t = 0;
    return sdtServo;
  }
}

float moveServo(float sdtAwals, float sdtTujuans, float kecepatans) { //Kecepatan (Jumlah Titik) = Kecepatan Saat body maju ambil korban.
  if (t <= 180) {
    Inc = 180 / kecepatans;
    act = ((sdtTujuans - sdtAwals) / 10) * 2;
    sdtServo = sdtAwals + (((act * t) / 360)) * 10;
    t += Inc;
    if (t > 180)t = 0;
    return sdtServo;
  }
}

void kirimDynamixel(int servoID, int positions) {
  unsigned long checksums = 0;
  unsigned char positions_H = 0;
  unsigned char positions_L = 0;
  unsigned char speeds_H = 0;
  unsigned char speeds_L = 0;
  unsigned char lengthData = 4;
  unsigned char bufferData[11];  // Adjust the buffer size accordingly
  unsigned char lengthTotal = lengthData + 4;  // Adjust the lengthTotal calculation
  speeds_H = 0;  // Set speed to constant value 0
  speeds_L = 0;
  positions_H = positions >> 8;
  positions_L = positions & 0xff;
  checksums = 0xFF + lengthTotal + 0x83 + 0x1E + lengthData;
  // Header
  bufferData[0] = 0xFF;
  bufferData[1] = 0xFF;
  // Instruction
  bufferData[2] = servoID;
  // lengthTotal
  bufferData[3] = lengthTotal;
  // Instruction
  bufferData[4] = 0x83;
  // First Address
  bufferData[5] = 0x1E;
  // lengthTotal of Data
  bufferData[6] = lengthData;
  // Servo ID
  bufferData[7] = servoID;
  // Position
  bufferData[8] = positions_L;
  bufferData[9] = positions_H;
  // Speed
  bufferData[10] = speeds_L;
  bufferData[11] = speeds_H;
  // checksums
  checksums += servoID + positions_L + positions_H + speeds_L + speeds_H;
  checksums = (~checksums) & 0xFF;
  bufferData[12] = checksums;
  sendData(13, bufferData);  // Adjust the size of the buffer accordingly
}

void sendData(char jmlhData, unsigned char *paket) {
  for (int i = 0; i < jmlhData; i++) {
    Serial2.write(paket[i]);
  }
}
