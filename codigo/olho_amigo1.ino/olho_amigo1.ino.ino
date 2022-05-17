#include <Ultrasonic.h>

HC_SR04 sensor1(6,5); 

int duracao;
int distancia;


void setup()
{

  
  pinMode(11, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT); 
  Serial.begin(9600);

}

void loop()
{
  

distancia=   sensor1.distance();
  
Serial.print("Distancia :");
Serial.print(distancia);
Serial.print("cm");
Serial.print("  ");

  
  if(distancia>30){           
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9, LOW);
    Serial.println("Seguro");
  }
  else{
    digitalWrite(11,LOW);}
  
  if(distancia>=15 && distancia<30){ 
    digitalWrite(12,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9, HIGH);
    //Serial.println("Intervalo medio");
    delay(1000);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  }
  else{
       digitalWrite(12,LOW);}
     
  if(distancia<15){                 
    digitalWrite(13,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9, HIGH);
    //Serial.println("Nao seguro");
    delay(50);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  }
  else{
    digitalWrite(13,LOW); }
 }
