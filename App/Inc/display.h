/**
 * @file display.h
 * @author Kota-James
 * @brief 
 * @version 0.1
 * @date 2025-02-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __DISPLAY_H
#define __DISPLAY_H

#define min(A,B) ((A)>(B))?(B):(A)
#define max(A,B) ((A)>(B))?(A):(B)


void led_write(uint8_t, uint8_t, uint8_t);
void led_write_2(uint8_t);
int select_mode(int);
int __io_putchar(int);


#endif /* __DISPLAY_H */