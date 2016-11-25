#ifndef _LINK_NODE_H
#define _LINK_NODE_H

#include <iostream>

using std::cout ;
using std::endl;

template <typename T>
class LinkNode
{
	LinkNode<T> *next;
	LinkNode<T> *prev;
	T obj;
	
	public :
	//constructor : 
	LinkNode(const T &_obj,LinkNode<T> *_next,LinkNode<T> *_prev);
	
	//destructor :
	~LinkNode()
	{
		next = NULL;
		prev = NULL;
	}

	void setNext(LinkNode<T> *_next);
	void setPrev(LinkNode<T> *_prev);
	void setData(const T &_obj);
	
	LinkNode<T>* getNext();
	LinkNode<T>* getPrev();
	T getData();
	T Retrive();
	
};

template <typename T>
LinkNode<T>::LinkNode(const T &_obj = T(),LinkNode<T> *_next = NULL,LinkNode<T> *_prev = NULL )
{
	obj = _obj;
	next = _next;
	prev = _prev;
}

template <typename T>
void LinkNode<T>::setNext(LinkNode<T> *_next)
{
	next = _next;
}

template <typename T>
void LinkNode<T>::setPrev(LinkNode<T> *_prev)
{
	prev = _prev;
}

template <typename T>
void LinkNode<T>::setData(const T &_obj)
{
	obj = _obj;
}

template <typename T>
LinkNode<T>* LinkNode<T>::getNext()
{
	return next;
}

template <typename T>
LinkNode<T>* LinkNode<T>::getPrev()
{
	return prev;
}

template <typename T>
T LinkNode<T>::getData()
{
	return obj;
}

template <typename T>
T LinkNode<T>::Retrive()
{
	return getData();
}
#endif
