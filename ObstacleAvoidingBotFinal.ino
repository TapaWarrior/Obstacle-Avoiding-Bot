#include <Servo.h>
Servo s1;
void setup(){
  pinMode(2,OUTPUT);//servo
  s1.attach(2);
  pinMode(4,OUTPUT);//trig
  pinMode(5,INPUT);//echo
  Serial.begin(9600);
  s1.write(90);
  pinMode(6,OUTPUT);//IN1
  pinMode(7,OUTPUT);//IN2
  pinMode(8,OUTPUT);//IN3
  pinMode(9,OUTPUT);//IN4
  pinMode(3,OUTPUT);//EN1
  pinMode(10,OUTPUT);//EN2
}
void Right(){ 
 analogWrite(3,200);
 analogWrite(10,200);
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
}
void Left(){
 analogWrite(3,200);
 analogWrite(10,200);
 digitalWrite(6,HIGH);
 digitalWrite(7,LOW);
 digitalWrite(8,HIGH);
 digitalWrite(9,LOW);
}
void Fwd(){
 analogWrite(3,255);
 analogWrite(10,255);
 digitalWrite(6,HIGH);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
}
void Bwd(){
 analogWrite(3,255);
 analogWrite(10,255);
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 digitalWrite(8,HIGH);
 digitalWrite(9,LOW);
}
void Stop() {
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 digitalWrite(9,LOW);
}
float distance(){
  digitalWrite(4,LOW);
  delay(10);
  digitalWrite(4,HIGH);
  delay(10);
  digitalWrite(4,LOW);
  long long int t=pulseIn(5,HIGH);
  if(t==0){
   return 100;
  }
  return (t*0.0343)/2;
}
void loop() {
  Fwd();
  int ind=0;
  float d=100.0;
  for(int i=1;i<180;i+=10)
  {
    s1.write(i);
    delay(10);
    d=distance();
    if(d<20){
      ind=i;
      break;
    }
  }
  if(ind==0){
    for(int i=170;i>1;i-=10){
      s1.write(i);
      delay(10);
      d=distance();
      if(d<20) {
        ind=i;
        break;
      }
    }
  }

  if(ind!=0){
  Stop();
  delay(100);
  Bwd();
  delay(500);
  s1.write(90);
  if(ind>90)
  {
    while(d<20){
      Right();
      d=distance();
    }
  }
  else{
    while(d<20){
      Left();
      d=distance();
    }
  }
}
}
