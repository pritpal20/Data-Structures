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
	typedef const T & const_reference;
	typedef T* pointer;
	typedef const T *  const_pointer;
	
	class iterator
	{
		T *current ;
		
		public : 
		iterator():current(NULL)
		{
		}
		iterator(T* a_current):current(a_current)
		{
		}
		
		iterator operator++();
		iterator operator++(int);
		bool operator !=(const iterator rhs);
		bool operator ==(const iterator rhs);
		T operator*() const;
	};
	
	vector();
	explicit vector(size_type,const T&);
	vector(const vector&);

	size_type size() const { return vec_sz ;} 
	size_type capacity() const {return rsrv_sz;}
	
	void push_back(T element);
	
	vector<T>& operator=(const vector&);
	const_reference operator[](typename vector<T>::size_type) const;
	reference operator[](typename vector<T>::size_type);
	
	inline void reallocate();
	
	iterator begin() const;
	iterator end() const;
	iterator insert(iterator it,const T &value);
	
	private :
	
	size_type vec_sz ;
	size_type rsrv_sz;
	T *arr;

};

template <typename T>
vector<T>::vector()
{
	puts("Inside ... 1 ");
	rsrv_sz = 4;
	vec_sz = 0;
	arr = new T[rsrv_sz];

}

template <typename T>
vector<T>::vector(size_type n,const T &value = T())
{
	puts("Inside ... 2 ");
	vec_sz = n;
	rsrv_sz = vec_sz << 2 ;
	
	arr = new T[rsrv_sz];
	for(int i = 0; i < vec_sz ; i++)
		arr[i] = value;
}

//Copy constructor : 
template <typename T>
vector<T>::vector(const vector &obj)
{
	cout << "Copy constructor " << endl;
	rsrv_sz = obj.rsrv_sz;
	vec_sz = obj.vec_sz;
	
	arr = new T[rsrv_sz];
	for(int i = 0 ; i < vec_sz ; i++)
		arr[i] = obj.arr[i];
}

//Overloaded assignment operator : 
template <typename T>
vector<T>& vector<T>::operator=(const vector& rhs)
{
	if(this == &rhs)
	{
		cout << "self referencing doin nothng \n" ;
		return *this;		
	}
	puts("Inside ...3 ");
	if(rsrv_sz < rhs.vec_sz)
	{
		rsrv_sz = rhs.vec_sz << 1 ;
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
	
	if(vec_sz == rsrv_sz )
	{
		rsrv_sz <<= 1;
		reallocate();
	}
	arr[vec_sz] = element;
	vec_sz++;
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](typename vector<T>::size_type index) const
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
	T *arrnew = new T[rsrv_sz];
	memcpy(arrnew,arr,vec_sz * sizeof(T));
	
	delete [] arr;
	arr = arrnew;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() const {
	return arr;
}

template <typename T>
typename vector<T>::iterator vector<T>::cbegin() const {
	return arr;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() const {
	return arr + vec_sz;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator++()
{
	current = current + 1;
	return current;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator++(int)
{
	T* temp = current;
	operator++();
	return temp;
}

template <typename T>
bool vector<T>::iterator::operator !=(const iterator rhs)
{
	return current != rhs.current;
}

template <typename T>
bool vector<T>::iterator::operator ==(const iterator rhs)
{
	return current == rhs.current;
}

template <typename T>
T vector<T>::iterator::operator*() const
{
	return *current;
}

#endif
