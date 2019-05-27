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
	friend istream& operator >> (istream &in, node <T> *op);//������� ����� ������, ���� ����� ��� ���� ���� �������� ������
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
void list<T>::add(T d, int pos)//���������� �������� � ������ �� ������� pos
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
				if (pos == (size + 1))//���� ����������� ���� � ����� ������
				{
					while (prev_node->get_next_ptr() != nullptr)//���� ���� ����� �����������
						prev_node = prev_node->get_next_ptr();

					next_node = new node <T>;//�������� ������ ��� ����� ����
					prev_node->set_next_ptr(next_node);//��������� ���������� � ����� ����
					next_node->set_next_ptr(nullptr);//�.�. ���� ������ ��������� ��������� �� ��������� null
					next_node->set_data(d);
					size++;
				}
				else//���������� ���� � �������� ������
				{

					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� ��� ������������
					{
						prev_node = next_node;
						next_node = next_node->get_next_ptr();
					}
					node <T> *new_node;
					new_node = new node<T>;
					prev_node->set_next_ptr(new_node);//��������� ��������� ����������� ���� ����� ������
					new_node->set_next_ptr(next_node);//��������� ��������� ������ ����� ����������
					size++;
					new_node->set_data(d);
				}
			}
		}
		else//���������� ���� � ������ ������ � � ������ ������ ��� ���������
		{
			head = new node<T>;
			head->set_data(d);
			head->set_next_ptr(nullptr);
			size++;
		}
	}
	catch (int pos)
	{
		cout << "��������� ������ ������, ��� size+1 � ������ 1!!! ������ �� ����� ���������!!! ��������� ��������� ������������!" << endl;
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
				if (pos == size)//���� ��������� ��������� ������� � ������
				{
					del_node = head;
					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� 
					{
						prev_node = del_node;
						del_node = del_node->get_next_ptr();
					}
					ret = del_node->get_data();
					delete del_node;
					prev_node->set_next_ptr(nullptr);
					size--;

				}
				else//��������� ������� � �������� ������
				{
					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� 
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
			else//�������� ������� �������� � ������
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
		cout << "��������� ������ ������, ��� size+1 � ������ 1!!! ������ �� ����� ���������!!! ��������� ��������� ������������!" << endl;
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
		cout << "��������� ������ ������, ��� size+1 � ������ 1!!! ������ �� ����� ���������!!! ��������� ��������� ������������!" << endl;
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
		cout << "������� ������:" << op->get_data() << endl;
	}
	return out;
}

template<class T >
istream& operator >> (istream &in, node <T> *op)//����������������� 
{
	if (op != nullptr)
	{
		T B;
		cout << "������� ������� ������:";

		cin >> B;
		op->set_data(B);
	}
	return in;
}

template<>
istream& operator >> (istream &in, node <char *> *op)//����������������� 
{
	if (op != nullptr)
	{
		char B[1000];
		char *N = nullptr;
		cout << "������� ������� ������:";
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
void list<char *>::add(char * d, int pos)//���������� �������� � ������ �� ������� pos, d - ��������� �� ������
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
			if (pos == 1)//���� ��������� 1 � ��� ���� ��������
			{
				next_node = new node <char *>;//�������� ������ ��� ����� ����
				ptr = new char[len];//�������� ������ ��� ������
				next_node->set_data(ptr);//���� ����� ������� ���������
				strcpy(next_node->get_data(), d);//�������� d  � data

				next_node->set_next_ptr(head);
				head = next_node;
				size++;
			}
			else
			{
				if (pos == (size + 1))//���� ����������� ���� � ����� ������
				{
					while (prev_node->get_next_ptr() != nullptr)//���� ���� ����� �����������
						prev_node = prev_node->get_next_ptr();

					next_node = new node <char *>;//�������� ������ ��� ����� ����
					ptr = new char[len];//�������� ������ ��� ������
					next_node->set_data(ptr);//���� ����� ������� ���������
					strcpy(next_node->get_data(), d);//�������� d  � data

					prev_node->set_next_ptr(next_node);//��������� ���������� � ����� ����
					next_node->set_next_ptr(nullptr);//�.�. ���� ������ ��������� ��������� �� ��������� null
					size++;
				}
				else//���������� ���� � �������� ������
				{

					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� ��� ������������
					{
						prev_node = next_node;
						next_node = next_node->get_next_ptr();
					}
					node <char *> *new_node;

					new_node = new node <char *>;//�������� ������ ��� ����� ����
					ptr = new char[len];//�������� ������ ��� ������
					new_node->set_data(ptr);//���� ����� ������� ���������
					strcpy(new_node->get_data(), d);//�������� d  � data

					prev_node->set_next_ptr(new_node);//��������� ��������� ����������� ���� ����� ������
					new_node->set_next_ptr(next_node);//��������� ��������� ������ ����� ����������
					size++;
				}
			}
		}
		else//���������� ���� � ������ ������ � ��� ���������
		{
			head = new node <char *>;//�������� ������ ��� ����� ����
			ptr = new char[len];//�������� ������ ��� ������
			head->set_data(ptr);//���� ����� ������� ���������
			strcpy(head->get_data(), d);//�������� d  � data

			head->set_next_ptr(nullptr);
			size++;
		}
	}
	catch (int pos)
	{
		cout << "��������� ������ ������, ��� size+1 � ������ 1!!! ������ �� ����� ���������!!! ��������� ��������� ������������!" << endl;
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
				if (pos == size)//���� ��������� ��������� ������� � ������
				{
					del_node = head;
					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� 
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
				else//��������� ������� � �������� ������
				{
					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� 
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
			else//�������� ������� �������� � ������
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
		cout << "��������� ������ ������, ��� size+1 � ������ 1!!! ������ �� ����� ���������!!! ��������� ��������� ������������!" << endl;
		system("pause");
	}


}
