#include "dsp.h"
#include "stm32f7xx.h"
#include <stdlib.h>
#include <string.h>

MovingFloatFilter_Struct FILTER_MOV;
MedianFloatFilter_Struct FILTER_MED;
Low_Filter_1st_Order_Struct  FILTER_10RD =
{
	.b0 = TS / (TAU_10RD + TS),
	.a1 = -TAU_10RD / (TAU_10RD + TS)
};
/**
 * \brief	Функция фильтра скользящего среднего.
 *
 * \param	filter: структура с параметрами фильтра.
 * \param	x: входная переменная.
 *
 * \return	y: среднее значение.
 */

float MovingFloatFilter(MovingFloatFilter_Struct * filter, float x)
{
	// Отнимаем от суммы [n-1] точку и прибавляем [0] точку
	filter->sum = filter->sum - filter->buf[filter->pointer] + x;

	// Добавляем новую точку в массив точек
	filter->buf[filter->pointer] = x;

	// Инкремируем указатель
	if (++filter->pointer >= MAX_MOVING_FLOAT_SIZE)
		filter->pointer = 0;

	// Вычислим среднее значение
	return filter->sum * (1.f / MAX_MOVING_FLOAT_SIZE);
}

int cmp (const float *a, const float *b)
{
	if (*a > *b)
		return 1;

	if (*a < *b)
		return -1;

	return 0;
}
/**
 * \brief	Функция медианного фильтра.
 *
 * \param	filter: структура с параметрами фильтра.
 * \param	x: входная переменная.
 *
 * \return	y: среднее значение.
 */
float MedianFloatFilter(MedianFloatFilter_Struct * filter, float x)
{
		// Добавляем новую точку в массив точек
		filter->buf[filter->pointer] = x;

		// Инкремируем указатель
		if (++filter->pointer >= MAX_MEDIAN_FLOAT_SIZE)
			filter->pointer = 0;

		// Делаем копию массива точек
		for (int i = 0; i < MAX_MEDIAN_FLOAT_SIZE; i++)
			filter->buf_sorted[i] = filter->buf[i];

		// Ждем окончания копирования
		__ISB();
		__DSB();

		// Сортируем массив
		qsort(filter->buf_sorted, MAX_MEDIAN_FLOAT_SIZE, sizeof(filter->buf_sorted[0]), (int (*)(const void * , const void *))cmp);

		return filter->buf_sorted[MAX_MEDIAN_FLOAT_SIZE >> 1];

}


/**
 * \brief	Функция фильтра нижних частот 1го порядка.
 *
 * \param	filter: структура с параметрами фильтра.
 * \param	x: входная переменная.
 *
 * \return	y: выходная переменная.
 */

float Low_Filter_1st_Order (Low_Filter_1st_Order_Struct * filter, float x)
{
	// Рассчитываем выходную переменную для текущего такта.
	float y = x * filter->b0 - filter->yn * filter->a1;

	// Сохраняем выходную переменную для следующего такта.
	filter->yn = y;

	return y;
}



























