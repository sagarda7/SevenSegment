//counter which increments in each second
//Copyright (c) 2013 Sagar Devkota.  All right reserved.
//Email:sagarda7@yahoo.com
#include <SevenSegment.h>
SevenSegment disp(1); //1 for common anode and 0 for common cathode
int count=0;
int time;
void setup(){
  disp.begin(4,3,2,1,5,6,7,8,9,10,11,12); // begin(digit4,digit3,digit1,a,b,c,d,e,f,g,dot) pins
  time=millis();
}


void loop(){
  
  disp.printNumber(count,2);
  if((millis()-time)>1000){
  	count++;
  	time=millis();
  }
}

