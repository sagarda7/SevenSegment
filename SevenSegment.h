#ifndef SevenSeg_h
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
#define SevenSegment_h

#include "Arduino.h"
#define NUM_DIGITS 4 //defines number of digits

class SevenSegment
{
	private:
	uint8_t _mode; //mode 1 for common anode, other for common cathode
	int _current_number;
	byte m,s;  //used for minutes and seconds for printTimer
	uint8_t outDigit;  
	uint8_t digitsPin[NUM_DIGITS],segmentsPin[8];
	
	public:
		SevenSegment(uint8_t mode); //constructor
		void printNumber(int num, byte dec); //function to print number with given decimal place
		void begin(uint8_t d4,uint8_t d3,uint8_t d2,uint8_t d1,uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t dot);
		void printTimer(long sec);
		byte getMinutes();
		byte getSeconds();
		int  getNumber();
		//void init();
		
	
		
};

#endif