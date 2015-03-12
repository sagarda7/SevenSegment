# SevenSegment
SevenSegment is an arduino library which can be used to interface and work with seven segment displays

# Install

Clone (or download and unzip) the repository to `/libraries`
which can be found in your arduino installation. currently this library supports only 4 seven segments

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
		 disp.begin(4,3,2,1,5,6,7,8,9,10,11,12); // begin(digit4,digit3,digit2,digit1,a,b,c,d,e,f,g,dot) pins 
		 
	}
```

### printNumber(int value,int decimal_place)

It prints given number to seven segment
```c++
  void loop(){
  	  disp.printNumber(355,2);
  }
```

### getNumber()

It returns current number being printed to Seven Segment
```c++

  void loop(){
  	int dynamic_value=355;
  	 disp.printNumber(dynamic_value,2);
  	  if(disp.getNumber()==355) {
  	  	//do something
  	  }
  }
```

### printTimer(long sec)

It prints given seconds to minute:seconds eg. printTimer(310) gives 5.10 in sevensegment 
```c++
  void loop(){
  	  disp.printTimer(310);
  }
```



### getMinutes() and getSeconds()

It returns current minute and seconds value if printTimer is used
```c++
  void loop(){
  	  disp.printTimer(310);
  	  if(disp.getMinutes()==5 && disp.getSeconds()==30) {
  	  	//do something
  	  }
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
