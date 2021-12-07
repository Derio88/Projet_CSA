#include <Wire.h>
#include "LCD4884.h"


unsigned long dernierTemps = 0;
LCD4884 monLCD;


const byte adresseCAN = B1101000;      // B1101000X  b3-2-1 = A2 A1 A0  b0=R/nW bit

const byte configRegistreCH1 = B00011000; //  Voir Feuille de spÃ©cifications MCP3428 ou fin de ce Fichier
const double vRef = 2.048; // Valeur de la reference de tension interne en Volts

const int printInfosSerie = 1; // 1 pour imprimer info acquisition sur port série  ou 0 pour ne pas afficher
const int printInfosLCD = 1 ; // 1 pour afficher les canaux sur LCD

//Déclaration des fonctions (voir fin du code)
void mesure4Canaux(int lcd, int info);
double lire3428(int addresseCAN, int noCANAL, int printInfo);

// Variable global
float moyenne = 0;
float masse = 0;
float joystick = 0;
float decalage = 0;
float bobine = 0;

void setup()
{

  Wire.begin();

  if (printInfosSerie == 1) { Serial.begin(115200);}

  //Démarrage de l'affichage
  monLCD.init();
  monLCD.clear();

  //Configuration initiale des canaux du MCP3428
  Wire.beginTransmission(adresseCAN);
  Wire.write(configRegistreCH1);
  Wire.endTransmission();
}

void loop()
{
  char typeBobine[][20] = {"Plastique","Carton   "};
  int indexType = 0;
  String indexT;
  char* indexS = '0';
 joystick = analogRead(A0)* (5.0 / 1023.0);
 
  Serial.println(joystick  );
  Serial.println(decalage);
 if(joystick > 3.62 && joystick < 3.64) // en haut
 {
  
 }
 else if (joystick > 2.46 && joystick < 2.48) //droite
 {
    indexType = indexType + 1;
    if (indexType > 1)
    {
      indexType = 0;
    }
    indexT = String(indexType);
    indexS = indexT.c_str();
    monLCD.writeString(0,2,typeBobine[indexType],MENU_NORMAL);
    monLCD.writeString(0,3,indexS,MENU_NORMAL);
    
    
 }
 else if (joystick > 1.60 && joystick < 1.62) // bas
 {
  
 }
 else if(joystick > 0.69 && joystick < 0.71)   // appuie sur le bouton
 {
  decalage = lire3428(adresseCAN, 0, printInfosSerie) *1000* 0.9974 + 49.13;
  while(joystick > 0.69 && joystick < 0.71)
  {
    joystick = analogRead(A0)* (5.0 / 1023.0);
  }
 }
 else if (joystick == 0)// gauche
 {
    indexType--;
    if (indexType < 0)
    {
      indexType = 0;
    }
    monLCD.writeString(0,2,typeBobine[indexType],MENU_NORMAL);
 }
  
 for(int i=0;i<15;i++)
 {
  masse = (lire3428(adresseCAN, 0, printInfosSerie) * 1000 * 0.9974 + 49.13 - decalage - bobine);
  moyenne = masse*0.4+0.60*moyenne;
 }
 monLCD.writeString(20, 1, "      ", MENU_NORMAL);
  mesure4Canaux(printInfosLCD, printInfosSerie);
}




/*
  MCP3426/7/8
  16-Bit, Multi-Channel Î”Î£Analog-to-Digital Conver
  I2Câ„¢ Interface and On-Board Reference


  bit 7 RDY: Ready Bit
    This bit is the data ready flag. In read mode, this bit indicates if the outputregister has been updated
    with a latest conversion result. In One-Shot Conversion mode, writing this bit to ï¿½1ï¿½ initiates a new
    conversion.
    Reading RDYbit with the read command:
    1= Output register has not been updated.
    0= Output register has been updated with the latest conversion result.
    Writing RDYbit with the write command:
    Continuous Conversion mode: No effect
    One-Shot Conversion mode:
    1= Initiate a new conversion.
    0= No effect.

  bit 6-5 C1-C0: Channel Selection Bits
    00 = Select Channel 1 (Default)
    01 = Select Channel 2
    10 = Select Channel 3 (MCP3428 only, treated as 00 by the MCP3426/MCP3427)
    11 = Select Channel 4 (MCP3428 only, treated as 01 by the MCP3426/MCP3427)

  bit 4 O/C: Conversion Mode Bit
    1= Continuous Conversion Mode (Default). The device performs data conversions continuously.
    0= One-Shot Conversion Mode. The device performs a single conversion and enters a low power
    standby mode until it receives another write or read command.

  bit 3-2 S1-S0: Sample Rate Selection Bit
    00 = 240 SPS (12 bits) (Default)
    01 = 60 SPS (14 bits)
    10 = 15 SPS (16 bits)

  bit 1-0 G1-G0: PGA Gain Selection Bits
    00 =x1 (Default)
    01 =x2
    10 =x4
    11 =x8

*/

void mesure4Canaux(int lcd, int info) {

  if (lcd)
  {
    monLCD.writeString(6, 0, "ENTREES 3428", MENU_NORMAL);
  }
   
    if (lcd) {
      
       String moy = String(moyenne);
       String mas = String(masse);
      
      char *tensionChar = moy.c_str(); 
      monLCD.writeString(20, 1, tensionChar, MENU_NORMAL);
      monLCD.writeString(60, 1, "g", MENU_NORMAL);
    }
}






//retourne la valeur analogique mise à l'échelle en volts
//effectue la mise à l'échell en fonction de la configuration du canal

double lire3428(int addresseCAN, int noCANAL, int printInfo) {

  byte configCH_CAN = 0;

  switch (noCANAL) {   // Configure le registre selon le canal dÃ©sirÃ©
    case 0:
      configCH_CAN = configRegistreCH1;
      break;

    default:
      configCH_CAN = 0;
  }

  Wire.beginTransmission(addresseCAN);
  Wire.write(configCH_CAN);

  Wire.endTransmission();

  delay(1 + pow(2, 2 + 2 * ((configCH_CAN >> 2) & B00000011))); //dÃ©lais entre la configuration du registre et l'obtention d'une nouvelle valeur analogique
  //convertie selon les paramÃ¨tes de registre configurÃ©s  (nb bits-> Fs )  ci-haut.
  Wire.requestFrom(addresseCAN, 3);

  //récupère les deux BYTE de data

  byte octetGauche = Wire.read(); //Octet MSB
  byte octetDroit = Wire.read(); //Octet LSB
  byte configCAN = Wire.read();  //Retour des paramÃ¨tres actuels de configuration

  //extraction des paramètres de la mesure effectuée dont on a recu les 2 bytes

  int channelNUM = configCAN >> 5 & B00000011; // no du canal analogique converti
  int channelBITS = 12 + 2 * ((configCAN >> 2) & B00000011); // nombre de bits de conversion (implicite)
  int channelGAIN = 1 << (configCAN & B00000011); //

  if (printInfo) {
    printINFO(octetGauche, octetDroit, noCANAL, channelBITS, (channelGAIN) );
  }

  //appelle la fonction de conversion  BYTE + BYTE -> int16
  return convertDbyte_Double(octetGauche, octetDroit, channelBITS, (channelGAIN));
}



//Convertion de beux bytes en un int16 avec ajustement en fonction de l'échelle de canal

double convertDbyte_Double(byte gauche, byte droit, int noBITS, int gain) {

  long demiePlage = (1 << (noBITS)) / 2;
  if (noBITS == 16) {
    demiePlage = 32768;
  }
  // var t = valeur entiere de la conversion AN.
  long t = gauche << 8 | droit;
  if (t > demiePlage) t = ((1 << (noBITS)) * 10 + 1) - t;
  double v = (double)t * vRef / (double)demiePlage / (double)gain;
  return v;

}

void printINFO(byte gauche, byte droit, int canal, int noBits, int gain) {

  float voltage = convertDbyte_Double(gauche, droit, noBits, gain) * 1000;
  float masse = voltage * 0.9909 + 50.701;
  long demiePlage = (1 << (noBits)) / 2;
  if (noBits == 16) {
    demiePlage = 32768;
  }

  /*Serial.print("CH");
  Serial.print(canal + 1);
  Serial.print(" ");
  for (int cpt = 7; cpt >= 0; cpt-- ) {
    Serial.print(bitRead(gauche, cpt));
  }
  Serial.print("-");

  for (int cpt = 7; cpt >= 0; cpt-- ) {
    Serial.print(bitRead(droit, cpt));
  }

  Serial.println("");
  Serial.print("nombre de bits=");
  Serial.println(noBits);
  Serial.print("demie plage=");
  Serial.println((double)demiePlage);*/

 /* Serial.print("mV =");
  Serial.print(voltage);
  Serial.print(", ");
  //Serial.print("temps =");
 // Serial.print(millis(),DEC);
  Serial.print("Masse =");
  Serial.print(masse);
  Serial.println();*/

}
