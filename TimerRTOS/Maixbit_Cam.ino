//void read_maix() {
//  if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
//  else if (!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
//  else if (!huskylens.available()) Serial.println(F("No block or arrow appears on the screen!"));
//  else
//  {
//    result = huskylens.read();
//    //    Serial.print("X :");
//    //    Serial.println(result.xCenter);
//    //    Serial.print("Y :");
//    //    Serial.println(result.yCenter);
//    //    printResult(result);
//    //    while (huskylens.available())
//    //    {
//    //      HUSKYLENSResult result = huskylens.read();
//    //      printResult(result);
//    //    }
//  }
//  vTaskDelay(2 / portTICK_PERIOD_MS);
//}
