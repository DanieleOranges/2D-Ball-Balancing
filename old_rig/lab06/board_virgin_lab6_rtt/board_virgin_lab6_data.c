/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab6_data.c
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

#include "board_virgin_lab6.h"
#include "board_virgin_lab6_private.h"

/* Block parameters (auto storage) */
P_board_virgin_lab6_T board_virgin_lab6_P = {
  /*  Variable: Kx
   * Referenced by: '<S24>/x matrix gain'
   */
  { 36.68234289355761, 59.753829321339033, 0.94544400845155874 },
  31.493511726847981,                  /* Variable: Kxi
                                        * Referenced by: '<S24>/x integration gain'
                                        */

  /*  Variable: Ky
   * Referenced by: '<S25>/x matrix gain'
   */
  { 20.703361476284272, 33.724812278802013, -1.2044678714859387 },
  17.77480678730161,                   /* Variable: Kyi
                                        * Referenced by: '<S25>/x integration gain'
                                        */
  204.74999999999997,                  /* Variable: T1gain
                                        * Referenced by: '<S4>/gain motY'
                                        */
  2047.5000000000002,                  /* Variable: T1offset
                                        * Referenced by: '<S4>/Bias motY'
                                        */
  204.74999999999997,                  /* Variable: T2gain
                                        * Referenced by: '<S4>/gain motX'
                                        */
  2047.5000000000002,                  /* Variable: T2offset
                                        * Referenced by: '<S4>/Bias motX'
                                        */
  0.16565,                             /* Variable: V2theta_x
                                        * Referenced by: '<S24>/x integration gain1'
                                        */
  0.15936,                             /* Variable: V2theta_y
                                        * Referenced by: '<S25>/x integration gain1'
                                        */

  /*  Variable: Xtare_raw
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  { 870.0, 1250.0, 2036.0, 2836.0, 3410.0 },

  /*  Variable: Xtare_real
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  { -0.1275, -0.08, 0.0, 0.08, 0.1275 },

  /*  Variable: Ytare_raw
   * Referenced by: '<S4>/1-D Lookup Table1'
   */
  { 890.0, 1370.0, 2040.0, 2690.0, 3409.0 },

  /*  Variable: Ytare_real
   * Referenced by: '<S4>/1-D Lookup Table1'
   */
  { -0.0975, -0.05, 0.0, 0.05, 0.11 },

  /*  Variable: ref_2
   * Referenced by: '<S3>/Constant5'
   */
  { 0.0, 0.0 },

  /*  Variable: ref_3
   * Referenced by: '<S3>/Constant1'
   */
  { 0.08, 0.06 },
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S26>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_k
                                        * Referenced by: '<S27>/UD'
                                        */
  40U,                                 /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S15>/Digital Output1'
                                        */
  42U,                                 /* Mask Parameter: DigitalOutput1_pinNumber_h
                                        * Referenced by: '<S16>/Digital Output1'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S9>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S10>/Digital Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  2048.0,                              /* Expression: 2048
                                        * Referenced by: '<S20>/Constant'
                                        */
  2048.0,                              /* Expression: 2048
                                        * Referenced by: '<S21>/Constant'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Constant2'
   */
  { 0.0, 0.0 },
  100.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S26>/TSamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Delay'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S24>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Discrete-Time Integrator'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S27>/TSamp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S25>/Delay'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
  0.18,                                /* Computed Parameter: RateLimiter1_RisingLim
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  -0.18,                               /* Computed Parameter: RateLimiter1_FallingLim
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  0.01,                                /* Expression: sample_time
                                        * Referenced by: '<S19>/S-Function'
                                        */
  0U,                                  /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S11>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_d
                                        * Referenced by: '<S14>/S-Function'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S24>/Delay'
                                        */
  1U,                                  /* Computed Parameter: SFunction_p1_b
                                        * Referenced by: '<S12>/S-Function'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S25>/Delay'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_i
                                        * Referenced by: '<S13>/S-Function'
                                        */
  7U,                                  /* Computed Parameter: SFunction_p1_e
                                        * Referenced by: '<S17>/S-Function'
                                        */
  8U,                                  /* Computed Parameter: SFunction_p1_bw
                                        * Referenced by: '<S18>/S-Function'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_gs
                                        * Referenced by: '<S11>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S12>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S17>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_a2
                                        * Referenced by: '<S18>/Constant'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S11>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S12>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S17>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S18>/Gain'
                                        */
  6U,                                  /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S19>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S20>/S-Function'
                                        */
  0U,                                  /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S21>/S-Function'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_dn
                                        * Referenced by: '<Root>/Constant'
                                        */
  1                                    /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
