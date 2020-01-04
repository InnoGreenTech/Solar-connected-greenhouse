
void greenhouse_screen(){


/*********************************************************
*                  Back screen                           *
**********************************************************/


if (!bitRead(flag_first_screen,GREENHOUSE_SCREEN)){

  
  tft.fillScreen(FOND); 
  //tft.drawFastVLine(163,50,130,WHITE);
  tft.setTextSize(2);  
  tft.setTextColor(GREEN); 
  tft.setCursor(100,15);                     // Describe content
  tft.print F("SERRE");

  tft.setTextSize(1); 
  tft.setTextColor(WHITE);
  tft.setCursor(10,40); 
  tft.print F("Temperature air:");
  tft.setCursor(10,55);
  tft.print F("Humidite air:");
  tft.setCursor(10,70);
  tft.print F("C02");  
  tft.setCursor(10,90);
  tft.print F("Temperature sol:");
  tft.setCursor(10,105);
  tft.print F("Humidite sol:");
  tft.setCursor(10,125);
  tft.print F("Temperature eau:");
  tft.setCursor(10,140);
  tft.print F("Niveau eau:");
  tft.setCursor(10,160);
  tft.print F("Luminosite:");


/* Write Bottons */

      second_buttons_design();
      greenhouse_buttons_design();
      
      bitSet(flag_first_screen,GREENHOUSE_SCREEN); // Informe que la premiére lecture a été Faite
    } 

/* write current values */

if(refresh_demand==1){

  tft.setTextSize(1); 
  tft.setTextColor(GREEN,FOND);
  tft.setCursor(110,40);
  tft.print (temperature_greenhouse,2);
  tft.print F(" C ");
  tft.setCursor(110,55);
  tft.print (humidity_greenhouse);
  tft.print F(" % ");
  tft.setCursor(110,70);
  tft.print (co2_greenhouse);
  tft.print F(" ppm ");  
  tft.setCursor(110,90);
  tft.print (temperature_soil_greenhouse,2);
  tft.print F(" C ");
  tft.setCursor(110,105);
  tft.print (moisture_greenhouse);
  tft.print F(" % ");
  tft.setCursor(110,125);
  tft.print (temperature_water_greenhouse,2);
  tft.print F(" C ");
  tft.setCursor(110,140);
  tft.print (level_water_greenhouse);
  tft.print F(" Cm ");
  tft.setCursor(110,160);
  tft.print (luminosity_greenhouse);
  tft.print F(" Lux ");
  
  greenhouse_buttons_design();

}
    
/***********************************************************************************************************************************  
* Access to Greenhouse screen 
*/
  
  if(two_buttons[ESCAPE].contains(x,y))
    { 
      flag_screen=0;  
      flag_first_screen=0;
      bitSet(flag_screen,MAIN_SCREEN); 
     }

/**************************************************************************************************************************************  
*  Access SETTING SCREEN
 */
 
  if (two_buttons[SETTING].contains(x,y))
    {   
      flag_screen=0;  
      flag_first_screen=0;
      index_setting=0;
      new_index=10;
      bitSet(flag_screen,SETTING_SCREEN);
    }



/**************************************************************************************************************************************  
*  Forced buttons controle
 */

  for (int a=0; a<6; a++){
      if (six_buttons[a].contains(x,y))
        {  
          if(bitRead(forced_greenhouse,a)){bitSet(desactive_greenhouse,a);bitClear(forced_greenhouse,a);}
          else if(bitRead(desactive_greenhouse,a)){bitClear(desactive_greenhouse,a);}
          else{bitSet(forced_greenhouse,a);} 
          refresh_demand=2;
        }
    }
    
   y=0;
   x=0;  
 
}
