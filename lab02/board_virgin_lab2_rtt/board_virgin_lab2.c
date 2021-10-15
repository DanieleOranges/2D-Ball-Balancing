/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab2.c
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

const boolean_T board_virgin_lab2_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_board_virgin_lab2_T board_virgin_lab2_B;

/* Continuous states */
X_board_virgin_lab2_T board_virgin_lab2_X;

/* Block states (auto storage) */
DW_board_virgin_lab2_T board_virgin_lab2_DW;

/* Real-time model */
RT_MODEL_board_virgin_lab2_T board_virgin_lab2_M_;
RT_MODEL_board_virgin_lab2_T *const board_virgin_lab2_M = &board_virgin_lab2_M_;
static void rate_monotonic_scheduler(void);

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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 2 */
  board_virgin_lab2_M->Timing.RateInteraction.TID0_2 =
    (board_virgin_lab2_M->Timing.TaskCounters.TID[2] == 0);

  /* tid 1 shares data with slower tid rate: 2 */
  if (board_virgin_lab2_M->Timing.TaskCounters.TID[1] == 0) {
    board_virgin_lab2_M->Timing.RateInteraction.TID1_2 =
      (board_virgin_lab2_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (board_virgin_lab2_M->Timing.TaskCounters.TID[2])++;
  if ((board_virgin_lab2_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    board_virgin_lab2_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  board_virgin_lab2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  board_virgin_lab2_output0();
  board_virgin_lab2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  board_virgin_lab2_output0();
  board_virgin_lab2_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void board_virgin_lab2_output0(void)   /* Sample time: [0.0s, 0.0s] */
{
  uint16_T rtb_SFunction_0;
  int16_T rtb_Sum_a;
  real_T rtb_Filter;
  real_T rtb_Switch;
  int16_T rtb_Sum_b;
  boolean_T rtb_LogicalOperator;
  real_T rtb_Switch3[2];
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&board_virgin_lab2_M->solverInfo,
                          ((board_virgin_lab2_M->Timing.clockTick0+1)*
      board_virgin_lab2_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(board_virgin_lab2_M)) {
    board_virgin_lab2_M->Timing.t[0] = rtsiGetT(&board_virgin_lab2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* Bias: '<Root>/Bias' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    board_virgin_lab2_B.Bias = board_virgin_lab2_P.Constant1_Value +
      board_virgin_lab2_P.Bias_Bias;

    /* Bias: '<Root>/Bias1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    board_virgin_lab2_B.Bias1 = board_virgin_lab2_P.Constant_Value +
      board_virgin_lab2_P.Bias1_Bias;
  }

  /* S-Function (arduinoanaloginput_sfcn): '<S7>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab2_P.SFunction_p1);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  S-Function (arduinoanaloginput_sfcn): '<S7>/S-Function'
   */
  rtb_Sum_a = (int16_T)rtb_SFunction_0;
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* Constant: '<S7>/Constant' */
    board_virgin_lab2_B.Constant_n = board_virgin_lab2_P.Constant_Value_g;
  }

  /* Sum: '<S7>/Sum' incorporates:
   *  Gain: '<S7>/Gain'
   */
  rtb_Sum_a = (int16_T)((int16_T)(board_virgin_lab2_P.Gain_Gain * rtb_Sum_a >>
    15) + board_virgin_lab2_B.Constant_n);

  /* Sum: '<Root>/Sum' incorporates:
   *  Bias: '<S4>/Bias X'
   *  Gain: '<S4>/gain X'
   */
  rtb_Filter = board_virgin_lab2_B.Bias - (real_T)(board_virgin_lab2_P.Xgain *
    rtb_Sum_a + board_virgin_lab2_P.Xoffset) * 3.7252902984619141E-9;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  board_virgin_lab2_B.FilterCoefficient = (board_virgin_lab2_P.PIDController_D *
    rtb_Filter - board_virgin_lab2_X.Filter_CSTATE) *
    board_virgin_lab2_P.PIDController_N;

  /* Gain: '<S1>/Integral Gain' */
  board_virgin_lab2_B.IntegralGain = board_virgin_lab2_P.PIDController_I *
    rtb_Filter;

  /* S-Function (arduinoanaloginput_sfcn): '<S9>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab2_P.SFunction_p1_b);

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  S-Function (arduinoanaloginput_sfcn): '<S9>/S-Function'
   */
  rtb_Sum_b = (int16_T)rtb_SFunction_0;
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* Constant: '<S9>/Constant' */
    board_virgin_lab2_B.Constant_e = board_virgin_lab2_P.Constant_Value_c;
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/Gain'
   */
  rtb_Sum_b = (int16_T)((int16_T)(board_virgin_lab2_P.Gain_Gain_n * rtb_Sum_b >>
    15) + board_virgin_lab2_B.Constant_e);

  /* Sum: '<Root>/Sum1' incorporates:
   *  Bias: '<S4>/Bias Y'
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   *  Gain: '<S4>/gain Y'
   */
  rtb_Switch = board_virgin_lab2_B.Bias1 - (real_T)(board_virgin_lab2_P.Ygain *
    rtb_Sum_b + board_virgin_lab2_P.Yoffset) * 3.7252902984619141E-9;

  /* Gain: '<S2>/Filter Coefficient' incorporates:
   *  Gain: '<S2>/Derivative Gain'
   *  Integrator: '<S2>/Filter'
   *  Sum: '<S2>/SumD'
   */
  board_virgin_lab2_B.FilterCoefficient_p =
    (board_virgin_lab2_P.PIDController1_D * rtb_Switch -
     board_virgin_lab2_X.Filter_CSTATE_c) * board_virgin_lab2_P.PIDController1_N;

  /* Gain: '<S2>/Integral Gain' */
  board_virgin_lab2_B.IntegralGain_h = board_virgin_lab2_P.PIDController1_I *
    rtb_Switch;

  /* S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function' */
  rtb_LogicalOperator = MW_digitalRead(board_virgin_lab2_P.SFunction_p1_i);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function'
   */
  rtb_LogicalOperator = !rtb_LogicalOperator;

  /* S-Function (signals): '<S3>/S-Function2' */
  signals_Outputs_wrapper( &board_virgin_lab2_B.SFunction2_o1,
    &board_virgin_lab2_B.SFunction2_o2, &board_virgin_lab2_DW.SFunction2_DSTATE);
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* Constant: '<S15>/Constant' */
    board_virgin_lab2_B.Constant = board_virgin_lab2_P.Constant_Value_f;
  }

  /* Switch: '<S15>/Switch' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   */
  if (board_virgin_lab2_B.SFunction2_o1) {
    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    board_virgin_lab2_B.DataTypeConversion_l = rtb_LogicalOperator;
  } else if (board_virgin_lab2_B.Constant < 256.0) {
    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    if (board_virgin_lab2_B.Constant >= 0.0) {
      board_virgin_lab2_B.DataTypeConversion_l = (uint8_T)
        board_virgin_lab2_B.Constant;
    } else {
      board_virgin_lab2_B.DataTypeConversion_l = 0U;
    }
  } else {
    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    board_virgin_lab2_B.DataTypeConversion_l = MAX_uint8_T;
  }

  /* End of Switch: '<S15>/Switch' */
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output1' */
    MW_digitalWrite(board_virgin_lab2_P.DigitalOutput1_pinNumber,
                    board_virgin_lab2_B.DataTypeConversion_l);
  }

  /* RateTransition: '<S19>/Rate Transition' */
  if (rtmIsMajorTimeStep(board_virgin_lab2_M) &&
      board_virgin_lab2_M->Timing.RateInteraction.TID0_2) {
    board_virgin_lab2_B.RateTransition = board_virgin_lab2_B.SFunction2_o1;
  }

  /* End of RateTransition: '<S19>/Rate Transition' */

  /* RateTransition: '<S19>/Rate Transition1' incorporates:
   *  RateTransition: '<S19>/Rate Transition2'
   */
  if (rtmIsMajorTimeStep(board_virgin_lab2_M) &&
      board_virgin_lab2_M->Timing.RateInteraction.TID1_2) {
    board_virgin_lab2_B.RateTransition1 = 0.0;
    board_virgin_lab2_B.RateTransition2 = 0.0;
  }

  /* End of RateTransition: '<S19>/Rate Transition1' */

  /* RateTransition: '<S19>/Rate Transition5' */
  if (rtmIsMajorTimeStep(board_virgin_lab2_M) &&
      board_virgin_lab2_M->Timing.RateInteraction.TID0_2) {
    board_virgin_lab2_B.RateTransition5 = rtb_Sum_a;

    /* RateTransition: '<S19>/Rate Transition6' */
    board_virgin_lab2_B.RateTransition6 = rtb_Sum_b;
  }

  /* End of RateTransition: '<S19>/Rate Transition5' */
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* Bias: '<S4>/Bias motX1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Gain: '<S4>/gain motX1'
     */
    board_virgin_lab2_B.BiasmotX1 = board_virgin_lab2_P.T2gain *
      board_virgin_lab2_P.Constant1_Value_a + board_virgin_lab2_P.T2offset;

    /* Bias: '<S4>/Bias motY1' incorporates:
     *  Constant: '<S4>/Constant2'
     *  Gain: '<S4>/gain motY1'
     */
    board_virgin_lab2_B.BiasmotY1 = board_virgin_lab2_P.T1gain *
      board_virgin_lab2_P.Constant2_Value + board_virgin_lab2_P.T1offset;
  }

  /* Switch: '<S4>/Switch3' */
  if (rtb_LogicalOperator) {
    rtb_Switch3[0] = board_virgin_lab2_B.BiasmotX1;
    rtb_Switch3[1] = board_virgin_lab2_B.BiasmotY1;
  } else {
    /* Bias: '<S4>/Bias motX' incorporates:
     *  Gain: '<S1>/Proportional Gain'
     *  Gain: '<S4>/gain motX'
     *  Integrator: '<S1>/Integrator'
     *  Sum: '<S1>/Sum'
     */
    rtb_Filter = ((board_virgin_lab2_P.PIDController_P * rtb_Filter +
                   board_virgin_lab2_X.Integrator_CSTATE) +
                  board_virgin_lab2_B.FilterCoefficient) *
      board_virgin_lab2_P.T2gain + board_virgin_lab2_P.T2offset;

    /* Saturate: '<S4>/Saturation' */
    if (rtb_Filter > board_virgin_lab2_P.Saturation_UpperSat) {
      rtb_Switch3[0] = board_virgin_lab2_P.Saturation_UpperSat;
    } else if (rtb_Filter < board_virgin_lab2_P.Saturation_LowerSat) {
      rtb_Switch3[0] = board_virgin_lab2_P.Saturation_LowerSat;
    } else {
      rtb_Switch3[0] = rtb_Filter;
    }

    /* End of Saturate: '<S4>/Saturation' */

    /* Bias: '<S4>/Bias motY' incorporates:
     *  Gain: '<S2>/Proportional Gain'
     *  Gain: '<S4>/gain motY'
     *  Integrator: '<S2>/Integrator'
     *  Sum: '<S2>/Sum'
     */
    rtb_Filter = ((board_virgin_lab2_P.PIDController1_P * rtb_Switch +
                   board_virgin_lab2_X.Integrator_CSTATE_m) +
                  board_virgin_lab2_B.FilterCoefficient_p) *
      board_virgin_lab2_P.T1gain + board_virgin_lab2_P.T1offset;

    /* Saturate: '<S4>/Saturation2' */
    if (rtb_Filter > board_virgin_lab2_P.Saturation2_UpperSat) {
      rtb_Switch3[1] = board_virgin_lab2_P.Saturation2_UpperSat;
    } else if (rtb_Filter < board_virgin_lab2_P.Saturation2_LowerSat) {
      rtb_Switch3[1] = board_virgin_lab2_P.Saturation2_LowerSat;
    } else {
      rtb_Switch3[1] = rtb_Filter;
    }

    /* End of Saturate: '<S4>/Saturation2' */
  }

  /* End of Switch: '<S4>/Switch3' */

  /* RateTransition: '<S19>/Rate Transition10' */
  if (rtmIsMajorTimeStep(board_virgin_lab2_M) &&
      board_virgin_lab2_M->Timing.RateInteraction.TID0_2) {
    board_virgin_lab2_B.RateTransition10 = rtb_Switch3[0];
  }

  /* End of RateTransition: '<S19>/Rate Transition10' */
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* Constant: '<S20>/Constant' */
    board_virgin_lab2_B.Constant_c = board_virgin_lab2_P.Constant_Value_d;
  }

  /* Switch: '<S20>/Switch' incorporates:
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   */
  if (board_virgin_lab2_B.SFunction2_o1) {
    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    if (rtb_Switch3[1] < 65536.0) {
      if (rtb_Switch3[1] >= 0.0) {
        board_virgin_lab2_B.DataTypeConversion = (uint16_T)rtb_Switch3[1];
      } else {
        board_virgin_lab2_B.DataTypeConversion = 0U;
      }
    } else {
      board_virgin_lab2_B.DataTypeConversion = MAX_uint16_T;
    }
  } else if (board_virgin_lab2_B.Constant_c < 65536.0) {
    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    if (board_virgin_lab2_B.Constant_c >= 0.0) {
      board_virgin_lab2_B.DataTypeConversion = (uint16_T)
        board_virgin_lab2_B.Constant_c;
    } else {
      board_virgin_lab2_B.DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    board_virgin_lab2_B.DataTypeConversion = MAX_uint16_T;
  }

  /* End of Switch: '<S20>/Switch' */

  /* S-Function (sfcn_DAC): '<S20>/S-Function' */
  sfcn_DAC_Outputs_wrapper(&board_virgin_lab2_B.DataTypeConversion,
    &board_virgin_lab2_DW.SFunction_DSTATE_l,
    &board_virgin_lab2_P.SFunction_P1_d, 1);
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* Constant: '<S21>/Constant' */
    board_virgin_lab2_B.Constant_d = board_virgin_lab2_P.Constant_Value_o;
  }

  /* Switch: '<S21>/Switch' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   */
  if (board_virgin_lab2_B.SFunction2_o1) {
    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    if (rtb_Switch3[0] < 65536.0) {
      if (rtb_Switch3[0] >= 0.0) {
        board_virgin_lab2_B.DataTypeConversion_a = (uint16_T)rtb_Switch3[0];
      } else {
        board_virgin_lab2_B.DataTypeConversion_a = 0U;
      }
    } else {
      board_virgin_lab2_B.DataTypeConversion_a = MAX_uint16_T;
    }
  } else if (board_virgin_lab2_B.Constant_d < 65536.0) {
    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    if (board_virgin_lab2_B.Constant_d >= 0.0) {
      board_virgin_lab2_B.DataTypeConversion_a = (uint16_T)
        board_virgin_lab2_B.Constant_d;
    } else {
      board_virgin_lab2_B.DataTypeConversion_a = 0U;
    }
  } else {
    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    board_virgin_lab2_B.DataTypeConversion_a = MAX_uint16_T;
  }

  /* End of Switch: '<S21>/Switch' */

  /* S-Function (sfcn_DAC): '<S21>/S-Function' */
  sfcn_DAC_Outputs_wrapper(&board_virgin_lab2_B.DataTypeConversion_a,
    &board_virgin_lab2_DW.SFunction_DSTATE_m,
    &board_virgin_lab2_P.SFunction_P1_p, 1);

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  board_virgin_lab2_B.DataTypeConversion_c = board_virgin_lab2_B.SFunction2_o1;
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* S-Function (arduinodigitaloutput_sfcn): '<S5>/Digital Output' */
    MW_digitalWrite(board_virgin_lab2_P.DigitalOutput_pinNumber,
                    board_virgin_lab2_B.DataTypeConversion_c);
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  board_virgin_lab2_B.DataTypeConversion_p = board_virgin_lab2_B.SFunction2_o2;
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* S-Function (arduinodigitaloutput_sfcn): '<S6>/Digital Output' */
    MW_digitalWrite(board_virgin_lab2_P.DigitalOutput_pinNumber_e,
                    board_virgin_lab2_B.DataTypeConversion_p);

    /* S-Function (data_struct_init): '<S3>/S-Function1' */
    data_struct_init_Outputs_wrapper( &board_virgin_lab2_DW.SFunction1_DSTATE);
  }
}

/* Model update function for TID0 */
void board_virgin_lab2_update0(void)   /* Sample time: [0.0s, 0.0s] */
{
  /* S-Function "signals_wrapper" Block: <S3>/S-Function2 */
  signals_Update_wrapper( &board_virgin_lab2_B.SFunction2_o1,
    &board_virgin_lab2_B.SFunction2_o2, &board_virgin_lab2_DW.SFunction2_DSTATE);

  /* S-Function "sfcn_DAC_wrapper" Block: <S20>/S-Function */
  sfcn_DAC_Update_wrapper(&board_virgin_lab2_B.DataTypeConversion,
    &board_virgin_lab2_DW.SFunction_DSTATE_l,
    &board_virgin_lab2_P.SFunction_P1_d, 1);

  /* S-Function "sfcn_DAC_wrapper" Block: <S21>/S-Function */
  sfcn_DAC_Update_wrapper(&board_virgin_lab2_B.DataTypeConversion_a,
    &board_virgin_lab2_DW.SFunction_DSTATE_m,
    &board_virgin_lab2_P.SFunction_P1_p, 1);
  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    /* S-Function "data_struct_init_wrapper" Block: <S3>/S-Function1 */
    data_struct_init_Update_wrapper(&board_virgin_lab2_DW.SFunction1_DSTATE);
  }

  if (rtmIsMajorTimeStep(board_virgin_lab2_M)) {
    rt_ertODEUpdateContinuousStates(&board_virgin_lab2_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++board_virgin_lab2_M->Timing.clockTick0;
  board_virgin_lab2_M->Timing.t[0] = rtsiGetSolverStopTime
    (&board_virgin_lab2_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  board_virgin_lab2_M->Timing.clockTick1++;
}

/* Derivatives for root system: '<Root>' */
void board_virgin_lab2_derivatives(void)
{
  XDot_board_virgin_lab2_T *_rtXdot;
  _rtXdot = ((XDot_board_virgin_lab2_T *) board_virgin_lab2_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = board_virgin_lab2_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = board_virgin_lab2_B.IntegralGain;

  /* Derivatives for Integrator: '<S2>/Filter' */
  _rtXdot->Filter_CSTATE_c = board_virgin_lab2_B.FilterCoefficient_p;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = board_virgin_lab2_B.IntegralGain_h;
}

/* Model output function for TID2 */
void board_virgin_lab2_output2(void)   /* Sample time: [0.01s, 0.0s] */
{
  uint16_T rtb_SFunction_e_0;
  int16_T rtb_Sum_c;

  /* DataTypeConversion: '<S19>/conversion1' */
  board_virgin_lab2_B.conversion1 = (board_virgin_lab2_B.RateTransition1 != 0.0);

  /* DataTypeConversion: '<S19>/conversion3' */
  board_virgin_lab2_B.conversion3 = (board_virgin_lab2_B.RateTransition2 != 0.0);

  /* S-Function (arduinoanaloginput_sfcn): '<S8>/S-Function' */
  rtb_SFunction_e_0 = MW_analogRead(board_virgin_lab2_P.SFunction_p1_e);

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S8>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Gain: '<S8>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S8>/S-Function'
   */
  rtb_Sum_c = (int16_T)((int16_T)(board_virgin_lab2_P.Gain_Gain_f * (int16_T)
    rtb_SFunction_e_0 >> 14) + board_virgin_lab2_P.Constant_Value_n);

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  board_virgin_lab2_B.Compare = (rtb_Sum_c >
    board_virgin_lab2_P.CompareToConstant2_const);

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  board_virgin_lab2_B.Compare_j = (rtb_Sum_c >
    board_virgin_lab2_P.CompareToConstant3_const);

  /* DataTypeConversion: '<S19>/conversion13' */
  board_virgin_lab2_B.conversion13 = board_virgin_lab2_B.RateTransition5;

  /* DataTypeConversion: '<S19>/conversion2' */
  board_virgin_lab2_B.conversion2 = board_virgin_lab2_B.RateTransition6;

  /* S-Function (arduinoanaloginput_sfcn): '<S10>/S-Function' */
  rtb_SFunction_e_0 = MW_analogRead(board_virgin_lab2_P.SFunction_p1_a);

  /* DataTypeConversion: '<S19>/conversion4' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   *  Gain: '<S10>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S10>/S-Function'
   *  Sum: '<S10>/Sum'
   */
  board_virgin_lab2_B.conversion4 = (int16_T)((int16_T)
    (board_virgin_lab2_P.Gain_Gain_p * (int16_T)rtb_SFunction_e_0 >> 15) +
    board_virgin_lab2_P.Constant_Value_n3);

  /* S-Function (arduinoanaloginput_sfcn): '<S17>/S-Function' */
  rtb_SFunction_e_0 = MW_analogRead(board_virgin_lab2_P.SFunction_p1_es);

  /* DataTypeConversion: '<S19>/conversion5' incorporates:
   *  Constant: '<S17>/Constant'
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   *  Gain: '<S17>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S17>/S-Function'
   *  Sum: '<S17>/Sum'
   */
  board_virgin_lab2_B.conversion5 = (int16_T)((int16_T)
    (board_virgin_lab2_P.Gain_Gain_pu * (int16_T)rtb_SFunction_e_0 >> 14) +
    board_virgin_lab2_P.Constant_Value_a);

  /* S-Function (arduinoanaloginput_sfcn): '<S18>/S-Function' */
  rtb_SFunction_e_0 = MW_analogRead(board_virgin_lab2_P.SFunction_p1_bw);

  /* DataTypeConversion: '<S19>/conversion6' incorporates:
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  Gain: '<S18>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S18>/S-Function'
   *  Sum: '<S18>/Sum'
   */
  board_virgin_lab2_B.conversion6 = (int16_T)((int16_T)
    (board_virgin_lab2_P.Gain_Gain_m * (int16_T)rtb_SFunction_e_0 >> 14) +
    board_virgin_lab2_P.Constant_Value_a2);

  /* DataTypeConversion: '<S19>/conversion7' */
  board_virgin_lab2_B.conversion7 = (real32_T)
    board_virgin_lab2_B.RateTransition10;

  /* S-Function (SerialTx): '<S19>/S-Function' */
  SerialTx_Outputs_wrapper(&board_virgin_lab2_B.RateTransition, (boolean_T*)
    &board_virgin_lab2_BGND, (boolean_T*)&board_virgin_lab2_BGND, (boolean_T*)
    &board_virgin_lab2_BGND, &board_virgin_lab2_B.conversion1,
    &board_virgin_lab2_B.conversion3, &board_virgin_lab2_B.Compare,
    &board_virgin_lab2_B.Compare_j, &board_virgin_lab2_B.conversion13,
    &board_virgin_lab2_B.conversion2, &board_virgin_lab2_B.conversion4,
    &board_virgin_lab2_B.conversion5, &board_virgin_lab2_B.conversion6,
    &board_virgin_lab2_B.conversion7, &board_virgin_lab2_DW.SFunction_DSTATE,
    &board_virgin_lab2_P.SFunction_P1, 1, &board_virgin_lab2_P.SFunction_P2, 1);
}

/* Model update function for TID2 */
void board_virgin_lab2_update2(void)   /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function "SerialTx_wrapper" Block: <S19>/S-Function */
  SerialTx_Update_wrapper(&board_virgin_lab2_B.RateTransition, (boolean_T*)
    &board_virgin_lab2_BGND, (boolean_T*)&board_virgin_lab2_BGND, (boolean_T*)
    &board_virgin_lab2_BGND, &board_virgin_lab2_B.conversion1,
    &board_virgin_lab2_B.conversion3, &board_virgin_lab2_B.Compare,
    &board_virgin_lab2_B.Compare_j, &board_virgin_lab2_B.conversion13,
    &board_virgin_lab2_B.conversion2, &board_virgin_lab2_B.conversion4,
    &board_virgin_lab2_B.conversion5, &board_virgin_lab2_B.conversion6,
    &board_virgin_lab2_B.conversion7, &board_virgin_lab2_DW.SFunction_DSTATE,
    &board_virgin_lab2_P.SFunction_P1, 1, &board_virgin_lab2_P.SFunction_P2, 1);
}

/* Model initialize function */
void board_virgin_lab2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)board_virgin_lab2_M, 0,
                sizeof(RT_MODEL_board_virgin_lab2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&board_virgin_lab2_M->solverInfo,
                          &board_virgin_lab2_M->Timing.simTimeStep);
    rtsiSetTPtr(&board_virgin_lab2_M->solverInfo, &rtmGetTPtr
                (board_virgin_lab2_M));
    rtsiSetStepSizePtr(&board_virgin_lab2_M->solverInfo,
                       &board_virgin_lab2_M->Timing.stepSize0);
    rtsiSetdXPtr(&board_virgin_lab2_M->solverInfo,
                 &board_virgin_lab2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&board_virgin_lab2_M->solverInfo, (real_T **)
                         &board_virgin_lab2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&board_virgin_lab2_M->solverInfo,
      &board_virgin_lab2_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&board_virgin_lab2_M->solverInfo, (&rtmGetErrorStatus
      (board_virgin_lab2_M)));
    rtsiSetRTModelPtr(&board_virgin_lab2_M->solverInfo, board_virgin_lab2_M);
  }

  rtsiSetSimTimeStep(&board_virgin_lab2_M->solverInfo, MAJOR_TIME_STEP);
  board_virgin_lab2_M->ModelData.intgData.y =
    board_virgin_lab2_M->ModelData.odeY;
  board_virgin_lab2_M->ModelData.intgData.f[0] =
    board_virgin_lab2_M->ModelData.odeF[0];
  board_virgin_lab2_M->ModelData.intgData.f[1] =
    board_virgin_lab2_M->ModelData.odeF[1];
  board_virgin_lab2_M->ModelData.intgData.f[2] =
    board_virgin_lab2_M->ModelData.odeF[2];
  board_virgin_lab2_M->ModelData.contStates = ((X_board_virgin_lab2_T *)
    &board_virgin_lab2_X);
  rtsiSetSolverData(&board_virgin_lab2_M->solverInfo, (void *)
                    &board_virgin_lab2_M->ModelData.intgData);
  rtsiSetSolverName(&board_virgin_lab2_M->solverInfo,"ode3");
  rtmSetTPtr(board_virgin_lab2_M, &board_virgin_lab2_M->Timing.tArray[0]);
  board_virgin_lab2_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &board_virgin_lab2_B), 0,
                sizeof(B_board_virgin_lab2_T));

  /* states (continuous) */
  {
    (void) memset((void *)&board_virgin_lab2_X, 0,
                  sizeof(X_board_virgin_lab2_T));
  }

  /* states (dwork) */
  (void) memset((void *)&board_virgin_lab2_DW, 0,
                sizeof(DW_board_virgin_lab2_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S7>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab2_P.SFunction_p1);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S9>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab2_P.SFunction_p1_b);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function' */
  MW_pinModeInput(board_virgin_lab2_P.SFunction_p1_i);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output1' */
  MW_pinModeOutput(board_virgin_lab2_P.DigitalOutput1_pinNumber);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S8>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab2_P.SFunction_p1_e);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S10>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab2_P.SFunction_p1_a);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S17>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab2_P.SFunction_p1_es);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S18>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab2_P.SFunction_p1_bw);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S5>/Digital Output' */
  MW_pinModeOutput(board_virgin_lab2_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S6>/Digital Output' */
  MW_pinModeOutput(board_virgin_lab2_P.DigitalOutput_pinNumber_e);

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  board_virgin_lab2_X.Filter_CSTATE = board_virgin_lab2_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  board_virgin_lab2_X.Integrator_CSTATE = board_virgin_lab2_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Filter' */
  board_virgin_lab2_X.Filter_CSTATE_c = board_virgin_lab2_P.Filter_IC_g;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  board_virgin_lab2_X.Integrator_CSTATE_m = board_virgin_lab2_P.Integrator_IC_e;

  /* S-Function Block: <S3>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab2_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S19>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab2_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S20>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab2_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* S-Function Block: <S21>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab2_DW.SFunction_DSTATE_m = initVector[0];
      }
    }
  }

  /* S-Function Block: <S3>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab2_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void board_virgin_lab2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
