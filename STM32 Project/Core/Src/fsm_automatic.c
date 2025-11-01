/*
 * fsm_automatic.c
 *
 *  Created on: Nov 1, 2025
 *      Author: tri
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		//
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		status = AUTO_RED;
		setTimer1(5000);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		if(timer1_flag==1){
			status=AUTO_GREEN;
			setTimer1(3000);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_RESET);
		if(timer1_flag==1){
			status=AUTO_YELLOW;
			setTimer1(2000);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(RED_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,RED_LED_Pin, GPIO_PIN_SET);
		if(timer1_flag==1){
			status=AUTO_RED;
			setTimer1(5000);
		}
		break;
	default:
		break;
	}
}
