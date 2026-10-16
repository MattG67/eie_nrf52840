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


  while (1) {
    if(BTN_check_clear_pressed(BTN0)){
      LED_toggle(LED0);
      printk("Button 0 pressed");
    }
    k_msleep(SLEEP_MS);
  
  }
  return 0;
}
