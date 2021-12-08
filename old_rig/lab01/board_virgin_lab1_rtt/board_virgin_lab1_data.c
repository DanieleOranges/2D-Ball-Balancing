/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab1_data.c
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

#include "board_virgin_lab1.h"
#include "board_virgin_lab1_private.h"

/* Block parameters (auto storage) */
P_board_virgin_lab1_T board_virgin_lab1_P = {
  40U,                                 /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S9>/Digital Output1'
                                        */
  42U,                                 /* Mask Parameter: DigitalOutput1_pinNumber_m
                                        * Referenced by: '<S10>/Digital Output1'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S17>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S18>/Digital Output'
                                        */
  200,                                 /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S5>/Constant'
                                        */
  2048,                                /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  4000.0,                              /* Expression: 4000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  4000.0,                              /* Expression: 4000
                                        * Referenced by: '<Root>/Constant3'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  2048.0,                              /* Expression: 2048
                                        * Referenced by: '<S15>/Constant'
                                        */
  2048.0,                              /* Expression: 2048
                                        * Referenced by: '<S16>/Constant'
                                        */
  0.01,                                /* Expression: sample_time
                                        * Referenced by: '<S14>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S7>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_l
                                        * Referenced by: '<S8>/S-Function'
                                        */
  6U,                                  /* Computed Parameter: SFunction_p1_e
                                        * Referenced by: '<S2>/S-Function'
                                        */
  0U,                                  /* Computed Parameter: SFunction_p1_o
                                        * Referenced by: '<S1>/S-Function'
                                        */
  1U,                                  /* Computed Parameter: SFunction_p1_b
                                        * Referenced by: '<S3>/S-Function'
                                        */
  3U,                                  /* Computed Parameter: SFunction_p1_a
                                        * Referenced by: '<S4>/S-Function'
                                        */
  7U,                                  /* Computed Parameter: SFunction_p1_es
                                        * Referenced by: '<S12>/S-Function'
                                        */
  8U,                                  /* Computed Parameter: SFunction_p1_bw
                                        * Referenced by: '<S13>/S-Function'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S2>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S1>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S3>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_n3
                                        * Referenced by: '<S4>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S12>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_a2
                                        * Referenced by: '<S13>/Constant'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S3>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S4>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S2>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_pu
                                        * Referenced by: '<S12>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S13>/Gain'
                                        */
  6U,                                  /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S14>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S15>/S-Function'
                                        */
  0U                                   /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S16>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
