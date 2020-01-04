
void recep_wifi(){

 if(Serial1.available()>0){
                        char a;
                        char command[3];
                        String what="";
                        int  what_is;
                        String content="";
                                                
                        delay(2);                            // wait first to receive every data
                        command[0]=Serial1.read();
                        command[1]=Serial1.read();
                        command[2]=Serial1.read();
                        if (command!=CODE_COMMAND_INFO&&command!=CODE_COMMAND_READ&&command!=CODE_COMMAND_WRITE)
                        {Serial1.flush();return;}
                        what=Serial1.read();
                        what+=Serial1.read();
                        what_is=what.toInt();        
                        content = "";
                        while (Serial1.available()>0){        //read content
                        a=Serial1.read();
                        content += (char) a;} 

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

                                                                                              
                                default :
                                  break;
                                }
                        
                       
                      } 
  }
