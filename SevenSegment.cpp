/*
  SevenSegment.h - Seven Segment Display library
  Copyright (c) 2013 Sagar Devkota.  All right reserved.
  Email:sagarda7@yahoo.com
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "Arduino.h"
#include "SevenSegment.h"
uint8_t nums[10][7]={	{1,1,1,1,1,1,0},
						{0,1,1,0,0,0,0},
						{1,1,0,1,1,0,1},
						{1,1,1,1,0,0,1},
						{0,1,1,0,0,1,1},
						{1,0,1,1,0,1,1},
						{1,0,1,1,1,1,1},
						{1,1,1,0,0,0,0},
						{1,1,1,1,1,1,1},
						{1,1,1,1,0,1,1}
};


SevenSegment::SevenSegment(uint8_t mode){
	_mode=mode;
	//assign output mode
	if(_mode==1) //for common anode
	{
		outDigit=HIGH;
	}
	else{
		outDigit=LOW;
	}
	
}



void SevenSegment::begin(uint8_t d1,uint8_t d2,uint8_t d3,uint8_t d4,uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t dot){
//assign digits pin to an array
	digitsPin[0]=d1;
	digitsPin[1]=d2;
	digitsPin[2]=d3;
	digitsPin[3]=d4;
	
	// assiign segment pins as an array
	segmentsPin[0]=a;
	segmentsPin[1]=b;
	segmentsPin[2]=c;
	segmentsPin[3]=d;
	segmentsPin[4]=e;
	segmentsPin[5]=f;
	segmentsPin[6]=g;
	segmentsPin[7]=dot;
	
	uint8_t i;
	for(i=0; i<NUM_DIGITS; i++){
		pinMode(digitsPin[i],OUTPUT);

		digitalWrite(digitsPin[i],LOW);//to be changed according to mode later
	}
	
	for(i=0; i<8; i++){
		pinMode(segmentsPin[i],OUTPUT);
		digitalWrite(segmentsPin[i],LOW); //to be changed according to mode later
	}

	
}

void SevenSegment::printNumber(int num,byte dec){
	_current_number=num;

	uint8_t i=0;
	uint8_t digit;
	while(num>0){
		digit=num % 10;
		
		digitalWrite(digitsPin[i],HIGH);
		for(uint8_t j=0; j<7; j++){
				if(_mode==1)
					digitalWrite(segmentsPin[j],1-nums[digit][j]);//inverse output
				else
					digitalWrite(segmentsPin[j],nums[digit][j]);

				if(i==dec)
				{
					if(_mode==1)
						digitalWrite(segmentsPin[7],LOW);
					else
						digitalWrite(segmentsPin[7],HIGH);
				}
				else
				{
					if(_mode==1)
						digitalWrite(segmentsPin[7],HIGH);
					else
						digitalWrite(segmentsPin[7],LOW);
				}

			
		}
		
		delay(5);
		digitalWrite(digitsPin[i],LOW);

		i++;
		if(i>NUM_DIGITS) break;

		num/=10;
		
		
		
	}
	
	
	
}

void SevenSegment::printTimer(long sec){
	
	
	m=sec/60;
	s=sec%60;
	byte lsdmin,msdmin,lsdsec,msdsec;

	lsdmin=m%10;
	msdmin=m/10;

	lsdsec=s%10;
	msdsec=s/10;

	int timevalue=msdmin*1000+lsdmin*100+msdsec*10+lsdsec*1;
	printNumber(timevalue,2);
}

byte SevenSegment::getMinutes(){
	return m;
}

byte SevenSegment::getSeconds(){
	return s;
}

int SevenSegment::getNumber(){
	return _current_number;
}

