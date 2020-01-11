

void send_data(){

     
if(millis()-period_sent>PERIOD_SENT){
  
     byte code[33]={
            CODE_TEMPERATURE_COMPOST,    
            CODE_HUMIDITY_COMPOST,
            CODE_PUMP_COMPOST,
            CODE_HEAT_COMPOST,
            CODE_SPRAY_COMPOST,
            CODE_CLEAN_COMPOST,
       
            CODE_TEMPERATURE_OUT,
            CODE_HUMIDITY_OUT,
            CODE_LEVEL_WATER_GARDEN,
            CODE_SPRAY_GARDEN,
            CODE_TEMPERATURE_SOIL_GARDEN,
            CODE_MOISTURE_GARDEN,
            CODE_OUTPUT_GARDEN,   
    
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
                
       float  valeur[33]={
            temperature_compost,    
            humidity_compost,
            time_pump_compost,
            time_heat_compost,
            time_spray_compost,
       
            temperature_out,
            humidity_out,
            level_water_garden,
            time_spray_garden,
            temperature_soil_garden,
            moisture_garden,
            output_garden,   
    
            temperature_greenhouse,
            humidity_greenhouse,
            co2_greenhouse,
            level_water_greenhouse,
            time_spray_greenhouse,
            time_lamp_greenhouse,
            time_heat_greenhouse,
            time_cooling_greenhouse,
            time_cooling_greenhouse,
            temperature_water_greenhouse,
            temperature_soil_greenhouse,
            moisture_greenhouse,
            time_vmc_greenhouse,
            flap_ventilation_greenhouse,
            time_humidificator_greenhouse,
            output_greenhouse,
    
            v_battery,
            time_main_pump,
            a_battery,
            a_load                     
       } ;  
       if (index_sent<31){  
       Serial1.print(CODE_COMMAND_INFO);         
       Serial1.print(code[index_sent]);    // Envoi des valeurs au module Wifi
       Serial1.print(valeur[index_sent],2); 
         }
       index_sent++; 
       if (index_sent== 31){index_sent=0;period_sent=millis(); } // remise à zéro de l'index
    }  
  
}
