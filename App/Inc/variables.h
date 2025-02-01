/**
 * @file variables.h
 * @author Kota-James
 * @brief 
 * @version 0.1
 * @date 2025-02-01
 * 
 * 
 */

#ifndef __VARIABLES_H
#define __VARIABLES_H

#include "common.h"


//variables
extern uint16_t v, v_l, v_r;
extern uint16_t v_in, v_out;
extern uint16_t v_l_pre, v_r_pre;
extern uint16_t a, a_l, a_r;
extern uint16_t a_in, a_out;

extern uint16_t pulse_l, pulse_r;
extern uint16_t pulse_in, pulse_out;
extern uint16_t dist_l, dist_r;
extern uint16_t dist_in, dist_out;

extern float sum_time_l, sum_time_r;
extern float sum_time_in, sum_time_out;

extern float arr_l_float, arr_r_float;
extern uint16_t arr_l, arr_r;



#endif //__VARIABLES_H