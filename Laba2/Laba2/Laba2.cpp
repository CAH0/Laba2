#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);


	// объявляем переменные для определения времени выполнения
	int i = 0, j = 0, r, st;
	int n = 1000;
	int maxx = 100;
	int minn = -100;
	int** a, ** b, ** c, elem_c;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел

	printf("Введите кол-во элементов в матрице: ");
	scanf("%d", &n);

	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = minn + rand() % (maxx - minn + 1);
		}
	}

	b = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		b[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = minn + rand() % (maxx - minn + 1);
		}
	}

	c = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		c[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = minn + rand() % (maxx - minn + 1);
		}
	}


	while (i < n)
	{
		while (j < n)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;

	while (i < n)
	{
		while (j < n)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	clock_t start = clock();
	for (i = 0;i < n;i++) // O(n) *  O(n^2) = O(n^3)/10^8
	{
		for (j = 0;j < n;j++) // O(n)*O(n) = O(n^2)
		{
			// O(max(1,n)) = O(n)
			elem_c = 0; // O(1)
			for (r = 0;r < n;r++)  //O(n*1) = O(n)
			{
				elem_c = elem_c + a[i][r] * b[r][j];// O(1)
				c[i][j] = elem_c;               // O(1)
			}
		}
		printf("%d\n", i);
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("seconds = %f", seconds);

	scanf("%d", &st);
	return(0);
}
