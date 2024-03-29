

void output_greenhouse_control(){
  
  if(bitRead(refresh_demand,REFRESH_DATA))
  
     { 
          cooling_control();
          spray_greehouse();
          vmc_control();
          lamp_control();
          heating_water_tank(1);
    }

}

void output_garden_control(){
  if(bitRead(refresh_demand,REFRESH_DATA))
    { 
  
        spray_garden();     
        spray_compost();
        hydroponie_pump();      
        main_pump();
        spray_out_garden();
        out_cooling();
        
    }
}

/* Cooling system */

        void cooling_control(){
        if (!bitRead(desactive_greenhouse,FAN_COOLING_GREENHOUSE))
          { 
            if (bitRead(output_greenhouse,FAN_COOLING_GREENHOUSE)|| bitRead(forced_greenhouse,FAN_COOLING_GREENHOUSE)) 
                    {
                      digitalWrite(GREENHOUSE_FAN_COOLING,1);
                      time_cooling_greenhouse=time_cooling_greenhouse+DELAY_REFRESH_SCREEN_SECONDS;
                    }
            else{digitalWrite(GREENHOUSE_FAN_COOLING,0);}
          }
        else{digitalWrite(GREENHOUSE_FAN_COOLING,0);}
        
        if (!bitRead(desactive_greenhouse,PUMP_COOLING_GREENHOUSE))
          {
            if (bitRead(output_greenhouse,PUMP_COOLING_GREENHOUSE) || bitRead(forced_greenhouse,PUMP_COOLING_GREENHOUSE)) 
                    {
                      analogWrite(GREENHOUSE_PUMP_COOLING,80);                                          
                    }
            else{analogWrite(GREENHOUSE_PUMP_COOLING,0);}
          }
        else{analogWrite(GREENHOUSE_PUMP_COOLING,0);}   
        }
             
/* spray system */

        void spray_greehouse(){
        
        if (!bitRead(desactive_greenhouse,SPRAY_GREENHOUSE))
          {
            if(bitRead(output_greenhouse,SPRAY_GREENHOUSE) || bitRead(forced_greenhouse,SPRAY_GREENHOUSE)){
              digitalWrite(EV_GREENHOUSE_SPRAY,1);
              time_greenhouse_spray=time_greenhouse_spray+DELAY_REFRESH_SCREEN_SECONDS;
              }
            else {digitalWrite(EV_GREENHOUSE_SPRAY,0);} 
          }
        else {digitalWrite(EV_GREENHOUSE_SPRAY,0);}
        }
        
/* VMC control */

        void vmc_control(){
        
        if (!bitRead(desactive_greenhouse,VMC_GREENHOUSE))
          {
            if (bitRead(output_greenhouse,VMC_GREENHOUSE) || bitRead(forced_greenhouse,VMC_GREENHOUSE)){
              digitalWrite(GREENHOUSE_VMC,1);
              time_vmc_greenhouse=time_vmc_greenhouse+DELAY_REFRESH_SCREEN_SECONDS;
            }
            else{digitalWrite(GREENHOUSE_VMC,0);}
          }
        else{digitalWrite(GREENHOUSE_VMC,0);}
        }
        
/* Lamp control */

        void lamp_control(){
        
        if (!bitRead(desactive_greenhouse,LAMP_GREENHOUSE))
          {
            if ((bitRead(output_greenhouse,LAMP_GREENHOUSE)and v_battery>25) || bitRead(forced_greenhouse,LAMP_GREENHOUSE)){
              digitalWrite(GREENHOUSE_LAMP,1);
              time_lamp_greenhouse=time_lamp_greenhouse+DELAY_REFRESH_SCREEN_SECONDS;
            }
            else{digitalWrite(GREENHOUSE_LAMP,0);}
          }
        else{digitalWrite(GREENHOUSE_LAMP,0);}
        }
        
/* heating tank water*/

     void heating_water_tank(int refresh){
            
      if (!bitRead(desactive_greenhouse, HEATING_WATER_TANK))
        {
          if(bitRead(output_greenhouse,HEATING_WATER_TANK) || bitRead(forced_greenhouse,HEATING_WATER_TANK)){
                if(bitRead(forced_greenhouse,HEATING_WATER_TANK)){pwm_heat_water_tank=255;}
                analogWrite(WATER_TANK_HEATING,pwm_heat_water_tank);
                if (refresh=1){time_heat_water_tank=time_heat_water_tank+DELAY_REFRESH_SCREEN_SECONDS;}
                }
          else{analogWrite(WATER_TANK_HEATING,false);}
        }
      else{analogWrite(WATER_TANK_HEATING,false);}
     }

/* Spray garden control */

      void spray_garden(){
      if (!bitRead(desactive_garden,SPRAY_GARDEN))
        {
          if(bitRead(output_garden,SPRAY_GARDEN) || bitRead(forced_garden,SPRAY_GARDEN)|| bitRead(output_garden,CAT_PROOF_GARDEN)){
            digitalWrite(EV_GARDEN_SPRAY,1);
            time_spray_garden=time_spray_garden+DELAY_REFRESH_SCREEN_SECONDS;
            }
          else {digitalWrite(EV_GARDEN_SPRAY,0);}  
        }
      else {digitalWrite(EV_GARDEN_SPRAY,0);} 
      } 
      
/* Compost spray */

      void spray_compost(){
      if (!bitRead(desactive_garden, SPRAY_COMPOST))
        {
          if(bitRead(output_garden,SPRAY_COMPOST) || bitRead(forced_garden,SPRAY_COMPOST)){
            digitalWrite(EV_COMPOST_SPRAY,1);
            time_spray_compost=time_spray_compost+DELAY_REFRESH_SCREEN_SECONDS;
            }
          else {digitalWrite(EV_COMPOST_SPRAY,0);}    
        }
      else {digitalWrite(EV_COMPOST_SPRAY,0);}
      }
      
/* hydroponie pump */

      void hydroponie_pump(){      
      if (!bitRead(desactive_garden, PUMP_HYDROPONIE))
        {
          if(bitRead(output_garden,PUMP_HYDROPONIE) || bitRead(forced_garden,PUMP_HYDROPONIE)){
            analogWrite(HYDROPONIE_PUMP, 120);
            time_pump_hydroponie=time_pump_hydroponie+DELAY_REFRESH_SCREEN_SECONDS;
            }
          else {analogWrite(HYDROPONIE_PUMP, 0);} 
        }
      else {analogWrite(HYDROPONIE_PUMP, 0);}
      }
      

      
/*  main pump control */

      void main_pump(){
      if (!bitRead(desactive_garden, MAIN_PUMP))
        {
          if( digitalRead(EV_GARDEN_SPRAY)|| digitalRead(EV_GREENHOUSE_SPRAY) || digitalRead(EV_COMPOST_SPRAY)){
            digitalWrite(GARDEN_MAIN_PUMP, true);
          }
          else{digitalWrite(GARDEN_MAIN_PUMP,false);}
        }
      else{digitalWrite(GARDEN_MAIN_PUMP,false);}
      }

/* out_garden spray*/

      void spray_out_garden(){
      if (!bitRead(desactive_garden, SPRAY_OUT_GARDEN))
        {
          if(bitRead(output_garden,SPRAY_OUT_GARDEN) || bitRead(forced_garden,SPRAY_OUT_GARDEN)|| bitRead(output_garden,CAT_PROOF_OUT_GARDEN)){
            digitalWrite(OUT_GARDEN_SPRAY,1);
            time_out_garden_spray=time_out_garden_spray+DELAY_REFRESH_SCREEN_SECONDS;
            }
          else {digitalWrite(OUT_GARDEN_SPRAY,0);}    
        }
      else {digitalWrite(OUT_GARDEN_SPRAY,0);}
      }

/* out_cooling to refresh water during the Night*/

      void out_cooling(){
      if (!bitRead(desactive_garden, COOLING_OUT))
        {
          if(bitRead(output_garden,COOLING_OUT) || bitRead(forced_garden,COOLING_OUT)){
            digitalWrite(OUT_COOLING,1);
            time_out_cooling=time_out_cooling+DELAY_REFRESH_SCREEN_SECONDS;
            }
          else {digitalWrite(OUT_COOLING,0);}    
        }
      else {digitalWrite(OUT_COOLING,0);}
      }
