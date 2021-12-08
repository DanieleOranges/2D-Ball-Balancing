/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Trial_BOARD.h
 *
 * Code generated for Simulink model 'Trial_BOARD'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Nov 11 18:28:20 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Trial_BOARD_h_
#define RTW_HEADER_Trial_BOARD_h_
#include <string.h>
#include <stddef.h>
#ifndef Trial_BOARD_COMMON_INCLUDES_
# define Trial_BOARD_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_analoginput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* Trial_BOARD_COMMON_INCLUDES_ */

#include "Trial_BOARD_types.h"

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
  real32_T conversion8;                /* '<S22>/conversion8' */
  real32_T SFunction1_o1;              /* '<S22>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S22>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S22>/S-Function1' */
  real32_T conversion8_g;              /* '<S23>/conversion8' */
  real32_T SFunction1_o1_p;            /* '<S23>/S-Function1' */
  real32_T SFunction1_o2_p;            /* '<S23>/S-Function1' */
  real32_T SFunction1_o3_o;            /* '<S23>/S-Function1' */
  real32_T Switch[6];                  /* '<Root>/Switch' */
  int32_T SFunction;                   /* '<S18>/S-Function' */
  int32_T SFunction_g;                 /* '<S19>/S-Function' */
  int32_T SFunction_e;                 /* '<S20>/S-Function' */
  int32_T SFunction_l;                 /* '<S21>/S-Function' */
  uint16_T DataTypeConversion;         /* '<S10>/Data Type Conversion' */
  uint16_T DataTypeConversion_e;       /* '<S11>/Data Type Conversion' */
  boolean_T SFunction_m;               /* '<S15>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S24>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S24>/S-Function2' */
  boolean_T SFunction_h;               /* '<S14>/S-Function' */
  boolean_T Compare;                   /* '<S12>/Compare' */
  boolean_T Compare_j;                 /* '<S13>/Compare' */
  boolean_T LogicalOperator;           /* '<S22>/Logical Operator' */
  boolean_T LogicalOperator_f;         /* '<S23>/Logical Operator' */
} B_Trial_BOARD_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S24>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S10>/S-Function' */
  real_T SFunction_DSTATE_c;           /* '<S11>/S-Function' */
  real_T SFunction_DSTATE_d;           /* '<S18>/S-Function' */
  real_T SFunction_DSTATE_cn;          /* '<S19>/S-Function' */
  real_T SFunction_DSTATE_j;           /* '<S20>/S-Function' */
  real_T SFunction_DSTATE_e;           /* '<S21>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S22>/S-Function1' */
  real_T SFunction1_DSTATE_h;          /* '<S23>/S-Function1' */
  real_T SFunction_DSTATE_p;           /* '<S25>/S-Function' */
  real_T SFunction1_DSTATE_j;          /* '<S24>/S-Function1' */
} DW_Trial_BOARD_T;

/* Parameters (auto storage) */
struct P_Trial_BOARD_T_ {
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S18>/S-Function'
                                        */
  real_T Encoder1_dt_enc;              /* Mask Parameter: Encoder1_dt_enc
                                        * Referenced by: '<S19>/S-Function'
                                        */
  real_T Encoder2_dt_enc;              /* Mask Parameter: Encoder2_dt_enc
                                        * Referenced by: '<S20>/S-Function'
                                        */
  real_T Encoder3_dt_enc;              /* Mask Parameter: Encoder3_dt_enc
                                        * Referenced by: '<S21>/S-Function'
                                        */
  uint32_T DigitalOutput1_pinNumber;   /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S16>/Digital Output1'
                                        */
  uint32_T DigitalOutput1_pinNumber_d; /* Mask Parameter: DigitalOutput1_pinNumber_d
                                        * Referenced by: '<S17>/Digital Output1'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S26>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_m;  /* Mask Parameter: DigitalOutput_pinNumber_m
                                        * Referenced by: '<S27>/Digital Output'
                                        */
  int16_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  int16_T CompareToConstant1_const;    /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant_Value;               /* Expression: 2048
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 2048
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant_Value_ij[2];         /* Expression: [0 0]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Bias_Bias;                    /* Expression: -2048
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Gain_Gain;                    /* Expression: 6/2048
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S25>/S-Function'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S22>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S22>/S-Function1'
                                        */
  real32_T SFunction1_P2_c;            /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  real32_T SFunction1_P3_k;            /* Expression: single(dt_mot)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S15>/S-Function'
                                        */
  uint32_T SFunction_p1_k;             /* Computed Parameter: SFunction_p1_k
                                        * Referenced by: '<S7>/S-Function'
                                        */
  uint32_T SFunction_p1_kd;            /* Computed Parameter: SFunction_p1_kd
                                        * Referenced by: '<S8>/S-Function'
                                        */
  uint32_T SFunction_p1_j;             /* Computed Parameter: SFunction_p1_j
                                        * Referenced by: '<S14>/S-Function'
                                        */
  uint32_T SFunction_p1_b;             /* Computed Parameter: SFunction_p1_b
                                        * Referenced by: '<S9>/S-Function'
                                        */
  uint32_T SFunction_p1_i;             /* Computed Parameter: SFunction_p1_i
                                        * Referenced by: '<S1>/S-Function'
                                        */
  uint32_T SFunction_p1_o;             /* Computed Parameter: SFunction_p1_o
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint32_T SFunction_p1_ki;            /* Computed Parameter: SFunction_p1_ki
                                        * Referenced by: '<S3>/S-Function'
                                        */
  uint32_T SFunction_p1_h;             /* Computed Parameter: SFunction_p1_h
                                        * Referenced by: '<S4>/S-Function'
                                        */
  uint32_T SFunction_p1_f;             /* Computed Parameter: SFunction_p1_f
                                        * Referenced by: '<S5>/S-Function'
                                        */
  uint32_T SFunction_p1_n;             /* Computed Parameter: SFunction_p1_n
                                        * Referenced by: '<S6>/S-Function'
                                        */
  int16_T Constant_Value_e;            /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S1>/Constant'
                                        */
  int16_T Constant_Value_hj;           /* Computed Parameter: Constant_Value_hj
                                        * Referenced by: '<S2>/Constant'
                                        */
  int16_T Constant_Value_j;            /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S3>/Constant'
                                        */
  int16_T Constant_Value_hk;           /* Computed Parameter: Constant_Value_hk
                                        * Referenced by: '<S4>/Constant'
                                        */
  int16_T Constant_Value_a;            /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S5>/Constant'
                                        */
  int16_T Constant_Value_f3;           /* Computed Parameter: Constant_Value_f3
                                        * Referenced by: '<S6>/Constant'
                                        */
  int16_T Constant_Value_ix;           /* Computed Parameter: Constant_Value_ix
                                        * Referenced by: '<S7>/Constant'
                                        */
  int16_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S8>/Constant'
                                        */
  int16_T Constant_Value_hd;           /* Computed Parameter: Constant_Value_hd
                                        * Referenced by: '<S9>/Constant'
                                        */
  int16_T Gain_Gain_n;                 /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S1>/Gain'
                                        */
  int16_T Gain_Gain_g;                 /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S2>/Gain'
                                        */
  int16_T Gain_Gain_a;                 /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S3>/Gain'
                                        */
  int16_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S4>/Gain'
                                        */
  int16_T Gain_Gain_l;                 /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S5>/Gain'
                                        */
  int16_T Gain_Gain_m;                 /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S6>/Gain'
                                        */
  int16_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S7>/Gain'
                                        */
  int16_T Gain_Gain_j;                 /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S8>/Gain'
                                        */
  int16_T Gain_Gain_o;                 /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S9>/Gain'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S10>/S-Function'
                                        */
  uint8_T SFunction_P1_l;              /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S11>/S-Function'
                                        */
  uint8_T SFunction_P1_p;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S18>/S-Function'
                                        */
  uint8_T SFunction_P1_m;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S19>/S-Function'
                                        */
  uint8_T SFunction_P1_g;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S20>/S-Function'
                                        */
  uint8_T SFunction_P1_d;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S21>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S22>/S-Function1'
                                        */
  uint8_T SFunction1_P1_h;             /* Expression: uint8(MotorID)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S25>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Trial_BOARD_T {
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
extern P_Trial_BOARD_T Trial_BOARD_P;

/* Block signals (auto storage) */
extern B_Trial_BOARD_T Trial_BOARD_B;

/* Block states (auto storage) */
extern DW_Trial_BOARD_T Trial_BOARD_DW;

/* External data declarations for dependent source files */
extern const boolean_T Trial_BOARD_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void Trial_BOARD_initialize(void);
extern void Trial_BOARD_output0(void);
extern void Trial_BOARD_update0(void);
extern void Trial_BOARD_output1(void);
extern void Trial_BOARD_update1(void);
extern void Trial_BOARD_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Trial_BOARD_T *const Trial_BOARD_M;

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
 * '<Root>' : 'Trial_BOARD'
 * '<S1>'   : 'Trial_BOARD/Analog Input'
 * '<S2>'   : 'Trial_BOARD/Analog Input1'
 * '<S3>'   : 'Trial_BOARD/Analog Input2'
 * '<S4>'   : 'Trial_BOARD/Analog Input3'
 * '<S5>'   : 'Trial_BOARD/Analog Input4'
 * '<S6>'   : 'Trial_BOARD/Analog Input5'
 * '<S7>'   : 'Trial_BOARD/Analog Input6'
 * '<S8>'   : 'Trial_BOARD/Analog Input7'
 * '<S9>'   : 'Trial_BOARD/Analog Input8'
 * '<S10>'  : 'Trial_BOARD/Analog Output'
 * '<S11>'  : 'Trial_BOARD/Analog Output1'
 * '<S12>'  : 'Trial_BOARD/Compare To Constant'
 * '<S13>'  : 'Trial_BOARD/Compare To Constant1'
 * '<S14>'  : 'Trial_BOARD/Digital Input'
 * '<S15>'  : 'Trial_BOARD/Digital Input1'
 * '<S16>'  : 'Trial_BOARD/Digital Output'
 * '<S17>'  : 'Trial_BOARD/Digital Output1'
 * '<S18>'  : 'Trial_BOARD/Encoder'
 * '<S19>'  : 'Trial_BOARD/Encoder1'
 * '<S20>'  : 'Trial_BOARD/Encoder2'
 * '<S21>'  : 'Trial_BOARD/Encoder3'
 * '<S22>'  : 'Trial_BOARD/Motor'
 * '<S23>'  : 'Trial_BOARD/Motor1'
 * '<S24>'  : 'Trial_BOARD/PoliArd Init'
 * '<S25>'  : 'Trial_BOARD/Transmission1'
 * '<S26>'  : 'Trial_BOARD/PoliArd Init/Digital Output1'
 * '<S27>'  : 'Trial_BOARD/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_Trial_BOARD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
