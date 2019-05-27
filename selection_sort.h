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
	cout << "��������������� ������:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
}


template <class Ttype> //Ttype- ��������� �� ������ ����������������(��� ������������ ������������� ����������� 
	void selection_sort(Ttype *arr, int size, int flag)//�� ������������� ����, size - ������ �������, flag = 1 �� �����������, flag = 0 �� �������� ����������
{

	try
	{
		if (size < 0)
		{
			cout << "�������� �������� ������� ������� ������ 0!!!" << endl;
			throw( arr);
		}
		int val;
		if (flag == 1)//���������� �� �����������
		{
			for (int i = 0; i < size - 1; i++)
			{
				/* ������������� ��������� �������� ������������ ������� */
				Ttype min_i = arr[i];
				val = i;
				/* ������� ������ ������������ �������� */
				for (int j = i + 1; j < size; j++)
				{
					if (arr[j] < min_i)
					{
						min_i = arr[j];
						val = j;
					}
				}
				/* ������ �������� ������� */
				min_i = arr[i];
				arr[i] = arr[val];
				arr[val] = min_i;
			}
		}
		else //��������
		{
			for (int i = 0; i < size - 1; i++)
			{
				/* ������������� ��������� �������� ������������ ������� */
				Ttype min_i = arr[i];
				val = i;
				/* ������� ������ ������������ �������� */
				for (int j = i + 1; j < size; j++)
				{
					if (arr[j] > min_i)
					{
						min_i = arr[j];
						val = j;
					}
				}
				/* ������ �������� ������� */
				min_i = arr[i];
				arr[i] = arr[val];
				arr[val] = min_i;
			}
		}
		show(arr, size);
	}
	catch(Ttype arr)
	{
		cout << "���������� ���������� ������ ���������!!!" << endl;
		system("pause");
		exit(0);
	}

}

//����� ������������ ��������� ������� ��� ���� char**
template <> //
void selection_sort(char **arr, int size, int flag)// size - ������ �������, flag = 1 �� �����������, flag = 0 �� �������� ����������
{

	try
	{
		if (size < 0)
		{
			cout << "�������� �������� ������� ������� ������ 0!!!" << endl;
			throw(arr);
		}
		int val;
		if (flag == 1)//���������� �� �����������
		{
			for (int i = 0; i < size - 1; i++)
			{
				// ������������� ��������� �������� ������������ ������� 
				char min_i[1000];
				strcpy( min_i, arr[i]);
				val = i;
				// ������� ������ ������������ �������� 
				for (int j = i + 1; j < size; j++)
				{
					if ((strcmp(arr[j], min_i)) < 0)
					{
						strcpy(min_i, arr[j]);
						val = j;
					}
				}
				// ������ �������� �������, ���������� ������������ ������, ���� ������ ����� ������
				if (strlen(arr[i]) < strlen(arr[val]))
				{
					strcpy(min_i, arr[i]);

					delete[] arr[i];//������������ ������ ��� arr[i]
					arr[i] = new char[strlen(arr[val]) + 1];

					strcpy(arr[i], arr[val]);
					strcpy(arr[val], min_i);
				}
				else
				{
					strcpy(min_i, arr[val]);

					delete[] arr[val];//������������ ������ ��� arr[i]
					arr[val] = new char[strlen(arr[i]) + 1];

					strcpy(arr[val], arr[i]);
					strcpy(arr[i], min_i);
				}
			}
		}
		else //��������
		{
			for (int i = 0; i < size - 1; i++)
			{
				// ������������� ��������� �������� ������������ ������� 
				char min_i[1000];
				strcpy(min_i, arr[i]);
				val = i;
				// ������� ������ ������������ �������� 
				for (int j = i + 1; j < size; j++)
				{
					if ((strcmp(arr[j], min_i)) > 0)
					{
						strcpy(min_i, arr[j]);
						val = j;
					}
				}
				// ������ �������� �������, ���������� ������������ ������, ���� ������ ����� ������
				if (strlen(arr[i]) < strlen(arr[val]))
				{
					strcpy(min_i, arr[i]);

					delete[] arr[i];//������������ ������ ��� arr[i]
					arr[i] = new char[strlen(arr[val]) + 1];

					strcpy(arr[i], arr[val]);
					strcpy(arr[val], min_i);
				}
				else
				{
					strcpy(min_i, arr[val]);

					delete[] arr[val];//������������ ������ ��� arr[i]
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
		cout << "���������� ���������� ������ ���������!!!" << endl;
		system("pause");
		exit(0);
	}
}



#endif
