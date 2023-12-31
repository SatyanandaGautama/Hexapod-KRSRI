void read_maix() {
  //  Serial.println("Trigger Maix");
  Serial6.write('1'); // trigger maix buat ngirim data
  //  Serial.println("Data Masuk");
  //  Serial.println(Serial6.available());
  if (Serial6.available()) {
    if (Serial6.read() == '*') {
      int charPos = 0;
      String x_in = "", y_in = "", area_in = "";
      while (1) {
        if (Serial6.available()) {
          char inChar = Serial6.read();
          //            Serial.print(inChar);
          if (inChar == ',') {
            charPos += 1; continue;
          }
          else if (inChar == '#') {
            break;
          }
          if (charPos == 0) x_in = x_in + inChar;
          else if (charPos == 1) y_in = y_in + inChar;
          else if (charPos == 2) area_in = area_in + inChar;
        }
      }
      pict_x = x_in.toInt();
      pict_y = y_in.toInt();
      area = area_in.toInt();
      Serial.print("Pict X : ");
      Serial.println(pict_x);
      Serial.print("Area : ");
      Serial.println(area);
      //      Serial6.flush();
    }
  }
  //else {
  //    while (!Serial6.available()) {
  //      command("standby", 99, false);
  //      Serial6.write('1');
  //      vTaskDelay(50 / portTICK_PERIOD_MS);
  //    }
  //    Serial6.flush();
  //  }
  vTaskDelay(10 / portTICK_PERIOD_MS);
}
