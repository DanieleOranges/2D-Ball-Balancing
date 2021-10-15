/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_virgin_lab1.c
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

const boolean_T board_virgin_lab1_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_board_virgin_lab1_T board_virgin_lab1_B;

/* Block states (auto storage) */
DW_board_virgin_lab1_T board_virgin_lab1_DW;

/* Real-time model */
RT_MODEL_board_virgin_lab1_T board_virgin_lab1_M_;
RT_MODEL_board_virgin_lab1_T *const board_virgin_lab1_M = &board_virgin_lab1_M_;
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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (board_virgin_lab1_M->Timing.TaskCounters.TID[1])++;
  if ((board_virgin_lab1_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    board_virgin_lab1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
void board_virgin_lab1_output0(void)   /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model update function for TID0 */
void board_virgin_lab1_update0(void)   /* Sample time: [0.001s, 0.0s] */
{
  /* (no update code required) */
}

/* Model output function for TID1 */
void board_virgin_lab1_output1(void)   /* Sample time: [0.01s, 0.0s] */
{
  boolean_T rtb_SFunction_h_0;
  uint16_T rtb_SFunction_0;
  int16_T rtb_Sum_b;
  int16_T rtb_Sum_kb;
  real_T rtb_Switch3_idx_0;
  real_T rtb_Switch3_idx_1;
  uint8_T tmp;

  /* S-Function (arduinodigitalinput_sfcn): '<S7>/S-Function' */
  board_virgin_lab1_B.SFunction = MW_digitalRead
    (board_virgin_lab1_P.SFunction_p1);

  /* S-Function (signals): '<S11>/S-Function2' */
  signals_Outputs_wrapper( &board_virgin_lab1_B.SFunction2_o1,
    &board_virgin_lab1_B.SFunction2_o2, &board_virgin_lab1_DW.SFunction2_DSTATE);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if (board_virgin_lab1_B.SFunction2_o1) {
    rtb_Switch3_idx_0 = board_virgin_lab1_B.SFunction;
  } else {
    rtb_Switch3_idx_0 = board_virgin_lab1_P.Constant_Value;
  }

  /* End of Switch: '<S9>/Switch' */

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (rtb_Switch3_idx_0 < 256.0) {
    if (rtb_Switch3_idx_0 >= 0.0) {
      tmp = (uint8_T)rtb_Switch3_idx_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output1' */
  MW_digitalWrite(board_virgin_lab1_P.DigitalOutput1_pinNumber, tmp);

  /* S-Function (arduinodigitalinput_sfcn): '<S8>/S-Function' */
  rtb_SFunction_h_0 = MW_digitalRead(board_virgin_lab1_P.SFunction_p1_l);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  S-Function (arduinodigitalinput_sfcn): '<S8>/S-Function'
   */
  if (board_virgin_lab1_B.SFunction2_o1) {
    rtb_Switch3_idx_0 = rtb_SFunction_h_0;
  } else {
    rtb_Switch3_idx_0 = board_virgin_lab1_P.Constant_Value_p;
  }

  /* End of Switch: '<S10>/Switch' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  if (rtb_Switch3_idx_0 < 256.0) {
    if (rtb_Switch3_idx_0 >= 0.0) {
      tmp = (uint8_T)rtb_Switch3_idx_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output1' */
  MW_digitalWrite(board_virgin_lab1_P.DigitalOutput1_pinNumber_m, tmp);

  /* DataTypeConversion: '<S14>/conversion3' */
  board_virgin_lab1_B.conversion3 = false;

  /* S-Function (arduinoanaloginput_sfcn): '<S2>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab1_P.SFunction_p1_e);

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  Gain: '<S2>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S2>/S-Function'
   */
  rtb_Sum_b = (int16_T)((int16_T)(board_virgin_lab1_P.Gain_Gain_f * (int16_T)
    rtb_SFunction_0 >> 14) + board_virgin_lab1_P.Constant_Value_n);

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   */
  board_virgin_lab1_B.Compare = (rtb_Sum_b >
    board_virgin_lab1_P.CompareToConstant2_const);

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  board_virgin_lab1_B.Compare_j = (rtb_Sum_b >
    board_virgin_lab1_P.CompareToConstant3_const);

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab1_P.SFunction_p1_o);

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Gain: '<S1>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S1>/S-Function'
   */
  rtb_Sum_b = (int16_T)((int16_T)(board_virgin_lab1_P.Gain_Gain * (int16_T)
    rtb_SFunction_0 >> 15) + board_virgin_lab1_P.Constant_Value_g);

  /* DataTypeConversion: '<S14>/conversion13' */
  board_virgin_lab1_B.conversion13 = rtb_Sum_b;

  /* S-Function (arduinoanaloginput_sfcn): '<S3>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab1_P.SFunction_p1_b);

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S3>/S-Function'
   */
  rtb_Sum_kb = (int16_T)((int16_T)(board_virgin_lab1_P.Gain_Gain_n * (int16_T)
    rtb_SFunction_0 >> 15) + board_virgin_lab1_P.Constant_Value_c);

  /* DataTypeConversion: '<S14>/conversion2' */
  board_virgin_lab1_B.conversion2 = rtb_Sum_kb;

  /* S-Function (arduinoanaloginput_sfcn): '<S4>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab1_P.SFunction_p1_a);

  /* DataTypeConversion: '<S14>/conversion4' incorporates:
   *  Constant: '<S4>/Constant'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  Gain: '<S4>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S4>/S-Function'
   *  Sum: '<S4>/Sum'
   */
  board_virgin_lab1_B.conversion4 = (int16_T)((int16_T)
    (board_virgin_lab1_P.Gain_Gain_p * (int16_T)rtb_SFunction_0 >> 15) +
    board_virgin_lab1_P.Constant_Value_n3);

  /* S-Function (arduinoanaloginput_sfcn): '<S12>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab1_P.SFunction_p1_es);

  /* DataTypeConversion: '<S14>/conversion5' incorporates:
   *  Constant: '<S12>/Constant'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  Gain: '<S12>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S12>/S-Function'
   *  Sum: '<S12>/Sum'
   */
  board_virgin_lab1_B.conversion5 = (int16_T)((int16_T)
    (board_virgin_lab1_P.Gain_Gain_pu * (int16_T)rtb_SFunction_0 >> 14) +
    board_virgin_lab1_P.Constant_Value_a);

  /* S-Function (arduinoanaloginput_sfcn): '<S13>/S-Function' */
  rtb_SFunction_0 = MW_analogRead(board_virgin_lab1_P.SFunction_p1_bw);

  /* DataTypeConversion: '<S14>/conversion6' incorporates:
   *  Constant: '<S13>/Constant'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   *  Gain: '<S13>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S13>/S-Function'
   *  Sum: '<S13>/Sum'
   */
  board_virgin_lab1_B.conversion6 = (int16_T)((int16_T)
    (board_virgin_lab1_P.Gain_Gain_m * (int16_T)rtb_SFunction_0 >> 14) +
    board_virgin_lab1_P.Constant_Value_a2);

  /* DataTypeConversion: '<S14>/conversion7' */
  board_virgin_lab1_B.conversion7 = 0.0F;

  /* S-Function (SerialTx): '<S14>/S-Function' */
  SerialTx_Outputs_wrapper(&board_virgin_lab1_B.SFunction2_o1, (boolean_T*)
    &board_virgin_lab1_BGND, (boolean_T*)&board_virgin_lab1_BGND, (boolean_T*)
    &board_virgin_lab1_BGND, &board_virgin_lab1_B.SFunction,
    &board_virgin_lab1_B.conversion3, &board_virgin_lab1_B.Compare,
    &board_virgin_lab1_B.Compare_j, &board_virgin_lab1_B.conversion13,
    &board_virgin_lab1_B.conversion2, &board_virgin_lab1_B.conversion4,
    &board_virgin_lab1_B.conversion5, &board_virgin_lab1_B.conversion6,
    &board_virgin_lab1_B.conversion7, &board_virgin_lab1_DW.SFunction_DSTATE,
    &board_virgin_lab1_P.SFunction_P1, 1, &board_virgin_lab1_P.SFunction_P2, 1);

  /* Switch: '<Root>/Switch3' incorporates:
   *  Abs: '<Root>/Abs'
   *  Abs: '<Root>/Abs1'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  S-Function (arduinodigitalinput_sfcn): '<S8>/S-Function'
   *  Sum: '<Root>/Sum'
   *  Sum: '<Root>/Sum1'
   */
  if (rtb_SFunction_h_0) {
    rtb_Switch3_idx_0 = board_virgin_lab1_P.Constant1_Value[0];
    rtb_Switch3_idx_1 = board_virgin_lab1_P.Constant1_Value[1];
  } else {
    rtb_Switch3_idx_0 = fabs((real_T)rtb_Sum_b -
      board_virgin_lab1_P.Constant2_Value);
    rtb_Switch3_idx_1 = fabs((real_T)rtb_Sum_kb -
      board_virgin_lab1_P.Constant3_Value);
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   */
  if (board_virgin_lab1_B.SFunction2_o1) {
    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    if (rtb_Switch3_idx_1 < 65536.0) {
      if (rtb_Switch3_idx_1 >= 0.0) {
        board_virgin_lab1_B.DataTypeConversion = (uint16_T)rtb_Switch3_idx_1;
      } else {
        board_virgin_lab1_B.DataTypeConversion = 0U;
      }
    } else {
      board_virgin_lab1_B.DataTypeConversion = MAX_uint16_T;
    }
  } else if (board_virgin_lab1_P.Constant_Value_d < 65536.0) {
    /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
     *  Constant: '<S15>/Constant'
     */
    if (board_virgin_lab1_P.Constant_Value_d >= 0.0) {
      board_virgin_lab1_B.DataTypeConversion = (uint16_T)
        board_virgin_lab1_P.Constant_Value_d;
    } else {
      board_virgin_lab1_B.DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    board_virgin_lab1_B.DataTypeConversion = MAX_uint16_T;
  }

  /* End of Switch: '<S15>/Switch' */

  /* S-Function (sfcn_DAC): '<S15>/S-Function' */
  sfcn_DAC_Outputs_wrapper(&board_virgin_lab1_B.DataTypeConversion,
    &board_virgin_lab1_DW.SFunction_DSTATE_l,
    &board_virgin_lab1_P.SFunction_P1_d, 1);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant'
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   */
  if (board_virgin_lab1_B.SFunction2_o1) {
    /* DataTypeConversion: '<S16>/Data Type Conversion' */
    if (rtb_Switch3_idx_0 < 65536.0) {
      if (rtb_Switch3_idx_0 >= 0.0) {
        board_virgin_lab1_B.DataTypeConversion_a = (uint16_T)rtb_Switch3_idx_0;
      } else {
        board_virgin_lab1_B.DataTypeConversion_a = 0U;
      }
    } else {
      board_virgin_lab1_B.DataTypeConversion_a = MAX_uint16_T;
    }
  } else if (board_virgin_lab1_P.Constant_Value_o < 65536.0) {
    /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
     *  Constant: '<S16>/Constant'
     */
    if (board_virgin_lab1_P.Constant_Value_o >= 0.0) {
      board_virgin_lab1_B.DataTypeConversion_a = (uint16_T)
        board_virgin_lab1_P.Constant_Value_o;
    } else {
      board_virgin_lab1_B.DataTypeConversion_a = 0U;
    }
  } else {
    /* DataTypeConversion: '<S16>/Data Type Conversion' */
    board_virgin_lab1_B.DataTypeConversion_a = MAX_uint16_T;
  }

  /* End of Switch: '<S16>/Switch' */

  /* S-Function (sfcn_DAC): '<S16>/S-Function' */
  sfcn_DAC_Outputs_wrapper(&board_virgin_lab1_B.DataTypeConversion_a,
    &board_virgin_lab1_DW.SFunction_DSTATE_m,
    &board_virgin_lab1_P.SFunction_P1_p, 1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S17>/Digital Output' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   */
  MW_digitalWrite(board_virgin_lab1_P.DigitalOutput_pinNumber, (uint8_T)
                  board_virgin_lab1_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S18>/Digital Output' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   */
  MW_digitalWrite(board_virgin_lab1_P.DigitalOutput_pinNumber_e, (uint8_T)
                  board_virgin_lab1_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S11>/S-Function1' */
  data_struct_init_Outputs_wrapper( &board_virgin_lab1_DW.SFunction1_DSTATE);
}

/* Model update function for TID1 */
void board_virgin_lab1_update1(void)   /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function "signals_wrapper" Block: <S11>/S-Function2 */
  signals_Update_wrapper( &board_virgin_lab1_B.SFunction2_o1,
    &board_virgin_lab1_B.SFunction2_o2, &board_virgin_lab1_DW.SFunction2_DSTATE);

  /* S-Function "SerialTx_wrapper" Block: <S14>/S-Function */
  SerialTx_Update_wrapper(&board_virgin_lab1_B.SFunction2_o1, (boolean_T*)
    &board_virgin_lab1_BGND, (boolean_T*)&board_virgin_lab1_BGND, (boolean_T*)
    &board_virgin_lab1_BGND, &board_virgin_lab1_B.SFunction,
    &board_virgin_lab1_B.conversion3, &board_virgin_lab1_B.Compare,
    &board_virgin_lab1_B.Compare_j, &board_virgin_lab1_B.conversion13,
    &board_virgin_lab1_B.conversion2, &board_virgin_lab1_B.conversion4,
    &board_virgin_lab1_B.conversion5, &board_virgin_lab1_B.conversion6,
    &board_virgin_lab1_B.conversion7, &board_virgin_lab1_DW.SFunction_DSTATE,
    &board_virgin_lab1_P.SFunction_P1, 1, &board_virgin_lab1_P.SFunction_P2, 1);

  /* S-Function "sfcn_DAC_wrapper" Block: <S15>/S-Function */
  sfcn_DAC_Update_wrapper(&board_virgin_lab1_B.DataTypeConversion,
    &board_virgin_lab1_DW.SFunction_DSTATE_l,
    &board_virgin_lab1_P.SFunction_P1_d, 1);

  /* S-Function "sfcn_DAC_wrapper" Block: <S16>/S-Function */
  sfcn_DAC_Update_wrapper(&board_virgin_lab1_B.DataTypeConversion_a,
    &board_virgin_lab1_DW.SFunction_DSTATE_m,
    &board_virgin_lab1_P.SFunction_P1_p, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S11>/S-Function1 */
  data_struct_init_Update_wrapper(&board_virgin_lab1_DW.SFunction1_DSTATE);
}

/* Model initialize function */
void board_virgin_lab1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)board_virgin_lab1_M, 0,
                sizeof(RT_MODEL_board_virgin_lab1_T));

  /* block I/O */
  (void) memset(((void *) &board_virgin_lab1_B), 0,
                sizeof(B_board_virgin_lab1_T));

  /* states (dwork) */
  (void) memset((void *)&board_virgin_lab1_DW, 0,
                sizeof(DW_board_virgin_lab1_T));

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S7>/S-Function' */
  MW_pinModeInput(board_virgin_lab1_P.SFunction_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output1' */
  MW_pinModeOutput(board_virgin_lab1_P.DigitalOutput1_pinNumber);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S8>/S-Function' */
  MW_pinModeInput(board_virgin_lab1_P.SFunction_p1_l);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output1' */
  MW_pinModeOutput(board_virgin_lab1_P.DigitalOutput1_pinNumber_m);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S2>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab1_P.SFunction_p1_e);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab1_P.SFunction_p1_o);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S3>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab1_P.SFunction_p1_b);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S4>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab1_P.SFunction_p1_a);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S12>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab1_P.SFunction_p1_es);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S13>/S-Function' */
  MW_pinModeAnalogInput(board_virgin_lab1_P.SFunction_p1_bw);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S17>/Digital Output' */
  MW_pinModeOutput(board_virgin_lab1_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S18>/Digital Output' */
  MW_pinModeOutput(board_virgin_lab1_P.DigitalOutput_pinNumber_e);

  /* S-Function Block: <S11>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab1_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S14>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab1_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S15>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab1_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* S-Function Block: <S16>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab1_DW.SFunction_DSTATE_m = initVector[0];
      }
    }
  }

  /* S-Function Block: <S11>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        board_virgin_lab1_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void board_virgin_lab1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
