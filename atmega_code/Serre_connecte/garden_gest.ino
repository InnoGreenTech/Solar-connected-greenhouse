void garden_gest(){
  if(bitRead(refresh_demand,REFRESH_DATA))
  { 
    onewire_garden.select(address_soil_garden);
    temperature_soil_garden=onewire_garden.getTempC();
    read_values_out();
    read_values_compost();
    tension_battery();
    intensity_battery();
    intensity_load();
    get_moisture_garden();
    cat_proof_control();
    hydroponie_control();

    temperature_control_compost();
    spray_control_garden(); 
    spray_control_out_garden();   
  }
  
  
}

void read_values_compost(){
  /*temperature_compost=compost_sensor.readTempC();
  pressure_compost=compost_sensor.readFloatPressure();
  humidity_compost=compost_sensor.readFloatHumidity();*/
  onewire_garden.select(address_compost);
  pressure_compost=1000;
  humidity_compost=80;
  temperature_compost=onewire_garden.getTempC();
  
}

void read_values_out(){
  temperature_out=out_sensor.readTempC();
  pressure_out=(out_sensor.readFloatPressure())/100;
  humidity_out=out_sensor.readFloatHumidity();

  // take samples in one hour to do average , use for the weather forecasts
  
  pressure_corrected= pressure_out * pow((1 - ((0.0065 * set_altitude) / (temperature_out + 0.0065 * set_altitude + 273.15))), -5.257);
  if (current_sample_pressure<total_samples_pressure){current_sample_pressure++;current_average_pressure=current_average_pressure+(pressure_corrected/total_samples_pressure);}
  else{
    rotate_index++;
    if (rotate_index>=NUMBER_SAMPLES_HOUR){rotate_index=0;}
    average_pressure[rotate_index]= current_average_pressure;
    current_average_pressure=0;
    current_sample_pressure=0;    
  }
}



float tension_battery(){
  float read_pin=0;
  float volts;
  for (int i = 0; i <100; i ++) {
  read_pin = read_pin +float( analogRead(V_BATTERY))/100; 
  }
  //float read_pin= float(analogRead(V_BATTERY));
  volts= 1+((read_pin*30/1023)/1.07)+ float(set_v_offset_battery)/100;
  if (volts<29){v_battery=volts;}
  return v_battery;
  
}

float intensity_battery(){
  float read_pin=0;
  for (int i = 0; i <500; i ++) {
  read_pin = read_pin +float( analogRead(INTENSITY_BATTERY))/500; 
  }
  read_pin=read_pin-512;
  //float read_pin= float(analogRead(INTENSITY_BATTERY)-512);
  a_battery= (read_pin*25/512)+ float(set_a_offset_battery)/100;   //100 mV/A
  return a_battery;

}

float intensity_load(){
  float read_pin=0;
  for (int i = 0; i <500; i ++) {
  read_pin = read_pin +float( analogRead(INTENSITY_LOAD))/500; 
  }
  read_pin=read_pin-512;
  //float read_pin=float(analogRead(INTENSITY_LOAD)-512);  
  a_load= (read_pin*25/512)+ float(set_a_offset_load)/100;
  return a_load;

}

  
void hydroponie_control(){
  if ((millis()-last_pump_hydroponie)>delay_hydroponie and night_day==0)
      {
        if (!start_pump_hydroponie==1) 
          { start_pump_hydroponie=1; delay_start_pump_hydroponie=millis(); bitSet(output_garden,PUMP_HYDROPONIE);}
        else if ((millis()-delay_start_pump_hydroponie) > delay_pump_hydroponie)
          {bitClear(output_garden,PUMP_HYDROPONIE);last_pump_hydroponie=millis(); start_pump_hydroponie=0;}  
      }
  else{ bitClear(output_garden,PUMP_HYDROPONIE);}   
}

/* Control temperature compost with cooling system */

void temperature_control_compost(){
    if ((temperature_compost<set_temperature_compost) and  bitRead(output_greenhouse,PUMP_COOLING_GREENHOUSE) and (temperature_water_greenhouse>temperature_compost))
      {
        bitSet(output_garden,HEATING_COMPOST);
      }
    else if ( temperature_compost>set_temperature_compost and  bitRead(output_greenhouse,PUMP_COOLING_GREENHOUSE) and (temperature_water_greenhouse<temperature_compost))
       {
        bitSet(output_garden,HEATING_COMPOST);
      }
    else{
        bitClear(output_garden,HEATING_COMPOST);
    }
  }

void get_moisture_garden(){
  float read_pin=float(analogRead(MOISTURE_GARDEN));
  moisture_garden= int(((read_pin*a_moist_garden)-b_moist_garden)/100);
  if(moisture_garden>100){moisture_garden=100;}
  else if(moisture_garden<0){moisture_garden=0;}
  return moisture_garden;}

void spray_control_garden(){


   if (night_day==1){
    //bitClear(output_garden,SPRAY_GARDEN);
    garden_spray_done=0;                                 // reset memory use,wait day morning to switch on spray
    delay_garden_spray= int((average_temperature_out-10)*15+(70-average_humidity_out)*10);

    
  }

  if ((delay_garden_spray>0 || moisture_garden<set_moisture_garden) and night_day==0 and !garden_spray_done){
    bitSet(output_garden,SPRAY_GARDEN);
    delay_garden_spray= delay_garden_spray-DELAY_REFRESH_SCREEN_SECONDS;
  }
  else if (night_day==0 and !garden_spray_done){
    garden_spray_done=1;
  }
  else if ( wifi_spray_garden and delay_garden_spray>0){
    bitSet(output_garden,SPRAY_GARDEN);
    delay_garden_spray= delay_garden_spray-DELAY_REFRESH_SCREEN_SECONDS;
  }
  else if (  wifi_spray_garden ){
    wifi_spray_garden=0;
  }
  else{bitClear(output_garden,SPRAY_GARDEN);}
}

void spray_control_out_garden(){

   if (night_day==1){
    //bitClear(output_garden,SPRAY_OUT_GARDEN);
    out_garden_spray_done=0;                                 // reset memory use,wait day morning to switch on spray
    delay_out_garden_spray= int((average_temperature_out-10)*30+(70-average_humidity_out)*15);
    
  }

  if (delay_out_garden_spray>0 and night_day==0 and !out_garden_spray_done){
    bitSet(output_garden,SPRAY_OUT_GARDEN);
    delay_out_garden_spray= delay_out_garden_spray-DELAY_REFRESH_SCREEN_SECONDS;
  }
  else if (night_day==0 and !out_garden_spray_done){
    out_garden_spray_done=1;
  }
  else if ( wifi_spray_out_garden and delay_out_garden_spray>0){
    bitSet(output_garden,SPRAY_OUT_GARDEN);
    delay_out_garden_spray= delay_out_garden_spray-DELAY_REFRESH_SCREEN_SECONDS;
  }
  else if (  wifi_spray_out_garden ){
    wifi_spray_out_garden=0;
  }
 else{bitClear(output_garden,SPRAY_OUT_GARDEN);}
}

void cat_proof_control(){
  if(digitalRead(CAT_PROOF_DETECT)){
    bitSet(output_garden,CAT_PROOF_GARDEN);
  }
  else{bitClear(output_garden,CAT_PROOF_GARDEN);}
 if(digitalRead(CAT_PROOF_OUT)){
  bitSet(output_garden,CAT_PROOF_OUT_GARDEN);
 }
 else{bitClear(output_garden,CAT_PROOF_OUT_GARDEN);}
}


  
