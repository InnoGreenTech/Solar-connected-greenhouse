
void recep_data(){

 
 if(Serial.available()>0){
                        char a;
                        String command="";
                        String what="";
                        int  what_is;
                        String content="";
                                                
                        delay(2);                            // wait first to receive every data
                        for(int i=0;i<3;i++){
                            a=Serial.read();
                            command +=(char)a;
                          }
                          

                        if (command!=CODE_COMMAND_INFO&&command!=CODE_COMMAND_READ&&command!=CODE_COMMAND_WRITE)
                          {
                           
                            while (Serial.available()>0){        //read content
                            Serial.read();}
                            Serial.flush();return;
                            }
                                                  
                        for(int i=0;i<2;i++){
                            a=Serial.read();
                            what +=(char)a;
                          }

                        what_is=what.toInt();        
                        content = "";
                        while (Serial.available()>0){        //read content
                        a=Serial.read();
                        content += (char) a;} 

                  switch(what_is){         
       
                                case CODE_TEMPERATURE_COMPOST:
                                   index_average++;                           // it use use to do average beetween two send.
                                   temperature_compost=content.toFloat();           
                                   break;
                                case CODE_HUMIDITY_COMPOST:                              
                                   humidity_compost=content.toInt();            
                                   break;
                                case CODE_PUMP_COMPOST:                      //calcul the time of work between two sent              
                                   if (index_average==1){ time_pump_compost_1= content.toInt();} 
                                   else{time_pump_compost=content.toInt()-time_pump_compost_1;}          
                                   break;
                                case CODE_HEAT_COMPOST:
                                  if (index_average==1){ time_heat_compost_1=content.toInt();}
                                  else{time_heat_compost=content.toInt()- time_heat_compost_1;}
                                  break;
                                case CODE_SPRAY_COMPOST:
                                  if (index_average==1){time_spray_compost_1=content.toInt();}
                                  else{time_spray_compost=content.toInt()- time_spray_compost_1;}
                                  

                                case CODE_TEMPERATURE_OUT:
                                  temperature_out=content.toFloat();
                                  break;
                               case CODE_HUMIDITY_OUT:
                                  humidity_out=content.toFloat();
                                  break;
                               case CODE_LEVEL_WATER_GARDEN:
                                  level_water_garden=content.toInt();
                                  break;
                               case CODE_SPRAY_GARDEN:
                                  if (index_average==1){time_spray_garden_1=content.toInt();}
                                  else{time_spray_garden=content.toInt()- time_spray_garden_1;}
                                  break;
                               case CODE_TEMPERATURE_SOIL_GARDEN:
                                  temperature_soil_garden=content.toFloat();
                                  break;
                               case CODE_MOISTURE_GARDEN:
                                  moisture_garden=content.toFloat();
                                  break;
                               case CODE_OUTPUT_GARDEN:
                                  output_garden=content.toInt();
                                  break;                                  
                      

                              case CODE_TEMPERATURE_GREENHOUSE:
                                  temperature_greenhouse=content.toFloat();
                                  break;
                              case CODE_HUMIDITY_GREENHOUSE:
                                  humidity_greenhouse=content.toInt();
                                  break;
                              case CODE_CO2_GREENHOUSE:
                                  co2_greenhouse=content.toInt();
                                  break;
                              case CODE_LEVEL_WATER_GREENHOUSE:
                                  level_water_greenhouse=content.toInt();
                                  break;
                              case CODE_SPRAY_GREENHOUSE:
                                   if (index_average==1){time_spray_greenhouse_1=content.toInt();}
                                  else{time_spray_greenhouse=content.toInt()- time_spray_greenhouse_1;}
                                  break;                                 
                              case CODE_LAMP_GREENHOUSE:
                                  if (index_average==1){time_lamp_greenhouse_1=content.toInt();}
                                  else{time_lamp_greenhouse=content.toInt()- time_lamp_greenhouse_1;}
                                  break;                              
                              case CODE_HEAT_GREENHOUSE:
                                  if (index_average==1){time_heat_greenhouse_1=content.toInt();}
                                  else{time_heat_greenhouse=content.toInt()- time_heat_greenhouse_1;}
                                  break;                                  
                              case CODE_FAN_COOLING_GREENHOUSE:
                                  if (index_average==1){time_fan_cooling_greenhouse_1=content.toInt();}
                                  else{time_fan_cooling_greenhouse=content.toInt()- time_fan_cooling_greenhouse_1;}
                                  break;                        
                              case CODE_PUMP_COOLING_GREENHOUSE:
                                  if (index_average==1){time_pump_cooling_greenhouse_1=content.toInt();}
                                  else{time_pump_cooling_greenhouse=content.toInt()- time_pump_cooling_greenhouse_1;}
                                  break;                               
                              case CODE_TEMPERATURE_WATER_GREENHOUSE:
                                  temperature_water_greenhouse=content.toFloat();
                                  break;
                              case CODE_TEMPERATURE_SOIL_GREENHOUSE:
                                  temperature_soil_greenhouse=content.toFloat();
                                  break;
                              case CODE_MOISTURE_GREENHOUSE:
                                  moisture_greenhouse=content.toFloat();
                                  break;
                              case CODE_VMC_GREENHOUSE:
                                  if (index_average==1){time_vmc_greenhouse_1=content.toInt();}
                                  else{time_vmc_greenhouse=content.toInt()- time_vmc_greenhouse_1;}
                                  break;               
                              case CODE_FLAP_VENTILATION_GREENHOUSE:
                                  flap_ventilation_greenhouse=content.toInt();
                                  break;
                              case CODE_HUMIDIFICATOR_GREENHOUSE:
                                  if (index_average==1){time_humidificator_greenhouse_1=content.toInt();}
                                  else{time_humidificator_greenhouse=content.toInt()- time_humidificator_greenhouse_1;}
                                  break;
                              case CODE_OUTPUT_GREENHOUSE:
                                  output_greenhouse=content.toInt();
                                  break;                                 
                      
                              case CODE_AVERAGE_V_BATTERY:
                                  if (index_average==1){v_battery=content.toFloat();}
                                  else{v_battery= v_battery + content.toFloat();}
                                  average_v_battery= v_battery/index_average;
                                  break;
                              case CODE_GENERAL_PUMP:
                                  if (index_average==1){time_main_pump_1=content.toInt();}
                                  else{time_main_pump=content.toInt()- time_main_pump_1;}
                                  break;                           
                              
                              case CODE_AVERAGE_A_BATTERY:
                                  if (index_average==1){a_battery=content.toFloat();}
                                  else{a_battery= a_battery + content.toFloat();}
                                  average_a_battery= a_battery/index_average;
                                  break;                              
                              case CODE_AVERAGE_A_LOAD:
                                  if (index_average==1){a_load=content.toFloat();}
                                  else{a_load= a_load + content.toFloat();}
                                  average_a_load= a_load/index_average;
                                  break;                           
                                                                                                                  
                             default :
                                  break;
                                }
                        
                       
                      } 
  }
