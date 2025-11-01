/*
 * button.h
 *
 *  Created on: Nov 1, 2025
 *      Author: tri
 */
#include "main.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
