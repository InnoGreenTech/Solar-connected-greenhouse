/***************************************
*     Main soft                         *
****************************************/

void loop(void){


      
  if (bitRead(refresh_demand,UPDATE_SCREEN)){bitSet(refresh_demand,REFRESH_SCREEN);}
   
  if (millis()>refresh_datas+DELAY_REFRESH_SCREEN){              // demand a refresh screen and lecture of sensor
      bitSet(refresh_demand,REFRESH_DATA);
      bitSet(refresh_demand,REFRESH_SCREEN);                  
      refresh_datas=millis();
      number_of_samples ++;      
    }  
  greenhouse_gest();
  tactil ();

  garden_gest();
  tactil ();
  
   /* save solar energy in the water */
  energy_saver();
  tactil ();


  mode();
  tactil ();

  output_greenhouse_control();
  tactil ();

  output_garden_control();

  tactil ();

  recep_wifi();
  
  tactil ();


  send_data();

  tactil ();
  switch(flag_screen){

             case B00000001:
                main_screen();
                break;

             case B00000010:
                greenhouse_screen();
                break;
        
             case B00000100:
                compost_screen();
                break;
  
             case B00001000:
                 garden_screen();
                 break;

             case B00010000:
                 setting_screen();
                 break;  
                 
             case B10000000:
                 information_screen();
                 break;                               

             default:
                  main_screen();
                  break;
            }


 if(bitRead(refresh_demand,REFRESH_SCREEN)){bitClear(refresh_demand,REFRESH_SCREEN);}
 if(bitRead(refresh_demand,REFRESH_DATA)){bitClear(refresh_demand,REFRESH_DATA);}



 wdt_reset();

}
