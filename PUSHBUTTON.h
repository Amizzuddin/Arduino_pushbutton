#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "Arduino.h"

class pushbutton{
  public:
	/********************************************************
	 * Constructor which require to input the connection	*
	 * of pushbutton on arduino input						*
	 ********************************************************/
  	pushbutton(byte pin);

	/********************************************************
	 * This function performs pinMode of the pushbutton		*
	 ********************************************************/
  	void initialize();
	
  	/********************************************************
	 * Read pushbutton with debounce capability. 			*
	 * Return value:							 			*
	 * Pull_up connection:  TRUE=NOT PRESSED, FALSE=PRESSED	*
	 * Pull_down connection:TRUE=PRESSED, FALSE=NOT PRESSED	* 
	 ********************************************************/
  	bool read();
	
  	/********************************************************
	 * Read pushbutton with debounce capability				*
	 * Return value:										*
	 * Toggles betweeen TRUE or FALSE based on the last		* 
	 * result value for every pushbutton pressed			*
	 ********************************************************/
  	bool toggle();
	
	/********************************************************
	 * Read pushbutton with debounce capability				*
	 * Return value:										*
	 * TRUE = There is a change of state					*
	 * LOW = No change of state								*
	 * NOTE: function captures falling and rising states	*
	 ********************************************************/
  	//may reuire to improve to provide options between PGT | NGT
  	bool cosd();
	
  	//return the number of times pushbutton is pressed
  	int clicker(int max_count);
	

  private:
  	byte pb;
    bool buttonState;             		 // the current reading from the input pin
	bool lastButtonState = LOW;   		 // the previous reading from the input pin
  	bool last_read_input = LOW;
  	bool toggle_value;
  	int counter = 0;
  	unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
	unsigned long debounceDelay = 30;    // the debounce time; increase if the output flickers
};

#endif