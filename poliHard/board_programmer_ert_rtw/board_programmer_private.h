/*
 * board_programmer_private.h
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

#ifndef RTW_HEADER_board_programmer_private_h_
#define RTW_HEADER_board_programmer_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "board_programmer.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

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

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void double2ascii_Start_wrapper(void);
SFB_EXTERN_C void double2ascii_Outputs_wrapper(const int32_T *double_input,
  uint8_T *array_output);
SFB_EXTERN_C void double2ascii_Terminate_wrapper(void);

#undef SFB_EXTERN_C

extern real_T rt_roundd_snf(real_T u);
extern uint32_T plook_lincg(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction);
extern void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);
extern void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern void board_pr_MovingAverage_Init(DW_MovingAverage_board_progra_T *localDW);
extern void board_p_MovingAverage_Reset(DW_MovingAverage_board_progra_T *localDW);
extern void board_p_MovingAverage_Start(DW_MovingAverage_board_progra_T *localDW);
extern void board_program_MovingAverage(real_T rtu_0,
  B_MovingAverage_board_program_T *localB, DW_MovingAverage_board_progra_T
  *localDW);
extern void board_pro_controlloPP1_Init(DW_controlloPP1_board_program_T *localDW,
  P_controlloPP1_board_programm_T *localP);
extern void board_pr_controlloPP1_Reset(DW_controlloPP1_board_program_T *localDW,
  P_controlloPP1_board_programm_T *localP);
extern void board_pr_controlloPP1_Start(DW_controlloPP1_board_program_T *localDW);
extern void board__controlloPP1_Disable(DW_controlloPP1_board_program_T *localDW);
extern void board_programm_controlloPP1(boolean_T rtu_Enable, const real_T
  rtu_ref[2], const real_T rtu_pos[2], real_T rty_theta[2],
  B_controlloPP1_board_programm_T *localB, DW_controlloPP1_board_program_T
  *localDW, P_controlloPP1_board_programm_T *localP);
extern void board__MovingAverage_p_Init(DW_MovingAverage_board_prog_f_T *localDW);
extern void board_MovingAverage_g_Start(DW_MovingAverage_board_prog_f_T *localDW);
extern void board_progr_MovingAverage_p(real_T rtu_0,
  B_MovingAverage_board_progr_c_T *localB, DW_MovingAverage_board_prog_f_T
  *localDW);
extern void board_pr_MovingAverage_Term(DW_MovingAverage_board_progra_T *localDW);
extern void board_pro_controlloPP1_Term(DW_controlloPP1_board_program_T *localDW);
extern void board__MovingAverage_d_Term(DW_MovingAverage_board_prog_f_T *localDW);

#endif                              /* RTW_HEADER_board_programmer_private_h_ */
