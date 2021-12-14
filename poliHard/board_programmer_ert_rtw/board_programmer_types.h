/*
 * board_programmer_types.h
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

#ifndef RTW_HEADER_board_programmer_types_h_
#define RTW_HEADER_board_programmer_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_JPcja6edXKWr46QNLtmIqF_
#define DEFINED_TYPEDEF_FOR_struct_JPcja6edXKWr46QNLtmIqF_

typedef struct {
  real_T P[16];
  real_T Q[16];
  real_T R[4];
  real_T t[301];
  real_T u[600];
  real_T x[1204];
  real_T xref[1204];
} struct_JPcja6edXKWr46QNLtmIqF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_wJc9tatOqAirtnyX8knTdD_
#define DEFINED_TYPEDEF_FOR_struct_wJc9tatOqAirtnyX8knTdD_

typedef struct {
  real_T uk[162];
  real_T xk[324];
  real_T K[648];
  real_T IC[4];
  real_T T[81];
  real_T N;
  real_T start[2];
} struct_wJc9tatOqAirtnyX8knTdD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_weNVlWBZbZ0OZ2J0ZCVHbH_
#define DEFINED_TYPEDEF_FOR_struct_weNVlWBZbZ0OZ2J0ZCVHbH_

typedef struct {
  struct_JPcja6edXKWr46QNLtmIqF opt;
  struct_wJc9tatOqAirtnyX8knTdD lqr;
} struct_weNVlWBZbZ0OZ2J0ZCVHbH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_niyjK1YQs0CaQXrM5YwP5G_
#define DEFINED_TYPEDEF_FOR_struct_niyjK1YQs0CaQXrM5YwP5G_

typedef struct {
  struct_weNVlWBZbZ0OZ2J0ZCVHbH open;
  struct_weNVlWBZbZ0OZ2J0ZCVHbH closed;
} struct_niyjK1YQs0CaQXrM5YwP5G;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_5eb5WpGlM4ku9RSV6RDqG_
#define DEFINED_TYPEDEF_FOR_struct_5eb5WpGlM4ku9RSV6RDqG_

typedef struct {
  real_T Kx[3];
  real_T Kxi;
  real_T Ky[3];
  real_T Kyi;
} struct_5eb5WpGlM4ku9RSV6RDqG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BGDNKOO7IhhATN5MccaVJC_
#define DEFINED_TYPEDEF_FOR_struct_BGDNKOO7IhhATN5MccaVJC_

typedef struct {
  real_T real[2];
  real_T raw[2];
  real_T raw2real_poly[2];
  real_T real2raw_poly[2];
  real_T real2raw_gain;
  real_T real2raw_bias;
} struct_BGDNKOO7IhhATN5MccaVJC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_2daG3D4sIUVlLRg8l9bwKC_
#define DEFINED_TYPEDEF_FOR_struct_2daG3D4sIUVlLRg8l9bwKC_

typedef struct {
  struct_BGDNKOO7IhhATN5MccaVJC thX;
  struct_BGDNKOO7IhhATN5MccaVJC thY;
} struct_2daG3D4sIUVlLRg8l9bwKC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_B5NBdw4sWD16lecuE7kHNC_
#define DEFINED_TYPEDEF_FOR_struct_B5NBdw4sWD16lecuE7kHNC_

typedef struct {
  real_T real[9];
  real_T raw[9];
  real_T poly[2];
  real_T gain;
  real_T bias;
} struct_B5NBdw4sWD16lecuE7kHNC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_oblq0bpnSFbyCkjpduvbqF_
#define DEFINED_TYPEDEF_FOR_struct_oblq0bpnSFbyCkjpduvbqF_

typedef struct {
  real_T real[7];
  real_T raw[7];
  real_T poly[2];
  real_T gain;
  real_T bias;
} struct_oblq0bpnSFbyCkjpduvbqF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_TL40Sm6Yho660LrrvvBZDD_
#define DEFINED_TYPEDEF_FOR_struct_TL40Sm6Yho660LrrvvBZDD_

typedef struct {
  struct_B5NBdw4sWD16lecuE7kHNC x;
  struct_oblq0bpnSFbyCkjpduvbqF y;
} struct_TL40Sm6Yho660LrrvvBZDD;

#endif

#ifndef struct_tag_4B5c9t1JtSUztS9hrJrCFG
#define struct_tag_4B5c9t1JtSUztS9hrJrCFG

struct tag_4B5c9t1JtSUztS9hrJrCFG
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[9];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_4B5c9t1JtSUztS9hrJrCFG */

#ifndef typedef_g_dsp_internal_SlidingWindowA_T
#define typedef_g_dsp_internal_SlidingWindowA_T

typedef struct tag_4B5c9t1JtSUztS9hrJrCFG g_dsp_internal_SlidingWindowA_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindowA_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_board_programmer_T
#define typedef_cell_wrap_board_programmer_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_board_programmer_T;

#endif                                /* typedef_cell_wrap_board_programmer_T */

#ifndef struct_tag_fvggScuiyshoksoPP6S2aF
#define struct_tag_fvggScuiyshoksoPP6S2aF

struct tag_fvggScuiyshoksoPP6S2aF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_board_programmer_T inputVarSize;
  g_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                 /* struct_tag_fvggScuiyshoksoPP6S2aF */

#ifndef typedef_dsp_simulink_MovingAverage_bo_T
#define typedef_dsp_simulink_MovingAverage_bo_T

typedef struct tag_fvggScuiyshoksoPP6S2aF dsp_simulink_MovingAverage_bo_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_bo_T */

#ifndef struct_tag_twKmvSwtXFvwm110YFDILC
#define struct_tag_twKmvSwtXFvwm110YFDILC

struct tag_twKmvSwtXFvwm110YFDILC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[4];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_twKmvSwtXFvwm110YFDILC */

#ifndef typedef_g_dsp_internal_SlidingWindo_l_T
#define typedef_g_dsp_internal_SlidingWindo_l_T

typedef struct tag_twKmvSwtXFvwm110YFDILC g_dsp_internal_SlidingWindo_l_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindo_l_T */

#ifndef struct_tag_VSW2YOpcQ0JoSsliuYZ3uD
#define struct_tag_VSW2YOpcQ0JoSsliuYZ3uD

struct tag_VSW2YOpcQ0JoSsliuYZ3uD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_board_programmer_T inputVarSize;
  g_dsp_internal_SlidingWindo_l_T *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindo_l_T _pobj0;
};

#endif                                 /* struct_tag_VSW2YOpcQ0JoSsliuYZ3uD */

#ifndef typedef_dsp_simulink_MovingAverage_e_T
#define typedef_dsp_simulink_MovingAverage_e_T

typedef struct tag_VSW2YOpcQ0JoSsliuYZ3uD dsp_simulink_MovingAverage_e_T;

#endif                              /* typedef_dsp_simulink_MovingAverage_e_T */

#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_d_arduinodriver_ArduinoDigita_T
#define typedef_d_arduinodriver_ArduinoDigita_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C d_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_d_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_mPMPiw8t0JZKYO8orfnwRG
#define struct_tag_mPMPiw8t0JZKYO8orfnwRG

struct tag_mPMPiw8t0JZKYO8orfnwRG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_mPMPiw8t0JZKYO8orfnwRG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_mPMPiw8t0JZKYO8orfnwRG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_qrLkTWTW64zZK0sqwALTyG
#define struct_tag_qrLkTWTW64zZK0sqwALTyG

struct tag_qrLkTWTW64zZK0sqwALTyG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_qrLkTWTW64zZK0sqwALTyG */

#ifndef typedef_codertarget_arduinobase_blo_h_T
#define typedef_codertarget_arduinobase_blo_h_T

typedef struct tag_qrLkTWTW64zZK0sqwALTyG codertarget_arduinobase_blo_h_T;

#endif                             /* typedef_codertarget_arduinobase_blo_h_T */

#ifndef struct_tag_hIvgYBDLTTPVSpcx04ytXH
#define struct_tag_hIvgYBDLTTPVSpcx04ytXH

struct tag_hIvgYBDLTTPVSpcx04ytXH
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_hIvgYBDLTTPVSpcx04ytXH */

#ifndef typedef_c_arduinodriver_ArduinoSerial_T
#define typedef_c_arduinodriver_ArduinoSerial_T

typedef struct tag_hIvgYBDLTTPVSpcx04ytXH c_arduinodriver_ArduinoSerial_T;

#endif                             /* typedef_c_arduinodriver_ArduinoSerial_T */

#ifndef struct_tag_UWHgmoqoe5Gc3vQOnLBwhC
#define struct_tag_UWHgmoqoe5Gc3vQOnLBwhC

struct tag_UWHgmoqoe5Gc3vQOnLBwhC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T Protocol;
  uint16_T DataSizeInBytes;
  uint16_T DataTypeWidth;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /* struct_tag_UWHgmoqoe5Gc3vQOnLBwhC */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_UWHgmoqoe5Gc3vQOnLBwhC codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_elfJpF8y5668Yvvc02e29E
#define struct_tag_elfJpF8y5668Yvvc02e29E

struct tag_elfJpF8y5668Yvvc02e29E
{
  uint8_T f1[4];
  uint8_T f2[4];
  uint8_T f3[4];
  uint8_T f4[4];
  uint8_T f5[4];
  uint8_T f6;
  uint8_T f7;
  uint8_T f8[2];
  boolean_T f9;
};

#endif                                 /* struct_tag_elfJpF8y5668Yvvc02e29E */

#ifndef typedef_cell_board_programmer_T
#define typedef_cell_board_programmer_T

typedef struct tag_elfJpF8y5668Yvvc02e29E cell_board_programmer_T;

#endif                                 /* typedef_cell_board_programmer_T */

#ifndef struct_tag_IRLG9vcdhbEoNZQ4x8hW3F
#define struct_tag_IRLG9vcdhbEoNZQ4x8hW3F

struct tag_IRLG9vcdhbEoNZQ4x8hW3F
{
  char_T f1[5];
};

#endif                                 /* struct_tag_IRLG9vcdhbEoNZQ4x8hW3F */

#ifndef typedef_f_cell_wrap_board_programmer_T
#define typedef_f_cell_wrap_board_programmer_T

typedef struct tag_IRLG9vcdhbEoNZQ4x8hW3F f_cell_wrap_board_programmer_T;

#endif                              /* typedef_f_cell_wrap_board_programmer_T */

#ifndef struct_tag_IRLG9vcdhbEoNZQ4x8hW3F
#define struct_tag_IRLG9vcdhbEoNZQ4x8hW3F

struct tag_IRLG9vcdhbEoNZQ4x8hW3F
{
  char_T f1[5];
};

#endif                                 /* struct_tag_IRLG9vcdhbEoNZQ4x8hW3F */

#ifndef typedef_e_cell_wrap_board_programmer_T
#define typedef_e_cell_wrap_board_programmer_T

typedef struct tag_IRLG9vcdhbEoNZQ4x8hW3F e_cell_wrap_board_programmer_T;

#endif                              /* typedef_e_cell_wrap_board_programmer_T */

#ifndef struct_tag_fPFWAHID9o6yHiG60RRjeG
#define struct_tag_fPFWAHID9o6yHiG60RRjeG

struct tag_fPFWAHID9o6yHiG60RRjeG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_board_programmer_T inputVarSize;
  uint8_T DataBuffer[27];
  cell_board_programmer_T PrevOutCellArray;
};

#endif                                 /* struct_tag_fPFWAHID9o6yHiG60RRjeG */

#ifndef typedef_matlabshared_embedded_utiliti_T
#define typedef_matlabshared_embedded_utiliti_T

typedef struct tag_fPFWAHID9o6yHiG60RRjeG matlabshared_embedded_utiliti_T;

#endif                             /* typedef_matlabshared_embedded_utiliti_T */

#ifndef struct_tag_biR2LGuyDtsAdkgxNYAVUG
#define struct_tag_biR2LGuyDtsAdkgxNYAVUG

struct tag_biR2LGuyDtsAdkgxNYAVUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_board_programmer_T inputVarSize[2];
};

#endif                                 /* struct_tag_biR2LGuyDtsAdkgxNYAVUG */

#ifndef typedef_matlabshared_embedded_utili_h_T
#define typedef_matlabshared_embedded_utili_h_T

typedef struct tag_biR2LGuyDtsAdkgxNYAVUG matlabshared_embedded_utili_h_T;

#endif                             /* typedef_matlabshared_embedded_utili_h_T */

#ifndef struct_tag_n0MAEkii5LAwS60oH8C7vG
#define struct_tag_n0MAEkii5LAwS60oH8C7vG

struct tag_n0MAEkii5LAwS60oH8C7vG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_board_programmer_T inputVarSize[5];
};

#endif                                 /* struct_tag_n0MAEkii5LAwS60oH8C7vG */

#ifndef typedef_matlabshared_embedded_util_hx_T
#define typedef_matlabshared_embedded_util_hx_T

typedef struct tag_n0MAEkii5LAwS60oH8C7vG matlabshared_embedded_util_hx_T;

#endif                             /* typedef_matlabshared_embedded_util_hx_T */

#ifndef struct_tag_vNpQ9bJB0ku0iBAJkNrL9C
#define struct_tag_vNpQ9bJB0ku0iBAJkNrL9C

struct tag_vNpQ9bJB0ku0iBAJkNrL9C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_board_programmer_T inputVarSize;
  real_T Protocol;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /* struct_tag_vNpQ9bJB0ku0iBAJkNrL9C */

#ifndef typedef_codertarget_arduinobase_int_h_T
#define typedef_codertarget_arduinobase_int_h_T

typedef struct tag_vNpQ9bJB0ku0iBAJkNrL9C codertarget_arduinobase_int_h_T;

#endif                             /* typedef_codertarget_arduinobase_int_h_T */

/* Parameters for system: '<S6>/controllo PP 1' */
typedef struct P_controlloPP1_board_programm_T_ P_controlloPP1_board_programm_T;

/* Parameters (default storage) */
typedef struct P_board_programmer_T_ P_board_programmer_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_board_programmer_T RT_MODEL_board_programmer_T;

#endif                                /* RTW_HEADER_board_programmer_types_h_ */
