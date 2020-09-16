void add_module(){

      String   reception;

      if ( server.hasArg("ip_server") ) 
              {      
              reception=server.arg("ip_server");
              int c = reception.length() + 1;         // longueur de la chaîne de caractéres                    
              if ( c>16){ Serial.println(F("adresse ip invalide")); return;}
              reception.toCharArray(ip_server, c); 
              for (int i = 0; i < c; i++) { 
                                            EEPROM.write((i+MEM_ADRESS_SERVER),reception[i]);  // save adresse IP in EEPROM
                                            }  
              }

      if ( server.hasArg("port") ) 
              {       
              reception = server.arg("port");
              port_server=reception.toInt();           
              int b=port_server;
              for (int a=0;a<2;a++){EEPROM.write(MEM_PORT_SERVER+a ,b);b=b>>8;} // Save configuration port
              } 

      if ( server.hasArg("name") ) 
              { 
              reception=server.arg("name"); 
              int c = reception.length() + 1;                               
              if ( c>20){Serial.println(F("Nom trop long"));return;} 
              reception.toCharArray(name_module, c); 
              for (int i = 0; i < c; i++) { 
                                            EEPROM.write((i+MEM_NAME_MODULE),reception[i]);  // save adresse IP in EEPROM
                                            }  
              } 

      if ( server.hasArg("period") )       // Period to send datas
              {       
              reception = server.arg("period");
              period=reception.toInt();           
              int b=period;
              delay_sent=period*1000;
              for (int a=0;a<2;a++){EEPROM.write(MEM_PERIOD+a ,b);b=b>>8;} 
              } 
      EEPROM.commit();     // Enregistrement

      server.send ( 200, "text/csv", answer_add_module() );   // envoi de la page  
}

/* file csv with information for php server */

String answer_add_module(){
  String page =name_module; page +=F(";");  page +=ref_module;  page +=F(";");  page +=local_mac;  page +=F(";");
         page +=local_ip; page +=F(";");  page +=version_module; page +=F("\r\n");                                      // line 1 informations module
         
         // type( probe or actuator,id,name,type_probe)

         
         page +=F("probe;p1;temp_greenhouse;DHT_22_temp\r\n");    
         page +=F("probe;p2;hum_greenhouse;DHT_22_hum\r\n"); 
         page +=F("probe;p3;co2_greenhouse;MH-Z19\r\n");     
         page +=F("probe;p4;lux_greenhouse;PHOTO_RESISTOR\r\n");
         page +=F("probe;p5;moist_greenhouse;MOISTURE_SOIL\r\n");
         page +=F("probe;p6;temp_soil_greenhouse;DS18b20\r\n");
         page +=F("probe;p7;temp_water_greenhouse;DS18b20\r\n");
         page +=F("probe;p19;level_water_greenhouse;sonar_level\r\n");
         
         page +=F("probe;p8;temp_out;BME280_temp\r\n");
         page +=F("probe;p9;hum_out;BME280_hum\r\n");
         page +=F("probe;p18;pres_out;BME280_pre\r\n"); 
         page +=F("probe;p10;temp_compost;BME280_temp\r\n");
         page +=F("probe;p11;hum_compost;BME280_hum\r\n");
         page +=F("probe;p12;pres_compost;BME280_pre\r\n");
         page +=F("probe;p13;moist_garden;MOISTURE_SOIL\r\n");
         page +=F("probe;p14;temp_soil_garden;DS18b20\r\n");
         
         page +=F("probe;p15;v_battery;ANA_ARDUINO_V\r\n");          
         page +=F("probe;p16;a_battery;ACS712\r\n");
         page +=F("probe;p17;a_load;ACS712\r\n");
                 
         page +=F("actuator;a1;main_pump;MOSFET\r\n");
         
         page +=F("actuator;a2;vmc_greenhouse;MOSFET\r\n");
         page +=F("actuator;a3;fan_cooling_greenhouse;MOSFET\r\n");
         page +=F("actuator;a4;pump_cooling_greenhouse;MOSFET\r\n");
         page +=F("actuator;a5;heating_tank_water;MOSFET\r\n");
         page +=F("actuator;a6;spray_greenhouse;MOSFET\r\n"); 
         page +=F("actuator;a7;lamp_greenhouse;MOSFET\r\n");
         page +=F("actuator;a8;flap_venti_greenhouse;SERVO\r\n");
         page +=F("actuator;a9;humidificator_greenhouse;MOSFET\r\n");           

         page +=F("actuator;a10;spray_garden;MOSFET\r\n");
         page +=F("actuator;a11;out_cooling;MOSFET\r\n");
         page +=F("actuator;a12;spray_compost;MOSFET\r\n");
         page +=F("actuator;a13;pump_compost;MOSFET\r\n");
         page +=F("actuator;a14;spray_out_garden;MOSFET\r\n");
         
         return page;
  }
