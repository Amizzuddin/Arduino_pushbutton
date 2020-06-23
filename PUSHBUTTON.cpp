#include "PUSHBUTTON.h"
#include "Arduino.h"

PUSHBUTTON::PUSHBUTTON(byte pin){
   	pb = pin; 
}

void PUSHBUTTON::initialize(){
    pinMode(pb, INPUT);
}

bool PUSHBUTTON::read(){
    int reading = digitalRead(pb);
    if (reading != lastButtonState) {
    	lastDebounceTime = millis();
  	}
  	if ((millis() - lastDebounceTime) > debounceDelay) {
    	if (reading != buttonState) {
      		buttonState = reading;
    	}
  	}
  	lastButtonState = reading;
    return buttonState;
}

bool PUSHBUTTON::toggle(){
    bool read_input = read();
    if(read_input != last_read_input){
        if(read_input == HIGH){
        	toggle_value = !toggle_value;
        }
    }
    last_read_input = read_input;
    return toggle_value;
}

bool PUSHBUTTON::cosd(){
    bool read_input = read();
    if(read_input != last_read_input){
        last_read_input = read_input;
        return HIGH;
    }
    else{
        last_read_input = read_input;
        return LOW;
    }
}

int PUSHBUTTON::clicker(int max_count){
   	bool read_input = read();
   	if(read_input != last_read_input){
       	if(read_input == HIGH){
          	counter = (counter < max_count-1) ? counter + 1: 0;
       	}
   	}
   	last_read_input = read_input; 
  	return counter;
}