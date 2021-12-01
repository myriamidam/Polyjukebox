#include <Adafruit_NeoPixel.h>
#define PIN 6 // broche 6
#define nbled 22 // nombre de led du ruban
Adafruit_NeoPixel led = Adafruit_NeoPixel(nbled, PIN, NEO_GRB + NEO_KHZ800);

unsigned long t0,t1=0,t2=0,t3=0,t4=0; // toutes les tempos 
byte a,b,p=0; // sert au calcul dans les anim
int d=1,e; // direction des anim
uint32_t c;

void setup() {
  led.begin();
 }

void loop() {
 t0=millis(); // mémorise le temps  
// Serial.print("t0="); Serial.println(t0);
e=analogRead(A0); // lecture du potard
 if (t0>t3) {
  p=random(9); 
  t3=t0+10000; t1=0; a=1;
 } // change le programme toutes les 10 secondes
 //Serial.print("t3="); Serial.println(t3);
if (e) p=2;   // si utilisation du potard

 switch (p) {
    //case 0: { prog0(1000);  break; } // potard
    //case 1: { prog1(100);  break; } // 50 = temps de changement de led   
    case 2: { prog2(28);  break; } // 20 = vitesse de déplacement
    //case 3: { prog3(500); break; } // 500 = vitesse de changement 
    //case 4: { prog4(100);  break; } // 50 = vitesse de déplacement    
    //case 5: { prog5(100);  break; } // 10 = vitesse de déplacement  
    //case 6: { prog6(10);  break; } // 10 = vitesse de déplacement    
    //case 7: { prog7(10);  break; } // 10 = vitesse de déplacement   
    //case 8: { prog8(1000);  break; } // 10 = vitesse de déplacement   
    //case 9: { prog9(100);  break; } // 1000 = explosion toutes les seconde  

 }
  led.show();

} 
void prog2(int t) {    
  uint32_t c=random(0x1000000); // choix d'une couleur aléatoire
  if (t0>t2) { 
    led.setPixelColor(a,c);     
    a=a+d; if(a>=nbled) d=-1; if(a<=0) d=1;
    t2=t0+t;}
  if (t0>t1) degrad(10); // 10= durée d'instinction des leds
}

void degrad(int t){ // t détermine la vitesse d'extinction des leds
  for(int i=0; i<nbled; i++) { 
    uint32_t c = led.getPixelColor(i); // extraction des couleurs
    byte r =   c / 0x10000;
    byte v = ( c & 0xFF00)/0x100;
    byte b =   c & 0xFF;
    led.setPixelColor(i,r/1.05,v/1.05, b/1.05); // baisse la luminosité des leds
    }
  t1=t0+t; // initialise t1
}
