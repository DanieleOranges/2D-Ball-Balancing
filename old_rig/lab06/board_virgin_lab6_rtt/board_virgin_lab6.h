/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab6.h
 *
 * Code generated for Simulink model 'board_virgin_lab6'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Nov 11 20:00:18 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_board_virgin_lab6_h_
#define RTW_HEADER_board_virgin_lab6_h_
#include <string.h>
#include <stddef.h>
#ifndef board_virgin_lab6_COMMON_INCLUDES_
# define board_virgin_lab6_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* board_virgin_lab6_COMMON_INCLUDES_ */

#include "board_virgin_lab6_types.h"

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
  real_T TSamp;                        /* '<S26>/TSamp' */
  real_T Sum2;                         /* '<S6>/Sum2' */
  real_T Sum1;                         /* '<S24>/Sum1' */
  real_T TSamp_n;                      /* '<S27>/TSamp' */
  real_T Sum3;                         /* '<S6>/Sum3' */
  real_T Sum1_k;                       /* '<S25>/Sum1' */
  real32_T DataTypeConversion4;        /* '<S4>/Data Type Conversion4' */
  real32_T DataTypeConversion1;        /* '<S4>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<S4>/Data Type Conversion2' */
  real32_T DataTypeConversion3;        /* '<S4>/Data Type Conversion3' */
  real32_T conversion6;                /* '<S19>/conversion6' */
  real32_T conversion7;                /* '<S19>/conversion7' */
  uint16_T DataTypeConversion;         /* '<S20>/Data Type Conversion' */
  uint16_T DataTypeConversion_a;       /* '<S21>/Data Type Conversion' */
  boolean_T SFunction;                 /* '<S14>/S-Function' */
  boolean_T SFunction_o;               /* '<S13>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S2>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S2>/S-Function2' */
} B_board_virgin_lab6_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S26>/UD' */
  real_T Delay_DSTATE;                 /* '<S24>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S24>/Discrete-Time Integrator' */
  real_T UD_DSTATE_f;                  /* '<S27>/UD' */
  real_T Delay_DSTATE_d;               /* '<S25>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S25>/Discrete-Time Integrator' */
  real_T SFunction2_DSTATE;            /* '<S2>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S19>/S-Function' */
  real_T SFunction_DSTATE_l;           /* '<S20>/S-Function' */
  real_T SFunction_DSTATE_m;           /* '<S21>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S2>/S-Function1' */
  real_T PrevY[2];                     /* '<Root>/Rate Limiter1' */
} DW_board_virgin_lab6_T;

/* Parameters (auto storage) */
struct P_board_virgin_lab6_T_ {
  real_T Kx[3];                        /* Variable: Kx
                                        * Referenced by: '<S24>/x matrix gain'
                                        */
  real_T Kxi;                          /* Variable: Kxi
                                        * Referenced by: '<S24>/x integration gain'
                                        */
  real_T Ky[3];                        /* Variable: Ky
                                        * Referenced by: '<S25>/x matrix gain'
                                        */
  real_T Kyi;                          /* Variable: Kyi
                                        * Referenced by: '<S25>/x integration gain'
                                        */
  real_T T1gain;                       /* Variable: T1gain
                                        * Referenced by: '<S4>/gain motY'
                                        */
  real_T T1offset;                     /* Variable: T1offset
                                        * Referenced by: '<S4>/Bias motY'
                                        */
  real_T T2gain;                       /* Variable: T2gain
                                        * Referenced by: '<S4>/gain motX'
                                        */
  real_T T2offset;                     /* Variable: T2offset
                                        * Referenced by: '<S4>/Bias motX'
                                        */
  real_T V2theta_x;                    /* Variable: V2theta_x
                                        * Referenced by: '<S24>/x integration gain1'
                                        */
  real_T V2theta_y;                    /* Variable: V2theta_y
                                        * Referenced by: '<S25>/x integration gain1'
                                        */
  real_T Xtare_raw[5];                 /* Variable: Xtare_raw
                                        * Referenced by: '<S4>/1-D Lookup Table'
                                        */
  real_T Xtare_real[5];                /* Variable: Xtare_real
                                        * Referenced by: '<S4>/1-D Lookup Table'
                                        */
  real_T Ytare_raw[5];                 /* Variable: Ytare_raw
                                        * Referenced by: '<S4>/1-D Lookup Table1'
                                        */
  real_T Ytare_real[5];                /* Variable: Ytare_real
                                        * Referenced by: '<S4>/1-D Lookup Table1'
                                        */
  real_T ref_2[2];                     /* Variable: ref_2
                                        * Referenced by: '<S3>/Constant5'
                                        */
  real_T ref_3[2];                     /* Variable: ref_3
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S26>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_k;/* Mask Parameter: DiscreteDerivative_ICPrevScal_k
                                          * Referenced by: '<S27>/UD'
                                          */
  uint32_T DigitalOutput1_pinNumber;   /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S15>/Digital Output1'
                                        */
  uint32_T DigitalOutput1_pinNumber_h; /* Mask Parameter: DigitalOutput1_pinNumber_h
                                        * Referenced by: '<S16>/Digital Output1'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S9>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_f;  /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S10>/Digital Output'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 2048
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 2048
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant2_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S26>/TSamp'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S24>/Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S24>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S24>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S27>/TSamp'
                                        */
  real_T Delay_InitialCondition_j;     /* Expression: 0
                                        * Referenced by: '<S25>/Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                          * Referenced by: '<S25>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
  real_T RateLimiter1_RisingLim;       /* Computed Parameter: RateLimiter1_RisingLim
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  real_T RateLimiter1_FallingLim;      /* Computed Parameter: RateLimiter1_FallingLim
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  real_T RateLimiter1_IC;              /* Expression: 0
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S19>/S-Function'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S11>/S-Function'
                                        */
  uint32_T SFunction_p1_d;             /* Computed Parameter: SFunction_p1_d
                                        * Referenced by: '<S14>/S-Function'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S24>/Delay'
                                        */
  uint32_T SFunction_p1_b;             /* Computed Parameter: SFunction_p1_b
                                        * Referenced by: '<S12>/S-Function'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S25>/Delay'
                                        */
  uint32_T SFunction_p1_i;             /* Computed Parameter: SFunction_p1_i
                                        * Referenced by: '<S13>/S-Function'
                                        */
  uint32_T SFunction_p1_e;             /* Computed Parameter: SFunction_p1_e
                                        * Referenced by: '<S17>/S-Function'
                                        */
  uint32_T SFunction_p1_bw;            /* Computed Parameter: SFunction_p1_bw
                                        * Referenced by: '<S18>/S-Function'
                                        */
  int16_T Constant_Value_gs;           /* Computed Parameter: Constant_Value_gs
                                        * Referenced by: '<S11>/Constant'
                                        */
  int16_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S12>/Constant'
                                        */
  int16_T Constant_Value_a;            /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S17>/Constant'
                                        */
  int16_T Constant_Value_a2;           /* Computed Parameter: Constant_Value_a2
                                        * Referenced by: '<S18>/Constant'
                                        */
  int16_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S11>/Gain'
                                        */
  int16_T Gain_Gain_n;                 /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S12>/Gain'
                                        */
  int16_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S17>/Gain'
                                        */
  int16_T Gain_Gain_m;                 /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S18>/Gain'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S19>/S-Function'
                                        */
  uint8_T SFunction_P1_d;              /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S20>/S-Function'
                                        */
  uint8_T SFunction_P1_p;              /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S21>/S-Function'
                                        */
  boolean_T Constant_Value_dn;         /* Computed Parameter: Constant_Value_dn
                                        * Referenced by: '<Root>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_board_virgin_lab6_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_board_virgin_lab6_T board_virgin_lab6_P;

/* Block signals (auto storage) */
extern B_board_virgin_lab6_T board_virgin_lab6_B;

/* Block states (auto storage) */
extern DW_board_virgin_lab6_T board_virgin_lab6_DW;

/* External data declarations for dependent source files */
extern const boolean_T board_virgin_lab6_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void board_virgin_lab6_initialize(void);
extern void board_virgin_lab6_output0(void);
extern void board_virgin_lab6_update0(void);
extern void board_virgin_lab6_output1(void);
extern void board_virgin_lab6_update1(void);
extern void board_virgin_lab6_terminate(void);

/* Real-time Model object */
extern RT_MODEL_board_virgin_lab6_T *const board_virgin_lab6_M;

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
 * '<Root>' : 'board_virgin_lab6'
 * '<S1>'   : 'board_virgin_lab6/MARCO'
 * '<S2>'   : 'board_virgin_lab6/PoliArd Init'
 * '<S3>'   : 'board_virgin_lab6/Subsystem'
 * '<S4>'   : 'board_virgin_lab6/Subsystem1'
 * '<S5>'   : 'board_virgin_lab6/controllo PID1'
 * '<S6>'   : 'board_virgin_lab6/controllo PP '
 * '<S7>'   : 'board_virgin_lab6/MARCO/S-R Flip-Flop'
 * '<S8>'   : 'board_virgin_lab6/MARCO/Sample and Hold'
 * '<S9>'   : 'board_virgin_lab6/PoliArd Init/Digital Output1'
 * '<S10>'  : 'board_virgin_lab6/PoliArd Init/Digital Output3'
 * '<S11>'  : 'board_virgin_lab6/Subsystem1/Analog Input 1 -> X'
 * '<S12>'  : 'board_virgin_lab6/Subsystem1/Analog Input 2 -> Y'
 * '<S13>'  : 'board_virgin_lab6/Subsystem1/Digital In  -Swich 1'
 * '<S14>'  : 'board_virgin_lab6/Subsystem1/Digital In  -Swich 2'
 * '<S15>'  : 'board_virgin_lab6/Subsystem1/Digital Out - LED1'
 * '<S16>'  : 'board_virgin_lab6/Subsystem1/Digital Out - LED2'
 * '<S17>'  : 'board_virgin_lab6/Subsystem1/Potentiometer 1'
 * '<S18>'  : 'board_virgin_lab6/Subsystem1/Potentiometer 2'
 * '<S19>'  : 'board_virgin_lab6/Subsystem1/Transmission'
 * '<S20>'  : 'board_virgin_lab6/Subsystem1/motor A01 -Y'
 * '<S21>'  : 'board_virgin_lab6/Subsystem1/motor A02 -X'
 * '<S22>'  : 'board_virgin_lab6/controllo PID1/PID Controller2'
 * '<S23>'  : 'board_virgin_lab6/controllo PID1/PID Controller4'
 * '<S24>'  : 'board_virgin_lab6/controllo PP /PPX 1'
 * '<S25>'  : 'board_virgin_lab6/controllo PP /PPX 2'
 * '<S26>'  : 'board_virgin_lab6/controllo PP /PPX 1/Discrete Derivative'
 * '<S27>'  : 'board_virgin_lab6/controllo PP /PPX 2/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_board_virgin_lab6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
