void moveDynamixel() {  //Kecepatan (Jumlah Titik) = Kecepatan Saat body maju ambil korban.
  if (tDyn <= 180) {
    actDyn = ((sdtDynAkhir - sdtDynAwal) / 10) * 2;
    sdtDyn = (sdtDynAwal + (((actDyn * tDyn) / 360)) * 10) * 3.41;
    tDyn += Inc;
    if (tDyn > 180) {
      moveDyn = false;
      tDyn = 0;
    }
  }
}

void movePegangan() {  //Kecepatan (Jumlah Titik) = Kecepatan Saat body maju ambil korban.
  if (tServo <= 180) {
    actServo = ((sdtServoAkhir - sdtServoAwal) / 10) * 2;
    sdtServo = sdtServoAwal + (((actServo * tServo) / 360)) * 10;
    tServo += Inc;
    if (tServo > 180) {
      movePeg = false;
      tServo = 0;
    }
  }
}

void taruhKorban1(int kecepatan) {
  if (!moveDyn && !movePeg) {
    Capit = true;
    Inc = 180 / kecepatan;
    switch (stepss) {
      case 0:  //Turunkan Capit
        sdtServoAwal = 82, sdtServoAkhir = 62;
        sdtDynAwal = 240, sdtDynAkhir = 117;
        moveDyn = true;
        movePeg = true;
        break;
      case 1:  //Buka Capit
        //        capit1.write(135);
        capit2.write(40);
        sdtServoAwal = 62, sdtServoAkhir = 62;
        sdtDynAwal = 117, sdtDynAkhir = 117;
        moveDyn = true;
        movePeg = true;
        break;
      case 2:
        sdtServoAwal = 62, sdtServoAkhir = 102;
        sdtDynAwal = 117, sdtDynAkhir = 117;
        moveDyn = true;
        movePeg = true;
        break;
      case 3:  //Naikkan Capit
        sdtServoAwal = 102, sdtServoAkhir = 82;
        sdtDynAwal = 117, sdtDynAkhir = 240;
        moveDyn = true;
        movePeg = true;
        break;
      case 4:
        Inc = 180 / 3;
        sdtServoAwal = 82, sdtServoAkhir = 82;
        sdtDynAwal = 240, sdtDynAkhir = 240;
        moveDyn = true;
        movePeg = true;
        break;
    }
    stepss++;
    if (stepss > 5) {
      Capit = false;
      stepss = 0;
    }
  }
}

void taruhKorban2(int kecepatan) {
  if (!moveDyn && !movePeg) {
    Capit = true;
    Inc = 180 / kecepatan;
    switch (stepss) {
      case 0:  //Turunkan Capit
        sdtServoAwal = 82, sdtServoAkhir = 50;
        sdtDynAwal = 240, sdtDynAkhir = 134;
        moveDyn = true;
        movePeg = true;
        break;
      case 1:  //Buka Capit
        //        capit1.write(135);
        capit2.write(40);
        sdtServoAwal = 50, sdtServoAkhir = 50;
        sdtDynAwal = 134, sdtDynAkhir = 134;
        moveDyn = true;
        movePeg = true;
        break;
      case 2:
        sdtServoAwal = 50, sdtServoAkhir = 92;
        sdtDynAwal = 134, sdtDynAkhir = 134;
        moveDyn = true;
        movePeg = true;
        break;
      case 3:  //Naikkan Capit
        sdtServoAwal = 92, sdtServoAkhir = 82;
        sdtDynAwal = 134, sdtDynAkhir = 240;
        moveDyn = true;
        movePeg = true;
        break;
      case 4:
        Inc = 180 / 3;
        sdtServoAwal = 82, sdtServoAkhir = 82;
        sdtDynAwal = 240, sdtDynAkhir = 240;
        moveDyn = true;
        movePeg = true;
        break;
    }
    stepss++;
    if (stepss > 5) {
      Capit = false;
      stepss = 0;
    }
  }
}

void taruhKorban5(int kecepatan) {
  if (!moveDyn && !movePeg) {
    Capit = true;
    Inc = 180 / kecepatan;
    switch (stepss) {
      case 0:  //Turunkan Capit
        Inc = 180 / 40;
        sdtServoAwal = 82, sdtServoAkhir = 50;
        sdtDynAwal = 240, sdtDynAkhir = 136;
        moveDyn = true;
        movePeg = true;
        break;
      case 1:  //Buka Capit
        //        capit1.write(135);
        capit2.write(48);
        sdtServoAwal = 50, sdtServoAkhir = 50;
        sdtDynAwal = 136, sdtDynAkhir = 136;
        moveDyn = true;
        movePeg = true;
        break;
    }
    stepss++;
    if (stepss > 2) {
      Capit = false;
      stepss = 0;
    }
  }
}

void CapitBack_K5(int kecepatan) {
  if (!moveDyn && !movePeg) {
    Capit = true;
    Inc = 180 / kecepatan;
    switch (stepss) {
      case 0:  //Turunkan Capit
        Inc = 180 / 20;
        sdtServoAwal = 50, sdtServoAkhir = 82;
        sdtDynAwal = 136, sdtDynAkhir = 240;
        moveDyn = true;
        movePeg = true;
        break;
      case 1:  //Buka Capit
        //        capit1.write(135);
        capit2.write(40);
        sdtServoAwal = 82, sdtServoAkhir = 82;
        sdtDynAwal = 240, sdtDynAkhir = 240;
        moveDyn = true;
        movePeg = true;
        break;
    }
    stepss++;
    if (stepss > 2) {
      Capit = false;
      stepss = 0;
    }
  }
}

void kirimDynamixel(int positions) {
  unsigned long checksums = 0;
  unsigned char positions_H = 0;
  unsigned char positions_L = 0;
  unsigned char speeds_H = 0;
  unsigned char speeds_L = 0;
  unsigned char id;
  unsigned char lengthTotalData = 4;
  unsigned char jumlahServo = 1;
  unsigned char bufferData[13];
  unsigned char lengthTotal = (lengthTotalData + 1) * jumlahServo + 4;  //19; // (panjang data +1) x jumlah servo + 4 ===>>> lighat manual rx 28 halaman 37
  speeds_H = 780 >> 8;                                                  //high adresses
  speeds_L = 780 & 0xff;                                                //low addresses karena pengiriman  data harus 16 bit tetapi dipecah menjadi 2 yaitu masing2 8bit
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
  checksums = (~checksums) & 0xFF;  //only use lower bytes hal.49
  bufferData[12] = checksums;
  sendData(13, bufferData);
}

void sendData(char jmlhData, unsigned char *paket) {
  for (int i = 0; i < jmlhData; i++) {
    Serial2.write(paket[i]);
  }
}
