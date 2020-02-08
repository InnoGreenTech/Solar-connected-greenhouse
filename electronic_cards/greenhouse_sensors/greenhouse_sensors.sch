EESchema Schematic File Version 4
LIBS:greenhouse_sensors-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CO2_capteur:CO2_Meter-sensors J2
U 1 1 5E009C51
P 8500 3050
F 0 "J2" H 8500 3225 50  0000 C CNN
F 1 "CO2_Meter-sensors" H 8500 3134 50  0000 C CNN
F 2 "ES8266:MHZ19B" H 8350 3100 50  0001 C CNN
F 3 "" H 8350 3100 50  0001 C CNN
	1    8500 3050
	1    0    0    -1  
$EndComp
$Comp
L CO2_capteur:DHT22_Temperature_Humidity-sensors TH1
U 1 1 5E009CC8
P 5450 3800
F 0 "TH1" H 5728 4272 60  0000 L CNN
F 1 "DHT22_Temperature_Humidity-sensors" H 5728 4166 60  0000 L CNN
F 2 "ES8266:DHT22_Temperature_Humidity" H 5500 3800 60  0001 C CNN
F 3 "" H 5500 3800 60  0000 C CNN
	1    5450 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_PHOTO R2
U 1 1 5E009DDC
P 3300 3500
F 0 "R2" H 3370 3546 50  0000 L CNN
F 1 "R_PHOTO" H 3370 3455 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Vertical" V 3350 3250 50  0001 L CNN
F 3 "~" H 3300 3450 50  0001 C CNN
	1    3300 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x06 J1
U 1 1 5E00A116
P 4700 5000
F 0 "J1" H 4780 4992 50  0000 L CNN
F 1 "Screw_Terminal_01x06" H 4780 4901 50  0000 L CNN
F 2 "TerminalBlock_MetzConnect:TerminalBlock_MetzConnect_Type059_RT06306HBWC_1x06_P3.50mm_Horizontal" H 4700 5000 50  0001 C CNN
F 3 "~" H 4700 5000 50  0001 C CNN
	1    4700 5000
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5E00A2C4
P 3300 3050
F 0 "#PWR0101" H 3300 2900 50  0001 C CNN
F 1 "+5V" H 3315 3223 50  0000 C CNN
F 2 "" H 3300 3050 50  0001 C CNN
F 3 "" H 3300 3050 50  0001 C CNN
	1    3300 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5E00A2EE
P 9100 3500
F 0 "#PWR0102" H 9100 3350 50  0001 C CNN
F 1 "+5V" H 9115 3673 50  0000 C CNN
F 2 "" H 9100 3500 50  0001 C CNN
F 3 "" H 9100 3500 50  0001 C CNN
	1    9100 3500
	1    0    0    1   
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5E00A318
P 5000 3900
F 0 "#PWR0103" H 5000 3750 50  0001 C CNN
F 1 "+5V" H 5015 4073 50  0000 C CNN
F 2 "" H 5000 3900 50  0001 C CNN
F 3 "" H 5000 3900 50  0001 C CNN
	1    5000 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5E00A349
P 5800 3900
F 0 "#PWR0104" H 5800 3650 50  0001 C CNN
F 1 "GND" H 5805 3727 50  0000 C CNN
F 2 "" H 5800 3900 50  0001 C CNN
F 3 "" H 5800 3900 50  0001 C CNN
	1    5800 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5E00A37A
P 9300 3500
F 0 "#PWR0105" H 9300 3250 50  0001 C CNN
F 1 "GND" H 9305 3327 50  0000 C CNN
F 2 "" H 9300 3500 50  0001 C CNN
F 3 "" H 9300 3500 50  0001 C CNN
	1    9300 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E00AAA8
P 2900 4050
F 0 "R1" H 2970 4096 50  0000 L CNN
F 1 "NU" H 2970 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2830 4050 50  0001 C CNN
F 3 "~" H 2900 4050 50  0001 C CNN
	1    2900 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5E00ABF4
P 2900 4500
F 0 "#PWR0106" H 2900 4250 50  0001 C CNN
F 1 "GND" H 2905 4327 50  0000 C CNN
F 2 "" H 2900 4500 50  0001 C CNN
F 3 "" H 2900 4500 50  0001 C CNN
	1    2900 4500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5E00AD5D
P 4500 3900
F 0 "#PWR0107" H 4500 3750 50  0001 C CNN
F 1 "+5V" H 4515 4073 50  0000 C CNN
F 2 "" H 4500 3900 50  0001 C CNN
F 3 "" H 4500 3900 50  0001 C CNN
	1    4500 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5E00AD63
P 4700 3900
F 0 "#PWR0108" H 4700 3650 50  0001 C CNN
F 1 "GND" H 4705 3727 50  0000 C CNN
F 2 "" H 4700 3900 50  0001 C CNN
F 3 "" H 4700 3900 50  0001 C CNN
	1    4700 3900
	1    0    0    1   
$EndComp
Wire Wire Line
	8900 3400 9100 3400
Wire Wire Line
	9100 3400 9100 3500
Wire Wire Line
	8900 3300 9300 3300
Wire Wire Line
	9300 3300 9300 3500
Wire Wire Line
	8100 3200 7700 3200
Wire Wire Line
	8100 3300 7800 3300
Wire Wire Line
	5350 3800 5350 3900
Wire Wire Line
	5350 3900 5000 3900
Wire Wire Line
	5550 3800 5550 3850
Wire Wire Line
	5550 3850 5800 3850
Wire Wire Line
	5800 3850 5800 3900
Wire Wire Line
	5450 4300 5450 3800
Wire Wire Line
	3300 3050 3300 3350
Wire Wire Line
	3300 3650 3300 3800
Wire Wire Line
	3300 3800 2900 3800
Wire Wire Line
	2900 3800 2900 3900
Wire Wire Line
	2900 4200 2900 4500
Wire Wire Line
	3300 3800 4400 3800
Wire Wire Line
	4400 3800 4400 4800
Connection ~ 3300 3800
Wire Wire Line
	7700 3200 7700 4400
Wire Wire Line
	7700 4400 4800 4400
Wire Wire Line
	4800 4400 4800 4800
Wire Wire Line
	7800 3300 7800 4500
Wire Wire Line
	7800 4500 4900 4500
Wire Wire Line
	4900 4500 4900 4800
Wire Wire Line
	4700 3900 4700 4800
Wire Wire Line
	4500 4300 4500 4800
Wire Wire Line
	4500 4300 5450 4300
Wire Wire Line
	4500 3900 4500 4050
Wire Wire Line
	4500 4050 4600 4050
Wire Wire Line
	4600 4050 4600 4800
$EndSCHEMATC