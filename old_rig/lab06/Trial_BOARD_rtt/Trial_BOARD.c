/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Trial_BOARD.c
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

const boolean_T Trial_BOARD_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_Trial_BOARD_T Trial_BOARD_B;

/* Block states (auto storage) */
DW_Trial_BOARD_T Trial_BOARD_DW;

/* Real-time model */
RT_MODEL_Trial_BOARD_T Trial_BOARD_M_;
RT_MODEL_Trial_BOARD_T *const Trial_BOARD_M = &Trial_BOARD_M_;
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
  (Trial_BOARD_M->Timing.TaskCounters.TID[1])++;
  if ((Trial_BOARD_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    Trial_BOARD_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
void Trial_BOARD_output0(void)         /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model update function for TID0 */
void Trial_BOARD_update0(void)         /* Sample time: [0.001s, 0.0s] */
{
  /* (no update code required) */
}

/* Model output function for TID1 */
void Trial_BOARD_output1(void)         /* Sample time: [0.01s, 0.0s] */
{
  uint16_T rtb_SFunction_o_0;
  uint16_T rtb_SFunction_l_0;
  uint16_T rtb_SFunction_e_0;
  uint16_T rtb_SFunction_j_0;
  uint16_T rtb_SFunction_k_0;
  uint16_T rtb_SFunction_m_0;
  int16_T rtb_Sum;
  int16_T rtb_Sum_l;
  int16_T rtb_Sum_i;
  real_T rtb_Gain_idx_0;
  real_T rtb_Gain_idx_1;
  uint8_T tmp;

  /* S-Function (arduinodigitalinput_sfcn): '<S15>/S-Function' */
  Trial_BOARD_B.SFunction_m = MW_digitalRead(Trial_BOARD_P.SFunction_p1);

  /* S-Function (arduinoanaloginput_sfcn): '<S7>/S-Function' */
  rtb_SFunction_o_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_k);

  /* Sum: '<S7>/Sum' incorporates:
   *  Constant: '<S7>/Constant'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Gain: '<S7>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S7>/S-Function'
   */
  rtb_Sum = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_p * (int16_T)
    rtb_SFunction_o_0 >> 14) + Trial_BOARD_P.Constant_Value_ix);

  /* S-Function (arduinoanaloginput_sfcn): '<S8>/S-Function' */
  rtb_SFunction_o_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_kd);

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S8>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Gain: '<S8>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S8>/S-Function'
   */
  rtb_Sum_l = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_j * (int16_T)
    rtb_SFunction_o_0 >> 14) + Trial_BOARD_P.Constant_Value_d);

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (Trial_BOARD_B.SFunction_m) {
    rtb_Gain_idx_0 = Trial_BOARD_P.Constant_Value_ij[0];
    rtb_Gain_idx_1 = Trial_BOARD_P.Constant_Value_ij[1];
  } else {
    rtb_Gain_idx_0 = rtb_Sum;
    rtb_Gain_idx_1 = rtb_Sum_l;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* S-Function (signals): '<S24>/S-Function2' */
  signals_Outputs_wrapper( &Trial_BOARD_B.SFunction2_o1,
    &Trial_BOARD_B.SFunction2_o2, &Trial_BOARD_DW.SFunction2_DSTATE);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   */
  if (Trial_BOARD_B.SFunction2_o1) {
    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    if (rtb_Gain_idx_0 < 65536.0) {
      if (rtb_Gain_idx_0 >= 0.0) {
        Trial_BOARD_B.DataTypeConversion = (uint16_T)rtb_Gain_idx_0;
      } else {
        Trial_BOARD_B.DataTypeConversion = 0U;
      }
    } else {
      Trial_BOARD_B.DataTypeConversion = MAX_uint16_T;
    }
  } else if (Trial_BOARD_P.Constant_Value < 65536.0) {
    /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
     *  Constant: '<S10>/Constant'
     */
    if (Trial_BOARD_P.Constant_Value >= 0.0) {
      Trial_BOARD_B.DataTypeConversion = (uint16_T)Trial_BOARD_P.Constant_Value;
    } else {
      Trial_BOARD_B.DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    Trial_BOARD_B.DataTypeConversion = MAX_uint16_T;
  }

  /* End of Switch: '<S10>/Switch' */

  /* S-Function (sfcn_DAC): '<S10>/S-Function' */
  sfcn_DAC_Outputs_wrapper(&Trial_BOARD_B.DataTypeConversion,
    &Trial_BOARD_DW.SFunction_DSTATE, &Trial_BOARD_P.SFunction_P1_h, 1);

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   */
  if (Trial_BOARD_B.SFunction2_o1) {
    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    if (rtb_Gain_idx_1 < 65536.0) {
      if (rtb_Gain_idx_1 >= 0.0) {
        Trial_BOARD_B.DataTypeConversion_e = (uint16_T)rtb_Gain_idx_1;
      } else {
        Trial_BOARD_B.DataTypeConversion_e = 0U;
      }
    } else {
      Trial_BOARD_B.DataTypeConversion_e = MAX_uint16_T;
    }
  } else if (Trial_BOARD_P.Constant_Value_f < 65536.0) {
    /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
     *  Constant: '<S11>/Constant'
     */
    if (Trial_BOARD_P.Constant_Value_f >= 0.0) {
      Trial_BOARD_B.DataTypeConversion_e = (uint16_T)
        Trial_BOARD_P.Constant_Value_f;
    } else {
      Trial_BOARD_B.DataTypeConversion_e = 0U;
    }
  } else {
    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    Trial_BOARD_B.DataTypeConversion_e = MAX_uint16_T;
  }

  /* End of Switch: '<S11>/Switch' */

  /* S-Function (sfcn_DAC): '<S11>/S-Function' */
  sfcn_DAC_Outputs_wrapper(&Trial_BOARD_B.DataTypeConversion_e,
    &Trial_BOARD_DW.SFunction_DSTATE_c, &Trial_BOARD_P.SFunction_P1_l, 1);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (Trial_BOARD_B.SFunction2_o1) {
    rtb_Gain_idx_0 = Trial_BOARD_B.SFunction_m;
  } else {
    rtb_Gain_idx_0 = Trial_BOARD_P.Constant_Value_h;
  }

  /* End of Switch: '<S16>/Switch' */

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (rtb_Gain_idx_0 < 256.0) {
    if (rtb_Gain_idx_0 >= 0.0) {
      tmp = (uint8_T)rtb_Gain_idx_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S16>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S16>/Digital Output1' */
  MW_digitalWrite(Trial_BOARD_P.DigitalOutput1_pinNumber, tmp);

  /* S-Function (arduinodigitalinput_sfcn): '<S14>/S-Function' */
  Trial_BOARD_B.SFunction_h = MW_digitalRead(Trial_BOARD_P.SFunction_p1_j);

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   */
  if (Trial_BOARD_B.SFunction2_o1) {
    rtb_Gain_idx_0 = Trial_BOARD_B.SFunction_h;
  } else {
    rtb_Gain_idx_0 = Trial_BOARD_P.Constant_Value_i;
  }

  /* End of Switch: '<S17>/Switch' */

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  if (rtb_Gain_idx_0 < 256.0) {
    if (rtb_Gain_idx_0 >= 0.0) {
      tmp = (uint8_T)rtb_Gain_idx_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S17>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S17>/Digital Output1' */
  MW_digitalWrite(Trial_BOARD_P.DigitalOutput1_pinNumber_d, tmp);

  /* S-Function (arduinoanaloginput_sfcn): '<S9>/S-Function' */
  rtb_SFunction_o_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_b);

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S9>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Gain: '<S9>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S9>/S-Function'
   */
  rtb_Sum_i = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_o * (int16_T)
    rtb_SFunction_o_0 >> 14) + Trial_BOARD_P.Constant_Value_hd);

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  Trial_BOARD_B.Compare = (rtb_Sum_i > Trial_BOARD_P.CompareToConstant_const);

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   */
  Trial_BOARD_B.Compare_j = (rtb_Sum_i > Trial_BOARD_P.CompareToConstant1_const);

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/S-Function' */
  rtb_SFunction_o_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_i);

  /* S-Function (arduinoanaloginput_sfcn): '<S2>/S-Function' */
  rtb_SFunction_l_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_o);

  /* S-Function (arduinoanaloginput_sfcn): '<S3>/S-Function' */
  rtb_SFunction_e_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_ki);

  /* S-Function (arduinoanaloginput_sfcn): '<S4>/S-Function' */
  rtb_SFunction_j_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_h);

  /* S-Function (arduinoanaloginput_sfcn): '<S5>/S-Function' */
  rtb_SFunction_k_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_f);

  /* S-Function (arduinoanaloginput_sfcn): '<S6>/S-Function' */
  rtb_SFunction_m_0 = MW_analogRead(Trial_BOARD_P.SFunction_p1_n);

  /* S-Function (sfcn_encoder): '<S18>/S-Function' */
  sfcn_encoder_Outputs_wrapper((boolean_T*)&Trial_BOARD_BGND,
    &Trial_BOARD_B.SFunction, &Trial_BOARD_DW.SFunction_DSTATE_d,
    &Trial_BOARD_P.SFunction_P1_p, 1, &Trial_BOARD_P.Encoder_dt_enc, 1);

  /* S-Function (sfcn_encoder): '<S19>/S-Function' */
  sfcn_encoder_Outputs_wrapper((boolean_T*)&Trial_BOARD_BGND,
    &Trial_BOARD_B.SFunction_g, &Trial_BOARD_DW.SFunction_DSTATE_cn,
    &Trial_BOARD_P.SFunction_P1_m, 1, &Trial_BOARD_P.Encoder1_dt_enc, 1);

  /* S-Function (sfcn_encoder): '<S20>/S-Function' */
  sfcn_encoder_Outputs_wrapper((boolean_T*)&Trial_BOARD_BGND,
    &Trial_BOARD_B.SFunction_e, &Trial_BOARD_DW.SFunction_DSTATE_j,
    &Trial_BOARD_P.SFunction_P1_g, 1, &Trial_BOARD_P.Encoder2_dt_enc, 1);

  /* S-Function (sfcn_encoder): '<S21>/S-Function' */
  sfcn_encoder_Outputs_wrapper((boolean_T*)&Trial_BOARD_BGND,
    &Trial_BOARD_B.SFunction_l, &Trial_BOARD_DW.SFunction_DSTATE_e,
    &Trial_BOARD_P.SFunction_P1_d, 1, &Trial_BOARD_P.Encoder3_dt_enc, 1);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (Trial_BOARD_B.SFunction_m) {
    rtb_Gain_idx_0 = rtb_Sum;
  } else {
    rtb_Gain_idx_0 = Trial_BOARD_P.Constant_Value_ij[0];
  }

  /* DataTypeConversion: '<S22>/conversion8' incorporates:
   *  Bias: '<Root>/Bias'
   *  Gain: '<Root>/Gain'
   */
  Trial_BOARD_B.conversion8 = (real32_T)((rtb_Gain_idx_0 +
    Trial_BOARD_P.Bias_Bias) * Trial_BOARD_P.Gain_Gain);

  /* Logic: '<S22>/Logical Operator' */
  Trial_BOARD_B.LogicalOperator = (Trial_BOARD_B.SFunction_m &&
    Trial_BOARD_B.SFunction2_o1);

  /* S-Function (sfcn_motor_new): '<S22>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&Trial_BOARD_B.conversion8,
    &Trial_BOARD_B.LogicalOperator, &Trial_BOARD_B.SFunction1_o1,
    &Trial_BOARD_B.SFunction1_o2, &Trial_BOARD_B.SFunction1_o3,
    &Trial_BOARD_DW.SFunction1_DSTATE, &Trial_BOARD_P.SFunction1_P1, 1,
    &Trial_BOARD_P.SFunction1_P2, 1, &Trial_BOARD_P.SFunction1_P3, 1);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (Trial_BOARD_B.SFunction_m) {
    rtb_Gain_idx_0 = rtb_Sum_l;
  } else {
    rtb_Gain_idx_0 = Trial_BOARD_P.Constant_Value_ij[1];
  }

  /* DataTypeConversion: '<S23>/conversion8' incorporates:
   *  Bias: '<Root>/Bias'
   *  Gain: '<Root>/Gain'
   */
  Trial_BOARD_B.conversion8_g = (real32_T)((rtb_Gain_idx_0 +
    Trial_BOARD_P.Bias_Bias) * Trial_BOARD_P.Gain_Gain);

  /* Logic: '<S23>/Logical Operator' */
  Trial_BOARD_B.LogicalOperator_f = (Trial_BOARD_B.SFunction_m &&
    Trial_BOARD_B.SFunction2_o1);

  /* S-Function (sfcn_motor_new): '<S23>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&Trial_BOARD_B.conversion8_g,
    &Trial_BOARD_B.LogicalOperator_f, &Trial_BOARD_B.SFunction1_o1_p,
    &Trial_BOARD_B.SFunction1_o2_p, &Trial_BOARD_B.SFunction1_o3_o,
    &Trial_BOARD_DW.SFunction1_DSTATE_h, &Trial_BOARD_P.SFunction1_P1_h, 1,
    &Trial_BOARD_P.SFunction1_P2_c, 1, &Trial_BOARD_P.SFunction1_P3_k, 1);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S3>/Gain'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S6>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S1>/S-Function'
   *  S-Function (arduinoanaloginput_sfcn): '<S2>/S-Function'
   *  S-Function (arduinoanaloginput_sfcn): '<S3>/S-Function'
   *  S-Function (arduinoanaloginput_sfcn): '<S4>/S-Function'
   *  S-Function (arduinoanaloginput_sfcn): '<S5>/S-Function'
   *  S-Function (arduinoanaloginput_sfcn): '<S6>/S-Function'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S5>/Sum'
   *  Sum: '<S6>/Sum'
   */
  if (Trial_BOARD_B.SFunction_h) {
    Trial_BOARD_B.Switch[0] = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_n *
      (int16_T)rtb_SFunction_o_0 >> 15) + Trial_BOARD_P.Constant_Value_e);
    Trial_BOARD_B.Switch[1] = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_g *
      (int16_T)rtb_SFunction_l_0 >> 15) + Trial_BOARD_P.Constant_Value_hj);
    Trial_BOARD_B.Switch[2] = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_a *
      (int16_T)rtb_SFunction_e_0 >> 15) + Trial_BOARD_P.Constant_Value_j);
    Trial_BOARD_B.Switch[3] = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_e *
      (int16_T)rtb_SFunction_j_0 >> 15) + Trial_BOARD_P.Constant_Value_hk);
    Trial_BOARD_B.Switch[4] = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_l *
      (int16_T)rtb_SFunction_k_0 >> 15) + Trial_BOARD_P.Constant_Value_a);
    Trial_BOARD_B.Switch[5] = (int16_T)((int16_T)(Trial_BOARD_P.Gain_Gain_m *
      (int16_T)rtb_SFunction_m_0 >> 15) + Trial_BOARD_P.Constant_Value_f3);
  } else {
    Trial_BOARD_B.Switch[0] = (real32_T)Trial_BOARD_B.SFunction;
    Trial_BOARD_B.Switch[1] = (real32_T)Trial_BOARD_B.SFunction_g;
    Trial_BOARD_B.Switch[2] = (real32_T)Trial_BOARD_B.SFunction_e;
    Trial_BOARD_B.Switch[3] = (real32_T)Trial_BOARD_B.SFunction_l;
    Trial_BOARD_B.Switch[4] = Trial_BOARD_B.SFunction1_o1;
    Trial_BOARD_B.Switch[5] = Trial_BOARD_B.SFunction1_o1_p;
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (SerialTx): '<S25>/S-Function' */
  SerialTx_Outputs_wrapper(&Trial_BOARD_B.SFunction2_o1, (boolean_T*)
    &Trial_BOARD_BGND, (boolean_T*)&Trial_BOARD_BGND, (boolean_T*)
    &Trial_BOARD_BGND, &Trial_BOARD_B.SFunction_h, &Trial_BOARD_B.SFunction_m,
    &Trial_BOARD_B.Compare, &Trial_BOARD_B.Compare_j, &Trial_BOARD_B.Switch[0],
    &Trial_BOARD_B.Switch[1], &Trial_BOARD_B.Switch[2], &Trial_BOARD_B.Switch[3],
    &Trial_BOARD_B.Switch[4], &Trial_BOARD_B.Switch[5],
    &Trial_BOARD_DW.SFunction_DSTATE_p, &Trial_BOARD_P.SFunction_P1, 1,
    &Trial_BOARD_P.SFunction_P2, 1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S26>/Digital Output' incorporates:
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   */
  MW_digitalWrite(Trial_BOARD_P.DigitalOutput_pinNumber, (uint8_T)
                  Trial_BOARD_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S27>/Digital Output' incorporates:
   *  DataTypeConversion: '<S27>/Data Type Conversion'
   */
  MW_digitalWrite(Trial_BOARD_P.DigitalOutput_pinNumber_m, (uint8_T)
                  Trial_BOARD_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S24>/S-Function1' */
  data_struct_init_Outputs_wrapper( &Trial_BOARD_DW.SFunction1_DSTATE_j);
}

/* Model update function for TID1 */
void Trial_BOARD_update1(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function "signals_wrapper" Block: <S24>/S-Function2 */
  signals_Update_wrapper( &Trial_BOARD_B.SFunction2_o1,
    &Trial_BOARD_B.SFunction2_o2, &Trial_BOARD_DW.SFunction2_DSTATE);

  /* S-Function "sfcn_DAC_wrapper" Block: <S10>/S-Function */
  sfcn_DAC_Update_wrapper(&Trial_BOARD_B.DataTypeConversion,
    &Trial_BOARD_DW.SFunction_DSTATE, &Trial_BOARD_P.SFunction_P1_h, 1);

  /* S-Function "sfcn_DAC_wrapper" Block: <S11>/S-Function */
  sfcn_DAC_Update_wrapper(&Trial_BOARD_B.DataTypeConversion_e,
    &Trial_BOARD_DW.SFunction_DSTATE_c, &Trial_BOARD_P.SFunction_P1_l, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S18>/S-Function */
  sfcn_encoder_Update_wrapper((boolean_T*)&Trial_BOARD_BGND,
    &Trial_BOARD_B.SFunction, &Trial_BOARD_DW.SFunction_DSTATE_d,
    &Trial_BOARD_P.SFunction_P1_p, 1, &Trial_BOARD_P.Encoder_dt_enc, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S19>/S-Function */
  sfcn_encoder_Update_wrapper((boolean_T*)&Trial_BOARD_BGND,
    &Trial_BOARD_B.SFunction_g, &Trial_BOARD_DW.SFunction_DSTATE_cn,
    &Trial_BOARD_P.SFunction_P1_m, 1, &Trial_BOARD_P.Encoder1_dt_enc, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S20>/S-Function */
  sfcn_encoder_Update_wrapper((boolean_T*)&Trial_BOARD_BGND,
    &Trial_BOARD_B.SFunction_e, &Trial_BOARD_DW.SFunction_DSTATE_j,
    &Trial_BOARD_P.SFunction_P1_g, 1, &Trial_BOARD_P.Encoder2_dt_enc, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S21>/S-Function */
  sfcn_encoder_Update_wrapper((boolean_T*)&Trial_BOARD_BGND,
    &Trial_BOARD_B.SFunction_l, &Trial_BOARD_DW.SFunction_DSTATE_e,
    &Trial_BOARD_P.SFunction_P1_d, 1, &Trial_BOARD_P.Encoder3_dt_enc, 1);

  /* S-Function "sfcn_motor_new_wrapper" Block: <S22>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&Trial_BOARD_B.conversion8,
    &Trial_BOARD_B.LogicalOperator, &Trial_BOARD_B.SFunction1_o1,
    &Trial_BOARD_B.SFunction1_o2, &Trial_BOARD_B.SFunction1_o3,
    &Trial_BOARD_DW.SFunction1_DSTATE, &Trial_BOARD_P.SFunction1_P1, 1,
    &Trial_BOARD_P.SFunction1_P2, 1, &Trial_BOARD_P.SFunction1_P3, 1);

  /* S-Function "sfcn_motor_new_wrapper" Block: <S23>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&Trial_BOARD_B.conversion8_g,
    &Trial_BOARD_B.LogicalOperator_f, &Trial_BOARD_B.SFunction1_o1_p,
    &Trial_BOARD_B.SFunction1_o2_p, &Trial_BOARD_B.SFunction1_o3_o,
    &Trial_BOARD_DW.SFunction1_DSTATE_h, &Trial_BOARD_P.SFunction1_P1_h, 1,
    &Trial_BOARD_P.SFunction1_P2_c, 1, &Trial_BOARD_P.SFunction1_P3_k, 1);

  /* S-Function "SerialTx_wrapper" Block: <S25>/S-Function */
  SerialTx_Update_wrapper(&Trial_BOARD_B.SFunction2_o1, (boolean_T*)
    &Trial_BOARD_BGND, (boolean_T*)&Trial_BOARD_BGND, (boolean_T*)
    &Trial_BOARD_BGND, &Trial_BOARD_B.SFunction_h, &Trial_BOARD_B.SFunction_m,
    &Trial_BOARD_B.Compare, &Trial_BOARD_B.Compare_j, &Trial_BOARD_B.Switch[0],
    &Trial_BOARD_B.Switch[1], &Trial_BOARD_B.Switch[2], &Trial_BOARD_B.Switch[3],
    &Trial_BOARD_B.Switch[4], &Trial_BOARD_B.Switch[5],
    &Trial_BOARD_DW.SFunction_DSTATE_p, &Trial_BOARD_P.SFunction_P1, 1,
    &Trial_BOARD_P.SFunction_P2, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S24>/S-Function1 */
  data_struct_init_Update_wrapper(&Trial_BOARD_DW.SFunction1_DSTATE_j);
}

/* Model initialize function */
void Trial_BOARD_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Trial_BOARD_M, 0,
                sizeof(RT_MODEL_Trial_BOARD_T));

  /* block I/O */
  (void) memset(((void *) &Trial_BOARD_B), 0,
                sizeof(B_Trial_BOARD_T));

  /* states (dwork) */
  (void) memset((void *)&Trial_BOARD_DW, 0,
                sizeof(DW_Trial_BOARD_T));

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S15>/S-Function' */
  MW_pinModeInput(Trial_BOARD_P.SFunction_p1);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S7>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_k);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S8>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_kd);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S16>/Digital Output1' */
  MW_pinModeOutput(Trial_BOARD_P.DigitalOutput1_pinNumber);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S14>/S-Function' */
  MW_pinModeInput(Trial_BOARD_P.SFunction_p1_j);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S17>/Digital Output1' */
  MW_pinModeOutput(Trial_BOARD_P.DigitalOutput1_pinNumber_d);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S9>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_b);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_i);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S2>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_o);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S3>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_ki);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S4>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_h);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S5>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_f);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S6>/S-Function' */
  MW_pinModeAnalogInput(Trial_BOARD_P.SFunction_p1_n);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S26>/Digital Output' */
  MW_pinModeOutput(Trial_BOARD_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S27>/Digital Output' */
  MW_pinModeOutput(Trial_BOARD_P.DigitalOutput_pinNumber_m);

  /* S-Function Block: <S24>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S10>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S11>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction_DSTATE_c = initVector[0];
      }
    }
  }

  /* S-Function Block: <S18>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction_DSTATE_d = initVector[0];
      }
    }
  }

  /* S-Function Block: <S19>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction_DSTATE_cn = initVector[0];
      }
    }
  }

  /* S-Function Block: <S20>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction_DSTATE_j = initVector[0];
      }
    }
  }

  /* S-Function Block: <S21>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction_DSTATE_e = initVector[0];
      }
    }
  }

  /* S-Function Block: <S22>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S23>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction1_DSTATE_h = initVector[0];
      }
    }
  }

  /* S-Function Block: <S25>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction_DSTATE_p = initVector[0];
      }
    }
  }

  /* S-Function Block: <S24>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Trial_BOARD_DW.SFunction1_DSTATE_j = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void Trial_BOARD_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
