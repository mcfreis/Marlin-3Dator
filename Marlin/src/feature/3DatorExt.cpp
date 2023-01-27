#include "../inc/MarlinConfig.h"

/**

//command:
// 1 -> LEDs
// 2 -> FANs
// 3 -> overwrite
// 4 -> stuff

//programm LEDs:
// 1 -> fade LEDs
// 2 -> instant leds
// 3 -> move down
// 4 -> move up
// 5 -> move/wipe leds
// 6 -> jitter LEDs
// 7 -> rainbow (looping)
// 8 -> snake (looping)
// 9 -> pulse (looping)
//10 -> turn off all looping
//11 -> set brightness

//programm FANs:
// 1 -> Fan1 normal mode
// 2 -> Fan2 normal mode
// 3 -> Fan1 PWM mode
// 4 -> Fan2 PWM mode

//programm overwrite (pixels)
// 1 -> single pixel
// 2 -> single pixel stop overwrite
// 3 -> range
// 4 -> range stop overwrite

//programm stuff
// 1 -> Test mode
// 2 -> demo mode

*/

#if ENABLED(DATOR_EXTENSION_BOARD)

#include <Wire.h>

#define CMD_LED 1
	#define PRG_FADE 1
	#define PRG_INSTANT 2
	#define PRG_MOVE_DOWN 3
	#define PRG_MOVE_UP 4
	#define PRG_WIPE 5
	#define PRG_JITTER 6
	#define PRG_RAINBOW 7
	#define PRG_SNAKE 8
	#define PRG_PULSE 9
	#define PRG_LOOPS_OFF 10
	#define PRG_BRIGHTNESS 11
	
#define CMD_FAN 2
	#define FAN1 1
	#define FAN2 2
	//#define FAN1_PWM 3
	//#define FAN2_PWM 4
	
#define CMD_OVERWRITE 3
	#define PIXEl_SINGLE 1
	#define PIXEL_SINGLE_STOP 2
	#define PIXEL_RANGE 3
	#define PIXEL_RANGE_STOP 4
	
#define CMD_STUFF 4
	#define TEST_MODE 1
	#define DEMO_MODE 2


byte led_colors[3] = {255,255,255};
byte old_brightness = 255;
byte fanSpeed = 0;

void SendColorsInstant(byte red, byte grn, byte blu) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_LED);
  Wire.write(2);
  Wire.write(red);
  Wire.write(grn);
  Wire.write(blu);
  Wire.write(0);
  Wire.endTransmission();
}

void SendColors(byte red, byte grn, byte blu, byte prog, byte loops) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_LED);
  Wire.write(prog);
  Wire.write(red);
  Wire.write(grn);
  Wire.write(blu);
  Wire.write(loops);
  Wire.endTransmission();

  if (prog <= 6) {
    led_colors[0] = red;
    led_colors[1] = grn;
    led_colors[2] = blu;
  }
  SendColorsInstant(led_colors[0], led_colors[1], led_colors[2]);
}

byte SetBrightness(byte brightness) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_LED);
  Wire.write(PRG_BRIGHTNESS);
  Wire.write(0);
  Wire.write(0);
  Wire.write(brightness);
  Wire.write(0);
  Wire.endTransmission();
  
  byte return_old_brightness = old_brightness;
  old_brightness = brightness;
  return return_old_brightness;
}

void SendDemo(byte prog) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_STUFF);
  Wire.write(prog);
  Wire.endTransmission();
}

void SendFanPWM(byte fan_speed) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_FAN);
  Wire.write(FAN1);
  Wire.write(fan_speed);
  Wire.endTransmission();
  
  fanSpeed = fan_speed;
}

void SendRearFanPWM(byte fan_speed) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_FAN);
  Wire.write(FAN2);
  Wire.write(fan_speed);
  Wire.endTransmission();
}

#if 0
void SendOverwriteRange(byte from, byte to, byte red, byte grn, byte blu) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_OVERWRITE);
  Wire.write(PIXEL_RANGE);
  Wire.write(from);
  Wire.write(to);
  Wire.write(red);
  Wire.write(grn);
  Wire.write(blu);
  Wire.endTransmission();
  
  SendColorsInstant(led_colors[0], led_colors[1], led_colors[2]);
}

void SendStopOverwriteRange(byte from, byte to) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_OVERWRITE);
  Wire.write(PIXEL_RANGE_STOP);
  Wire.write(from);
  Wire.write(to);
  Wire.endTransmission();
}
#endif

#endif // DATOR_EXTENSION_BOARD

