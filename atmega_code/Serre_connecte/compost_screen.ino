
void compost_screen(){

/**************************************************************************************************************************************  
*  Forced buttons controle
 */
  for (int a=0; a<6; a++){
      if (six_buttons[a].contains(x,y))
        {   
          if(bitRead(forced_garden,a)){bitSet(desactive_garden,a);bitClear(forced_garden,a);}
          else if(bitRead(desactive_garden,a)){bitClear(desactive_garden,a);}
          else{bitSet(forced_garden,a);}
          garden_buttons_design();
        }
    }
    

/*********************************************************
*                  Back screen                           *
**********************************************************/


if (!bitRead(flag_first_screen,COMPOST_SCREEN)){

  
  tft.fillScreen(FOND); 
  tft.setTextSize(2);  
  tft.setTextColor(YELLOW); 
  tft.setCursor(50,10);                     // Describe content
  tft.print F("COMPOSTE");

  tft.setTextSize(1); 
  tft.setTextColor(WHITE);
  tft.setCursor(10,50); 
  tft.print F("Temperature:");
  tft.setCursor(10,65);
  tft.print F("Humidite:");
  
  tft.setCursor(10,100);
  tft.print F("Tension batterie:");
  tft.setCursor(10,115);
  tft.print F("Courant batterie:");
  tft.setCursor(10,130);
  tft.print F("Courant utilise:");



/* Write Bottons */

      second_buttons_design();
      
      bitSet(flag_first_screen,COMPOST_SCREEN);
    } 

/* write current values */

if(bitRead(refresh_demand,REFRESH_SCREEN)){

  garden_buttons_design();
  tft.setTextSize(1); 
  tft.setTextColor(GREEN,FOND);
  
  tft.setCursor(120,50);
  tft.print (temperature_compost,2); 
  tft.print F(" C ");
  tft.setCursor(120,65);
  tft.print (humidity_compost);
  tft.print F(" % ");
  
  tft.setCursor(120,100);
  tft.print (v_battery,2);
  tft.print F(" V ");
  tft.setCursor(120,115);
  tft.print (a_battery,2);
  tft.print F(" A ");
  tft.setCursor(120,130);
  tft.print (a_load,2);
  tft.print F(" A ");

  
     
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
      index_setting=1;
      new_index=0;
      bitSet(flag_screen,SETTING_SCREEN);
    }
  


   y=0;
   x=0;  
 
}
