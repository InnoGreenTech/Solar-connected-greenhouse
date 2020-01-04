int readCO2() {
  // D'après le code original de | From original code https://github.com/jehy/arduino-esp8266-mh-z19-serial
  byte cmd[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
  // command to ask for data
  byte response[9]; // for answer

  int ppm=222;

  Serial3.write(cmd, 9); //request PPM CO2

  // The serial stream can get out of sync. The response starts with 0xff, try to resync.
  while (Serial3.available() > 0 && (unsigned char)Serial3.peek() != 0xFF) {
    Serial3.read();
  }

  memset(response, 0, 9);
  Serial3.readBytes(response, 9);

  if (response[1] != 0x86)
  {
    Serial.println("Invalid response from co2 sensor!");
    
    return ppm;
  }

  byte crc = 0;
  for (int i = 1; i < 8; i++) {
    crc += response[i];
  }
  crc = 255 - crc + 1;

  if (response[8] == crc) {
    int responseHigh = (int) response[2];
    int responseLow = (int) response[3];
    //int ppm = (256 * responseHigh) + responseLow;
    ppm = response[2] << 8 | response[3];
    return ppm;
  } else {
    Serial.println("CRC error!");
    return -1;
  }
}
 /** ini co2 probe with munual configuration */
  void ini_CO2()

      {     
                  
          uint8_t cmd[9] = {0xFF, 0x01, 0x79, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00};

          uint8_t sum = 0x00;
           for (int i = 1; i < 8; i++)
          {
            sum += cmd[i];
          }
          sum = 0xff - sum + 0x01;

          cmd[8]= sum;
          Serial3.write(cmd, 9); //request PPM CO2

          delay(3000);
      } 

      /** Zero calibration */
      void zero_CO2()
         
        {
          uint8_t cmd[9] = {0xFF, 0x01, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
          
          uint8_t sum = 0x00;
          for (int i = 1; i < 8; i++)
          {
            sum += cmd[i];
          }
          sum = 0xff - sum + 0x01;

          cmd[8]= sum;
    
          Serial3.write(cmd, 9); //request PPM CO2*/

          delay (3000);
        }

       /** calibration manuel */

       void manu_cali()


          {                           
              uint8_t cmd[9] = {0xFF, 0x01, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    
              uint8_t sum = 0x00;
               for (int i = 1; i < 8; i++)
              {
                sum += cmd[i];
              }
              sum = 0xff - sum + 0x01;
    
              cmd[8]= sum;
              Serial3.write(cmd, 9); //request PPM CO2
    
              delay(3000);
          }        


              /* use to test and configure CO2 probeµ
        if (Serial.available()>0){consigne=Serial.read();}

        

        if (consigne=='m'){co2 = readCO2();Serial.println("Mesure CO2");consigne='m';}
        if (consigne=='i'){ini_CO2();Serial.println("Init auto calibaration");consigne='m';}
        if (consigne=='z'){zero_CO2();Serial.println("Zero calibration"),consigne='m';}
        if (consigne=='c') {manu_cali();Serial.println("Calibration manuel"),consigne='m';}    */    
        
