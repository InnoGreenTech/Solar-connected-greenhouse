void setting_screen(){


/*********************************************************
*                  Back screen                           *
**********************************************************/


if (!bitRead(flag_first_screen,SETTING_SCREEN)){

  
      tft.fillScreen(FOND);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      tft.setCursor(70,10);
      tft.print F("SETTING ");
  

/* Write Bottons */

    setting_buttons_design();

    choice_buttons_design();

    bitSet(flag_first_screen,SETTING_SCREEN);

    } 

/* read and adjust information */


char info_set[30][18]={"Temp COMPOST     ","Eco Temp COMPOST ","Hum COMPOST      ","Moist Garden     ","Altitude         ","Kmoist  garden   ","Empty  6         ","Empty  7         ","Empty  8         ","Empty  9         ",
                       "Moist Greenhouse ","Temp soil House  ","Hum Greenhouse   ","Temp greenhouse  ","C02 Greenhouse   ","Deep tank water  ","Kmoist greenhouse","Empty  17        ","Empty  18        ","Empty  19        ",
                       "V offset Battery ","A offset Battery ","Capacity Battery ","A offset load    ","Luminosity       ","Empty  25        ","Empty  26        ","Empty  27        ","Empty  28        ","Empty  29        "};

int mem_address[30]={MEM_SETTING_TEMPEPARTURE_COMPOST ,MEM_SETTING_ECO_TEMPERATURE_COMPOST ,MEM_SETTING_HUMIDITY_COMPOST ,MEM_SETTING_MOISTURE_GARDEN,MEM_SETTING_ALTITUDE ,MEM_SETTING_K_MOIST_GARDEN,255,255,255,255,
                       MEM_SETTING_MOISTURE_GREENHOUSE,MEM_SETTING_TEMPERATURE_GROUND_GREENHOUSE,MEM_SETTING_HUMIDITY_GREENHOUSE,MEM_SETTING_TEMPERATURE_GREENHOUSE,MEM_SETTING_CO2_GREENHOUSE,MEM_SETTING_DEEP_WATER,MEM_SETTING_K_MOIST_GREENHOUSE,255,255,255,
                       MEM_SETTING_V_OFFSET_BATTERY,MEM_SETTING_A_OFFSET_BATTERY,MEM_SETTING_CAPACITY_BATTERY,MEM_SETTING_A_OFFSET_LOAD,MEM_SETTING_LUMINOSITY,255,255,255,255,255};
                       
if (!(new_index==index_setting)){
      index_setting=new_index;                      
      tft.setTextColor(WHITE,FOND);
      tft.setTextSize(2);
      tft.setCursor(30,50);
      String infos=info_set[index_setting];
      tft.print(infos);
      byte read_mem[2];
      for (int a=0;a<2;a++){read_mem[a]=EEPROM.read (mem_address[index_setting]+a);}
      setting= read_mem[0] | read_mem[1] << 8;
      tft.setTextColor(CYAN,FOND);
      tft.setTextSize(3);
      new_setting=1;
      }

if (new_setting==1){
  
      tft.setCursor(85,100);
      tft.print("   ");
      tft.setCursor(85,100);
      tft.print(setting);
      new_setting=0;
      }
    
/***********************************************************************************************************************************  
* Adjust values buttons
*/
  
  if(four_buttons[ESC].contains(x,y))
    { 
      if (reset_demand==1){resetFunc();}
      flag_screen=0;  
      flag_first_screen=0;
      bitSet(flag_screen,MAIN_SCREEN); 
     }

  if(four_buttons[MORE].contains(x,y))
    { 
      new_setting=1;
      setting++;
     }

  
  if(four_buttons[LESS].contains(x,y))
    { 
      new_setting=1;
      setting--;
     }

  if(four_buttons[OK].contains(x,y))
    { 
      tft.setTextColor(GREEN,FOND);
      new_setting=1;
      int data=setting;
      for (int a=0;a<2;a++){EEPROM.write(mem_address[index_setting]+a,data);data=data>>8;}
      reset_demand=1;

     }


/**************************************************************************************************************************************  
*  Found parameter button
*/
 
  if (two_buttons[UP].contains(x,y))
    {   
        if (index_setting<29){new_index=index_setting+1;}
        else{new_index=1;}
    }
   if (two_buttons[DOWN].contains(x,y))
    {   
        if (index_setting>0){new_index=index_setting-1;}
        else{new_index=29;}
    }

   y=0;
   x=0;  
 
}
