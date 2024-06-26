void read_MPU() {
  Serial3.write('1');
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
          Serial.println("Invalid MPU Value");  // Karena value yaw maksimal 360, jika lebih dari 3 digit maka Serial yang diterima bukan value YPR.
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
    yaw = yawT.toInt();
    pitch = pitchT.toInt();
    roll = rollT.toInt();
    //    Serial.print("ypr: \t");
    //    Serial.print(yawT);
    //    Serial.print("\t");
    //    Serial.print(pitchT);
    //    Serial.print("\t");
    //    Serial.println(rollT);
    //    Serial.println(yaw);
  }
}

// void read_MPU() {
//   Serial3.write('1');

//   // // Wait for response
//   // while (!Serial3.available()) {
//   //   vTaskDelay(20 / portTICK_PERIOD_MS);  // Optional small delay to prevent busy waiting
//   // }

//   String data = Serial3.readStringUntil('\n');

//   // Split the data into yaw, pitch, and roll
//   int firstDelimiter = data.indexOf('|');
//   int secondDelimiter = data.indexOf('|', firstDelimiter + 1);

//   if (firstDelimiter != -1 && secondDelimiter != -1) {
//     String yawT = data.substring(0, firstDelimiter);
//     String pitchT = data.substring(firstDelimiter + 1, secondDelimiter);
//     String rollT = data.substring(secondDelimiter + 1);

//     // Validate and convert to integer
//     if (yawT.length() <= 3 && pitchT.length() <= 3 && (rollT.length() <= 3 || (rollT.length() == 4 && rollT[0] == '-'))) {
//       yaw = yawT.toInt();
//       pitch = pitchT.toInt();
//       roll = rollT.toInt();

//       // Print yaw, pitch, and roll values to Serial Monitor
//       // Serial.print("ypr: \t");
//       // Serial.print(yaw);
//       // Serial.print("\t");
//       // Serial.print(pitch);
//       // Serial.print("\t");
//       // Serial.println(roll);
//     } else {
//       Serial.println("Invalid MPU Value");
//     }
//   } else {
//     Serial.println("Invalid MPU Data");
//   }
// }


// void read_MPUv2() {
//   Serial3.write('1');

//   // Wait for response
//   while (!Serial3.available()) {
//     delay(10);  // Optional small delay to prevent busy waiting
//   }

//   String data = Serial3.readStringUntil('\n');

//   // Split the data into yaw, pitch, and roll
//   int firstDelimiter = data.indexOf('|');
//   int secondDelimiter = data.indexOf('|', firstDelimiter + 1);

//   if (firstDelimiter != -1 && secondDelimiter != -1) {
//     String yawT = data.substring(0, firstDelimiter);
//     String pitchT = data.substring(firstDelimiter + 1, secondDelimiter);
//     String rollT = data.substring(secondDelimiter + 1);

//     // Validate and convert to integer
//     if (yawT.length() <= 3 && pitchT.length() <= 3 && (rollT.length() <= 3 || (rollT.length() == 4 && rollT[0] == '-'))) {
//       yaw = yawT.toInt();
//       pitch = pitchT.toInt();
//       roll = rollT.toInt();

//       // Print yaw, pitch, and roll values to Serial Monitor
//       // Serial.print("ypr: \t");
//       // Serial.print(yaw);
//       // Serial.print("\t");
//       // Serial.print(pitch);
//       // Serial.print("\t");
//       // Serial.println(roll);
//     } else {
//       Serial.println("Invalid MPU Value");
//     }
//   } else {
//     Serial.println("Invalid MPU Data");
//   }
// }