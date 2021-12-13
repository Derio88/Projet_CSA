#include <Wire.h>
#include "LCD4884.h"
//#define NB_TYPE 3

LCD4884 monLCD;


const byte adresseCAN = B1101000;      // B1101000X  b3-2-1 = A2 A1 A0  b0=R/nW bit

const byte configRegistreCH1 = B00011000; //  Voir Feuille de spÃ©cifications MCP3428 ou fin de ce Fichier
const double vRef = 2.048; // Valeur de la reference de tension interne en Volts



//Déclaration des fonctions (voir fin du code)
void affichageMesure();
double lire3428(int addresseCAN, int noCANAL);

// Variable global
float moyenne = 0;
float masse = 0;
float joystick = 0;
float decalage = 0;

int indexType = 0;
int indexFilaments = 0;
float longueurFilament [] = {2.98,2.50};
float bobine[] = {200,150,0};

void setup()
{

  Wire.begin();

  Serial.begin(115200);

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
  char typeBobine[][20] = {"Plastique  ","Carton     ","Sans Bobine"};
  char typeFilaments[][5] = {"PLA","ABS"};
  float longueurFilament [] = {2.98,2.50};
  int NB_TYPE = sizeof(typeBobine)/sizeof(typeBobine[0])-1;
  int NB_FILAMENT = sizeof(typeFilaments)/sizeof(typeFilaments[0])-1;
 joystick = analogRead(A0)* (5.0 / 1023.0);
 
  Serial.println(joystick  );
  Serial.println(decalage);
 monLCD.writeString(0,0,"Bobine:",MENU_NORMAL);
 monLCD.writeString(10,1,typeBobine[indexType],MENU_NORMAL);
 monLCD.writeString(0,2,"Filament:",MENU_NORMAL);
 monLCD.writeString(60,2,typeFilaments[indexFilaments],MENU_NORMAL);
 Serial.println(indexType);
  Serial.println(NB_TYPE);
 if(joystick > 3.62 && joystick < 3.64) // en haut
 {
  indexFilaments++;
    if (indexFilaments > NB_FILAMENT)
    {
      indexFilaments = 0;
    }
 }
 else if (joystick > 2.46 && joystick < 2.48) //droite
 {
    indexType++;
    if (indexType > NB_TYPE)
    {
      indexType = 0;
    }
    
    
 }
 else if (joystick > 1.60 && joystick < 1.62) // bas
 {
   indexFilaments--;
    if (indexFilaments < 0)
    {
      indexFilaments = NB_FILAMENT;
    }
 }
 else if(joystick > 0.69 && joystick < 0.71)   // appuie sur le bouton
 {
  decalage = lire3428(adresseCAN, 0) *1000* 1.00095 + 53.397;
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
      indexType = NB_TYPE;
    }
 }
  
 for(int i=0;i<15;i++)
 {
  masse = (lire3428(adresseCAN, 0) * 1000 * 1.00095 + 53.397 - decalage - bobine[indexType]);
  moyenne = masse*0.4+0.60*moyenne;
 }
 monLCD.writeString(0, 3, "      ", MENU_NORMAL);
 monLCD.writeString(0, 4, "      ", MENU_NORMAL);
  affichageMesure();
}

void affichageMesure() 
{
      float longueur = 0.0;
      String moy = String(int(moyenne));
      String longString;
      if(masse > 0){
        longueur = int(moyenne) / longueurFilament[indexFilaments];
      } else
      {
        longueur = 0;
      }
      longString = String(longueur);
     
      char *tensionChar = moy.c_str(); 
      char *longueurChar = longString.c_str(); 
     
      monLCD.writeString(0, 3, tensionChar, MENU_NORMAL);
      monLCD.writeString(40, 3, "g", MENU_NORMAL); 
      monLCD.writeString(0, 4, longueurChar, MENU_NORMAL);
      monLCD.writeString(40, 4, "m", MENU_NORMAL); 
      
}






//retourne la valeur analogique mise à l'échelle en volts
//effectue la mise à l'échell en fonction de la configuration du canal

double lire3428(int addresseCAN, int noCANAL) {

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

  
    printINFO(octetGauche, octetDroit, noCANAL, channelBITS, (channelGAIN) );
  

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

}
