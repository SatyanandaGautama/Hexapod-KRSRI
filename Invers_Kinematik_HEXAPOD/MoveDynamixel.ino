void kiri_bawah(float k, float l, float m) {
  //dxl.setGoalVelocity(1, s, UNIT_RAW);
  dxl.setGoalPosition(1, k, UNIT_DEGREE);
  //dxl.setGoalVelocity(2, s, UNIT_RAW);
  dxl.setGoalPosition(2, l, UNIT_DEGREE);
  //dxl.setGoalVelocity(3, s, UNIT_RAW);
  dxl.setGoalPosition(3, m, UNIT_DEGREE);
}

void kiri_tengah(float n, float o, float p) {
  //dxl.setGoalVelocity(1, s, UNIT_RAW);
  dxl.setGoalPosition(4, n, UNIT_DEGREE);
  //dxl.setGoalVelocity(2, s, UNIT_RAW);
  dxl.setGoalPosition(5, o, UNIT_DEGREE);
  //dxl.setGoalVelocity(3, s, UNIT_RAW);
  dxl.setGoalPosition(6, p, UNIT_DEGREE);
}

void kiri_atas(float h, float i, float j) {
  //dxl.setGoalVelocity(10, s, UNIT_RAW);
  dxl.setGoalPosition(7, h, UNIT_DEGREE);
  //dxl.setGoalVelocity(11, s, UNIT_RAW);
  dxl.setGoalPosition(8, i, UNIT_DEGREE);
  //dxl.setGoalVelocity(12, s, UNIT_RAW);
  dxl.setGoalPosition(9, j, UNIT_DEGREE);
}


void kanan_atas(float a, float b, float c) {
  //dxl.setGoalVelocity(7, s, UNIT_RAW);
  dxl.setGoalPosition(10, a, UNIT_DEGREE);
  //dxl.setGoalVelocity(8, s, UNIT_RAW);
  dxl.setGoalPosition(11, b, UNIT_DEGREE);
  //dxl.setGoalVelocity(9, s, UNIT_RAW);
  dxl.setGoalPosition(12, c, UNIT_DEGREE);
}

void kanan_tengah(float yw, float pt, float rl) {
  //dxl.setGoalVelocity(1, s, UNIT_RAW);
  dxl.setGoalPosition(14, yw, UNIT_DEGREE);
  //dxl.setGoalVelocity(2, s, UNIT_RAW);
  dxl.setGoalPosition(15, pt, UNIT_DEGREE);
  //dxl.setGoalVelocity(3, s, UNIT_RAW);
  dxl.setGoalPosition(16, rl, UNIT_DEGREE);
}

void kanan_bawah(float d, float e, float f) {
  //dxl.setGoalVelocity(4, s, UNIT_RAW);
  dxl.setGoalPosition(17, d, UNIT_DEGREE);
  //dxl.setGoalVelocity(5, s, UNIT_RAW);
  dxl.setGoalPosition(18, e, UNIT_DEGREE);
  //dxl.setGoalVelocity(6, s, UNIT_RAW);
  dxl.setGoalPosition(19, f, UNIT_DEGREE);
}
