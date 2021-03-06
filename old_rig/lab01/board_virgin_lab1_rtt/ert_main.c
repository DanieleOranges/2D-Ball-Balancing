/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "Arduino.h"
#include "arduinodue_wrapper.h"
#include "io_wrappers.h"

/* PoliArd Mod | Andrea Costa - Damiano Milani */
/* #include "C:\MATLAB\SupportPackages\PoliCube\policube_data.h" */
#include "C:\MATLAB\SupportPackages\PoliArd\poliard_data.h"

/* PoliArd Mod | End */

/* PoliArd Mod | Andrea Costa - Damiano Milani */
extern Config_T Config;
extern Data2Send_T Data2Send;
char COM_str[26];
uint8_T *arrigon;
uint8_T tx_debug_status = 0;
uint8_t bytes2send = 0;
uint8_t SignalsEn[6];
uint8_T FirstStart = 1;
uint8_T EOT_MSB = 0;
uint8_T EOT_LSB = 0;

/* PoliArd Mod | End */
volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  ENABLE_SCHEDULER_INT();

  /*
   * For a bare-board target (i.e., no operating system), the
   * following code checks whether any subrate overruns,
   * and also sets the rates that need to run this time step.
   */
  eventFlags[1] = ((boolean_T)rtmStepTask(board_virgin_lab1_M, 1));
  board_virgin_lab1_output0();

  /* Get model outputs here */
  board_virgin_lab1_update0();
  DISABLE_SCHEDULER_INT();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    ENABLE_SCHEDULER_INT();
    switch (1) {
     case 1:
      board_virgin_lab1_output1();

      /* Get model outputs here */
      board_virgin_lab1_update1();
      break;

     default:
      break;
    }

    DISABLE_SCHEDULER_INT();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

int_T main(void)
{
  noInterrupts();
  init();

#ifdef _RTT_USE_SERIAL0_

  Serial_begin(0, 9600);
  Serial_write(0, "***starting the model***", 26);

#endif

#ifdef _RTT_USE_SERIAL1_

  Serial_begin(1, 9600);

#endif

#ifdef _RTT_USE_SERIAL2_

  Serial_begin(2, 9600);

#endif

#ifdef _RTT_USE_SERIAL3_

  Serial_begin(3, 9600);

#endif

  /* This pin indicates the base rate overrun */
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);
  interrupts();
  board_virgin_lab1_initialize();
  Setup_TickTimer(TC_FOR_TIMER8, CHANNEL_FOR_TIMER8, ID_TC_FOR_TIMER8,
                  IRQn_FOR_TIMER8, TC_CMR_TCCLKS_TIMER_CLOCK3, 2625U);

  /* PoliArd Mod | Andrea Costa - Damiano Milani */
  uint8_T i;

  /* PoliArd Mod | End */

  /* The main step loop */
  while (rtmGetErrorStatus(board_virgin_lab1_M) == (NULL)) {
    /* Check for overrun */
    if (IsrOverrun) {
      digitalWrite(13, 1);

      /* PoliArd Mod | Andrea Costa - Damiano Milani */
      /* Set overrun bit */
      Data2Send.C |= 1 << 6;

      /* PoliArd Mod | End */
    } else {
      /* PoliArd Mod | Andrea Costa - Damiano Milani */
      /* Clear overrun bit */
      Data2Send.C &= ~(1 << 6);

      /* PoliArd Mod | End */
    }

    /* PoliArd Mod | Andrea Costa - Damiano Milani */
    if (Config.dataReady_f == 1) {
      Config.dataReady_f = 0;
      if (FirstStart == 1) {
        /* First time running main while -> calculate num of sig to send and buffer size */
        bytes2send = 3 + Signals2Send*4;
        EOT_MSB = bytes2send-2;
        EOT_LSB = bytes2send-1;
        for (i = 0; i <= 6; i++) {
          if (i <= (Signals2Send-1))
            SignalsEn[i] = 1;
          else
            SignalsEn[i] = 0;
        }

        FirstStart = 0;
      }

      tx_debug_status = ! tx_debug_status;
      digitalWrite(PIN_DEBUG1, tx_debug_status);
      digitalWrite(PIN_DEBUG2, HIGH);
      COM_str[0] = Data2Send.C;
      if (SignalsEn[0] == 1) {
        arrigon = (uint8_T *) &Data2Send.S1;
        COM_str[1] = arrigon[0];
        COM_str[2] = arrigon[1];
        COM_str[3] = arrigon[2];
        COM_str[4] = arrigon[3];
      }

      if (SignalsEn[1] == 1) {
        arrigon = (uint8_T *) &Data2Send.S2;
        COM_str[5] = arrigon[0];
        COM_str[6] = arrigon[1];
        COM_str[7] = arrigon[2];
        COM_str[8] = arrigon[3];
      }

      if (SignalsEn[2] == 1) {
        arrigon = (uint8_T *) &Data2Send.S3;
        COM_str[9] = arrigon[0];
        COM_str[10] = arrigon[1];
        COM_str[11] = arrigon[2];
        COM_str[12] = arrigon[3];
      }

      if (SignalsEn[3] == 1) {
        arrigon = (uint8_T *) &Data2Send.S4;
        COM_str[13] = arrigon[0];
        COM_str[14] = arrigon[1];
        COM_str[15] = arrigon[2];
        COM_str[16] = arrigon[3];
      }

      if (SignalsEn[4] == 1) {
        arrigon = (uint8_T *) &Data2Send.S5;
        COM_str[17] = arrigon[0];
        COM_str[18] = arrigon[1];
        COM_str[19] = arrigon[2];
        COM_str[20] = arrigon[3];
      }

      if (SignalsEn[5] == 1) {
        arrigon = (uint8_T *) &Data2Send.S6;
        COM_str[21] = arrigon[0];
        COM_str[22] = arrigon[1];
        COM_str[23] = arrigon[2];
        COM_str[24] = arrigon[3];
      }

      /* End of transmission */
      COM_str[EOT_MSB] = 0b10000000;
      COM_str[EOT_LSB] = 1;

      //Serial_write(0, &COM_str, 27);
      Serial_write(0, &COM_str, bytes2send);
      digitalWrite(PIN_DEBUG2, LOW);

      /* PoliArd Mod | End */
    }
  }

  board_virgin_lab1_terminate();

  /* Disable Interrupts */
  noInterrupts();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
