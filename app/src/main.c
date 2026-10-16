/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1

int main(void) {
  if (0 > BTN_init()) {
    return 0;
  }
  printk("BTN < 0");
  if (0 > LED_init()) {
    return 0;
  }
  printk("LED < 0");

  int i = 0;

  while (1) {
    if(i == 16)
      i=0;
    if(BTN_check_clear_pressed(BTN0)){
      i++;
      printk("Button 0 pressed");
    }
    LED_set(LED0, i & (1 << 0));
    LED_set(LED1, i & (1 << 1));
    LED_set(LED2, i & (1 << 2));
    LED_set(LED3, i & (1 << 3));
    

    k_msleep(SLEEP_MS);
  
  }
  return 0;
}
