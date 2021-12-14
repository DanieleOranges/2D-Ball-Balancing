/*
 * board_programmer.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "board_programmer".
 *
 * Model version              : 1.24
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Dec 13 16:08:22 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_board_programmer_h_
#define RTW_HEADER_board_programmer_h_
#include <math.h>
#include <stdio.h>
#include <string.h>
#ifndef board_programmer_COMMON_INCLUDES_
#define board_programmer_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "ProtocolDecoderUtilities.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* board_programmer_COMMON_INCLUDES_ */

#include "board_programmer_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* user code (top of header file) */
#include "script\callback.h"

/* Block signals for system '<S27>/Moving Average' */
typedef struct {
  real_T csumrev[9];
  real_T MovingAverage;                /* '<S27>/Moving Average' */
} B_MovingAverage_board_program_T;

/* Block states (default storage) for system '<S27>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_bo_T obj; /* '<S27>/Moving Average' */
  boolean_T objisempty;                /* '<S27>/Moving Average' */
} DW_MovingAverage_board_progra_T;

/* Block signals for system '<S6>/controllo PP 1' */
typedef struct {
  real_T TSamp_h;                      /* '<S29>/TSamp' */
  real_T Sum2;                         /* '<S12>/Sum2' */
  real_T TSamp_e;                      /* '<S30>/TSamp' */
  real_T Sum3_h;                       /* '<S12>/Sum3' */
  real_T UnaryMinus;                   /* '<S27>/Unary Minus' */
  B_MovingAverage_board_program_T MovingAverage_p;/* '<S27>/Moving Average' */
  B_MovingAverage_board_program_T MovingAverage;/* '<S27>/Moving Average' */
} B_controlloPP1_board_programm_T;

/* Block states (default storage) for system '<S6>/controllo PP 1' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S29>/UD' */
  real_T Delay_DSTATE;                 /* '<S27>/Delay' */
  real_T UD_DSTATE_g;                  /* '<S30>/UD' */
  real_T Delay_DSTATE_k;               /* '<S28>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S28>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S27>/Discrete-Time Integrator' */
  int8_T controlloPP1_SubsysRanBC;     /* '<S6>/controllo PP 1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S28>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S27>/Discrete-Time Integrator' */
  boolean_T controlloPP1_MODE;         /* '<S6>/controllo PP 1' */
  DW_MovingAverage_board_progra_T MovingAverage_p;/* '<S27>/Moving Average' */
  DW_MovingAverage_board_progra_T MovingAverage;/* '<S27>/Moving Average' */
} DW_controlloPP1_board_program_T;

/* Block signals for system '<S7>/Moving Average' */
typedef struct {
  real_T csumrev[4];
  real_T MovingAverage;                /* '<S7>/Moving Average' */
} B_MovingAverage_board_progr_c_T;

/* Block states (default storage) for system '<S7>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_e_T obj;  /* '<S7>/Moving Average' */
  boolean_T objisempty;                /* '<S7>/Moving Average' */
} DW_MovingAverage_board_prog_f_T;

/* Block signals (default storage) */
typedef struct {
  char_T rtb_ASCIItoString7_m[256];
  char_T rtb_ASCIItoString7_c[256];
  real_T dv[8];
  f_cell_wrap_board_programmer_T b[8];
  e_cell_wrap_board_programmer_T b_k[5];
  uint8_T payload[24];
  real_T Merge[2];                     /* '<Root>/Merge' */
  real_T DataTypeConversion[2];        /* '<Root>/Data Type Conversion' */
  uint8_T inData[12];
  uint8_T dataIn[11];
  e_cell_wrap_board_programmer_T b_c[2];
  real_T Diff;                         /* '<S32>/Diff' */
  real_T Sum1[2];                      /* '<S10>/Sum1' */
  real_T DiscreteTimeIntegrator;       /* '<S16>/Discrete-Time Integrator' */
  real_T d;
  real_T TSamp;                        /* '<S31>/TSamp' */
  real_T TSamp_b;                      /* '<S32>/TSamp' */
  real_T DiscreteTimeIntegrator_b;     /* '<S23>/Discrete-Time Integrator' */
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;
  real_T unnamed_idx_2;
  real_T unnamed_idx_3;
  real_T Diff_p;                       /* '<S31>/Diff' */
  int64m_T Gain3;                      /* '<S5>/Gain3' */
  int64m_T Bias2;                      /* '<S5>/Bias2' */
  int64m_T r;
  int64m_T r1;
  int64m_T r2;
  uint8_T uv[8];
  f_cell_wrap_board_programmer_T c;
  f_cell_wrap_board_programmer_T d_c;
  f_cell_wrap_board_programmer_T e;
  f_cell_wrap_board_programmer_T f;
  f_cell_wrap_board_programmer_T g;
  f_cell_wrap_board_programmer_T h;
  f_cell_wrap_board_programmer_T j;
  f_cell_wrap_board_programmer_T k;
  char_T l_f3[5];
  e_cell_wrap_board_programmer_T c_f;
  e_cell_wrap_board_programmer_T d_g;
  char_T e_f3[5];
  char_T f_f2[5];
  char_T g_f2[5];
  char_T h_f1[5];
  int32_T DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  int32_T DataTypeConversion8;         /* '<Root>/Data Type Conversion8' */
  int32_T CCaller_o1;                  /* '<S38>/C Caller' */
  int32_T CCaller_o2;                  /* '<S38>/C Caller' */
  int32_T CCaller_o3;                  /* '<S38>/C Caller' */
  int32_T DataTypeConversion3;         /* '<S38>/Data Type Conversion3' */
  int32_T DataTypeConversion4;         /* '<S38>/Data Type Conversion4' */
  int32_T rowIdx;
  int32_T tableOffset;
  int32_T tableOffset_g;
  int32_T tableOffset_m;
  int32_T tableOffset_n;
  int32_T tableOffset_p;
  int32_T tableOffset_l;
  int32_T qY;
  int32_T b_i;
  int32_T ret;
  uint32_T Sum_k;                      /* '<S19>/Sum' */
  uint32_T rtb_Sum_k_j;
  uint8_T CCCodeBlock3[4];             /* '<S38>/C//C++ Code Block3' */
  uint8_T CCCodeBlock4[4];             /* '<S38>/C//C++ Code Block4' */
  uint8_T CCCodeBlock5[4];             /* '<S38>/C//C++ Code Block5' */
  uint8_T CCCodeBlock6[4];             /* '<S38>/C//C++ Code Block6' */
  uint8_T CCCodeBlock7[4];             /* '<S38>/C//C++ Code Block7' */
  uint8_T uv1[4];
  uint16_T inDataIdx;
  uint16_T outIdx;
  uint8_T uv2[2];
  boolean_T rtb_DigitalInput1_d;
  boolean_T rtb_DigitalInput2_g;
  boolean_T NOT1;                      /* '<S1>/NOT1' */
  boolean_T Compare;                   /* '<S37>/Compare' */
  boolean_T AND_e;                     /* '<S23>/AND' */
  char_T c_l;
  B_controlloPP1_board_programm_T controlloPP1_d;/* '<S2>/controllo PP 1' */
  B_MovingAverage_board_progr_c_T MovingAverage1;/* '<S7>/Moving Average' */
  B_MovingAverage_board_progr_c_T MovingAverage;/* '<S7>/Moving Average' */
  B_controlloPP1_board_programm_T controlloPP1;/* '<S6>/controllo PP 1' */
} B_board_programmer_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  matlabshared_embedded_util_hx_T obj; /* '<S38>/Protocol Encoder2' */
  codertarget_arduinobase_int_h_T obj_j;/* '<S38>/Serial Transmit1' */
  matlabshared_embedded_utiliti_T obj_f;/* '<Root>/Protocol Decoder1' */
  matlabshared_embedded_utili_h_T obj_a;/* '<S38>/Protocol Encoder1' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Serial Receive' */
  codertarget_arduinobase_block_T obj_lp;/* '<S1>/Digital Input2' */
  codertarget_arduinobase_block_T obj_i;/* '<S1>/Digital Input1' */
  codertarget_arduinobase_block_T obj_e;/* '<S1>/Digital Input' */
  codertarget_arduinobase_blo_h_T obj_n;/* '<S3>/Digital Output2' */
  codertarget_arduinobase_blo_h_T obj_fp;/* '<S3>/Digital Output1' */
  codertarget_arduinobase_blo_h_T obj_c;/* '<S3>/Digital Output' */
  real_T UD_DSTATE;                    /* '<S31>/UD' */
  real_T UD_DSTATE_j;                  /* '<S32>/UD' */
  real_T Delay1_DSTATE;                /* '<S6>/Delay1' */
  real_T Delay1_DSTATE_a;              /* '<S23>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S23>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S16>/Discrete-Time Integrator' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DataT;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Dat_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Discr;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum1_;   /* synthesized block */

  int8_T Subsystem_SubsysRanBC;        /* '<Root>/Subsystem' */
  int8_T Controllers_SubsysRanBC;      /* '<Root>/Controllers' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S6>/Subsystem1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S23>/Discrete-Time Integrator' */
  int8_T Subsystem_SubsysRanBC_j;      /* '<S6>/Subsystem' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S16>/Discrete-Time Integrator' */
  boolean_T objisempty;                /* '<S38>/Serial Transmit1' */
  boolean_T objisempty_p;              /* '<S38>/Protocol Encoder2' */
  boolean_T objisempty_d;              /* '<S38>/Protocol Encoder1' */
  boolean_T objisempty_a;              /* '<Root>/Serial Receive' */
  boolean_T objisempty_pr;             /* '<Root>/Protocol Decoder1' */
  boolean_T objisempty_o;              /* '<S3>/Digital Output2' */
  boolean_T objisempty_f;              /* '<S3>/Digital Output1' */
  boolean_T objisempty_l;              /* '<S3>/Digital Output' */
  boolean_T Memory_PreviousInput;      /* '<S9>/Memory' */
  boolean_T objisempty_b;              /* '<S1>/Digital Input2' */
  boolean_T objisempty_fl;             /* '<S1>/Digital Input1' */
  boolean_T objisempty_g;              /* '<S1>/Digital Input' */
  boolean_T Controllers_MODE;          /* '<Root>/Controllers' */
  boolean_T Subsystem1_MODE;           /* '<S6>/Subsystem1' */
  boolean_T Subsystem_MODE;            /* '<S6>/Subsystem' */
  DW_controlloPP1_board_program_T controlloPP1_d;/* '<S2>/controllo PP 1' */
  DW_MovingAverage_board_prog_f_T MovingAverage1;/* '<S7>/Moving Average' */
  DW_MovingAverage_board_prog_f_T MovingAverage;/* '<S7>/Moving Average' */
  DW_controlloPP1_board_program_T controlloPP1;/* '<S6>/controllo PP 1' */
} DW_board_programmer_T;

/* Parameters for system: '<S6>/controllo PP 1' */
struct P_controlloPP1_board_programm_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S29>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_f;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                               * Referenced by: '<S30>/UD'
                               */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S29>/TSamp'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S27>/Delay'
                                        */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S30>/TSamp'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 0
                                        * Referenced by: '<S28>/Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S28>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S28>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_k;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                           * Referenced by: '<S27>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S27>/Discrete-Time Integrator'
                                        */
};

/* Parameters (default storage) */
struct P_board_programmer_T_ {
  struct_niyjK1YQs0CaQXrM5YwP5G circ1; /* Variable: circ1
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S17>/[0]'
                                        *   '<S17>/[1]'
                                        *   '<S18>/[0]'
                                        *   '<S18>/[1]'
                                        *   '<S19>/[0]'
                                        *   '<S19>/[1]'
                                        *   '<S24>/[0]'
                                        *   '<S24>/[1]'
                                        *   '<S25>/[0]'
                                        *   '<S25>/[1]'
                                        *   '<S26>/[0]'
                                        *   '<S26>/[1]'
                                        */
  struct_TL40Sm6Yho660LrrvvBZDD touch; /* Variable: touch
                                        * Referenced by:
                                        *   '<S5>/Bias2'
                                        *   '<S5>/Bias3'
                                        *   '<S5>/Gain2'
                                        *   '<S5>/Gain3'
                                        */
  struct_2daG3D4sIUVlLRg8l9bwKC pwm;   /* Variable: pwm
                                        * Referenced by:
                                        *   '<S5>/Bias'
                                        *   '<S5>/Bias1'
                                        *   '<S5>/Gain'
                                        *   '<S5>/Gain1'
                                        */
  struct_5eb5WpGlM4ku9RSV6RDqG slow;   /* Variable: slow
                                        * Referenced by:
                                        *   '<S33>/x integration gain'
                                        *   '<S33>/x matrix gain'
                                        *   '<S34>/x integration gain'
                                        *   '<S34>/x matrix gain'
                                        *   '<S27>/x integration gain'
                                        *   '<S27>/x matrix gain'
                                        *   '<S28>/x integration gain'
                                        *   '<S28>/x matrix gain'
                                        */
  real_T h;                            /* Variable: h
                                        * Referenced by:
                                        *   '<S10>/Gain'
                                        *   '<S11>/Gain1'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S31>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S32>/UD'
                               */
  int32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S37>/Constant'
                                       */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S9>/Memory'
                                  */
  real_T DigitalInput_SampleTime;      /* Expression: 0.02
                                        * Referenced by: '<S1>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.02
                                        * Referenced by: '<S1>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: 0.02
                                        * Referenced by: '<S1>/Digital Input2'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S16>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  real_T time_Y0;                      /* Computed Parameter: time_Y0
                                        * Referenced by: '<S10>/time'
                                        */
  real_T Prelookup2_BreakpointsData[81];/* Expression: ([1:circ1.open.lqr.N])
                                         * Referenced by: '<S10>/Prelookup2'
                                         */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S23>/Delay1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                           * Referenced by: '<S23>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S23>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T EndTimeClosed_Value;   /* Expression: round(circ1.closed.lqr.T(end), 2)
                                 * Referenced by: '<S11>/End Time Closed'
                                 */
  real_T Prelookup1_BreakpointsData[81];/* Expression: ([1:circ1.open.lqr.N])
                                         * Referenced by: '<S11>/Prelookup1'
                                         */
  real_T Constant_Value_m[2];          /* Expression: [0 0]
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S31>/TSamp'
                                        */
  real_T TSamp_WtEt_g;                 /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S32>/TSamp'
                                        */
  real_T EndTimeOpen_Value;       /* Expression: round(circ1.open.lqr.T(end), 2)
                                   * Referenced by: '<S6>/End Time Open'
                                   */
  real_T Delay1_InitialCondition_p;    /* Expression: 0
                                        * Referenced by: '<S6>/Delay1'
                                        */
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T Constant1_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<S38>/Serial Transmit1'
                                        */
  real_T Constant_Value_mc;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<Root>/Merge'
                                       */
  uint32_T offsetforupperindex1_Value;
                               /* Computed Parameter: offsetforupperindex1_Value
                                * Referenced by: '<S17>/offset for upper index 1'
                                */
  uint32_T offsetforupperindex1_Value_g;
                             /* Computed Parameter: offsetforupperindex1_Value_g
                              * Referenced by: '<S18>/offset for upper index 1'
                              */
  uint32_T offsetforupperindex1_Value_a;
                             /* Computed Parameter: offsetforupperindex1_Value_a
                              * Referenced by: '<S19>/offset for upper index 1'
                              */
  uint32_T offsetforupperindex1_Value_i;
                             /* Computed Parameter: offsetforupperindex1_Value_i
                              * Referenced by: '<S24>/offset for upper index 1'
                              */
  uint32_T offsetforupperindex1_Value_m;
                             /* Computed Parameter: offsetforupperindex1_Value_m
                              * Referenced by: '<S25>/offset for upper index 1'
                              */
  uint32_T offsetforupperindex1_Value_j;
                             /* Computed Parameter: offsetforupperindex1_Value_j
                              * Referenced by: '<S26>/offset for upper index 1'
                              */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S9>/Logic'
                                        */
  P_controlloPP1_board_programm_T controlloPP1_d;/* '<S2>/controllo PP 1' */
  P_controlloPP1_board_programm_T controlloPP1;/* '<S6>/controllo PP 1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_board_programmer_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_board_programmer_T board_programmer_P;

/* Block signals (default storage) */
extern B_board_programmer_T board_programmer_B;

/* Block states (default storage) */
extern DW_board_programmer_T board_programmer_DW;

/* External function called from main */
extern void board_programmer_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void board_programmer_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void board_programmer_initialize(void);
extern void board_programmer_step0(void);
extern void board_programmer_step1(void);
extern void board_programmer_step2(void);
extern void board_programmer_terminate(void);

/* Real-time Model object */
extern RT_MODEL_board_programmer_T *const board_programmer_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/ASCII to String' : Unused code path elimination
 * Block '<Root>/ASCII to String2' : Unused code path elimination
 * Block '<Root>/ASCII to String3' : Unused code path elimination
 * Block '<Root>/ASCII to String4' : Unused code path elimination
 * Block '<Root>/ASCII to String5' : Unused code path elimination
 * Block '<Root>/ASCII to String6' : Unused code path elimination
 * Block '<S1>/NOT2' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion3' : Unused code path elimination
 * Block '<Root>/Data Type Conversion4' : Unused code path elimination
 * Block '<Root>/Data Type Conversion5' : Unused code path elimination
 * Block '<Root>/Data Type Conversion6' : Unused code path elimination
 * Block '<Root>/Data Type Conversion7' : Unused code path elimination
 * Block '<Root>/String to Double' : Unused code path elimination
 * Block '<Root>/String to Double2' : Unused code path elimination
 * Block '<Root>/String to Double3' : Unused code path elimination
 * Block '<Root>/String to Double4' : Unused code path elimination
 * Block '<Root>/String to Double5' : Unused code path elimination
 * Block '<Root>/String to Double6' : Unused code path elimination
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S38>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S38>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S38>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S38>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S38>/Rate Transition5' : Eliminated since input and output rates are identical
 */

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
 * '<Root>' : 'board_programmer'
 * '<S1>'   : 'board_programmer/Buttons'
 * '<S2>'   : 'board_programmer/Controllers'
 * '<S3>'   : 'board_programmer/LED'
 * '<S4>'   : 'board_programmer/Subsystem'
 * '<S5>'   : 'board_programmer/System Interface'
 * '<S6>'   : 'board_programmer/Controllers/Subsystem2'
 * '<S7>'   : 'board_programmer/Controllers/Subsystem3'
 * '<S8>'   : 'board_programmer/Controllers/controllo PP 1'
 * '<S9>'   : 'board_programmer/Controllers/Subsystem2/S-R Flip-Flop'
 * '<S10>'  : 'board_programmer/Controllers/Subsystem2/Subsystem'
 * '<S11>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1'
 * '<S12>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1'
 * '<S13>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 1'
 * '<S14>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 2'
 * '<S15>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 3'
 * '<S16>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Timer '
 * '<S17>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 1/Matrix interpolation'
 * '<S18>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 2/Matrix interpolation'
 * '<S19>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 3/Matrix interpolation'
 * '<S20>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 4'
 * '<S21>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 5'
 * '<S22>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 6'
 * '<S23>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Timer with reset'
 * '<S24>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 4/Matrix interpolation'
 * '<S25>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 5/Matrix interpolation'
 * '<S26>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 6/Matrix interpolation'
 * '<S27>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1/PPX 1'
 * '<S28>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1/PPX 2'
 * '<S29>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1/PPX 1/Discrete Derivative'
 * '<S30>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1/PPX 2/Discrete Derivative'
 * '<S31>'  : 'board_programmer/Controllers/Subsystem3/Discrete Derivative'
 * '<S32>'  : 'board_programmer/Controllers/Subsystem3/Discrete Derivative1'
 * '<S33>'  : 'board_programmer/Controllers/controllo PP 1/PPX 1'
 * '<S34>'  : 'board_programmer/Controllers/controllo PP 1/PPX 2'
 * '<S35>'  : 'board_programmer/Controllers/controllo PP 1/PPX 1/Discrete Derivative'
 * '<S36>'  : 'board_programmer/Controllers/controllo PP 1/PPX 2/Discrete Derivative'
 * '<S37>'  : 'board_programmer/System Interface/Compare To Constant'
 * '<S38>'  : 'board_programmer/System Interface/Subsystem'
 */
#endif                                 /* RTW_HEADER_board_programmer_h_ */
