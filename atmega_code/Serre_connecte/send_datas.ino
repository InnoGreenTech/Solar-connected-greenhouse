

void send_data(){

     
if(millis()-period_sent>PERIOD_SENT){
  
     int code[35]={
            CODE_TEMPERATURE_COMPOST,    
            CODE_HUMIDITY_COMPOST,
            CODE_PUMP_HYDROPONIE,
            CODE_HEAT_COMPOST,
            CODE_SPRAY_COMPOST,
       
            CODE_TEMPERATURE_OUT,
            CODE_HUMIDITY_OUT,
            CODE_PRESSURE_OUT,
            CODE_LEVEL_WATER_GARDEN,
            CODE_SPRAY_GARDEN,
            CODE_TEMPERATURE_SOIL_GARDEN,
            CODE_MOISTURE_GARDEN,
            CODE_OUTPUT_GARDEN,
            CODE_SPRAY_OUT_GARDEN,
            
            CODE_LUMINOSITY_GREENHOUSE,   
            CODE_TEMPERATURE_GREENHOUSE,
            CODE_HUMIDITY_GREENHOUSE,
            CODE_CO2_GREENHOUSE,
            CODE_LEVEL_WATER_GREENHOUSE,
            CODE_SPRAY_GREENHOUSE,
            CODE_LAMP_GREENHOUSE,
            CODE_HEAT_GREENHOUSE,
            CODE_FAN_COOLING_GREENHOUSE,
            CODE_PUMP_COOLING_GREENHOUSE,
            CODE_TEMPERATURE_WATER_GREENHOUSE,
            CODE_TEMPERATURE_SOIL_GREENHOUSE,
            CODE_MOISTURE_GREENHOUSE,
            CODE_VMC_GREENHOUSE,
            CODE_FLAP_VENTILATION_GREENHOUSE,
            CODE_HUMIDIFICATOR_GREENHOUSE,
            CODE_OUTPUT_GREENHOUSE,
    
            CODE_AVERAGE_V_BATTERY,
            CODE_GENERAL_PUMP,
            CODE_AVERAGE_A_BATTERY,
            CODE_AVERAGE_A_LOAD  
            }; 
                
       String  valeur[35]={
            String(temperature_compost),    
            String(humidity_compost),
            String(time_pump_hydroponie),
            String(time_heat_compost),
            String(time_spray_compost),
       
            String(temperature_out),
            String(humidity_out),
            String(pressure_out),
            String(level_water_garden),
            String(time_spray_garden),
            String(temperature_soil_garden),
            String(moisture_garden),
            String(output_garden),
            String(time_out_garden_spray),
            
            String(luminosity_greenhouse),              
            String(temperature_greenhouse),
            String(humidity_greenhouse),
            String(co2_greenhouse),
            String(level_water_greenhouse),
            String(time_greenhouse_spray),
            String(time_lamp_greenhouse),
            String(time_heat_greenhouse),
            String(time_cooling_greenhouse),
            String(time_cooling_greenhouse),
            String(temperature_water_greenhouse),
            String(temperature_soil_greenhouse),
            String(moisture_greenhouse),
            String(time_vmc_greenhouse),
            String(flap_ventilation_greenhouse),
            String(time_humidificator_greenhouse),
            String(output_greenhouse),
    
            String(v_battery),
            String(time_main_pump),
            String(a_battery),
            String(a_load)                     
       } ;  
       if (index_sent<36){  
       Serial1.print(CODE_COMMAND_INFO);
       //Serial.print(CODE_COMMAND_INFO);       
       Serial1.print(code[index_sent]);    // Envoi des valeurs au module Wifi
       //Serial.print(code[index_sent]);
       Serial1.print(valeur[index_sent]); 
       //Serial.println(valeur[index_sent]); 
         }
       index_sent++; 
       if (index_sent== 35){index_sent=0;} // remise à zéro de l'index
       period_sent=millis(); 
    }  
  
}
