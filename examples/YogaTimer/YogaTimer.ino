#include <SevenSegment.h>
SevenSegment disp(1);
int button=0;
int out[5]={A0,A1,A2,A3,A4};
unsigned long time;
int sec=0;
byte minutes;
void setup(){
  disp.begin(4,3,2,1,5,6,7,8,9,10,11,12);
  pinMode(button,INPUT);
  for(byte i=0; i<4; i++){
    pinMode(out[i],OUTPUT);
    digitalWrite(out[i],LOW);
  }
  
  
}


void loop(){
  
  while(digitalRead(button)==HIGH){
   disp.printNumber(8888,0); 
  }
  time=millis();
  while(1){
    if((millis()-time)>1000)
    {
      sec++;
      time=millis();
    }
    disp.printTimer(sec);
    minutes=disp.getMinutes();
    if(minutes<3){
      digitalWrite(out[0],HIGH);
      digitalWrite(out[1],LOW);
      digitalWrite(out[2],LOW);
      digitalWrite(out[3],LOW);
      digitalWrite(out[4],LOW);
      
    }
    else if(minutes>=3 && minutes<6){
      digitalWrite(out[0],LOW);
      digitalWrite(out[1],HIGH);
      digitalWrite(out[2],LOW);
      digitalWrite(out[3],LOW);
      digitalWrite(out[4],LOW);
      
    }
    else if(minutes>=6 && minutes<9){
      digitalWrite(out[0],LOW);
      digitalWrite(out[1],LOW);
      digitalWrite(out[2],HIGH);
      digitalWrite(out[3],LOW);
      digitalWrite(out[4],LOW);
      
    }
    else if(minutes>=9 && minutes<12){
      digitalWrite(out[0],LOW);
      digitalWrite(out[1],LOW);
      digitalWrite(out[2],LOW);
      digitalWrite(out[3],HIGH);
      digitalWrite(out[4],LOW);
      
    }
    else if(minutes>=12 && minutes<=15){
     digitalWrite(out[0],LOW);
      digitalWrite(out[1],LOW);
      digitalWrite(out[2],LOW);
      digitalWrite(out[3],LOW);
      digitalWrite(out[4],HIGH);
      
    }
      
    //disp.printNum(8765,2);
    if(minutes==15) break;
    
  }
  
  time=0;
  sec=0;
}

