/*
 * board_testa.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "board_testa".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Dec 13 16:32:44 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_board_testa_h_
#define RTW_HEADER_board_testa_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef board_testa_COMMON_INCLUDES_
#define board_testa_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "ProtocolDecoderUtilities.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* board_testa_COMMON_INCLUDES_ */

#include "board_testa_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "script\callback.h"

/* Block signals (default storage) */
typedef struct {
  f_cell_wrap_board_testa_T b[8];
  uint8_T b_dataOut[25];
  uint8_T dataIn[25];
  uint8_T payload[24];
  real_T d;
  uint8_T uv[8];
  f_cell_wrap_board_testa_T c;
  f_cell_wrap_board_testa_T d_m;
  f_cell_wrap_board_testa_T e;
  f_cell_wrap_board_testa_T f;
  f_cell_wrap_board_testa_T g;
  f_cell_wrap_board_testa_T h;
  f_cell_wrap_board_testa_T j;
  f_cell_wrap_board_testa_T k;
  char_T l_f3[5];
} B_board_testa_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_d_T obj; /* '<Root>/Serial Transmit' */
  matlabshared_embedded_utiliti_T obj_f;/* '<Root>/Protocol Decoder1' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Serial Receive' */
  codertarget_arduinobase_block_T obj_n;/* '<S1>/Digital Output2' */
  codertarget_arduinobase_block_T obj_fp;/* '<S1>/Digital Output1' */
  codertarget_arduinobase_block_T obj_c;/* '<S1>/Digital Output' */
  boolean_T objisempty;                /* '<Root>/Serial Transmit' */
  boolean_T objisempty_a;              /* '<Root>/Serial Receive' */
  boolean_T objisempty_p;              /* '<Root>/Protocol Decoder1' */
  boolean_T objisempty_o;              /* '<S1>/Digital Output2' */
  boolean_T objisempty_f;              /* '<S1>/Digital Output1' */
  boolean_T objisempty_l;              /* '<S1>/Digital Output' */
} DW_board_testa_T;

/* Parameters (default storage) */
struct P_board_testa_T_ {
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_board_testa_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_board_testa_T board_testa_P;

/* Block signals (default storage) */
extern B_board_testa_T board_testa_B;

/* Block states (default storage) */
extern DW_board_testa_T board_testa_DW;

/* Model entry point functions */
extern void board_testa_initialize(void);
extern void board_testa_step(void);
extern void board_testa_terminate(void);

/* Real-time Model object */
extern RT_MODEL_board_testa_T *const board_testa_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/ASCII to String' : Unused code path elimination
 * Block '<Root>/ASCII to String1' : Unused code path elimination
 * Block '<Root>/ASCII to String2' : Unused code path elimination
 * Block '<Root>/ASCII to String3' : Unused code path elimination
 * Block '<Root>/ASCII to String4' : Unused code path elimination
 * Block '<Root>/ASCII to String5' : Unused code path elimination
 * Block '<Root>/ASCII to String6' : Unused code path elimination
 * Block '<Root>/ASCII to String7' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion3' : Unused code path elimination
 * Block '<Root>/Data Type Conversion4' : Unused code path elimination
 * Block '<Root>/Data Type Conversion5' : Unused code path elimination
 * Block '<Root>/Data Type Conversion6' : Unused code path elimination
 * Block '<Root>/Data Type Conversion7' : Unused code path elimination
 * Block '<Root>/Data Type Conversion8' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/String to Double' : Unused code path elimination
 * Block '<Root>/String to Double1' : Unused code path elimination
 * Block '<Root>/String to Double2' : Unused code path elimination
 * Block '<Root>/String to Double3' : Unused code path elimination
 * Block '<Root>/String to Double4' : Unused code path elimination
 * Block '<Root>/String to Double5' : Unused code path elimination
 * Block '<Root>/String to Double6' : Unused code path elimination
 * Block '<Root>/String to Double7' : Unused code path elimination
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
 * '<Root>' : 'board_testa'
 * '<S1>'   : 'board_testa/LED'
 */
#endif                                 /* RTW_HEADER_board_testa_h_ */
