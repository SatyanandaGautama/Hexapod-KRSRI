    // // afterTangga();
    // // bodyKiri.write(110);
    // // while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFKiri();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Kiri");
    // //   Serial.println(TOFKiri);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }

    // // xSemaphoreTake(mutex, portMAX_DELAY);
    // // bodyKiri.write(0);
    // // xSemaphoreGive(mutex);
    // // while (1) {    while (1) {
    //   // afterTangga();
    //   // Standby();
    //   // // bodyKiri.write(130);
    //   // // while (1) {
    //   // //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   // //   bacaTOFKiri();
    //   // //   xSemaphoreGive(mutex);
    //   // //   Serial.print("TOF Kiri");
    //   // //   Serial.println(TOFKiri);
    //   // // }

    //   // // xSemaphoreTake(mutex, portMAX_DELAY);
    //   // // bodyKiri.write(0);
    //   // // xSemaphoreGive(mutex);
    //   // while (1) {
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFDepan();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Depan");
    //   //   Serial.println(TOFDepan);
    //   // }


    //   // ROTASI KE KIRI

    //   // heightFR = -89;
    //   // heightRM = -93;
    //   // heightBR = -98;
    //   // heightFL = -89;
    //   // heightLM = -93;
    //   // heightBL = -98;
    //   // Standby();
    //   // while (1) {
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFDepan();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Depan");
    //   //   Serial.println(TOFDepan);
    //   // }



    //   // ROTASI -90 KE KIRI
    //   bodyKanan.write(170);
    //   filtered_IR = 0;
    //   heightFR = -72;
    //   heightRM = -72;
    //   heightBR = -72;
    //   heightFL = -100;
    //   heightLM = -100;
    //   heightBL = -100;
    //   Standby();
    //   while (1) {
    //     // xSemaphoreTake(mutex, portMAX_DELAY);
    //     // bacaTOFKanan();
    //     // xSemaphoreGive(mutex);
    //     // Serial.print("TOF Kanan");
    //     // Serial.println(TOFKanan);
    //     // xSemaphoreTake(mutex, portMAX_DELAY);
    //     // bacaTOFBelakang();
    //     // xSemaphoreGive(mutex);
    //     // Serial.print("TOF Belakang");
    //     // Serial.println(TOFBelakang);
    //     xSemaphoreTake(mutex, portMAX_DELAY);
    //     read_MPU();
    //     vTaskDelay(15 / portTICK_PERIOD_MS);
    //     xSemaphoreGive(mutex);
    //   }



    //   // xSemaphoreTake(mutex, portMAX_DELAY);
    //   // bodyKanan.write(180);
    //   // xSemaphoreGive(mutex);
    //   // while (1) {
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFBelakang();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Belakang");
    //   //   Serial.println(TOFBelakang);
    //   // }



    //   // bodyKanan.write(0);
    //   // while (1) {
    //   //   ButtonState = digitalRead(Button);
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFKanan();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Kanan");
    //   //   Serial.println(TOFKanan);
    //   //   if (ButtonState == 0) {
    //   //     break;
    //   //   }
    //   // }



    //   // bodyKanan.write(180);

    //   // while (1) {
    //   //   ButtonState = digitalRead(Button);
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFBelakang();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Belakang");
    //   //   Serial.println(TOFBelakang);
    //   //   if (ButtonState == 0) {
    //   //     break;
    //   //   }
    //   // }



    //   // bodyKanan.write(70);
    //   // while (1) {
    //   //   ButtonState = digitalRead(Button);
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFKanan();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Kanan");
    //   //   Serial.println(TOFKanan);
    //   //   if (ButtonState == 0) {
    //   //     break;
    //   //   }
    //   // }


    //   // bodyKanan.write(180);
    //   // //SETELAH lONGSOR

    //   // offsetCX[0] = -5;
    //   // offsetCX[1] = 5;
    //   // offsetCX[2] = -5;
    //   // offsetCX[3] = 5;
    //   // while (1) {
    //   //   ButtonState = digitalRead(Button);
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFDepan();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Depan");
    //   //   Serial.println(TOFDepan);
    //   //   if (ButtonState == 0) {
    //   //     break;
    //   //   }
    //   // }


    //   // offsetCX[0] = 0;  //Coxa BL //25
    //   // offsetCX[1] = 0;  //Coxa FL //-22
    //   // offsetCX[2] = 0;  //Coxa BL //25
    //   // offsetCX[3] = 0;  //Coxa FL //-22

    //   // heightFR = -92;
    //   // heightRM = -92;
    //   // heightBR = -92;
    //   // heightFL = -92;
    //   // heightLM = -92;
    //   // heightBL = -92;
    //   // Standby();


    //   // while (1) {
    //   //   ButtonState = digitalRead(Button);
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFBelakang();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Belakang");
    //   //   Serial.println(TOFBelakang);
    //   //   if (ButtonState == 0) {
    //   //     break;
    //   //   }
    //   // }



    //   // while (1) {
    //   //   ButtonState = digitalRead(Button);
    //   //   xSemaphoreTake(mutex, portMAX_DELAY);
    //   //   bacaTOFBelakang();
    //   //   xSemaphoreGive(mutex);
    //   //   Serial.print("TOF Belakang");
    //   //   Serial.println(TOFBelakang);
    //   //   if (ButtonState == 0) {
    //   //     break;
    //   //   }
    //   // }
    // }
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFDepan();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Depan");
    // //   Serial.println(TOFDepan);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }

    // // heightFR = -89;
    // // heightRM = -93;
    // // heightBR = -98;
    // // heightFL = -89;
    // // heightLM = -93;
    // // heightBL = -98;
    
    // // while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFDepan();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Depan");
    // //   Serial.println(TOFDepan);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

   
    // // heightFR = -89;
    // // heightRM = -93;
    // // heightBR = -98;
    // // heightFL = -89;
    // // heightLM = -93;
    // // heightBL = -98;
    
    // // bodyKanan.write(0);
    // // filtered_IR = 0;
    // // heightFR = -72;
    // // heightRM = -72;
    // // heightBR = -72;
    // // heightFL = -100;
    // // heightLM = -100;
    // // heightBL = -100;
    // // while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFKanan();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Kanan");
    // //   Serial.println(TOFKanan);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

    
    // // xSemaphoreTake(mutex, portMAX_DELAY);
    // // bodyKanan.write(180);
    // // xSemaphoreGive(mutex);
    // // while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFBelakang();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Belakang");
    // //   Serial.println(TOFBelakang);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

    
    // // bodyKanan.write(0);
    // // while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFKanan();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Kanan");
    // //   Serial.println(TOFKanan);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

    
    // // bodyKanan.write(180);

    // // while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFBelakang();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Belakang");
    // //   Serial.println(TOFBelakang);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

   
    // // bodyKanan.write(70);
    // // while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFKanan();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Kanan");
    // //   Serial.println(TOFKanan);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

    // // bodyKanan.write(180);
   
    // // offsetCX[0] = -5;
    // // offsetCX[1] = 5;
    // // offsetCX[2] = -5;
    // // offsetCX[3] = 5;
    // // while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFDepan();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Depan");
    // //   Serial.println(TOFDepan);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

    // // offsetCX[0] = 0;  //Coxa BL //25
    // // offsetCX[1] = 0;  //Coxa FL //-22
    // // offsetCX[2] = 0;  //Coxa BL //25
    // // offsetCX[3] = 0;  //Coxa FL //-22
   
    // // heightFR = -92;
    // // heightRM = -92;
    // // heightBR = -92;
    // // heightFL = -92;
    // // heightLM = -92;
    // // heightBL = -92;
    
    // //   while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFBelakang();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Belakang");
    // //   Serial.println(TOFBelakang);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

    
    // //   while (1) {
    // //   ButtonState = digitalRead(Button);
    // //   xSemaphoreTake(mutex, portMAX_DELAY);
    // //   bacaTOFBelakang();
    // //   xSemaphoreGive(mutex);
    // //   Serial.print("TOF Belakang");
    // //   Serial.println(TOFBelakang);
    // //   if (ButtonState == 0) {
    // //     break;
    // //   }
    // // }
    

    










