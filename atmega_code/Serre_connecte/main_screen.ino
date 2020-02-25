
/*********************************
*             Page d'accueil     *
**********************************/

void main_screen(){


/*********************************************************
*                  Back screen                           *
**********************************************************/


if (!bitRead(flag_first_screen,MAIN_SCREEN)){

  
  tft.fillScreen(FOND); 
  tft.drawFastVLine(160,10,160,WHITE);
  tft.drawFastHLine(180,105,120,WHITE);
  tft.setTextSize(2); 
  tft.setTextColor(GREEN); 
  tft.setCursor(50,10);                     // Describe content
  tft.print F("SERRE");
  tft.setTextColor(CYAN);
  tft.setCursor(185,10);
  tft.print F("JARDINIERE");
  tft.setTextColor(YELLOW);
  tft.setCursor(195,115);
  tft.print F("COMPOSTE");
  
  
  tft.setTextSize(1); 
  tft.setTextColor(WHITE);
  tft.setCursor(10,50); 
  tft.print F("Temperature air:");
  tft.setCursor(10,65);
  tft.print F("Humidite air:");  
  tft.setCursor(10,85);
  tft.print F("Temperature sol:");
  tft.setCursor(10,100);
  tft.print F("Humidite sol:");
  tft.setCursor(10,120);
  tft.print F("Temperature eau:");
  tft.setCursor(10,135);
  tft.print F("Niveau eau:");
  tft.setCursor(10,155);
  tft.print F("Tension batterie:");
  

  tft.setCursor(175,50); 
  tft.print F("Temperature ext:");
  tft.setCursor(175,65);
  tft.print F("Humidite ext:");  
  tft.setCursor(175,85);
  tft.print F("Humidite sol:");

  tft.setCursor(175,145); 
  tft.print F("Temperature:");
  tft.setCursor(175,160);
  tft.print F("Humidite:");  






/* Write Bottons */
      main_buttons_design();

bitSet(flag_first_screen,MAIN_SCREEN); 

    } 



/****************************************************
 *                Write  information                *
 ****************************************************/

if(bitRead(refresh_demand,REFRESH_SCREEN)){
    
  tft.setTextSize(1); 
  tft.setTextColor(GREEN,FOND);
  tft.setCursor(110,50);
  tft.print (temperature_greenhouse,2);
  tft.print F(" C ");
  tft.setCursor(110,65);
  tft.print (humidity_greenhouse,1);
  tft.print F(" % ");  
  
  tft.setCursor(110,85);
  tft.print (temperature_soil_greenhouse,2);
  tft.print F(" C ");
  tft.setCursor(110,100);
  tft.print (moisture_greenhouse);
  tft.print F(" % ");
  tft.setCursor(110,120);
  tft.print (temperature_water_greenhouse,2);
  tft.print F(" C ");
  tft.setCursor(110,135);
  tft.print (level_water_greenhouse,1);
  tft.print F(" Cm ");
  tft.setCursor(110,155);
  tft.print (v_battery,2);
  tft.print F(" V ");

  tft.setCursor(270,50); 
  tft.print (temperature_out,2);
  tft.print F(" C ");
  tft.setCursor(270,65);
  tft.print (humidity_out);
  tft.print F(" % ");  
  tft.setCursor(270,85);
  tft.print (moisture_garden);
  tft.print F(" % ");
  tft.setCursor(240,40);
  tft.print (weather_string[forecasts_weather-1]);

  tft.setCursor(270,145);
  tft.print (temperature_compost,2); 
  tft.print F(" C ");
  tft.setCursor(270,160);
  tft.print (humidity_compost);
  tft.print F(" % ");  
  
} 
/***********************************************************************************************************************************  
* Access to Greenhouse screen 
*/
  
  if(four_buttons[GREENHOUSE].contains(x,y))
    { 
      flag_screen=0;  
      flag_first_screen=0;
      refresh_demand=2;
      bitSet(flag_screen,GREENHOUSE_SCREEN); 
    }

/**************************************************************************************************************************************  
*  Access to compost screen
 */
 
  if (four_buttons[COMPOST].contains(x,y))
    {    
      flag_screen=0;  
      flag_first_screen=0;
      refresh_demand=2;
      bitSet(flag_screen,COMPOST_SCREEN);
    }
  
/***********************************************************************************************************************************
* Access to Garden screen
*/
 
  if (four_buttons[GARDEN].contains(x,y))
    {   
      flag_screen=0;
      refresh_demand=2;
      flag_first_screen=0;
      bitSet(flag_screen,GARDEN_SCREEN);
    }

/***********************************************************************************************************************************
* Access to Wifi screen
*/
 
  if (four_buttons[INFORMATION].contains(x,y))
    { 
      Serial.println("demande ecrans");  
      flag_screen=0;  
      flag_first_screen=0;
      refresh_demand=2;
      bitSet(flag_screen,INFORMATION_SCREEN);
    }

   y=0;
   x=0;  
 
}
  
