EESchema Schematic File Version 4
LIBS:Vmc_card-cache
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
L Connector_Generic:Conn_01x03 J2
U 1 1 5E2A0450
P 5950 3800
F 0 "J2" H 6029 3842 50  0000 L CNN
F 1 "Servo_flap" H 6029 3751 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5950 3800 50  0001 C CNN
F 3 "~" H 5950 3800 50  0001 C CNN
	1    5950 3800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x06 J1
U 1 1 5E2A04F7
P 4500 4050
F 0 "J1" H 4420 4367 50  0000 C CNN
F 1 "Input" H 4420 4276 50  0000 C CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x06_P3.50mm_Horizontal" H 4500 4050 50  0001 C CNN
F 3 "~" H 4500 4050 50  0001 C CNN
	1    4500 4050
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5E2A0582
P 5950 4500
F 0 "J3" H 6030 4492 50  0000 L CNN
F 1 "Fan" H 6030 4401 50  0000 L CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x02_P3.50mm_Horizontal" H 5950 4500 50  0001 C CNN
F 3 "~" H 5950 4500 50  0001 C CNN
	1    5950 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4600 5750 4600
$Comp
L power:GND #PWR0101
U 1 1 5E2A0C39
P 5700 4150
F 0 "#PWR0101" H 5700 3900 50  0001 C CNN
F 1 "GND" H 5705 3977 50  0000 C CNN
F 2 "" H 5700 4150 50  0001 C CNN
F 3 "" H 5700 4150 50  0001 C CNN
	1    5700 4150
	1    0    0    -1  
$EndComp
$Comp
L power:+24V #PWR0102
U 1 1 5E2A0C68
P 5350 4600
F 0 "#PWR0102" H 5350 4450 50  0001 C CNN
F 1 "+24V" H 5365 4773 50  0000 C CNN
F 2 "" H 5350 4600 50  0001 C CNN
F 3 "" H 5350 4600 50  0001 C CNN
	1    5350 4600
	1    0    0    1   
$EndComp
Wire Wire Line
	4700 4250 5400 4250
Wire Wire Line
	5400 4250 5400 4500
Wire Wire Line
	5400 4500 5750 4500
Wire Wire Line
	4700 4350 5350 4350
Wire Wire Line
	5350 4350 5350 4600
Connection ~ 5350 4600
Wire Wire Line
	4700 4050 4800 4050
Wire Wire Line
	5700 4050 5700 4150
Wire Wire Line
	5750 3900 5700 3900
Wire Wire Line
	5700 3900 5700 4050
Connection ~ 5700 4050
Wire Wire Line
	4700 4150 4800 4150
Wire Wire Line
	4800 4150 4800 4050
Connection ~ 4800 4050
Wire Wire Line
	4800 4050 5700 4050
Wire Wire Line
	4700 3950 5200 3950
Wire Wire Line
	5200 3950 5200 3800
Wire Wire Line
	5200 3800 5750 3800
Wire Wire Line
	4700 3850 4800 3850
Wire Wire Line
	4800 3850 4800 3700
Wire Wire Line
	4800 3700 5750 3700
$EndSCHEMATC
