/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab2.h
 *
 * Code generated for Simulink model 'board_virgin_lab2'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Oct 14 19:15:12 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_board_virgin_lab2_h_
#define RTW_HEADER_board_virgin_lab2_h_
#include <string.h>
#include <stddef.h>
#ifndef board_virgin_lab2_COMMON_INCLUDES_
# define board_virgin_lab2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* board_virgin_lab2_COMMON_INCLUDES_ */

#include "board_virgin_lab2_types.h"

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

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Bias;                         /* '<Root>/Bias' */
  real_T Bias1;                        /* '<Root>/Bias1' */
  real_T FilterCoefficient;            /* '<S1>/Filter Coefficient' */
  real_T IntegralGain;                 /* '<S1>/Integral Gain' */
  real_T FilterCoefficient_p;          /* '<S2>/Filter Coefficient' */
  real_T IntegralGain_h;               /* '<S2>/Integral Gain' */
  real_T Constant;                     /* '<S15>/Constant' */
  real_T RateTransition1;              /* '<S19>/Rate Transition1' */
  real_T RateTransition2;              /* '<S19>/Rate Transition2' */
  real_T BiasmotX1;                    /* '<S4>/Bias motX1' */
  real_T BiasmotY1;                    /* '<S4>/Bias motY1' */
  real_T RateTransition10;             /* '<S19>/Rate Transition10' */
  real_T Constant_c;                   /* '<S20>/Constant' */
  real_T Constant_d;                   /* '<S21>/Constant' */
  real32_T conversion13;               /* '<S19>/conversion13' */
  real32_T conversion2;                /* '<S19>/conversion2' */
  real32_T conversion4;                /* '<S19>/conversion4' */
  real32_T conversion5;                /* '<S19>/conversion5' */
  real32_T conversion6;                /* '<S19>/conversion6' */
  real32_T conversion7;                /* '<S19>/conversion7' */
  int16_T Constant_n;                  /* '<S7>/Constant' */
  int16_T Constant_e;                  /* '<S9>/Constant' */
  int16_T RateTransition5;             /* '<S19>/Rate Transition5' */
  int16_T RateTransition6;             /* '<S19>/Rate Transition6' */
  uint16_T DataTypeConversion;         /* '<S20>/Data Type Conversion' */
  uint16_T DataTypeConversion_a;       /* '<S21>/Data Type Conversion' */
  uint8_T DataTypeConversion_l;        /* '<S15>/Data Type Conversion' */
  uint8_T DataTypeConversion_c;        /* '<S5>/Data Type Conversion' */
  uint8_T DataTypeConversion_p;        /* '<S6>/Data Type Conversion' */
  boolean_T SFunction2_o1;             /* '<S3>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S3>/S-Function2' */
  boolean_T RateTransition;            /* '<S19>/Rate Transition' */
  boolean_T conversion1;               /* '<S19>/conversion1' */
  boolean_T conversion3;               /* '<S19>/conversion3' */
  boolean_T Compare;                   /* '<S11>/Compare' */
  boolean_T Compare_j;                 /* '<S12>/Compare' */
} B_board_virgin_lab2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S3>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S19>/S-Function' */
  real_T SFunction_DSTATE_l;           /* '<S20>/S-Function' */
  real_T SFunction_DSTATE_m;           /* '<S21>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S3>/S-Function1' */
} DW_board_virgin_lab2_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S1>/Filter' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S2>/Filter' */
  real_T Integrator_CSTATE_m;          /* '<S2>/Integrator' */
} X_board_virgin_lab2_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S1>/Filter' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S2>/Filter' */
  real_T Integrator_CSTATE_m;          /* '<S2>/Integrator' */
} XDot_board_virgin_lab2_T;

/* State disabled  */
typedef struct {
  boolean_T Filter_CSTATE;             /* '<S1>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Filter_CSTATE_c;           /* '<S2>/Filter' */
  boolean_T Integrator_CSTATE_m;       /* '<S2>/Integrator' */
} XDis_board_virgin_lab2_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_board_virgin_lab2_T_ {
  real_T T1gain;                       /* Variable: T1gain
                                        * Referenced by:
                                        *   '<S4>/gain motY'
                                        *   '<S4>/gain motY1'
                                        */
  real_T T1offset;                     /* Variable: T1offset
                                        * Referenced by:
                                        *   '<S4>/Bias motY'
                                        *   '<S4>/Bias motY1'
                                        */
  real_T T2gain;                       /* Variable: T2gain
                                        * Referenced by:
                                        *   '<S4>/gain motX'
                                        *   '<S4>/gain motX1'
                                        */
  real_T T2offset;                     /* Variable: T2offset
                                        * Referenced by:
                                        *   '<S4>/Bias motX'
                                        *   '<S4>/Bias motX1'
                                        */
  int32_T Xoffset;                     /* Variable: Xoffset
                                        * Referenced by: '<S4>/Bias X'
                                        */
  int32_T Yoffset;                     /* Variable: Yoffset
                                        * Referenced by: '<S4>/Bias Y'
                                        */
  int16_T Xgain;                       /* Variable: Xgain
                                        * Referenced by: '<S4>/gain X'
                                        */
  int16_T Ygain;                       /* Variable: Ygain
                                        * Referenced by: '<S4>/gain Y'
                                        */
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S2>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S2>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  uint32_T DigitalOutput1_pinNumber;   /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S15>/Digital Output1'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S5>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_e;  /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S6>/Digital Output'
                                        */
  int16_T CompareToConstant2_const;    /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  int16_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4095
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 4095
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: -1
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Bias1_Bias;                   /* Expression: -0.01
                                        * Referenced by: '<Root>/Bias1'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Filter_IC_g;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S2>/Filter'
                                        */
  real_T Integrator_IC_e;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S19>/S-Function'
                                        */
  real_T Constant_Value_d;             /* Expression: 2048
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 2048
                                        * Referenced by: '<S21>/Constant'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S7>/S-Function'
                                        */
  uint32_T SFunction_p1_b;             /* Computed Parameter: SFunction_p1_b
                                        * Referenced by: '<S9>/S-Function'
                                        */
  uint32_T SFunction_p1_i;             /* Computed Parameter: SFunction_p1_i
                                        * Referenced by: '<S13>/S-Function'
                                        */
  uint32_T SFunction_p1_e;             /* Computed Parameter: SFunction_p1_e
                                        * Referenced by: '<S8>/S-Function'
                                        */
  uint32_T SFunction_p1_a;             /* Computed Parameter: SFunction_p1_a
                                        * Referenced by: '<S10>/S-Function'
                                        */
  uint32_T SFunction_p1_es;            /* Computed Parameter: SFunction_p1_es
                                        * Referenced by: '<S17>/S-Function'
                                        */
  uint32_T SFunction_p1_bw;            /* Computed Parameter: SFunction_p1_bw
                                        * Referenced by: '<S18>/S-Function'
                                        */
  int16_T Constant_Value_g;            /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S7>/Constant'
                                        */
  int16_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S9>/Constant'
                                        */
  int16_T Constant_Value_n;            /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S8>/Constant'
                                        */
  int16_T Constant_Value_n3;           /* Computed Parameter: Constant_Value_n3
                                        * Referenced by: '<S10>/Constant'
                                        */
  int16_T Constant_Value_a;            /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S17>/Constant'
                                        */
  int16_T Constant_Value_a2;           /* Computed Parameter: Constant_Value_a2
                                        * Referenced by: '<S18>/Constant'
                                        */
  int16_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S7>/Gain'
                                        */
  int16_T Gain_Gain_n;                 /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S9>/Gain'
                                        */
  int16_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S10>/Gain'
                                        */
  int16_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S8>/Gain'
                                        */
  int16_T Gain_Gain_pu;                /* Computed Parameter: Gain_Gain_pu
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
};

/* Real-time Model Data Structure */
struct tag_RTM_board_virgin_lab2_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_board_virgin_lab2_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[4];
    real_T odeF[3][4];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_2;
      boolean_T TID1_2;
    } RateInteraction;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_board_virgin_lab2_T board_virgin_lab2_P;

/* Block signals (auto storage) */
extern B_board_virgin_lab2_T board_virgin_lab2_B;

/* Continuous states (auto storage) */
extern X_board_virgin_lab2_T board_virgin_lab2_X;

/* Block states (auto storage) */
extern DW_board_virgin_lab2_T board_virgin_lab2_DW;

/* External data declarations for dependent source files */
extern const boolean_T board_virgin_lab2_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void board_virgin_lab2_initialize(void);
extern void board_virgin_lab2_output0(void);
extern void board_virgin_lab2_update0(void);
extern void board_virgin_lab2_output2(void);
extern void board_virgin_lab2_update2(void);
extern void board_virgin_lab2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_board_virgin_lab2_T *const board_virgin_lab2_M;

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
 * '<Root>' : 'board_virgin_lab2'
 * '<S1>'   : 'board_virgin_lab2/PID Controller'
 * '<S2>'   : 'board_virgin_lab2/PID Controller1'
 * '<S3>'   : 'board_virgin_lab2/PoliArd Init1'
 * '<S4>'   : 'board_virgin_lab2/Subsystem1'
 * '<S5>'   : 'board_virgin_lab2/PoliArd Init1/Digital Output1'
 * '<S6>'   : 'board_virgin_lab2/PoliArd Init1/Digital Output3'
 * '<S7>'   : 'board_virgin_lab2/Subsystem1/Analog Input 1 -> X'
 * '<S8>'   : 'board_virgin_lab2/Subsystem1/Analog Input 1 -> X//Y1'
 * '<S9>'   : 'board_virgin_lab2/Subsystem1/Analog Input 2 -> Y'
 * '<S10>'  : 'board_virgin_lab2/Subsystem1/Analog Input 4 -> Laser'
 * '<S11>'  : 'board_virgin_lab2/Subsystem1/Compare To Constant2'
 * '<S12>'  : 'board_virgin_lab2/Subsystem1/Compare To Constant3'
 * '<S13>'  : 'board_virgin_lab2/Subsystem1/Digital In  -Swich 2'
 * '<S14>'  : 'board_virgin_lab2/Subsystem1/Digital In - Swich 3'
 * '<S15>'  : 'board_virgin_lab2/Subsystem1/Digital Out - LED1'
 * '<S16>'  : 'board_virgin_lab2/Subsystem1/Digital Out - LED2'
 * '<S17>'  : 'board_virgin_lab2/Subsystem1/Potentiometer 1'
 * '<S18>'  : 'board_virgin_lab2/Subsystem1/Potentiometer 2'
 * '<S19>'  : 'board_virgin_lab2/Subsystem1/Transmission'
 * '<S20>'  : 'board_virgin_lab2/Subsystem1/motor A01 -Y'
 * '<S21>'  : 'board_virgin_lab2/Subsystem1/motor A02 -X'
 */
#endif                                 /* RTW_HEADER_board_virgin_lab2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
