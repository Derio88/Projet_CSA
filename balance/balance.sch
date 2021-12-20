EESchema Schematic File Version 4
EELAYER 30 0
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
L Device:R_US R?
U 1 1 61BFC51A
P 1250 3000
F 0 "R?" H 1182 2954 50  0000 R CNN
F 1 "R_US" H 1182 3045 50  0000 R CNN
F 2 "" V 1290 2990 50  0001 C CNN
F 3 "~" H 1250 3000 50  0001 C CNN
	1    1250 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R?
U 1 1 61BFD888
P 1750 3000
F 0 "R?" H 1682 2954 50  0000 R CNN
F 1 "R_US" H 1682 3045 50  0000 R CNN
F 2 "" V 1790 2990 50  0001 C CNN
F 3 "~" H 1750 3000 50  0001 C CNN
	1    1750 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R?
U 1 1 61BFDCE4
P 1250 3500
F 0 "R?" H 1182 3454 50  0000 R CNN
F 1 "R_US" H 1182 3545 50  0000 R CNN
F 2 "" V 1290 3490 50  0001 C CNN
F 3 "~" H 1250 3500 50  0001 C CNN
	1    1250 3500
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R?
U 1 1 61BFE756
P 1750 3500
F 0 "R?" H 1682 3454 50  0000 R CNN
F 1 "R_US" H 1682 3545 50  0000 R CNN
F 2 "" V 1790 3490 50  0001 C CNN
F 3 "~" H 1750 3500 50  0001 C CNN
	1    1750 3500
	-1   0    0    1   
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 61BFFCA0
P 1500 3650
F 0 "#PWR?" H 1500 3400 50  0001 C CNN
F 1 "GNDREF" H 1505 3477 50  0000 C CNN
F 2 "" H 1500 3650 50  0001 C CNN
F 3 "" H 1500 3650 50  0001 C CNN
	1    1500 3650
	1    0    0    -1  
$EndComp
Connection ~ 1500 3650
Wire Wire Line
	1500 3650 1750 3650
Wire Wire Line
	1250 3650 1500 3650
$Comp
L New_Library:INA118 U1
U 1 1 61C0948A
P 2800 3200
F 0 "U1" H 3150 3550 50  0000 C CNN
F 1 "INA118" H 3200 3450 50  0000 C CNN
F 2 "" H 2800 3200 50  0001 C CNN
F 3 "" H 2800 3200 50  0001 C CNN
	1    2800 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 3150 1750 3250
Wire Wire Line
	1250 3150 1250 3250
$Comp
L Device:R_US R?
U 1 1 61C0E420
P 2250 3200
F 0 "R?" H 2182 3154 50  0000 R CNN
F 1 "R_US" H 2182 3245 50  0000 R CNN
F 2 "" V 2290 3190 50  0001 C CNN
F 3 "~" H 2250 3200 50  0001 C CNN
	1    2250 3200
	-1   0    0    1   
$EndComp
Wire Wire Line
	2650 3150 2500 3150
Wire Wire Line
	2500 3150 2500 3050
Wire Wire Line
	2500 3050 2250 3050
Wire Wire Line
	2650 3250 2500 3250
Wire Wire Line
	2500 3250 2500 3350
Wire Wire Line
	2500 3350 2250 3350
Wire Wire Line
	2650 3350 2650 3950
Wire Wire Line
	2650 3950 1050 3950
Wire Wire Line
	1050 3250 1250 3250
Wire Wire Line
	1750 3250 2100 3250
Wire Wire Line
	2100 3250 2100 2900
Wire Wire Line
	2100 2900 2650 2900
Wire Wire Line
	2650 2900 2650 3050
Connection ~ 1750 3250
Wire Wire Line
	1750 3250 1750 3350
Connection ~ 1250 3250
Wire Wire Line
	1250 3250 1250 3350
Wire Wire Line
	1050 3250 1050 3950
$Comp
L power:-5V #PWR?
U 1 1 61C10ED8
P 3050 3550
F 0 "#PWR?" H 3050 3650 50  0001 C CNN
F 1 "-5V" H 3065 3723 50  0000 C CNN
F 2 "" H 3050 3550 50  0001 C CNN
F 3 "" H 3050 3550 50  0001 C CNN
	1    3050 3550
	-1   0    0    1   
$EndComp
NoConn ~ 4150 3150
NoConn ~ 4150 3250
NoConn ~ 4150 3350
NoConn ~ 4150 3450
NoConn ~ 4150 3550
NoConn ~ 4150 3650
Wire Wire Line
	3500 3150 3700 3150
Wire Wire Line
	3700 3150 3700 2950
Wire Wire Line
	3700 2950 4150 2950
Wire Wire Line
	3500 3300 3800 3300
Wire Wire Line
	3900 3300 3900 3050
Wire Wire Line
	3900 3050 4150 3050
$Comp
L power:GNDREF #PWR?
U 1 1 61C148EB
P 3800 3300
F 0 "#PWR?" H 3800 3050 50  0001 C CNN
F 1 "GNDREF" H 3805 3127 50  0000 C CNN
F 2 "" H 3800 3300 50  0001 C CNN
F 3 "" H 3800 3300 50  0001 C CNN
	1    3800 3300
	1    0    0    -1  
$EndComp
Connection ~ 3800 3300
Wire Wire Line
	3800 3300 3900 3300
NoConn ~ 4950 3350
NoConn ~ 4950 3450
$Comp
L New_Library:Arduino_Mega2560 XA?
U 1 1 61C18C60
P 7850 3700
F 0 "XA?" H 7850 1319 60  0000 C CNN
F 1 "Arduino_Mega2560" H 7850 1213 60  0000 C CNN
F 2 "" H 8550 6450 60  0001 C CNN
F 3 "https://store.arduino.cc/arduino-mega-2560-rev3" H 8550 6450 60  0001 C CNN
	1    7850 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 61C20D24
P 4550 3850
F 0 "#PWR?" H 4550 3600 50  0001 C CNN
F 1 "GNDREF" H 4555 3677 50  0000 C CNN
F 2 "" H 4550 3850 50  0001 C CNN
F 3 "" H 4550 3850 50  0001 C CNN
	1    4550 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 61C23D94
P 6100 5100
F 0 "#PWR?" H 6100 4850 50  0001 C CNN
F 1 "GNDREF" H 6105 4927 50  0000 C CNN
F 2 "" H 6100 5100 50  0001 C CNN
F 3 "" H 6100 5100 50  0001 C CNN
	1    6100 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 4950 6100 4950
Wire Wire Line
	6100 4950 6100 5100
$Comp
L New_Library:MCP3428 U?
U 1 1 61C2961E
P 4550 3250
F 0 "U?" H 4650 3800 50  0000 C CNN
F 1 "MCP3428" H 4750 3700 50  0000 C CNN
F 2 "" H 4550 3250 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22226a.pdf" H 4550 3250 50  0001 C CNN
	1    4550 3250
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:MC78L05_SO8 U?
U 1 1 61C574D0
P 2300 1750
F 0 "U?" H 2300 1992 50  0000 C CNN
F 1 "MC78L05_SO8" H 2300 1901 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 2400 1950 50  0001 C CIN
F 3 "https://www.onsemi.com/pub/Collateral/MC78L00A-D.PDF" H 2500 1750 50  0001 C CNN
	1    2300 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 61C5A583
P 1600 1600
F 0 "#PWR?" H 1600 1450 50  0001 C CNN
F 1 "+5V" H 1615 1773 50  0000 C CNN
F 2 "" H 1600 1600 50  0001 C CNN
F 3 "" H 1600 1600 50  0001 C CNN
	1    1600 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 1600 1600 1750
Wire Wire Line
	1600 1750 2000 1750
$Comp
L power:GNDREF #PWR?
U 1 1 61C5B887
P 2300 2050
F 0 "#PWR?" H 2300 1800 50  0001 C CNN
F 1 "GNDREF" H 2305 1877 50  0000 C CNN
F 2 "" H 2300 2050 50  0001 C CNN
F 3 "" H 2300 2050 50  0001 C CNN
	1    2300 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 2850 1500 2850
Wire Wire Line
	2600 1750 3000 1750
Wire Wire Line
	3000 1750 3000 2500
Wire Wire Line
	3000 2500 1500 2500
Wire Wire Line
	1500 2500 1500 2850
Connection ~ 1500 2850
Wire Wire Line
	1500 2850 1750 2850
Wire Wire Line
	3050 2900 3050 2500
Wire Wire Line
	3050 2500 3000 2500
Connection ~ 3000 2500
Wire Wire Line
	4550 2750 4550 2500
Wire Wire Line
	4550 2500 3050 2500
Connection ~ 3050 2500
Wire Wire Line
	4950 3050 6200 3050
Wire Wire Line
	6200 3050 6200 2350
Wire Wire Line
	6200 2350 6550 2350
Wire Wire Line
	6300 3150 6300 2450
Wire Wire Line
	6300 2450 6550 2450
$Comp
L Device:R_US R?
U 1 1 61C60638
P 5900 3300
F 0 "R?" H 5832 3254 50  0000 R CNN
F 1 "R_US" H 5832 3345 50  0000 R CNN
F 2 "" V 5940 3290 50  0001 C CNN
F 3 "~" H 5900 3300 50  0001 C CNN
	1    5900 3300
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 61C6184C
P 5500 3700
F 0 "C?" H 5615 3746 50  0000 L CNN
F 1 "C" H 5615 3655 50  0000 L CNN
F 2 "" H 5538 3550 50  0001 C CNN
F 3 "~" H 5500 3700 50  0001 C CNN
	1    5500 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 61C62050
P 5900 3700
F 0 "C?" H 6015 3746 50  0000 L CNN
F 1 "C" H 6015 3655 50  0000 L CNN
F 2 "" H 5938 3550 50  0001 C CNN
F 3 "~" H 5900 3700 50  0001 C CNN
	1    5900 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3450 5500 3550
Wire Wire Line
	5900 3450 5900 3550
Wire Wire Line
	5500 3850 5700 3850
$Comp
L power:GNDREF #PWR?
U 1 1 61C662FF
P 5700 3850
F 0 "#PWR?" H 5700 3600 50  0001 C CNN
F 1 "GNDREF" H 5705 3677 50  0000 C CNN
F 2 "" H 5700 3850 50  0001 C CNN
F 3 "" H 5700 3850 50  0001 C CNN
	1    5700 3850
	1    0    0    -1  
$EndComp
Connection ~ 5700 3850
Wire Wire Line
	5700 3850 5900 3850
Wire Wire Line
	4550 2500 5500 2500
Wire Wire Line
	5500 2500 5500 3450
Connection ~ 4550 2500
Connection ~ 5500 3450
Connection ~ 5900 3450
Connection ~ 5900 3150
Wire Wire Line
	5900 3150 6300 3150
Wire Wire Line
	4950 3150 5900 3150
Wire Wire Line
	5500 3450 5900 3450
$EndSCHEMATC
