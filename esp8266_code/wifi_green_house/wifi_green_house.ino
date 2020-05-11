/************************************************************************************
    
    <Automatic greenhouse and greengarden control,>
    Copyright (C) <2019>  <Fabrice BAUDIN>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    info@InnoGreenTech.fr

****************************************************************************************/


/*******************************
 *    utilities                *
 *******************************/
 
 
    #include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
    #include <wchar.h> 
    #include <WString.h>
    #include <ESP8266WebServer.h>
    #include <DNSServer.h>
    #include <ESP8266Ping.h>
    #include <ESP8266HTTPClient.h>
    #include <ESP8266HTTPUpdateServer.h>
    
    #include <ArduinoJson.h>
    
    #include <EEPROM.h> // Gestion de la mémoire de type eeprom pour la sauvegarde des choix
    
    #define MEM_NAME_MODULE     1   //Name of module
    #define MEM_ADRESS_SERVER   22  // adress of server php
    #define MEM_PORT_SERVER     43  // Port of server
    #define MEM_PERIOD          50  // Period to send datas in seconds
    #define MEM_SSID            70
    #define MEM_PASSWORD        170 //



/****************************************************** 
 *      Keys of communication with ESP8266            *
 ******************************************************/

    #define CODE_COMMAND_INFO                           "$I$"
    #define CODE_COMMAND_READ                           "$R$" 
    #define CODE_COMMAND_WRITE                          "$W$"       
    
    #define CODE_TEMPERATURE_COMPOST                    10     
    #define CODE_HUMIDITY_COMPOST                       11
    #define CODE_PUMP_HYDROPONIE                        12
    #define CODE_HEAT_COMPOST                           13
    #define CODE_SETTING_TEMPERATURE_COMPOST            14
    #define CODE_SETTING_HUMIDITY_COMPOST               15 
    #define CODE_ECO_TEMPERATURE_COMPOST                16
    #define CODE_SPRAY_COMPOST                          17
    #define CODE_CLEAN_COMPOST                          18
    #define CODE_OUTPUT_GARDEN                          19
    
    
    #define CODE_TEMPERATURE_OUT                        20
    #define CODE_HUMIDITY_OUT                           21
    #define CODE_LEVEL_WATER_GARDEN                     22
    #define CODE_SPRAY_GARDEN                           23
    #define CODE_TEMPERATURE_SOIL_GARDEN                24
    #define CODE_MOISTURE_GARDEN                        25
    #define CODE_SETTING_MOISTURE_GARDEN                26
    #define CODE_LUMINOSITY_GREENHOUSE                  27
    #define CODE_PRESSURE_OUT                           28  
    #define CODE_SETTING_ALTITUDE                       29 
    
    #define CODE_TEMPERATURE_GREENHOUSE                 30
    #define CODE_HUMIDITY_GREENHOUSE                    31
    #define CODE_CO2_GREENHOUSE                         32
    #define CODE_LEVEL_WATER_GREENHOUSE                 33
    #define CODE_SPRAY_GREENHOUSE                       34
    #define CODE_LAMP_GREENHOUSE                        35
    #define CODE_HEAT_GREENHOUSE                        36
    #define CODE_FAN_COOLING_GREENHOUSE                 37
    #define CODE_PUMP_COOLING_GREENHOUSE                38
    #define CODE_TEMPERATURE_WATER_GREENHOUSE           39
    #define CODE_TEMPERATURE_SOIL_GREENHOUSE            40
    #define CODE_MOISTURE_GREENHOUSE                    41
    #define CODE_VMC_GREENHOUSE                         42
    #define CODE_FLAP_VENTILATION_GREENHOUSE            43
    #define CODE_HUMIDIFICATOR_GREENHOUSE               44
    #define CODE_SETTING_MOISTURE_GREENHOUSE            45
    #define CODE_SETTING_TEMPERATURE_SOIL_GREENHOUSE    46
    #define CODE_SETTING_HUMIDITY_GREENHOUSE            47
    #define CODE_SETTING_CO2_GREENHOUSE                 48
    #define CODE_OUTPUT_GREENHOUSE                      49
    
    #define CODE_DATE                                   50
    #define CODE_HEURE                                  51
    #define CODE_IP                                     52
    #define CODE_GATE_WAY                               53
    #define CODE_MAC                                    54
    #define CODE_PERIOD_SEND                            55
    
    #define CODE_AVERAGE_V_BATTERY                      60
    #define CODE_GENERAL_PUMP                           61
    #define CODE_AVERAGE_A_BATTERY                      62
    #define CODE_AVERAGE_A_LOAD                         63
    #define CODE_SETTING_V_OFFSET_BATTERIE              64
    #define CODE_SETTING_A_OFFSET_BATTERIE              65
    #define CODE_SETTING_A_OFFSET_LOAD                  66
    #define CODE_SETTING_CAPACITY_BATTERIE              67

    #define CODE_SPRAY_OUT_GARDEN                       70


/**************************************************
 *                RAM Memory map                  *
 **************************************************/

/*input Modul Compost/garden*/

    float   temperature_compost;
    int     humidity_compost;
    int     pressure_compost=1000;
    
    float   a_battery;
    float   average_a_battery;
    float   a_load;
    float   average_a_load;
    float   v_battery;
    float   average_v_battery;
    
    float   temperature_out;
    int     humidity_out;
    int     pressure_out;
    int     moisture_garden;
    float   temperature_soil_garden;
    int     level_water_garden;
    byte    cat_proof;

/*input modul greenhouse*/

    float   temperature_greenhouse;
    int     humidity_greenhouse;
    int     level_water_greenhouse;
    float   temperature_water_greenhouse;
    float   temperature_soil_greenhouse;
    int     moisture_greenhouse;
    int     co2_greenhouse;
    int     luminosity_greenhouse;
     


/* output modul greenhouse*/

    byte    output_greenhouse=0;          
    byte    forced_greenhouse=0;                  // control if the forced mode is activate
    byte    desactive_greenhouse=0;

    unsigned int time_heat_greenhouse;
    unsigned int time_fan_cooling_greenhouse;
    unsigned int time_pump_cooling_greenhouse;
    unsigned int time_spray_greenhouse;
    unsigned int time_vmc_greenhouse;
    unsigned int time_lamp_greenhouse;
    unsigned int time_humidificator_greenhouse;
    
    int          flap_ventilation_greenhouse;

    unsigned int time_heat_greenhouse_1;
    unsigned int time_fan_cooling_greenhouse_1;
    unsigned int time_pump_cooling_greenhouse_1;
    unsigned int time_spray_greenhouse_1;
    unsigned int time_vmc_greenhouse_1;
    unsigned int time_lamp_greenhouse_1;
    unsigned int time_humidificator_greenhouse_1;
    
/* output modul garden mode */

    byte    output_garden=0;                   // a bit by output tor
    byte    forced_garden=0;
    byte    desactive_garden=0;

    unsigned int time_main_pump=0;
    unsigned int time_spray_compost=0;
    unsigned int time_heat_compost=0;
    unsigned int time_pump_hydroponie=0;
    unsigned int time_spray_garden=0;
    unsigned int time_spray_out_garden=0;

    unsigned int time_main_pump_1=0;
    unsigned int time_spray_compost_1=0;
    unsigned int time_heat_compost_1=0;
    unsigned int time_pump_hydroponie_1=0;
    unsigned int time_spray_garden_1=0;
    unsigned int time_spray_out_garden_1=0;
    
/* String for commnunication */

    String  date;             
    String  currently_time;            
    String  gate_way; 
 



/**************************************************
 *                RAM Memory for setting          *
 **************************************************/


    int     set_temperature_compost;
    int     set_eco_temperature_compost;
    int     set_humidity_compost; 
    int     set_moisture_garden;
    int     set_moisture_greenhouse;
    int     set_temperature_soil_greenhouse;
    int     set_temperature_greenhouse;
    int     set_humidity_greenhouse;
    int     set_co2_greenhouse;
    int     set_v_offset_battery;
    int     set_a_offset_load;
    int     set_a_offset_battery; 
    int     set_capacity_battery;
    int     set_max_intensity;
    int     set_luminosity;
    int     set_deep_water;
    
    int     setting;


 

    int           period;                   // period to sent datas at server
    unsigned long delay_sent;               // delay to send a new message in milliseconds
    unsigned long last_message;
    int           index_average;

    int index_sent=0;                           //allow to sent data one by one with PERIOD_SENT bettween each
    #define PERIOD_SENT 1000                     //one information every 100 ms;
    unsigned long period_sent=0;                //control the last message
    unsigned long number_of_samples;            //Number of samples between two sender 

    
    
    
    char          name_module[20];          // name of module
    String        ref_module;               // référence du module
    String        version_module;           // version of module
    char          ip_server[15];            // adress ip of the module
    int unsigned  port_server;              // port of server
    String        local_mac;                // adress mac of the module
    String        local_ip;                 // adress ip of module


    String        read_mem;                 // Variable pour la réception sur le port série
    int           code;                     // Variable code pour l'échange d'information
    
    
    
    ESP8266WebServer server(80); 
    
    String      ssid="";
    String      password="";
    
    #include    <TimeLib.h>              // Use for take date in internet
    #include    <NtpClientLib.h>

/* setting to update server */

    const char* update_path = "/firmware";
    const char* update_username = "innogreentech";
    const char* update_password = "innogreentech";
    
    ESP8266HTTPUpdateServer httpUpdater;

void setup() {

              Serial.begin(115200);
              Serial.setDebugOutput(0);
              delay(10);
              Serial.println("");
              /* Read EEPROM */
            
              EEPROM.begin(256);                             
             
              
              char carac='1';   // Name of module
              int a=0;
              String read_mem="";
              while (!(carac=='\0')&&a<20){carac=char (EEPROM.read(MEM_NAME_MODULE+a));read_mem+= carac; a++;} 
              if ( a==20){read_mem=F("InnoGreenTech");}
              int c = read_mem.length() + 1;                               // longueur de la chaîne de caractéres
              read_mem.toCharArray(name_module, c); 
             // Serial.println(name_module);        
              
              read_mem="";    // read memory ip adress server
              carac='1';
              a=0;
              while (!(carac=='\0')&&a<20){carac=char (EEPROM.read(MEM_ADRESS_SERVER+a));read_mem+= carac; a++;}
              if (a==20){read_mem=F("InnoGreenTech");} 
              c = read_mem.length() + 1;       
              read_mem.toCharArray(ip_server, c);
              //  Serial.println(ip_server);     

                         
              byte mem[2];
              for (int a=0;a<3;a++){mem[a]= EEPROM.read(MEM_PORT_SERVER+a);}     // load the port server         
              port_server= mem[0]|mem[1]<<8;
              
              for (int a=0;a<3;a++){mem[a]= EEPROM.read(MEM_PERIOD+a);}          // load the time period
              period= mem[0]|mem[1]<<8;
              delay_sent=period*1000;

              carac='1';                
              a=0;
              while (!(carac=='\0')&&a<100){carac=char (EEPROM.read(MEM_SSID+a));
              if (!(carac=='\0')){ssid +=carac;} a++;}  //récupération du lien d'information
              if (ssid=='\0'||a>50){ssid=F("");}
            
              carac='1';
              a=0;
              while (!(carac=='\0')&&a<100){carac=char (EEPROM.read(MEM_PASSWORD+a));
              if (!(carac=='\0')){password +=carac;} a++;}  //récupération du lien d'information
              if (password=='\0'||a>50){password=F("");}




           /*Connexion wifi*/
           
           WiFi.mode(WIFI_STA);
           
           c =ssid.length()+1;
           char char_ssid[50];
           ssid.toCharArray(char_ssid, c);

           c =password.length()+1;
           char char_password[50];
           password.toCharArray(char_password, c);

        
           WiFi.begin(char_ssid,char_password);
           
             unsigned long time_out_connection = millis();
              while (WiFi.status() != WL_CONNECTED)
              {
                if (millis() - time_out_connection > 20000)
                {
                  Serial.println F("");
                  Serial.println F ("connection Wifi fail !");
            
                  break;
                }
                delay(100);
                Serial.print('-');
              }
           
           if ( WiFi.status()!= WL_CONNECTED)
        
              {
                Serial.println F ("Open setting gate !");
                WiFi.disconnect();
                WiFi.mode(WIFI_AP); 
                delay(200);
                WiFi.softAP("InnoGreenTech", "innogreentech");
                server.on ( "/index.html", handleRoot );    // go to set up wifi page
                delay(100);
                server.on ("/style.css", cssRoot);     // envoi au fichier de configuration de style
                local_mac = WiFi.macAddress();
                delay(100);
                server.begin();

              
              }

             else

             {
           
              
              /*Read the houre and date on internet */
            
              NTP.begin("pool.ntp.org", 1, true);  //configuration de la récupération de la date,  Serveur+1 heure, Heure été/hivers
              NTP.setInterval(3600);                // Toutes les heures
                      
              /*information of module*/

              local_ip=WiFi.localIP().toString().c_str();              
              local_mac=WiFi.macAddress();//.toString().c_str();
              gate_way=WiFi.gatewayIP().toString().c_str();
              ref_module="Greenhouse";
              version_module="V1";

              Serial.print(F("référence:"));Serial.println(ref_module);
              Serial.print(F("Version:"));Serial.println(version_module);
              Serial.print(F("Adresse IP:"));Serial.println(local_ip);
              Serial.print(F("Adresse MAC:"));Serial.println(local_mac); 
              Serial.println(WiFi.gatewayIP());
              Serial.println(WiFi.dnsIP(1));             
                    
                          
              /* setting of web server */
              
              server.on ( "/index.html", indexRoot );    // Renvoi à la page de index
               delay(100);
              server.on ( "/", indexRoot );    // Renvoi à la page de index
              delay(100);
              server.on ( "/add_module.csv", add_module );    // Page for add or modify  module by php server 
              delay(100);
              server.on ("/style.css", cssRoot);     // envoi au fichier de configuration de style
              delay(100);
               
              httpUpdater.setup(&server, update_path, update_username, update_password);
             }
              
              /*listen on the server*/
              
              server.begin();

              
              }


void loop() {

            server.handleClient();
            recep_data();
            send_information();
            if (millis()>last_message+delay_sent){send_data();}
  
            }
