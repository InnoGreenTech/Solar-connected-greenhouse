void greenhouse_gest(){
  if(bitRead(refresh_demand,REFRESH_DATA))
  {
             temperature_greenhouse= float(greenhouse_dht.readTemperature()); 
             humidity_greenhouse=float(greenhouse_dht.readHumidity()); 
             onewire_greenhouse.select(address_soil_greenhouse);
             temperature_soil_greenhouse=onewire_greenhouse.getTempC();
             onewire_greenhouse.select(address_water_greenhouse);
             temperature_water_greenhouse=onewire_greenhouse.getTempC();
             //get_water_level();
             get_moisture_greenhouse();
             co2_greenhouse=readCO2();
             get_luminosity();
             day_detect();
             
             vmc_control();
             cooling_system();
             control_spray_greenhouse();
             lamp_run();
  }

  }


 void cooling_system(){
    byte cooling_day=0;
    byte cooling_night=0;
    
    if((temperature_greenhouse>temperature_water_greenhouse+10) && night_day==0){cooling_day=1;} // control cooling during the day
    else{cooling_day=0;}


    if (bitRead(mode_flag,ECO_MODE)){
          if((temperature_greenhouse<(temperature_water_greenhouse-(temperature_water_greenhouse-temperature_out)*2/3)and (temperature_water_greenhouse-temperature_greenhouse)>5))
          {cooling_night=1;}
      }
    else if (!bitRead(mode_flag,SAFE_MODE)){
          if((temperature_greenhouse<(temperature_water_greenhouse-(temperature_water_greenhouse-temperature_out)/3)and (temperature_water_greenhouse-temperature_greenhouse)>5))
          {cooling_night=1;}
          }
    if (cooling_night==0){ 
          if((temperature_water_greenhouse>temperature_greenhouse) and temperature_greenhouse<5)
          {cooling_night=1;}
      }
    if(cooling_day==1 || cooling_night==1){    
            bitSet(output_greenhouse,FAN_COOLING_GREENHOUSE);
            bitSet(output_greenhouse,PUMP_COOLING_GREENHOUSE);
      }   
    else{
            bitClear(output_greenhouse,FAN_COOLING_GREENHOUSE);
            bitClear(output_greenhouse,PUMP_COOLING_GREENHOUSE);    
    }
  }


void get_water_level(){
  
  int distance=water_level.ping_cm();
  //Serial.println(distance);
  if (distance<set_deep_water and distance!=0){level_water_greenhouse = set_deep_water-distance;}


  }

void get_moisture_greenhouse(){
  //int read_pin=analogRead(MOISTURE_GREENHOUSE);
  float read_pin=0;
  for (int i = 0; i <500; i ++) {
  read_pin = read_pin +float( MOISTURE_GREENHOUSE)/500; 
  }
  //read_pin=read_pin-80;
  //moisture_greenhouse= 100-(read_pin*10/90);
  moisture_greenhouse=int(float(set_k_moist_greenhouse*100)/read_pin);
  if(moisture_greenhouse>100){moisture_greenhouse=100;}
  else if(moisture_greenhouse<0){moisture_greenhouse=0;}
  return moisture_greenhouse;}

void control_spray_greenhouse(){
  if (moisture_greenhouse<set_moisture_greenhouse and night_day==1){
    if(start_timer_spray_greenhouse==0)
      {start_timer_spray_greenhouse=1; start_timer_spray_greenhouse=millis();bitSet(output_greenhouse,SPRAY_GREENHOUSE); }
    else if (millis()-start_timer_spray_greenhouse >DELAY_SPRAY and start_timer_spray_greenhouse==1)
      {start_timer_spray_greenhouse=2;start_timer_spray_greenhouse=millis();bitClear(output_greenhouse,SPRAY_GREENHOUSE);}
    else if (millis()-start_timer_spray_greenhouse >DELAY_PAUSE_SPRAY and start_timer_spray_greenhouse==2)
      {start_timer_spray_greenhouse=0;}  
  }
  else{bitClear(output_greenhouse,SPRAY_GREENHOUSE);start_timer_spray_greenhouse=0;}
}

void vmc_control(){
  
  int calculate_humidity;
  int difference_humidity= humidity_greenhouse-set_humidity_greenhouse;
  
  if(humidity_out<95 and !bitRead(output_greenhouse,VMC_GREENHOUSE)){calculate_humidity=(humidity_out*temperature_out/temperature_greenhouse)+5;}
  else if (humidity_out<95){calculate_humidity=(humidity_out*temperature_out/temperature_greenhouse);}  
  else{calculate_humidity=100;}

  if (temperature_greenhouse>set_temperature_greenhouse || bitRead(forced_greenhouse,VMC_GREENHOUSE)){             // security to protect hot temperature
  bitSet(output_greenhouse,VMC_GREENHOUSE);
  servo_vmc.write(100);
  }
  else if( calculate_humidity<(humidity_greenhouse-5) && difference_humidity>5 && night_day==0){               // Control humidity only the night
        int open_servo= map(difference_humidity,0,10,10,100);
        if( open_servo<100){servo_vmc.write(open_servo);}else{servo_vmc.write(100);}
        if (difference_humidity>15 and temperature_greenhouse>20){bitSet(output_greenhouse,VMC_GREENHOUSE);}
       }
  else if (co2_greenhouse>set_co2_greenhouse){
        int open_servo= map(co2_greenhouse,set_co2_greenhouse,1700,10,100);
        if( open_servo<100){servo_vmc.write(open_servo);}else{servo_vmc.write(100);}
        if (co2_greenhouse>set_co2_greenhouse+300 and temperature_greenhouse>20){bitSet(output_greenhouse,VMC_GREENHOUSE);}
        
        }
  else {bitClear(output_greenhouse,VMC_GREENHOUSE);servo_vmc.write(10);}  

 }

void lamp_run(){
  if (night_day==0){
    bitClear(output_greenhouse,LAMP_GREENHOUSE);light_use=0;                                 // reset memory use,wait night to switch on the lamp
  }
  else if (!bitRead(output_greenhouse,LAMP_GREENHOUSE) and !light_use)
        {bitSet(output_greenhouse,LAMP_GREENHOUSE); time_lamp_day=millis();}
  else if ((millis()- time_lamp_day) > TIME_LAMP_DAY){
        bitClear(output_greenhouse,LAMP_GREENHOUSE); light_use=1;
   }    

        
  }
  
float get_luminosity(){
  
  float read_pin=analogRead(LUMINOSITY_GREENHOUSE); 
  read_pin= (read_pin*10/1023); 
  read_pin= read_pin*read_pin*read_pin;
  read_pin=1.8*read_pin;
  luminosity_greenhouse= int(read_pin);
    
  return luminosity_greenhouse;
}

void day_detect(){

  if (luminosity_greenhouse<50 and night_day==0){night_day=1;}
  else if (luminosity_greenhouse>200 and night_day==1){night_day=0;}
}
