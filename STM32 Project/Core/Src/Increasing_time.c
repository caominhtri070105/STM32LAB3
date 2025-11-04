/*
 * Increasing_time.c
 *
 *  Created on: Nov 3, 2025
 *      Author: tri
 */

#include "Increasing_time.h"

void Increasing_time(int *num, int *display_manual){
	if(isButton2Pressed()==1){
		*display_manual = *display_manual + 1;
		if (*display_manual > 99) *display_manual = 1;
	}
}
void Saving_time(int *display_manual, int *default_led){
	if(isButton3Pressed()==1){
		*default_led=*display_manual*1000;
	}
}
