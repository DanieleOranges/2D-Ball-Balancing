/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab2_data.c
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

#include "board_virgin_lab2.h"
#include "board_virgin_lab2_private.h"

/* Block parameters (auto storage) */
P_board_virgin_lab2_T board_virgin_lab2_P = {
  1303.4789839226228,                  /* Variable: T1gain
                                        * Referenced by:
                                        *   '<S4>/gain motY'
                                        *   '<S4>/gain motY1'
                                        */
  2047.5000000000002,                  /* Variable: T1offset
                                        * Referenced by:
                                        *   '<S4>/Bias motY'
                                        *   '<S4>/Bias motY1'
                                        */
  1303.4789839226228,                  /* Variable: T2gain
                                        * Referenced by:
                                        *   '<S4>/gain motX'
                                        *   '<S4>/gain motX1'
                                        */
  2047.5000000000002,                  /* Variable: T2offset
                                        * Referenced by:
                                        *   '<S4>/Bias motX'
                                        *   '<S4>/Bias motX1'
                                        */
  -67623672,                           /* Variable: Xoffset
                                        * Referenced by: '<S4>/Bias X'
                                        */
  -45510853,                           /* Variable: Yoffset
                                        * Referenced by: '<S4>/Bias Y'
                                        */
  31519,                               /* Variable: Xgain
                                        * Referenced by: '<S4>/gain X'
                                        */
  21237,                               /* Variable: Ygain
                                        * Referenced by: '<S4>/gain Y'
                                        */
  2.5,                                 /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  2.5,                                 /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S2>/Derivative Gain'
                                        */
  1.5,                                 /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  1.5,                                 /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
  5.45,                                /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  5.45,                                /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S2>/Filter Coefficient'
                                        */
  3.0,                                 /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  3.0,                                 /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  40U,                                 /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S15>/Digital Output1'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S5>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S6>/Digital Output'
                                        */
  200,                                 /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  2048,                                /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  4095.0,                              /* Expression: 4095
                                        * Referenced by: '<S4>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  4095.0,                              /* Expression: 4095
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Bias'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  -0.01,                               /* Expression: -0.01
                                        * Referenced by: '<Root>/Bias1'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S2>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S2>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  0.01,                                /* Expression: sample_time
                                        * Referenced by: '<S19>/S-Function'
                                        */
  2048.0,                              /* Expression: 2048
                                        * Referenced by: '<S20>/Constant'
                                        */
  2048.0,                              /* Expression: 2048
                                        * Referenced by: '<S21>/Constant'
                                        */
  0U,                                  /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S7>/S-Function'
                                        */
  1U,                                  /* Computed Parameter: SFunction_p1_b
                                        * Referenced by: '<S9>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_i
                                        * Referenced by: '<S13>/S-Function'
                                        */
  6U,                                  /* Computed Parameter: SFunction_p1_e
                                        * Referenced by: '<S8>/S-Function'
                                        */
  3U,                                  /* Computed Parameter: SFunction_p1_a
                                        * Referenced by: '<S10>/S-Function'
                                        */
  7U,                                  /* Computed Parameter: SFunction_p1_es
                                        * Referenced by: '<S17>/S-Function'
                                        */
  8U,                                  /* Computed Parameter: SFunction_p1_bw
                                        * Referenced by: '<S18>/S-Function'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S7>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S9>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S8>/Constant'
                                        */
  4095,                                /* Computed Parameter: Constant_Value_n3
                                        * Referenced by: '<S10>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S17>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_a2
                                        * Referenced by: '<S18>/Constant'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S7>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S9>/Gain'
                                        */
  -32768,                              /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S10>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S8>/Gain'
                                        */
  16384,                               /* Computed Parameter: Gain_Gain_pu
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
  0U                                   /* Expression: uint8(DAC_pin)
                                        * Referenced by: '<S21>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
