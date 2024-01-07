float moveServo(float sdtAwal, float sdtTujuan, float kecepatan) {
  if (t <= 180) {
    Inc = 180 / kecepatan;
    act = ((sdtTujuan - sdtAwal) / 10) * 2;
    sdtServo = sdtAwal + (((act * t) / 360)) * 10;
    t += Inc;
    if (t > 180)t = 0;
    return sdtServo;
  }
} //Kecepatan (Jumlah Titik) = Kecepatan Saat body maju ambil korban.
