#pragma once

#include <iostream>

template <typename T>
void choisesSort(T* arr, int const length) //СЛОЖНОСТЬ О(n^2) Начиная с элта под индексом 0, ищем в массиве наименьшее значение.Найденное значение меняем местами с нулевым элементом.
//Повторяем шаги для следующего индекса в массиве.
{
	for (int i = 0; i < length-1; ++i)
	{
		T count = arr[i];
		int key = i;
		for (int j = i + 1; j < length; ++j) 
			if (arr[j] < arr[key]) 
				key = j;
		if (key != i) 
		{
			arr[i] = arr[key];
			arr[key] = count;
		}
	}
}

template <typename T>
void bubbleSort(T* arr, int const length) // СЛОЖНОСТЬ О(n^2) Прохождение по всему массиву; Сравнивание между собой пар соседних ячеек;
//Если при сравнении оказывается, что значение ячейки i больше, чем значение ячейки i + 1, то мы меняем значения этих ячеек местами;
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length-1; j++) {
			if (arr[j] > arr[j + 1]) {
				int b = arr[j]; 
				arr[j] = arr[j + 1]; 
				arr[j + 1] = b;
			}
		}
	}
}

template <typename T>
void shellSort(T* arr, int const length)//ХУДШЕЕ ВРЕМЯ O(n2), ЛУЧШЕЕ O(n log2 n) 
//Сравнение разделенных на группы элементов последовательности, находящихся друг от друга на некотором расстоянии (d/2).
{
	int d = length;
	d = d / 2;
	while (d > 0)
	{
		for (int i = 0; i < length - d; ++i)
		{
			if(arr[i] > arr[i + d])
			{
				T count = arr[i];
				arr[i] = arr[i + d];
				arr[i + d] = count;
			}
		}
		d = d / 2;
	}
}

template <typename T>
void quickSort(T* arr, int length)//В СРЕДНЕМ  O(nlog n), В ХУДШЕМ o(n2) СРАВНЕНИЙ, упорядочиваем массивы до границы mid, далее рекурсивно
{
	//Указатели в начало и в конец массива
	int i = 0;
	int j = length - 1;

	//Центральный элемент массива
	int mid = arr[length / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (arr[i] < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (arr[j] > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		quickSort(arr, j + 1);
	}
	if (i < length) {
		//"Правый кусок"
		quickSort(&arr[i], length - i);
	}
}

template <typename T>
void mergingSort(T* arr, int const length)
{
	T* N = new T[length * 2];
	for (int i = 0; i < length; ++i)
		N[i] = arr[i];
	bool s = true, f;
	int i, j, k, l;
	do
	{
		if (s)
		{
			i = 0;
			j = length - 1;
			k = length;
			l = 2 * length - 1;
		}
		else
		{
			k = 0;
			l = length - 1;
			i = length;
			j = 2 * length - 1;
		}
		int d = 1;
		f = false;
		while (i != j)
		{
			if (N[i] < N[j])
			{
				N[k] = N[i];
				k += d;
				++i;
				if (N[i - 1] <= N[i]) continue;
				do
				{
					N[k] = N[j];
					k += d;
					--j;
				} while (N[j + 1] <= N[j]);
				f = true;
			}
			else
			{
				N[k] = N[j];
				k += d;
				--j;
				if (N[j + 1] <= N[j]) continue;
				do
				{
					N[k] = N[i];
					k += d;
					++i;
				} while (N[i - 1] <= N[i]);
				f = true;
			}
		}
		N[k] = N[i];
		s = !s;
		d = -d;
		std::swap(k, l);
	} while (f);
	if (s)
		for (int c = 0; c < length; ++c)
			arr[c] = N[c];
	else
		for (int c = 0; c < length; ++c)
			arr[c] = N[c + length];
	delete[] N;
}
