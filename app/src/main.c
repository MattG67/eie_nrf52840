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

  LED_set(LED0, LED_ON);

  int password[] = {0,1,2};
  int pass_len = sizeof(password)/sizeof(password[0]);
  int entered[pass_len];
  int i = 0;
  while (1) {
    if(BTN_check_clear_pressed(BTN0)){
      entered[i] = 0;
        i++;
    }
    if(BTN_check_clear_pressed(BTN1)){
      entered[i] = 1;
        i++;
    }
    if(BTN_check_clear_pressed(BTN2)){
      entered[i] = 2;
        i++;
    }

    if(BTN_check_clear_pressed(BTN3)){
      for(int j = 0; j<i; j++){
        if(entered[j] != password[j]){
          i=0;
          break;
        }

      }
      LED_set(LED0, LED_OFF);

    }

    if(i > pass_len)
      i = 0;


    k_msleep(SLEEP_MS);
  
  }
  return 0;
}
