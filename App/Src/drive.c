/**
 * @file drive.c
 * @author Kota-James
 * @brief 
 * @version 0.1
 * @date 2025-02-01
 * 
 * 
 */

#include "drive.h"



//+++++++++++++++++++++   Core function - Running System  +++++++++++++++++++++++++//




//++++++++++++++++++++++++   Core function - Config  ++++++++++++++++++++++++++++//

/**
 * @brief 走行系の変数の初期化，モータードライバ関係のGPIO設定とPWM出力に使うタイマの設定をする
 * 
 */
void drive_init(void){

  //====走行系の変数の初期化====

  //====マウスフラグの初期化===

  //====ステッピングモータの初期化====
  drive_disable_motor();       //ステッピングモータ励磁OFF
  drive_set_dir(FORWARD);     //前進するようにモータの回転方向を設定

  //====PWM出力に使うタイマの設定====
  __HAL_TIM_SET_AUTORELOAD(&htim16, DEFAULT_ARR);
  __HAL_TIM_SET_AUTORELOAD(&htim17, DEFAULT_ARR);
}


/**
 * @brief ステッピングモータを励磁する
 * 
 */
void drive_enable_motor(void){
  HAL_GPIO_WritePin(M3_GPIO_Port, M3_Pin, GPIO_PIN_RESET);  //ステッピングモーター励磁ON
  HAL_GPIO_WritePin(M3_2_GPIO_Port, M3_2_Pin, GPIO_PIN_RESET);
}

/**
 * @brief ステッピングモータの励磁を切る
 * 
 */
void drive_disable_motor(void){
  HAL_GPIO_WritePin(M3_GPIO_Port, M3_Pin, GPIO_PIN_SET);    //ステッピングモーター励磁OFF
  HAL_GPIO_WritePin(M3_2_GPIO_Port, M3_2_Pin, GPIO_PIN_SET);
}

/**
 * @brief PWM出力に使うタイマを有効にする
 * 
 * @note TIM16 : 16ビットタイマ。左モータの制御に使う。出力はTIM16_CH1
 * @note TIM17 : 16ビットタイマ。右モータの制御に使う。出力はTIM17_CH1
 */
void drive_start(void){
    __HAL_TIM_CLEAR_FLAG(&htim16, TIM_FLAG_UPDATE);
    __HAL_TIM_ENABLE_IT(&htim16, TIM_IT_UPDATE);
    HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);

    __HAL_TIM_CLEAR_FLAG(&htim17, TIM_FLAG_UPDATE);
    __HAL_TIM_ENABLE_IT(&htim17, TIM_IT_UPDATE);
    HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
}

/**
 * @brief PWM出力に使うタイマを停止させる
 * 
 */
void drive_stop(void){
    HAL_TIM_PWM_Stop(&htim16, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop(&htim17, TIM_CHANNEL_1);

    __HAL_TIM_SET_COUNTER(&htim16, 0);  // Reset Counter
    __HAL_TIM_SET_COUNTER(&htim17, 0);  // Reset Counter
}

/**
 * @brief 進行方向を設定する
 * 
 * @param d_dir 
 */
void drive_set_dir(uint8_t d_dir){
    //====左モータ====
    switch(d_dir & 0x0f){     //0~3ビット目を取り出す  d_dirと0b00001111を比較
        //----正回転----
        case 0x00:                      //0x00の場合   d_dirが0bxxxx0000のとき
            HAL_GPIO_WritePin(CW_CCW_L_GPIO_Port, CW_CCW_L_Pin, MT_FWD_L);  //左を前進方向に設定
            break;
        //----逆回転----
        case 0x01:                      //0x01の場合   d_dirが0bxxxx1111のとき
            HAL_GPIO_WritePin(CW_CCW_L_GPIO_Port, CW_CCW_L_Pin, MT_BACK_L); //左を後進方向に設定
            break;
    }
    //====右モータ====
    switch(d_dir & 0xf0){     //4~7ビット目を取り出す   d_dirと0b11110000を比較
        case 0x00:                      //0x00の場合   d_dirが0b0000xxxxの時
            HAL_GPIO_WritePin(CW_CCW_R_GPIO_Port, CW_CCW_R_Pin, MT_FWD_R);  //右を前進方向に設定
            HAL_GPIO_WritePin(CW_CCW_R_2_GPIO_Port, CW_CCW_R_2_Pin, MT_FWD_R);
            break;
        case 0x10:                      //0x10の場合   d_dirが0b1111xxxxの
            HAL_GPIO_WritePin(CW_CCW_R_GPIO_Port, CW_CCW_R_Pin, MT_BACK_R); //右を後進方向に設定
            HAL_GPIO_WritePin(CW_CCW_R_2_GPIO_Port, CW_CCW_R_2_Pin, MT_BACK_R);
            break;
    }
}

