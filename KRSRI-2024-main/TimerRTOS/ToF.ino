//void SetupSingleShot(VL53L0X& sensor) {
//  int status;
//  uint8_t VhvSettings;
//  uint8_t PhaseCal;
//  uint32_t refSpadCount;
//  uint8_t isApertureSpads;
//
//  status = sensor.StaticInit();
//  if (status) {
//    Serial.println("StaticInit sensor failed");
//  }
//
//  status = sensor.PerformRefCalibration(&VhvSettings, &PhaseCal);
//  if (status) {
//    Serial.println("PerformRefCalibration sensor failed");
//  }
//
//  status = sensor.PerformRefSpadManagement(&refSpadCount, &isApertureSpads);
//  if (status) {
//    Serial.println("PerformRefSpadManagement sensor failed");
//  }
//
//  status = sensor.SetDeviceMode(VL53L0X_DEVICEMODE_SINGLE_RANGING);  // Setup in single ranging mode
//  if (status) {
//    Serial.println("SetDeviceMode sensor failed");
//  }
//
//  status = sensor.SetMeasurementTimingBudgetMicroSeconds(20000);
//  if (status) {
//    Serial.println("SetMeasurementTimingBudgetMicroSeconds sensor failed");
//  }
//
//  Serial.print("Sensor ke : ");
//  Serial.println(s);
//  s++;
//}
//
//void bacaTOFDepan() {
//  // Reading sensor 1
//  status = 1;
//  while (status == 1) {
//    sensor_vl53l0x_1.StartMeasurement();
//    VL53L0X_RangingMeasurementData_t pRangingMeasurementData_1;
//    NewDataReady_1 = 0;
//    status = sensor_vl53l0x_1.GetMeasurementDataReady(&NewDataReady_1);
//    if (status) {
//      Serial.println("GetMeasurementDataReady sensor 1 failed");
//    } else {
//      status = 0;
//    }
//  }
//  if (NewDataReady_1) {
//    status = sensor_vl53l0x_1.GetRangingMeasurementData(&pRangingMeasurementData_1);
//    if (status) {
//      Serial.println("GetRangingMeasurementData sensor 1 failed");
//    }
//
//    status = sensor_vl53l0x_1.ClearInterruptMask(0);
//    if (status) {
//      Serial.println("ClearInterruptMask sensor 1 failed");
//    }
//
//    if (pRangingMeasurementData_1.RangeStatus == 0) {
//      // we have a valid range.
//      distance_top_1 = pRangingMeasurementData_1.RangeMilliMeter;
//    } else {
//      distance_top_1 = 1200;
//    }
//    TOFDepan = distance_top_1 / 10.0;
//    // Serial.print("distance Depan : ");
//    // Serial.println(TOFDepan);
//  }
//}
//
//
//void bacaTOFKanan() {
//  // Reading sensor 2
//  status = 1;
//  while (status == 1) {
//    sensor_vl53l0x_2.StartMeasurement();
//    VL53L0X_RangingMeasurementData_t pRangingMeasurementData_2;
//    NewDataReady_2 = 0;
//    status = sensor_vl53l0x_2.GetMeasurementDataReady(&NewDataReady_2);
//    if (status) {
//      Serial.println("GetMeasurementDataReady sensor 2 failed");
//    } else {
//      status = 0;
//    }
//  }
//
//  if (NewDataReady_2) {
//
//    status = sensor_vl53l0x_2.GetRangingMeasurementData(&pRangingMeasurementData_2);
//    if (status) {
//      Serial.println("GetRangingMeasurementData sensor 2 failed");
//    }
//
//    status = sensor_vl53l0x_2.ClearInterruptMask(0);
//    if (status) {
//      Serial.println("ClearInterruptMask sensor 2 failed");
//    }
//
//    if (pRangingMeasurementData_2.RangeStatus == 0) {
//      // we have a valid range.
//      distance_top_2 = pRangingMeasurementData_2.RangeMilliMeter;
//    } else {
//      distance_top_2 = 1200;
//    }
//
//    TOFKanan = distance_top_2 / 10.0;
//    // Serial.print("distance Kanan : ");
//    // Serial.println(TOFKanan);
//  }
//}
//
//void bacaTOFKiri() {
//  // Reading sensor 3
//  status = 1;
//  while (status == 1) {
//    sensor_vl53l0x_3.StartMeasurement();
//    VL53L0X_RangingMeasurementData_t pRangingMeasurementData_3;
//    NewDataReady_3 = 0;
//    status = sensor_vl53l0x_3.GetMeasurementDataReady(&NewDataReady_3);
//    if (status) {
//      Serial.println("GetMeasurementDataReady sensor 3 failed");
//    } else {
//      status = 0;
//    }
//  }
//
//  if (NewDataReady_3) {
//
//    status = sensor_vl53l0x_3.GetRangingMeasurementData(&pRangingMeasurementData_3);
//    if (status) {
//      Serial.println("GetRangingMeasurementData sensor 3 failed");
//    }
//
//    status = sensor_vl53l0x_3.ClearInterruptMask(0);
//    if (status) {
//      Serial.println("ClearInterruptMask sensor 3 failed");
//    }
//
//    if (pRangingMeasurementData_3.RangeStatus == 0) {
//      // we have a valid range.
//      distance_top_3 = pRangingMeasurementData_3.RangeMilliMeter;
//    } else {
//      distance_top_3 = 1200;
//    }
//
//    TOFKiri = distance_top_3 / 10.0;
//    // Serial.print("distance Kiri : ");
//    // Serial.println(TOFKiri);
//  }
//}
//
//void bacaTOFBelakang() {
//
//  status = 1;
//  while (status == 1) {
//    sensor_vl53l0x_4.StartMeasurement();
//    VL53L0X_RangingMeasurementData_t pRangingMeasurementData_4;
//    NewDataReady_4 = 0;
//    status = sensor_vl53l0x_4.GetMeasurementDataReady(&NewDataReady_4);
//    if (status) {
//      Serial.println("GetMeasurementDataReady sensor 4 failed");
//    } else {
//      status = 0;
//    }
//  }
//  if (NewDataReady_4) {
//
//    status = sensor_vl53l0x_4.GetRangingMeasurementData(&pRangingMeasurementData_4);
//    if (status) {
//      Serial.println("GetRangingMeasurementData sensor 4 failed");
//    }
//
//    status = sensor_vl53l0x_4.ClearInterruptMask(0);
//    if (status) {
//      Serial.println("ClearInterruptMask sensor 4 failed");
//    }
//
//    if (pRangingMeasurementData_4.RangeStatus == 0) {
//      // we have a valid range.
//      distance_top_4 = pRangingMeasurementData_4.RangeMilliMeter;
//    } else {
//      distance_top_4 = 1200;
//    }
//    TOFBelakang = distance_top_4 / 10.0;
//    // Serial.print("distance Belakang : ");
//    // Serial.println(TOFBelakang);
//  }
//}
//
//void bacaTOFBelakangKanan() {
//
//  // Reading sensor 5
//  status = 1;
//  while (status == 1) {
//    sensor_vl53l0x_5.StartMeasurement();
//    VL53L0X_RangingMeasurementData_t pRangingMeasurementData_5;
//    NewDataReady_5 = 0;
//    status = sensor_vl53l0x_5.GetMeasurementDataReady(&NewDataReady_5);
//    if (status) {
//      Serial.println("GetMeasurementDataReady sensor 5 failed");
//    } else {
//      status = 0;
//    }
//  }
//
//  if (NewDataReady_5) {
//
//    status = sensor_vl53l0x_5.GetRangingMeasurementData(&pRangingMeasurementData_5);
//    if (status) {
//      Serial.println("GetRangingMeasurementData sensor 5 failed");
//    }
//
//    status = sensor_vl53l0x_5.ClearInterruptMask(0);
//    if (status) {
//      Serial.println("ClearInterruptMask sensor 5 failed");
//    }
//
//    if (pRangingMeasurementData_5.RangeStatus == 0) {
//      // we have a valid range.
//      distance_top_5 = pRangingMeasurementData_5.RangeMilliMeter;
//    } else {
//      distance_top_5 = 1200;
//    }
//    TOFBelakangKanan = distance_top_5 / 10.0;
//    // Serial.print("distance Belakang Kanan: ");
//    // Serial.println(TOFBelakangKanan);
//  }
//}
//
//void bacaTOFBelakangKiri() {
//
//  // Reading sensor 6
//  status = 1;
//  while (status == 1) {
//    sensor_vl53l0x_6.StartMeasurement();
//    VL53L0X_RangingMeasurementData_t pRangingMeasurementData_6;
//    NewDataReady_6 = 0;
//    status = sensor_vl53l0x_6.GetMeasurementDataReady(&NewDataReady_6);
//    if (status) {
//      Serial.println("GetMeasurementDataReady sensor 6 failed");
//    } else {
//      status = 0;
//    }
//  }
//
//  if (NewDataReady_6) {
//
//    status = sensor_vl53l0x_6.GetRangingMeasurementData(&pRangingMeasurementData_6);
//    if (status) {
//      Serial.println("GetRangingMeasurementData sensor 6 failed");
//    }
//
//    status = sensor_vl53l0x_6.ClearInterruptMask(0);
//    if (status) {
//      Serial.println("ClearInterruptMask sensor 6 failed");
//    }
//
//    if (pRangingMeasurementData_6.RangeStatus == 0) {
//      // we have a valid range.
//      distance_top_6 = pRangingMeasurementData_6.RangeMilliMeter;
//    } else {
//      distance_top_6 = 1200;
//    }
//    TOFBelakangKiri = distance_top_6 / 10.0;
//    // Serial.print("distance Belakang Kiri: ");
//    // Serial.println(TOFBelakangKiri);
//  }
//}

void SetupSingleShot(VL53L0X& sensor) {
  int status;
  uint8_t VhvSettings;
  uint8_t PhaseCal;
  uint32_t refSpadCount;
  uint8_t isApertureSpads;

  status = sensor.StaticInit();
  if (status) {
    Serial.println("StaticInit sensor failed");
  }

  status = sensor.PerformRefCalibration(&VhvSettings, &PhaseCal);
  if (status) {
    Serial.println("PerformRefCalibration sensor failed");
  }

  status = sensor.PerformRefSpadManagement(&refSpadCount, &isApertureSpads);
  if (status) {
    Serial.println("PerformRefSpadManagement sensor failed");
  }

  status = sensor.SetDeviceMode(VL53L0X_DEVICEMODE_SINGLE_RANGING);  // Setup in single ranging mode
  if (status) {
    Serial.println("SetDeviceMode sensor failed");
  }

  status = sensor.SetMeasurementTimingBudgetMicroSeconds(20000);
  if (status) {
    Serial.println("SetMeasurementTimingBudgetMicroSeconds sensor failed");
  }

  Serial.print("Sensor ke : ");
  Serial.println(s);
  s++;
}

void bacaTOFDepan() {

  // Reading sensor 1
  sensor_vl53l0x_1.StartMeasurement();
  VL53L0X_RangingMeasurementData_t pRangingMeasurementData_1;
  NewDataReady_1 = 0;
  status = sensor_vl53l0x_1.GetMeasurementDataReady(&NewDataReady_1);
  if (status) {
    Serial.println("GetMeasurementDataReady sensor 1 failed");
  }
  if (NewDataReady_1) {
    status = sensor_vl53l0x_1.GetRangingMeasurementData(&pRangingMeasurementData_1);
    if (status) {
      Serial.println("GetRangingMeasurementData sensor 1 failed");
    }

    status = sensor_vl53l0x_1.ClearInterruptMask(0);
    if (status) {
      Serial.println("ClearInterruptMask sensor 1 failed");
    }

    if (pRangingMeasurementData_1.RangeStatus == 0) {
      // we have a valid range.
      distance_top_1 = pRangingMeasurementData_1.RangeMilliMeter;
    } else {
      distance_top_1 = 1200;
    }
    TOFDepan = distance_top_1 / 10.0;
    Serial.print("distance Depan : ");
    Serial.println(TOFDepan);
  }
}


void bacaTOFKanan() {
  // Reading sensor 2
  sensor_vl53l0x_2.StartMeasurement();

  VL53L0X_RangingMeasurementData_t pRangingMeasurementData_2;

  NewDataReady_2 = 0;
  status = sensor_vl53l0x_2.GetMeasurementDataReady(&NewDataReady_2);

  if (status) {
    Serial.println("GetMeasurementDataReady sensor 2 failed");
  }

  if (NewDataReady_2) {

    status = sensor_vl53l0x_2.GetRangingMeasurementData(&pRangingMeasurementData_2);
    if (status) {
      Serial.println("GetRangingMeasurementData sensor 2 failed");
    }

    status = sensor_vl53l0x_2.ClearInterruptMask(0);
    if (status) {
      Serial.println("ClearInterruptMask sensor 2 failed");
    }

    if (pRangingMeasurementData_2.RangeStatus == 0) {
      // we have a valid range.
      distance_top_2 = pRangingMeasurementData_2.RangeMilliMeter;
    } else {
      distance_top_2 = 1200;
    }

    TOFKanan = distance_top_2 / 10.0;
    Serial.print("distance Kanan : ");
    Serial.println(TOFKanan);
  }
}

void bacaTOFKiri() {
  // Reading sensor 3
  sensor_vl53l0x_3.StartMeasurement();

  VL53L0X_RangingMeasurementData_t pRangingMeasurementData_3;

  NewDataReady_3 = 0;
  status = sensor_vl53l0x_3.GetMeasurementDataReady(&NewDataReady_3);

  if (status) {
    Serial.println("GetMeasurementDataReady sensor 3 failed");
  }

  if (NewDataReady_3) {

    status = sensor_vl53l0x_3.GetRangingMeasurementData(&pRangingMeasurementData_3);
    if (status) {
      Serial.println("GetRangingMeasurementData sensor 3 failed");
    }

    status = sensor_vl53l0x_3.ClearInterruptMask(0);
    if (status) {
      Serial.println("ClearInterruptMask sensor 3 failed");
    }

    if (pRangingMeasurementData_3.RangeStatus == 0) {
      // we have a valid range.
      distance_top_3 = pRangingMeasurementData_3.RangeMilliMeter;
    } else {
      distance_top_3 = 1200;
    }

    TOFKiri = distance_top_3 / 10.0;
    // Serial.print("distance Kiri : ");
    // Serial.println(TOFKiri);
  }
}

void bacaTOFBelakang() {

  // Reading sensor 4
  sensor_vl53l0x_4.StartMeasurement();

  VL53L0X_RangingMeasurementData_t pRangingMeasurementData_4;

  NewDataReady_4 = 0;
  status = sensor_vl53l0x_4.GetMeasurementDataReady(&NewDataReady_4);

  if (status) {
    Serial.println("GetMeasurementDataReady sensor 4 failed");
  }

  if (NewDataReady_4) {

    status = sensor_vl53l0x_4.GetRangingMeasurementData(&pRangingMeasurementData_4);
    if (status) {
      Serial.println("GetRangingMeasurementData sensor 4 failed");
    }

    status = sensor_vl53l0x_4.ClearInterruptMask(0);
    if (status) {
      Serial.println("ClearInterruptMask sensor 4 failed");
    }

    if (pRangingMeasurementData_4.RangeStatus == 0) {
      // we have a valid range.
      distance_top_4 = pRangingMeasurementData_4.RangeMilliMeter;
    } else {
      distance_top_4 = 1200;
    }
    TOFBelakang = distance_top_4 / 10.0;
    Serial.print("distance Belakang : ");
    Serial.println(TOFBelakang);
  }
}

void bacaTOFBelakangKanan() {

  // Reading sensor 5
  sensor_vl53l0x_5.StartMeasurement();

  VL53L0X_RangingMeasurementData_t pRangingMeasurementData_5;

  NewDataReady_5 = 0;
  status = sensor_vl53l0x_5.GetMeasurementDataReady(&NewDataReady_5);

  if (status) {
    Serial.println("GetMeasurementDataReady sensor 5 failed");
  }

  if (NewDataReady_5) {

    status = sensor_vl53l0x_5.GetRangingMeasurementData(&pRangingMeasurementData_5);
    if (status) {
      Serial.println("GetRangingMeasurementData sensor 5 failed");
    }

    status = sensor_vl53l0x_5.ClearInterruptMask(0);
    if (status) {
      Serial.println("ClearInterruptMask sensor 5 failed");
    }

    if (pRangingMeasurementData_5.RangeStatus == 0) {
      // we have a valid range.
      distance_top_5 = pRangingMeasurementData_5.RangeMilliMeter;
    } else {
      distance_top_5 = 1200;
    }
    TOFBelakangKanan = distance_top_5 / 10.0;
    // Serial.print("distance Belakang Kanan: ");
    // Serial.println(TOFBelakangKanan);
  }
}

void bacaTOFBelakangKiri() {

  // Reading sensor 6
  sensor_vl53l0x_6.StartMeasurement();

  VL53L0X_RangingMeasurementData_t pRangingMeasurementData_6;

  NewDataReady_6 = 0;
  status = sensor_vl53l0x_6.GetMeasurementDataReady(&NewDataReady_6);

  if (status) {
    Serial.println("GetMeasurementDataReady sensor 6 failed");
  }

  if (NewDataReady_6) {

    status = sensor_vl53l0x_6.GetRangingMeasurementData(&pRangingMeasurementData_6);
    if (status) {
      Serial.println("GetRangingMeasurementData sensor 6 failed");
    }

    status = sensor_vl53l0x_6.ClearInterruptMask(0);
    if (status) {
      Serial.println("ClearInterruptMask sensor 6 failed");
    }

    if (pRangingMeasurementData_6.RangeStatus == 0) {
      // we have a valid range.
      distance_top_6 = pRangingMeasurementData_6.RangeMilliMeter;
    } else {
      distance_top_6 = 1200;
    }
    TOFBelakangKiri = distance_top_6 / 10.0;
    // Serial.print("distance Belakang Kiri: ");
    // Serial.println(TOFBelakangKiri);
  }
}
