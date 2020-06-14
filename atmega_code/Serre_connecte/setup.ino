void setup(void){

 /*********************************************************************************************** 
  *                                   memory setting                                            *
  ***********************************************************************************************/

  
  /* Raz every memories */

  byte first_pass=EEPROM.read (MEM_SET);
  if (!first_pass==0){
    for (int a=0;a<255;a++){EEPROM.write(a,0);}
  }

  /* setting of screen */

  tft.reset();   
  uint16_t identifier=0x9341;     
  tft.begin(identifier); 
  tft.setRotation(135);           

  /* Read recorder EEPROM */

  byte mem[2];                                        // Array to read men
  long read_save;                                     // long to read save


  
  /*for (int a=0;a<4;a++){mem[a]= EEPROM.read (MEM_SETTING_TEMPEPARTURE_COMPOST+a);}
  read_save=(long)mem[0]|(long)mem[1]<<8|(long)mem[2]<<16|(long)mem[3]<<24;
  set_temperature_COMPOST= float(read_save)/1000;*/

  for (int a = 0; a < 2; a++){mem[a]= EEPROM.read (MEM_SETTING_TEMPEPARTURE_COMPOST+a);}
  set_temperature_compost= mem[0] | mem[1] << 8;
  
  for (int a = 0; a < 2; a++){mem[a]= EEPROM.read (MEM_SETTING_ECO_TEMPERATURE_COMPOST+a);}
  set_eco_temperature_compost= mem[0] | mem[1] << 8;
  
  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_HUMIDITY_COMPOST + a);} 
  set_humidity_compost = mem[0] | mem[1] << 8;

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_MOISTURE_GARDEN + a);} 
  set_moisture_garden = mem[0] | mem[1] << 8;  

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_MOISTURE_GREENHOUSE + a);} 
  set_moisture_greenhouse = mem[0] | mem[1] << 8;   

  for (int a = 0; a < 2; a++){mem[a]= EEPROM.read (MEM_SETTING_TEMPERATURE_GROUND_GREENHOUSE+a);}
  set_temperature_soil_greenhouse= mem[0] | mem[1] << 8;
  
  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_HUMIDITY_GREENHOUSE + a);} 
  set_humidity_greenhouse = mem[0] | mem[1] << 8; 
  
  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_CO2_GREENHOUSE + a);} 
  set_co2_greenhouse = mem[0] | mem[1] << 8; 
  
  for (int a = 0; a < 2; a++){mem[a]= EEPROM.read (MEM_SETTING_V_OFFSET_BATTERY  +a);}
  set_v_offset_battery = mem[0] | mem[1] << 8;

  for (int a = 0; a < 2; a++){mem[a]= EEPROM.read (MEM_SETTING_A_OFFSET_BATTERY  +a);}
  set_a_offset_battery = mem[0] | mem[1] << 8;

  for (int a = 0; a < 2; a++){mem[a]= EEPROM.read (MEM_SETTING_A_OFFSET_LOAD  +a);}
  set_a_offset_load = mem[0] | mem[1] << 8;

  for (int a = 0; a < 2; a++){mem[a]= EEPROM.read (MEM_SETTING_CAPACITY_BATTERY  +a);}
  set_capacity_battery = mem[0] | mem[1] << 8;  

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_LUMINOSITY  + a);} 
  set_luminosity = mem[0] | mem[1] << 8; 

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_DEEP_WATER + a);} 
  set_deep_water = mem[0] | mem[1] << 8; 

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_TEMPERATURE_GREENHOUSE  + a);} 
  set_temperature_greenhouse = mem[0] | mem[1] << 8; 

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_MAX_INTENSITY  + a);} 
  set_max_intensity = mem[0] | mem[1] << 8; 

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_ALTITUDE  + a);} 
  set_altitude = mem[0] | mem[1] << 8; 

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_K_MOIST_GARDEN  + a);} 
  set_k_moist_garden = mem[0] | mem[1] << 8;
  a_moist_garden=10000/(float(set_k_moist_garden)-615); 
  b_moist_garden=a_moist_garden*615;

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_K_MOIST_GREENHOUSE  + a);} 
  set_k_moist_greenhouse = mem[0] | mem[1] << 8; 
  a_moist_greenhouse=10000/(float(set_k_moist_greenhouse)-615); 
  b_moist_greenhouse=a_moist_greenhouse*615;

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_SCALE_WATER  + a);} 
  set_scale_water = mem[0] | mem[1] << 8;
  if (set_scale_water<4000){set_scale_water=7300;}     // default value  
  
  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_TARE_WATER  + a);} 
  set_tare_water = mem[0] | mem[1] << 8;  
  if (set_tare_water<500){set_tare_water=1450;}       // default value

  for (int a = 0; a < 2; a++) {mem[a] = EEPROM.read(MEM_SETTING_INITIAL_PRESSURE  + a);} 
  set_initial_pressure = mem[0] | mem[1] << 8;  
  if (set_initial_pressure<500){set_initial_pressure=1013;}       // default value
    
  Serial.begin(9600);     
  Serial1.begin(115200);    // set communication with ESP8266
  Serial2.begin(9600);    
  Serial3.begin(9600);      // Start communication with CO2 sensor  MH_Z19_RX

   /*********************************************************************************************** 
  *                                   sensors and input define                                            *
  ***********************************************************************************************/

  greenhouse_dht.begin();

  /* water level measure */
  
  pinMode(SCK_WATER, OUTPUT);
  pinMode(DATA_WATER, INPUT_PULLUP);
   
  digitalWrite(SCK, LOW); // start module
 
  /*Set and start BME280 sensor, sensor out*/

  out_sensor.settings.commInterface = I2C_MODE;  // I have worked with the example of http://gilles.thebault.free.fr/
  out_sensor.settings.I2CAddress = 0x77;
  out_sensor.settings.runMode = 3; 
  out_sensor.settings.tStandby = 0;
  out_sensor.settings.filter = 0;
  out_sensor.settings.tempOverSample = 1 ;
  out_sensor.settings.pressOverSample = 1;
  out_sensor.settings.humidOverSample = 1;

  

  delay(10);                                              // Necessary time to start sensor

  //compost_sensor.begin();
  out_sensor.begin();

  /*cat proof sensor */

  pinMode(CAT_PROOF_DETECT, INPUT);
  pinMode(CAT_PROOF_OUT,INPUT);


   /*********************************************************************************************** 
  *                                   output define                                             *
  ***********************************************************************************************/

  /* Greenhouse output*/

  pinMode(GREENHOUSE_VMC ,OUTPUT);
  pinMode(GREENHOUSE_PUMP_COOLING,OUTPUT);  // Note Pwm output
  pinMode(GREENHOUSE_FAN_COOLING,OUTPUT);
  pinMode(GREENHOUSE_LAMP,OUTPUT);
  pinMode(GREENHOUSE_HEATING,OUTPUT);
  pinMode(GREENHOUSE_HUMIDIFICATOR,OUTPUT);  

  servo_vmc.attach(GREENHOUSE_SERVO_VMC);

 /* Garden/Compost output */

  pinMode(GARDEN_MAIN_PUMP ,OUTPUT);
  pinMode(EV_GARDEN_SPRAY,OUTPUT);
  pinMode(EV_GREENHOUSE_SPRAY,OUTPUT);
  pinMode(EV_COMPOST_SPRAY,OUTPUT);
  pinMode(COMPOST_HEATING,OUTPUT);          // Note Pwm output
  pinMode(HYDROPONIE_PUMP,OUTPUT);       // Note Pwm output
  pinMode(OUT_GARDEN_SPRAY,OUTPUT);

  /* init average day */

  for (int i=0; i<NUMBER_SAMPLES_DAY;i++){
    day_temperature_greenhouse[i]=25;
    day_humidity_greenhouse[i]=70;
    day_temperature_out[i]=20;
    day_humidity_out[i]=50;   
    
  }

  wdt_enable(WDTO_4S);


}
