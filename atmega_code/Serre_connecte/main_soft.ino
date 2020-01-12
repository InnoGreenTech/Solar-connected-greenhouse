/***************************************
*     Main soft                         *
****************************************/

void loop(void){

      
  if (refresh_demand==2){refresh_demand=1;}
   
  if (millis()>refresh_datas+REFRESH_SCREEN){              // demand a refresh screen and lecture of sensor
      refresh_demand=1;                   
      refresh_datas=millis();
      number_of_samples ++;      
    }
  
  tactil ();
  
  greenhouse_gest();
  
  garden_gest();

  output_greenhouse_control();

  output_garden_control();

recep_wifi();
  send_data();

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


 if(refresh_demand==1){refresh_demand=0;}

}
