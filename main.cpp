#include<iostream>
#include"Header.h"
#include<cstdio>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Rus");
	
	int choice = 0, choice2 = 0;

	do {

		system("cls");
		cout << "Выбирите задание:" << endl << "[1] Сортировка выбором." << endl << "[2] Параметризированый список" << endl << "[0] Выход из программы." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			do
			{
				system("cls");
				cout << "Выбирите тип данных:" << endl << "[0] Перейти к другому заданию." << endl << "[1] int." << endl << "[2] char." << endl << "[3] float." << endl << "[4] double." << endl << "[5] char*." << endl;
				cin >> choice2;

				system("cls");
				switch (choice2)
				{
				case 1:
				{
					int size = 0,flag = 0;
					cout << "Введите размер массива типа int:";
					cin >> size;
					system("cls");

					int *arr;
					arr = new int [size];

					cout << "[1] Сортировака повозрастанию." << endl << "[0] Сортировка по убыванию" << endl;
					cin >> flag;
					system("cls");

					for (int i = 0; i < size; i++)
					{
						cout << "Введите элмент типа int" << endl;
						cin >> arr[i];
						cout << endl;
					}

					selection_sort(arr, size, flag);

					delete[] arr;
					break;
				}
				case 2:
				{
					int size = 0, flag = 0;
					cout << "Введите размер массива типа char:";
					cin >> size;
					system("cls");

					char *arr;
					arr = new char[size];

					cout << "[1] Сортировака повозрастанию." << endl << "[0] Сортировка по убыванию" << endl;
					cin >> flag;
					system("cls");

					for (int i = 0; i < size; i++)
					{
						cout << "Введите символ: ";
						cin >> arr[i];
						cout << endl;
					}

					selection_sort(arr, size, flag);

					delete[] arr;
					break;
				}
				case 3:
				{
					int size = 0, flag = 0;
					cout << "Введите размер массива типа float:";
					cin >> size;
					system("cls");

					float *arr;
					arr = new float[size];

					cout << "[1] Сортировака повозрастанию." << endl << "[0] Сортировка по убыванию" << endl;
					cin >> flag;
					system("cls");

					for (int i = 0; i < size; i++)
					{
						cout << "Введите число типа float: ";
						cin >> arr[i];
						cout << endl;
					}

					selection_sort(arr, size, flag);

					delete[] arr;
					break;
				}
				case 4:
				{
					int size = 0, flag = 0;
					cout << "Введите размер массива типа double:";
					cin >> size;
					system("cls");

					double *arr;
					arr = new double[size];

					cout << "[1] Сортировака повозрастанию." << endl << "[0] Сортировка по убыванию" << endl;
					cin >> flag;
					system("cls");
					for (int i = 0; i < size; i++)
					{
						cout << "Введите число типа double: ";
						cin >> arr[i];
						cout << endl;
					}
					
					selection_sort(arr, size, flag);

					delete[] arr;
					break;
				}
				case 5:
				{
					int size = 0, flag = 0;
					char **arr;

					cout << "Введите размер массива типа char*:";
					cin >> size;
					system("cls");

					arr = new char*[size];

					cout << "[1] Сортировака повозрастанию." << endl << "[0] Сортировка по убыванию" << endl;
					cin >> flag;
					system("cls");
					getchar();
					for (int i = 0; i < size; i++)
					{
						cout << "Введите строку:";
						char tmp[1000];
						cin.getline(tmp,1000);
						cout << endl;
						arr[i] = new char[ strlen(tmp)+1 ];
						strcpy(arr[i], tmp);
					}

					selection_sort(arr, size, flag);

					for (int i = 0; i < size; i++)
					{
						delete [] arr[i];
					}

					delete[] arr;
					break;
				}
				case 0: break;
				default:
					cout << "Введена неправильная команда" << endl;
					break;
				}

			} while (choice2);

			break;
		}
		case 2:
		{
			int choice3 = 0;
			do
			{
				system("cls");
				cout << "Выбирите тип данных:" << endl << "[0] Перейти к другому заданию." << endl << "[1] int." << endl << "[2] char." << endl << "[3] float." << endl << "[4] double." << endl << "[5] char*." << endl;
				cin >> choice2;

				system("cls");

				switch (choice2)
				{
				case 1://int
				{
					list <int> l;
					

					do {
						system("cls");
						cout << "[0] Перейди к другому действию" << endl<<"[1] Добавить элемент в список."<< endl << "[2] Удалить элемент из списка." << endl
							<<"[3] Вывести значение узла списка."<<endl<<"[4] Изменить значение элемнета"<<endl<<"[5] Слияние 2-х списков:"<<endl<<"[6] Вывести список на экран:"<<endl;
						cin >> choice3;
						system("cls");

						switch (choice3)
						{
						case 1:
						{
							int pos = 0; int data = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Введите число типа инт:";
							cin >> data;
							cout << endl;

							l.add(data, pos);
						
							l.show();
							break;
						}
						case 2:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Удалённый элемент:" << l[pos] << endl;
							l.del(pos);
							system("pause");
							break;
						}
						case 3:
						{
							int pos = 0;;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << l[pos];
							system("pause");
							break;
						}
						case 4:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cin >> l[pos];
							break;
						}
						case 5:
						{
							list <int> l2 = l;
							l + l2;
							cout << "Список слитый сам с собой" << endl;
							l.show();
							break;
						}
						case 6:
							l.show();
							break;
						case 0: break;
						default: cout << "Введена неправильная команда!!!" << endl; break;
						}
					} while (choice3);

					break;
				}
				case 2://char
				{
					list <char> l;
					do {
						system("cls");
						cout << "[0] Перейди к другому действию" << endl << "[1] Добавить элемент в список." << endl << "[2] Удалить элемент из списка." << endl
							<< "[3] Вывести значение узла списка." << endl << "[4] Изменить значение элемнета" << endl << "[5] Слияние 2-х списков:" << endl << "[6] Вывести список на экран:" << endl;
						cin >> choice3;
						system("cls");

						switch (choice3)
						{
						case 1:
						{
							int pos = 0; char data;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Введите число символ:";
							cin >> data;
							cout << endl;

							l.add(data, pos);

							l.show();
							break;
						}
						case 2:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Удалённый элемент:" << l[pos] << endl;
							l.del(pos);
							system("pause");
							break;
						}
						case 3:
						{
							int pos = 0;;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << l[pos];
							system("pause");
							break;
						}
						case 4:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cin >> l[pos];
							break;
						}
						case 5:
						{
							list <char> l2 = l;
							l + l2;
							cout << "Список слитый сам с собой" << endl;
							l.show();
							break;
						}
						case 6:
							l.show();
							break;
						case 0: break;
						default: cout << "Введена неправильная команда!!!" << endl; break;
						}
					} while (choice3);
					break;
				}
				case 3://float
				{
					list <float> l; 
					do {
						system("cls");
						cout << "[0] Перейди к другому действию" << endl << "[1] Добавить элемент в список." << endl << "[2] Удалить элемент из списка." << endl
							<< "[3] Вывести значение узла списка." << endl << "[4] Изменить значение элемнета" << endl << "[5] Слияние 2-х списков:" << endl << "[6] Вывести список на экран:" << endl;
						cin >> choice3;
						system("cls");

						switch (choice3)
						{
						case 1:
						{
							int pos = 0; float data = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Введите число типа float:";
							cin >> data;
							cout << endl;

							l.add(data, pos);

							l.show();
							break;
						}
						case 2:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Удалённый элемент:" << l[pos] << endl;
							l.del(pos);
							system("pause");
							break;
						}
						case 3:
						{
							int pos = 0;;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << l[pos];
							system("pause");
							break;
						}
						case 4:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cin >> l[pos];
							break;
						}
						case 5:
						{
							list <float> l2 = l;
							l + l2;
							cout << "Список слитый сам с собой" << endl;
							l.show();
							break;
						}
						case 6:
							l.show();
							break;
						case 0: break;
						default: cout << "Введена неправильная команда!!!" << endl; break;
						}
					} while (choice3);
					break;
				}
				case 4://double
				{
					list <double> l;
					do {
						system("cls");
						cout << "[0] Перейди к другому действию" << endl << "[1] Добавить элемент в список." << endl << "[2] Удалить элемент из списка." << endl
							<< "[3] Вывести значение узла списка." << endl << "[4] Изменить значение элемнета" << endl << "[5] Слияние 2-х списков:" << endl << "[6] Вывести список на экран:" << endl;
						cin >> choice3;
						system("cls");

						switch (choice3)
						{
						case 1:
						{
							int pos = 0; double data = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Введите число типа double:";
							cin >> data;
							cout << endl;

							l.add(data, pos);

							l.show();
							break;
						}
						case 2:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Удалённый элемент:" << l[pos] << endl;
							l.del(pos);
							system("pause");
							break;
						}
						case 3:
						{
							int pos = 0;;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << l[pos];
							system("pause");
							break;
						}
						case 4:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cin >> l[pos];
							break;
						}
						case 5:
						{
							list <double> l2 = l;
							l + l2;
							cout << "Список слитый сам с собой" << endl;
							l.show();
							break;
						}
						case 6:
							l.show();
							break;
						case 0: break;
						default: cout << "Введена неправильная команда!!!" << endl; break;
						}
					} while (choice3);
					break;
				}
				case 5://char*
				{
					list <char *> l;
					do {
						system("cls");
						cout << "[0] Перейди к другому действию" << endl << "[1] Добавить элемент в список." << endl << "[2] Удалить элемент из списка." << endl
							<< "[3] Вывести значение узла списка." << endl << "[4] Изменить значение элемнета" << endl << "[5] Слияние 2-х списков:" << endl << "[6] Вывести список на экран:" << endl;
						cin >> choice3;
						system("cls");

						switch (choice3)
						{
						case 1:
						{
							int pos = 0; char data[1000];
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Введите строку:";
							cin >> data;
							cout << endl;

							l.add(data, pos);

							l.show();
							break;
						}
						case 2:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << endl;

							cout << "Удалённый элемент:" << l[pos] << endl;
							l.del(pos);
							system("pause");
							break;
						}
						case 3:
						{
							int pos = 0;;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cout << l[pos];
							system("pause");
							break;
						}
						case 4:
						{
							int pos = 0;
							cout << "Введите позицию в списке:";
							cin >> pos;
							cin >> l[pos];
							break;
						}
						case 5:
						{
							list <char *> l2 = l;
							l + l2;
							cout << "Список слитый сам с собой" << endl;
							l.show();
							break;
						}
						case 6:
							l.show();
							break;
						case 0: break;
						default: cout << "Введена неправильная команда!!!" << endl; break;
						}
					} while (choice3);
					break;
				}
				case 0: break;
				
				default:
					cout << "Введена неправильная команда!!!" << endl;
					break;
				}

			} while (choice2);
		}
		case 0: break;
		default:
			cout << "Введена неправильная команда!!!" << endl;
			break;
		}

	} while (choice);
	return 0;

}

