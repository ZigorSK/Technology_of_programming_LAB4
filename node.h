#pragma once
#include<iostream>
#include<cstring>

template <class T> 
	class node
{
	T data;
	node <T>*next_ptr;


public:
	node() : data(0), next_ptr(nullptr) {};//����������� ��� ����������
	node(T d) : data(d), next_ptr(nullptr) {};//����������� c ����������
	node(const node<T> &a) :next_ptr(a.get_next_ptr()), data(a.get_data()) {};//����������� �����������

	~node() {};

	T get_data();
	void set_data(T d);

	node <T> *get_next_ptr();
	void set_next_ptr(node <T> *ptr);
};
//����� ������������ ������ node ���� char *


template<class T>
inline T node<T>::get_data()
{
	return data;
}

template<class T>
inline void node<T>::set_data(T d)
{
	data = d;
}

template<class T>
inline node <T> *node<T>::get_next_ptr()
{
	return next_ptr;
}

template<class T>
inline void node<T>::set_next_ptr(node<T>* ptr)
{
	next_ptr = ptr;
}


// ����� ������������� ������ node<char*>
//
//
//

template <> 
	class node <char*>
{
	char*  data;
	node <char*> *next_ptr;


public:
	node() : data(nullptr), next_ptr(nullptr) {};//����������� ��� ����������
	node(char *d) :  next_ptr(nullptr) //����������� c ����������
	{
		strcpy(data, d);
	};
	node(const node<char *>&obg)//����������� �����������
	{
		next_ptr = obg.next_ptr;
		strcpy(data, obg.data);
	}
	~node(){	};

	char *get_data(){	return data;	}
	void set_data(char *d) {	data = d;	}

	node <char *> *get_next_ptr(){	return next_ptr;	}
	void set_next_ptr(node <char *> *ptr) {	next_ptr = ptr;	}
};
	 
