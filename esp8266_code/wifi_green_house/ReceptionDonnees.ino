
void recep_data(){

 
 if(Serial.available()>0){
                        char a;
                        String command="";
                        String what="";
                        int  what_is;
                        String content="";
                        float float_content;
                        int   int_content;
                                                
                        delay(2);// wait first to receive every data
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
                        while (Serial.available()>0 and (char)a!='$'){        //read content
                        a=Serial.read();
                        if ((char)a!='$'){content += (char) a;}
                        }
                        int_content=content.toInt();
                        float_content=content.toFloat();

                  switch(what_is){         
       
                                case CODE_TEMPERATURE_COMPOST:
                                   index_average++;                           // it use use to do average beetween two send.
                                   if (float_content>(-20) and float_content<70){temperature_compost=float_content;}           
                                   break;
                                case CODE_HUMIDITY_COMPOST:                              
                                   if (int_content>=0 and float_content<=100){humidity_compost=int_content;}            
                                   break;
                                case CODE_PUMP_HYDROPONIE:                      //calcul the time of work between two sent              
                                   if (time_pump_hydroponie_1==0){time_pump_hydroponie_1= int_content;} 
                                   else if (int_content>=time_pump_hydroponie_1){time_pump_hydroponie=int_content-time_pump_hydroponie_1;}          
                                   break;
                               case CODE_OUT_COOLING:
                                  if (time_out_cooling_1==0){time_out_cooling_1=int_content;}
                                  else if (int_content>=time_out_cooling_1){time_out_cooling=int_content- time_out_cooling_1;}
                                  break; 
                                case CODE_SPRAY_COMPOST:
                                  if (time_spray_compost_1==0){time_spray_compost_1=int_content;}
                                  else if (int_content>=time_spray_compost_1){time_spray_compost=int_content- time_spray_compost_1;}
                                  break;
                                  

                                case CODE_TEMPERATURE_OUT:
                                  if (float_content>(-20) and float_content<70){temperature_out=float_content;}
                                  if (temperature_out != temperature_out){temperature_out=0;}
                                  break;
                               case CODE_HUMIDITY_OUT:
                                  if (int_content>=0 and float_content<=100){humidity_out=int_content;}
                                  break;
                               case CODE_PRESSURE_OUT:
                                  if (int_content>=0 and float_content<=5000){pressure_out=int_content;}
                                  break;                                  
                               case CODE_LEVEL_WATER_GARDEN:
                                  level_water_garden=int_content;
                                  break;
                               case CODE_SPRAY_GARDEN:
                                  if (time_spray_garden_1==0){time_spray_garden_1=int_content;}
                                  else if (int_content>=time_spray_garden_1){time_spray_garden=int_content- time_spray_garden_1;}
                                  break;                             
                               case CODE_TEMPERATURE_SOIL_GARDEN:
                                  if (float_content>(-20) and float_content<70){temperature_soil_garden=float_content;}
                                  break;
                               case CODE_MOISTURE_GARDEN:
                                  if (int_content>=0 and float_content<=100){moisture_garden=float_content;}
                                  break;
                               case CODE_OUTPUT_GARDEN:
                                  output_garden=int_content;
                                  break;  
                               case CODE_LUMINOSITY_GREENHOUSE:
                                  luminosity_greenhouse=int_content;
                                  break;                                
                      

                              case CODE_TEMPERATURE_GREENHOUSE:
                                  if (float_content>(-20) and float_content<70){temperature_greenhouse=float_content;}
                                  if (temperature_greenhouse != temperature_greenhouse){temperature_greenhouse=0;}
                                  break;
                              case CODE_HUMIDITY_GREENHOUSE:
                                  if (int_content>=0 and float_content<=100){humidity_greenhouse=int_content;}
                                  break;
                              case CODE_CO2_GREENHOUSE:
                                  if (int_content>=0 and float_content<=5000){co2_greenhouse=int_content;}
                                  break;
                              case CODE_LEVEL_WATER_GREENHOUSE:
                                  level_water_greenhouse=int_content;
                                  break;
                              case CODE_SPRAY_GREENHOUSE:
                                  if (time_spray_greenhouse_1==0){time_spray_greenhouse_1=int_content;}
                                  else if (int_content>=time_spray_greenhouse_1){time_spray_greenhouse=int_content- time_spray_greenhouse_1;}
                                  break;                                 
                              case CODE_LAMP_GREENHOUSE:
                                  if (time_lamp_greenhouse_1==0){time_lamp_greenhouse_1=int_content;}
                                  else if (int_content>=time_lamp_greenhouse_1){time_lamp_greenhouse=int_content- time_lamp_greenhouse_1;}
                                  break;                              
                              case CODE_HEAT_TANK_WATER:
                                  if (time_heat_tank_water_1==0){ time_heat_tank_water_1=int_content;}
                                  else if (int_content>=time_heat_tank_water_1){time_heat_tank_water=int_content- time_heat_tank_water_1;}
                                  break;                                
                              case CODE_FAN_COOLING_GREENHOUSE:
                                  if (time_fan_cooling_greenhouse_1==0){time_fan_cooling_greenhouse_1=int_content;}
                                  else if (int_content>=time_fan_cooling_greenhouse_1){time_fan_cooling_greenhouse=int_content- time_fan_cooling_greenhouse_1;}
                                  break;                        
                              case CODE_PUMP_COOLING_GREENHOUSE:
                                  if (time_pump_cooling_greenhouse_1==0){time_pump_cooling_greenhouse_1=int_content;}
                                  else if (int_content>=time_pump_cooling_greenhouse_1){time_pump_cooling_greenhouse=int_content- time_pump_cooling_greenhouse_1;}
                                  break;                               
                              case CODE_TEMPERATURE_WATER_GREENHOUSE:
                                  if (float_content>(-20) and float_content<70){temperature_water_greenhouse=float_content;}
                                  break;
                              case CODE_TEMPERATURE_SOIL_GREENHOUSE:
                                  if (float_content>(-20) and float_content<70){temperature_soil_greenhouse=content.toFloat();}
                                  break;
                              case CODE_MOISTURE_GREENHOUSE:
                                  if (int_content>=0 and float_content<=100){moisture_greenhouse=float_content;}
                                  break;
                              case CODE_VMC_GREENHOUSE:
                                  if (time_vmc_greenhouse_1==0){time_vmc_greenhouse_1=int_content;}
                                  else if (int_content>=time_vmc_greenhouse_1){time_vmc_greenhouse=int_content- time_vmc_greenhouse_1;}
                                  break;               
                              case CODE_FLAP_VENTILATION_GREENHOUSE:
                                  flap_ventilation_greenhouse=int_content;
                                  break;
                              case CODE_HUMIDIFICATOR_GREENHOUSE:
                                  if (time_humidificator_greenhouse_1==0){time_humidificator_greenhouse_1=int_content;}
                                  else if (int_content>=time_humidificator_greenhouse_1){time_humidificator_greenhouse=int_content - time_humidificator_greenhouse_1;}
                                  break;
                              case CODE_OUTPUT_GREENHOUSE:
                                  output_greenhouse=int_content;
                                  break;                                 
                      
                              case CODE_AVERAGE_V_BATTERY:
                                  if (index_average==1){v_battery=float_content;}
                                  else if (content.toFloat()<30){v_battery= v_battery + float_content;} // filter
                                  else {v_battery= v_battery + average_v_battery;}
                                  average_v_battery= v_battery/index_average;
                                  break;
                              case CODE_GENERAL_PUMP:
                                  if (time_main_pump_1==0){time_main_pump_1=int_content;}
                                  else if (int_content>=time_main_pump_1){time_main_pump=int_content- time_main_pump_1;}
                                  break;                           
                              
                              case CODE_AVERAGE_A_BATTERY:
                                  if (index_average==1){a_battery=float_content;}
                                  else{a_battery= a_battery + float_content;}
                                  average_a_battery= a_battery/index_average;
                                  break;                              
                              case CODE_AVERAGE_A_LOAD:
                                  if (index_average==1){a_load=float_content;}
                                  else{a_load= a_load + float_content;}
                                  average_a_load= a_load/index_average;
                                  break;                           
                                                                                                                  
                             default :
                                  break;
                                }
                        
                       
                      } 
  }
