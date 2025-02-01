/**
 * @file display.c
 * @author Kota-James
 * @brief 
 * @version 0.1
 * @date 2025-02-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "common.h"
#include "display.h"

/**
 * @brief 
 * 
 * @param led1 
 * @param led2 
 * @param led3 
 */
void led_write(uint8_t led1, uint8_t led2, uint8_t led3) {
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, led1);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, led2);
    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, led3);
}

/**
 * @brief 
 * 
 * @param led4 
 */
void led_write_2(uint8_t led4) {
    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, led4);
}

/**
 * @brief 
 * 
 * @param mode 
 * @return int 
 */
int select_mode(int mode){
    printf("Mode : %d\n", mode);

    while(1){
        led_write(mode & 0b001, mode & 0b010, mode & 0b100);

        if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin) == GPIO_PIN_RESET){     //スイッチのGPIOピンにはpull-up抵抗がついているので、押されているときはLOW
            HAL_Delay(150);     //チャタリング防止
            // while(HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == GPIO_PIN_RESET){     //スイッチが離されるのを待つ　なんか機能しないからオフにしとく
            //     ;
            // }
            mode++;
            mode %= 8;
            printf("Mode : %d\n", mode);
        }
        if(HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin) == GPIO_PIN_RESET){
            HAL_Delay(150);
            mode--;
            mode %= 8;
            printf("Mode : %d\n", mode);
        }
        if(HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == GPIO_PIN_RESET){
            HAL_Delay(150);
            return mode;
            printf("Mode : %d\n", mode);
        }
    }
}

/**
 * @brief 
 * 
 * @param c 
 * @return int 
 */
int __io_putchar(int c) {
    if (c == '\n') {
        int _c = '\r';
        HAL_UART_Transmit(&huart2, &_c, 1, 1);
    }
    HAL_UART_Transmit(&huart2, &c, 1, 1);
    return 0;
}