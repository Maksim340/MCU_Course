#include "timer.h"
#include "stm32f7xx.h"

void init_TIMER8(void)
{
	// Вкл.  тактирование модуля таймера
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
	// Настраиваем:
	//		Предделитель: 1
	//		Макс. счет: 1080 (100кГц)
	TIM8->PSC = 0;
	TIM8->ARR = 1080;

	// Регистр сравнения: 540 (50% скидка)
	TIM8->CCR1 = TIM8->ARR / 2;

	// Симметричный счет (режим 2)
	TIM8->CR1 |= TIM_CR1_CMS_1;

	// Включаем канал сравнения
	TIM8->CCER |= TIM_CCER_CC1E;

	// Режим ШИМ-1
	TIM8->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;

	// Вкл. буферизации
	TIM8->CCMR1 |= TIM_CCMR1_OC1PE;

	// Вкл. физический  канал выхода
	TIM8->BDTR |= TIM_BDTR_MOE;

	//Вкл. прерывания по обновлению
	TIM8->DIER |= TIM_DIER_UIE;

	// Вкл. счет таймера
	TIM8->CR1 |= TIM_CR1_CEN;
}


void init_TIMER8async(void)
{
	// Вкл.  тактирование модуля таймера
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
	// Настраиваем:
	//		Предделитель: 1
	//		Макс. счет: 1080 (100кГц)
	TIM8->PSC = 0;
	TIM8->ARR = 1080;

	// Регистр сравнения: 540 (50% скидка)
	TIM8->CCR1 = 540;
	TIM8->CCR2 = TIM8->ARR - TIM8->CCR1;
	// Симметричный счет (режим 2)
	TIM8->CR1 |= TIM_CR1_CMS_1;

	// Включаем канал сравнения
	TIM8->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E;

	// Режим ШИМ-1
	TIM8->CCMR1 |= 	TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | //TIM_CCMR1_OC1M_3 | 		// 1 канал
					TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 ;//| TIM_CCMR1_OC2M_3;		// 2 канал

	TIM8->BDTR |= TIM_BDTR_MOE | TIM_BDTR_AOE;
	TIM8->BDTR |= 100;


	// Вкл. буферизации
	TIM8->CCMR1 |= TIM_CCMR1_OC1PE;
	TIM8->CCMR1 |= TIM_CCMR1_OC2PE;

	// Вкл. физический  канал выхода
	TIM8->BDTR |= TIM_BDTR_MOE;

	// Вкл. счет таймера
	TIM8->CR1 |= TIM_CR1_CEN;
}
