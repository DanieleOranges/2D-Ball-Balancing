/*
 * board_programmer.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "board_programmer".
 *
 * Model version              : 1.23
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Dec  9 19:01:36 2021
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
#include <stddef.h>
#include <string.h>
#ifndef board_programmer_COMMON_INCLUDES_
#define board_programmer_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
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
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "script\callback.h"

/* Block signals for system '<S26>/Moving Average' */
typedef struct {
  real_T csumrev[9];
  real_T MovingAverage;                /* '<S26>/Moving Average' */
} B_MovingAverage_board_program_T;

/* Block states (default storage) for system '<S26>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_bo_T obj; /* '<S26>/Moving Average' */
  boolean_T objisempty;                /* '<S26>/Moving Average' */
} DW_MovingAverage_board_progra_T;

/* Block signals for system '<S5>/controllo PP 1' */
typedef struct {
  real_T TSamp_h;                      /* '<S28>/TSamp' */
  real_T Sum2;                         /* '<S11>/Sum2' */
  real_T TSamp_e;                      /* '<S29>/TSamp' */
  real_T Sum3_h;                       /* '<S11>/Sum3' */
  real_T UnaryMinus;                   /* '<S26>/Unary Minus' */
  B_MovingAverage_board_program_T MovingAverage_p;/* '<S26>/Moving Average' */
  B_MovingAverage_board_program_T MovingAverage;/* '<S26>/Moving Average' */
} B_controlloPP1_board_programm_T;

/* Block states (default storage) for system '<S5>/controllo PP 1' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S28>/UD' */
  real_T Delay_DSTATE;                 /* '<S26>/Delay' */
  real_T UD_DSTATE_g;                  /* '<S29>/UD' */
  real_T Delay_DSTATE_k;               /* '<S27>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S27>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S26>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S27>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S26>/Discrete-Time Integrator' */
  boolean_T controlloPP1_MODE;         /* '<S5>/controllo PP 1' */
  DW_MovingAverage_board_progra_T MovingAverage_p;/* '<S26>/Moving Average' */
  DW_MovingAverage_board_progra_T MovingAverage;/* '<S26>/Moving Average' */
} DW_controlloPP1_board_program_T;

/* Block signals for system '<S6>/Moving Average' */
typedef struct {
  real_T csumrev[4];
  real_T MovingAverage;                /* '<S6>/Moving Average' */
} B_MovingAverage_board_progr_c_T;

/* Block states (default storage) for system '<S6>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_e_T obj;  /* '<S6>/Moving Average' */
  boolean_T objisempty;                /* '<S6>/Moving Average' */
} DW_MovingAverage_board_prog_f_T;

/* Block signals (default storage) */
typedef struct {
  real_T dv[8];
  e_cell_wrap_board_programmer_T b[5];
  uint8_T dataIn[23];
  real_T Merge[2];                     /* '<Root>/Merge' */
  real_T DataTypeConversion[2];        /* '<Root>/Data Type Conversion' */
  uint8_T dataIn_m[11];
  e_cell_wrap_board_programmer_T b_c[2];
  real_T DiscreteTimeIntegrator;       /* '<S15>/Discrete-Time Integrator' */
  real_T TSamp;                        /* '<S30>/TSamp' */
  real_T TSamp_b;                      /* '<S31>/TSamp' */
  real_T DiscreteTimeIntegrator_k;     /* '<S22>/Discrete-Time Integrator' */
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;
  real_T unnamed_idx_2;
  real_T unnamed_idx_3;
  real_T Diff;                         /* '<S30>/Diff' */
  real_T Diff_k;                       /* '<S31>/Diff' */
  int64m_T Gain3;                      /* '<S4>/Gain3' */
  int64m_T Bias2;                      /* '<S4>/Bias2' */
  int64m_T r;
  int64m_T r1;
  int64m_T r2;
  e_cell_wrap_board_programmer_T c;
  e_cell_wrap_board_programmer_T d;
  e_cell_wrap_board_programmer_T e;
  e_cell_wrap_board_programmer_T f;
  e_cell_wrap_board_programmer_T g;
  char_T h_f3[5];
  char_T j_f2[5];
  char_T k_f2[5];
  char_T l_f1[5];
  e_cell_wrap_board_programmer_T c_c;
  e_cell_wrap_board_programmer_T d_b;
  char_T e_f3[5];
  char_T f_f2[5];
  char_T g_f2[5];
  char_T h_f1[5];
  uint8_T uv[5];
  int32_T CCaller_o1;                  /* '<S37>/C Caller' */
  int32_T CCaller_o2;                  /* '<S37>/C Caller' */
  int32_T CCaller_o3;                  /* '<S37>/C Caller' */
  int32_T DataTypeConversion3;         /* '<S37>/Data Type Conversion3' */
  int32_T DataTypeConversion4;         /* '<S37>/Data Type Conversion4' */
  int32_T rowIdx;
  int32_T tableOffset;
  int32_T tableOffset_p;
  int32_T tableOffset_c;
  int32_T tableOffset_f;
  int32_T tableOffset_g;
  int32_T tableOffset_g1;
  int32_T qY;
  int32_T b_i;
  int32_T ret;
  int32_T b_i_m;
  int32_T ret_n;
  uint32_T Sum_k;                      /* '<S18>/Sum' */
  uint32_T rtb_Sum_k_p;
  uint8_T CCCodeBlock3[4];             /* '<S37>/C//C++ Code Block3' */
  uint8_T CCCodeBlock4[4];             /* '<S37>/C//C++ Code Block4' */
  uint8_T CCCodeBlock5[4];             /* '<S37>/C//C++ Code Block5' */
  uint8_T CCCodeBlock6[4];             /* '<S37>/C//C++ Code Block6' */
  uint8_T CCCodeBlock7[4];             /* '<S37>/C//C++ Code Block7' */
  uint8_T uv1[4];
  uint16_T inDataIdx;
  uint16_T outIdx;
  uint8_T uv2[2];
  char_T c_l;
  char_T c1;
  boolean_T rtb_DigitalInput_j;
  boolean_T NOT1;                      /* '<S1>/NOT1' */
  boolean_T Compare;                   /* '<S36>/Compare' */
  boolean_T AND_e;                     /* '<S22>/AND' */
  B_controlloPP1_board_programm_T controlloPP1_d;/* '<S2>/controllo PP 1' */
  B_MovingAverage_board_progr_c_T MovingAverage1;/* '<S6>/Moving Average' */
  B_MovingAverage_board_progr_c_T MovingAverage;/* '<S6>/Moving Average' */
  B_controlloPP1_board_programm_T controlloPP1;/* '<S5>/controllo PP 1' */
} B_board_programmer_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  matlabshared_embedded_utili_h_T obj; /* '<S37>/Protocol Encoder2' */
  codertarget_arduinobase_inter_T obj_l;/* '<S37>/Serial Transmit2' */
  codertarget_arduinobase_inter_T obj_j;/* '<S37>/Serial Transmit1' */
  matlabshared_embedded_utiliti_T obj_a;/* '<S37>/Protocol Encoder1' */
  codertarget_arduinobase_block_T obj_lp;/* '<S1>/Digital Input2' */
  codertarget_arduinobase_block_T obj_i;/* '<S1>/Digital Input1' */
  codertarget_arduinobase_block_T obj_e;/* '<S1>/Digital Input' */
  real_T UD_DSTATE;                    /* '<S30>/UD' */
  real_T UD_DSTATE_j;                  /* '<S31>/UD' */
  real_T Delay1_DSTATE;                /* '<S5>/Delay1' */
  real_T Delay1_DSTATE_a;              /* '<S22>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S22>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S22>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S15>/Discrete-Time Integrator' */
  boolean_T objisempty;                /* '<S37>/Serial Transmit2' */
  boolean_T objisempty_j;              /* '<S37>/Serial Transmit1' */
  boolean_T objisempty_p;              /* '<S37>/Protocol Encoder2' */
  boolean_T objisempty_d;              /* '<S37>/Protocol Encoder1' */
  boolean_T Memory_PreviousInput;      /* '<S8>/Memory' */
  boolean_T objisempty_b;              /* '<S1>/Digital Input2' */
  boolean_T objisempty_f;              /* '<S1>/Digital Input1' */
  boolean_T objisempty_g;              /* '<S1>/Digital Input' */
  boolean_T Controllers_MODE;          /* '<Root>/Controllers' */
  boolean_T Subsystem1_MODE;           /* '<S5>/Subsystem1' */
  boolean_T Subsystem_MODE;            /* '<S5>/Subsystem' */
  DW_controlloPP1_board_program_T controlloPP1_d;/* '<S2>/controllo PP 1' */
  DW_MovingAverage_board_prog_f_T MovingAverage1;/* '<S6>/Moving Average' */
  DW_MovingAverage_board_prog_f_T MovingAverage;/* '<S6>/Moving Average' */
  DW_controlloPP1_board_program_T controlloPP1;/* '<S5>/controllo PP 1' */
} DW_board_programmer_T;

/* Parameters for system: '<S5>/controllo PP 1' */
struct P_controlloPP1_board_programm_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S28>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_f;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                               * Referenced by: '<S29>/UD'
                               */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S28>/TSamp'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S26>/Delay'
                                        */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S29>/TSamp'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 0
                                        * Referenced by: '<S27>/Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S27>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S27>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_k;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                           * Referenced by: '<S26>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S26>/Discrete-Time Integrator'
                                        */
};

/* Parameters (default storage) */
struct P_board_programmer_T_ {
  struct_niyjK1YQs0CaQXrM5YwP5G circ1; /* Variable: circ1
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S16>/[0]'
                                        *   '<S16>/[1]'
                                        *   '<S17>/[0]'
                                        *   '<S17>/[1]'
                                        *   '<S18>/[0]'
                                        *   '<S18>/[1]'
                                        *   '<S23>/[0]'
                                        *   '<S23>/[1]'
                                        *   '<S24>/[0]'
                                        *   '<S24>/[1]'
                                        *   '<S25>/[0]'
                                        *   '<S25>/[1]'
                                        */
  struct_TL40Sm6Yho660LrrvvBZDD touch; /* Variable: touch
                                        * Referenced by:
                                        *   '<S4>/Bias2'
                                        *   '<S4>/Bias3'
                                        *   '<S4>/Gain2'
                                        *   '<S4>/Gain3'
                                        */
  struct_2daG3D4sIUVlLRg8l9bwKC pwm;   /* Variable: pwm
                                        * Referenced by:
                                        *   '<S4>/Bias'
                                        *   '<S4>/Bias1'
                                        *   '<S4>/Gain'
                                        *   '<S4>/Gain1'
                                        */
  struct_5eb5WpGlM4ku9RSV6RDqG slow;   /* Variable: slow
                                        * Referenced by:
                                        *   '<S32>/x integration gain'
                                        *   '<S32>/x matrix gain'
                                        *   '<S33>/x integration gain'
                                        *   '<S33>/x matrix gain'
                                        *   '<S26>/x integration gain'
                                        *   '<S26>/x matrix gain'
                                        *   '<S27>/x integration gain'
                                        *   '<S27>/x matrix gain'
                                        */
  real_T h;                            /* Variable: h
                                        * Referenced by:
                                        *   '<S9>/Gain'
                                        *   '<S10>/Gain1'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S30>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S31>/UD'
                               */
  int32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S36>/Constant'
                                       */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S8>/Memory'
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
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S15>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S15>/Discrete-Time Integrator'
                                        */
  real_T time_Y0;                      /* Computed Parameter: time_Y0
                                        * Referenced by: '<S9>/time'
                                        */
  real_T Prelookup2_BreakpointsData[81];/* Expression: ([1:circ1.open.lqr.N])
                                         * Referenced by: '<S9>/Prelookup2'
                                         */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S22>/Delay1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                           * Referenced by: '<S22>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T EndTimeClosed_Value;   /* Expression: round(circ1.closed.lqr.T(end), 2)
                                 * Referenced by: '<S10>/End Time Closed'
                                 */
  real_T Prelookup1_BreakpointsData[81];/* Expression: ([1:circ1.open.lqr.N])
                                         * Referenced by: '<S10>/Prelookup1'
                                         */
  real_T Constant_Value_m[2];          /* Expression: [0 0]
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S30>/TSamp'
                                        */
  real_T TSamp_WtEt_g;                 /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S31>/TSamp'
                                        */
  real_T EndTimeOpen_Value;       /* Expression: round(circ1.open.lqr.T(end), 2)
                                   * Referenced by: '<S5>/End Time Open'
                                   */
  real_T Delay1_InitialCondition_p;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay1'
                                        */
  real_T Constant1_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<S37>/Serial Transmit1'
                                        */
  real_T SerialTransmit2_Protocol;     /* Expression: 0
                                        * Referenced by: '<S37>/Serial Transmit2'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<Root>/Merge'
                                       */
  uint32_T offsetforupperindex1_Value;
                               /* Computed Parameter: offsetforupperindex1_Value
                                * Referenced by: '<S16>/offset for upper index 1'
                                */
  uint32_T offsetforupperindex1_Value_g;
                             /* Computed Parameter: offsetforupperindex1_Value_g
                              * Referenced by: '<S17>/offset for upper index 1'
                              */
  uint32_T offsetforupperindex1_Value_a;
                             /* Computed Parameter: offsetforupperindex1_Value_a
                              * Referenced by: '<S18>/offset for upper index 1'
                              */
  uint32_T offsetforupperindex1_Value_i;
                             /* Computed Parameter: offsetforupperindex1_Value_i
                              * Referenced by: '<S23>/offset for upper index 1'
                              */
  uint32_T offsetforupperindex1_Value_m;
                             /* Computed Parameter: offsetforupperindex1_Value_m
                              * Referenced by: '<S24>/offset for upper index 1'
                              */
  uint32_T offsetforupperindex1_Value_j;
                             /* Computed Parameter: offsetforupperindex1_Value_j
                              * Referenced by: '<S25>/offset for upper index 1'
                              */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S8>/Logic'
                                        */
  P_controlloPP1_board_programm_T controlloPP1_d;/* '<S2>/controllo PP 1' */
  P_controlloPP1_board_programm_T controlloPP1;/* '<S5>/controllo PP 1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_board_programmer_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_board_programmer_T board_programmer_P;

/* Block signals (default storage) */
extern B_board_programmer_T board_programmer_B;

/* Block states (default storage) */
extern DW_board_programmer_T board_programmer_DW;

/* Model entry point functions */
extern void board_programmer_initialize(void);
extern void board_programmer_step(void);
extern void board_programmer_terminate(void);

/* Real-time Model object */
extern RT_MODEL_board_programmer_T *const board_programmer_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/NOT2' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S37>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S37>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S37>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S37>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S37>/Rate Transition5' : Eliminated since input and output rates are identical
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
 * '<S3>'   : 'board_programmer/Subsystem'
 * '<S4>'   : 'board_programmer/System Interface'
 * '<S5>'   : 'board_programmer/Controllers/Subsystem2'
 * '<S6>'   : 'board_programmer/Controllers/Subsystem3'
 * '<S7>'   : 'board_programmer/Controllers/controllo PP 1'
 * '<S8>'   : 'board_programmer/Controllers/Subsystem2/S-R Flip-Flop'
 * '<S9>'   : 'board_programmer/Controllers/Subsystem2/Subsystem'
 * '<S10>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1'
 * '<S11>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1'
 * '<S12>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 1'
 * '<S13>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 2'
 * '<S14>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 3'
 * '<S15>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Timer '
 * '<S16>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 1/Matrix interpolation'
 * '<S17>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 2/Matrix interpolation'
 * '<S18>'  : 'board_programmer/Controllers/Subsystem2/Subsystem/Interpolate Matrix(x) 3/Matrix interpolation'
 * '<S19>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 4'
 * '<S20>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 5'
 * '<S21>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 6'
 * '<S22>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Timer with reset'
 * '<S23>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 4/Matrix interpolation'
 * '<S24>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 5/Matrix interpolation'
 * '<S25>'  : 'board_programmer/Controllers/Subsystem2/Subsystem1/Interpolate Matrix(x) 6/Matrix interpolation'
 * '<S26>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1/PPX 1'
 * '<S27>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1/PPX 2'
 * '<S28>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1/PPX 1/Discrete Derivative'
 * '<S29>'  : 'board_programmer/Controllers/Subsystem2/controllo PP 1/PPX 2/Discrete Derivative'
 * '<S30>'  : 'board_programmer/Controllers/Subsystem3/Discrete Derivative'
 * '<S31>'  : 'board_programmer/Controllers/Subsystem3/Discrete Derivative1'
 * '<S32>'  : 'board_programmer/Controllers/controllo PP 1/PPX 1'
 * '<S33>'  : 'board_programmer/Controllers/controllo PP 1/PPX 2'
 * '<S34>'  : 'board_programmer/Controllers/controllo PP 1/PPX 1/Discrete Derivative'
 * '<S35>'  : 'board_programmer/Controllers/controllo PP 1/PPX 2/Discrete Derivative'
 * '<S36>'  : 'board_programmer/System Interface/Compare To Constant'
 * '<S37>'  : 'board_programmer/System Interface/Subsystem'
 */
#endif                                 /* RTW_HEADER_board_programmer_h_ */
