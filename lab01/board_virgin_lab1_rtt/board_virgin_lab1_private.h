/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab1_private.h
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

#ifndef RTW_HEADER_board_virgin_lab1_private_h_
#define RTW_HEADER_board_virgin_lab1_private_h_
#include "rtwtypes.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern void signals_Outputs_wrapper(boolean_T *signal_enable,
  boolean_T *signal_alarm,
  const real_T *xD);
extern void signals_Update_wrapper(const boolean_T *signal_enable,
  const boolean_T *signal_alarm,
  real_T *xD);
extern void SerialTx_Outputs_wrapper(const boolean_T *C1,
  const boolean_T *C2,
  const boolean_T *C3,
  const boolean_T *C4,
  const boolean_T *C5,
  const boolean_T *C6,
  const boolean_T *C7,
  const boolean_T *C8,
  const real32_T *S1,
  const real32_T *S2,
  const real32_T *S3,
  const real32_T *S4,
  const real32_T *S5,
  const real32_T *S6,
  const real_T *xD,
  const real_T *sample_tx, const int_T p_width0,
  const uint16_T *Samples, const int_T p_width1);
extern void SerialTx_Update_wrapper(const boolean_T *C1,
  const boolean_T *C2,
  const boolean_T *C3,
  const boolean_T *C4,
  const boolean_T *C5,
  const boolean_T *C6,
  const boolean_T *C7,
  const boolean_T *C8,
  const real32_T *S1,
  const real32_T *S2,
  const real32_T *S3,
  const real32_T *S4,
  const real32_T *S5,
  const real32_T *S6,
  real_T *xD,
  const real_T *sample_tx, const int_T p_width0,
  const uint16_T *Samples, const int_T p_width1);
extern void sfcn_DAC_Outputs_wrapper(const uint16_T *in,
  const real_T *xD,
  const uint8_T *DACpin, const int_T p_width0);
extern void sfcn_DAC_Update_wrapper(const uint16_T *in,
  real_T *xD,
  const uint8_T *DACpin, const int_T p_width0);
extern void data_struct_init_Outputs_wrapper(const real_T *xD);
extern void data_struct_init_Update_wrapper(real_T *xD);

#endif                                 /* RTW_HEADER_board_virgin_lab1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
