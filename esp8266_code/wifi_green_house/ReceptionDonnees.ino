
void recep_data(){

 
 if(Serial.available()>0){
                        char a;
                        char command[2];
                        char what[2];
                        int  what_is;
                        String content="";
                                                
                        delay(2);                            // wait first 
                        command[0]=Serial.read();
                        command[1]=Serial.read();
                        if (command!=CODE_COMMAND_INFO&&command!=CODE_COMMAND_READ&&command!=CODE_COMMAND_WRITE)
                        {Serial.flush();return;}
                        what[0]=Serial.read();
                        what[1]=Serial.read();
                        content=what;
                        what_is=content.toInt();        
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
                                case CODE_PUMP_COMPOST:                
                                   if (index_average==1){ time_pump_compost_1= content.toInt();} 
                                   else{time_pump_compost=content.toInt()-time_pump_compost_1;}          
                                   break;
                                case CODE_HEAT_COMPOST:
                                  if (index_average==1){ time_heat_compost_1=content.toInt();}
                                  else{time_heat_compost=content.toInt()- time_heat_compost;}
                                  break;
                                
                                                                                                                  
                                 default :
                                    break;
                                }
                        
                       
                      } 
  }
