void read_MPU() {
  Serial3.write('1');
  //  Serial3.flush();
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
    //    Serial.print("ypr: \t");
    //    Serial.print(yawT);
    //    Serial.print("\t");
    //    Serial.print(pitchT);
    //    Serial.print("\t");
    //    Serial.println(rollT);
    //    Serial3.flush();

    yaw = yawT.toInt();
    pitch = pitchT.toInt();
    roll = rollT.toInt();
    Serial.println(yaw);
  }
}
