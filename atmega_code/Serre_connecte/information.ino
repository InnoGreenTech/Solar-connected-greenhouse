void information_screen(){

if (!bitRead(flag_first_screen,INFORMATION_SCREEN)){   // If it is the first read

      tft.fillScreen(FOND);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      tft.setCursor(8,10);
      tft.print F("Information Connexion WIFI");
      
      tft.setTextSize(1);
      tft.setCursor(8,45);
      tft.print F("Adresse Ip:"); 
      tft.setCursor(8,60);  // mise en place du curseur
      tft.print(ip_address);
      tft.setCursor(8,80); // Therme générique de la qualité
      tft.print F("Passerelle :");
      tft.setCursor(8,95);  // mise en place du curseur
      tft.print(gate_way);  
      tft.setCursor(8,115); // Therme générique de la qualité
      tft.print F("Adresse MAC :");
      tft.setCursor(8,130);  // mise en place du curseur
      tft.print(mac_address);

 


/* Create Buttons */

      second_buttons_design();
     
     bitSet(flag_first_screen,INFORMATION_SCREEN); 
}
  


  if (two_buttons[ESCAPE].contains(x,y)){       
      flag_screen=0;  
      flag_first_screen=0;
      bitSet(flag_screen,MAIN_SCREEN);              //call main screen  
      }


 
  if (two_buttons[SETTING].contains(x,y)){  
      flag_screen=0;  
      flag_first_screen=0;
      index_setting=1;
      new_index=0;
      bitSet(flag_screen,SETTING_SCREEN);              //call setting screen to set WIFI
        }
      


          y=0;
          x=0;             

}
