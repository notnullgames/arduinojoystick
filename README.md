# arduinojoystick

Use an arduino (or bare chip) to generate serial signals that look like a stingray joystick.


This is heavlily based on ideas from [Linux-Arduino-Serial-Joystick](https://github.com/mcgurk/Linux-Arduino-Serial-Joystick). Ideas and start for a circuit from [RPI-I2C-Joystick](https://github.com/piloChambert/RPI-I2C-Joystick). If you want to emualte a serial joystick using arduino's GPIO, over raspberry pi's (or any other) serial, this is for you. My goal is to use RX/TX on pi directly, and appear like a regular old-timey Gravis Stinger (serial) joystick on linux-side.


## host

```
# install "driver"
sudo apt install inputattach

# run it
sudo inputattach --baud 9600 --always --stinger /dev/ttyS0

# test it
jstest /dev/js0


# run it as a daemon
inputattach --baud 9600 --always --stinger --daemon /dev/ttyS0
```

## arduino

I tried to keep it fairly readable so you can modify it to work how you like. Open it in arduino IDE and click "Upload". The pins used for differnt buttons is defined in the sketch, and should be farily straightforward to use. I use `INPUT_PULLUP` because I like to connect the other side of switches to ground, but you could invert it, if you like.
