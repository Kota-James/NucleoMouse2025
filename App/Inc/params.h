/**
 * @file params.h
 * @author Kota-James
 * @brief 
 * @version 0.1
 * @date 2025-02-01
 * 
 * 
 */

#ifndef __PARAMS_H
#define __PARAMS_H

// Mouse info
#define PI 3.1415926535
#define CLOCK 1000000   //モータ制御用のマイコンのクロック
#define TIRE_DIAMETER 52    //タイヤ直径
#define TIRE_PERIMETER (PI * TIRE_DIAMETER)    //タイヤ外周
#define DIS_BET_AXLE 78.5    //車軸間距離
#define PULSE_1_ROT 400   //1回転パルス数

// Pulse info
#define PULSE_SEC_HALF 219 // 半区画走行用パルス。2倍すると1区画分に
#define PULSE_ROT_R90 153     // 右90度回転用パルス数
#define PULSE_ROT_L90 153     // 左90度回転用パルス数
#define PULSE_ROT_180 305     // 180度回転用パルス数
#define PULSE_SETPOS_BACK 200 // 後ろ壁に当てるために下がるパルス数
#define PULSE_SETPOS_SIDE 100 //横壁から中央までのパルス数
#define PULSE_SETPOS_SET 94  // 後ろ壁から中央までのパルス数

// Velocity info
#define DEFAULT_V 140   //デフォルトの速度
#define DRIVEA_V  270   //デフォルトの半区画加速後の速度
#define DEFAULT_A 300   //デフォルトの加速度
#define DEFAULT_OFFSET 16   //オフセット距離[mm]
#define MAX_V 1000
#define MAX_ARR (TIRE_PERIMETER / (MAX_V * PULSE_1_ROT)) * CLOCK

// Sensor info
//----壁判断閾値（しきい値）----
#define WALL_BASE_FR 70 // 前壁右センサ
#define WALL_BASE_FL 200 // 前壁左センサ
#define WALL_BASE_R 100  // 右壁センサ
#define WALL_BASE_L 100  // 左壁センサ

#define WALL_OFFSET_FL 600  //オフセット時の目標センサ値
#define WALL_OFFSET_FR 360  //オフセット時の目標センサ値

#define BATT_LOW_VOL 3204 * 0.88 // バッテリ電圧低下判定のしきい値
                                // 33kΩと10kΩの分圧抵抗を通してバッテリ電圧を取得している→ 11.1*(10/(10+33)/3.3)*4096=3204

//----制御閾値（しきい値）----
#define CTRL_BASE_L 0 // 左制御閾値
#define CTRL_BASE_R 0 // 右制御閾値
#define CTRL_MAX 200    // 制御量上限値
#define CTRL_P 0.70  // 比例制御係数
#define CTRL_D 0    //微分制御係数
#define RAPID_CHANGE  10 //10 //急激な変化量
#define WALL_BASE_INC_AMT 60    //急激な変化時の壁の閾値の増加量

//----赤外線（赤色）LED発光待機時間（単位はマイクロ秒）
#define IR_WAIT_US 15

#define GOAL_X 7
#define GOAL_Y 7


#endif // __PARAMS_H