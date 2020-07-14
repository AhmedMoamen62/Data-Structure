#pragma once
#include <iostream>
using namespace std;
template <class T>
class Dynamicarray
{
	T* p;
	int u; //size
public:
	Dynamicarray();
	void setsize(int);
	int getsize();
	void add(T);
	void setel(int, T);
	void removeel(int);
	void removeall();
    T& operator[](int);
	T getel(int);
	Dynamicarray(const Dynamicarray<T>& x);
	~Dynamicarray();
};
template <typename T>
Dynamicarray<T>::Dynamicarray()
{
	p = NULL;
	u = 0;
}
template <typename T>
Dynamicarray<T>::~Dynamicarray()
{
	if (p != NULL)
	{
		delete[]p;
	}
}
template <typename T>
T& Dynamicarray<T>::operator[](int index)
{
    return p[index];
}
template <typename T>
int Dynamicarray<T>::getsize()
{
	return u;
}
template <typename T>
T Dynamicarray<T>::getel(int a)
{
	return p[a - 1];
}
template <typename T>
void Dynamicarray<T>::setel(int a, T o)
{
	p[a - 1] = o;
}
template <typename T>
void Dynamicarray<T>::add(T a)
{
	setsize(u + 1);
	p[u - 1] = a;
}
template <typename T>
void Dynamicarray<T>::removeel(int a)
{
	for (int i = a - 1; i < u - 1; i++)
	{
		p[i] = p[i + 1];
	}
	setsize(u - 1);
}
template <typename T>
void Dynamicarray<T>::removeall()
{
	delete[]p;
}
template <typename T>
void Dynamicarray<T>::setsize(int a)
{
	if (u > a)
	{
		T* t = new T[a];
		for (int i = 0; i < a; i++)
		{
			t[i] = p[i];
		}
		delete[]p;
		u = a;
		p = t;
		return;
	}
	if (u < a)
	{
		T* t = new T[a];
		for (int i = 0; i < u; i++)
		{
			t[i] = p[i];
		}
		delete[]p;
		u = a;
		p = t;
		return;
	}
	if (u == 0)
	{
		p = new T[a];
		u = a;
		return;
	}
}
template <typename T>
Dynamicarray<T>::Dynamicarray(const Dynamicarray<T>& x)
{
	u = x.u;
	if (u > 0)
	{
		p = new T[u];
		for (int i = 0; i < u; i++)
		{
			p[i] = x.p[i];
		}
	}
	else
	{
		p = NULL;
	}
}


