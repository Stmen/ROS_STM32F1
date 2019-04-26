#ifndef __SPEED_CONTROL_H
#define __SPEED_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
//#include "stm32f10x.h"
#include "config.h"

#define OPTICAL_ENCODE_CONSTANT  (13*4) //编码器分辨率
#define REDUCTION_RATIO          30 //减速比
#define SPEED_CONTROL_PERIOD  100  //速度控制周期（ms）
#define CAR_SPEED_CONSTANT  (1000.0/SPEED_CONTROL_PERIOD/OPTICAL_ENCODE_CONSTANT/REDUCTION_RATIO)  //单位转化比例值（将速度单位转化为 转/秒，对应轮子转速）

#define MPS2NPS  ((float)1/(2*PI*WHEEL_RADIUS))

#define CAR_SPEED_SET 0
#define MOTOR_OUT_DEAD_VAL 0

extern float g_fCarSpeed;
extern int g_nLeftMotorPulseSigma, g_nRightMotorPulseSigma;
extern float g_fSpeedControlOutOld, g_fSpeedControlOutNew;
extern float g_fSpeedControlIntegral;
extern float g_fSpeedControlOut;
extern uint16_t g_nSpeedControlPeriod;
//临时为ros发布数据定义的变量，后续在优化
extern int left_encoder_count, right_encoder_count;

//蓝牙控制相关变量
extern float g_fBTSpeedSet;


void GetMotorPulse(void);
void SpeedControl(void);
void SpeedControlOutput(void);

#ifdef __cplusplus
}
#endif

#endif /* __SPEED_CONTROL_H */

