/*
 * fsm_manual.c
 *
 *  Created on: Nov 2, 2025
 *      Author: tri
 */

#include "fsm_manual.h"
void fsm_manual_run(){
	switch(mode){
	case INIT:
		fsm_automatic_run();
		if(isButton1Pressed()==1){
			mode=MAN_RED;
			setTimer3(250);
		}
		break;
	case MAN_RED:
		if(timer3_flag==1){
			HAL_GPIO_TogglePin(RED_LED_GPIO_Port,RED_LED_Pin);
			setTimer3(250);
		}
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin, GPIO_PIN_SET);
		if(isButton1Pressed()==1){
			mode=MAN_GREEN;
			setTimer3(250);
		}
		break;
	case MAN_GREEN:
		if(timer3_flag==1){
			HAL_GPIO_TogglePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin);
			setTimer3(250);
		}
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		if(isButton1Pressed()==1){
			mode=MAN_YELLOW;
			setTimer3(250);
		}
		break;
	case MAN_YELLOW:
		if(timer3_flag==1){
			HAL_GPIO_TogglePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin);
			setTimer3(250);
		}
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin, GPIO_PIN_SET);
		if(isButton1Pressed()==1){
			mode=INIT;
			setTimer3(250);
		}
		break;
	default:
		break;
	}
}
