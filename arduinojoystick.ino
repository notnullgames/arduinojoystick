#include "SerialJoystick.h"

// I use these below to represent pins that have buttons on them
// I skip D13, because that has LED on it, on an UNO
#define BUTTON_A 2
#define BUTTON_B 3
#define BUTTON_X 4
#define BUTTON_Y 5

#define BUTTON_START 6
#define BUTTON_SELECT 7

#define BUTTON_LB 8
#define BUTTON_RB 9

#define BUTTON_LT 10
#define BUTTON_RT 11

#define BUTTON_DUP 12
#define BUTTON_DDOWN 14
#define BUTTON_DLEFT 15
#define BUTTON_DRIGHT 16

// thse aren't used by me, but you could put them here
#define ANALOG_AXIS0 A3 // also D17
#define ANALOG_AXIS1 A4 // also D18

SerialJoystick joystick;

void setup() {
  Serial.begin(9600);
  
  // setup my hardware
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_X, INPUT_PULLUP);
  pinMode(BUTTON_Y, INPUT_PULLUP);
  pinMode(BUTTON_START, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_LB, INPUT_PULLUP);
  pinMode(BUTTON_RB, INPUT_PULLUP);
  pinMode(BUTTON_LT, INPUT_PULLUP);
  pinMode(BUTTON_RT, INPUT_PULLUP);
  pinMode(BUTTON_DUP, INPUT_PULLUP);
  pinMode(BUTTON_DDOWN, INPUT_PULLUP);
  pinMode(BUTTON_DLEFT, INPUT_PULLUP);
  pinMode(BUTTON_DRIGHT, INPUT_PULLUP);
}

void loop() {
  // read all the inputs, inverted with ! because I am using INPUT_PULLUP
  joystick.A = !digitalRead(BUTTON_A);
  joystick.B = !digitalRead(BUTTON_B);
  joystick.X = !digitalRead(BUTTON_X);
  joystick.Y = !digitalRead(BUTTON_Y);
  joystick.START = !digitalRead(BUTTON_START);
  joystick.SELECT = !digitalRead(BUTTON_SELECT);
  joystick.LB = !digitalRead(BUTTON_LB);
  joystick.RB = !digitalRead(BUTTON_RB);
  joystick.LT = !digitalRead(BUTTON_LT);
  joystick.RT = !digitalRead(BUTTON_RT);
  
  // this is how you would do analog
  // joystick.AXIS0 = map(analogRead(ANALOG_AXIS0), 0, 1023, -32767, 32767);
  // joystick.AXIS1 = map(analogRead(ANALOG_AXIS1), 0, 1023, -32767, 32767);

  // but I am doing DPAD buttons
  joystick.dpad(
    !digitalRead(BUTTON_DUP),
    !digitalRead(BUTTON_DDOWN),
    !digitalRead(BUTTON_DLEFT),
    !digitalRead(BUTTON_DRIGHT)
  );
  
  joystick.send();
}
