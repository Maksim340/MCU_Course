/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f7xx.h"
#include "rcc.h"

int main(void)
{
	init_RCC();

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER |= 1 << (1 << 1);
    int iii = 0;
    /* Loop forever */
    for(;;)
    {

        for(int i = 0; i < 10000000; i++)
        {

        }

        GPIOD->ODR ^= 1 << 1;






    }
}
