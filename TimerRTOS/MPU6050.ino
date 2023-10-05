void verify_nano() {
  while (true) {
    String status = "";
    if (Serial3.available()) {
      while (Serial3.available()) {
        char c = Serial3.read();
        status += c;
      }
    }
    if (status == "200") {
      Serial.println("Connection successful");
      break;
    } else if (status == "404") {
      Serial.println("Connection failed");
      while (1);
    } else {
      Serial.println("Connection pending");
    }
    delay(200);
  }
}

void read_MPU() {
  Serial3.write('1'); // trigger ngirim data

  String status = "";
  String yawS, pitchS, rollS = ""; // Menyimpan data yaw dan pitch yang diterima
  int i = -1;

  while (Serial3.available()) {
    // Mulai membaca data
    if (i == -1) {
      char c = Serial3.read();
      if (c == '|') {
        i += 1;
      } else {
        status += c;
      }
    } else if (i == 0) {
      // Make sure status code is correct
      if (status != "200") {
        Serial.println("Read Invalid!");
        return;
      }

      char c = Serial3.read();
      if (c == '|') {
        i += 1;
      } else {
        yawS += c;
      }
    } else if (i == 1) {
      char c = Serial3.read();

      if (c == '|') {
        i += 1;
      } else {
        pitchS += c;
      }
    } else {
      char c = Serial3.read();
      rollS += c;
    }
  }

  yaw = yawS.toInt();
  pitch = pitchS.toInt();
  roll = rollS.toInt();

  Serial.print("YAW: ");
  Serial.println(yaw);
  Serial.print("PITCH:");
  Serial.println(pitch);
  Serial.print("ROLL:");
  Serial.println(roll);
}
