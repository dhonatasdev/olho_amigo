// C++ code
//
int duration;
int distance;


void setup()
{
  pinMode(13, OUTPUT); 
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  
  pinMode(10, OUTPUT);
  
  pinMode(2, OUTPUT);  
  pinMode(3, INPUT);   
  
  pinMode(9, OUTPUT); 
  Serial.begin(9600);

}

void loop()
{
digitalWrite(2,HIGH);
delayMicroseconds(10);
digitalWrite(2,LOW);
  
duration= pulseIn(3,HIGH);
distance= duration * 0.034/2;
  
Serial.print("Distance :");
Serial.print(distance);
Serial.print("cm");
Serial.print("  ");

  
  if(distance>300){           
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9, LOW);
    Serial.println("Safe");
  }
  else{
    digitalWrite(11,LOW);}
  
  if(distance>=150 && distance<300){ 
    digitalWrite(12,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9, HIGH);
    Serial.println("Mid Range");
    delay(2000);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  }
  else{
       digitalWrite(12,LOW);}
     
  if(distance<150){                 
    digitalWrite(13,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9, HIGH);
    Serial.println("Unsafe");
    delay(50);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  }
  else{
    digitalWrite(13,LOW); }
 }