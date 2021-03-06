void send_data(){

    


      String ip=WiFi.localIP().toString().c_str();    // Allow at the server to know the new address if it have changed
      String data; 
      
      /* Création des données json */

      
       
      const size_t bufferSize =JSON_OBJECT_SIZE(37);
      DynamicJsonDocument root(bufferSize);
      //DynamicJsonBuffer jsonBuffer(bufferSize);                             
      //JsonObject& root = jsonBuffer.createObject();
     root["mac_adress"]=WiFi.macAddress();
     root["ip_adress"]=ip; 

     root["p1"]=temperature_greenhouse;    
     root["p2"]=humidity_greenhouse;
     root["p3"]=co2_greenhouse;    
     root["p4"]=luminosity_greenhouse;
     root["p5"]=moisture_greenhouse;
     root["p6"]=temperature_soil_greenhouse;
     root["p7"]=temperature_water_greenhouse;
     root["p19"]=level_water_greenhouse;
        
     root["p8"]=temperature_out;
     root["p9"]=humidity_out;
     root["p18"]=pressure_out;
     root["p10"]=temperature_compost;
     root["p11"]=humidity_compost;
     root["p12"]=pressure_compost;
     root["p13"]=moisture_garden;
     root["p14"]=temperature_soil_garden;
         
     root["p15"]=average_v_battery;          
     root["p16"]=average_a_battery;
     root["p17"]=average_a_load;      
     root["a1"]=time_main_pump;
         
     root["a2"]=time_vmc_greenhouse;
     root["a3"]=time_fan_cooling_greenhouse;
     root["a4"]=time_pump_cooling_greenhouse;
     root["a5"]=time_heat_tank_water;
     root["a6"]=time_spray_greenhouse; 
     root["a7"]=time_lamp_greenhouse;
     root["a8"]=flap_ventilation_greenhouse;
     root["a9"]=time_humidificator_greenhouse;
     
     root["a10"]=time_spray_garden;
     root["a11"]=time_out_cooling;
     root["a12"]=time_spray_compost;
     root["a13"]=time_pump_hydroponie;
     root["a14"]=time_spray_out_garden;


     
     serializeJson(root,data);    
     //root.printTo(data);
     String adresse="http://";
     adresse+=ip_server;
     adresse+="/InnoGreenTech/controller/json_probe.php";
     String data1= "data=";
     data1 +=data;
     //Serial.println(data1);

     HTTPClient http;
     int httpCode = 0;
     http.begin(adresse);
     http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //http.addHeader("Content-Type", "application/json");
     httpCode = http.POST(data1);
     String payload = http.getString();
     //Serial.println(httpCode);   //Print HTTP return code
     //Serial.println(payload);
     http.end();  //Close connection 
     last_message= millis();
     average_v_battery=0;          
     average_a_battery=0;
     average_a_load=0;
     index_average=0; 
     time_pump_hydroponie_1=0;
     time_heat_tank_water_1=0;
     time_spray_compost_1=0;   
     time_spray_garden_1=0;
     time_spray_greenhouse_1=0;
     time_lamp_greenhouse_1=0;
     time_fan_cooling_greenhouse_1=0;
     time_pump_cooling_greenhouse_1=0;
     time_vmc_greenhouse_1=0;
     time_humidificator_greenhouse_1=0;
     time_main_pump_1 =0;
     time_spray_out_garden_1=0;        
     time_pump_hydroponie=0;
     time_heat_tank_water=0;
     time_spray_compost=0;   
     time_spray_garden=0;
     time_spray_greenhouse=0;
     time_lamp_greenhouse=0;
     time_fan_cooling_greenhouse=0;
     time_pump_cooling_greenhouse=0;
     time_vmc_greenhouse=0;
     time_humidificator_greenhouse=0;
     time_main_pump=0;
     time_spray_out_garden=0;  
  
}
