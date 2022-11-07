#include "dma.h"
#include "stm32f7xx.h"

volatile uint32_t ADC_Buffer[6];

void init_DMA(void)
{
	// Вкл.  тактирование модуля DMA
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

	// Настраиваем:
	// Адрес источника
	DMA2_Stream0->PAR = (unsigned int)&ADC->CDR;

	// Адрес приема
	DMA2_Stream0->M0AR =  (uint32_t)&ADC_Buffer;

	// Число передач
	DMA2_Stream0->NDTR =  6;

	// Выбираем канал 0
	DMA2_Stream0->CR |= 0 << 25;

	// Установка приоритета при выборе каналов DMA для передачи
	// данных по шине данных = very high
	DMA2_Stream0->CR |= DMA_SxCR_PL_0 | DMA_SxCR_PL_1;

	// Размер данных в источнике АЦП 32 бита
	DMA2_Stream0->CR |= DMA_SxCR_PSIZE_1;

	// Размер данных в месте назначения массив 32 бита
	DMA2_Stream0->CR |= DMA_SxCR_MSIZE_1;

	// Включаем инкремент адреса места назначения
	DMA2_Stream0->CR |= DMA_SxCR_MINC;

	// Включаем циклический режим
	DMA2_Stream0->CR |= DMA_SxCR_CIRC;

	// Включаем прерывания по окончании передачи
	DMA2_Stream0->CR |= DMA_SxCR_TCIE;

	// Включаем канал DMA2_Stream0
	DMA2_Stream0->CR |= DMA_SxCR_EN;



}

