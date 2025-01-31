#include "common.h"
#include "auxiliary.h"

void led_write(uint8_t led1, uint8_t led2, uint8_t led3) {
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, led1);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, led2);
    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, led3);
}

void led_write_2(uint8_t led4) {
    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, led4);
}