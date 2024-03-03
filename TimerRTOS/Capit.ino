//while ((moveServ || moveDyn) || movePeg) {
//  if (movePeg) {
//    pegangan.write(movePegangan(50 , 72, 20));
//  }
//  if (moveDyn) {
//    kirimDynamixel(512, moveDynamixel(240, 110, 200));
//  }
//}
int moveDynamixel(float sdtAwal, float sdtTujuan, float kecepatan) { //Kecepatan (Jumlah Titik) = Kecepatan Saat body maju ambil korban.
  if (t <= 180) {
    Inc = 180 / kecepatan;
    act = ((sdtTujuan - sdtAwal) / 10) * 2;
    sdtServo = (sdtAwal + (((act * t) / 360)) * 10) * 3.41;
    t += Inc;
    if (t > 180) {
      moveDyn = false;
      //      t = 0;
    }
  }
}

float movePegangan(float sdtAwals, float sdtTujuans, float kecepatans) { //Kecepatan (Jumlah Titik) = Kecepatan Saat body maju ambil korban.
  //  if (moveServ) {
  Inc = 180 / kecepatans;
  act = ((sdtTujuans - sdtAwals) / 10) * 2;
  sdtServo = sdtAwals + (((act * t) / 360)) * 10;
  t += Inc;
  if (t > 180) {
    movePeg = false;
    t = 0;
  }
  return sdtServo;
}

//void kirimDynamixel(int speedss, int positions) {
//  unsigned long checksum = 0;
//  unsigned char position_H = 0;
//  unsigned char position_L = 0;
//  unsigned char speed_H = 0;
//  unsigned char speed_L = 0;
//  unsigned char id;
//  unsigned char panjangData = 4;
//  unsigned char jumlahServo = 1;
//  unsigned char bufferDataTx[98];
//  unsigned char LENGTH = (panjangData + 1) * jumlahServo + 4;//19; // (panjang data +1) x jumlah servo + 4 ===>>> lighat manual rx 28 halaman 37
//  speed_H = speedss >> 8;    //high adresses
//  speed_L = speedss & 0xff;  //low addresses karena pengiriman  data harus 16 bit tetapi dipecah menjadi 2 yaitu masing2 8bit
//  checksum = 0xFE + LENGTH + 0x83 + 0x1E + panjangData;
//  //############# HEADER ############//
//  bufferDataTx[0] = 0xFF;
//  bufferDataTx[1] = 0xFF;
//  //######## BROADCAST INTRUCTION ############//
//  bufferDataTx[2] = 0xFE;
//  //######## LENGTH ############//
//  bufferDataTx[3] = LENGTH;
//  //######## SYNC WRITE ############//
//  bufferDataTx[4] = 0x83;
//  //######## FISRT ADDRESS ############//
//  bufferDataTx[5] = 0x1E;
//  //######## LENGTH OF DATA ############//
//  bufferDataTx[6] = panjangData;
//  //######## SERVO 00 ##################//
//  position_H = positions >> 8;
//  position_L = positions & 0xff;
//  id = 19;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[7] = id;
//  bufferDataTx[8] = position_L;
//  bufferDataTx[9] = position_H;
//  bufferDataTx[10] = speed_L;
//  bufferDataTx[11] = speed_H;
//  //############# checksum ##############//
//  checksum = (~checksum) & 0xFF; //only use lower bytes hal.49
//  bufferDataTx[12] = checksum;
//  sendData(13, bufferDataTx);
//}
//

void kirimDynamixel(int speedss, int positions) {
  unsigned long checksums = 0;
  unsigned char positions_H = 0;
  unsigned char positions_L = 0;
  unsigned char speeds_H = 0;
  unsigned char speeds_L = 0;
  unsigned char id;
  unsigned char lengthTotalData = 4;
  unsigned char jumlahServo = 1;
  unsigned char bufferData[98];
  unsigned char lengthTotal = (lengthTotalData + 1) * jumlahServo + 4;//19; // (panjang data +1) x jumlah servo + 4 ===>>> lighat manual rx 28 halaman 37
  speeds_H = speedss >> 8;    //high adresses
  speeds_L = speedss & 0xff;  //low addresses karena pengiriman  data harus 16 bit tetapi dipecah menjadi 2 yaitu masing2 8bit
  checksums = 0xFE + lengthTotal + 0x83 + 0x1E + lengthTotalData;
  //############# HEADER ############//
  bufferData[0] = 0xFF;
  bufferData[1] = 0xFF;
  //######## BROADCAST INTRUCTION ############//
  bufferData[2] = 0xFE;
  //######## lengthTotal ############//
  bufferData[3] = lengthTotal;
  //######## SYNC WRITE ############//
  bufferData[4] = 0x83;
  //######## FISRT ADDRESS ############//
  bufferData[5] = 0x1E;
  //######## lengthTotal OF DATA ############//
  bufferData[6] = lengthTotalData;
  //######## SERVO 00 ##################//
  positions_H = positions >> 8;
  positions_L = positions & 0xff;
  id = 19;
  checksums += positions_L + positions_H + speeds_L + speeds_H + id;
  bufferData[7] = id;
  bufferData[8] = positions_L;
  bufferData[9] = positions_H;
  bufferData[10] = speeds_L;
  bufferData[11] = speeds_H;
  //############# checksums ##############//
  checksums = (~checksums) & 0xFF; //only use lower bytes hal.49
  bufferData[12] = checksums;
  sendData(13, bufferData);
}

void sendData(char jmlhData, unsigned char *paket) {
  for (int i = 0; i < jmlhData; i++) {
    Serial2.write(paket[i]);
  }
}
