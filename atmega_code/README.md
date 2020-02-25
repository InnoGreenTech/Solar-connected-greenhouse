 /*********************************************************************************************** 
  *                                   output define                                             *
  ***********************************************************************************************/

/* Greenhouse card output*/

    #define GREENHOUSE_VMC           O2_2         
    #define GREENHOUSE_PUMP_COOLING  O2_3
    #define GREENHOUSE_FAN_COOLING   O2_4
    #define GREENHOUSE_LAMP          O2_1
    #define GREENHOUSE_HEATING       O2_0  
    #define GREENHOUSE_HUMIDIFICATOR O2_5
    #define GREENHOUSE_SERVO_VMC     O2_6 

/* Garden card output*/

    #define GARDEN_MAIN_PUMP        O1_0
    #define EV_GARDEN_SPRAY         O1_1
    #define EV_GREENHOUSE_SPRAY     O1_5
    #define EV_COMPOST_SPRAY        O1_4
    #define COMPOST_HEATING         O1_3
    #define COMPOST_DRAIN_PUMP      O1_2


 /*********************************************************************************************** 
  *                                   sensors define                                            *
  ***********************************************************************************************/



  /* Greenhouse sensors*/

    DHT greenhouse_dht(I2_0,DHT22);     // Sensor for humidity and temperature
    
    #define V_BATTERY             A2_4
    #define MOISTURE_GREENHOUSE   A2_0
    #define LUMINOSITY_GREENHOUSE A2_1
    
    DS18B20 onewire_greenhouse(I2_4);  // define the bus of one Wire of the green_house card
    uint8_t address_soil_greenhouse[] ={ 0x28, 0x2F, 0xBC, 0x79, 0x97, 0x08, 0x03, 0x1F};
    uint8_t address_water_greenhouse[] = { 0x28, 0xBF, 0x7B, 0x79, 0x97, 0x05, 0x03, 0x54};

    //Broches sonar for level of water

    #define   TRIGGER_SONAR   I2_3// Broche TRIGGER
    #define   ECHO_SONAR      I2_2// Broche ECHO
    NewPing   water_level(TRIGGER_SONAR,ECHO_SONAR);

/* Garden and lompricomposte sensors */

    #define MOISTURE_GARDEN     A1_4
    #define INTENSITY_BATTERY   A1_1
    #define INTENSITY_LOAD      A1_2   
    #define CAT_PROOF_DETECT    I1_1
    

    DS18B20 onewire_garden(I1_4);       //define the bus of the one Wire of the garden
    uint8_t address_soil_garden[] = {  0x28,  0x7D,  0x97,  0x79,  0x97,  0x7,  0x3,  0xCF};

    BME280  compost_sensor;             // BME280 sensor
    BME280  out_sensor;

    /**************************************************
 *    Connected map of composter modul            *
 **************************************************/

    #define RX1   17     //Serial communication Serial2
    #define TX1   16     
    
    #define SCL1  SCL      //I²C BUS
    #define SDA1  SDA
    
    #define A1_0  A6      //Charge battery control
    
    #define A1_1  A7      //Analog input, you can use it like a digital input
    #define A1_2  A8
    #define A1_3  A9
    #define A1_4  A10
    
    #define I1_0  32      //Digital input
    #define I1_1  34
    #define I1_2  36
    #define I1_3  38
    #define I1_4  40
    
    #define O1_0  44      //pwm output connected on a mofset
    #define O1_1  31        //Power output connected on a mofset
    #define O1_2  33
    #define O1_3  29
    #define O1_4  35
    #define O1_5  27
    
    #define O1_6  37    //Output 5 volts, can be use for Servo or Steper
    #define O1_7  25
    #define O1_8  39
    #define O1_9  23
    
    #define O1_10 41   //Output 5 volts



/**************************************************
 *    Connected map of greenhouse modul           *
 **************************************************/
 
    #define RX2   15     //Serial communication Serial3
    #define TX2   14     
    
    #define SCL2  21    //I²C BUS
    #define SDA2  20
    
    #define A2_0  A11    //Charge battery control
    
    #define A2_1  A12    //Analog input, you can use it like a digital input
    #define A2_2  A13
    #define A2_3  A14
    #define A2_4  A15
    
    #define I2_0  22      //Digital input
    #define I2_1  24
    #define I2_2  26
    #define I2_3  28
    #define I2_4  30
    
    #define O2_0  43    //Power output connected on a mofset
    #define O2_1  42
    #define O2_2  45    //Pwm output
    #define O2_3  46    //Pwm output
    #define O2_4  47
    #define O2_5  48
    
    #define O2_6  49    //Output 5 volts, can be use for Servo or Steper
    #define O2_7  50
    #define O2_8  51
    #define O2_9  52
    
    #define O2_10 53   //Output 5 volts