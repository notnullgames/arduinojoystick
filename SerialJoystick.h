#ifndef SerialJoystick_h
#define SerialJoystick_h

#include "Arduino.h"

// this represents the joystick
class SerialJoystick {
  public:
    SerialJoystick();
    bool A = false;
    bool B = false;
    bool X = false;
    bool Y = false;
    bool START = false;
    bool SELECT = false;
    bool LB = false; // also called "C"
    bool RB = false; // also called "Z"
    bool LT = false;
    bool RT = false;
    int AXIS0 = 0; // -32767 to 32767
    int AXIS1 = 0; // -32767 to 32767

    // turn D-pad button-type inputs into axes
    void dpad(bool up, bool down, bool left, bool right);

    // translates the current states into Stinger format and send to serial
    void send();
};

SerialJoystick::SerialJoystick() {}

void SerialJoystick::send() {
  uint8_t *state;
  state[0] = 0;
  state[1] = 0;
  state[2] = 0;
  state[3] = 0;

  // handle buttons
  if (A) bitSet(state[0], 5);
  if (B) bitSet(state[0], 4);
  if (START) bitSet(state[3], 1);
  if (SELECT) bitSet(state[3], 0);
  if (X) bitSet(state[0], 2);
  if (Y) bitSet(state[3], 5);
  if (LT) bitSet(state[3], 3);
  if (RT) bitSet(state[3], 2);
  if (LB) bitSet(state[0], 3);
  if (RB) bitSet(state[3], 4);

  // handle axes
  if (AXIS0 <= 0) {
    bitClear(state[0], 1);
  } else {
    bitSet(state[0], 1);
  }
  if (AXIS1 <= 0) {
    bitClear(state[0], 0);
  } else {
    bitSet(state[0], 0);
  }
  state[2] = map(AXIS0, -32767, 32767, B00111111, B00000000);
  state[1] = map(AXIS1, -32767, 32767, B00111111, B00000000);

  Serial.write(state, 4);
}

void SerialJoystick::dpad(bool up, bool down, bool left, bool right) {
  if (up) {
    AXIS0 = -32767;
  } else if (down) {
    AXIS0 = 32767;
  } else {
    AXIS0 = 0;
  }
  if (left) {
    AXIS1 = -32767;
  } else if (right) {
    AXIS1 = 32767;
  } else {
    AXIS1 = 0;
  }
}

#endif
