/*
 * fsm_manual.c
 *
 *  Created on: Nov 2, 2025
 *      Author: tri
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin, GPIO_PIN_SET);
		if(timer1_flag==1){
			status= AUTO_RED;
			setTimer1(5000);
		}
		if(isButton1Pressed()==1){
			status=MAN_GREEN;
			setTimer1(10000);
		}
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin, GPIO_PIN_RESET);
		if(timer1_flag==1){
			status= AUTO_GREEN;
			setTimer1(3000);
		}
		if(isButton1Pressed()==1){
			status=MAN_YELLOW;
			setTimer1(10000);
		}
		break;
	case MAN_YELLOW:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin, GPIO_PIN_RESET);
		if(timer1_flag==1){
			status= AUTO_YELLOW;
			setTimer1(2000);
		}
		if(isButton1Pressed()==1){
			status=MAN_RED;
			setTimer1(10000);
		}
		break;
	default:
		break;
	}
}
