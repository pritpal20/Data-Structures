/*
* capacity of vector increases exponentially 
*if vector size defined is 4 then capacity is 2 << 4 ; which is 
*/

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stdlib.h>
#include <string.h>
using std::cout ;
using std::endl ;

template <typename T>
class vector
{
	public :
	
	typedef T value_type;
	typedef unsigned int size_type;
	typedef T & reference;
	
	class iterator
	{
		T *current ;
		public : 
		iterator():current(NULL)
		{
		}
	};	
	vector();
	vector(size_type,const T&);
	vector(const vector&);
	//vector(std::initializer_list<T>);
	vector<T>& operator=(const vector&);

	size_type size() const { return vec_sz ;} 
	size_type Capacity() const {return capacity;}
	
	void push_back(T element);
	reference operator[](typename vector<T>::size_type) const;
	reference operator[](typename vector<T>::size_type);
	
	inline void reallocate();
	
	private :
	
	size_type vec_sz ;
	size_type capacity;
    size_type length;	
	T *arr;

};

template <typename T>
vector<T>::vector()
{
	capacity = 4;
	length = 0;
	vec_sz = 0;
	arr = new T[capacity];

}

template <typename T>
vector<T>::vector(size_type n,const T &value = T())
{
	capacity = n << 1 ;
	vec_sz = n;
	
	arr = new T[vec_sz];
	for(int i = 0; i < vec_sz ; i++)
		arr[i] = value;
}

//Copy constructor : 
template <typename T>
vector<T>::vector(const vector &obj)
{
	cout << "Copy constructor " << endl;
	capacity = obj.capacity;
	length = obj.length;
	vec_sz = obj.vec_sz;
	
	arr = new T[capacity];
	for(int i = 0 ; i < vec_sz ; i++)
		arr[i] = obj.arr[i];
}

// Overloaded assignment operator : 
template <typename T>
vector<T>& vector<T>::operator=(const vector& rhs)
{
	if(this == &rhs)
	{
		cout << "self referencing doin nothng \n" ;
		return *this;		
	}
	
	if(capacity < rhs.vec_sz)
	{
		capacity = rhs.vec_sz << 1 ;
		reallocate();
	}
	
	for(int i = 0 ; i <= rhs.vec_sz ; i++)
		arr[i] = rhs.arr[i];
	vec_sz = rhs.vec_sz;
	
	return *this;
	
}
template <typename T>
void vector<T>::push_back(T element)
{
	
	if(vec_sz == capacity )
	{
		capacity <<= 1;
		reallocate();
	}
	arr[vec_sz] = element;
	vec_sz++;
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](typename vector<T>::size_type index) const
{
	return arr[index];
	
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](typename vector<T>::size_type index) 
{
	return arr[index];
	
}

template <typename T>
inline void vector<T>::reallocate()
{
	T *arrnew = new T[capacity];
	memcpy(arrnew,arr,vec_sz * sizeof(T));
	
	delete [] arr;
	arr = arrnew;
}

#endif
