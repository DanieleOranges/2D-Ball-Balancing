/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab1.h
 *
 * Code generated for Simulink model 'board_virgin_lab1'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Oct 14 16:29:51 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_board_virgin_lab1_h_
#define RTW_HEADER_board_virgin_lab1_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef board_virgin_lab1_COMMON_INCLUDES_
# define board_virgin_lab1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analoginput_lct.h"
#endif                                 /* board_virgin_lab1_COMMON_INCLUDES_ */

#include "board_virgin_lab1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T conversion13;               /* '<S14>/conversion13' */
  real32_T conversion2;                /* '<S14>/conversion2' */
  real32_T conversion4;                /* '<S14>/conversion4' */
  real32_T conversion5;                /* '<S14>/conversion5' */
  real32_T conversion6;                /* '<S14>/conversion6' */
  real32_T conversion7;                /* '<S14>/conversion7' */
  uint16_T DataTypeConversion;         /* '<S15>/Data Type Conversion' */
  uint16_T DataTypeConversion_a;       /* '<S16>/Data Type Conversion' */
  boolean_T SFunction;                 /* '<S7>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S11>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S11>/S-Function2' */
  boolean_T conversion3;               /* '<S14>/conversion3' */
  boolean_T Compare;                   /* '<S5>/Compare' */
  boolean_T Compare_j;                 /* '<S6>/Compare' */
} B_board_virgin_lab1_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S11>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S14>/S-Function' */
  real_T SFunction_DSTATE_l;           /* '<S15>/S-Function' */
  real_T SFunction_DSTATE_m;           /* '<S16>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S11>/S-Function1' */
} DW_board_virgin_lab1_T;

/* Parameters (auto storage) */
struct P_board_virgin_lab1_T_ {
  uint32_T DigitalOutput1_pinNumber;   /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S9>/Digital Output1'
                                        */
  uint32_T DigitalOutput1_pinNumber_m; /* Mask Parameter: DigitalOutput1_pinNumber_m
                                        * Referenced by: '<S10>/Digital Output1'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S17>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_e;  /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S18>/Digital Output'
                                        */
  int16_T CompareToConstant2_const;    /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S5>/Constant'
                                        */
  int16_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 4000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 4000
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant1_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 2048
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 2048
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S14>/S-Function'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S7>/S-Function'
                                        */
  uint32_T SFunction_p1_l;             /* Computed Parameter: SFunction_p1_l
                                        * Referenced by: '<S8>/S-Function'
                                        */
  uint32_T SFunction_p1_e;             /* Computed Parameter: SFunction_p1_e
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint32_T SFunction_p1_o;             /* Computed Parameter: SFunction_p1_o
                                        * Referenced by: '<S1>/S-Function'
                                        */
  uint32_T SFunction_p1_b;             /* Computed Parameter: SFunction_p1_b
                                        * Referenced by: '<S3>/S-Function'
                                        */
  uint32_T SFunction_p1_a;             /* Computed Parameter: SFunction_p1_a
                                        * Referenced by: '<S4>/S-Function'
                                        */
  uint32_T SFunction_p1_es;            /* Computed Parameter: SFunction_p1_es
                                        * Referenced by: '<S12>/S-Function'
                                        */
  uint32_T SFunction_p1_bw;            /* Computed Parameter: SFunction_p1_bw
                                        * Referenced by: '<S13>/S-Function'
                                        */
  int16_T Constant_Value_n;            /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S2>/Constant'
                                        */
  int16_T Constant_Value_g;            /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S1>/Constant'
                                        */
  int16_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S3>/Constant'
                                        */
  int16_T Constant_Value_n3;           /* Computed Parameter: Constant_Value_n3
                                        * Referenced by: '<S4>/Constant'
                                        */
  int16_T Constant_Value_a;            /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S12>/Constant'
                                        */
  int16_T Constant_Value_a2;           /* Computed Parameter: Constant_Value_a2
                                        * Referenced by: '<S13>/Constant'
                                        */
  int16_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  int16_T Gain_Gain_n;                 /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S3>/Gain'
                                        */
  int16_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S4>/Gain'
                                        */
  int16_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S2>/Gain'
                                        */
  int16_T Gain_Gain_pu;                /* Computed Parameter: Gain_Gain_pu
                                        * Referenced by: '<S12>/Gain'
                                        */
  int16_T Gain_Gain_m;                 /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S13>/Gain'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S14>/S-Function'
                                        */
  uint8_T SFunction_P1_d;              /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S15>/S-Function'
                                        */
  uint8_T SFunction_P1_p;              /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S16>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_board_virgin_lab1_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_board_virgin_lab1_T board_virgin_lab1_P;

/* Block signals (auto storage) */
extern B_board_virgin_lab1_T board_virgin_lab1_B;

/* Block states (auto storage) */
extern DW_board_virgin_lab1_T board_virgin_lab1_DW;

/* External data declarations for dependent source files */
extern const boolean_T board_virgin_lab1_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void board_virgin_lab1_initialize(void);
extern void board_virgin_lab1_output0(void);
extern void board_virgin_lab1_update0(void);
extern void board_virgin_lab1_output1(void);
extern void board_virgin_lab1_update1(void);
extern void board_virgin_lab1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_board_virgin_lab1_T *const board_virgin_lab1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'board_virgin_lab1'
 * '<S1>'   : 'board_virgin_lab1/Analog Input 1 -> X'
 * '<S2>'   : 'board_virgin_lab1/Analog Input 1 -> X//Y1'
 * '<S3>'   : 'board_virgin_lab1/Analog Input 2 -> Y'
 * '<S4>'   : 'board_virgin_lab1/Analog Input 4 -> Laser'
 * '<S5>'   : 'board_virgin_lab1/Compare To Constant2'
 * '<S6>'   : 'board_virgin_lab1/Compare To Constant3'
 * '<S7>'   : 'board_virgin_lab1/Digital In  -Swich 2'
 * '<S8>'   : 'board_virgin_lab1/Digital In - Swich 3'
 * '<S9>'   : 'board_virgin_lab1/Digital Out - LED1'
 * '<S10>'  : 'board_virgin_lab1/Digital Out - LED2'
 * '<S11>'  : 'board_virgin_lab1/PoliArd Init1'
 * '<S12>'  : 'board_virgin_lab1/Potentiometer 1'
 * '<S13>'  : 'board_virgin_lab1/Potentiometer 2'
 * '<S14>'  : 'board_virgin_lab1/Transmission'
 * '<S15>'  : 'board_virgin_lab1/motor A01 -Y'
 * '<S16>'  : 'board_virgin_lab1/motor A02 -X'
 * '<S17>'  : 'board_virgin_lab1/PoliArd Init1/Digital Output1'
 * '<S18>'  : 'board_virgin_lab1/PoliArd Init1/Digital Output3'
 */
#endif                                 /* RTW_HEADER_board_virgin_lab1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
