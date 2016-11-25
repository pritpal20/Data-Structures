#ifndef MY_VECTOR_H
#define MY_VECTOR_H

using std::cout ;
using std::endl ;

template <typename T>
class vector
{
	public :
	
	typedef T value_type;
	typedef unsigned int size_type;
	
	class iterator
	{
		T *current ;
		public : 
		iterator():current(NULL)
		{
		}
	};	
	vector();
	vector(size_type);
	vector(size_type,const T);
	vector(const T&);
	vector(const vector&);
	vector<T>& operator=(const vector&);

	size_type size() const { return capacity ;} 
	
	void push_back(T element);
	value_type operator[](typename vector<T>::size_type) const;


	private :
	
	size_type vec_sz ;
	size_type capacity;
    size_type length;	
	T *arr;

};

template <typename T>
vector<T>::vector()
{
	capacity = 10;
	length = 0;
	vec_sz = 0;
	arr = new T[capacity];

}

template <typename T>
vector<T>::vector(size_type n)
{
	capacity = n << 2 ;
	length = 0;
	arr = new T[capacity];
	for(int i = 0; i < capacity ; i++)
		arr[i] = T();
	vec_sz= n;
}

template <typename T>
vector<T>::vector(const T &value)
{
	capacity = 10 ;
	length = 0;
	arr = new T[capacity];
	for(int i = 0; i < capacity ; i++)
		arr[i] = value;
	length = capacity;
	
}

template <typename T>
vector<T>::vector(size_type n,const T value)
{
	capacity = n << 2 ;
	
	arr = new T[capacity];
	for(int i = 0; i < capacity ; i++)
		arr[i] = value;
	vec_sz= n;
	length = capacity;
}

template <typename T>
vector<T>::vector(const vector &obj)
{
	cout << "Copy constructor " << endl;
	capacity = obj.capacity;
	length = obj.length;
	vec_sz = obj.vec_sz;
	
	arr = new T[capacity];
	for(int i = 0 ; i < capacity ; i++)
		arr[i] = obj.arr[i];
}

template <typename T>
void vector<T>::push_back(T element)
{
	if(length < capacity )
		arr[length++] = element;
	else
		cout << "vector full " << endl;
	

}

template <typename T>
typename vector<T>::value_type vector<T>::operator[](typename vector<T>::size_type index) const
{
	return arr[index];
	
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& obj)
{
	size = obj.size;
	return *this;
}

#endif
