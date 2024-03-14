//void KirimIntruksiGerak(int speedss) {
//  unsigned long checksum = 0;
//  unsigned char position_H = 0;
//  unsigned char position_L = 0;
//  unsigned char speed_H = 0;
//  unsigned char speed_L = 0;
//  unsigned char id;
//  unsigned char panjangData = 4;
//  unsigned char jumlahServo = 19;
//  unsigned char bufferDataTx[103];
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
//  position_H = outServo[0][0] >> 8;
//  position_L = outServo[0][0] & 0xff;
//  id = 1;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[7] = id;
//  bufferDataTx[8] = position_L;
//  bufferDataTx[9] = position_H;
//  bufferDataTx[10] = speed_L;
//  bufferDataTx[11] = speed_H;
//  //######## SERVO 01 ##################//
//  position_H = outServo[0][1] >> 8;
//  position_L = outServo[0][1] & 0xff;
//  id = 2;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[12] = id;
//  bufferDataTx[13] = position_L;
//  bufferDataTx[14] = position_H;
//  bufferDataTx[15] = speed_L;
//  bufferDataTx[16] = speed_H;
//  //######## SERVO 02 ##################//
//  position_H = outServo[0][2] >> 8;
//  position_L = outServo[0][2] & 0xff;
//  id = 3;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[17] = id;
//  bufferDataTx[18] = position_L;
//  bufferDataTx[19] = position_H;
//  bufferDataTx[20] = speed_L;
//  bufferDataTx[21] = speed_H;
//  //######## SERVO 03 ##################//
//  position_H = outServo[1][0] >> 8;
//  position_L = outServo[1][0] & 0xff;
//  id = 4;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[22] = id;
//  bufferDataTx[23] = position_L;
//  bufferDataTx[24] = position_H;
//  bufferDataTx[25] = speed_L;
//  bufferDataTx[26] = speed_H;
//  //######## SERVO 04 ##################//
//  position_H = outServo[1][1] >> 8;
//  position_L = outServo[1][1] & 0xff;
//  id = 5;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[27] = id;
//  bufferDataTx[28] = position_L;
//  bufferDataTx[29] = position_H;
//  bufferDataTx[30] = speed_L;
//  bufferDataTx[31] = speed_H;
//  //######## SERVO 05 ##################//
//  position_H = outServo[1][2] >> 8;
//  position_L = outServo[1][2] & 0xff;
//  id = 6;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[32] = id;
//  bufferDataTx[33] = position_L;
//  bufferDataTx[34] = position_H;
//  bufferDataTx[35] = speed_L;
//  bufferDataTx[36] = speed_H;
//  //######## SERVO 06 ##################//
//  position_H = outServo[2][0] >> 8;
//  position_L = outServo[2][0] & 0xff;
//  id = 7;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[37] = id;
//  bufferDataTx[38] = position_L;
//  bufferDataTx[39] = position_H;
//  bufferDataTx[40] = speed_L;
//  bufferDataTx[41] = speed_H;
//  //######## SERVO 07 ##################//
//  position_H = outServo[2][1] >> 8;
//  position_L = outServo[2][1] & 0xff;
//  id = 8;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[42] = id;
//  bufferDataTx[43] = position_L;
//  bufferDataTx[44] = position_H;
//  bufferDataTx[45] = speed_L;
//  bufferDataTx[46] = speed_H;
//  //######## SERVO 08 ##################//
//  position_H = outServo[2][2] >> 8;
//  position_L = outServo[2][2] & 0xff;
//  id = 9;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[47] = id;
//  bufferDataTx[48] = position_L;
//  bufferDataTx[49] = position_H;
//  bufferDataTx[50] = speed_L;
//  bufferDataTx[51] = speed_H;
//  //######## SERVO 09 ##################//
//  position_H = outServo[3][0] >> 8;
//  position_L = outServo[3][0] & 0xff;
//  id = 10;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[52] = id;
//  bufferDataTx[53] = position_L;
//  bufferDataTx[54] = position_H;
//  bufferDataTx[55] = speed_L;
//  bufferDataTx[56] = speed_H;
//  //######## SERVO 10 ##################//
//  position_H = outServo[3][1] >> 8;
//  position_L = outServo[3][1] & 0xff;
//  id = 11;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[57] = id;
//  bufferDataTx[58] = position_L;
//  bufferDataTx[59] = position_H;
//  bufferDataTx[60] = speed_L;
//  bufferDataTx[61] = speed_H;
//  //######## SERVO 11 ##################//
//  position_H = outServo[3][2] >> 8;
//  position_L = outServo[3][2] & 0xff;
//  id = 12;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[62] = id;
//  bufferDataTx[63] = position_L;
//  bufferDataTx[64] = position_H;
//  bufferDataTx[65] = speed_L;
//  bufferDataTx[66] = speed_H;
//  //######## SERVO 12 ##################//
//  position_H = outServo[4][0] >> 8;
//  position_L = outServo[4][0] & 0xff;
//  id = 13;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[67] = id;
//  bufferDataTx[68] = position_L;
//  bufferDataTx[69] = position_H;
//  bufferDataTx[70] = speed_L;
//  bufferDataTx[71] = speed_H;
//  //######## SERVO 13 ##################//
//  position_H = outServo[4][1] >> 8;
//  position_L = outServo[4][1] & 0xff;
//  id = 14;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[72] = id;
//  bufferDataTx[73] = position_L;
//  bufferDataTx[74] = position_H;
//  bufferDataTx[75] = speed_L;
//  bufferDataTx[76] = speed_H;
//  //######## SERVO 14 ##################//
//  position_H = outServo[4][2] >> 8;
//  position_L = outServo[4][2] & 0xff;
//  id = 15;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[77] = id;
//  bufferDataTx[78] = position_L;
//  bufferDataTx[79] = position_H;
//  bufferDataTx[80] = speed_L;
//  bufferDataTx[81] = speed_H;
//  //######## SERVO 15 ##################//
//  position_H = outServo[5][0] >> 8;
//  position_L = outServo[5][0] & 0xff;
//  id = 16;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[82] = id;
//  bufferDataTx[83] = position_L;
//  bufferDataTx[84] = position_H;
//  bufferDataTx[85] = speed_L;
//  bufferDataTx[86] = speed_H;
//  //######## SERVO 16 ##################//
//  position_H = outServo[5][1] >> 8;
//  position_L = outServo[5][1] & 0xff;
//  id = 17;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[87] = id;
//  bufferDataTx[88] = position_L;
//  bufferDataTx[89] = position_H;
//  bufferDataTx[90] = speed_L;
//  bufferDataTx[91] = speed_H;
//  //######## SERVO 17 ##################//
//  position_H = outServo[5][2] >> 8;
//  position_L = outServo[5][2] & 0xff;
//  id = 18;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[92] = id;
//  bufferDataTx[93] = position_L;
//  bufferDataTx[94] = position_H;
//  bufferDataTx[95] = speed_L;
//  bufferDataTx[96] = speed_H;
//  //######## SERVO 18 ##################//
//  position_H = sdtDyn >> 8;
//  position_L = sdtDyn & 0xff;
//  id = 19;
//  checksum += position_L + position_H + speed_L + speed_H + id;
//  bufferDataTx[97] = id;
//  bufferDataTx[98] = position_L;
//  bufferDataTx[99] = position_H;
//  bufferDataTx[100] = speed_L;
//  bufferDataTx[101] = speed_H;
//  //############# checksum ##############//
//  checksum = (~checksum) & 0xFF; //only use lower bytes hal.49
//  bufferDataTx[102] = checksum;
//  kirimData(103, bufferDataTx);
//}
//
//void kirimData(char jumlahData, unsigned char *packet) {
//  for (int i = 0; i < jumlahData; i++) {
//    Serial2.write(packet[i]);
//  }
//}

void KirimIntruksiGerak(int speedss) {
  unsigned long checksum = 0;
  unsigned char position_H = 0;
  unsigned char position_L = 0;
  unsigned char speed_H = 0;
  unsigned char speed_L = 0;
  unsigned char id;
  unsigned char panjangData = 4;
  unsigned char jumlahServo = 6 * 3;
  unsigned char bufferDataTx[98];
  unsigned char LENGTH = (panjangData + 1) * jumlahServo + 4;//19; // (panjang data +1) x jumlah servo + 4 ===>>> lighat manual rx 28 halaman 37
  speed_H = speedss >> 8;    //high adresses
  speed_L = speedss & 0xff;  //low addresses karena pengiriman  data harus 16 bit tetapi dipecah menjadi 2 yaitu masing2 8bit
  checksum = 0xFE + LENGTH + 0x83 + 0x1E + panjangData;
  //############# HEADER ############//
  bufferDataTx[0] = 0xFF;
  bufferDataTx[1] = 0xFF;
  //######## BROADCAST INTRUCTION ############//
  bufferDataTx[2] = 0xFE;
  //######## LENGTH ############//
  bufferDataTx[3] = LENGTH;
  //######## SYNC WRITE ############//
  bufferDataTx[4] = 0x83;
  //######## FISRT ADDRESS ############//
  bufferDataTx[5] = 0x1E;
  //######## LENGTH OF DATA ############//
  bufferDataTx[6] = panjangData;
  //######## SERVO 00 ##################//
  position_H = outServo[0][0] >> 8;
  position_L = outServo[0][0] & 0xff;
  id = 1;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[7] = id;
  bufferDataTx[8] = position_L;
  bufferDataTx[9] = position_H;
  bufferDataTx[10] = speed_L;
  bufferDataTx[11] = speed_H;
  //######## SERVO 01 ##################//
  position_H = outServo[0][1] >> 8;
  position_L = outServo[0][1] & 0xff;
  id = 2;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[12] = id;
  bufferDataTx[13] = position_L;
  bufferDataTx[14] = position_H;
  bufferDataTx[15] = speed_L;
  bufferDataTx[16] = speed_H;
  //######## SERVO 02 ##################//
  position_H = outServo[0][2] >> 8;
  position_L = outServo[0][2] & 0xff;
  id = 3;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[17] = id;
  bufferDataTx[18] = position_L;
  bufferDataTx[19] = position_H;
  bufferDataTx[20] = speed_L;
  bufferDataTx[21] = speed_H;
  //######## SERVO 03 ##################//
  position_H = outServo[1][0] >> 8;
  position_L = outServo[1][0] & 0xff;
  id = 4;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[22] = id;
  bufferDataTx[23] = position_L;
  bufferDataTx[24] = position_H;
  bufferDataTx[25] = speed_L;
  bufferDataTx[26] = speed_H;
  //######## SERVO 04 ##################//
  position_H = outServo[1][1] >> 8;
  position_L = outServo[1][1] & 0xff;
  id = 5;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[27] = id;
  bufferDataTx[28] = position_L;
  bufferDataTx[29] = position_H;
  bufferDataTx[30] = speed_L;
  bufferDataTx[31] = speed_H;
  //######## SERVO 05 ##################//
  position_H = outServo[1][2] >> 8;
  position_L = outServo[1][2] & 0xff;
  id = 6;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[32] = id;
  bufferDataTx[33] = position_L;
  bufferDataTx[34] = position_H;
  bufferDataTx[35] = speed_L;
  bufferDataTx[36] = speed_H;
  //######## SERVO 06 ##################//
  position_H = outServo[2][0] >> 8;
  position_L = outServo[2][0] & 0xff;
  id = 7;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[37] = id;
  bufferDataTx[38] = position_L;
  bufferDataTx[39] = position_H;
  bufferDataTx[40] = speed_L;
  bufferDataTx[41] = speed_H;
  //######## SERVO 07 ##################//
  position_H = outServo[2][1] >> 8;
  position_L = outServo[2][1] & 0xff;
  id = 8;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[42] = id;
  bufferDataTx[43] = position_L;
  bufferDataTx[44] = position_H;
  bufferDataTx[45] = speed_L;
  bufferDataTx[46] = speed_H;
  //######## SERVO 08 ##################//
  position_H = outServo[2][2] >> 8;
  position_L = outServo[2][2] & 0xff;
  id = 9;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[47] = id;
  bufferDataTx[48] = position_L;
  bufferDataTx[49] = position_H;
  bufferDataTx[50] = speed_L;
  bufferDataTx[51] = speed_H;
  //######## SERVO 09 ##################//
  position_H = outServo[3][0] >> 8;
  position_L = outServo[3][0] & 0xff;
  id = 10;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[52] = id;
  bufferDataTx[53] = position_L;
  bufferDataTx[54] = position_H;
  bufferDataTx[55] = speed_L;
  bufferDataTx[56] = speed_H;
  //######## SERVO 10 ##################//
  position_H = outServo[3][1] >> 8;
  position_L = outServo[3][1] & 0xff;
  id = 11;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[57] = id;
  bufferDataTx[58] = position_L;
  bufferDataTx[59] = position_H;
  bufferDataTx[60] = speed_L;
  bufferDataTx[61] = speed_H;
  //######## SERVO 11 ##################//
  position_H = outServo[3][2] >> 8;
  position_L = outServo[3][2] & 0xff;
  id = 12;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[62] = id;
  bufferDataTx[63] = position_L;
  bufferDataTx[64] = position_H;
  bufferDataTx[65] = speed_L;
  bufferDataTx[66] = speed_H;
  //######## SERVO 12 ##################//
  position_H = outServo[4][0] >> 8;
  position_L = outServo[4][0] & 0xff;
  id = 13;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[67] = id;
  bufferDataTx[68] = position_L;
  bufferDataTx[69] = position_H;
  bufferDataTx[70] = speed_L;
  bufferDataTx[71] = speed_H;
  //######## SERVO 13 ##################//
  position_H = outServo[4][1] >> 8;
  position_L = outServo[4][1] & 0xff;
  id = 14;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[72] = id;
  bufferDataTx[73] = position_L;
  bufferDataTx[74] = position_H;
  bufferDataTx[75] = speed_L;
  bufferDataTx[76] = speed_H;
  //######## SERVO 14 ##################//
  position_H = outServo[4][2] >> 8;
  position_L = outServo[4][2] & 0xff;
  id = 15;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[77] = id;
  bufferDataTx[78] = position_L;
  bufferDataTx[79] = position_H;
  bufferDataTx[80] = speed_L;
  bufferDataTx[81] = speed_H;
  //######## SERVO 15 ##################//
  position_H = outServo[5][0] >> 8;
  position_L = outServo[5][0] & 0xff;
  id = 16;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[82] = id;
  bufferDataTx[83] = position_L;
  bufferDataTx[84] = position_H;
  bufferDataTx[85] = speed_L;
  bufferDataTx[86] = speed_H;
  //######## SERVO 16 ##################//
  position_H = outServo[5][1] >> 8;
  position_L = outServo[5][1] & 0xff;
  id = 17;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[87] = id;
  bufferDataTx[88] = position_L;
  bufferDataTx[89] = position_H;
  bufferDataTx[90] = speed_L;
  bufferDataTx[91] = speed_H;
  //######## SERVO 17 ##################//
  position_H = outServo[5][2] >> 8;
  position_L = outServo[5][2] & 0xff;
  id = 18;
  checksum += position_L + position_H + speed_L + speed_H + id;
  bufferDataTx[92] = id;
  bufferDataTx[93] = position_L;
  bufferDataTx[94] = position_H;
  bufferDataTx[95] = speed_L;
  bufferDataTx[96] = speed_H;
  //############# checksum ##############//
  checksum = (~checksum) & 0xFF; //only use lower bytes hal.49
  bufferDataTx[97] = checksum;
  kirimData(98, bufferDataTx);
}

void kirimData(char jumlahData, unsigned char *packet) {
  for (int i = 0; i < jumlahData; i++) {
    Serial2.write(packet[i]);
  }
}
