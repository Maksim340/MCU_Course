#include "interrupt.h"
#include "stm32f7xx.h"

volatile float TEMPERATURE;

void init_INTERRUPT(void)
{
	// Настройка варианта группирования прерываний 3 (16 групп приоритетов, 16 подгрупп)
	NVIC_SetPriorityGrouping(3);

	// Установка приоритета прерывания TIM8_UP_TIM13: группа 1, приоритет 1
	NVIC_SetPriority(TIM8_UP_TIM13_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 1));

	// Вкл. прерываний TIM8_UP_TIM13 в NVIC
	NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);

	// Установка приоритета прерывания DMA2_Stream0_IRQn: группа 2, приоритет 1
	NVIC_SetPriority(DMA2_Stream0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 2, 1));

	// Вкл. прерываний ADC в NVIC
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}
void TIM8_UP_TIM13_IRQHandler(void)
{
	// Сброс флага прерывания TIM8 по обновлению
	TIM8->SR &= ~TIM_SR_UIF;

	// Ожидание выполнения всех инструкций в конвейере
	__ISB();

	GPIOD->ODR ^= GPIO_ODR_OD6;
}












