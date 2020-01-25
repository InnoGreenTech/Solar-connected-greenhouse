






void output_greenhouse_control(){
if(refresh_demand==1)
  { 
         /* Cooling system */
        if (!bitRead(desactive_greenhouse,FAN_COOLING_GREENHOUSE))
          { 
            if (bitRead(output_greenhouse,FAN_COOLING_GREENHOUSE)|| bitRead(forced_greenhouse,FAN_COOLING_GREENHOUSE)) 
                    {
                      digitalWrite(GREENHOUSE_FAN_COOLING,1);
                      time_cooling_greenhouse=time_cooling_greenhouse+REFRESH_SCREEN_SECONDS;
                    }
            else{digitalWrite(GREENHOUSE_FAN_COOLING,0);}
          }
        else{digitalWrite(GREENHOUSE_FAN_COOLING,0);}
        
        if (!bitRead(desactive_greenhouse,PUMP_COOLING_GREENHOUSE))
          {
            if (bitRead(output_greenhouse,PUMP_COOLING_GREENHOUSE) || bitRead(forced_greenhouse,PUMP_COOLING_GREENHOUSE)) 
                    {
                      analogWrite(GREENHOUSE_PUMP_COOLING,100);                                          
                    }
            else{analogWrite(GREENHOUSE_PUMP_COOLING,0);}
          }
        else{analogWrite(GREENHOUSE_PUMP_COOLING,0);}   
             
        /* spray system */
        
        if (!bitRead(desactive_greenhouse,SPRAY_GREENHOUSE))
          {
            if(bitRead(output_greenhouse,SPRAY_GREENHOUSE) || bitRead(forced_greenhouse,SPRAY_GREENHOUSE)){
              digitalWrite(EV_GREENHOUSE_SPRAY,1);
              time_spray_greenhouse=time_spray_greenhouse+REFRESH_SCREEN_SECONDS;
              }
            else {digitalWrite(EV_GREENHOUSE_SPRAY,0);} 
          }
        else {digitalWrite(EV_GREENHOUSE_SPRAY,0);}
        
        /* VMC control */
        
        if (!bitRead(desactive_greenhouse,VMC_GREENHOUSE))
          {
            if (bitRead(output_greenhouse,VMC_GREENHOUSE) || bitRead(forced_greenhouse,VMC_GREENHOUSE)){
              digitalWrite(GREENHOUSE_VMC,1);
              time_vmc_greenhouse=time_vmc_greenhouse+REFRESH_SCREEN_SECONDS;
            }
            else{digitalWrite(GREENHOUSE_VMC,0);}
          }
        else{digitalWrite(GREENHOUSE_VMC,0);}
        
        /* Lamp control */
        
        if (!bitRead(desactive_greenhouse,LAMP_GREENHOUSE))
          {
            if ((bitRead(output_greenhouse,LAMP_GREENHOUSE)and v_battery>24) || bitRead(forced_greenhouse,LAMP_GREENHOUSE)){
              digitalWrite(GREENHOUSE_LAMP,1);
              time_lamp_greenhouse=time_lamp_greenhouse+REFRESH_SCREEN_SECONDS;
            }
            else{digitalWrite(GREENHOUSE_LAMP,0);}
          }
        else{digitalWrite(GREENHOUSE_LAMP,0);}

       /* Heat soil control */

               if (!bitRead(desactive_greenhouse,HEATING_GREENHOUSE))
          {
            if ((bitRead(output_greenhouse,HEATING_GREENHOUSE) and v_battery>25)|| bitRead(forced_greenhouse,HEATING_GREENHOUSE)){
              digitalWrite(GREENHOUSE_HEATING,1);
              time_heat_greenhouse=time_heat_greenhouse+REFRESH_SCREEN_SECONDS;
            }
            else{digitalWrite(GREENHOUSE_HEATING,0);}
          }
        else{digitalWrite(GREENHOUSE_HEATING,0);}
  }

}

void output_garden_control(){
if(refresh_demand==1)
  { 
      /* Spray garden control */
      if (!bitRead(desactive_garden,SPRAY_GARDEN))
        {
          if(bitRead(output_garden,SPRAY_GARDEN) || bitRead(forced_garden,SPRAY_GARDEN)|| bitRead(output_garden,CAT_PROOF_GARDEN)){
            digitalWrite(EV_GARDEN_SPRAY,1);
            time_spray_garden=time_spray_garden+REFRESH_SCREEN_SECONDS;
            }
          else {digitalWrite(EV_GARDEN_SPRAY,0);}  
        }
      else {digitalWrite(EV_GARDEN_SPRAY,0);}  
      
      /* Compost spray */
      
      if (!bitRead(desactive_garden, SPRAY_COMPOST))
        {
          if(bitRead(output_garden,SPRAY_COMPOST) || bitRead(forced_garden,SPRAY_COMPOST)){
            digitalWrite(EV_COMPOST_SPRAY,1);
            time_spray_compost=time_spray_compost+REFRESH_SCREEN_SECONDS;
            }
          else {digitalWrite(EV_COMPOST_SPRAY,0);}    
        }
      else {digitalWrite(EV_COMPOST_SPRAY,0);}
      
      /* Compost drain post */
      
      if (!bitRead(desactive_garden, PUMP_COMPOST))
        {
          if(bitRead(output_garden,PUMP_COMPOST) || bitRead(forced_garden,PUMP_COMPOST)){
            analogWrite(COMPOST_DRAIN_PUMP, 100);
            time_pump_compost=time_spray_compost+REFRESH_SCREEN_SECONDS;
            }
          else {analogWrite(COMPOST_DRAIN_PUMP, 0);} 
        }
      else {analogWrite(COMPOST_DRAIN_PUMP, 0);}
      
      
      /* heating Compost */
      
      if (!bitRead(desactive_garden, HEATING_COMPOST))
        {
          if(bitRead(output_garden,HEATING_COMPOST) || bitRead(forced_garden,HEATING_COMPOST)){
                digitalWrite(COMPOST_HEATING,true);
                time_heat_compost=time_heat_compost+REFRESH_SCREEN_SECONDS;
                }
          else{digitalWrite(COMPOST_HEATING,false);}
        }
      else{digitalWrite(COMPOST_HEATING,false);}
      
      /*  main pump control */
      if (!bitRead(desactive_garden, MAIN_PUMP))
        {
          if( digitalRead(EV_GARDEN_SPRAY)|| digitalRead(EV_GREENHOUSE_SPRAY) || digitalRead(EV_COMPOST_SPRAY)){
            digitalWrite(GARDEN_MAIN_PUMP, true);
          }
          else{digitalWrite(GARDEN_MAIN_PUMP,false);}
        }
      else{digitalWrite(GARDEN_MAIN_PUMP,false);}
  }
}
