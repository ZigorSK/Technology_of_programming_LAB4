#pragma once
#ifndef _selection_sort_H_
#include <iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define _selection_sort_H_

template <class Ttype>
void show(Ttype *arr, int size)
{
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
}


template <class Ttype> //Ttype- указатель на массив определённоготипа(Тип определяется компиляторовв зависимости 
	void selection_sort(Ttype *arr, int size, int flag)//от предеаваемого типа, size - размер массива, flag = 1 по возрастанию, flag = 0 по убыванию сортировка
{

	try
	{
		if (size < 0)
		{
			cout << "Введённое значение размера массива меньше 0!!!" << endl;
			throw( arr);
		}
		int val;
		if (flag == 1)//сортировка по возрастанию
		{
			for (int i = 0; i < size - 1; i++)
			{
				/* устанавливаем начальное значение минимального индекса */
				Ttype min_i = arr[i];
				val = i;
				/* находим индекс минимального элемента */
				for (int j = i + 1; j < size; j++)
				{
					if (arr[j] < min_i)
					{
						min_i = arr[j];
						val = j;
					}
				}
				/* меняем значения местами */
				min_i = arr[i];
				arr[i] = arr[val];
				arr[val] = min_i;
			}
		}
		else //убыванию
		{
			for (int i = 0; i < size - 1; i++)
			{
				/* устанавливаем начальное значение минимального индекса */
				Ttype min_i = arr[i];
				val = i;
				/* находим индекс минимального элемента */
				for (int j = i + 1; j < size; j++)
				{
					if (arr[j] > min_i)
					{
						min_i = arr[j];
						val = j;
					}
				}
				/* меняем значения местами */
				min_i = arr[i];
				arr[i] = arr[val];
				arr[val] = min_i;
			}
		}
		show(arr, size);
	}
	catch(Ttype arr)
	{
		cout << "Безопасное завершение работы программы!!!" << endl;
		system("pause");
		exit(0);
	}

}

//Явная спецификация шаблонной функции для типа char**
template <> //
void selection_sort(char **arr, int size, int flag)// size - размер массива, flag = 1 по возрастанию, flag = 0 по убыванию сортировка
{

	try
	{
		if (size < 0)
		{
			cout << "Введённое значение размера массива меньше 0!!!" << endl;
			throw(arr);
		}
		int val;
		if (flag == 1)//сортировка по возрастанию
		{
			for (int i = 0; i < size - 1; i++)
			{
				// устанавливаем начальное значение минимального индекса 
				char min_i[1000];
				strcpy( min_i, arr[i]);
				val = i;
				// находим индекс минимального элемента 
				for (int j = i + 1; j < size; j++)
				{
					if ((strcmp(arr[j], min_i)) < 0)
					{
						strcpy(min_i, arr[j]);
						val = j;
					}
				}
				// меняем значения местами, необходимо перевыделить память, если размер строк разный
				if (strlen(arr[i]) < strlen(arr[val]))
				{
					strcpy(min_i, arr[i]);

					delete[] arr[i];//перевыделяем память для arr[i]
					arr[i] = new char[strlen(arr[val]) + 1];

					strcpy(arr[i], arr[val]);
					strcpy(arr[val], min_i);
				}
				else
				{
					strcpy(min_i, arr[val]);

					delete[] arr[val];//перевыделяем память для arr[i]
					arr[val] = new char[strlen(arr[i]) + 1];

					strcpy(arr[val], arr[i]);
					strcpy(arr[i], min_i);
				}
			}
		}
		else //убыванию
		{
			for (int i = 0; i < size - 1; i++)
			{
				// устанавливаем начальное значение минимального индекса 
				char min_i[1000];
				strcpy(min_i, arr[i]);
				val = i;
				// находим индекс минимального элемента 
				for (int j = i + 1; j < size; j++)
				{
					if ((strcmp(arr[j], min_i)) > 0)
					{
						strcpy(min_i, arr[j]);
						val = j;
					}
				}
				// меняем значения местами, необходимо перевыделить память, если размер строк разный
				if (strlen(arr[i]) < strlen(arr[val]))
				{
					strcpy(min_i, arr[i]);

					delete[] arr[i];//перевыделяем память для arr[i]
					arr[i] = new char[strlen(arr[val]) + 1];

					strcpy(arr[i], arr[val]);
					strcpy(arr[val], min_i);
				}
				else
				{
					strcpy(min_i, arr[val]);

					delete[] arr[val];//перевыделяем память для arr[i]
					arr[val] = new char[strlen(arr[i]) + 1];

					strcpy(arr[val], arr[i]);
					strcpy(arr[i], min_i);
				}
			}
		}
		show(arr, size);
	}
	catch (char** arr)
	{
		cout << "Безопасное завершение работы программы!!!" << endl;
		system("pause");
		exit(0);
	}
}



#endif
