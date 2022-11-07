#ifndef DSP_H_
#define DSP_H_

#include "stm32f7xx.h"
#include "dsp.h"

#define MAX_MOVING_FLOAT_SIZE (500)
#define MAX_MEDIAN_FLOAT_SIZE (500)

#define TS 				(1./100.e3)	// период декретизации (период коммутации).
#define WC_10RD			(2.*3.145*1000.)		// Постоянная времени фильтра 1го порядка (с).
#define TAU_10RD		(1./WC_10RD)		// Постоянная времени фильтра 1го порядка (с).

typedef struct
{
	float buf[MAX_MOVING_FLOAT_SIZE];

	unsigned int pointer;

	float sum;

} MovingFloatFilter_Struct;		// Структура фильтра скользящего среднего.

typedef struct
{
	float buf[MAX_MEDIAN_FLOAT_SIZE];
	float buf_sorted[MAX_MEDIAN_FLOAT_SIZE];

	unsigned int pointer;

} MedianFloatFilter_Struct;		// Структура медианного фильтра.



typedef struct
{
	float yn;	// Переменная для хранения значения выходной переменной
				// с предыдущего такта расчета.

	float b0; 	// Коэффициент числитеь ПФ фильтра.
	float a1;	// Коэффициент знаменателя ПФ фильтра.

} Low_Filter_1st_Order_Struct; 	// Структура фильтра нижних частот первого порядка.

float MovingFloatFilter(MovingFloatFilter_Struct * filter, float x);
float MedianFloatFilter(MedianFloatFilter_Struct * filter, float x);
float Low_Filter_1st_Order (Low_Filter_1st_Order_Struct * filter, float x);

extern MovingFloatFilter_Struct FILTER_MOV;
extern MedianFloatFilter_Struct FILTER_MED;
extern Low_Filter_1st_Order_Struct  FILTER_10RD;



#endif
