/*
 * button.c
 *
 *  Created on: Nov 1, 2025
 *      Author: tri
 */

#include "button.h"

int button1_flag=0;
int button2_flag=0;
int button3_flag=0;

int B1KeyReg0 = NORMAL_STATE;
int B1KeyReg1 = NORMAL_STATE;
int B1KeyReg2 = NORMAL_STATE;
int B1KeyReg3 = NORMAL_STATE;

int B2KeyReg0 = NORMAL_STATE;
int B2KeyReg1 = NORMAL_STATE;
int B2KeyReg2 = NORMAL_STATE;
int B2KeyReg3 = NORMAL_STATE;

int B3KeyReg0 = NORMAL_STATE;
int B3KeyReg1 = NORMAL_STATE;
int B3KeyReg2 = NORMAL_STATE;
int B3KeyReg3 = NORMAL_STATE;

int TimerForKeyPress1 = 200;
int TimerForKeyPress2 = 200;
int TimerForKeyPress3 = 200;

int isButton1Pressed(){
	if(button1_flag==1){
		button1_flag=0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag==1){
		button2_flag=0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag==1){
		button3_flag=0;
		return 1;
	}
	return 0;
}

void subKeyProcess1(){
	button1_flag=1;
	//todo
}
void subKeyProcess2(){
	button2_flag=1;
	//todo
}
void subKeyProcess3(){
	button3_flag=1;
	//todo
}
void getKeyInput(){
	B1KeyReg0=B1KeyReg1;
	B1KeyReg1=B1KeyReg2;
	B1KeyReg2=HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if((B1KeyReg0==B1KeyReg1) && (B1KeyReg1==B1KeyReg2)){
		if(B1KeyReg3!=B1KeyReg2){
			B1KeyReg3 = B1KeyReg2;
			if(B1KeyReg2==PRESSED_STATE){
				//
				subKeyProcess1();
				TimerForKeyPress1=200;
			}
		}
		else{
			TimerForKeyPress1--;
			if (TimerForKeyPress1==0){
				B1KeyReg3= NORMAL_STATE;
			}
		}
	}
	B2KeyReg0=B2KeyReg1;
	B2KeyReg1=B2KeyReg2;
	B2KeyReg2=HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	if((B2KeyReg0==B2KeyReg1) && (B2KeyReg1==B2KeyReg2)){
		if(B2KeyReg3!=B2KeyReg2){
			B2KeyReg3 = B2KeyReg2;
			if(B2KeyReg2==PRESSED_STATE){
				//
				subKeyProcess2();
				TimerForKeyPress2=200;
			}
		}
		else{
			TimerForKeyPress2--;
			if (TimerForKeyPress2==0){
				B2KeyReg3= NORMAL_STATE;
			}
		}
	}

	B3KeyReg0=B3KeyReg1;
	B3KeyReg1=B3KeyReg2;
	B3KeyReg2=HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	if((B3KeyReg0==B3KeyReg1) && (B3KeyReg1==B3KeyReg2)){
		if(B3KeyReg3!=B3KeyReg2){
			B3KeyReg3 = B3KeyReg2;
			if(B3KeyReg2==PRESSED_STATE){
				//
				subKeyProcess3();
				TimerForKeyPress3=200;
			}
		}
		else{
			TimerForKeyPress3--;
			if (TimerForKeyPress3==0){
				B3KeyReg3= NORMAL_STATE;
			}
		}
	}
}
