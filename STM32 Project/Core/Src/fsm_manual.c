/*
 * fsm_manual.c
 *
 *  Created on: Nov 2, 2025
 *      Author: tri
 */

int display_red;
int display_green;
int display_yellow;
int index_led=0;
#include "fsm_manual.h"
#include "fsm_automatic.h"
void fsm_manual_run(){
	if (timer4_flag==1){
			update7SEGMODE(index_led);
			index_led++;
			if (index_led>=2) index_led=0;
			setTimer4(250);
		}
	if(isButton3Pressed()==1){
		mode=INIT;
		status = INIT;
	    status1 = INIT;
	}
	switch(mode){
	case INIT:
		fsm_automatic_run();
		if(isButton1Pressed()==1){
			mode=MAN_RED;
			display_red = default_red / 1000;
			setTimer3(250);
		}
		break;
	case MAN_RED:
		if(timer3_flag==1){
			HAL_GPIO_TogglePin(RED_LED_GPIO_Port,RED_LED_Pin);
			setTimer3(250);
			display7SEG1(display_red/10);
			display7SEG2(display_red%10);
		}
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin, GPIO_PIN_SET);
		Increasing_time(&display_red);
		Saving_time(&display_red, &default_red);
		if(isButton1Pressed()==1){
			mode=MAN_GREEN;
			display_green = default_green / 1000;
			setTimer3(250);
		}
		break;
	case MAN_GREEN:
		if(timer3_flag==1){
			HAL_GPIO_TogglePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin);
			setTimer3(250);
			display7SEG1(display_green/10);
			display7SEG2(display_green%10);
		}
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		Increasing_time(&display_green);
		Saving_time(&default_green);
		if(isButton1Pressed()==1){
			mode=MAN_YELLOW;
			display_yellow = default_yellow / 1000;
			setTimer3(250);
		}
		break;
	case MAN_YELLOW:
		if(timer3_flag==1){
			HAL_GPIO_TogglePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin);
			setTimer3(250);
			display7SEG1(display_yellow/10);
			display7SEG2(display_yellow%10);
		}
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin, GPIO_PIN_SET);
		Increasing_time(&display_yellow);
		Saving_time(&display_yellow, &default_yellow);
		if(isButton1Pressed()==1){
			mode=INIT;
			setTimer3(250);
		}
		break;
	default:
		break;
	}
}
