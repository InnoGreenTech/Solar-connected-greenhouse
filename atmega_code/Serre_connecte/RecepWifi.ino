
void recep_wifi(){

 if(Serial1.available()>0){
                        char a;
                        String command="";
                        String what="";
                        int  what_is;
                        String content="";
                                                
                        delay(2);                            // wait first to receive every data
                        for(int i=0;i<3;i++){
                            a=Serial1.read();
                            command +=(char)a;
                          }
                          
                        if (command!=CODE_COMMAND_INFO&&command!=CODE_COMMAND_READ&&command!=CODE_COMMAND_WRITE)
                          {
                           
                            while (Serial1.available()>0){        //read content
                            Serial1.read();}
                            Serial1.flush();return;
                            }

                        for(int i=0;i<2;i++){
                            a=Serial1.read();
                            what+=(char)a;
                          }
                        what_is=what.toInt(); 
                        
   
                        content = "";
                        
                        while (Serial1.available()>0 and a!='$'){        //read content
                        a=Serial1.read();
                        if (a!='$'){content += (char) a;}
                        }
                        


                  switch(what_is){         
    
                                case CODE_DATE:                               // Date actuelle
                                   date=content;       
                                   break;
                                case CODE_HEURE:                              // heure actuelle
                                   hour=content;           
                                   break;
                                case CODE_IP:                                 // adresse ip
                                   ip_address=content;           
                                   break;
                                case CODE_GATE_WAY:                           // passerelle
                                   gate_way=content;           
                                   break; 
                                case CODE_MAC:                               // adresse MAC
                                   mac_address=content;           
                                   break;
                                case CODE_SPRAY_GREENHOUSE:
                                   delay_greenhouse_spray= content.toInt();
                                   wifi_spray_greenhouse=1;
                                   break;                           
                                case CODE_SPRAY_GARDEN:
                                   delay_garden_spray= content.toInt();
                                   wifi_spray_garden=1;
                                   break;                           
                                case CODE_SPRAY_OUT_GARDEN:
                                   delay_out_garden_spray= content.toInt();
                                   wifi_spray_out_garden=1;
                                   break;                           

                                

                                                                                              
                                default :
                                  break;
                                }
                        
                       
                      } 
  }
