# SevenSegment
SevenSegment is an arduino library which can be used to interface and work with seven segment displays

# Install

Clone (or download and unzip) the repository to `/libraries`
which can be found in your arduino installation. currently this library supports only 3 seven segments

# Usage

### Include

```c++
#include <SevenSegment.h>
```

### SevenSegment disp(type); 

Constructor to create an SevenSegment object which takes type parameter.
Type can be:
1 for common anode and 0 for common cathode



### begin(digit3,digit2,digit1,a,b,c,d,e,f,g,dot)

Initializes Seven Segments with with pin numbers for given parameters

```c++
	void setup(){
		 disp.begin(4,3,2,1,5,6,7,8,9,10,11,12); // begin(digit3,digit2,digit2,digit1,a,b,c,d,e,f,g,dot) pins 
		 
	}
```

### printNumber(int value,int decimal_place)

It prints given number to seven segment
```c++
  void loop(){
  	  disp.printNumber(355,2);
  }
```

### Full Working example of Counter



```c++
	//counter which increments in each second
	//Copyright (c) 2013 Sagar Devkota. All right reserved.
	//Email:sagarda7@yahoo.com
	#include <SevenSegment.h>
	SevenSegment disp(1); //1 for common anode and 0 for common cathode
	int count=0;
	int time;
	void setup(){
	 disp.begin(4,3,2,1,5,6,7,8,9,10,11,12); // begin(digit4,digit3,digit2,digit1,a,b,c,d,e,f,g,dot) pins 
	 time=millis();
	}
	 
	void loop(){
	 
	 disp.printNumber(count,2);
	 if((millis()-time)>1000){
	 count++;
	 time=millis();
	 }
	}
```



# Tutorial
Full Tutorial Can be found at [My Blog](http://www.sagardevkota.com.np/blog/use-seven-segment-display-easily-using-my-sevensegment-library/)
