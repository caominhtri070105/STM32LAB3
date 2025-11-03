/*
 * Increasing_time.c
 *
 *  Created on: Nov 3, 2025
 *      Author: tri
 */

#include "Increasing_time.h"

void Increasing_time(int *num, int *display_manual){
	if(isButton2Pressed()==1){
		*num=*num+1000;
		if (*num>99000) *num=1000;
		*display_manual = *num / 1000;
	}
}
void Saving_time(int *display_manual, int *default_led){
	if(isButton3Pressed()==1){
		*default_led=*display_manual*1000;
	}
}
