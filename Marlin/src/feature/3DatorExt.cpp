#include "../inc/MarlinConfig.h"

#if ENABLED(DATOR_EXTENSION_BOARD)

#include <Wire.h>
#include "3DatorExt.h"

#if ENABLED(DATOR_EXTENSION_PART_FAN)
byte fanSpeed = 0;
#endif

#if ENABLED(DATOR_EXTENSION_LEDS)
byte led_colors[3] = {255,255,255};
byte old_brightness = 255;

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
#endif

#if ENABLED(DATOR_EXTENSION_PART_FAN)

void SendFanPWM(byte fan_speed) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_FAN);
  Wire.write(FAN1);
  Wire.write(fan_speed);
  Wire.endTransmission();
  
  fanSpeed = fan_speed;
}

#endif

#if ENABLED(DATOR_EXTENSION_HOTEND_FAN)

void SendRearFanPWM(byte fan_speed) {
  //send information over i2c
  Wire.beginTransmission(4);
  Wire.write(CMD_FAN);
  Wire.write(FAN2);
  Wire.write(fan_speed);
  Wire.endTransmission();
}

#endif

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

