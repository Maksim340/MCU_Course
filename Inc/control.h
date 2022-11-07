#ifndef CONTROL_H_
#define CONTROL_H_

#define SET_SHIFTS_MAX_COUNT ((unsigned int)(0.5*100.e3))

typedef struct
{

}Control_Struct; //Структура с параметрами системы управления

typedef struct
{
	uint32_t count; // 0 - режим измерения (не происходит автоопределение смещения)
					// >0 - режим автоопределения смещения


	struct
	{
		float inj; // Сигнал инжекции
		float u2;  // Выходное напряжение, [В]
		float iL;  // Ток реактора, [А]
		float temperature; // Температура, [град. Ц.]
		float u1;  // Входное напряжение, [В]
		float in;  // Выходной ток, [А]

	} data, shift, scale, sum; 	//data = scale * x + shift - Структура с расчитанными значениями
								//shift - Структура с расчитанными значениями
								//scale - Структура с расчитанными значениями
								//sum - Переменные для накопления сумм при автоопределении смещения

	struct
	{
		float data; 		// Значение для вывода на ЦАП
		float shift; 		// Смещение значения переменной
		float scale; 		// Коэффициент масштабирования переменной
	}dac[2];	// Структура с параметрами ЦАП1 и ЦАП 2

}Measure_Struct; //Структура с параметрами измерений

typedef struct
{

}Protect_Struct; //Структура с параметрами защит





extern Measure_Struct Boost_Measure;





#endif
