/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab6.c
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

const boolean_T board_virgin_lab6_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_board_virgin_lab6_T board_virgin_lab6_B;

/* Block states (auto storage) */
DW_board_virgin_lab6_T board_virgin_lab6_DW;

/* Real-time model */
RT_MODEL_board_virgin_lab6_T board_virgin_lab6_M_;
RT_MODEL_board_virgin_lab6_T *const board_virgin_lab6_M = &board_virgin_lab6_M_;
static void rate_monotonic_scheduler(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (board_virgin_lab6_M->Timing.TaskCounters.TID[1])++;
  if ((board_virgin_lab6_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    board_virgin_lab6_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
void board_virgin_lab6_output0(void)   /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model update function for TID0 */
void board_virgin_lab6_update0(void)   /* Sample time: [0.001s, 0.0s] */
{
  /* (no update code required) */
}

/* Model output function for TID1 */
void board_virgin_lab6_output1(void)   /* Sample time: [0.01s, 0.0s] */
{
  uint16_T rtb_SFunction_0;
  uint16_T rtb_SFunction_1;
  int16_T rtb_Sum;
  real_T rtb_int_x;
  real_T rtb_Switch;
  real_T rtb_RateLimiter1;
  real_T rtb_RateLimiter1_idx_0;
  real_T rtb_RateLimiter1_idx_1;
  uint8_T tmp;

  /* S-Function (arduinoanaloginput_sfcn): '<S11>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab6_P.SFunction_p1);

  /* Lookup_n-D: '<S4>/1-D Lookup Table' incorporates:
   *  Constant: '<S11>/Constant'
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   *  DataTypeConversion: '<S4>/Data Type Conversion7'
   *  Gain: '<S11>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S11>/S-Function'
   *  Sum: '<S11>/Sum'
   */
  rtb_int_x = look1_binlxpw((int16_T)((int16_T)(board_virgin_lab6_P.Gain_Gain *
    (int16_T)rtb_SFunction_0 >> 15) + board_virgin_lab6_P.Constant_Value_gs),
    board_virgin_lab6_P.Xtare_raw, board_virgin_lab6_P.Xtare_real, 4U);

  /* SampleTimeMath: '<S26>/TSamp'
   *
   * About '<S26>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  board_virgin_lab6_B.TSamp = rtb_int_x * board_virgin_lab6_P.TSamp_WtEt;

  /* S-Function (arduinodigitalinput_sfcn): '<S14>/S-Function' */
  board_virgin_lab6_B.SFunction = MW_digitalRead
    (board_virgin_lab6_P.SFunction_p1_d);

  /* Switch: '<S3>/Switch3' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant5'
   */
  if (board_virgin_lab6_B.SFunction) {
    rtb_RateLimiter1_idx_0 = board_virgin_lab6_P.ref_3[0];
    rtb_RateLimiter1_idx_1 = board_virgin_lab6_P.ref_3[1];
  } else {
    rtb_RateLimiter1_idx_0 = board_virgin_lab6_P.ref_2[0];
    rtb_RateLimiter1_idx_1 = board_virgin_lab6_P.ref_2[1];
  }

  /* End of Switch: '<S3>/Switch3' */

  /* Sum: '<S6>/Sum2' */
  board_virgin_lab6_B.Sum2 = rtb_RateLimiter1_idx_0 - rtb_int_x;

  /* Sum: '<S24>/Sum1' incorporates:
   *  Delay: '<S24>/Delay'
   *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator'
   *  Gain: '<S24>/x integration gain'
   *  Gain: '<S24>/x integration gain1'
   *  Gain: '<S24>/x matrix gain'
   *  SignalConversion: '<S24>/TmpSignal ConversionAtx matrix gainInport1'
   *  Sum: '<S26>/Diff'
   *  UnaryMinus: '<S24>/xvel minus'
   *  UnitDelay: '<S26>/UD'
   */
  board_virgin_lab6_B.Sum1 = ((-(board_virgin_lab6_B.TSamp -
    board_virgin_lab6_DW.UD_DSTATE) * board_virgin_lab6_P.Kx[0] +
    board_virgin_lab6_P.Kx[1] * board_virgin_lab6_B.Sum2) +
    -board_virgin_lab6_P.V2theta_x * board_virgin_lab6_DW.Delay_DSTATE *
    board_virgin_lab6_P.Kx[2]) + board_virgin_lab6_P.Kxi *
    board_virgin_lab6_DW.DiscreteTimeIntegrator_DSTATE;

  /* S-Function (arduinoanaloginput_sfcn): '<S12>/S-Function' */
  rtb_SFunction_1 = MW_analogRead(board_virgin_lab6_P.SFunction_p1_b);

  /* Sum: '<S12>/Sum' incorporates:
   *  Constant: '<S12>/Constant'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  Gain: '<S12>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S12>/S-Function'
   */
  rtb_Sum = (int16_T)((int16_T)(board_virgin_lab6_P.Gain_Gain_n * (int16_T)
    rtb_SFunction_1 >> 15) + board_virgin_lab6_P.Constant_Value_c);

  /* Lookup_n-D: '<S4>/1-D Lookup Table1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion8'
   */
  rtb_int_x = look1_binlxpw(rtb_Sum, board_virgin_lab6_P.Ytare_raw,
    board_virgin_lab6_P.Ytare_real, 4U);

  /* SampleTimeMath: '<S27>/TSamp'
   *
   * About '<S27>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  board_virgin_lab6_B.TSamp_n = rtb_int_x * board_virgin_lab6_P.TSamp_WtEt_b;

  /* Sum: '<S6>/Sum3' */
  board_virgin_lab6_B.Sum3 = rtb_RateLimiter1_idx_1 - rtb_int_x;

  /* Sum: '<S25>/Sum1' incorporates:
   *  Delay: '<S25>/Delay'
   *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
   *  Gain: '<S25>/x integration gain'
   *  Gain: '<S25>/x integration gain1'
   *  Gain: '<S25>/x matrix gain'
   *  SignalConversion: '<S25>/TmpSignal ConversionAtx matrix gainInport1'
   *  Sum: '<S27>/Diff'
   *  UnaryMinus: '<S25>/xvel minus'
   *  UnitDelay: '<S27>/UD'
   */
  board_virgin_lab6_B.Sum1_k = ((-(board_virgin_lab6_B.TSamp_n -
    board_virgin_lab6_DW.UD_DSTATE_f) * board_virgin_lab6_P.Ky[0] +
    board_virgin_lab6_P.Ky[1] * board_virgin_lab6_B.Sum3) +
    -board_virgin_lab6_P.V2theta_y * board_virgin_lab6_DW.Delay_DSTATE_d *
    board_virgin_lab6_P.Ky[2]) + board_virgin_lab6_P.Kyi *
    board_virgin_lab6_DW.DiscreteTimeIntegrator_DSTATE_g;

  /* S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function' */
  board_virgin_lab6_B.SFunction_o = MW_digitalRead
    (board_virgin_lab6_P.SFunction_p1_i);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (board_virgin_lab6_B.SFunction_o) {
    rtb_RateLimiter1_idx_0 = board_virgin_lab6_B.Sum1;
    rtb_RateLimiter1_idx_1 = board_virgin_lab6_B.Sum1_k;
  } else {
    rtb_RateLimiter1_idx_0 = board_virgin_lab6_P.Constant2_Value[0];
    rtb_RateLimiter1_idx_1 = board_virgin_lab6_P.Constant2_Value[1];
  }

  /* End of Switch: '<Root>/Switch' */

  /* RateLimiter: '<Root>/Rate Limiter1' */
  rtb_Switch = rtb_RateLimiter1_idx_0 - board_virgin_lab6_DW.PrevY[0];
  rtb_int_x = rtb_RateLimiter1_idx_1 - board_virgin_lab6_DW.PrevY[1];
  rtb_RateLimiter1 = rtb_RateLimiter1_idx_0;
  if (rtb_Switch > board_virgin_lab6_P.RateLimiter1_RisingLim) {
    rtb_RateLimiter1 = board_virgin_lab6_DW.PrevY[0] +
      board_virgin_lab6_P.RateLimiter1_RisingLim;
  } else {
    if (rtb_Switch < board_virgin_lab6_P.RateLimiter1_FallingLim) {
      rtb_RateLimiter1 = board_virgin_lab6_DW.PrevY[0] +
        board_virgin_lab6_P.RateLimiter1_FallingLim;
    }
  }

  rtb_RateLimiter1_idx_0 = rtb_RateLimiter1;
  rtb_RateLimiter1 = rtb_RateLimiter1_idx_1;
  if (rtb_int_x > board_virgin_lab6_P.RateLimiter1_RisingLim) {
    rtb_RateLimiter1 = board_virgin_lab6_DW.PrevY[1] +
      board_virgin_lab6_P.RateLimiter1_RisingLim;
  } else {
    if (rtb_int_x < board_virgin_lab6_P.RateLimiter1_FallingLim) {
      rtb_RateLimiter1 = board_virgin_lab6_DW.PrevY[1] +
        board_virgin_lab6_P.RateLimiter1_FallingLim;
    }
  }

  board_virgin_lab6_DW.PrevY[0] = rtb_RateLimiter1_idx_0;
  board_virgin_lab6_DW.PrevY[1] = rtb_RateLimiter1;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* S-Function (signals): '<S2>/S-Function2' */
  signals_Outputs_wrapper( &board_virgin_lab6_B.SFunction2_o1,
    &board_virgin_lab6_B.SFunction2_o2, &board_virgin_lab6_DW.SFunction2_DSTATE);

  /* DataTypeConversion: '<S4>/Data Type Conversion4' incorporates:
   *  Constant: '<S11>/Constant'
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   *  Gain: '<S11>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S11>/S-Function'
   *  Sum: '<S11>/Sum'
   */
  board_virgin_lab6_B.DataTypeConversion4 = (int16_T)((int16_T)
    (board_virgin_lab6_P.Gain_Gain * (int16_T)rtb_SFunction_0 >> 15) +
    board_virgin_lab6_P.Constant_Value_gs);

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion8'
   */
  board_virgin_lab6_B.DataTypeConversion1 = rtb_Sum;

  /* S-Function (arduinoanaloginput_sfcn): '<S17>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab6_P.SFunction_p1_e);

  /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
   *  Constant: '<S17>/Constant'
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   *  Gain: '<S17>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S17>/S-Function'
   *  Sum: '<S17>/Sum'
   */
  board_virgin_lab6_B.DataTypeConversion2 = (int16_T)((int16_T)
    (board_virgin_lab6_P.Gain_Gain_p * (int16_T)rtb_SFunction_0 >> 14) +
    board_virgin_lab6_P.Constant_Value_a);

  /* S-Function (arduinoanaloginput_sfcn): '<S18>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab6_P.SFunction_p1_bw);

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  Gain: '<S18>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S18>/S-Function'
   *  Sum: '<S18>/Sum'
   */
  board_virgin_lab6_B.DataTypeConversion3 = (int16_T)((int16_T)
    (board_virgin_lab6_P.Gain_Gain_m * (int16_T)rtb_SFunction_0 >> 14) +
    board_virgin_lab6_P.Constant_Value_a2);

  /* Bias: '<S4>/Bias motX' incorporates:
   *  Gain: '<S4>/gain motX'
   */
  rtb_int_x = board_virgin_lab6_P.T2gain * rtb_RateLimiter1_idx_0 +
    board_virgin_lab6_P.T2offset;

  /* DataTypeConversion: '<S19>/conversion6' */
  board_virgin_lab6_B.conversion6 = (real32_T)rtb_int_x;

  /* Bias: '<S4>/Bias motY' incorporates:
   *  Gain: '<S4>/gain motY'
   */
  rtb_Switch = board_virgin_lab6_P.T1gain * rtb_RateLimiter1 +
    board_virgin_lab6_P.T1offset;

  /* DataTypeConversion: '<S19>/conversion7' */
  board_virgin_lab6_B.conversion7 = (real32_T)rtb_Switch;

  /* S-Function (SerialTx): '<S19>/S-Function' */
  SerialTx_Outputs_wrapper(&board_virgin_lab6_B.SFunction2_o1, (boolean_T*)
    &board_virgin_lab6_BGND, (boolean_T*)&board_virgin_lab6_BGND, (boolean_T*)
    &board_virgin_lab6_BGND, &board_virgin_lab6_B.SFunction_o,
    &board_virgin_lab6_B.SFunction, &board_virgin_lab6_P.Constant_Value_dn,
    &board_virgin_lab6_P.Constant1_Value,
    &board_virgin_lab6_B.DataTypeConversion4,
    &board_virgin_lab6_B.DataTypeConversion1,
    &board_virgin_lab6_B.DataTypeConversion2,
    &board_virgin_lab6_B.DataTypeConversion3, &board_virgin_lab6_B.conversion6,
    &board_virgin_lab6_B.conversion7, &board_virgin_lab6_DW.SFunction_DSTATE,
    &board_virgin_lab6_P.SFunction_P1, 1, &board_virgin_lab6_P.SFunction_P2, 1);

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Constant'
   */
  if (!board_virgin_lab6_B.SFunction2_o1) {
    rtb_Switch = board_virgin_lab6_P.Constant_Value_d;
  }

  /* End of Switch: '<S20>/Switch' */

  /* DataTypeConversion: '<S20>/Data Type Conversion' */
  if (rtb_Switch < 65536.0) {
    if (rtb_Switch >= 0.0) {
      board_virgin_lab6_B.DataTypeConversion = (uint16_T)rtb_Switch;
    } else {
      board_virgin_lab6_B.DataTypeConversion = 0U;
    }
  } else {
    board_virgin_lab6_B.DataTypeConversion = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S20>/Data Type Conversion' */

  /* S-Function (sfcn_DAC): '<S20>/S-Function' */
  sfcn_DAC_Outputs_wrapper(&board_virgin_lab6_B.DataTypeConversion,
    &board_virgin_lab6_DW.SFunction_DSTATE_l,
    &board_virgin_lab6_P.SFunction_P1_d, 1);

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant'
   */
  if (!board_virgin_lab6_B.SFunction2_o1) {
    rtb_int_x = board_virgin_lab6_P.Constant_Value_o;
  }

  /* End of Switch: '<S21>/Switch' */

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  if (rtb_int_x < 65536.0) {
    if (rtb_int_x >= 0.0) {
      board_virgin_lab6_B.DataTypeConversion_a = (uint16_T)rtb_int_x;
    } else {
      board_virgin_lab6_B.DataTypeConversion_a = 0U;
    }
  } else {
    board_virgin_lab6_B.DataTypeConversion_a = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S21>/Data Type Conversion' */

  /* S-Function (sfcn_DAC): '<S21>/S-Function' */
  sfcn_DAC_Outputs_wrapper(&board_virgin_lab6_B.DataTypeConversion_a,
    &board_virgin_lab6_DW.SFunction_DSTATE_m,
    &board_virgin_lab6_P.SFunction_P1_p, 1);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   */
  if (board_virgin_lab6_B.SFunction2_o1) {
    rtb_Switch = board_virgin_lab6_B.SFunction_o;
  } else {
    rtb_Switch = board_virgin_lab6_P.Constant_Value;
  }

  /* End of Switch: '<S15>/Switch' */

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      tmp = (uint8_T)rtb_Switch;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output1' */
  MW_digitalWrite(board_virgin_lab6_P.DigitalOutput1_pinNumber, tmp);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (board_virgin_lab6_B.SFunction2_o1) {
    rtb_Switch = board_virgin_lab6_B.SFunction;
  } else {
    rtb_Switch = board_virgin_lab6_P.Constant_Value_g;
  }

  /* End of Switch: '<S16>/Switch' */

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      tmp = (uint8_T)rtb_Switch;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S16>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S16>/Digital Output1' */
  MW_digitalWrite(board_virgin_lab6_P.DigitalOutput1_pinNumber_h, tmp);

  /* S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   */
  MW_digitalWrite(board_virgin_lab6_P.DigitalOutput_pinNumber, (uint8_T)
                  board_virgin_lab6_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   */
  MW_digitalWrite(board_virgin_lab6_P.DigitalOutput_pinNumber_f, (uint8_T)
                  board_virgin_lab6_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S2>/S-Function1' */
  data_struct_init_Outputs_wrapper( &board_virgin_lab6_DW.SFunction1_DSTATE);
}

/* Model update function for TID1 */
void board_virgin_lab6_update1(void)   /* Sample time: [0.01s, 0.0s] */
{
  /* Update for UnitDelay: '<S26>/UD' */
  board_virgin_lab6_DW.UD_DSTATE = board_virgin_lab6_B.TSamp;

  /* Update for Delay: '<S24>/Delay' */
  board_virgin_lab6_DW.Delay_DSTATE = board_virgin_lab6_B.Sum1;

  /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
  board_virgin_lab6_DW.DiscreteTimeIntegrator_DSTATE +=
    board_virgin_lab6_P.DiscreteTimeIntegrator_gainval *
    board_virgin_lab6_B.Sum2;

  /* Update for UnitDelay: '<S27>/UD' */
  board_virgin_lab6_DW.UD_DSTATE_f = board_virgin_lab6_B.TSamp_n;

  /* Update for Delay: '<S25>/Delay' */
  board_virgin_lab6_DW.Delay_DSTATE_d = board_virgin_lab6_B.Sum1_k;

  /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  board_virgin_lab6_DW.DiscreteTimeIntegrator_DSTATE_g +=
    board_virgin_lab6_P.DiscreteTimeIntegrator_gainva_p *
    board_virgin_lab6_B.Sum3;

  /* S-Function "signals_wrapper" Block: <S2>/S-Function2 */
  signals_Update_wrapper( &board_virgin_lab6_B.SFunction2_o1,
    &board_virgin_lab6_B.SFunction2_o2, &board_virgin_lab6_DW.SFunction2_DSTATE);

  /* S-Function "SerialTx_wrapper" Block: <S19>/S-Function */
  SerialTx_Update_wrapper(&board_virgin_lab6_B.SFunction2_o1, (boolean_T*)
    &board_virgin_lab6_BGND, (boolean_T*)&board_virgin_lab6_BGND, (boolean_T*)
    &board_virgin_lab6_BGND, &board_virgin_lab6_B.SFunction_o,
    &board_virgin_lab6_B.SFunction, &board_virgin_lab6_P.Constant_Value_dn,
    &board_virgin_lab6_P.Constant1_Value,
    &board_virgin_lab6_B.DataTypeConversion4,
    &board_virgin_lab6_B.DataTypeConversion1,
    &board_virgin_lab6_B.DataTypeConversion2,
    &board_virgin_lab6_B.DataTypeConversion3, &board_virgin_lab6_B.conversion6,
    &board_virgin_lab6_B.conversion7, &board_virgin_lab6_DW.SFunction_DSTATE,
    &board_virgin_lab6_P.SFunction_P1, 1, &board_virgin_lab6_P.SFunction_P2, 1);

  /* S-Function "sfcn_DAC_wrapper" Block: <S20>/S-Function */
  sfcn_DAC_Update_wrapper(&board_virgin_lab6_B.DataTypeConversion,
    &board_virgin_lab6_DW.SFunction_DSTATE_l,
    &board_virgin_lab6_P.SFunction_P1_d, 1);

  /* S-Function "sfcn_DAC_wrapper" Block: <S21>/S-Function */
  sfcn_DAC_Update_wrapper(&board_virgin_lab6_B.DataTypeConversion_a,
    &board_virgin_lab6_DW.SFunction_DSTATE_m,
    &board_virgin_lab6_P.SFunction_P1_p, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S2>/S-Function1 */
  data_struct_init_Update_wrapper(&board_virgin_lab6_DW.SFunction1_DSTATE);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  board_virgin_lab6_M->Timing.clockTick1++;
}

/* Model initialize function */
void board_virgin_lab6_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)board_virgin_lab6_M, 0,
                sizeof(RT_MODEL_board_virgin_lab6_T));

  /* block I/O */
  (void) memset(((void *) &board_virgin_lab6_B), 0,
                sizeof(B_board_virgin_lab6_T));

  /* states (dwork) */
  (void) memset((void *)&board_virgin_lab6_DW, 0,
                sizeof(DW_board_virgin_lab6_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S11>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab6_P.SFunction_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S14>/S-Function' */
  MW_pinModeInput(board_virgin_lab6_P.SFunction_p1_d);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S12>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab6_P.SFunction_p1_b);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function' */
  MW_pinModeInput(board_virgin_lab6_P.SFunction_p1_i);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S17>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab6_P.SFunction_p1_e);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S18>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab6_P.SFunction_p1_bw);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output1' */
  MW_pinModeOutput(board_virgin_lab6_P.DigitalOutput1_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S16>/Digital Output1' */
  MW_pinModeOutput(board_virgin_lab6_P.DigitalOutput1_pinNumber_h);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output' */
  MW_pinModeOutput(board_virgin_lab6_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output' */
  MW_pinModeOutput(board_virgin_lab6_P.DigitalOutput_pinNumber_f);

  /* InitializeConditions for UnitDelay: '<S26>/UD' */
  board_virgin_lab6_DW.UD_DSTATE =
    board_virgin_lab6_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Delay: '<S24>/Delay' */
  board_virgin_lab6_DW.Delay_DSTATE = board_virgin_lab6_P.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
  board_virgin_lab6_DW.DiscreteTimeIntegrator_DSTATE =
    board_virgin_lab6_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S27>/UD' */
  board_virgin_lab6_DW.UD_DSTATE_f =
    board_virgin_lab6_P.DiscreteDerivative_ICPrevScal_k;

  /* InitializeConditions for Delay: '<S25>/Delay' */
  board_virgin_lab6_DW.Delay_DSTATE_d =
    board_virgin_lab6_P.Delay_InitialCondition_j;

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  board_virgin_lab6_DW.DiscreteTimeIntegrator_DSTATE_g =
    board_virgin_lab6_P.DiscreteTimeIntegrator_IC_b;

  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter1' */
  board_virgin_lab6_DW.PrevY[0] = board_virgin_lab6_P.RateLimiter1_IC;
  board_virgin_lab6_DW.PrevY[1] = board_virgin_lab6_P.RateLimiter1_IC;

  /* S-Function Block: <S2>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab6_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S19>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab6_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S20>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab6_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* S-Function Block: <S21>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab6_DW.SFunction_DSTATE_m = initVector[0];
      }
    }
  }

  /* S-Function Block: <S2>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab6_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void board_virgin_lab6_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
