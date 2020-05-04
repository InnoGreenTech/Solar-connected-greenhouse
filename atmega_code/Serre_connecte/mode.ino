void mode(){
  if(bitRead(refresh_demand,REFRESH_DATA))
  {
    weather();
    average_day();
    
    if (current_weather==SUNNY and forecasts_weather==SUNNY){bitClear(mode_flag,ECO_MODE);}
    else{bitSet(mode_flag,ECO_MODE);}
    if (v_battery<24){bitSet(mode_flag,SAFE_MODE);}
    else {bitClear(mode_flag,SAFE_MODE);}
  }
  }


/* current and forecasts weather, use out door imformation */

void weather(){
    
  float current_p=average_pressure[rotate_index]; 
  float last_hour_p;

  if(rotate_index+1<NUMBER_SAMPLES_HOUR){last_hour_p = average_pressure [rotate_index+1];}
  else {last_hour_p = average_pressure [0];}

  // current Weather

  if (current_p<1006){current_weather=RAIN;}
  else if (current_p<1020){current_weather=CLOUDLY;}
  else {current_weather=SUNNY;}

  float dp= last_hour_p-current_p;

  if (-0.25<dp>0.25){forecasts_weather=current_weather;}
  
  if (dp>=1 and current_p<1006 ){forecasts_weather=CLOUDLY;}
  else if (dp>=0.25){forecasts_weather=SUNNY;}
  
  if(dp<=-0.25 and current_p>1020){forecasts_weather=CLOUDLY;}
  else if(dp<=-0.25){forecasts_weather=RAIN;}
  else if(dp<=-1){forecasts_weather=THUNDERSTORM;}  
  }

/* cacul average temperature and other in one day */

void average_day(){


    if (current_sample_day<total_samples_day){
        current_sample_day++;
        if (temperature_greenhouse<560){current_average_temperature_greenhouse =  current_average_temperature_greenhouse+(temperature_greenhouse/total_samples_day);}        

        current_average_humidity_greenhouse =  current_average_humidity_greenhouse+(humidity_greenhouse/total_samples_day);

        current_average_temperature_out =  current_average_temperature_out+(temperature_out/total_samples_day);
        current_average_humidity_out =  current_average_humidity_out+(humidity_out/total_samples_day);  

        //Serial.print("prise d'un échantillon :");Serial.println(total_samples_day);
        //Serial.println(int((average_temperature_greenhouse-10)*60));
             
        }
        
    else{
        rotate_day_index++;
        if (rotate_day_index>NUMBER_SAMPLES_DAY){rotate_day_index=0;}
        
        day_temperature_greenhouse[rotate_day_index]= current_average_temperature_greenhouse;
        current_average_temperature_greenhouse=0;
        day_temperature_greenhouse[rotate_day_index]= current_average_humidity_greenhouse;
        current_average_humidity_greenhouse=0;

        day_temperature_out[rotate_day_index]= current_average_temperature_out;
        current_average_temperature_out=0;
        day_temperature_out[rotate_day_index]= current_average_humidity_out;
        current_average_humidity_out=0;
        
        current_sample_day=0;    
        }
        average_temperature_greenhouse=0;
        average_humidity_greenhouse=0;
        average_temperature_out=0;
        average_humidity_out=0;
  for(int i=0;i<NUMBER_SAMPLES_DAY;i++){
        average_temperature_greenhouse=average_temperature_greenhouse+day_temperature_greenhouse[i]/NUMBER_SAMPLES_DAY;
        average_humidity_greenhouse=average_humidity_greenhouse+day_humidity_greenhouse[i]/NUMBER_SAMPLES_DAY;     

        average_temperature_out=average_temperature_out+day_temperature_out[i]/NUMBER_SAMPLES_DAY;
        average_humidity_out=average_humidity_out+day_humidity_out[i]/NUMBER_SAMPLES_DAY;   
  }
  /*Serial.println(average_temperature_greenhouse);
  Serial.println(current_average_temperature_greenhouse);
  
  Serial.println(average_humidity_greenhouse);
  Serial.println(current_average_humidity_greenhouse);
  
  Serial.println(average_temperature_out);
  Serial.println(current_average_temperature_out);*/
}
