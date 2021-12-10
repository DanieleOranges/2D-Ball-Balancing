#ifndef CALLBACK__H
#define CALLBACK__H
#ifndef MATLAB_MEX_FILE
#include "Arduino.h"

#endif

void touchRead(int *x,int * y, int *press);
//void nunchuckRead(short *Jx,short *Jy, short *Ax, short *Ay, short *Az, short *C, short *Z);
void serialSend(char *pwmX, char *pwmY, char *Xserial, char *Yserial, char *press_serial);
//void setup();
#endif