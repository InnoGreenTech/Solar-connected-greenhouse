
void garden_screen(){


/*********************************************************
*                  Back screen                           *
**********************************************************/


if (!bitRead(flag_first_screen,GARDEN_SCREEN)){

  
  tft.fillScreen(FOND); 
  tft.setTextSize(2);   
  tft.setTextColor(CYAN); 
  tft.setCursor(50,10);                     // Describe content
  tft.print F("JARDINIERE");

  tft.setTextSize(1); 
  tft.setTextColor(WHITE);
  tft.setCursor(10,50); 
  tft.print F("Temperature:");
  tft.setCursor(10,65);
  tft.print F("Humidite:");

  tft.setCursor(10,90);
  tft.print F("Temperature sol:");
  tft.setCursor(10,105);
  tft.print F("Humidite sol:");
  tft.setCursor(10,120);
  tft.print F("Cat proof:");
  
  tft.setCursor(10,150);
  tft.print F("Niveau eau:");



/* Write Bottons */

      second_buttons_design();
      garden_buttons_design();
      bitSet(flag_first_screen,GARDEN_SCREEN);
    } 

 
/* write current values */

if(bitRead(refresh_demand,REFRESH_SCREEN)){
  
  garden_buttons_design();
  tft.setTextSize(1); 
  tft.setTextColor(GREEN,FOND);

  tft.setCursor(120,50); 
  tft.print (temperature_out,2);
  tft.print F(" C ");
  tft.setCursor(120,65);
  tft.print (humidity_out);
  tft.print F(" % ");

  tft.setCursor(120,90);
  tft.print (temperature_soil_garden,2);
  tft.print F(" C ");
  tft.setCursor(120,105);
  tft.print (moisture_garden);
  tft.print F(" % ");
  tft.setCursor(120,120);
  tft.print (cat_proof);
  
  
  tft.setCursor(120,150);
  tft.print (level_water_greenhouse);
  tft.print F(" Cm ");

}


/***********************************************************************************************************************************  
* Access to main screen 
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
      new_index=20;
      bitSet(flag_screen,SETTING_SCREEN);
    }

/**************************************************************************************************************************************  
*  Forced buttons controle
 */

  for (int a=0; a<6; a++){
      if (six_buttons[a].contains(x,y))
        {   
          if(bitRead(forced_garden,a)){bitSet(desactive_garden,a);bitClear(forced_garden,a);}
          else if(bitRead(desactive_garden,a)){bitClear(desactive_garden,a);}
          else{bitSet(forced_garden,a);}
          refresh_demand=2;
        }
    }

   y=0;
   x=0;  
 
}
