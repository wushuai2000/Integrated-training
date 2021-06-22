#ifndef __LED_KEY_H__
#define __LED_KEY_H__
#include "iocc2530.h"
enum LED_NUM{LED0,LED1};
enum LED_STATE{LED_ON,LED_OFF};
enum KEY_STATUS{KEY_DOWN,KEY_UP};
extern void led_init(void);
extern void led_ctrl(int led_num,int led_state);
void beep_init(void);
#endif
