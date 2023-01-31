#pragma once

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


extern byte led_colors[3];
extern byte old_brightness;
extern byte fanSpeed;

extern void SendColors(byte red, byte grn, byte blu, byte prog, byte loops);
extern byte SetBrightness(byte brightness);
extern void SendDemo(byte prog);
extern void SendFanPWM(byte fan0);
extern void SendRearFanPWM(byte fan_speed);
#if 0
extern void SendOverwriteRange(byte from, byte to, byte red, byte grn, byte blu);
extern void SendStopOverwriteRange(byte from, byte to);
#endif
