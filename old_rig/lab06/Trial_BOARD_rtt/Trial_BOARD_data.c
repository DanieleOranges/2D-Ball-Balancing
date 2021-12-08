/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Trial_BOARD_data.c
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

#include "Trial_BOARD.h"
#include "Trial_BOARD_private.h"

/* Block parameters (auto storage) */
P_Trial_BOARD_T Trial_BOARD_P = {
  -1.0,                                /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S18>/S-Function'
                                        */
  -1.0,                                /* Mask Parameter: Encoder1_dt_enc
                                        * Referenced by: '<S19>/S-Function'
                                        */
  -1.0,                                /* Mask Parameter: Encoder2_dt_enc
                                        * Referenced by: '<S20>/S-Function'
                                        */
  -1.0,                                /* Mask Parameter: Encoder3_dt_enc
                                        * Referenced by: '<S21>/S-Function'
                                        */
  42U,                                 /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S16>/Digital Output1'
                                        */
  40U,                                 /* Mask Parameter: DigitalOutput1_pinNumber_d
                                        * Referenced by: '<S17>/Digital Output1'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S26>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_m
                                        * Referenced by: '<S27>/Digital Output'
                                        */
  200,                                 /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  2048,                                /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S13>/Constant'
                                        */
  2048.0,                              /* Expression: 2048
                                        * Referenced by: '<S10>/Constant'
                                        */
  2048.0,                              /* Expression: 2048
                                        * Referenced by: '<S11>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 0.0 },
  -2048.0,                             /* Expression: -2048
                                        * Referenced by: '<Root>/Bias'
                                        */
  0.0029296875,                        /* Expression: 6/2048
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.01,                                /* Expression: sample_time
                                        * Referenced by: '<S25>/S-Function'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S22>/S-Function1'
                                        */
  -1.0F,                               /* Expression: single(dt_mot)
                                        * Referenced by: '<S22>/S-Function1'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  -1.0F,                               /* Expression: single(dt_mot)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S15>/S-Function'
                                        */
  7U,                                  /* Computed Parameter: SFunction_p1_k
                                        * Referenced by: '<S7>/S-Function'
                                        */
  8U,                                  /* Computed Parameter: SFunction_p1_kd
                                        * Referenced by: '<S8>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_j
                                        * Referenced by: '<S14>/S-Function'
                                        */
  6U,                                  /* Computed Parameter: SFunction_p1_b
                                        * Referenced by: '<S9>/S-Function'
                                        */
  0U,                                  /* Computed Parameter: SFunction_p1_i
                                        * Referenced by: '<S1>/S-Function'
                                        */
  1U,                                  /* Computed Parameter: SFunction_p1_o
                                        * Referenced by: '<S2>/S-Function'
                                        */
  2U,                                  /* Computed Parameter: SFunction_p1_ki
                                        * Referenced by: '<S3>/S-Function'
                                        */
  3U,                                  /* Computed Parameter: SFunction_p1_h
                                        * Referenced by: '<S4>/S-Function'
                                        */
  4U,                                  /* Computed Parameter: SFunction_p1_f
                                        * Referenced by: '<S5>/S-Function'
                                        */
  5U,                                  /* Computed Parameter: SFunction_p1_n
                                        * Referenced by: '<S6>/S-Function'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S1>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_hj
                                        * Referenced by: '<S2>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S3>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_hk
                                        * Referenced by: '<S4>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S5>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_f3
                                        * Referenced by: '<S6>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_ix
                                        * Referenced by: '<S7>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S8>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_hd
                                        * Referenced by: '<S9>/Constant'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S1>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S2>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S3>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S4>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S5>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S6>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S7>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S8>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S9>/Gain'
                                        */
  0U,                                  /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S10>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S11>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S18>/S-Function'
                                        */
  2U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S19>/S-Function'
                                        */
  3U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S20>/S-Function'
                                        */
  4U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S21>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S22>/S-Function1'
                                        */
  2U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  6U                                   /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S25>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
