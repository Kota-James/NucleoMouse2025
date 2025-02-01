/**
 * @file drive.h
 * @author Kota-James
 * @brief 
 * @version 0.1
 * @date 2025-02-01
 * 
 * 
 */

#ifndef __DRIVE_H
#define __DRIVE_H

#include "common.h"

//direction
#define FORWARD   0x00
#define BACK      0x11
#define ROTATE_L  0x01
#define ROTATE_R  0x10

#define MT_FWD_L GPIO_PIN_SET    // CW/CCWで前に進む出力（左）
#define MT_BACK_L GPIO_PIN_RESET // CW/CCWで後ろに進む出力（左）
#define MT_FWD_R GPIO_PIN_RESET  // CW/CCWで前に進む出力（右）
#define MT_BACK_R GPIO_PIN_SET   // CW/CCWで後ろに進む出力（右）

//基幹関数
void drive_enable_motor(void);
void drive_disable_motor(void);
void drive_start(void);
void drive_stop(void);
void drive_set_dir(uint8_t dir);


#endif //__DRIVE_H