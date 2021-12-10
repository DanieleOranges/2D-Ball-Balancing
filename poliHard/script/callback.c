#include "callback.h"

//#include <Wire.h>
//#include "Nunchuk.h"

/*#include "Wire.h"
#include "Nunchuk.h"
*/

/*=================================
4- Wire Touchscreen Connections
A0=====X+
A1=====X-
A2=====Y+
A3=====Y-
=================================*/

#define Y2 A0
#define X2 A1
#define Y1 A2
#define X1 A3
//Define your screen resolution as per your Touch screen (Max: 1024)
#define Xresolution 1024 
#define Yresolution 1024 
#define Pressresolution 1024 
/*
void setup() {
   Serial.begin(19200);
}
*/
void touchRead(int *x,int *y, int *press){
	#ifndef MATLAB_MEX_FILE

   pinMode(X1,INPUT);
   pinMode(Y2,INPUT);  
   digitalWrite(Y2,LOW);
   pinMode(Y1,OUTPUT);
   digitalWrite(Y1,HIGH);
   pinMode(X2,OUTPUT);
   digitalWrite(X2,LOW);
   *press = (analogRead(X1))/(1024/Pressresolution); //Reads Pressure
    
   
   pinMode(Y1,INPUT);
   pinMode(Y2,INPUT);  
   digitalWrite(Y2,LOW);
   pinMode(X1,OUTPUT);
   digitalWrite(X1,HIGH);
   pinMode(X2,OUTPUT);
   digitalWrite(X2,LOW);
   *x = (analogRead(Y1))/(1024/Xresolution); //Reads X axis touch position
    
   pinMode(X1,INPUT);
   pinMode(X2,INPUT);
   digitalWrite(X2,LOW);
   pinMode(Y1,OUTPUT);
   digitalWrite(Y1,HIGH);
   pinMode(Y2,OUTPUT);
   digitalWrite(Y2,LOW);
   *y = (analogRead(X1))/(1024/Yresolution); //Reads Y axis touch position
 
	#endif
}
/*
void serialSend(char *pwmX, char *pwmY, char *Xserial, char *Yserial, char *press_serial){
   char message[100];
   strcpy(message, "@");

   strcat(message, pwmX);
   strcat(message, pwmY);
   strcat(message, Xserial);
   strcat(message, Yserial);
   strcat(message, press_serial);

 
   Serial.println(message);


}

void nunchuckRead(short *Jx,short *Jy, short *Ax, short *Ay, short *Az, short *C, short *Z) {
    if (nunchuk_read()) {

	*Jx = nunchuk_joystickX();
	*Jy = nunchuk_joystickY();
	
	*Ax = nunchuk_accelX();
	*Ay = nunchuk_accelY();
	*Az = nunchuk_accelZ();

	*C =  nunchuk_buttonC(); 
        *Z =  nunchuk_buttonZ();

    }
}
*/