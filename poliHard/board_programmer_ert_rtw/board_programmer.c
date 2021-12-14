/*
 * board_programmer.c
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
static void board_programm_SystemCore_setup(matlabshared_embedded_utiliti_T *obj);
static void ProtocolDecoderBase_get_DataTyp(uint8_T value[8]);
static void ProtocolEncoderBase_get_DataTyp(uint8_T value[2]);
static void rate_monotonic_scheduler(void);
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

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void board_programmer_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(board_programmer_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(board_programmer_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (board_programmer_M->Timing.TaskCounters.TID[1])++;
  if ((board_programmer_M->Timing.TaskCounters.TID[1]) > 50) {/* Sample time: [0.0051s, 0.0s] */
    board_programmer_M->Timing.TaskCounters.TID[1] = 0;
  }

  (board_programmer_M->Timing.TaskCounters.TID[2])++;
  if ((board_programmer_M->Timing.TaskCounters.TID[2]) > 199) {/* Sample time: [0.02s, 0.0s] */
    board_programmer_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* System initialize for atomic system: */
void board_pr_MovingAverage_Init(DW_MovingAverage_board_progra_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S27>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S27>/Moving Average' */
}

/* System reset for atomic system: */
void board_p_MovingAverage_Reset(DW_MovingAverage_board_progra_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S27>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S27>/Moving Average' */
}

/* Start for atomic system: */
void board_p_MovingAverage_Start(DW_MovingAverage_board_progra_T *localDW)
{
  /* Start for MATLABSystem: '<S27>/Moving Average' */
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
void board_program_MovingAverage(real_T rtu_0, B_MovingAverage_board_program_T
  *localB, DW_MovingAverage_board_progra_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<S27>/Moving Average' */
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

  /* MATLABSystem: '<S27>/Moving Average' */
  localB->MovingAverage = 0.0;

  /* MATLABSystem: '<S27>/Moving Average' */
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
    /* MATLABSystem: '<S27>/Moving Average' */
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
void board_pr_MovingAverage_Term(DW_MovingAverage_board_progra_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  /* Terminate for MATLABSystem: '<S27>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S27>/Moving Average' */
}

/*
 * System initialize for enable system:
 *    '<S6>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_pro_controlloPP1_Init(DW_controlloPP1_board_program_T *localDW,
  P_controlloPP1_board_programm_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S29>/UD' */
  localDW->UD_DSTATE = localP->DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Sum: '<S27>/Sum1' incorporates:
   *  Delay: '<S27>/Delay'
   */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S30>/UD' */
  localDW->UD_DSTATE_g = localP->DiscreteDerivative_ICPrevScal_f;

  /* InitializeConditions for Sum: '<S28>/Sum1' incorporates:
   *  Delay: '<S28>/Delay'
   */
  localDW->Delay_DSTATE_k = localP->Delay_InitialCondition_o;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_n = localP->DiscreteTimeIntegrator_IC_a;
  localDW->DiscreteTimeIntegrator_PrevRe_p = 2;
  board_pr_MovingAverage_Init(&localDW->MovingAverage);
  board_pr_MovingAverage_Init(&localDW->MovingAverage_p);
}

/*
 * System reset for enable system:
 *    '<S6>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_pr_controlloPP1_Reset(DW_controlloPP1_board_program_T *localDW,
  P_controlloPP1_board_programm_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S29>/UD' */
  localDW->UD_DSTATE = localP->DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Sum: '<S27>/Sum1' incorporates:
   *  Delay: '<S27>/Delay'
   */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S30>/UD' */
  localDW->UD_DSTATE_g = localP->DiscreteDerivative_ICPrevScal_f;

  /* InitializeConditions for Sum: '<S28>/Sum1' incorporates:
   *  Delay: '<S28>/Delay'
   */
  localDW->Delay_DSTATE_k = localP->Delay_InitialCondition_o;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_n = localP->DiscreteTimeIntegrator_IC_a;
  localDW->DiscreteTimeIntegrator_PrevRe_p = 2;
  board_p_MovingAverage_Reset(&localDW->MovingAverage);
  board_p_MovingAverage_Reset(&localDW->MovingAverage_p);
}

/*
 * Disable for enable system:
 *    '<S6>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board__controlloPP1_Disable(DW_controlloPP1_board_program_T *localDW)
{
  localDW->controlloPP1_MODE = false;
}

/*
 * Start for enable system:
 *    '<S6>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_pr_controlloPP1_Start(DW_controlloPP1_board_program_T *localDW)
{
  localDW->controlloPP1_MODE = false;
  board_p_MovingAverage_Start(&localDW->MovingAverage);
  board_p_MovingAverage_Start(&localDW->MovingAverage_p);
}

/*
 * Output and update for enable system:
 *    '<S6>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_programm_controlloPP1(boolean_T rtu_Enable, const real_T rtu_ref[2],
  const real_T rtu_pos[2], real_T rty_theta[2], B_controlloPP1_board_programm_T *
  localB, DW_controlloPP1_board_program_T *localDW,
  P_controlloPP1_board_programm_T *localP)
{
  /* local block i/o variables */
  real_T rtb_UnaryMinus_h;

  /* Outputs for Enabled SubSystem: '<S6>/controllo PP 1' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->controlloPP1_MODE) {
      board_pr_controlloPP1_Reset(localDW, localP);
      localDW->controlloPP1_MODE = true;
    }

    /* SampleTimeMath: '<S29>/TSamp'
     *
     * About '<S29>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TSamp_h = rtu_pos[0] * localP->TSamp_WtEt;

    /* UnaryMinus: '<S27>/Unary Minus' incorporates:
     *  Sum: '<S29>/Diff'
     *  UnitDelay: '<S29>/UD'
     */
    localB->UnaryMinus = -(localB->TSamp_h - localDW->UD_DSTATE);
    board_program_MovingAverage(localB->UnaryMinus, &localB->MovingAverage,
      &localDW->MovingAverage);

    /* Sum: '<S12>/Sum2' */
    localB->Sum2 = rtu_ref[0] - rtu_pos[0];

    /* SampleTimeMath: '<S30>/TSamp'
     *
     * About '<S30>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TSamp_e = rtu_pos[1] * localP->TSamp_WtEt_m;

    /* UnaryMinus: '<S28>/Unary Minus' incorporates:
     *  Sum: '<S30>/Diff'
     *  UnitDelay: '<S30>/UD'
     */
    rtb_UnaryMinus_h = -(localB->TSamp_e - localDW->UD_DSTATE_g);
    board_program_MovingAverage(rtb_UnaryMinus_h, &localB->MovingAverage_p,
      &localDW->MovingAverage_p);

    /* Sum: '<S12>/Sum3' */
    localB->Sum3_h = rtu_ref[1] - rtu_pos[1];

    /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
    if (localDW->DiscreteTimeIntegrator_PrevRese <= 0) {
      localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
    }

    /* Sum: '<S28>/Sum1' incorporates:
     *  Delay: '<S28>/Delay'
     *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator'
     *  Gain: '<S28>/x integration gain'
     *  Gain: '<S28>/x matrix gain'
     *  SignalConversion generated from: '<S28>/x matrix gain'
     */
    localDW->Delay_DSTATE_k = ((board_programmer_P.slow.Ky[0] *
      localB->MovingAverage_p.MovingAverage + board_programmer_P.slow.Ky[1] *
      localB->Sum3_h) + board_programmer_P.slow.Ky[2] * localDW->Delay_DSTATE_k)
      + board_programmer_P.slow.Kyi * localDW->DiscreteTimeIntegrator_DSTATE;

    /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
    if (localDW->DiscreteTimeIntegrator_PrevRe_p <= 0) {
      localDW->DiscreteTimeIntegrator_DSTATE_n =
        localP->DiscreteTimeIntegrator_IC_a;
    }

    /* Sum: '<S27>/Sum1' incorporates:
     *  Delay: '<S27>/Delay'
     *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
     *  Gain: '<S27>/x integration gain'
     *  Gain: '<S27>/x matrix gain'
     *  SignalConversion generated from: '<S27>/x matrix gain'
     */
    localDW->Delay_DSTATE = ((board_programmer_P.slow.Kx[0] *
      localB->MovingAverage.MovingAverage + board_programmer_P.slow.Kx[1] *
      localB->Sum2) + board_programmer_P.slow.Kx[2] * localDW->Delay_DSTATE) +
      board_programmer_P.slow.Kxi * localDW->DiscreteTimeIntegrator_DSTATE_n;

    /* SignalConversion generated from: '<S12>/theta' */
    rty_theta[0] = localDW->Delay_DSTATE;
    rty_theta[1] = localDW->Delay_DSTATE_k;

    /* Update for UnitDelay: '<S29>/UD' */
    localDW->UD_DSTATE = localB->TSamp_h;

    /* Update for UnitDelay: '<S30>/UD' */
    localDW->UD_DSTATE_g = localB->TSamp_e;

    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * localB->Sum3_h;
    localDW->DiscreteTimeIntegrator_PrevRese = 1;

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE_n +=
      localP->DiscreteTimeIntegrator_gainva_k * localB->Sum2;
    localDW->DiscreteTimeIntegrator_PrevRe_p = 1;
    srUpdateBC(localDW->controlloPP1_SubsysRanBC);
  } else if (localDW->controlloPP1_MODE) {
    board__controlloPP1_Disable(localDW);
  }

  /* End of Outputs for SubSystem: '<S6>/controllo PP 1' */
}

/*
 * Termination for enable system:
 *    '<S6>/controllo PP 1'
 *    '<S2>/controllo PP 1'
 */
void board_pro_controlloPP1_Term(DW_controlloPP1_board_program_T *localDW)
{
  board_pr_MovingAverage_Term(&localDW->MovingAverage);
  board_pr_MovingAverage_Term(&localDW->MovingAverage_p);
}

/* System initialize for atomic system: */
void board__MovingAverage_p_Init(DW_MovingAverage_board_prog_f_T *localDW)
{
  g_dsp_internal_SlidingWindo_l_T *obj;

  /* InitializeConditions for MATLABSystem: '<S7>/Moving Average' */
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

  /* End of InitializeConditions for MATLABSystem: '<S7>/Moving Average' */
}

/* Start for atomic system: */
void board_MovingAverage_g_Start(DW_MovingAverage_board_prog_f_T *localDW)
{
  /* Start for MATLABSystem: '<S7>/Moving Average' */
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
void board_progr_MovingAverage_p(real_T rtu_0, B_MovingAverage_board_progr_c_T
  *localB, DW_MovingAverage_board_prog_f_T *localDW)
{
  g_dsp_internal_SlidingWindo_l_T *obj;
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;

  /* MATLABSystem: '<S7>/Moving Average' */
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

  /* MATLABSystem: '<S7>/Moving Average' */
  localB->MovingAverage = 0.0;

  /* MATLABSystem: '<S7>/Moving Average' */
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
    /* MATLABSystem: '<S7>/Moving Average' */
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
void board__MovingAverage_d_Term(DW_MovingAverage_board_prog_f_T *localDW)
{
  g_dsp_internal_SlidingWindo_l_T *obj;

  /* Terminate for MATLABSystem: '<S7>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S7>/Moving Average' */
}

static void board_programm_SystemCore_setup(matlabshared_embedded_utiliti_T *obj)
{
  int32_T i;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  for (i = 0; i < 27; i++) {
    obj->DataBuffer[i] = 0U;
  }

  obj->PrevOutCellArray.f1[0] = 0U;
  obj->PrevOutCellArray.f2[0] = 0U;
  obj->PrevOutCellArray.f3[0] = 0U;
  obj->PrevOutCellArray.f4[0] = 0U;
  obj->PrevOutCellArray.f5[0] = 0U;
  obj->PrevOutCellArray.f1[1] = 0U;
  obj->PrevOutCellArray.f2[1] = 0U;
  obj->PrevOutCellArray.f3[1] = 0U;
  obj->PrevOutCellArray.f4[1] = 0U;
  obj->PrevOutCellArray.f5[1] = 0U;
  obj->PrevOutCellArray.f1[2] = 0U;
  obj->PrevOutCellArray.f2[2] = 0U;
  obj->PrevOutCellArray.f3[2] = 0U;
  obj->PrevOutCellArray.f4[2] = 0U;
  obj->PrevOutCellArray.f5[2] = 0U;
  obj->PrevOutCellArray.f1[3] = 0U;
  obj->PrevOutCellArray.f2[3] = 0U;
  obj->PrevOutCellArray.f3[3] = 0U;
  obj->PrevOutCellArray.f4[3] = 0U;
  obj->PrevOutCellArray.f5[3] = 0U;
  obj->PrevOutCellArray.f6 = 0U;
  obj->PrevOutCellArray.f7 = 0U;
  obj->PrevOutCellArray.f8[0] = 0U;
  obj->PrevOutCellArray.f8[1] = 0U;
  obj->PrevOutCellArray.f9 = false;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
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

static void ProtocolDecoderBase_get_DataTyp(uint8_T value[8])
{
  int32_T b_i;
  int32_T ret;
  char_T m_f2[5];
  char_T n_f2[5];
  char_T o_f1[5];
  char_T tmp;
  static const char_T tmp_0[5] = { 'u', 'i', 'n', 't', '8' };

  static const char_T tmp_1[5] = { 'i', 'n', 't', '6', '4' };

  static const char_T tmp_2[5] = { 'i', 'n', 't', '3', '2' };

  static const char_T tmp_3[5] = { 'i', 'n', 't', '1', '6' };

  for (b_i = 0; b_i < 5; b_i++) {
    tmp = tmp_0[b_i];
    board_programmer_B.c.f1[b_i] = tmp;
    board_programmer_B.d_c.f1[b_i] = tmp;
    board_programmer_B.e.f1[b_i] = tmp;
    board_programmer_B.f.f1[b_i] = tmp;
    board_programmer_B.g.f1[b_i] = tmp;
    board_programmer_B.h.f1[b_i] = tmp;
    board_programmer_B.j.f1[b_i] = tmp;
    board_programmer_B.k.f1[b_i] = tmp;
    board_programmer_B.l_f3[b_i] = tmp_1[b_i];
    m_f2[b_i] = tmp_2[b_i];
    n_f2[b_i] = tmp;
    o_f1[b_i] = tmp_3[b_i];
  }

  for (b_i = 0; b_i < 8; b_i++) {
    board_programmer_B.b[0] = board_programmer_B.c;
    board_programmer_B.b[1] = board_programmer_B.d_c;
    board_programmer_B.b[2] = board_programmer_B.e;
    board_programmer_B.b[3] = board_programmer_B.f;
    board_programmer_B.b[4] = board_programmer_B.g;
    board_programmer_B.b[5] = board_programmer_B.h;
    board_programmer_B.b[6] = board_programmer_B.j;
    board_programmer_B.b[7] = board_programmer_B.k;
    ret = memcmp(&board_programmer_B.b[b_i].f1[0], &board_programmer_B.l_f3[0],
                 5);
    if (ret == 0) {
      ret = 0;
    } else {
      ret = memcmp(&board_programmer_B.b[b_i].f1[0], &m_f2[0], 5);
      if (ret == 0) {
        ret = 1;
      } else {
        ret = memcmp(&board_programmer_B.b[b_i].f1[0], &n_f2[0], 5);
        if (ret == 0) {
          ret = 2;
        } else {
          ret = memcmp(&board_programmer_B.b[b_i].f1[0], &o_f1[0], 5);
          if (ret == 0) {
            ret = 3;
          } else {
            ret = -1;
          }
        }
      }
    }

    switch (ret) {
     case 0:
      value[b_i] = 8U;
      break;

     case 1:
      value[b_i] = 4U;
      break;

     case 2:
      value[b_i] = 1U;
      break;

     case 3:
      value[b_i] = 2U;
      break;

     default:
      value[b_i] = 1U;
      break;
    }
  }
}

static void ProtocolEncoderBase_get_DataTyp(uint8_T value[2])
{
  static const char_T tmp[5] = { 'u', 'i', 'n', 't', '8' };

  static const char_T tmp_0[5] = { 'i', 'n', 't', '6', '4' };

  static const char_T tmp_1[5] = { 'i', 'n', 't', '3', '2' };

  static const char_T tmp_2[5] = { 'i', 'n', 't', '1', '6' };

  for (board_programmer_B.b_i = 0; board_programmer_B.b_i < 5;
       board_programmer_B.b_i++) {
    board_programmer_B.c_l = tmp[board_programmer_B.b_i];
    board_programmer_B.c_f.f1[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.d_g.f1[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.e_f3[board_programmer_B.b_i] =
      tmp_0[board_programmer_B.b_i];
    board_programmer_B.f_f2[board_programmer_B.b_i] =
      tmp_1[board_programmer_B.b_i];
    board_programmer_B.g_f2[board_programmer_B.b_i] = board_programmer_B.c_l;
    board_programmer_B.h_f1[board_programmer_B.b_i] =
      tmp_2[board_programmer_B.b_i];
  }

  for (board_programmer_B.b_i = 0; board_programmer_B.b_i < 2;
       board_programmer_B.b_i++) {
    board_programmer_B.b_c[0] = board_programmer_B.c_f;
    board_programmer_B.b_c[1] = board_programmer_B.d_g;
    board_programmer_B.ret = memcmp
      (&board_programmer_B.b_c[board_programmer_B.b_i].f1[0],
       &board_programmer_B.e_f3[0], 5);
    if (board_programmer_B.ret == 0) {
      board_programmer_B.ret = 0;
    } else {
      board_programmer_B.ret = memcmp
        (&board_programmer_B.b_c[board_programmer_B.b_i].f1[0],
         &board_programmer_B.f_f2[0], 5);
      if (board_programmer_B.ret == 0) {
        board_programmer_B.ret = 1;
      } else {
        board_programmer_B.ret = memcmp
          (&board_programmer_B.b_c[board_programmer_B.b_i].f1[0],
           &board_programmer_B.g_f2[0], 5);
        if (board_programmer_B.ret == 0) {
          board_programmer_B.ret = 2;
        } else {
          board_programmer_B.ret = memcmp
            (&board_programmer_B.b_c[board_programmer_B.b_i].f1[0],
             &board_programmer_B.h_f1[0], 5);
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

/* Model step function for TID0 */
void board_programmer_step0(void)      /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++board_programmer_M->Timing.clockTick0)) {
    ++board_programmer_M->Timing.clockTickH0;
  }

  board_programmer_M->Timing.taskTime0 = board_programmer_M->Timing.clockTick0 *
    board_programmer_M->Timing.stepSize0 +
    board_programmer_M->Timing.clockTickH0 *
    board_programmer_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void board_programmer_step1(void)      /* Sample time: [0.0051s, 0.0s] */
{
  int32_T d;
  int32_T i;
  uint32_T rtb_StringtoDouble7;
  uint16_T idx;
  uint16_T payloadLength;
  uint8_T b_varargout_1[4];
  uint8_T b_varargout_2[4];
  uint8_T b_varargout_3[4];
  uint8_T b_varargout_4[4];
  uint8_T b_varargout_5[4];
  uint8_T terminator[2];
  uint8_T header;
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' incorporates:
   *  MATLABSystem: '<Root>/Protocol Decoder1'
   */
  if (board_programmer_DW.obj_l.Protocol !=
      board_programmer_P.SerialReceive_Protocol) {
    board_programmer_DW.obj_l.Protocol =
      board_programmer_P.SerialReceive_Protocol;
  }

  MW_Serial_read(1, board_programmer_DW.obj_l.DataSizeInBytes,
                 &board_programmer_B.inData[0], &status);

  /* End of MATLABSystem: '<Root>/Serial Receive' */

  /* MATLABSystem: '<Root>/Protocol Decoder1' */
  if (board_programmer_DW.obj_f.TunablePropsChanged) {
    board_programmer_DW.obj_f.TunablePropsChanged = false;
  }

  header = 64U;
  terminator[0] = 13U;
  terminator[1] = 10U;
  status = readPacket(&board_programmer_B.inData[0], 12, &header, 1,
                      &terminator[0], 2, false, 24, 24,
                      &board_programmer_DW.obj_f.DataBuffer[0],
                      &board_programmer_B.payload[0], &payloadLength);
  if (status != 0) {
    rtb_StringtoDouble7 = payloadLength + 1U;
    if (payloadLength + 1U > 65535U) {
      rtb_StringtoDouble7 = 65535U;
    }

    if ((uint16_T)rtb_StringtoDouble7 > 24) {
      d = 0;
      i = -1;
    } else {
      d = (uint16_T)rtb_StringtoDouble7 - 1;
      i = 23;
    }

    i = (i - d) + 1;
    if (0 <= i - 1) {
      memset(&board_programmer_B.payload[d], 0, ((i + d) - d) * sizeof(uint8_T));
    }

    payloadLength = 1U;
    idx = 1U;
    b_varargout_1[0] = 0U;
    b_varargout_1[1] = 0U;
    b_varargout_1[2] = 0U;
    b_varargout_1[3] = 0U;
    while (payloadLength <= 4) {
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_programmer_B.uv[0]);
      d = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        d = 0;
      }

      if (payloadLength > (uint16_T)d) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_1[idx - 1] = board_programmer_B.payload[i];
      rtb_StringtoDouble7 = idx + 1U;
      if (idx + 1U > 65535U) {
        rtb_StringtoDouble7 = 65535U;
      }

      idx = (uint16_T)rtb_StringtoDouble7;
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength +
        board_programmer_B.uv[0]);
    }

    payloadLength = 5U;
    idx = 1U;
    b_varargout_2[0] = 0U;
    b_varargout_2[1] = 0U;
    b_varargout_2[2] = 0U;
    b_varargout_2[3] = 0U;
    while (payloadLength <= 8) {
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_programmer_B.uv[1]);
      d = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        d = 0;
      }

      if (payloadLength > (uint16_T)d) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_2[idx - 1] = board_programmer_B.payload[i];
      rtb_StringtoDouble7 = idx + 1U;
      if (idx + 1U > 65535U) {
        rtb_StringtoDouble7 = 65535U;
      }

      idx = (uint16_T)rtb_StringtoDouble7;
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength +
        board_programmer_B.uv[1]);
    }

    payloadLength = 9U;
    idx = 1U;
    b_varargout_3[0] = 0U;
    b_varargout_3[1] = 0U;
    b_varargout_3[2] = 0U;
    b_varargout_3[3] = 0U;
    while (payloadLength <= 12) {
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_programmer_B.uv[2]);
      d = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        d = 0;
      }

      if (payloadLength > (uint16_T)d) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_3[idx - 1] = board_programmer_B.payload[i];
      rtb_StringtoDouble7 = idx + 1U;
      if (idx + 1U > 65535U) {
        rtb_StringtoDouble7 = 65535U;
      }

      idx = (uint16_T)rtb_StringtoDouble7;
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength +
        board_programmer_B.uv[2]);
    }

    payloadLength = 13U;
    idx = 1U;
    b_varargout_4[0] = 0U;
    b_varargout_4[1] = 0U;
    b_varargout_4[2] = 0U;
    b_varargout_4[3] = 0U;
    while (payloadLength <= 16) {
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_programmer_B.uv[3]);
      d = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        d = 0;
      }

      if (payloadLength > (uint16_T)d) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_4[idx - 1] = board_programmer_B.payload[i];
      rtb_StringtoDouble7 = idx + 1U;
      if (idx + 1U > 65535U) {
        rtb_StringtoDouble7 = 65535U;
      }

      idx = (uint16_T)rtb_StringtoDouble7;
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength +
        board_programmer_B.uv[3]);
    }

    payloadLength = 17U;
    idx = 1U;
    b_varargout_5[0] = 0U;
    b_varargout_5[1] = 0U;
    b_varargout_5[2] = 0U;
    b_varargout_5[3] = 0U;
    while (payloadLength <= 20) {
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_programmer_B.uv[4]);
      d = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        d = 0;
      }

      if (payloadLength > (uint16_T)d) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_5[idx - 1] = board_programmer_B.payload[i];
      rtb_StringtoDouble7 = idx + 1U;
      if (idx + 1U > 65535U) {
        rtb_StringtoDouble7 = 65535U;
      }

      idx = (uint16_T)rtb_StringtoDouble7;
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength +
        board_programmer_B.uv[4]);
    }

    payloadLength = 21U;
    status = 0U;
    while (payloadLength <= 21) {
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      d = (int32_T)(board_programmer_B.uv[5] + 20U);
      if (board_programmer_B.uv[5] + 20U > board_programmer_B.uv[5] + 21U) {
        d = 0;
      }

      if (21 > (uint16_T)d) {
        i = 0;
      } else {
        i = 20;
      }

      status = board_programmer_B.payload[i];
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      payloadLength = (uint16_T)(board_programmer_B.uv[5] + 21U);
    }

    payloadLength = 22U;
    header = 0U;
    while (payloadLength <= 22) {
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      d = (int32_T)(board_programmer_B.uv[6] + 21U);
      if (board_programmer_B.uv[6] + 21U > board_programmer_B.uv[6] + 22U) {
        d = 0;
      }

      if (22 > (uint16_T)d) {
        i = 0;
      } else {
        i = 21;
      }

      header = board_programmer_B.payload[i];
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      payloadLength = (uint16_T)(board_programmer_B.uv[6] + 22U);
    }

    payloadLength = 23U;
    idx = 1U;
    terminator[0] = 0U;
    terminator[1] = 0U;
    while (payloadLength <= 24) {
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_programmer_B.uv[7]);
      d = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        d = 0;
      }

      if (payloadLength > (uint16_T)d) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      terminator[idx - 1] = board_programmer_B.payload[i];
      rtb_StringtoDouble7 = idx + 1U;
      if (idx + 1U > 65535U) {
        rtb_StringtoDouble7 = 65535U;
      }

      idx = (uint16_T)rtb_StringtoDouble7;
      ProtocolDecoderBase_get_DataTyp(board_programmer_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength +
        board_programmer_B.uv[7]);
    }

    board_programmer_DW.obj_f.PrevOutCellArray.f1[0] = b_varargout_1[0];
    board_programmer_DW.obj_f.PrevOutCellArray.f2[0] = b_varargout_2[0];
    board_programmer_DW.obj_f.PrevOutCellArray.f3[0] = b_varargout_3[0];
    board_programmer_DW.obj_f.PrevOutCellArray.f4[0] = b_varargout_4[0];
    board_programmer_DW.obj_f.PrevOutCellArray.f5[0] = b_varargout_5[0];
    board_programmer_DW.obj_f.PrevOutCellArray.f1[1] = b_varargout_1[1];
    board_programmer_DW.obj_f.PrevOutCellArray.f2[1] = b_varargout_2[1];
    board_programmer_DW.obj_f.PrevOutCellArray.f3[1] = b_varargout_3[1];
    board_programmer_DW.obj_f.PrevOutCellArray.f4[1] = b_varargout_4[1];
    board_programmer_DW.obj_f.PrevOutCellArray.f5[1] = b_varargout_5[1];
    board_programmer_DW.obj_f.PrevOutCellArray.f1[2] = b_varargout_1[2];
    board_programmer_DW.obj_f.PrevOutCellArray.f2[2] = b_varargout_2[2];
    board_programmer_DW.obj_f.PrevOutCellArray.f3[2] = b_varargout_3[2];
    board_programmer_DW.obj_f.PrevOutCellArray.f4[2] = b_varargout_4[2];
    board_programmer_DW.obj_f.PrevOutCellArray.f5[2] = b_varargout_5[2];
    board_programmer_DW.obj_f.PrevOutCellArray.f1[3] = b_varargout_1[3];
    board_programmer_DW.obj_f.PrevOutCellArray.f2[3] = b_varargout_2[3];
    board_programmer_DW.obj_f.PrevOutCellArray.f3[3] = b_varargout_3[3];
    board_programmer_DW.obj_f.PrevOutCellArray.f4[3] = b_varargout_4[3];
    board_programmer_DW.obj_f.PrevOutCellArray.f5[3] = b_varargout_5[3];
    board_programmer_DW.obj_f.PrevOutCellArray.f6 = status;
    board_programmer_DW.obj_f.PrevOutCellArray.f7 = header;
    board_programmer_DW.obj_f.PrevOutCellArray.f8[0] = terminator[0];
    board_programmer_DW.obj_f.PrevOutCellArray.f8[1] = terminator[1];
    board_programmer_DW.obj_f.PrevOutCellArray.f9 = false;
  } else {
    b_varargout_2[0] = board_programmer_DW.obj_f.PrevOutCellArray.f2[0];
    b_varargout_2[1] = board_programmer_DW.obj_f.PrevOutCellArray.f2[1];
    b_varargout_2[2] = board_programmer_DW.obj_f.PrevOutCellArray.f2[2];
    b_varargout_2[3] = board_programmer_DW.obj_f.PrevOutCellArray.f2[3];
    terminator[0] = board_programmer_DW.obj_f.PrevOutCellArray.f8[0];
    terminator[1] = board_programmer_DW.obj_f.PrevOutCellArray.f8[1];
  }

  /* ASCIIToString: '<Root>/ASCII to String1' incorporates:
   *  MATLABSystem: '<Root>/Protocol Decoder1'
   */
  board_programmer_B.rtb_ASCIItoString7_m[0] = (int8_T)b_varargout_2[0];
  board_programmer_B.rtb_ASCIItoString7_m[1] = (int8_T)b_varargout_2[1];
  board_programmer_B.rtb_ASCIItoString7_m[2] = (int8_T)b_varargout_2[2];
  board_programmer_B.rtb_ASCIItoString7_m[3] = (int8_T)b_varargout_2[3];
  memset(&board_programmer_B.rtb_ASCIItoString7_m[4], 0, 252U * sizeof(char_T));

  /* ScanString: '<Root>/String to Double1' incorporates:
   *  ASCIIToString: '<Root>/ASCII to String1'
   */
  rtb_StringtoDouble7 = 0U;
  sscanf(&board_programmer_B.rtb_ASCIItoString7_m[0], "%u", &rtb_StringtoDouble7);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  board_programmer_B.DataTypeConversion2 = (int32_T)rtb_StringtoDouble7;

  /* ASCIIToString: '<Root>/ASCII to String7' incorporates:
   *  MATLABSystem: '<Root>/Protocol Decoder1'
   */
  board_programmer_B.rtb_ASCIItoString7_c[0] = (int8_T)terminator[0];
  board_programmer_B.rtb_ASCIItoString7_c[1] = (int8_T)terminator[1];
  memset(&board_programmer_B.rtb_ASCIItoString7_c[2], 0, 254U * sizeof(char_T));

  /* ScanString: '<Root>/String to Double7' incorporates:
   *  ASCIIToString: '<Root>/ASCII to String7'
   */
  rtb_StringtoDouble7 = 0U;
  sscanf(&board_programmer_B.rtb_ASCIItoString7_c[0], "%u", &rtb_StringtoDouble7);

  /* DataTypeConversion: '<Root>/Data Type Conversion8' */
  board_programmer_B.DataTypeConversion8 = (int32_T)rtb_StringtoDouble7;

  /* MATLABSystem: '<S3>/Digital Output' incorporates:
   *  Constant: '<S3>/Constant'
   *  MATLABSystem: '<S3>/Digital Output1'
   *  MATLABSystem: '<S3>/Digital Output2'
   */
  board_programmer_B.d = rt_roundd_snf(board_programmer_P.Constant_Value_mc);
  if (board_programmer_B.d < 256.0) {
    if (board_programmer_B.d >= 0.0) {
      status = (uint8_T)board_programmer_B.d;
    } else {
      status = 0U;
    }
  } else {
    status = MAX_uint8_T;
  }

  writeDigitalPin(47, status);

  /* End of MATLABSystem: '<S3>/Digital Output' */

  /* MATLABSystem: '<S3>/Digital Output1' */
  if (board_programmer_B.d < 256.0) {
    if (board_programmer_B.d >= 0.0) {
      status = (uint8_T)board_programmer_B.d;
    } else {
      status = 0U;
    }
  } else {
    status = MAX_uint8_T;
  }

  writeDigitalPin(45, status);

  /* MATLABSystem: '<S3>/Digital Output2' */
  if (board_programmer_B.d < 256.0) {
    if (board_programmer_B.d >= 0.0) {
      status = (uint8_T)board_programmer_B.d;
    } else {
      status = 0U;
    }
  } else {
    status = MAX_uint8_T;
  }

  writeDigitalPin(43, status);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0051, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  board_programmer_M->Timing.clockTick1++;
  if (!board_programmer_M->Timing.clockTick1) {
    board_programmer_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void board_programmer_step2(void)      /* Sample time: [0.02s, 0.0s] */
{
  static const int64m_T tmp = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_0 = { { 0U, 2147483648U }/* chunks */
  };

  /* Reset subsysRan breadcrumbs */
  srClearBC(board_programmer_DW.Subsystem_SubsysRanBC_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(board_programmer_DW.Subsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(board_programmer_DW.controlloPP1.controlloPP1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(board_programmer_DW.Controllers_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(board_programmer_DW.Subsystem_SubsysRanBC);

  /* MATLABSystem: '<S1>/Digital Input1' */
  if (board_programmer_DW.obj_i.SampleTime !=
      board_programmer_P.DigitalInput1_SampleTime) {
    board_programmer_DW.obj_i.SampleTime =
      board_programmer_P.DigitalInput1_SampleTime;
  }

  board_programmer_B.rtb_DigitalInput1_d = readDigitalPin(53);

  /* MATLABSystem: '<S1>/Digital Input2' */
  if (board_programmer_DW.obj_lp.SampleTime !=
      board_programmer_P.DigitalInput2_SampleTime) {
    board_programmer_DW.obj_lp.SampleTime =
      board_programmer_P.DigitalInput2_SampleTime;
  }

  board_programmer_B.rtb_DigitalInput2_g = readDigitalPin(51);

  /* MATLABSystem: '<S1>/Digital Input' */
  if (board_programmer_DW.obj_e.SampleTime !=
      board_programmer_P.DigitalInput_SampleTime) {
    board_programmer_DW.obj_e.SampleTime =
      board_programmer_P.DigitalInput_SampleTime;
  }

  board_programmer_B.Compare = readDigitalPin(7);

  /* Logic: '<S1>/NOT1' incorporates:
   *  MATLABSystem: '<S1>/Digital Input'
   */
  board_programmer_B.NOT1 = !board_programmer_B.Compare;

  /* CCaller: '<S38>/C Caller' */
  touchRead(&board_programmer_B.CCaller_o1, &board_programmer_B.CCaller_o2,
            &board_programmer_B.CCaller_o3);

  /* Gain: '<S5>/Gain2' */
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

  board_programmer_B.rtb_Sum_k_j = (uint32_T)board_programmer_B.CCaller_o1;
  sMultiWordMul(&board_programmer_B.Sum_k, 1, &board_programmer_B.rtb_Sum_k_j, 1,
                &board_programmer_B.Gain3.chunks[0U], 2);

  /* End of Gain: '<S5>/Gain2' */

  /* Bias: '<S5>/Bias2' */
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

  /* End of Bias: '<S5>/Bias2' */

  /* Gain: '<S5>/Gain3' */
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

  board_programmer_B.rtb_Sum_k_j = (uint32_T)board_programmer_B.CCaller_o2;
  sMultiWordMul(&board_programmer_B.Sum_k, 1, &board_programmer_B.rtb_Sum_k_j, 1,
                &board_programmer_B.Gain3.chunks[0U], 2);

  /* End of Gain: '<S5>/Gain3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  board_programmer_B.DataTypeConversion[0] = sMultiWord2Double
    (&board_programmer_B.Bias2.chunks[0U], 2, 0) * 2.2737367544323206E-13;

  /* Bias: '<S5>/Bias3' */
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

  /* End of Bias: '<S5>/Bias3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  board_programmer_B.DataTypeConversion[1] = sMultiWord2Double
    (&board_programmer_B.r2.chunks[0U], 2, 0) * 2.2737367544323206E-13;

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  board_programmer_B.Compare = (board_programmer_B.CCaller_o3 >
    board_programmer_P.CompareToConstant_const);

  /* Outputs for Enabled SubSystem: '<Root>/Controllers' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (board_programmer_B.Compare) {
    board_programmer_DW.Controllers_MODE = true;

    /* SampleTimeMath: '<S31>/TSamp'
     *
     * About '<S31>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    board_programmer_B.TSamp = board_programmer_B.DataTypeConversion[0] *
      board_programmer_P.TSamp_WtEt;

    /* Sum: '<S31>/Diff' incorporates:
     *  UnitDelay: '<S31>/UD'
     */
    board_programmer_B.Diff_p = board_programmer_B.TSamp -
      board_programmer_DW.UD_DSTATE;
    board_progr_MovingAverage_p(board_programmer_B.Diff_p,
      &board_programmer_B.MovingAverage, &board_programmer_DW.MovingAverage);

    /* SampleTimeMath: '<S32>/TSamp'
     *
     * About '<S32>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    board_programmer_B.TSamp_b = board_programmer_B.DataTypeConversion[1] *
      board_programmer_P.TSamp_WtEt_g;

    /* Sum: '<S32>/Diff' incorporates:
     *  UnitDelay: '<S32>/UD'
     */
    board_programmer_B.Diff = board_programmer_B.TSamp_b -
      board_programmer_DW.UD_DSTATE_j;
    board_progr_MovingAverage_p(board_programmer_B.Diff,
      &board_programmer_B.MovingAverage1, &board_programmer_DW.MovingAverage1);

    /* CombinatorialLogic: '<S9>/Logic' incorporates:
     *  Constant: '<S6>/End Time Open'
     *  Delay: '<S6>/Delay1'
     *  Logic: '<S6>/NOT'
     *  Memory: '<S9>/Memory'
     *  RelationalOperator: '<S6>/Relational Operator'
     */
    board_programmer_B.rowIdx = (int32_T)(((((uint32_T)
      (board_programmer_P.EndTimeOpen_Value <= board_programmer_DW.Delay1_DSTATE)
      << 1) + !board_programmer_B.NOT1) << 1) +
      board_programmer_DW.Memory_PreviousInput);

    /* Outputs for Enabled SubSystem: '<S6>/Subsystem1' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    board_programmer_DW.Memory_PreviousInput = board_programmer_P.Logic_table
      [(uint32_T)board_programmer_B.rowIdx];
    if (board_programmer_DW.Memory_PreviousInput) {
      if (!board_programmer_DW.Subsystem1_MODE) {
        /* SystemReset for Atomic SubSystem: '<S11>/Timer with reset' */
        /* InitializeConditions for Delay: '<S23>/Delay1' */
        board_programmer_DW.Delay1_DSTATE_a =
          board_programmer_P.Delay1_InitialCondition;

        /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE =
          board_programmer_P.DiscreteTimeIntegrator_IC_c;
        board_programmer_DW.DiscreteTimeIntegrator_PrevRese = 2;

        /* End of SystemReset for SubSystem: '<S11>/Timer with reset' */
        board_programmer_DW.Subsystem1_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S11>/Timer with reset' */
      /* Logic: '<S23>/AND' incorporates:
       *  Constant: '<S11>/End Time Closed'
       *  Delay: '<S23>/Delay1'
       *  RelationalOperator: '<S23>/Relational Operator'
       */
      board_programmer_B.AND_e = (board_programmer_DW.Delay1_DSTATE_a >=
        board_programmer_P.EndTimeClosed_Value);

      /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
      if ((board_programmer_B.AND_e &&
           (board_programmer_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
          ((!board_programmer_B.AND_e) &&
           (board_programmer_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE =
          board_programmer_P.DiscreteTimeIntegrator_IC_c;
      }

      board_programmer_B.DiscreteTimeIntegrator_b =
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE;

      /* Update for Delay: '<S23>/Delay1' incorporates:
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       */
      board_programmer_DW.Delay1_DSTATE_a =
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE;

      /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S23>/Constant'
       */
      board_programmer_DW.DiscreteTimeIntegrator_DSTATE +=
        board_programmer_P.DiscreteTimeIntegrator_gainva_j *
        board_programmer_P.Constant_Value_c;
      board_programmer_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
        board_programmer_B.AND_e;

      /* End of Outputs for SubSystem: '<S11>/Timer with reset' */

      /* Gain: '<S11>/Gain1' */
      board_programmer_B.DiscreteTimeIntegrator_b *= 1.0 / board_programmer_P.h;

      /* PreLookup: '<S11>/Prelookup1' */
      board_programmer_B.Sum_k = plook_lincg
        (board_programmer_B.DiscreteTimeIntegrator_b,
         board_programmer_P.Prelookup1_BreakpointsData, 80U,
         &board_programmer_B.DiscreteTimeIntegrator_b);

      /* LookupNDDirect: '<S24>/[0]' incorporates:
       *  Sum: '<S19>/Sum'
       *
       * About '<S24>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset = (int32_T)board_programmer_B.rtb_Sum_k_j <<
        3;

      /* Sum: '<S24>/Sum' incorporates:
       *  Constant: '<S24>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_i;
      if (board_programmer_B.rtb_Sum_k_j < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_j = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S24>/[1]' incorporates:
       *  Sum: '<S24>/Sum'
       *
       * About '<S24>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_j > 80U) {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_g = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 3;

      /* LookupNDDirect: '<S25>/[0]' incorporates:
       *  Sum: '<S19>/Sum'
       *
       * About '<S25>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_m = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 2;

      /* Sum: '<S25>/Sum' incorporates:
       *  Constant: '<S25>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_m;
      if (board_programmer_B.rtb_Sum_k_j < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_j = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S25>/[1]' incorporates:
       *  Sum: '<S25>/Sum'
       *
       * About '<S25>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_j > 80U) {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_n = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 2;

      /* LookupNDDirect: '<S26>/[0]' incorporates:
       *  Sum: '<S19>/Sum'
       *
       * About '<S26>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_p = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 1;

      /* Sum: '<S26>/Sum' incorporates:
       *  Constant: '<S26>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_j;
      if (board_programmer_B.rtb_Sum_k_j < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_j = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S26>/[1]' incorporates:
       *  Sum: '<S26>/Sum'
       *
       * About '<S26>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_j > 80U) {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_l = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 1;
      for (board_programmer_B.qY = 0; board_programmer_B.qY < 8;
           board_programmer_B.qY++) {
        /* Sum: '<S24>/Sum3' incorporates:
         *  Fcn: '<S24>/Fcn'
         *  LookupNDDirect: '<S24>/[0]'
         *  LookupNDDirect: '<S24>/[1]'
         *  Product: '<S24>/1-lambda_x'
         *  Product: '<S24>/lambda_x.'
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
        board_programmer_B.dv[board_programmer_B.qY] = (1.0 -
          board_programmer_B.DiscreteTimeIntegrator_b) *
          board_programmer_P.circ1.open.lqr.K[board_programmer_B.qY +
          board_programmer_B.tableOffset] +
          board_programmer_P.circ1.open.lqr.K[board_programmer_B.qY +
          board_programmer_B.tableOffset_g] *
          board_programmer_B.DiscreteTimeIntegrator_b;
      }

      /* Sum: '<S11>/Sum2' incorporates:
       *  Fcn: '<S25>/Fcn'
       *  LookupNDDirect: '<S25>/[0]'
       *  LookupNDDirect: '<S25>/[1]'
       *  Product: '<S25>/1-lambda_x'
       *  Product: '<S25>/lambda_x.'
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
      board_programmer_B.unnamed_idx_0 = ((1.0 -
        board_programmer_B.DiscreteTimeIntegrator_b) *
        board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_m] +
        board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_n] *
        board_programmer_B.DiscreteTimeIntegrator_b) -
        board_programmer_B.MovingAverage.MovingAverage;
      board_programmer_B.unnamed_idx_1 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_m +
         1] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_b) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_n +
         1] * board_programmer_B.DiscreteTimeIntegrator_b) -
        board_programmer_B.DataTypeConversion[0];
      board_programmer_B.unnamed_idx_2 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_m +
         2] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_b) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_n +
         2] * board_programmer_B.DiscreteTimeIntegrator_b) -
        board_programmer_B.MovingAverage1.MovingAverage;
      board_programmer_B.unnamed_idx_3 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_m +
         3] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_b) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_n +
         3] * board_programmer_B.DiscreteTimeIntegrator_b) -
        board_programmer_B.DataTypeConversion[1];
      for (board_programmer_B.qY = 0; board_programmer_B.qY < 2;
           board_programmer_B.qY++) {
        /* Merge: '<Root>/Merge' incorporates:
         *  Fcn: '<S26>/Fcn'
         *  LookupNDDirect: '<S26>/[0]'
         *  LookupNDDirect: '<S26>/[1]'
         *  Product: '<S11>/Matrix Multiply1'
         *  Product: '<S26>/1-lambda_x'
         *  Product: '<S26>/lambda_x.'
         *  Sum: '<S11>/Sum3'
         *  Sum: '<S26>/Sum3'
         *
         * About '<S26>/[0]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         *
         * About '<S26>/[1]':
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
           board_programmer_B.tableOffset_p] * (1.0 -
            board_programmer_B.DiscreteTimeIntegrator_b) +
           board_programmer_P.circ1.open.lqr.uk[board_programmer_B.qY +
           board_programmer_B.tableOffset_l] *
           board_programmer_B.DiscreteTimeIntegrator_b);
      }

      srUpdateBC(board_programmer_DW.Subsystem1_SubsysRanBC);
    } else {
      board_programmer_DW.Subsystem1_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S6>/Subsystem1' */

    /* Logic: '<S6>/AND' incorporates:
     *  CombinatorialLogic: '<S9>/Logic'
     */
    board_programmer_B.NOT1 =
      (board_programmer_P.Logic_table[board_programmer_B.rowIdx + 8U] &&
       board_programmer_B.NOT1);

    /* Outputs for Enabled SubSystem: '<S6>/Subsystem' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    if (board_programmer_B.NOT1) {
      if (!board_programmer_DW.Subsystem_MODE) {
        /* SystemReset for Atomic SubSystem: '<S10>/Timer ' */
        /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o =
          board_programmer_P.DiscreteTimeIntegrator_IC;
        board_programmer_DW.DiscreteTimeIntegrator_PrevRe_a = 2;

        /* End of SystemReset for SubSystem: '<S10>/Timer ' */
        board_programmer_DW.Subsystem_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S10>/Timer ' */
      /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
      if (board_programmer_DW.DiscreteTimeIntegrator_PrevRe_a <= 0) {
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o =
          board_programmer_P.DiscreteTimeIntegrator_IC;
      }

      /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
      board_programmer_B.DiscreteTimeIntegrator =
        board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o;

      /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S16>/Constant'
       */
      board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o +=
        board_programmer_P.DiscreteTimeIntegrator_gainval *
        board_programmer_P.Constant_Value;
      board_programmer_DW.DiscreteTimeIntegrator_PrevRe_a = 1;

      /* End of Outputs for SubSystem: '<S10>/Timer ' */

      /* Gain: '<S10>/Gain' */
      board_programmer_B.DiscreteTimeIntegrator_b = 1.0 / board_programmer_P.h *
        board_programmer_B.DiscreteTimeIntegrator;

      /* PreLookup: '<S10>/Prelookup2' */
      board_programmer_B.Sum_k = plook_lincg
        (board_programmer_B.DiscreteTimeIntegrator_b,
         board_programmer_P.Prelookup2_BreakpointsData, 80U,
         &board_programmer_B.DiscreteTimeIntegrator_b);

      /* LookupNDDirect: '<S17>/[0]' incorporates:
       *  PreLookup: '<S10>/Prelookup2'
       *
       * About '<S17>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset = (int32_T)board_programmer_B.rtb_Sum_k_j <<
        3;

      /* Sum: '<S17>/Sum' incorporates:
       *  Constant: '<S17>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value;
      if (board_programmer_B.rtb_Sum_k_j < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_j = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S17>/[1]' incorporates:
       *  Sum: '<S17>/Sum'
       *
       * About '<S17>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_j > 80U) {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_g = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 3;

      /* LookupNDDirect: '<S18>/[0]' incorporates:
       *  PreLookup: '<S10>/Prelookup2'
       *
       * About '<S18>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_m = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 2;

      /* Sum: '<S18>/Sum' incorporates:
       *  Constant: '<S18>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_g;
      if (board_programmer_B.rtb_Sum_k_j < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_j = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S18>/[1]' incorporates:
       *  Sum: '<S18>/Sum'
       *
       * About '<S18>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_j > 80U) {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_n = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 2;

      /* LookupNDDirect: '<S19>/[0]' incorporates:
       *  PreLookup: '<S10>/Prelookup2'
       *
       * About '<S19>/[0]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.Sum_k <= 80U) {
        board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k;
      } else {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_p = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 1;

      /* Sum: '<S19>/Sum' incorporates:
       *  Constant: '<S19>/offset for upper index 1'
       */
      board_programmer_B.rtb_Sum_k_j = board_programmer_B.Sum_k +
        board_programmer_P.offsetforupperindex1_Value_a;
      if (board_programmer_B.rtb_Sum_k_j < board_programmer_B.Sum_k) {
        board_programmer_B.rtb_Sum_k_j = MAX_uint32_T;
      }

      /* LookupNDDirect: '<S19>/[1]' incorporates:
       *  Sum: '<S19>/Sum'
       *
       * About '<S19>/[1]':
       *  3-dimensional Direct Look-Up returning a 2-D Matrix,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (board_programmer_B.rtb_Sum_k_j > 80U) {
        board_programmer_B.rtb_Sum_k_j = 80U;
      }

      board_programmer_B.tableOffset_l = (int32_T)board_programmer_B.rtb_Sum_k_j
        << 1;
      for (board_programmer_B.qY = 0; board_programmer_B.qY < 8;
           board_programmer_B.qY++) {
        /* Sum: '<S17>/Sum3' incorporates:
         *  Fcn: '<S17>/Fcn'
         *  LookupNDDirect: '<S17>/[0]'
         *  LookupNDDirect: '<S17>/[1]'
         *  Product: '<S17>/1-lambda_x'
         *  Product: '<S17>/lambda_x.'
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
        board_programmer_B.dv[board_programmer_B.qY] = (1.0 -
          board_programmer_B.DiscreteTimeIntegrator_b) *
          board_programmer_P.circ1.open.lqr.K[board_programmer_B.qY +
          board_programmer_B.tableOffset] +
          board_programmer_P.circ1.open.lqr.K[board_programmer_B.qY +
          board_programmer_B.tableOffset_g] *
          board_programmer_B.DiscreteTimeIntegrator_b;
      }

      /* Sum: '<S10>/Sum' incorporates:
       *  Fcn: '<S18>/Fcn'
       *  LookupNDDirect: '<S18>/[0]'
       *  LookupNDDirect: '<S18>/[1]'
       *  Product: '<S18>/1-lambda_x'
       *  Product: '<S18>/lambda_x.'
       *  Sum: '<S18>/Sum3'
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
      board_programmer_B.unnamed_idx_0 = ((1.0 -
        board_programmer_B.DiscreteTimeIntegrator_b) *
        board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_m] +
        board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_n] *
        board_programmer_B.DiscreteTimeIntegrator_b) -
        board_programmer_B.MovingAverage.MovingAverage;
      board_programmer_B.unnamed_idx_1 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_m +
         1] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_b) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_n +
         1] * board_programmer_B.DiscreteTimeIntegrator_b) -
        board_programmer_B.DataTypeConversion[0];
      board_programmer_B.unnamed_idx_2 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_m +
         2] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_b) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_n +
         2] * board_programmer_B.DiscreteTimeIntegrator_b) -
        board_programmer_B.MovingAverage1.MovingAverage;
      board_programmer_B.unnamed_idx_3 =
        (board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_m +
         3] * (1.0 - board_programmer_B.DiscreteTimeIntegrator_b) +
         board_programmer_P.circ1.open.lqr.xk[board_programmer_B.tableOffset_n +
         3] * board_programmer_B.DiscreteTimeIntegrator_b) -
        board_programmer_B.DataTypeConversion[1];
      for (board_programmer_B.qY = 0; board_programmer_B.qY < 2;
           board_programmer_B.qY++) {
        /* Sum: '<S10>/Sum1' incorporates:
         *  Fcn: '<S19>/Fcn'
         *  LookupNDDirect: '<S19>/[0]'
         *  LookupNDDirect: '<S19>/[1]'
         *  Product: '<S10>/Matrix Multiply'
         *  Product: '<S19>/1-lambda_x'
         *  Product: '<S19>/lambda_x.'
         *  Sum: '<S19>/Sum3'
         *
         * About '<S19>/[0]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         *
         * About '<S19>/[1]':
         *  3-dimensional Direct Look-Up returning a 2-D Matrix,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        board_programmer_B.Sum1[board_programmer_B.qY] =
          (((board_programmer_B.dv[board_programmer_B.qY + 2] *
             board_programmer_B.unnamed_idx_1 +
             board_programmer_B.dv[board_programmer_B.qY] *
             board_programmer_B.unnamed_idx_0) +
            board_programmer_B.dv[board_programmer_B.qY + 4] *
            board_programmer_B.unnamed_idx_2) +
           board_programmer_B.dv[board_programmer_B.qY + 6] *
           board_programmer_B.unnamed_idx_3) +
          (board_programmer_P.circ1.open.lqr.uk[board_programmer_B.qY +
           board_programmer_B.tableOffset_p] * (1.0 -
            board_programmer_B.DiscreteTimeIntegrator_b) +
           board_programmer_P.circ1.open.lqr.uk[board_programmer_B.qY +
           board_programmer_B.tableOffset_l] *
           board_programmer_B.DiscreteTimeIntegrator_b);
      }

      /* Merge: '<Root>/Merge' incorporates:
       *  SignalConversion generated from: '<S10>/Out3'
       *  Sum: '<S10>/Sum1'
       */
      board_programmer_B.Merge[0] = board_programmer_B.Sum1[0];
      board_programmer_B.Merge[1] = board_programmer_B.Sum1[1];
      srUpdateBC(board_programmer_DW.Subsystem_SubsysRanBC_j);
    } else {
      board_programmer_DW.Subsystem_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S6>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S6>/controllo PP 1' */
    /* Logic: '<S6>/AND1' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Logic: '<S6>/NOT1'
     *  Logic: '<S6>/NOT2'
     */
    board_programm_controlloPP1((!board_programmer_DW.Memory_PreviousInput) && (
      !board_programmer_B.NOT1), board_programmer_P.circ1.open.lqr.start,
      board_programmer_B.DataTypeConversion, board_programmer_B.Merge,
      &board_programmer_B.controlloPP1, &board_programmer_DW.controlloPP1,
      &board_programmer_P.controlloPP1);

    /* End of Outputs for SubSystem: '<S6>/controllo PP 1' */

    /* Outputs for Enabled SubSystem: '<S2>/controllo PP 1' */
    /* Logic: '<S1>/NOT3' incorporates:
     *  Constant: '<S2>/Constant'
     *  MATLABSystem: '<S1>/Digital Input2'
     */
    board_programm_controlloPP1(!board_programmer_B.rtb_DigitalInput2_g,
      board_programmer_P.Constant_Value_m, board_programmer_B.DataTypeConversion,
      board_programmer_B.Merge, &board_programmer_B.controlloPP1_d,
      &board_programmer_DW.controlloPP1_d, &board_programmer_P.controlloPP1_d);

    /* End of Outputs for SubSystem: '<S2>/controllo PP 1' */

    /* Update for UnitDelay: '<S31>/UD' */
    board_programmer_DW.UD_DSTATE = board_programmer_B.TSamp;

    /* Update for UnitDelay: '<S32>/UD' */
    board_programmer_DW.UD_DSTATE_j = board_programmer_B.TSamp_b;

    /* Update for Delay: '<S6>/Delay1' */
    board_programmer_DW.Delay1_DSTATE =
      board_programmer_B.DiscreteTimeIntegrator;
    srUpdateBC(board_programmer_DW.Controllers_SubsysRanBC);
  } else if (board_programmer_DW.Controllers_MODE) {
    /* Disable for Enabled SubSystem: '<S6>/Subsystem1' */
    board_programmer_DW.Subsystem1_MODE = false;

    /* End of Disable for SubSystem: '<S6>/Subsystem1' */

    /* Disable for Enabled SubSystem: '<S6>/Subsystem' */
    board_programmer_DW.Subsystem_MODE = false;

    /* End of Disable for SubSystem: '<S6>/Subsystem' */

    /* Disable for Enabled SubSystem: '<S6>/controllo PP 1' */
    if (board_programmer_DW.controlloPP1.controlloPP1_MODE) {
      board__controlloPP1_Disable(&board_programmer_DW.controlloPP1);
    }

    /* End of Disable for SubSystem: '<S6>/controllo PP 1' */

    /* Disable for Enabled SubSystem: '<S2>/controllo PP 1' */
    if (board_programmer_DW.controlloPP1_d.controlloPP1_MODE) {
      board__controlloPP1_Disable(&board_programmer_DW.controlloPP1_d);
    }

    /* End of Disable for SubSystem: '<S2>/controllo PP 1' */
    board_programmer_DW.Controllers_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/Controllers' */

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Logic: '<Root>/OR' incorporates:
   *  Logic: '<Root>/NOT'
   *  Logic: '<S1>/AND'
   *  Logic: '<S1>/NOT4'
   *  MATLABSystem: '<S1>/Digital Input1'
   *  MATLABSystem: '<S1>/Digital Input2'
   */
  if ((!board_programmer_B.rtb_DigitalInput1_d) ||
      (!board_programmer_B.rtb_DigitalInput2_g) || (!board_programmer_B.Compare))
  {
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S4>/Constant1'
     *  SignalConversion generated from: '<S4>/theta'
     */
    board_programmer_B.Merge[0] = board_programmer_P.Constant1_Value[0];
    board_programmer_B.Merge[1] = board_programmer_P.Constant1_Value[1];
    srUpdateBC(board_programmer_DW.Subsystem_SubsysRanBC);
  }

  /* End of Logic: '<Root>/OR' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* DataTypeConversion: '<S38>/Data Type Conversion3' incorporates:
   *  Bias: '<S5>/Bias'
   *  Gain: '<S5>/Gain'
   */
  board_programmer_B.TSamp = rt_roundd_snf
    (board_programmer_P.pwm.thX.real2raw_gain * board_programmer_B.Merge[0] +
     board_programmer_P.pwm.thX.real2raw_bias);
  if (rtIsNaN(board_programmer_B.TSamp) || rtIsInf(board_programmer_B.TSamp)) {
    board_programmer_B.TSamp = 0.0;
  } else {
    board_programmer_B.TSamp = fmod(board_programmer_B.TSamp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S38>/Data Type Conversion3' */
  board_programmer_B.DataTypeConversion3 = board_programmer_B.TSamp < 0.0 ?
    -(int32_T)(uint32_T)-board_programmer_B.TSamp : (int32_T)(uint32_T)
    board_programmer_B.TSamp;

  /* S-Function (double2ascii): '<S38>/C//C++ Code Block3' */
  double2ascii_Outputs_wrapper(&board_programmer_B.DataTypeConversion3,
    &board_programmer_B.CCCodeBlock3[0]);

  /* DataTypeConversion: '<S38>/Data Type Conversion4' incorporates:
   *  Bias: '<S5>/Bias1'
   *  Gain: '<S5>/Gain1'
   */
  board_programmer_B.TSamp = rt_roundd_snf
    (board_programmer_P.pwm.thY.real2raw_gain * board_programmer_B.Merge[1] +
     board_programmer_P.pwm.thY.real2raw_bias);
  if (rtIsNaN(board_programmer_B.TSamp) || rtIsInf(board_programmer_B.TSamp)) {
    board_programmer_B.TSamp = 0.0;
  } else {
    board_programmer_B.TSamp = fmod(board_programmer_B.TSamp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S38>/Data Type Conversion4' */
  board_programmer_B.DataTypeConversion4 = board_programmer_B.TSamp < 0.0 ?
    -(int32_T)(uint32_T)-board_programmer_B.TSamp : (int32_T)(uint32_T)
    board_programmer_B.TSamp;

  /* S-Function (double2ascii): '<S38>/C//C++ Code Block4' */
  double2ascii_Outputs_wrapper(&board_programmer_B.DataTypeConversion4,
    &board_programmer_B.CCCodeBlock4[0]);

  /* MATLABSystem: '<S38>/Protocol Encoder1' incorporates:
   *  MATLABSystem: '<S38>/Serial Transmit1'
   *  S-Function (double2ascii): '<S38>/C//C++ Code Block3'
   *  S-Function (double2ascii): '<S38>/C//C++ Code Block4'
   */
  if (board_programmer_DW.obj_a.TunablePropsChanged) {
    board_programmer_DW.obj_a.TunablePropsChanged = false;
  }

  board_programmer_B.dataIn[0] = 64U;
  board_programmer_B.inDataIdx = 1U;
  board_programmer_B.dataIn[1] = 0U;
  board_programmer_B.dataIn[2] = 0U;
  board_programmer_B.dataIn[3] = 0U;
  board_programmer_B.dataIn[4] = 0U;
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
  board_programmer_B.dataIn[5] = 0U;
  board_programmer_B.dataIn[6] = 0U;
  board_programmer_B.dataIn[7] = 0U;
  board_programmer_B.dataIn[8] = 0U;
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
    ProtocolEncoderBase_get_DataTyp(board_programmer_B.uv2);
    board_programmer_B.Sum_k = (uint32_T)board_programmer_B.outIdx +
      board_programmer_B.uv2[1];
    if (board_programmer_B.Sum_k > 65535U) {
      board_programmer_B.Sum_k = 65535U;
    }

    board_programmer_B.outIdx = (uint16_T)board_programmer_B.Sum_k;
    board_programmer_B.inDataIdx++;
  }

  board_programmer_B.dataIn[9] = 13U;
  board_programmer_B.dataIn[10] = 10U;

  /* End of MATLABSystem: '<S38>/Protocol Encoder1' */

  /* MATLABSystem: '<S38>/Serial Transmit1' */
  if (board_programmer_DW.obj_j.Protocol !=
      board_programmer_P.SerialTransmit1_Protocol) {
    board_programmer_DW.obj_j.Protocol =
      board_programmer_P.SerialTransmit1_Protocol;
  }

  MW_Serial_write(board_programmer_DW.obj_j.port, &board_programmer_B.dataIn[0],
                  11.0, board_programmer_DW.obj_j.dataSizeInBytes,
                  board_programmer_DW.obj_j.sendModeEnum,
                  board_programmer_DW.obj_j.dataType,
                  board_programmer_DW.obj_j.sendFormatEnum, 2.0, '\x00');

  /* S-Function (double2ascii): '<S38>/C//C++ Code Block5' */
  double2ascii_Outputs_wrapper(&board_programmer_B.CCaller_o1,
    &board_programmer_B.CCCodeBlock5[0]);

  /* S-Function (double2ascii): '<S38>/C//C++ Code Block6' */
  double2ascii_Outputs_wrapper(&board_programmer_B.CCaller_o2,
    &board_programmer_B.CCCodeBlock6[0]);

  /* S-Function (double2ascii): '<S38>/C//C++ Code Block7' */
  double2ascii_Outputs_wrapper(&board_programmer_B.CCaller_o3,
    &board_programmer_B.CCCodeBlock7[0]);

  /* MATLABSystem: '<S38>/Protocol Encoder2' */
  if (board_programmer_DW.obj.TunablePropsChanged) {
    board_programmer_DW.obj.TunablePropsChanged = false;
  }

  /* End of MATLABSystem: '<S38>/Protocol Encoder2' */

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  board_programmer_M->Timing.clockTick2++;
  if (!board_programmer_M->Timing.clockTick2) {
    board_programmer_M->Timing.clockTickH2++;
  }
}

/* Model initialize function */
void board_programmer_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)board_programmer_M, 0,
                sizeof(RT_MODEL_board_programmer_T));
  rtmSetTFinal(board_programmer_M, -1);
  board_programmer_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  board_programmer_M->Sizes.checksums[0] = (470233135U);
  board_programmer_M->Sizes.checksums[1] = (2722852592U);
  board_programmer_M->Sizes.checksums[2] = (3930600403U);
  board_programmer_M->Sizes.checksums[3] = (2429703267U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[26];
    board_programmer_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&board_programmer_DW.Subsystem_SubsysRanBC_j;
    systemRan[5] = (sysRanDType *)&board_programmer_DW.Subsystem_SubsysRanBC_j;
    systemRan[6] = (sysRanDType *)&board_programmer_DW.Subsystem1_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&board_programmer_DW.Subsystem1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &board_programmer_DW.controlloPP1.controlloPP1_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &board_programmer_DW.controlloPP1.controlloPP1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &board_programmer_DW.controlloPP1.controlloPP1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&board_programmer_DW.Controllers_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&board_programmer_DW.Controllers_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &board_programmer_DW.controlloPP1_d.controlloPP1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &board_programmer_DW.controlloPP1_d.controlloPP1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &board_programmer_DW.controlloPP1_d.controlloPP1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&board_programmer_DW.Controllers_SubsysRanBC;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = (sysRanDType *)&board_programmer_DW.Subsystem_SubsysRanBC;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(board_programmer_M->extModeInfo,
      &board_programmer_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(board_programmer_M->extModeInfo,
                        board_programmer_M->Sizes.checksums);
    rteiSetTPtr(board_programmer_M->extModeInfo, rtmGetTPtr(board_programmer_M));
  }

  /* block I/O */
  (void) memset(((void *) &board_programmer_B), 0,
                sizeof(B_board_programmer_T));

  /* states (dwork) */
  (void) memset((void *)&board_programmer_DW, 0,
                sizeof(DW_board_programmer_T));

  {
    real_T tmp;
    uint32_T tmp_0;
    uint8_T tmp_1;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    board_programmer_DW.obj_l.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_a = true;
    board_programmer_DW.obj_l.Protocol =
      board_programmer_P.SerialReceive_Protocol;
    board_programmer_DW.obj_l.isInitialized = 1;
    board_programmer_DW.obj_l.DataTypeWidth = 1U;
    tmp_0 = 12U * board_programmer_DW.obj_l.DataTypeWidth;
    if (tmp_0 > 65535U) {
      tmp_0 = 65535U;
    }

    board_programmer_DW.obj_l.DataSizeInBytes = (uint16_T)tmp_0;
    MW_SCI_Open(1);
    board_programmer_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Receive' */

    /* Start for MATLABSystem: '<Root>/Protocol Decoder1' */
    board_programmer_DW.obj_f.isInitialized = 0;
    board_programmer_DW.obj_f.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_pr = true;
    board_programm_SystemCore_setup(&board_programmer_DW.obj_f);

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    board_programmer_DW.obj_c.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_l = true;
    board_programmer_DW.obj_c.isInitialized = 1;
    digitalIOSetup(47, 1);
    board_programmer_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Output1' */
    board_programmer_DW.obj_fp.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_f = true;
    board_programmer_DW.obj_fp.isInitialized = 1;
    digitalIOSetup(45, 1);
    board_programmer_DW.obj_fp.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Output2' */
    board_programmer_DW.obj_n.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_o = true;
    board_programmer_DW.obj_n.isInitialized = 1;
    digitalIOSetup(43, 1);
    board_programmer_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Input1' */
    board_programmer_DW.obj_i.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_fl = true;
    board_programmer_DW.obj_i.SampleTime =
      board_programmer_P.DigitalInput1_SampleTime;
    board_programmer_DW.obj_i.isInitialized = 1;
    digitalIOSetup(53, 2.0);
    board_programmer_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Input2' */
    board_programmer_DW.obj_lp.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_b = true;
    board_programmer_DW.obj_lp.SampleTime =
      board_programmer_P.DigitalInput2_SampleTime;
    board_programmer_DW.obj_lp.isInitialized = 1;
    digitalIOSetup(51, 2.0);
    board_programmer_DW.obj_lp.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Input' */
    board_programmer_DW.obj_e.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_g = true;
    board_programmer_DW.obj_e.SampleTime =
      board_programmer_P.DigitalInput_SampleTime;
    board_programmer_DW.obj_e.isInitialized = 1;
    digitalIOSetup(7, 2.0);
    board_programmer_DW.obj_e.isSetupComplete = true;

    /* Start for Enabled SubSystem: '<Root>/Controllers' */
    board_programmer_DW.Controllers_MODE = false;
    board_MovingAverage_g_Start(&board_programmer_DW.MovingAverage);
    board_MovingAverage_g_Start(&board_programmer_DW.MovingAverage1);

    /* Start for Enabled SubSystem: '<S6>/Subsystem1' */
    board_programmer_DW.Subsystem1_MODE = false;

    /* End of Start for SubSystem: '<S6>/Subsystem1' */

    /* Start for Enabled SubSystem: '<S6>/Subsystem' */
    board_programmer_DW.Subsystem_MODE = false;

    /* Start for Enabled SubSystem: '<S6>/controllo PP 1' */
    board_pr_controlloPP1_Start(&board_programmer_DW.controlloPP1);

    /* End of Start for SubSystem: '<S6>/controllo PP 1' */

    /* Start for Enabled SubSystem: '<S2>/controllo PP 1' */
    board_pr_controlloPP1_Start(&board_programmer_DW.controlloPP1_d);

    /* End of Start for SubSystem: '<S2>/controllo PP 1' */

    /* Start for MATLABSystem: '<S38>/Protocol Encoder1' */
    board_programmer_DW.obj_a.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_d = true;
    board_programmer_DW.obj_a.isInitialized = 1;
    board_programmer_DW.obj_a.isSetupComplete = true;
    board_programmer_DW.obj_a.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<S38>/Serial Transmit1' */
    board_programmer_DW.obj_j.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty = true;
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
        tmp_1 = (uint8_T)tmp;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_1);
    board_programmer_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S38>/Serial Transmit1' */

    /* Start for MATLABSystem: '<S38>/Protocol Encoder2' */
    board_programmer_DW.obj.matlabCodegenIsDeleted = false;
    board_programmer_DW.objisempty_p = true;
    board_programmer_DW.obj.isInitialized = 1;
    board_programmer_DW.obj.isSetupComplete = true;
    board_programmer_DW.obj.TunablePropsChanged = false;
  }

  /* SystemInitialize for Enabled SubSystem: '<Root>/Controllers' */
  /* InitializeConditions for UnitDelay: '<S31>/UD' */
  board_programmer_DW.UD_DSTATE =
    board_programmer_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S32>/UD' */
  board_programmer_DW.UD_DSTATE_j =
    board_programmer_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  board_programmer_DW.Delay1_DSTATE =
    board_programmer_P.Delay1_InitialCondition_p;

  /* InitializeConditions for Enabled SubSystem: '<S6>/Subsystem1' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* InitializeConditions for Memory: '<S9>/Memory' */
  board_programmer_DW.Memory_PreviousInput =
    board_programmer_P.SRFlipFlop_initial_condition;

  /* SystemInitialize for Enabled SubSystem: '<S6>/Subsystem1' */
  /* SystemInitialize for Atomic SubSystem: '<S11>/Timer with reset' */
  /* InitializeConditions for Delay: '<S23>/Delay1' */
  board_programmer_DW.Delay1_DSTATE_a =
    board_programmer_P.Delay1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
  board_programmer_DW.DiscreteTimeIntegrator_DSTATE =
    board_programmer_P.DiscreteTimeIntegrator_IC_c;
  board_programmer_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* End of SystemInitialize for SubSystem: '<S11>/Timer with reset' */
  /* End of SystemInitialize for SubSystem: '<S6>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S6>/Subsystem' */
  /* SystemInitialize for Atomic SubSystem: '<S10>/Timer ' */
  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  board_programmer_DW.DiscreteTimeIntegrator_DSTATE_o =
    board_programmer_P.DiscreteTimeIntegrator_IC;
  board_programmer_DW.DiscreteTimeIntegrator_PrevRe_a = 2;

  /* End of SystemInitialize for SubSystem: '<S10>/Timer ' */

  /* SystemInitialize for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Outport: '<S10>/time'
   */
  board_programmer_B.DiscreteTimeIntegrator = board_programmer_P.time_Y0;

  /* End of SystemInitialize for SubSystem: '<S6>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S6>/controllo PP 1' */
  board_pro_controlloPP1_Init(&board_programmer_DW.controlloPP1,
    &board_programmer_P.controlloPP1);

  /* End of SystemInitialize for SubSystem: '<S6>/controllo PP 1' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/controllo PP 1' */
  board_pro_controlloPP1_Init(&board_programmer_DW.controlloPP1_d,
    &board_programmer_P.controlloPP1_d);

  /* End of SystemInitialize for SubSystem: '<S2>/controllo PP 1' */
  board__MovingAverage_p_Init(&board_programmer_DW.MovingAverage);
  board__MovingAverage_p_Init(&board_programmer_DW.MovingAverage1);

  /* End of SystemInitialize for SubSystem: '<Root>/Controllers' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  board_programmer_B.Merge[0] = board_programmer_P.Merge_InitialOutput;
  board_programmer_B.Merge[1] = board_programmer_P.Merge_InitialOutput;
}

/* Model terminate function */
void board_programmer_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!board_programmer_DW.obj_l.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/Protocol Decoder1' */
  if (!board_programmer_DW.obj_f.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Protocol Decoder1' */
  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!board_programmer_DW.obj_c.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output1' */
  if (!board_programmer_DW.obj_fp.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_fp.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output2' */
  if (!board_programmer_DW.obj_n.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S1>/Digital Input1' */
  if (!board_programmer_DW.obj_i.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Input1' */

  /* Terminate for MATLABSystem: '<S1>/Digital Input2' */
  if (!board_programmer_DW.obj_lp.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_lp.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Input2' */

  /* Terminate for MATLABSystem: '<S1>/Digital Input' */
  if (!board_programmer_DW.obj_e.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Input' */

  /* Terminate for Enabled SubSystem: '<Root>/Controllers' */
  board__MovingAverage_d_Term(&board_programmer_DW.MovingAverage);
  board__MovingAverage_d_Term(&board_programmer_DW.MovingAverage1);

  /* Terminate for Enabled SubSystem: '<S6>/controllo PP 1' */
  board_pro_controlloPP1_Term(&board_programmer_DW.controlloPP1);

  /* End of Terminate for SubSystem: '<S6>/controllo PP 1' */

  /* Terminate for Enabled SubSystem: '<S2>/controllo PP 1' */
  board_pro_controlloPP1_Term(&board_programmer_DW.controlloPP1_d);

  /* End of Terminate for SubSystem: '<S2>/controllo PP 1' */

  /* Terminate for MATLABSystem: '<S38>/Protocol Encoder1' */
  if (!board_programmer_DW.obj_a.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S38>/Protocol Encoder1' */

  /* Terminate for MATLABSystem: '<S38>/Serial Transmit1' */
  if (!board_programmer_DW.obj_j.matlabCodegenIsDeleted) {
    board_programmer_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S38>/Serial Transmit1' */

  /* Terminate for MATLABSystem: '<S38>/Protocol Encoder2' */
  if (!board_programmer_DW.obj.matlabCodegenIsDeleted) {
    board_programmer_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S38>/Protocol Encoder2' */
}
