/*
 * board_testa.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "board_testa".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Dec 13 16:32:44 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "board_testa.h"
#include "board_testa_private.h"

/* Block signals (default storage) */
B_board_testa_T board_testa_B;

/* Block states (default storage) */
DW_board_testa_T board_testa_DW;

/* Real-time model */
static RT_MODEL_board_testa_T board_testa_M_;
RT_MODEL_board_testa_T *const board_testa_M = &board_testa_M_;

/* Forward declaration for local functions */
static void board_testa_SystemCore_setup(matlabshared_embedded_utiliti_T *obj);
static void ProtocolDecoderBase_get_DataTyp(uint8_T value[8]);
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

static void board_testa_SystemCore_setup(matlabshared_embedded_utiliti_T *obj)
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
    board_testa_B.c.f1[b_i] = tmp;
    board_testa_B.d_m.f1[b_i] = tmp;
    board_testa_B.e.f1[b_i] = tmp;
    board_testa_B.f.f1[b_i] = tmp;
    board_testa_B.g.f1[b_i] = tmp;
    board_testa_B.h.f1[b_i] = tmp;
    board_testa_B.j.f1[b_i] = tmp;
    board_testa_B.k.f1[b_i] = tmp;
    board_testa_B.l_f3[b_i] = tmp_1[b_i];
    m_f2[b_i] = tmp_2[b_i];
    n_f2[b_i] = tmp;
    o_f1[b_i] = tmp_3[b_i];
  }

  for (b_i = 0; b_i < 8; b_i++) {
    board_testa_B.b[0] = board_testa_B.c;
    board_testa_B.b[1] = board_testa_B.d_m;
    board_testa_B.b[2] = board_testa_B.e;
    board_testa_B.b[3] = board_testa_B.f;
    board_testa_B.b[4] = board_testa_B.g;
    board_testa_B.b[5] = board_testa_B.h;
    board_testa_B.b[6] = board_testa_B.j;
    board_testa_B.b[7] = board_testa_B.k;
    ret = memcmp(&board_testa_B.b[b_i].f1[0], &board_testa_B.l_f3[0], 5);
    if (ret == 0) {
      ret = 0;
    } else {
      ret = memcmp(&board_testa_B.b[b_i].f1[0], &m_f2[0], 5);
      if (ret == 0) {
        ret = 1;
      } else {
        ret = memcmp(&board_testa_B.b[b_i].f1[0], &n_f2[0], 5);
        if (ret == 0) {
          ret = 2;
        } else {
          ret = memcmp(&board_testa_B.b[b_i].f1[0], &o_f1[0], 5);
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

/* Model step function */
void board_testa_step(void)
{
  int32_T c;
  int32_T i;
  uint32_T tmp;
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

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (board_testa_DW.obj_l.Protocol != board_testa_P.SerialReceive_Protocol) {
    board_testa_DW.obj_l.Protocol = board_testa_P.SerialReceive_Protocol;
  }

  MW_Serial_read(1, board_testa_DW.obj_l.DataSizeInBytes,
                 &board_testa_B.b_dataOut[0], &status);

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (board_testa_DW.obj.Protocol != board_testa_P.SerialTransmit_Protocol) {
    board_testa_DW.obj.Protocol = board_testa_P.SerialTransmit_Protocol;
  }

  for (i = 0; i < 25; i++) {
    board_testa_B.dataIn[i] = board_testa_B.b_dataOut[i];
  }

  MW_Serial_write(board_testa_DW.obj.port, &board_testa_B.dataIn[0], 25.0,
                  board_testa_DW.obj.dataSizeInBytes,
                  board_testa_DW.obj.sendModeEnum, board_testa_DW.obj.dataType,
                  board_testa_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */

  /* MATLABSystem: '<Root>/Protocol Decoder1' */
  if (board_testa_DW.obj_f.TunablePropsChanged) {
    board_testa_DW.obj_f.TunablePropsChanged = false;
  }

  header = 64U;
  terminator[0] = 13U;
  terminator[1] = 10U;
  status = readPacket(&board_testa_B.b_dataOut[0], 25, &header, 1, &terminator[0],
                      2, false, 24, 24, &board_testa_DW.obj_f.DataBuffer[0],
                      &board_testa_B.payload[0], &payloadLength);
  if (status != 0) {
    tmp = payloadLength + 1U;
    if (payloadLength + 1U > 65535U) {
      tmp = 65535U;
    }

    if ((uint16_T)tmp > 24) {
      i = 0;
      c = -1;
    } else {
      i = (uint16_T)tmp - 1;
      c = 23;
    }

    c = (c - i) + 1;
    if (0 <= c - 1) {
      memset(&board_testa_B.payload[i], 0, ((c + i) - i) * sizeof(uint8_T));
    }

    payloadLength = 1U;
    idx = 1U;
    b_varargout_1[0] = 0U;
    b_varargout_1[1] = 0U;
    b_varargout_1[2] = 0U;
    b_varargout_1[3] = 0U;
    while (payloadLength <= 4) {
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_testa_B.uv[0]);
      c = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        c = 0;
      }

      if (payloadLength > (uint16_T)c) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_1[idx - 1] = board_testa_B.payload[i];
      tmp = idx + 1U;
      if (idx + 1U > 65535U) {
        tmp = 65535U;
      }

      idx = (uint16_T)tmp;
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength + board_testa_B.uv[0]);
    }

    payloadLength = 5U;
    idx = 1U;
    b_varargout_2[0] = 0U;
    b_varargout_2[1] = 0U;
    b_varargout_2[2] = 0U;
    b_varargout_2[3] = 0U;
    while (payloadLength <= 8) {
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_testa_B.uv[1]);
      c = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        c = 0;
      }

      if (payloadLength > (uint16_T)c) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_2[idx - 1] = board_testa_B.payload[i];
      tmp = idx + 1U;
      if (idx + 1U > 65535U) {
        tmp = 65535U;
      }

      idx = (uint16_T)tmp;
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength + board_testa_B.uv[1]);
    }

    payloadLength = 9U;
    idx = 1U;
    b_varargout_3[0] = 0U;
    b_varargout_3[1] = 0U;
    b_varargout_3[2] = 0U;
    b_varargout_3[3] = 0U;
    while (payloadLength <= 12) {
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_testa_B.uv[2]);
      c = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        c = 0;
      }

      if (payloadLength > (uint16_T)c) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_3[idx - 1] = board_testa_B.payload[i];
      tmp = idx + 1U;
      if (idx + 1U > 65535U) {
        tmp = 65535U;
      }

      idx = (uint16_T)tmp;
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength + board_testa_B.uv[2]);
    }

    payloadLength = 13U;
    idx = 1U;
    b_varargout_4[0] = 0U;
    b_varargout_4[1] = 0U;
    b_varargout_4[2] = 0U;
    b_varargout_4[3] = 0U;
    while (payloadLength <= 16) {
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_testa_B.uv[3]);
      c = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        c = 0;
      }

      if (payloadLength > (uint16_T)c) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_4[idx - 1] = board_testa_B.payload[i];
      tmp = idx + 1U;
      if (idx + 1U > 65535U) {
        tmp = 65535U;
      }

      idx = (uint16_T)tmp;
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength + board_testa_B.uv[3]);
    }

    payloadLength = 17U;
    idx = 1U;
    b_varargout_5[0] = 0U;
    b_varargout_5[1] = 0U;
    b_varargout_5[2] = 0U;
    b_varargout_5[3] = 0U;
    while (payloadLength <= 20) {
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_testa_B.uv[4]);
      c = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        c = 0;
      }

      if (payloadLength > (uint16_T)c) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      b_varargout_5[idx - 1] = board_testa_B.payload[i];
      tmp = idx + 1U;
      if (idx + 1U > 65535U) {
        tmp = 65535U;
      }

      idx = (uint16_T)tmp;
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength + board_testa_B.uv[4]);
    }

    payloadLength = 21U;
    status = 0U;
    while (payloadLength <= 21) {
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      c = (int32_T)(board_testa_B.uv[5] + 20U);
      if (board_testa_B.uv[5] + 20U > board_testa_B.uv[5] + 21U) {
        c = 0;
      }

      if (21 > (uint16_T)c) {
        i = 0;
      } else {
        i = 20;
      }

      status = board_testa_B.payload[i];
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      payloadLength = (uint16_T)(board_testa_B.uv[5] + 21U);
    }

    payloadLength = 22U;
    header = 0U;
    while (payloadLength <= 22) {
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      c = (int32_T)(board_testa_B.uv[6] + 21U);
      if (board_testa_B.uv[6] + 21U > board_testa_B.uv[6] + 22U) {
        c = 0;
      }

      if (22 > (uint16_T)c) {
        i = 0;
      } else {
        i = 21;
      }

      header = board_testa_B.payload[i];
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      payloadLength = (uint16_T)(board_testa_B.uv[6] + 22U);
    }

    payloadLength = 23U;
    idx = 1U;
    terminator[0] = 0U;
    terminator[1] = 0U;
    while (payloadLength <= 24) {
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      i = (int32_T)((uint32_T)payloadLength + board_testa_B.uv[7]);
      c = (int32_T)(i - 1U);
      if (i - 1U > (uint32_T)i) {
        c = 0;
      }

      if (payloadLength > (uint16_T)c) {
        i = 0;
      } else {
        i = payloadLength - 1;
      }

      terminator[idx - 1] = board_testa_B.payload[i];
      tmp = idx + 1U;
      if (idx + 1U > 65535U) {
        tmp = 65535U;
      }

      idx = (uint16_T)tmp;
      ProtocolDecoderBase_get_DataTyp(board_testa_B.uv);
      payloadLength = (uint16_T)((uint32_T)payloadLength + board_testa_B.uv[7]);
    }

    board_testa_DW.obj_f.PrevOutCellArray.f1[0] = b_varargout_1[0];
    board_testa_DW.obj_f.PrevOutCellArray.f2[0] = b_varargout_2[0];
    board_testa_DW.obj_f.PrevOutCellArray.f3[0] = b_varargout_3[0];
    board_testa_DW.obj_f.PrevOutCellArray.f4[0] = b_varargout_4[0];
    board_testa_DW.obj_f.PrevOutCellArray.f5[0] = b_varargout_5[0];
    board_testa_DW.obj_f.PrevOutCellArray.f1[1] = b_varargout_1[1];
    board_testa_DW.obj_f.PrevOutCellArray.f2[1] = b_varargout_2[1];
    board_testa_DW.obj_f.PrevOutCellArray.f3[1] = b_varargout_3[1];
    board_testa_DW.obj_f.PrevOutCellArray.f4[1] = b_varargout_4[1];
    board_testa_DW.obj_f.PrevOutCellArray.f5[1] = b_varargout_5[1];
    board_testa_DW.obj_f.PrevOutCellArray.f1[2] = b_varargout_1[2];
    board_testa_DW.obj_f.PrevOutCellArray.f2[2] = b_varargout_2[2];
    board_testa_DW.obj_f.PrevOutCellArray.f3[2] = b_varargout_3[2];
    board_testa_DW.obj_f.PrevOutCellArray.f4[2] = b_varargout_4[2];
    board_testa_DW.obj_f.PrevOutCellArray.f5[2] = b_varargout_5[2];
    board_testa_DW.obj_f.PrevOutCellArray.f1[3] = b_varargout_1[3];
    board_testa_DW.obj_f.PrevOutCellArray.f2[3] = b_varargout_2[3];
    board_testa_DW.obj_f.PrevOutCellArray.f3[3] = b_varargout_3[3];
    board_testa_DW.obj_f.PrevOutCellArray.f4[3] = b_varargout_4[3];
    board_testa_DW.obj_f.PrevOutCellArray.f5[3] = b_varargout_5[3];
    board_testa_DW.obj_f.PrevOutCellArray.f6 = status;
    board_testa_DW.obj_f.PrevOutCellArray.f7 = header;
    board_testa_DW.obj_f.PrevOutCellArray.f8[0] = terminator[0];
    board_testa_DW.obj_f.PrevOutCellArray.f8[1] = terminator[1];
    board_testa_DW.obj_f.PrevOutCellArray.f9 = false;
  }

  /* End of MATLABSystem: '<Root>/Protocol Decoder1' */

  /* MATLABSystem: '<S1>/Digital Output' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLABSystem: '<S1>/Digital Output1'
   *  MATLABSystem: '<S1>/Digital Output2'
   */
  board_testa_B.d = rt_roundd_snf(board_testa_P.Constant_Value);
  if (board_testa_B.d < 256.0) {
    if (board_testa_B.d >= 0.0) {
      status = (uint8_T)board_testa_B.d;
    } else {
      status = 0U;
    }
  } else {
    status = MAX_uint8_T;
  }

  writeDigitalPin(47, status);

  /* End of MATLABSystem: '<S1>/Digital Output' */

  /* MATLABSystem: '<S1>/Digital Output1' */
  if (board_testa_B.d < 256.0) {
    if (board_testa_B.d >= 0.0) {
      status = (uint8_T)board_testa_B.d;
    } else {
      status = 0U;
    }
  } else {
    status = MAX_uint8_T;
  }

  writeDigitalPin(45, status);

  /* MATLABSystem: '<S1>/Digital Output2' */
  if (board_testa_B.d < 256.0) {
    if (board_testa_B.d >= 0.0) {
      status = (uint8_T)board_testa_B.d;
    } else {
      status = 0U;
    }
  } else {
    status = MAX_uint8_T;
  }

  writeDigitalPin(43, status);
}

/* Model initialize function */
void board_testa_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(board_testa_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&board_testa_DW, 0,
                sizeof(DW_board_testa_T));

  {
    real_T tmp;
    uint32_T tmp_0;
    uint8_T tmp_1;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    board_testa_DW.obj_l.matlabCodegenIsDeleted = false;
    board_testa_DW.objisempty_a = true;
    board_testa_DW.obj_l.Protocol = board_testa_P.SerialReceive_Protocol;
    board_testa_DW.obj_l.isInitialized = 1;
    board_testa_DW.obj_l.DataTypeWidth = 1U;
    tmp_0 = 25U * board_testa_DW.obj_l.DataTypeWidth;
    if (tmp_0 > 65535U) {
      tmp_0 = 65535U;
    }

    board_testa_DW.obj_l.DataSizeInBytes = (uint16_T)tmp_0;
    MW_SCI_Open(1);
    board_testa_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Receive' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    board_testa_DW.obj.matlabCodegenIsDeleted = false;
    board_testa_DW.objisempty = true;
    board_testa_DW.obj.Protocol = board_testa_P.SerialTransmit_Protocol;
    board_testa_DW.obj.isInitialized = 1;
    board_testa_DW.obj.port = 0.0;
    board_testa_DW.obj.dataSizeInBytes = 1.0;
    board_testa_DW.obj.dataType = 0.0;
    board_testa_DW.obj.sendModeEnum = 0.0;
    board_testa_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(board_testa_DW.obj.port);
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
    board_testa_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */

    /* Start for MATLABSystem: '<Root>/Protocol Decoder1' */
    board_testa_DW.obj_f.isInitialized = 0;
    board_testa_DW.obj_f.matlabCodegenIsDeleted = false;
    board_testa_DW.objisempty_p = true;
    board_testa_SystemCore_setup(&board_testa_DW.obj_f);

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    board_testa_DW.obj_c.matlabCodegenIsDeleted = false;
    board_testa_DW.objisempty_l = true;
    board_testa_DW.obj_c.isInitialized = 1;
    digitalIOSetup(47, 1);
    board_testa_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    board_testa_DW.obj_fp.matlabCodegenIsDeleted = false;
    board_testa_DW.objisempty_f = true;
    board_testa_DW.obj_fp.isInitialized = 1;
    digitalIOSetup(45, 1);
    board_testa_DW.obj_fp.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output2' */
    board_testa_DW.obj_n.matlabCodegenIsDeleted = false;
    board_testa_DW.objisempty_o = true;
    board_testa_DW.obj_n.isInitialized = 1;
    digitalIOSetup(43, 1);
    board_testa_DW.obj_n.isSetupComplete = true;
  }
}

/* Model terminate function */
void board_testa_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!board_testa_DW.obj_l.matlabCodegenIsDeleted) {
    board_testa_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!board_testa_DW.obj.matlabCodegenIsDeleted) {
    board_testa_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */

  /* Terminate for MATLABSystem: '<Root>/Protocol Decoder1' */
  if (!board_testa_DW.obj_f.matlabCodegenIsDeleted) {
    board_testa_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Protocol Decoder1' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!board_testa_DW.obj_c.matlabCodegenIsDeleted) {
    board_testa_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!board_testa_DW.obj_fp.matlabCodegenIsDeleted) {
    board_testa_DW.obj_fp.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output2' */
  if (!board_testa_DW.obj_n.matlabCodegenIsDeleted) {
    board_testa_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output2' */
}
