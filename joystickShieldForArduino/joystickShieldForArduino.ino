/**
   JoystickShield - Arduino Library for JoystickShield (http://hardwarefun.com/projects/joystick-shield)

   Copyright 2011  Sudar Muthu  (email : sudar@sudarmuthu.com)

 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <sudar@sudarmuthu.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer or coffee in return - Sudar
 * ----------------------------------------------------------------------------
 * 2014 edit by Markus Mücke, muecke.ma(a)gmail.com
 * Changes for JoysikShield V1.2
 * added a function to read the amplitude of the joystick
 * added a auto calibrate function for 3.3V and 5V mode
 *
 * Added functions:
 *  Functions for F and E Button
 *  Calibrate Joystick
 *  xAmplitude
 *  yAmplitude
 */

/**
 * Before running this example, stack the JoystickShield on top of Arduino board
 *
 */
#include <JoystickShield.h> // include JoystickShield Library

JoystickShield joystickShield; // create an instance of JoystickShield object

void setup() {
    Serial.begin(9600);
    
    delay(100);
    // new calibration function
    joystickShield.calibrateJoystick();
    
    // predefined Joystick to Pins 0 and 1.
    // Change it if you are using a different shield
    // setJoystickPins(0, 1);
	
    // predefined buttons to the following pins.
    // change it if you are using a different shield.
    // setButtonPins(pinJoystickButton, pinUp, pinRight, pinDown, pinLeft, pinF, pinE);
    // to deactivate a button use a pin outside of the range of the arduino e.g. 255, but not above
    // setButtonPins(8, 2, 3, 4, 5, 7, 6);
    
    // Joystick Callbacks
    joystickShield.onJSUp(&up);
    joystickShield.onJSRightUp(&rightUp);
    joystickShield.onJSRight(&right);
    joystickShield.onJSRightDown(&rightDown);
    joystickShield.onJSDown(&down);
    joystickShield.onJSLeftDown(&leftDown);
    joystickShield.onJSLeft(&left);
    joystickShield.onJSLeftUp(&leftUp);
//    joystickShield.onJSnotCenter(&notCenter);
    joystickShield.onJSCenter(&center);

    // Button Callbacks
    joystickShield.onJoystickButton(&joystickButton);
    joystickShield.onUpButton(&upButton);
    joystickShield.onRightButton(&rightButton);
    joystickShield.onDownButton(&downButton);
    joystickShield.onLeftButton(&leftButton);
    joystickShield.onFButton(&FButton);
    joystickShield.onEButton(&EButton);
}


void loop() {
    joystickShield.processCallbacks(); // you don't have do anything else
}

/** Define Callback Function **/
void up() {
    Serial.print("UP");
}

void rightUp() {
    Serial.print("RU");
}

void right() {
    Serial.print("RI");
}

void rightDown() {
    Serial.print("RD");
}

void down() {
    Serial.print("DO");
}

void leftDown() {
    Serial.print("LD");
}

void left() {
    Serial.print("LE");
}

void leftUp() {
    Serial.print("LU");
}

void joystickButton() {
    Serial.print("JB");
}

void upButton() {
    Serial.print("AB");
}

void rightButton() {
    Serial.print("BB");
}

void downButton() {
    Serial.print("CB");
}

void leftButton() {
    Serial.print("DB");
}

void FButton() {
    Serial.print("FB");
}

void EButton() {
    Serial.print("EB");
}

void notCenter() {
//   Serial.println("Not Center");
   // new position functions
   Serial.print("x ");	Serial.print(joystickShield.xAmplitude());Serial.print(" y ");Serial.print(joystickShield.yAmplitude());
}

void center() {
  Serial.print("CE");
}
