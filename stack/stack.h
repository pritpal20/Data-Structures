#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>

template <typename T>
class stack {
	
	private : 
	int stk_sz;
	int rsrv_sz;
	T *arr;
	
	public : 
	
	stack();
	void push(const T& data);
	void pop();
	T top() const;
	void reallocate();
	bool empty() const;
	unsigned int size() const;
	
};

template <typename T>
stack<T>::stack()
{
	stk_sz = 0;
	rsrv_sz = 4;
	arr = new T[rsrv_sz];
}

template <typename T>
void stack<T>::push(const T& data)
{
	// if(stk_sz == rsrv_sz)
	// {
		// rsrv_sz = stk_sz << 2 ;
		// reallocate();
		// printf("stack full \n");
		// return;
	// }
	arr[stk_sz++] = data;
}

template <typename T>
void stack<T>::pop()
{
	if(stk_sz == 0)
	{
		printf("stack empty \n");
		return;
	}
	arr[--stk_sz].~T();
}

template <typename T>
T stack<T>::top() const
{	
	int index = stk_sz -1;
	return arr[index];
}

template <typename T>
bool stack<T>::empty() const
{
	return stk_sz == 0 ? 1 : 0;
}

template <typename T>
unsigned int stack<T>::size() const
{
	return stk_sz;
}
#endif