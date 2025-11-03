/*
 * LED7SEG_setting.c
 *
 *  Created on: Nov 3, 2025
 *      Author: tri
 */

#include "LED7SEG_setting.h"
// Bảng tra cứu cho LED 7 đoạn (hiển thị số từ 0 đến 9)
const uint8_t seven_seg_digits[] = {
    0b0000001, // 0
    0b1001111, // 1
    0b0010010, // 2
    0b0000110, // 3
    0b1001100, // 4
    0b0100100, // 5
    0b0100000, // 6
    0b0001111, // 7
    0b0000000, // 8
    0b0000100  // 9
};

void display7SEG1(int number) {
    if (number < 0 || number > 9) return;  // Kiểm tra số hợp lệ

    uint8_t digit = seven_seg_digits[number];  // Lấy trạng thái từ bảng tra cứu

    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (digit & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (digit & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (digit & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (digit & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (digit & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (digit & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (digit & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void display7SEG2(int number) {
    if (number < 0 || number > 9) return;  // Kiểm tra số hợp lệ

    uint8_t digit = seven_seg_digits[number];  // Lấy trạng thái từ bảng tra cứu

    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, (digit & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, (digit & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, (digit & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, (digit & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, (digit & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, (digit & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, (digit & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void display7SEGMODE(int number) {
    if (number < 0 || number > 9) return;  // Kiểm tra số hợp lệ

    uint8_t digit = seven_seg_digits[number];  // Lấy trạng thái từ bảng tra cứu

    HAL_GPIO_WritePin(SEGM0_GPIO_Port, SEGM0_Pin, (digit & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM1_GPIO_Port, SEGM1_Pin, (digit & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM2_GPIO_Port, SEGM2_Pin, (digit & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM3_GPIO_Port, SEGM3_Pin, (digit & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM4_GPIO_Port, SEGM4_Pin, (digit & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM5_GPIO_Port, SEGM5_Pin, (digit & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM6_GPIO_Port, SEGM6_Pin, (digit & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}


