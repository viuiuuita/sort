#pragma once

#include <iostream>

template <typename T>
void choisesSort(T* arr, int const length) //��������� �(n^2) ������� � ���� ��� �������� 0, ���� � ������� ���������� ��������.��������� �������� ������ ������� � ������� ���������.
//��������� ���� ��� ���������� ������� � �������.
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
void bubbleSort(T* arr, int const length) // ��������� �(n^2) ����������� �� ����� �������; ����������� ����� ����� ��� �������� �����;
//���� ��� ��������� �����������, ��� �������� ������ i ������, ��� �������� ������ i + 1, �� �� ������ �������� ���� ����� �������;
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
void shellSort(T* arr, int const length)//������ ����� O(n2), ������ O(n log2 n) 
//��������� ����������� �� ������ ��������� ������������������, ����������� ���� �� ����� �� ��������� ���������� (d/2).
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
void quickSort(T* arr, int length)//� �������  O(nlog n), � ������ o(n2) ���������, ������������� ������� �� ������� mid, ����� ����������
{
	//��������� � ������ � � ����� �������
	int i = 0;
	int j = length - 1;

	//����������� ������� �������
	int mid = arr[length / 2];

	//����� ������
	do {
		//��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
		//� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
		while (arr[i] < mid) {
			i++;
		}
		//� ������ ����� ���������� ��������, ������� ������ ������������
		while (arr[j] > mid) {
			j--;
		}

		//������ �������� �������
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//����������� ������, ���� ��������, ��� �����������
	if (j > 0) {
		//"����� �����"
		quickSort(arr, j + 1);
	}
	if (i < length) {
		//"������ �����"
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
