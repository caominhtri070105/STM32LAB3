/*
 * Increasing_time.c
 *
 *  Created on: Nov 3, 2025
 *      Author: tri
 */

#include "Increasing_time.h"

void Increasing_time(int num){
	if(isButton2Pressed()==1){
		num++;
	}
	if (num>99) num=0;
}
