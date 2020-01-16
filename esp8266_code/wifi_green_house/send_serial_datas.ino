


/****************************************************** 
 *      Keys of communication with ESP8266            *
 ******************************************************/

void send_information(){
  

     
if(millis()-period_sent>PERIOD_SENT){
  
     byte code[5]={ 
               CODE_HEURE,
               CODE_DATE,
               CODE_IP,
               CODE_GATE_WAY,
               CODE_MAC
                }; 
                
       String  valeur[5]={NTP.getTimeStr(),NTP.getDateStr(), local_ip,gate_way,local_mac} ;  
       if (index_sent<5){  
       Serial.print(CODE_COMMAND_INFO);         
       Serial.print(code[index_sent]);    // Envoi des valeurs au module Wifi
       Serial.print(valeur[index_sent]); 
         }
       index_sent++; 
       if (index_sent== 5){index_sent=0; } // remise à zéro de l'index
       period_sent=millis();
    }  
  
}
