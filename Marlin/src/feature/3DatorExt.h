#pragma once

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
