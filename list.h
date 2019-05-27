#pragma once
#include<iostream>
#include"node.h"
#include<cstring>


template <class T>  class list
{
	node <T> *head;
	int size;
public:
	list() : head(nullptr), size(0) {};
	list(const list<T> &A);
	~list();

	node <T>*get_head();
	void set_head(node <T> *h);
	int get_size();
	void set_size(int d);

	void add(T d, int pos);
	T del(int pos);

	list <T> & operator +(list &op);
	node <T>*operator[](int pos);
	
	void show();
	
	friend ostream& operator << (ostream &out, node <T> *op);
	friend istream& operator >> (istream &in, node <T> *op);//элемент можно ввести, если ранее под него была выделена память
};

template<class T>
inline list<T>::list(const list<T>& A)
{
	node <T> *ptr = A.head;

	for (int i = 1;ptr!= nullptr; i++)
	{
		add(ptr->get_data(), i);
		ptr = ptr->get_next_ptr();
	}
}

template<class T>
inline list<T>::~list()
{
	node <T> *ptr = head;

	while ( head != nullptr)
	{
		ptr = head;
		head = head->get_next_ptr();
		delete ptr;
	}
}
template<>
inline list<char *>::~list()
{
	node <char *> *ptr = head;

	while (head != nullptr)
	{
		ptr = head;
		head = head->get_next_ptr();
		delete ptr->get_data();
		delete ptr;
	}
}

template<class T>
inline node<T>* list<T>::get_head()
{
	return head;
}

template<class T>
inline void list<T>::set_head(node<T>* h)
{
	head = h;
}

template<class T>
inline int list<T>::get_size()
{
	return size;
}

template<class T>
inline void list<T>::set_size(int d)
{
	size = d;
}

template<class T>
void list<T>::add(T d, int pos)//добавление элемента в список на позицию pos
{
	try
	{
		if ((pos > size + 1) || (pos < 1))
			throw(pos);

		node <T> *prev_node = head, *next_node = head;

		if (head != nullptr)
		{
			if (pos == 1)
			{
				node <T> *ptr;
				ptr = new node<T>;
				ptr->set_data(d);
				ptr->set_next_ptr(head);
				head = ptr;
				size++;

			}
			else
			{
				if (pos == (size + 1))//если добавляемый узел в конце списка
				{
					while (prev_node->get_next_ptr() != nullptr)//Ищем узел перед добавляемым
						prev_node = prev_node->get_next_ptr();

					next_node = new node <T>;//выделяем память под новый узел
					prev_node->set_next_ptr(next_node);//связываем предыдущий и новый узел
					next_node->set_next_ptr(nullptr);//т.к. узел теперь последний указатель на следующий null
					next_node->set_data(d);
					size++;
				}
				else//добаляемый узел в середине списка
				{

					for (int i = 1; i < pos; i++)//ищем предыдущий и следующий узел для добавляемого
					{
						prev_node = next_node;
						next_node = next_node->get_next_ptr();
					}
					node <T> *new_node;
					new_node = new node<T>;
					prev_node->set_next_ptr(new_node);//следующий указатель предыдущего узла равен новому
					new_node->set_next_ptr(next_node);//следующий указатель нового равен следующему
					size++;
					new_node->set_data(d);
				}
			}
		}
		else//добаляемый узел в начале списка и в списке больше нет элементов
		{
			head = new node<T>;
			head->set_data(d);
			head->set_next_ptr(nullptr);
			size++;
		}
	}
	catch (int pos)
	{
		cout << "Переданый размер больше, чем size+1 и меньше 1!!! Ничего не будет выполнено!!! Выполнени программы продолжается!" << endl;
		system("pause");
	}
}

template<class T>
T list<T>::del(int pos)
{
	try
	{
		if ((size < pos ) || (size < 1))
			throw pos;
		T ret;
		if (head->get_next_ptr() != nullptr)
		{
			node <T> *del_node = nullptr, *prev_node = nullptr, *next_node = nullptr;
			if (pos != 1)
			{
				if (pos == size)//если удаляется последний элемент в списке
				{
					del_node = head;
					for (int i = 1; i < pos; i++)//ищем предыдущий и последний узел 
					{
						prev_node = del_node;
						del_node = del_node->get_next_ptr();
					}
					ret = del_node->get_data();
					delete del_node;
					prev_node->set_next_ptr(nullptr);
					size--;

				}
				else//удаляется элемент в середине списка
				{
					for (int i = 1; i < pos; i++)//ищем предыдущий и последний узел 
					{
						prev_node = del_node;
						del_node = del_node->get_next_ptr();
					}
					next_node = del_node->get_next_ptr();
					ret = del_node->get_data();
					delete del_node;
					prev_node->set_next_ptr(next_node);
					size--;
				}
			}
			else//удаление первого элемента в списке
			{
				del_node = head;
				head = head->get_next_ptr();
				ret = del_node->get_data();
				delete del_node;
				size--;
			}
			return ret;
		}
		else
		{
			ret = head->get_data();
			delete head;
			head = nullptr;
			size--;
		}
	}
	catch(int pos)
	{
		cout << "Переданый размер больше, чем size+1 и меньше 1!!! Ничего не будет выполнено!!! Выполнени программы продолжается!" << endl;
		system("pause");
	}


}


template<class T>
inline list<T>& list<T>::operator+(list & op)
{
	int s = size + 1;
	node <T> *ptr = op.get_head();
	while (ptr != nullptr)
	{
		add(ptr->get_data(), s);
		ptr = ptr->get_next_ptr();
		s++;
	}
	return *this;
}

template<class T>
node<T>* list<T>::operator[](int pos)
{
	try
	{
		if ((pos > size ) || (pos<1))
			throw(pos);

		if (pos == (size + 1))
		{
			return nullptr;
		}
		else
		{
			node <T> *ptr = head;
				for (int i = 1; i < pos; i++)
				{
					ptr = ptr->get_next_ptr();
				}
			return ptr;
		}
		
	}
	catch (int pos)
	{
		cout << "Переданый размер больше, чем size+1 и меньше 1!!! Ничего не будет выполнено!!! Выполнени программы продолжается!" << endl;
		system("pause");
		return nullptr;
	}

}


template<class T>
void list<T>::show()
{
	node <T> *ptr = head;
	for (int i = 0; i < size; i++)
	{
		cout << ptr;
		ptr = ptr->get_next_ptr();

	}
	system("pause");
}

template<class T>
ostream& operator << (ostream &out, node <T> *op)
{
	if (op)
	{
		cout << "Элемент списка:" << op->get_data() << endl;
	}
	return out;
}

template<class T >
istream& operator >> (istream &in, node <T> *op)//Переинициализация 
{
	if (op != nullptr)
	{
		T B;
		cout << "Введите элемент списка:";

		cin >> B;
		op->set_data(B);
	}
	return in;
}

template<>
istream& operator >> (istream &in, node <char *> *op)//Переинициализация 
{
	if (op != nullptr)
	{
		char B[1000];
		char *N = nullptr;
		cout << "Введите элемент списка:";
		cin >> B;
		int len = strlen(B)+1;

		delete[] op->get_data();
		N = new char[len];
		strcpy(N, B);
		op->set_data(N);
		cout << endl;
	}
	
	return in;
}


template <>
void list<char *>::add(char * d, int pos)//добавление элемента в список на позицию pos, d - указатель на строку
{
	int len = strlen(d) + 1;
	char *ptr = nullptr;

	try
	{
		if ((pos > size + 1) || (pos < 1))
			throw(pos);

		node <char *> *prev_node = head, *next_node = head;

		if (head)
		{
			if (pos == 1)//если добавляем 1 и уже есть элементы
			{
				next_node = new node <char *>;//выделяем память под новый узел
				ptr = new char[len];//выделяем память для строки
				next_node->set_data(ptr);//дата равна данному указателю
				strcpy(next_node->get_data(), d);//копируем d  в data

				next_node->set_next_ptr(head);
				head = next_node;
				size++;
			}
			else
			{
				if (pos == (size + 1))//если добавляемый узел в конце списка
				{
					while (prev_node->get_next_ptr() != nullptr)//Ищем узел перед добавляемым
						prev_node = prev_node->get_next_ptr();

					next_node = new node <char *>;//выделяем память под новый узел
					ptr = new char[len];//выделяем память для строки
					next_node->set_data(ptr);//дата равна данному указателю
					strcpy(next_node->get_data(), d);//копируем d  в data

					prev_node->set_next_ptr(next_node);//связываем предыдущий и новый узел
					next_node->set_next_ptr(nullptr);//т.к. узел теперь последний указатель на следующий null
					size++;
				}
				else//добаляемый узел в середине списка
				{

					for (int i = 1; i < pos; i++)//ищем предыдущий и следующий узел для добавляемого
					{
						prev_node = next_node;
						next_node = next_node->get_next_ptr();
					}
					node <char *> *new_node;

					new_node = new node <char *>;//выделяем память под новый узел
					ptr = new char[len];//выделяем память для строки
					new_node->set_data(ptr);//дата равна данному указателю
					strcpy(new_node->get_data(), d);//копируем d  в data

					prev_node->set_next_ptr(new_node);//следующий указатель предыдущего узла равен новому
					new_node->set_next_ptr(next_node);//следующий указатель нового равен следующему
					size++;
				}
			}
		}
		else//добаляемый узел в начале списка и нет элементов
		{
			head = new node <char *>;//выделяем память под новый узел
			ptr = new char[len];//выделяем память для строки
			head->set_data(ptr);//дата равна данному указателю
			strcpy(head->get_data(), d);//копируем d  в data

			head->set_next_ptr(nullptr);
			size++;
		}
	}
	catch (int pos)
	{
		cout << "Переданый размер больше, чем size+1 и меньше 1!!! Ничего не будет выполнено!!! Выполнени программы продолжается!" << endl;
		system("pause");
	}
}

template <>
char * list<char *>::del(int pos)
{
	try
	{
		if ((size < pos) || (size < 1))
			throw pos;

		static char ret[1000];
		if (head->get_next_ptr() == nullptr)
		{
			node <char *> *del_node = nullptr, *prev_node = nullptr, *next_node = nullptr;
			if (pos != 1)
			{
				if (pos == size)//если удаляется последний элемент в списке
				{
					del_node = head;
					for (int i = 1; i < pos; i++)//ищем предыдущий и последний узел 
					{
						prev_node = del_node;
						del_node = del_node->get_next_ptr();
					}
					strcpy(ret, del_node->get_data());
					delete del_node->get_data();
					delete del_node;
					prev_node->set_next_ptr(nullptr);
					size--;

				}
				else//удаляется элемент в середине списка
				{
					for (int i = 1; i < pos; i++)//ищем предыдущий и последний узел 
					{
						prev_node = del_node;
						del_node = del_node->get_next_ptr();
					}
					next_node = del_node->get_next_ptr();
					strcpy(ret, del_node->get_data());
					delete del_node->get_data();
					delete del_node;
					prev_node->set_next_ptr(next_node);
					size--;
				}
			}
			else//удаление первого элемента в списке
			{
				del_node = head;
				head = head->get_next_ptr();
				strcpy(ret, del_node->get_data());
				delete del_node->get_data();
				delete del_node;
				size--;
			}
			return ret;
		}
		else
		{
		strcpy(ret, head->get_data());
		delete head;
		head = nullptr;
		return ret;
		size--;
		}

	}
	catch (int pos)
	{
		cout << "Переданый размер больше, чем size+1 и меньше 1!!! Ничего не будет выполнено!!! Выполнени программы продолжается!" << endl;
		system("pause");
	}


}
