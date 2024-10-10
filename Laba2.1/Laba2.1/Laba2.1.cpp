#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}


int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end;
	int i = 0, j = 0, r, min = -1000, max = 1000, c = 10000;
	int mas1[10000], mas2[10000], mas3[10000];
	for (int i = 0; i < c; i++)
	{
		mas1[i] = min + rand() % (max - min + 1);
		mas2[i] = mas1[i];
		mas3[i] = mas1[i];

	}
	clock_t starttime, endtime;

	// рандом
	starttime = clock();
	shell(mas1, c);
	endtime = clock();
	float t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Сортировка Шелла на случайно наборе: %f\n", t);

	starttime = clock();
	qs(mas2,0,c-1);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Быстрая сортировка на случайно наборе: %f\n", t);

	starttime = clock();
	qsort(mas3, c, sizeof(int), compare);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Функция qsort() на случайно наборе: %f\n", t);

	// возрастающая
	for (int ii = 0; i < c; i++)
	{
		mas1[i] = i;
		mas2[i] = i;
		mas3[i] = i;
	}

	starttime = clock();
	shell(mas1, c);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Сортировка Шелла на возрастающей последовательности чисел: %f\n", t);

	starttime = clock();
	qs(mas2, 0, c - 1);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Быстрая сортировка на возрастающей последовательности чисел: %f\n", t);

	starttime = clock();
	qsort(mas3, c, sizeof(int), compare);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Функция qsort() на возрастающей последовательности чисел: %f\n", t);

	// Убывающая
	for (int ii = 0; i < c; i++)
	{
		if (i <= c / 2)
		{
			mas1[i] = i;
		}
		else
		{
			mas1[i] = c - i;
		}
		mas2[i] = mas1[i];
		mas3[i] = mas1[i];
	}

	starttime = clock();
	shell(mas1, c);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Сортировка Шелла на убывающей последовательности чисел: %f\n", t);

	starttime = clock();
	qs(mas2, 0, c - 1);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Быстрая сортировка на убывающей последовательности чисел: %f\n", t);

	starttime = clock();
	qsort(mas3, c, sizeof(int), compare);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Функция qsort() на убывающей последовательности чисел: %f\n", t);

	// возрастающая - убывающая
	for (int ii = 0; i < c; i++)
	{
		mas1[i] = c - i;
		mas2[i] = c - i;
		mas3[i] = c - i;
	}

	starttime = clock();
	shell(mas1, c);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Сортировка Шелла на возраст - убыв последовательности чисел: %f\n", t);

	starttime = clock();
	qs(mas2, 0, c - 1);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Быстрая сортировка на возраст - убыв последовательности чисел: %f\n", t);

	starttime = clock();
	qsort(mas3, c, sizeof(int), compare);
	endtime = clock();
	t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
	printf("Функция qsort() на возраст - убыв последовательности чисел: %f\n", t);

}
