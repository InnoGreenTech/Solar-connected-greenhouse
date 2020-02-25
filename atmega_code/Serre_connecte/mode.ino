void mode(){
  if(bitRead(refresh_demand,REFRESH_DATA))
  {
    weather();
    
    if (current_weather==SUNNY and forecasts_weather==SUNNY){bitClear(mode_flag,ECO_MODE);}
    else{bitSet(mode_flag,ECO_MODE);}
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
