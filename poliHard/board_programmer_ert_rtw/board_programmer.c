/*
 * board_programmer.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "board_programmer".
 *
 * Model version              : 1.23
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Dec  9 19:01:36 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "board_programmer.h"
#include "board_programmer_private.h"

/* Block signals (default storage) */
B_board_programmer_T board_programmer_B;

/* Block states (default storage) */
DW_board_programmer_T board_programmer_DW;

/* Real-time model */
static RT_MODEL_board_programmer_T board_programmer_M_;
RT_MODEL_board_programmer_T *const board_programmer_M = &board_programmer_M_;

/* Forward declaration for local functions */
static void ProtocolEncoderBase_get_DataTyp(uint8_T value[2]);
static void ProtocolEncoderBase_get_DataT_h(uint8_T value[5]);
uint32_T plook_lincg(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                     *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Linear Search */
  bpIndex = maxIndex >> 1U;
  while ((u < bp[bpIndex]) && (bpIndex > 0U)) {
    bpIndex--;
  }

  while ((bpIndex < maxIndex - 1U) && (u >= bp[bpIndex + 1U])) {
    bpIndex++;
  }

  *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  return bpIndex;
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

void Double2MultiWord(real_T u1, uint32_T y[], int32_T n)
{
  real_T yd;
  real_T yn;
  int32_T currExp;
  int32_T i;
  int32_T msl;
  int32_T prevExp;
  uint32_T cb;
  uint32_T u1i;
  boolean_T isNegative;
  isNegative = (u1 < 0.0);
  yn = frexp(u1, &currExp);
  msl = currExp <= 0 ? -1 : (currExp - 1) / 32;
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? -yn : yn;
  prevExp = 32 * msl;
  for (i = msl; i >= 0; i--) {
    yn = ldexp(yn, currExp - prevExp);
    yd = floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = (uint32_T)yd;
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (uint32_T)(cb < u1i);
    }
  }
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  uint32_T carry = 0U;
  uint32_T u1i;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0U ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

/* System initialize for atomic system: */
void board_progra_MovingAverage_Init(DW_MovingAverage_board_progra_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S26>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S26>/Moving Average' */
}

/* System reset for atomic system: */
void board_progr_MovingAverage_Reset(DW_MovingAverage_board_progra_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S26>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S26>/Moving Average' */
}

/* Start for atomic system: */
void board_progr_MovingAverage_Start(DW_MovingAverage_board_progra_T *localDW)
{
  /* Start for MATLABSystem: '<S26>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

/* Output and update for atomic system: */
void board_programmer_MovingAverage(real_T rtu_0,
  B_MovingAverage_board_program_T *localB, DW_MovingAverage_board_progra_T
  *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<S26>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 9; i++) {
    localB->csumrev[i] = obj->pCumSumRev[i];
  }

  modValueRev = obj->pModValueRev;
  z = 0.0;

  /* MATLABSystem: '<S26>/Moving Average' */
  localB->MovingAverage = 0.0;

  /* MATLABSystem: '<S26>/Moving Average' */
  csum += rtu_0;
  if (modValueRev == 0.0) {
    z = localB->csumrev[(int32_T)cumRevIndex - 1] + csum;
  }

  localB->csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 9.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (i = 7; i >= 0; i--) {
      localB->csumrev[i] += localB->csumrev[i + 1];
    }
  }

  if (modValueRev == 0.0) {
    /* MATLABSystem: '<S26>/Moving Average' */
    localB->MovingAverage = z / 10.0;
  }

  obj->pCumSum = csum;
  for (i = 0; i < 9; i++) {
    obj->pCumSumRev[i] = localB->csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }
}

/* Termination for atomic system: */
void board_progra_MovingAverage_Term(DW_MovingAverage_board_progra_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  /* Terminate for MATLABSystem: '<S26>/Moving Average' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S26>/Moving Average' */
}

/*
 * System initialize for enable system:
 *    '<S5>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_program_controlloPP1_Init(DW_controlloPP1_board_program_T *localDW,
  P_controlloPP1_board_programm_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S28>/UD' */
  localDW->UD_DSTATE = localP->DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Sum: '<S26>/Sum1' incorporates:
   *  Delay: '<S26>/Delay'
   */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S29>/UD' */
  localDW->UD_DSTATE_g = localP->DiscreteDerivative_ICPrevScal_f;

  /* InitializeConditions for Sum: '<S27>/Sum1' incorporates:
   *  Delay: '<S27>/Delay'
   */
  localDW->Delay_DSTATE_k = localP->Delay_InitialCondition_o;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_n = localP->DiscreteTimeIntegrator_IC_a;
  localDW->DiscreteTimeIntegrator_PrevRe_p = 2;
  board_progra_MovingAverage_Init(&localDW->MovingAverage);
  board_progra_MovingAverage_Init(&localDW->MovingAverage_p);
}

/*
 * System reset for enable system:
 *    '<S5>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_progra_controlloPP1_Reset(DW_controlloPP1_board_program_T *localDW,
  P_controlloPP1_board_programm_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S28>/UD' */
  localDW->UD_DSTATE = localP->DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Sum: '<S26>/Sum1' incorporates:
   *  Delay: '<S26>/Delay'
   */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S29>/UD' */
  localDW->UD_DSTATE_g = localP->DiscreteDerivative_ICPrevScal_f;

  /* InitializeConditions for Sum: '<S27>/Sum1' incorporates:
   *  Delay: '<S27>/Delay'
   */
  localDW->Delay_DSTATE_k = localP->Delay_InitialCondition_o;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_n = localP->DiscreteTimeIntegrator_IC_a;
  localDW->DiscreteTimeIntegrator_PrevRe_p = 2;
  board_progr_MovingAverage_Reset(&localDW->MovingAverage);
  board_progr_MovingAverage_Reset(&localDW->MovingAverage_p);
}

/*
 * Disable for enable system:
 *    '<S5>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_prog_controlloPP1_Disable(DW_controlloPP1_board_program_T *localDW)
{
  localDW->controlloPP1_MODE = false;
}

/*
 * Start for enable system:
 *    '<S5>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_progra_controlloPP1_Start(DW_controlloPP1_board_program_T *localDW)
{
  localDW->controlloPP1_MODE = false;
  board_progr_MovingAverage_Start(&localDW->MovingAverage);
  board_progr_MovingAverage_Start(&localDW->MovingAverage_p);
}

/*
 * Output and update for enable system:
 *    '<S5>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_programmer_controlloPP1(boolean_T rtu_Enable, const real_T rtu_ref[2],
  const real_T rtu_pos[2], real_T rty_theta[2], B_controlloPP1_board_programm_T *
  localB, DW_controlloPP1_board_program_T *localDW,
  P_controlloPP1_board_programm_T *localP)
{
  /* local block i/o variables */
  real_T rtb_UnaryMinus_h;

  /* Outputs for Enabled SubSystem: '<S5>/controllo PP 1' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->controlloPP1_MODE) {
      board_progra_controlloPP1_Reset(localDW, localP);
      localDW->controlloPP1_MODE = true;
    }

    /* SampleTimeMath: '<S28>/TSamp'
     *
     * About '<S28>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TSamp_h = rtu_pos[0] * localP->TSamp_WtEt;

    /* UnaryMinus: '<S26>/Unary Minus' incorporates:
     *  Sum: '<S28>/Diff'
     *  UnitDelay: '<S28>/UD'
     */
    localB->UnaryMinus = -(localB->TSamp_h - localDW->UD_DSTATE);
    board_programmer_MovingAverage(localB->UnaryMinus, &localB->MovingAverage,
      &localDW->MovingAverage);

    /* Sum: '<S11>/Sum2' */
    localB->Sum2 = rtu_ref[0] - rtu_pos[0];

    /* SampleTimeMath: '<S29>/TSamp'
     *
     * About '<S29>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TSamp_e = rtu_pos[1] * localP->TSamp_WtEt_m;

    /* UnaryMinus: '<S27>/Unary Minus' incorporates:
     *  Sum: '<S29>/Diff'
     *  UnitDelay: '<S29>/UD'
     */
    rtb_UnaryMinus_h = -(localB->TSamp_e - localDW->UD_DSTATE_g);
    board_programmer_MovingAverage(rtb_UnaryMinus_h, &localB->MovingAverage_p,
      &localDW->MovingAverage_p);

    /* Sum: '<S11>/Sum3' */
    localB->Sum3_h = rtu_ref[1] - rtu_pos[1];

    /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
    if (localDW->DiscreteTimeIntegrator_PrevRese <= 0) {
      localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
    }

    /* Sum: '<S27>/Sum1' incorporates:
     *  Delay: '<S27>/Delay'
     *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
     *  Gain: '<S27>/x integration gain'
     *  Gain: '<S27>/x matrix gain'
     *  SignalConversion generated from: '<S27>/x matrix gain'
     */
    localDW->Delay_DSTATE_k = ((board_programmer_P.slow.Ky[0] *
      localB->MovingAverage_p.MovingAverage + board_programmer_P.slow.Ky[1] *
      localB->Sum3_h) + board_programmer_P.slow.Ky[2] * localDW->Delay_DSTATE_k)
      + board_programmer_P.slow.Kyi * localDW->DiscreteTimeIntegrator_DSTATE;

    /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
    if (localDW->DiscreteTimeIntegrator_PrevRe_p <= 0) {
      localDW->DiscreteTimeIntegrator_DSTATE_n =
        localP->DiscreteTimeIntegrator_IC_a;
    }

    /* Sum: '<S26>/Sum1' incorporates:
     *  Delay: '<S26>/Delay'
     *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
     *  Gain: '<S26>/x integration gain'
     *  Gain: '<S26>/x matrix gain'
     *  SignalConversion generated from: '<S26>/x matrix gain'
     */
    localDW->Delay_DSTATE = ((board_programmer_P.slow.Kx[0] *
      localB->MovingAverage.MovingAverage + board_programmer_P.slow.Kx[1] *
      localB->Sum2) + board_programmer_P.slow.Kx[2] * localDW->Delay_DSTATE) +
      board_programmer_P.slow.Kxi * localDW->DiscreteTimeIntegrator_DSTATE_n;

    /* SignalConversion generated from: '<S11>/theta' */
    rty_theta[0] = localDW->Delay_DSTATE;
    rty_theta[1] = localDW->Delay_DSTATE_k;

    /* Update for UnitDelay: '<S28>/UD' */
    localDW->UD_DSTATE = localB->TSamp_h;

    /* Update for UnitDelay: '<S29>/UD' */
    localDW->UD_DSTATE_g = localB->TSamp_e;

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * localB->Sum3_h;
    localDW->DiscreteTimeIntegrator_PrevRese = 1;

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE_n +=
      localP->DiscreteTimeIntegrator_gainva_k * localB->Sum2;
    localDW->DiscreteTimeIntegrator_PrevRe_p = 1;
  } else if (localDW->controlloPP1_MODE) {
    board_prog_controlloPP1_Disable(localDW);
  }

  /* End of Outputs for SubSystem: '<S5>/controllo PP 1' */
}

/*
 * Termination for enable system:
 *    '<S5>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_program_controlloPP1_Term(DW_controlloPP1_board_program_T *localDW)
{
  board_progra_MovingAverage_Term(&localDW->MovingAverage);
  board_progra_MovingAverage_Term(&localDW->MovingAverage_p);
}

/* System initialize for atomic system: */
void board_prog_MovingAverage_h_Init(DW_MovingAverage_board_prog_f_T *localDW)
{
  g_dsp_internal_SlidingWindo_l_T *obj;

  /* InitializeConditions for MATLABSystem: '<S6>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumSumRev[3] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S6>/Moving Average' */
}

/* Start for atomic system: */
void board_pro_MovingAverage_a_Start(DW_MovingAverage_board_prog_f_T *localDW)
{
  /* Start for MATLABSystem: '<S6>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

/* Output and update for atomic system: */
void board_programme_MovingAverage_p(real_T rtu_0,
  B_MovingAverage_board_progr_c_T *localB, DW_MovingAverage_board_prog_f_T
  *localDW)
{
  g_dsp_internal_SlidingWindo_l_T *obj;
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;

  /* MATLABSystem: '<S6>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumSumRev[3] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumSumRev[3] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  localB->csumrev[0] = obj->pCumSumRev[0];
  localB->csumrev[1] = obj->pCumSumRev[1];
  localB->csumrev[2] = obj->pCumSumRev[2];
  localB->csumrev[3] = obj->pCumSumRev[3];
  modValueRev = obj->pModValueRev;
  z = 0.0;

  /* MATLABSystem: '<S6>/Moving Average' */
  localB->MovingAverage = 0.0;

  /* MATLABSystem: '<S6>/Moving Average' */
  csum += rtu_0;
  if (modValueRev == 0.0) {
    z = localB->csumrev[(int32_T)cumRevIndex - 1] + csum;
  }

  localB->csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 4.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    localB->csumrev[2] += localB->csumrev[3];
    localB->csumrev[1] += localB->csumrev[2];
    localB->csumrev[0] += localB->csumrev[1];
  }

  if (modValueRev == 0.0) {
    /* MATLABSystem: '<S6>/Moving Average' */
    localB->MovingAverage = z / 5.0;
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = localB->csumrev[0];
  obj->pCumSumRev[1] = localB->csumrev[1];
  obj->pCumSumRev[2] = localB->csumrev[2];
  obj->pCumSumRev[3] = localB->csumrev[3];
  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }
}

/* Termination for atomic system: */
void board_prog_MovingAverage_e_Term(DW_MovingAverage_board_prog_f_T *localDW)
{
  g_dsp_internal_SlidingWindo_l_T *obj;

  /* Terminate for MATLABSystem: '<S6>/Moving Average' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Moving Average' */
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void ProtocolEncoderBase_get_DataTyp(uint8_T value[2])
{
  static const char_T tmp[5] = { 'u', 'i', 'n', 't', '8' };

  static const char_T tmp_0[5] = { 'i', 'n', 't', '6', '4' };

  static const char_T tmp_1[5] = { 'i', 'n', 't', '3', '2' };

  static const char_T tmp_2[5] = { 'i', 'n', 't', '1', '6' };

  for (board_programmer_B.b_i_m = 0; board_programmer_B.b_i_m < 5;
       board_programmer_B.b_i_m++) {
    board_programmer_B.c1 = tmp[board_programmer_B.b_i_m];
    board_programmer_B.c_c.f1[board_programmer_B.b_i_m] = board_programmer_B.c1;
    board_programmer_B.d_b.f1[board_programmer_B.b_i_m] = board_programmer_B.c1;
    board_programmer_B.e_f3[board_programmer_B.b_i_m] =
      tmp_0[board_programmer_B.b_i_m];
    board_programmer_B.f_f2[board_programmer_B.b_i_m] =
      tmp_1[board_programmer_B.b_i_m];
    board_programmer_B.g_f2[board_programmer_B.b_i_m] = board_programmer_B.c1;
    board_programmer_B.h_f1[board_programmer_B.b_i_m] =
      tmp_2[board_programmer_B.b_i_m];
  }

  for (board_programmer_B.b_i_m = 0; board_programmer_B.b_i_m < 2;
       board_programmer_B.b_i_m++) {
    board_programmer_B.b_c[0] = board_programmer_B.c_c;
    board_programmer_B.b_c[1] = board_programmer_B.d_b;
    board_programmer_B.ret_n = memcmp
      (&board_programmer_B.b_c[board_programmer_B.b_i_m].f1[0],
       &board_programmer_B.e_f3[0], 5);
    if (board_programmer_B.ret_n == 0) {
      board_programmer_B.ret_n = 0;
    } else {
      board_programmer_B.ret_n = memcmp
        (&board_programmer_B.b_c[board_programmer_B.b_i_m].f1[0],
         &board_programmer_B.f_f2[0], 5);
      if (board_programmer_B.ret_n == 0) {
        board_programmer_B.ret_n = 1;
      } else {
        board_programmer_B.ret_n = memcmp
          (&board_programmer_B.b_c[board_programmer_B.b_i_m].f1[0],
           &board_programmer_B.g_f2[0], 5);
        if (board_programmer_B.ret_n == 0) {
          board_programmer_B.ret_n = 2;
        } else {
          board_programmer_B.ret_n = memcmp
            (&board_programmer_B.b_c[board_programmer_B.b_i_m].f1[0],
             &board_programmer_B.h_f1[0], 5);
          if (board_programmer_B.ret_n == 0) {
            board_programmer_B.ret_n = 3;
          } else {
            board_programmer_B.ret_n = -1;
          }
        }
      }
    }

    switch (board_programmer_B.ret_n) {
     case 0:
      value[board_programmer_B.b_i_m] = 8U;
      break;

     case 1:
      value[board_programmer_B.b_i_m] = 4U;
      break;

     case 2:
      value[board_programmer_B.b_i_m] = 1U;
      break;

     case 3:
      value[board_programmer_B.b_i_m] = 2U;
      break;

     default:
      value[board_programmer_B.b_i_m] = 1U;
      break;
    }
  }
}

static void ProtocolEncoderBase_get_DataT_h(uint8_T value[5])
{
  static const char_T tmp[5] = { 'u', 'i', 'n', 't', '8' };

  static const char_T tmp_0[5] = { 'i', 'n', 't', '6', '4' };

  static const char_T tmp_1[5] = { 'i', 'n', 't', '3', '2' };

  static const char_T tmp_2[5] = { 'i', 'n', 't', '1', '6' };

  for (board_programmer_B.b_i = 0; board_programmer_B.b_i < 5;
       board_programmer_B.b_i++) {
    board_programmer_B.c_l = tmp[board_programmer_B.b_i];
    board_programmer_B.c.f1[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.d.f1[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.e.f1[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.f.f1[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.g.f1[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.h_f3[board_programmer_B.b_i] =
      tmp_0[board_programmer_B.b_i];
    board_programmer_B.j_f2[board_programmer_B.b_i] =
      tmp_1[board_programmer_B.b_i];
    board_programmer_B.k_f2[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.l_f1[board_programmer_B.b_i] =
      tmp_2[board_programmer_B.b_i];
  }

  for (board_programmer_B.b_i = 0; board_programmer_B.b_i < 5;
       board_programmer_B.b_i++) {
    board_programmer_B.b[0] = board_programmer_B.c;
    board_programmer_B.b[1] = board_programmer_B.d;
    board_programmer_B.b[2] = board_programmer_B.e;
    board_programmer_B.b[3] = board_programmer_B.f;
    board_programmer_B.b[4] = board_programmer_B.g;
    board_programmer_B.ret = memcmp(&board_programmer_B.b[board_programmer_B.b_i]
      .f1[0], &board_programmer_B.h_f3[0], 5);
    if (board_programmer_B.ret == 0) {
      board_programmer_B.ret = 0;
    } else {
      board_programmer_B.ret = memcmp
        (&board_programmer_B.b[board_programmer_B.b_i].f1[0],
         &board_programmer_B.j_f2[0], 5);
      if (board_programmer_B.ret == 0) {
        board_programmer_B.ret = 1;
      } else {
        board_programmer_B.ret = memcmp
          (&board_programmer_B.b[board_programmer_B.b_i].f1[0],
           &board_programmer_B.k_f2[0], 5);
        if (board_programmer_B.ret == 0) {
          board_programmer_B.ret = 2;
        } else {
          board_programmer_B.ret = memcmp
            (&board_programmer_B.b[board_programmer_B.b_i].f1[0],
             &board_programmer_B.l_f1[0], 5);
          if (board_programmer_B.ret == 0) {
            board_programmer_B.ret = 3;
          } else {
            board_programmer_B.ret = -1;
          }
        }
      }
    }

    switch (board_programmer_B.ret) {
     case 0:
      value[board_programmer_B.b_i] = 8U;
      break;

     case 1:
      value[board_programmer_B.b_i] = 4U;
      break;

     case 2:
      value[board_programmer_B.b_i] = 1U;
      break;

     case 3:
      value[board_programmer_B.b_i] = 2U;
      break;

     default:
      value[board_programmer_B.b_i] = 1U;
      break;
    }
  }
}

/* Model step function */
void board_programmer_step(void)
{
  static const int64m_T tmp = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_0 = { { 0U, 2147483648U }/* chunks */
  };

  /* MATLABSystem: '<S1>/Digital Input' */
  if (board_programmer_DW.obj_e.SampleTime !=
      board_programmer_P.DigitalInput_SampleTime) {
    board_programmer_DW.obj_e.SampleTime =
      board_programmer_P.DigitalInput_SampleTime;
  }

  board_programmer_B.rtb_DigitalInput_j = readDigitalPin(7);

  /* Logic: '<S1>/NOT1' incorporates:
   *  MATLABSystem: '<S1>/Digital Input'
   */
  board_programmer_B.NOT1 = !board_programmer_B.rtb_DigitalInput_j;

  /* MATLABSystem: '<S1>/Digital Input2' */
  if (board_programmer_DW.obj_lp.SampleTime !=
      board_programmer_P.DigitalInput2_SampleTime) {
    board_programmer_DW.obj_lp.SampleTime =
      board_programmer_P.DigitalInput2_SampleTime;
  }

  board_programmer_B.rtb_DigitalInput_j = readDigitalPin(51);

  /* CCaller: '<S37>/C Caller' */
  touchRead(&board_programmer_B.CCaller_o1, &board_programmer_B.CCaller_o2,
            &board_programmer_B.CCaller_o3);

  /* Gain: '<S4>/Gain2' */
  board_programmer_B.TSamp = board_programmer_P.touch.x.gain *
    4.398046511104E+12;
  board_programmer_B.TSamp_b = fabs(board_programmer_B.TSamp);
  if (board_programmer_B.TSamp_b < 4.503599627370496E+15) {
    if (board_programmer_B.TSamp_b >= 0.5) {
      board_programmer_B.TSamp = floor(board_programmer_B.TSamp + 0.5);
    } else {
      board_programmer_B.TSamp *= 0.0;
    }
  }

  if (board_programmer_B.TSamp < 2.147483648E+9) {
    if (board_programmer_B.TSamp >= -2.147483648E+9) {
      board_programmer_B.Sum_k = (uint32_T)(int32_T)board_programmer_B.TSamp;
    } else {
      board_programmer_B.Sum_k = 2147483648U;
    }
  } else {
    board_programmer_B.Sum_k = 2147483647U;
  }

  board_programmer_B.rtb_Sum_k_p = (uint32_T)board_programmer_B.CCaller_o1;
  sMultiWordMul(&board_programmer_B.Sum_k, 1, &board_programmer_B.rtb_Sum_k_p, 1,
                &board_programmer_B.Gain3.chunks[0U], 2);

  /* End of Gain: '<S4>/Gain2' */

  /* Bias: '<S4>/Bias2' */
  board_programmer_B.TSamp = board_programmer_P.touch.x.bias *
    4.398046511104E+12;
  board_programmer_B.TSamp_b = fabs(board_programmer_B.TSamp);
  if (board_programmer_B.TSamp_b < 4.503599627370496E+15) {
    if (board_programmer_B.TSamp_b >= 0.5) {
      board_programmer_B.TSamp = floor(board_programmer_B.TSamp + 0.5);
    } else {
      board_programmer_B.TSamp *= 0.0;
    }
  }

  if (board_programmer_B.TSamp < 9.2233720368547758E+18) {
    if (board_programmer_B.TSamp >= -9.2233720368547758E+18) {
      Double2MultiWord(board_programmer_B.TSamp, &board_programmer_B.r1.chunks
                       [0U], 2);
    } else {
      board_programmer_B.r1 = tmp_0;
    }
  } else {
    board_programmer_B.r1 = tmp;
  }

  MultiWordAdd(&board_programmer_B.Gain3.chunks[0U],
               &board_programmer_B.r1.chunks[0U],
               &board_programmer_B.Bias2.chunks[0U], 2);

  /* End of Bias: '<S4>/Bias2' */

  /* Gain: '<S4>/Gain3' */
  board_programmer_B.TSamp = board_programmer_P.touch.y.gain *
    4.398046511104E+12;
  board_programmer_B.TSamp_b = fabs(board_programmer_B.TSamp);
  if (board_programmer_B.TSamp_b < 4.503599627370496E+15) {
    if (board_programmer_B.TSamp_b >= 0.5) {
      board_programmer_B.TSamp = floor(board_programmer_B.TSamp + 0.5);
    } else {
      board_programmer_B.TSamp *= 0.0;
    }
  }

  if (board_programmer_B.TSamp < 2.147483648E+9) {
    if (board_programmer_B.TSamp >= -2.147483648E+9) {
      board_programmer_B.Sum_k = (uint32_T)(int32_T)board_programmer_B.TSamp;
    } else {
      board_programmer_B.Sum_k = 2147483648U;
    }
  } else {
    board_programmer_B.Sum_k = 2147483647U;
  }

  board_programmer_B.rtb_Sum_k_p = (uint32_T)board_programmer_B.CCaller_o2;
  sMultiWordMul(&board_programmer_B.Sum_k, 1, &board_programmer_B.rtb_Sum_k_p, 1,
                &board_programmer_B.Gain3.chunks[0U], 2);

  /* End of Gain: '<S4>/Gain3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  board_programmer_B.DataTypeConversion[0] = sMultiWord2Double
    (&board_programmer_B.Bias2.chunks[0U], 2, 0) * 2.2737367544323206E-13;

  /* Bias: '<S4>/Bias3' */
  board_programmer_B.TSamp = board_programmer_P.touch.y.bias *
    4.398046511104E+12;
  board_programmer_B.TSamp_b = fabs(board_programmer_B.TSamp);
  if (board_programmer_B.TSamp_b < 4.503599627370496E+15) {
    if (board_programmer_B.TSamp_b >= 0.5) {
      board_programmer_B.TSamp = floor(board_programmer_B.TSamp + 0.5);
    } else {
      board_programmer_B.TSamp *= 0.0;
    }
  }

  if (board_programmer_B.TSamp < 9.2233720368547758E+18) {
    if (board_programmer_B.TSamp >= -9.2233720368547758E+18) {
      Double2MultiWord(board_programmer_B.TSamp, &board_programmer_B.r.chunks[0U],
                       2);
    } else {
      board_programmer_B.r = tmp_0;
    }
  } else {
    board_programmer_B.r = tmp;
  }

  MultiWordAdd(&board_programmer_B.Gain3.chunks[0U],
               &board_programmer_B.r.chunks[0U], &board_programmer_B.r2.chunks
               [0U], 2);

  /* End of Bias: '<S4>/Bias3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  board_programmer_B.DataTypeConversion[1] = sMultiWord2Double
    (&board_programmer_B.r2.chunks[0U], 2, 0) * 2.2737367544323206E-13;

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S36>/Constant'
   */
  board_programmer_B.Compare = (board_programmer_B.CCaller_o3 >
    board_programmer_P.CompareToConstant_const);

  /* Outputs for Enabled SubSystem: '<Root>/Controllers' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (board_programmer_B.Compare) {
    board_programmer_DW.Controllers_MODE = true;

    /* SampleTimeMath: '<S30>/TSamp'
     *
     * About '<S30>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    board_programmer_B.TSamp = board_programmer_B.DataTypeConversion[0] *
      board_programmer_P.TSamp_WtEt;

    /* Sum: '<S30>/Diff' incorporates:
     *  UnitDelay: '<S30>/UD'
     */
    board_programmer_B.Diff = board_programmer_B.TSamp -
      board_programmer_DW.UD_DSTATE;
    board_programme_MovingAverage_p(board_programmer_B.Diff,
      &board_programmer_B.MovingAverage, &board_programmer_DW.MovingAverage);

    /* SampleTimeMath: '<S31>/TSamp'
     *
     * About '<S31>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    board_programmer_B.TSamp_b = board_programmer_B.DataTypeConversion[1] *
      board_programmer_P.TSamp_WtEt_g;

    /* Sum: '<S31>/Diff' incorporates:
     *  UnitDelay: '<S31>/UD'
     */
    board_programmer_B.Diff_k = board_programmer_B.TSamp_b -
      board_programmer_DW.UD_DSTATE_j;
    board_programme_MovingAverage_p(board_programmer_B.Diff_k,
      &board_programmer_B.MovingAverage1, &board_programmer_DW.MovingAverage1);

    /* CombinatorialLogic: '<S8>/Logic' incorporates:
     *  Constant: '<S5>/End Time Open'
     *  Delay: '<S5>/Delay1'
     *  Logic: '<S5>/NOT'
     *  Memory: '<S8>/Memory'
     *  RelationalOperator: '<S5>/Relational Operator'
     */
    board_programmer_B.rowIdx = (int32_T)(((((uint32_T)
      (board_programmer_P.EndTimeOpen_Value <= board_programmer_DW.Delay1_DSTATE)
      << 1) + !board_programmer_B.NOT1) << 1) +
      board_programmer_DW.Memory_PreviousInput);

    /* Outputs for Enabled SubSystem: '<S5>/Subsystem1' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    board_programmer_DW.Memory_PreviousInput = board_programmer_P.Logic_table
      [(uint32_T)board_programmer_B.rowIdx];
    if (board_programmer_DW.Memory_PreviousInput) {
      if (!board_programmer_DW.Subsystem1_MODE) {
        /* SystemReset for Atomic SubSystem: '<S10>/Timer with reset' */
        /* InitializeConditions for Delay: '<S22>/Delay1' */
        board_programmer_DW.Delay1_DSTATE_a =
          board_programmer_P.Delay1_InitialCondition;

        /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE =
          board_programmer_P.DiscreteTimeIntegrator_IC_c;
        board_programmer_DW.DiscreteTimeIntegrator_PrevRese = 2;

        /* End of SystemReset for SubSystem: '<S10>/Timer with reset' */
        board_programmer_DW.Subsystem1_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S10>/Timer with reset' */
      /* Logic: '<S22>/AND' incorporates:
       *  Constant: '<S10>/End Time Closed'
       *  Delay: '<S22>/Delay1'
       *  RelationalOperator: '<S22>/Relational Operator'
       */
      board_programmer_B.AND_e = (board_programmer_DW.Delay1_DSTATE_a >=
        board_programmer_P.EndTimeClosed_Value);

      /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
      if ((board_programmer_B.AND_e &&
           (board_programmer_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
          ((!board_programmer_B.AND_e) &&
           (board_programmer_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE =
          board_programmer_P.DiscreteTimeIntegrator_IC_c;
      }

      board_programmer_B.DiscreteTimeIntegrator_k =
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE;

      /* Update for Delay: '<S22>/Delay1' incorporates:
       *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
       */
      board_programmer_DW.Delay1_DSTATE_a =
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE;

      /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S22>/Constant'
       */
      board_programmer_DW.DiscreteTimeIntegrator_DSTATE +=
        board_programmer_P.DiscreteTimeIntegrator_gainva_j *
        board_programmer_P.Constant_Value_c;
      board_programmer_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
        board_programmer_B.AND_e;

      /* End of Outputs for SubSystem: '<S10>/Timer with reset' */

      /* Gain: '<S10>/Gain1' */
      board_programmer_B.DiscreteTimeIntegrator_k *= 1.0 / board_programmer_P.h;

      /* PreLookup: '<S10>/Prelookup1' */
      board_programmer_B.Sum_k = plook_lincg
        (board_programmer_B.DiscreteTimeIntegrator_k,
         board_programmer_P.Prelookup1_BreakpointsData, 80U,
         &board_programmer_B.DiscreteTimeIntegrator_k);

      /* LookupNDDirect: '<S23>/[0]' incorporates:
       *  Sum: '<S18>/Sum'
       *
       * About '<S23>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset = (int32_T)board_programmer_B.rtb_Sum_k_p <<
        3;

      /* Sum: '<S23>/Sum' incorporates:
       *  Constant: '<S23>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_i;
      if (board_programmer_B.rtb_Sum_k_p < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_p = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S23>/[1]' incorporates:
       *  Sum: '<S23>/Sum'
       *
       * About '<S23>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_p > 80U) {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_p = (int32_T)board_programmer_B.rtb_Sum_k_p
        << 3;

      /* LookupNDDirect: '<S24>/[0]' incorporates:
       *  Sum: '<S18>/Sum'
       *
       * About '<S24>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_c = (int32_T)board_programmer_B.rtb_Sum_k_p
        << 2;

      /* Sum: '<S24>/Sum' incorporates:
       *  Constant: '<S24>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_m;
      if (board_programmer_B.rtb_Sum_k_p < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_p = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S24>/[1]' incorporates:
       *  Sum: '<S24>/Sum'
       *
       * About '<S24>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_p > 80U) {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_f = (int32_T)board_programmer_B.rtb_Sum_k_p
        << 2;

      /* LookupNDDirect: '<S25>/[0]' incorporates:
       *  Sum: '<S18>/Sum'
       *
       * About '<S25>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_g = (int32_T)board_programmer_B.rtb_Sum_k_p
        << 1;

      /* Sum: '<S25>/Sum' incorporates:
       *  Constant: '<S25>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_j;
      if (board_programmer_B.rtb_Sum_k_p < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_p = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S25>/[1]' incorporates:
       *  Sum: '<S25>/Sum'
       *
       * About '<S25>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_p > 80U) {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_g1 = (int32_T)
        board_programmer_B.rtb_Sum_k_p << 1;
      for (board_programmer_B.qY = 0; board_programmer_B.qY < 8;
           board_programmer_B.qY++) {
        /* Sum: '<S23>/Sum3' incorporates:
         *  Fcn: '<S23>/Fcn'
         *  LookupNDDirect: '<S23>/[0]'
         *  LookupNDDirect: '<S23>/[1]'
         *  Product: '<S23>/1-lambda_x'
         *  Product: '<S23>/lambda_x.'
         *
         * About '<S23>/[0]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         *
         * About '<S23>/[1]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        board_programmer_B.dv[board_programmer_B.qY] = (1.0 -
          board_programmer_B.DiscreteTimeIntegrator_k) *
          board_programmer_P.circ1.open.lqr.K[board_programmer_B.qY +
          board_programmer_B.tableOffset] +
          board_programmer_P.circ1.open.lqr.K[board_programmer_B.qY +
          board_programmer_B.tableOffset_p] *
          board_programmer_B.DiscreteTimeIntegrator_k;
      }

      /* Sum: '<S10>/Sum2' incorporates:
       *  Fcn: '<S24>/Fcn'
       *  LookupNDDirect: '<S24>/[0]'
       *  LookupNDDirect: '<S24>/[1]'
       *  Product: '<S24>/1-lambda_x'
       *  Product: '<S24>/lambda_x.'
       *  Sum: '<S24>/Sum3'
       *
       * About '<S24>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       *
       * About '<S24>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      board_programmer_B.unnamed_idx_0 = ((1.0 -
        board_programmer_B.DiscreteTimeIntegrator_k) *
        board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_c] +
        board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_f] *
        board_programmer_B.DiscreteTimeIntegrator_k) -
        board_programmer_B.MovingAverage.MovingAverage;
      board_programmer_B.unnamed_idx_1 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_c +
         1] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_k) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_f +
         1] * board_programmer_B.DiscreteTimeIntegrator_k) -
        board_programmer_B.DataTypeConversion[0];
      board_programmer_B.unnamed_idx_2 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_c +
         2] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_k) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_f +
         2] * board_programmer_B.DiscreteTimeIntegrator_k) -
        board_programmer_B.MovingAverage1.MovingAverage;
      board_programmer_B.unnamed_idx_3 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_c +
         3] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_k) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_f +
         3] * board_programmer_B.DiscreteTimeIntegrator_k) -
        board_programmer_B.DataTypeConversion[1];
      for (board_programmer_B.qY = 0; board_programmer_B.qY < 2;
           board_programmer_B.qY++) {
        /* Merge: '<Root>/Merge' incorporates:
         *  Fcn: '<S25>/Fcn'
         *  LookupNDDirect: '<S25>/[0]'
         *  LookupNDDirect: '<S25>/[1]'
         *  Product: '<S10>/Matrix Multiply1'
         *  Product: '<S25>/1-lambda_x'
         *  Product: '<S25>/lambda_x.'
         *  Sum: '<S10>/Sum3'
         *  Sum: '<S25>/Sum3'
         *
         * About '<S25>/[0]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         *
         * About '<S25>/[1]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        board_programmer_B.Merge[board_programmer_B.qY] =
          (((board_programmer_B.dv[board_programmer_B.qY + 2] *
             board_programmer_B.unnamed_idx_1 +
             board_programmer_B.dv[board_programmer_B.qY] *
             board_programmer_B.unnamed_idx_0) +
            board_programmer_B.dv[board_programmer_B.qY + 4] *
            board_programmer_B.unnamed_idx_2) +
           board_programmer_B.dv[board_programmer_B.qY + 6] *
           board_programmer_B.unnamed_idx_3) +
          (board_programmer_P.circ1.open.lqr.uk[board_programmer_B.qY +
           board_programmer_B.tableOffset_g] * (1.0 -
            board_programmer_B.DiscreteTimeIntegrator_k) +
           board_programmer_P.circ1.open.lqr.uk[board_programmer_B.qY +
           board_programmer_B.tableOffset_g1] *
           board_programmer_B.DiscreteTimeIntegrator_k);
      }
    } else {
      board_programmer_DW.Subsystem1_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S5>/Subsystem1' */

    /* Logic: '<S5>/AND' incorporates:
     *  CombinatorialLogic: '<S8>/Logic'
     */
    board_programmer_B.NOT1 =
      (board_programmer_P.Logic_table[board_programmer_B.rowIdx + 8U] &&
       board_programmer_B.NOT1);

    /* Outputs for Enabled SubSystem: '<S5>/Subsystem' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    if (board_programmer_B.NOT1) {
      if (!board_programmer_DW.Subsystem_MODE) {
        /* SystemReset for Atomic SubSystem: '<S9>/Timer ' */
        /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o =
          board_programmer_P.DiscreteTimeIntegrator_IC;
        board_programmer_DW.DiscreteTimeIntegrator_PrevRe_a = 2;

        /* End of SystemReset for SubSystem: '<S9>/Timer ' */
        board_programmer_DW.Subsystem_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S9>/Timer ' */
      /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
      if (board_programmer_DW.DiscreteTimeIntegrator_PrevRe_a <= 0) {
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o =
          board_programmer_P.DiscreteTimeIntegrator_IC;
      }

      /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
      board_programmer_B.DiscreteTimeIntegrator =
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o;

      /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S15>/Constant'
       */
      board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o +=
        board_programmer_P.DiscreteTimeIntegrator_gainval *
        board_programmer_P.Constant_Value;
      board_programmer_DW.DiscreteTimeIntegrator_PrevRe_a = 1;

      /* End of Outputs for SubSystem: '<S9>/Timer ' */

      /* Gain: '<S9>/Gain' */
      board_programmer_B.DiscreteTimeIntegrator_k = 1.0 / board_programmer_P.h *
        board_programmer_B.DiscreteTimeIntegrator;

      /* PreLookup: '<S9>/Prelookup2' */
      board_programmer_B.Sum_k = plook_lincg
        (board_programmer_B.DiscreteTimeIntegrator_k,
         board_programmer_P.Prelookup2_BreakpointsData, 80U,
         &board_programmer_B.DiscreteTimeIntegrator_k);

      /* LookupNDDirect: '<S16>/[0]' incorporates:
       *  PreLookup: '<S9>/Prelookup2'
       *
       * About '<S16>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset = (int32_T)board_programmer_B.rtb_Sum_k_p <<
        3;

      /* Sum: '<S16>/Sum' incorporates:
       *  Constant: '<S16>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value;
      if (board_programmer_B.rtb_Sum_k_p < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_p = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S16>/[1]' incorporates:
       *  Sum: '<S16>/Sum'
       *
       * About '<S16>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_p > 80U) {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_p = (int32_T)board_programmer_B.rtb_Sum_k_p
        << 3;

      /* LookupNDDirect: '<S17>/[0]' incorporates:
       *  PreLookup: '<S9>/Prelookup2'
       *
       * About '<S17>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_c = (int32_T)board_programmer_B.rtb_Sum_k_p
        << 2;

      /* Sum: '<S17>/Sum' incorporates:
       *  Constant: '<S17>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_g;
      if (board_programmer_B.rtb_Sum_k_p < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_p = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S17>/[1]' incorporates:
       *  Sum: '<S17>/Sum'
       *
       * About '<S17>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_p > 80U) {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_f = (int32_T)board_programmer_B.rtb_Sum_k_p
        << 2;

      /* LookupNDDirect: '<S18>/[0]' incorporates:
       *  PreLookup: '<S9>/Prelookup2'
       *
       * About '<S18>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_g = (int32_T)board_programmer_B.rtb_Sum_k_p
        << 1;

      /* Sum: '<S18>/Sum' incorporates:
       *  Constant: '<S18>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_p = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_a;
      if (board_programmer_B.rtb_Sum_k_p < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_p = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S18>/[1]' incorporates:
       *  Sum: '<S18>/Sum'
       *
       * About '<S18>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_p > 80U) {
        board_programmer_B.rtb_Sum_k_p = 80U;
      }

      board_programmer_B.tableOffset_g1 = (int32_T)
        board_programmer_B.rtb_Sum_k_p << 1;
      for (board_programmer_B.qY = 0; board_programmer_B.qY < 8;
           board_programmer_B.qY++) {
        /* Sum: '<S16>/Sum3' incorporates:
         *  Fcn: '<S16>/Fcn'
         *  LookupNDDirect: '<S16>/[0]'
         *  LookupNDDirect: '<S16>/[1]'
         *  Product: '<S16>/1-lambda_x'
         *  Product: '<S16>/lambda_x.'
         *
         * About '<S16>/[0]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         *
         * About '<S16>/[1]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        board_programmer_B.dv[board_programmer_B.qY] = (1.0 -
          board_programmer_B.DiscreteTimeIntegrator_k) *
          board_programmer_P.circ1.open.lqr.K[board_programmer_B.qY +
          board_programmer_B.tableOffset] +
          board_programmer_P.circ1.open.lqr.K[board_programmer_B.qY +
          board_programmer_B.tableOffset_p] *
          board_programmer_B.DiscreteTimeIntegrator_k;
      }

      /* Sum: '<S9>/Sum' incorporates:
       *  Fcn: '<S17>/Fcn'
       *  LookupNDDirect: '<S17>/[0]'
       *  LookupNDDirect: '<S17>/[1]'
       *  Product: '<S17>/1-lambda_x'
       *  Product: '<S17>/lambda_x.'
       *  Sum: '<S17>/Sum3'
       *
       * About '<S17>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       *
       * About '<S17>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      board_programmer_B.unnamed_idx_0 = ((1.0 -
        board_programmer_B.DiscreteTimeIntegrator_k) *
        board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_c] +
        board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_f] *
        board_programmer_B.DiscreteTimeIntegrator_k) -
        board_programmer_B.MovingAverage.MovingAverage;
      board_programmer_B.unnamed_idx_1 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_c +
         1] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_k) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_f +
         1] * board_programmer_B.DiscreteTimeIntegrator_k) -
        board_programmer_B.DataTypeConversion[0];
      board_programmer_B.unnamed_idx_2 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_c +
         2] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_k) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_f +
         2] * board_programmer_B.DiscreteTimeIntegrator_k) -
        board_programmer_B.MovingAverage1.MovingAverage;
      board_programmer_B.unnamed_idx_3 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_c +
         3] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_k) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_f +
         3] * board_programmer_B.DiscreteTimeIntegrator_k) -
        board_programmer_B.DataTypeConversion[1];
      for (board_programmer_B.qY = 0; board_programmer_B.qY < 2;
           board_programmer_B.qY++) {
        /* Merge: '<Root>/Merge' incorporates:
         *  Fcn: '<S18>/Fcn'
         *  LookupNDDirect: '<S18>/[0]'
         *  LookupNDDirect: '<S18>/[1]'
         *  Product: '<S18>/1-lambda_x'
         *  Product: '<S18>/lambda_x.'
         *  Product: '<S9>/Matrix Multiply'
         *  Sum: '<S18>/Sum3'
         *  Sum: '<S9>/Sum1'
         *
         * About '<S18>/[0]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         *
         * About '<S18>/[1]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        board_programmer_B.Merge[board_programmer_B.qY] =
          (((board_programmer_B.dv[board_programmer_B.qY + 2] *
             board_programmer_B.unnamed_idx_1 +
             board_programmer_B.dv[board_programmer_B.qY] *
             board_programmer_B.unnamed_idx_0) +
            board_programmer_B.dv[board_programmer_B.qY + 4] *
            board_programmer_B.unnamed_idx_2) +
           board_programmer_B.dv[board_programmer_B.qY + 6] *
           board_programmer_B.unnamed_idx_3) +
          (board_programmer_P.circ1.open.lqr.uk[board_programmer_B.qY +
           board_programmer_B.tableOffset_g] * (1.0 -
            board_programmer_B.DiscreteTimeIntegrator_k) +
           board_programmer_P.circ1.open.lqr.uk[board_programmer_B.qY +
           board_programmer_B.tableOffset_g1] *
           board_programmer_B.DiscreteTimeIntegrator_k);
      }
    } else {
      board_programmer_DW.Subsystem_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S5>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S5>/controllo PP 1' */
    /* Logic: '<S5>/AND1' incorporates:
     *  Constant: '<S5>/Constant1'
     *  Logic: '<S5>/NOT1'
     *  Logic: '<S5>/NOT2'
     */
    board_programmer_controlloPP1((!board_programmer_DW.Memory_PreviousInput) &&
      (!board_programmer_B.NOT1), board_programmer_P.circ1.open.lqr.start,
      board_programmer_B.DataTypeConversion, board_programmer_B.Merge,
      &board_programmer_B.controlloPP1, &board_programmer_DW.controlloPP1,
      &board_programmer_P.controlloPP1);

    /* End of Outputs for SubSystem: '<S5>/controllo PP 1' */

    /* Outputs for Enabled SubSystem: '<S2>/controllo PP 1' */
    /* Logic: '<S1>/NOT3' incorporates:
     *  Constant: '<S2>/Constant'
     *  MATLABSystem: '<S1>/Digital Input2'
     */
    board_programmer_controlloPP1(!board_programmer_B.rtb_DigitalInput_j,
      board_programmer_P.Constant_Value_m, board_programmer_B.DataTypeConversion,
      board_programmer_B.Merge, &board_programmer_B.controlloPP1_d,
      &board_programmer_DW.controlloPP1_d, &board_programmer_P.controlloPP1_d);

    /* End of Outputs for SubSystem: '<S2>/controllo PP 1' */

    /* Update for UnitDelay: '<S30>/UD' */
    board_programmer_DW.UD_DSTATE = board_programmer_B.TSamp;

    /* Update for UnitDelay: '<S31>/UD' */
    board_programmer_DW.UD_DSTATE_j = board_programmer_B.TSamp_b;

    /* Update for Delay: '<S5>/Delay1' */
    board_programmer_DW.Delay1_DSTATE =
      board_programmer_B.DiscreteTimeIntegrator;
  } else if (board_programmer_DW.Controllers_MODE) {
    /* Disable for Enabled SubSystem: '<S5>/Subsystem1' */
    board_programmer_DW.Subsystem1_MODE = false;

    /* End of Disable for SubSystem: '<S5>/Subsystem1' */

    /* Disable for Enabled SubSystem: '<S5>/Subsystem' */
    board_programmer_DW.Subsystem_MODE = false;

    /* End of Disable for SubSystem: '<S5>/Subsystem' */

    /* Disable for Enabled SubSystem: '<S5>/controllo PP 1' */
    if (board_programmer_DW.controlloPP1.controlloPP1_MODE) {
      board_prog_controlloPP1_Disable(&board_programmer_DW.controlloPP1);
    }

    /* End of Disable for SubSystem: '<S5>/controllo PP 1' */

    /* Disable for Enabled SubSystem: '<S2>/controllo PP 1' */
    if (board_programmer_DW.controlloPP1_d.controlloPP1_MODE) {
      board_prog_controlloPP1_Disable(&board_programmer_DW.controlloPP1_d);
    }

    /* End of Disable for SubSystem: '<S2>/controllo PP 1' */
    board_programmer_DW.Controllers_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/Controllers' */

  /* MATLABSystem: '<S1>/Digital Input1' */
  if (board_programmer_DW.obj_i.SampleTime !=
      board_programmer_P.DigitalInput1_SampleTime) {
    board_programmer_DW.obj_i.SampleTime =
      board_programmer_P.DigitalInput1_SampleTime;
  }

  board_programmer_B.NOT1 = readDigitalPin(53);

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* Logic: '<Root>/OR' incorporates:
   *  Logic: '<Root>/NOT'
   *  Logic: '<S1>/AND'
   *  Logic: '<S1>/NOT4'
   *  MATLABSystem: '<S1>/Digital Input1'
   *  MATLABSystem: '<S1>/Digital Input2'
   */
  if ((!board_programmer_B.NOT1) || (!board_programmer_B.rtb_DigitalInput_j) ||
      (!board_programmer_B.Compare)) {
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S3>/Constant1'
     *  SignalConversion generated from: '<S3>/theta'
     */
    board_programmer_B.Merge[0] = board_programmer_P.Constant1_Value[0];
    board_programmer_B.Merge[1] = board_programmer_P.Constant1_Value[1];
  }

  /* End of Logic: '<Root>/OR' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* DataTypeConversion: '<S37>/Data Type Conversion3' incorporates:
   *  Bias: '<S4>/Bias'
   *  Gain: '<S4>/Gain'
   */
  board_programmer_B.TSamp = rt_roundd_snf
    (board_programmer_P.pwm.thX.real2raw_gain * board_programmer_B.Merge[0] +
     board_programmer_P.pwm.thX.real2raw_bias);
  if (rtIsNaN(board_programmer_B.TSamp) || rtIsInf(board_programmer_B.TSamp)) {
    board_programmer_B.TSamp = 0.0;
  } else {
    board_programmer_B.TSamp = fmod(board_programmer_B.TSamp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S37>/Data Type Conversion3' */
  board_programmer_B.DataTypeConversion3 = board_programmer_B.TSamp < 0.0 ?
    -(int32_T)(uint32_T)-board_programmer_B.TSamp : (int32_T)(uint32_T)
    board_programmer_B.TSamp;

  /* S-Function (double2ascii): '<S37>/C//C++ Code Block3' */
  double2ascii_Outputs_wrapper(&board_programmer_B.DataTypeConversion3,
    &board_programmer_B.CCCodeBlock3[0]);

  /* DataTypeConversion: '<S37>/Data Type Conversion4' incorporates:
   *  Bias: '<S4>/Bias1'
   *  Gain: '<S4>/Gain1'
   */
  board_programmer_B.TSamp = rt_roundd_snf
    (board_programmer_P.pwm.thY.real2raw_gain * board_programmer_B.Merge[1] +
     board_programmer_P.pwm.thY.real2raw_bias);
  if (rtIsNaN(board_programmer_B.TSamp) || rtIsInf(board_programmer_B.TSamp)) {
    board_programmer_B.TSamp = 0.0;
  } else {
    board_programmer_B.TSamp = fmod(board_programmer_B.TSamp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S37>/Data Type Conversion4' */
  board_programmer_B.DataTypeConversion4 = board_programmer_B.TSamp < 0.0 ?
    -(int32_T)(uint32_T)-board_programmer_B.TSamp : (int32_T)(uint32_T)
    board_programmer_B.TSamp;

  /* S-Function (double2ascii): '<S37>/C//C++ Code Block4' */
  double2ascii_Outputs_wrapper(&board_programmer_B.DataTypeConversion4,
    &board_programmer_B.CCCodeBlock4[0]);

  /* S-Function (double2ascii): '<S37>/C//C++ Code Block5' */
  double2ascii_Outputs_wrapper(&board_programmer_B.CCaller_o1,
    &board_programmer_B.CCCodeBlock5[0]);

  /* S-Function (double2ascii): '<S37>/C//C++ Code Block6' */
  double2ascii_Outputs_wrapper(&board_programmer_B.CCaller_o2,
    &board_programmer_B.CCCodeBlock6[0]);

  /* S-Function (double2ascii): '<S37>/C//C++ Code Block7' */
  double2ascii_Outputs_wrapper(&board_programmer_B.CCaller_o3,
    &board_programmer_B.CCCodeBlock7[0]);

  /* MATLABSystem: '<S37>/Protocol Encoder2' incorporates:
   *  MATLABSystem: '<S37>/Serial Transmit2'
   *  S-Function (double2ascii): '<S37>/C//C++ Code Block3'
   *  S-Function (double2ascii): '<S37>/C//C++ Code Block4'
   *  S-Function (double2ascii): '<S37>/C//C++ Code Block5'
   *  S-Function (double2ascii): '<S37>/C//C++ Code Block6'
   *  S-Function (double2ascii): '<S37>/C//C++ Code Block7'
   */
  if (board_programmer_DW.obj.TunablePropsChanged) {
    board_programmer_DW.obj.TunablePropsChanged = false;
  }

  board_programmer_B.dataIn[0] = 64U;
  board_programmer_B.inDataIdx = 1U;
  board_programmer_B.dataIn[1] = 0U;
  board_programmer_B.dataIn[2] = 0U;
  board_programmer_B.dataIn[3] = 0U;
  board_programmer_B.dataIn[4] = 0U;
  board_programmer_B.outIdx = 1U;
  while (board_programmer_B.inDataIdx <= 4) {
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[0];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.qY = (int32_T)(board_programmer_B.Sum_k - 1U);
    if (board_programmer_B.Sum_k - 1U > board_programmer_B.Sum_k) {
      board_programmer_B.qY = 0;
    }

    if (board_programmer_B.outIdx > (uint16_T)board_programmer_B.qY) {
      board_programmer_B.rowIdx = 0;
      board_programmer_B.qY = 0;
    } else {
      board_programmer_B.rowIdx = board_programmer_B.outIdx - 1;
      board_programmer_B.qY = (uint16_T)board_programmer_B.qY;
    }

    board_programmer_B.uv1[0] = board_programmer_B.dataIn[1];
    board_programmer_B.uv1[1] = board_programmer_B.dataIn[2];
    board_programmer_B.uv1[2] = board_programmer_B.dataIn[3];
    board_programmer_B.uv1[3] = board_programmer_B.dataIn[4];
    board_programmer_B.tableOffset = board_programmer_B.qY -
      board_programmer_B.rowIdx;
    for (board_programmer_B.qY = 0; board_programmer_B.qY <
         board_programmer_B.tableOffset; board_programmer_B.qY++) {
      board_programmer_B.uv1[board_programmer_B.rowIdx + board_programmer_B.qY] =
        board_programmer_B.CCCodeBlock3[board_programmer_B.inDataIdx - 1];
    }

    board_programmer_B.dataIn[1] = board_programmer_B.uv1[0];
    board_programmer_B.dataIn[2] = board_programmer_B.uv1[1];
    board_programmer_B.dataIn[3] = board_programmer_B.uv1[2];
    board_programmer_B.dataIn[4] = board_programmer_B.uv1[3];
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[0];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.outIdx = (uint16_T)board_programmer_B.Sum_k;
    board_programmer_B.inDataIdx++;
  }

  board_programmer_B.inDataIdx = 1U;
  board_programmer_B.dataIn[5] = 0U;
  board_programmer_B.dataIn[6] = 0U;
  board_programmer_B.dataIn[7] = 0U;
  board_programmer_B.dataIn[8] = 0U;
  board_programmer_B.outIdx = 1U;
  while (board_programmer_B.inDataIdx <= 4) {
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[1];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.qY = (int32_T)(board_programmer_B.Sum_k - 1U);
    if (board_programmer_B.Sum_k - 1U > board_programmer_B.Sum_k) {
      board_programmer_B.qY = 0;
    }

    if (board_programmer_B.outIdx > (uint16_T)board_programmer_B.qY) {
      board_programmer_B.rowIdx = 0;
      board_programmer_B.qY = 0;
    } else {
      board_programmer_B.rowIdx = board_programmer_B.outIdx - 1;
      board_programmer_B.qY = (uint16_T)board_programmer_B.qY;
    }

    board_programmer_B.uv1[0] = board_programmer_B.dataIn[5];
    board_programmer_B.uv1[1] = board_programmer_B.dataIn[6];
    board_programmer_B.uv1[2] = board_programmer_B.dataIn[7];
    board_programmer_B.uv1[3] = board_programmer_B.dataIn[8];
    board_programmer_B.tableOffset = board_programmer_B.qY -
      board_programmer_B.rowIdx;
    for (board_programmer_B.qY = 0; board_programmer_B.qY <
         board_programmer_B.tableOffset; board_programmer_B.qY++) {
      board_programmer_B.uv1[board_programmer_B.rowIdx + board_programmer_B.qY] =
        board_programmer_B.CCCodeBlock4[board_programmer_B.inDataIdx - 1];
    }

    board_programmer_B.dataIn[5] = board_programmer_B.uv1[0];
    board_programmer_B.dataIn[6] = board_programmer_B.uv1[1];
    board_programmer_B.dataIn[7] = board_programmer_B.uv1[2];
    board_programmer_B.dataIn[8] = board_programmer_B.uv1[3];
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[1];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.outIdx = (uint16_T)board_programmer_B.Sum_k;
    board_programmer_B.inDataIdx++;
  }

  board_programmer_B.inDataIdx = 1U;
  board_programmer_B.dataIn[9] = 0U;
  board_programmer_B.dataIn[10] = 0U;
  board_programmer_B.dataIn[11] = 0U;
  board_programmer_B.dataIn[12] = 0U;
  board_programmer_B.outIdx = 1U;
  while (board_programmer_B.inDataIdx <= 4) {
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[2];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.qY = (int32_T)(board_programmer_B.Sum_k - 1U);
    if (board_programmer_B.Sum_k - 1U > board_programmer_B.Sum_k) {
      board_programmer_B.qY = 0;
    }

    if (board_programmer_B.outIdx > (uint16_T)board_programmer_B.qY) {
      board_programmer_B.rowIdx = 0;
      board_programmer_B.qY = 0;
    } else {
      board_programmer_B.rowIdx = board_programmer_B.outIdx - 1;
      board_programmer_B.qY = (uint16_T)board_programmer_B.qY;
    }

    board_programmer_B.uv1[0] = board_programmer_B.dataIn[9];
    board_programmer_B.uv1[1] = board_programmer_B.dataIn[10];
    board_programmer_B.uv1[2] = board_programmer_B.dataIn[11];
    board_programmer_B.uv1[3] = board_programmer_B.dataIn[12];
    board_programmer_B.tableOffset = board_programmer_B.qY -
      board_programmer_B.rowIdx;
    for (board_programmer_B.qY = 0; board_programmer_B.qY <
         board_programmer_B.tableOffset; board_programmer_B.qY++) {
      board_programmer_B.uv1[board_programmer_B.rowIdx + board_programmer_B.qY] =
        board_programmer_B.CCCodeBlock5[board_programmer_B.inDataIdx - 1];
    }

    board_programmer_B.dataIn[9] = board_programmer_B.uv1[0];
    board_programmer_B.dataIn[10] = board_programmer_B.uv1[1];
    board_programmer_B.dataIn[11] = board_programmer_B.uv1[2];
    board_programmer_B.dataIn[12] = board_programmer_B.uv1[3];
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[2];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.outIdx = (uint16_T)board_programmer_B.Sum_k;
    board_programmer_B.inDataIdx++;
  }

  board_programmer_B.inDataIdx = 1U;
  board_programmer_B.dataIn[13] = 0U;
  board_programmer_B.dataIn[14] = 0U;
  board_programmer_B.dataIn[15] = 0U;
  board_programmer_B.dataIn[16] = 0U;
  board_programmer_B.outIdx = 1U;
  while (board_programmer_B.inDataIdx <= 4) {
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[3];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.qY = (int32_T)(board_programmer_B.Sum_k - 1U);
    if (board_programmer_B.Sum_k - 1U > board_programmer_B.Sum_k) {
      board_programmer_B.qY = 0;
    }

    if (board_programmer_B.outIdx > (uint16_T)board_programmer_B.qY) {
      board_programmer_B.rowIdx = 0;
      board_programmer_B.qY = 0;
    } else {
      board_programmer_B.rowIdx = board_programmer_B.outIdx - 1;
      board_programmer_B.qY = (uint16_T)board_programmer_B.qY;
    }

    board_programmer_B.uv1[0] = board_programmer_B.dataIn[13];
    board_programmer_B.uv1[1] = board_programmer_B.dataIn[14];
    board_programmer_B.uv1[2] = board_programmer_B.dataIn[15];
    board_programmer_B.uv1[3] = board_programmer_B.dataIn[16];
    board_programmer_B.tableOffset = board_programmer_B.qY -
      board_programmer_B.rowIdx;
    for (board_programmer_B.qY = 0; board_programmer_B.qY <
         board_programmer_B.tableOffset; board_programmer_B.qY++) {
      board_programmer_B.uv1[board_programmer_B.rowIdx + board_programmer_B.qY] =
        board_programmer_B.CCCodeBlock6[board_programmer_B.inDataIdx - 1];
    }

    board_programmer_B.dataIn[13] = board_programmer_B.uv1[0];
    board_programmer_B.dataIn[14] = board_programmer_B.uv1[1];
    board_programmer_B.dataIn[15] = board_programmer_B.uv1[2];
    board_programmer_B.dataIn[16] = board_programmer_B.uv1[3];
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[3];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.outIdx = (uint16_T)board_programmer_B.Sum_k;
    board_programmer_B.inDataIdx++;
  }

  board_programmer_B.inDataIdx = 1U;
  board_programmer_B.dataIn[17] = 0U;
  board_programmer_B.dataIn[18] = 0U;
  board_programmer_B.dataIn[19] = 0U;
  board_programmer_B.dataIn[20] = 0U;
  board_programmer_B.outIdx = 1U;
  while (board_programmer_B.inDataIdx <= 4) {
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[4];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.qY = (int32_T)(board_programmer_B.Sum_k - 1U);
    if (board_programmer_B.Sum_k - 1U > board_programmer_B.Sum_k) {
      board_programmer_B.qY = 0;
    }

    if (board_programmer_B.outIdx > (uint16_T)board_programmer_B.qY) {
      board_programmer_B.rowIdx = 0;
      board_programmer_B.qY = 0;
    } else {
      board_programmer_B.rowIdx = board_programmer_B.outIdx - 1;
      board_programmer_B.qY = (uint16_T)board_programmer_B.qY;
    }

    board_programmer_B.uv1[0] = board_programmer_B.dataIn[17];
    board_programmer_B.uv1[1] = board_programmer_B.dataIn[18];
    board_programmer_B.uv1[2] = board_programmer_B.dataIn[19];
    board_programmer_B.uv1[3] = board_programmer_B.dataIn[20];
    board_programmer_B.tableOffset = board_programmer_B.qY -
      board_programmer_B.rowIdx;
    for (board_programmer_B.qY = 0; board_programmer_B.qY <
         board_programmer_B.tableOffset; board_programmer_B.qY++) {
      board_programmer_B.uv1[board_programmer_B.rowIdx + board_programmer_B.qY] =
        board_programmer_B.CCCodeBlock7[board_programmer_B.inDataIdx - 1];
    }

    board_programmer_B.dataIn[17] = board_programmer_B.uv1[0];
    board_programmer_B.dataIn[18] = board_programmer_B.uv1[1];
    board_programmer_B.dataIn[19] = board_programmer_B.uv1[2];
    board_programmer_B.dataIn[20] = board_programmer_B.uv1[3];
    ProtocolEncoderBase_get_DataT_h(board_programmer_B.uv);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv[4];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.outIdx = (uint16_T)board_programmer_B.Sum_k;
    board_programmer_B.inDataIdx++;
  }

  board_programmer_B.dataIn[21] = 13U;
  board_programmer_B.dataIn[22] = 10U;

  /* MATLABSystem: '<S37>/Serial Transmit2' */
  if (board_programmer_DW.obj_l.Protocol !=
      board_programmer_P.SerialTransmit2_Protocol) {
    board_programmer_DW.obj_l.Protocol =
      board_programmer_P.SerialTransmit2_Protocol;
  }

  MW_Serial_write(board_programmer_DW.obj_l.port, &board_programmer_B.dataIn[0],
                  23.0, board_programmer_DW.obj_l.dataSizeInBytes,
                  board_programmer_DW.obj_l.sendModeEnum,
                  board_programmer_DW.obj_l.dataType,
                  board_programmer_DW.obj_l.sendFormatEnum, 2.0, '\x00');

  /* MATLABSystem: '<S37>/Protocol Encoder1' incorporates:
   *  MATLABSystem: '<S37>/Protocol Encoder2'
   *  MATLABSystem: '<S37>/Serial Transmit1'
   *  S-Function (double2ascii): '<S37>/C//C++ Code Block3'
   *  S-Function (double2ascii): '<S37>/C//C++ Code Block4'
   */
  if (board_programmer_DW.obj_a.TunablePropsChanged) {
    board_programmer_DW.obj_a.TunablePropsChanged = false;
  }

  board_programmer_B.dataIn_m[0] = 64U;
  board_programmer_B.inDataIdx = 1U;
  board_programmer_B.dataIn_m[1] = 0U;
  board_programmer_B.dataIn_m[2] = 0U;
  board_programmer_B.dataIn_m[3] = 0U;
  board_programmer_B.dataIn_m[4] = 0U;
  board_programmer_B.outIdx = 1U;
  while (board_programmer_B.inDataIdx <= 4) {
    ProtocolEncoderBase_get_DataTyp(board_programmer_B.uv2);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv2[0];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.qY = (int32_T)(board_programmer_B.Sum_k - 1U);
    if (board_programmer_B.Sum_k - 1U > board_programmer_B.Sum_k) {
      board_programmer_B.qY = 0;
    }

    if (board_programmer_B.outIdx > (uint16_T)board_programmer_B.qY) {
      board_programmer_B.rowIdx = 0;
      board_programmer_B.qY = 0;
    } else {
      board_programmer_B.rowIdx = board_programmer_B.outIdx - 1;
      board_programmer_B.qY = (uint16_T)board_programmer_B.qY;
    }

    board_programmer_B.uv1[0] = board_programmer_B.dataIn_m[1];
    board_programmer_B.uv1[1] = board_programmer_B.dataIn_m[2];
    board_programmer_B.uv1[2] = board_programmer_B.dataIn_m[3];
    board_programmer_B.uv1[3] = board_programmer_B.dataIn_m[4];
    board_programmer_B.tableOffset = board_programmer_B.qY -
      board_programmer_B.rowIdx;
    for (board_programmer_B.qY = 0; board_programmer_B.qY <
         board_programmer_B.tableOffset; board_programmer_B.qY++) {
      board_programmer_B.uv1[board_programmer_B.rowIdx + board_programmer_B.qY] =
        board_programmer_B.CCCodeBlock3[board_programmer_B.inDataIdx - 1];
    }

    board_programmer_B.dataIn_m[1] = board_programmer_B.uv1[0];
    board_programmer_B.dataIn_m[2] = board_programmer_B.uv1[1];
    board_programmer_B.dataIn_m[3] = board_programmer_B.uv1[2];
    board_programmer_B.dataIn_m[4] = board_programmer_B.uv1[3];
    ProtocolEncoderBase_get_DataTyp(board_programmer_B.uv2);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv2[0];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.outIdx = (uint16_T)board_programmer_B.Sum_k;
    board_programmer_B.inDataIdx++;
  }

  board_programmer_B.inDataIdx = 1U;
  board_programmer_B.dataIn_m[5] = 0U;
  board_programmer_B.dataIn_m[6] = 0U;
  board_programmer_B.dataIn_m[7] = 0U;
  board_programmer_B.dataIn_m[8] = 0U;
  board_programmer_B.outIdx = 1U;
  while (board_programmer_B.inDataIdx <= 4) {
    ProtocolEncoderBase_get_DataTyp(board_programmer_B.uv2);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv2[1];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.qY = (int32_T)(board_programmer_B.Sum_k - 1U);
    if (board_programmer_B.Sum_k - 1U > board_programmer_B.Sum_k) {
      board_programmer_B.qY = 0;
    }

    if (board_programmer_B.outIdx > (uint16_T)board_programmer_B.qY) {
      board_programmer_B.rowIdx = 0;
      board_programmer_B.qY = 0;
    } else {
      board_programmer_B.rowIdx = board_programmer_B.outIdx - 1;
      board_programmer_B.qY = (uint16_T)board_programmer_B.qY;
    }

    board_programmer_B.uv1[0] = board_programmer_B.dataIn_m[5];
    board_programmer_B.uv1[1] = board_programmer_B.dataIn_m[6];
    board_programmer_B.uv1[2] = board_programmer_B.dataIn_m[7];
    board_programmer_B.uv1[3] = board_programmer_B.dataIn_m[8];
    board_programmer_B.tableOffset = board_programmer_B.qY -
      board_programmer_B.rowIdx;
    for (board_programmer_B.qY = 0; board_programmer_B.qY <
         board_programmer_B.tableOffset; board_programmer_B.qY++) {
      board_programmer_B.uv1[board_programmer_B.rowIdx + board_programmer_B.qY] =
        board_programmer_B.CCCodeBlock4[board_programmer_B.inDataIdx - 1];
    }

    board_programmer_B.dataIn_m[5] = board_programmer_B.uv1[0];
    board_programmer_B.dataIn_m[6] = board_programmer_B.uv1[1];
    board_programmer_B.dataIn_m[7] = board_programmer_B.uv1[2];
    board_programmer_B.dataIn_m[8] = board_programmer_B.uv1[3];
    ProtocolEncoderBase_get_DataTyp(board_programmer_B.uv2);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv2[1];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.outIdx = (uint16_T)board_programmer_B.Sum_k;
    board_programmer_B.inDataIdx++;
  }

  board_programmer_B.dataIn_m[9] = 13U;
  board_programmer_B.dataIn_m[10] = 10U;

  /* End of MATLABSystem: '<S37>/Protocol Encoder1' */

  /* MATLABSystem: '<S37>/Serial Transmit1' */
  if (board_programmer_DW.obj_j.Protocol !=
      board_programmer_P.SerialTransmit1_Protocol) {
    board_programmer_DW.obj_j.Protocol =
      board_programmer_P.SerialTransmit1_Protocol;
  }

  MW_Serial_write(board_programmer_DW.obj_j.port, &board_programmer_B.dataIn_m[0],
                  11.0, board_programmer_DW.obj_j.dataSizeInBytes,
                  board_programmer_DW.obj_j.sendModeEnum,
                  board_programmer_DW.obj_j.dataType,
                  board_programmer_DW.obj_j.sendFormatEnum, 2.0, '\x00');
}

/* Model initialize function */
void board_programmer_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(board_programmer_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &board_programmer_B), 0,
                sizeof(B_board_programmer_T));

  /* states (dwork) */
  (void) memset((void *)&board_programmer_DW, 0,
                sizeof(DW_board_programmer_T));

  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<S1>/Digital Input' */
    board_programmer_DW.obj_e.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_g = true;
    board_programmer_DW.obj_e.SampleTime =
      board_programmer_P.DigitalInput_SampleTime;
    board_programmer_DW.obj_e.isInitialized = 1;
    digitalIOSetup(7, 2.0);
    board_programmer_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Input2' */
    board_programmer_DW.obj_lp.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_b = true;
    board_programmer_DW.obj_lp.SampleTime =
      board_programmer_P.DigitalInput2_SampleTime;
    board_programmer_DW.obj_lp.isInitialized = 1;
    digitalIOSetup(51, 2.0);
    board_programmer_DW.obj_lp.isSetupComplete = true;

    /* Start for Enabled SubSystem: '<Root>/Controllers' */
    board_programmer_DW.Controllers_MODE = false;
    board_pro_MovingAverage_a_Start(&board_programmer_DW.MovingAverage);
    board_pro_MovingAverage_a_Start(&board_programmer_DW.MovingAverage1);

    /* Start for Enabled SubSystem: '<S5>/Subsystem1' */
    board_programmer_DW.Subsystem1_MODE = false;

    /* End of Start for SubSystem: '<S5>/Subsystem1' */

    /* Start for Enabled SubSystem: '<S5>/Subsystem' */
    board_programmer_DW.Subsystem_MODE = false;

    /* End of Start for SubSystem: '<S5>/Subsystem' */

    /* Start for Enabled SubSystem: '<S5>/controllo PP 1' */
    board_progra_controlloPP1_Start(&board_programmer_DW.controlloPP1);

    /* End of Start for SubSystem: '<S5>/controllo PP 1' */

    /* Start for Enabled SubSystem: '<S2>/controllo PP 1' */
    board_progra_controlloPP1_Start(&board_programmer_DW.controlloPP1_d);

    /* End of Start for SubSystem: '<S2>/controllo PP 1' */
    /* End of Start for SubSystem: '<Root>/Controllers' */

    /* Start for MATLABSystem: '<S1>/Digital Input1' */
    board_programmer_DW.obj_i.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_f = true;
    board_programmer_DW.obj_i.SampleTime =
      board_programmer_P.DigitalInput1_SampleTime;
    board_programmer_DW.obj_i.isInitialized = 1;
    digitalIOSetup(53, 2.0);
    board_programmer_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S37>/Protocol Encoder2' */
    board_programmer_DW.obj.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_p = true;
    board_programmer_DW.obj.isInitialized = 1;
    board_programmer_DW.obj.isSetupComplete = true;
    board_programmer_DW.obj.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<S37>/Serial Transmit2' */
    board_programmer_DW.obj_l.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty = true;
    board_programmer_DW.obj_l.Protocol =
      board_programmer_P.SerialTransmit2_Protocol;
    board_programmer_DW.obj_l.isInitialized = 1;
    board_programmer_DW.obj_l.port = 0.0;
    board_programmer_DW.obj_l.dataSizeInBytes = 1.0;
    board_programmer_DW.obj_l.dataType = 0.0;
    board_programmer_DW.obj_l.sendModeEnum = 0.0;
    board_programmer_DW.obj_l.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(board_programmer_DW.obj_l.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    board_programmer_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S37>/Serial Transmit2' */

    /* Start for MATLABSystem: '<S37>/Protocol Encoder1' */
    board_programmer_DW.obj_a.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_d = true;
    board_programmer_DW.obj_a.isInitialized = 1;
    board_programmer_DW.obj_a.isSetupComplete = true;
    board_programmer_DW.obj_a.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<S37>/Serial Transmit1' */
    board_programmer_DW.obj_j.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_j = true;
    board_programmer_DW.obj_j.Protocol =
      board_programmer_P.SerialTransmit1_Protocol;
    board_programmer_DW.obj_j.isInitialized = 1;
    board_programmer_DW.obj_j.port = 3.0;
    board_programmer_DW.obj_j.dataSizeInBytes = 1.0;
    board_programmer_DW.obj_j.dataType = 0.0;
    board_programmer_DW.obj_j.sendModeEnum = 0.0;
    board_programmer_DW.obj_j.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(board_programmer_DW.obj_j.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    board_programmer_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S37>/Serial Transmit1' */
  }

  /* SystemInitialize for Enabled SubSystem: '<Root>/Controllers' */
  /* InitializeConditions for UnitDelay: '<S30>/UD' */
  board_programmer_DW.UD_DSTATE =
    board_programmer_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S31>/UD' */
  board_programmer_DW.UD_DSTATE_j =
    board_programmer_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for Delay: '<S5>/Delay1' */
  board_programmer_DW.Delay1_DSTATE =
    board_programmer_P.Delay1_InitialCondition_p;

  /* InitializeConditions for Enabled SubSystem: '<S5>/Subsystem1' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  /* InitializeConditions for Memory: '<S8>/Memory' */
  board_programmer_DW.Memory_PreviousInput =
    board_programmer_P.SRFlipFlop_initial_condition;

  /* SystemInitialize for Enabled SubSystem: '<S5>/Subsystem1' */
  /* SystemInitialize for Atomic SubSystem: '<S10>/Timer with reset' */
  /* InitializeConditions for Delay: '<S22>/Delay1' */
  board_programmer_DW.Delay1_DSTATE_a =
    board_programmer_P.Delay1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  board_programmer_DW.DiscreteTimeIntegrator_DSTATE =
    board_programmer_P.DiscreteTimeIntegrator_IC_c;
  board_programmer_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* End of SystemInitialize for SubSystem: '<S10>/Timer with reset' */
  /* End of SystemInitialize for SubSystem: '<S5>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S5>/Subsystem' */
  /* SystemInitialize for Atomic SubSystem: '<S9>/Timer ' */
  /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o =
    board_programmer_P.DiscreteTimeIntegrator_IC;
  board_programmer_DW.DiscreteTimeIntegrator_PrevRe_a = 2;

  /* End of SystemInitialize for SubSystem: '<S9>/Timer ' */

  /* SystemInitialize for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Outport: '<S9>/time'
   */
  board_programmer_B.DiscreteTimeIntegrator = board_programmer_P.time_Y0;

  /* End of SystemInitialize for SubSystem: '<S5>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S5>/controllo PP 1' */
  board_program_controlloPP1_Init(&board_programmer_DW.controlloPP1,
    &board_programmer_P.controlloPP1);

  /* End of SystemInitialize for SubSystem: '<S5>/controllo PP 1' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/controllo PP 1' */
  board_program_controlloPP1_Init(&board_programmer_DW.controlloPP1_d,
    &board_programmer_P.controlloPP1_d);

  /* End of SystemInitialize for SubSystem: '<S2>/controllo PP 1' */
  board_prog_MovingAverage_h_Init(&board_programmer_DW.MovingAverage);
  board_prog_MovingAverage_h_Init(&board_programmer_DW.MovingAverage1);

  /* End of SystemInitialize for SubSystem: '<Root>/Controllers' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  board_programmer_B.Merge[0] = board_programmer_P.Merge_InitialOutput;
  board_programmer_B.Merge[1] = board_programmer_P.Merge_InitialOutput;
}

/* Model terminate function */
void board_programmer_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Input' */
  if (!board_programmer_DW.obj_e.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Input' */

  /* Terminate for MATLABSystem: '<S1>/Digital Input2' */
  if (!board_programmer_DW.obj_lp.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_lp.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Input2' */

  /* Terminate for Enabled SubSystem: '<Root>/Controllers' */
  board_prog_MovingAverage_e_Term(&board_programmer_DW.MovingAverage);
  board_prog_MovingAverage_e_Term(&board_programmer_DW.MovingAverage1);

  /* Terminate for Enabled SubSystem: '<S5>/controllo PP 1' */
  board_program_controlloPP1_Term(&board_programmer_DW.controlloPP1);

  /* End of Terminate for SubSystem: '<S5>/controllo PP 1' */

  /* Terminate for Enabled SubSystem: '<S2>/controllo PP 1' */
  board_program_controlloPP1_Term(&board_programmer_DW.controlloPP1_d);

  /* End of Terminate for SubSystem: '<S2>/controllo PP 1' */
  /* End of Terminate for SubSystem: '<Root>/Controllers' */

  /* Terminate for MATLABSystem: '<S1>/Digital Input1' */
  if (!board_programmer_DW.obj_i.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Input1' */

  /* Terminate for MATLABSystem: '<S37>/Protocol Encoder2' */
  if (!board_programmer_DW.obj.matlabCodegenIsDeleted) {
    board_programmer_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S37>/Protocol Encoder2' */

  /* Terminate for MATLABSystem: '<S37>/Serial Transmit2' */
  if (!board_programmer_DW.obj_l.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S37>/Serial Transmit2' */

  /* Terminate for MATLABSystem: '<S37>/Protocol Encoder1' */
  if (!board_programmer_DW.obj_a.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S37>/Protocol Encoder1' */

  /* Terminate for MATLABSystem: '<S37>/Serial Transmit1' */
  if (!board_programmer_DW.obj_j.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S37>/Serial Transmit1' */
}
