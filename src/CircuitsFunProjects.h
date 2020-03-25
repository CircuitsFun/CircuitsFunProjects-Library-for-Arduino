//YWROBOT
#ifndef CircuitsFunProjects_h
#define CircuitsFunProjects_h

#include <inttypes.h>
#include "Print.h" 
#include <Wire.h>

#define HIGH 0x1

// commands

class Button {
	public:
		Button(int pin=8,bool pressedValue=HIGH);
		void begin();
		bool pressed(int timeout=0);
		bool released(int timeout=0);
		bool doublePressed(int timeout=0,int tolerance=500);

		bool isPressed();
		virtual bool getState();

	protected:
		int pin;
		bool pressedValue;
		bool lastState;
		long debounceTime;
		bool checkPress(int timeout, bool requiredState);
};


#endif
