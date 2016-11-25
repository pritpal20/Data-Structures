#ifndef _LINK_LIST_
#define _LINK_LIST_
#include "link_node.h"

template <typename T>
class LinkList
{
	private :
		LinkNode<T>* head ;
		LinkNode<T>* tail;
		unsigned int  length;
		
	public :
	
	class iterator
	{
		public :
		iterator(): current(NULL)
		{}
		
		iterator(LinkNode<T>* aNode):current(aNode)
		{}
		
		iterator operator++(void);
		iterator operator++(int);
		iterator operator--(void);
		iterator operator--(int);
		bool operator==(const iterator &rhs);
		bool operator!=(const iterator &rhs);
		T operator*();

		private :
		
		LinkNode<T>* current;
		
		friend class LinkList<T>;
	};

	LinkList(); 	//constructor 
	LinkList(const LinkList<T> &theList);	//copy constructor
	
	void PushBack(const T &element);
	void PushFront(const T &element);
	
	LinkNode<T>* getTail(void);
	LinkNode<T>* getHead(void);
	
	LinkNode<T>* Front(void) const;
	LinkNode<T>* Back(void) const;
	
	void SetHead(LinkNode<T>*);
	void SetTail(LinkNode<T>*);
	
	LinkNode<T>* GetHead() const;
	LinkNode<T>* GetTail() const;
	unsigned int GetLength() const;

	void PopFront(void);
	void  PopBack(void);

	void InsertAfter(LinkNode<T>* anode,const T &aObject);
	void InsertBefore(LinkNode<T>* prevNode,const T &aObject);
	
	void RemoveNode(LinkNode<T>* aNode);	
	void Print();
	void ListPrint();
	void PrintReverse();
	T Print(int pos);
	LinkNode<T>* operator[](int pos);
	bool IsEmpty();
	void Remove(int pos);
	
	iterator begin(void);
	iterator end(void);
};

template <typename T>
T LinkList<T>::iterator::operator*()
{
	if(current)
		return current->getData();
	//else
	//	return T it = T();

}

//Pre increment 
template <typename T>
typename LinkList<T>::iterator LinkList<T>::iterator::operator++(void)
{
	current = current->getNext();
	return *this;
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::iterator::operator++(int)
{
	iterator tmp = *this; 
        operator++();
        return tmp;
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::iterator::operator--(void)
{
        current = current->getPrev();
        return *this;
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::iterator::operator--(int)
{
        iterator tmp = *this;
        operator--();
        return tmp;
}

template <typename T>
bool LinkList<T>::iterator::operator==(const LinkList<T>::iterator &rhs)
{
	return current == rhs.current;
}

template <typename T>
bool LinkList<T>::iterator::operator!=(const LinkList<T>::iterator &rhs)
{
        return current != rhs.current;
}

template <typename T>
LinkList<T>::LinkList()
{
	head = new LinkNode<T>;
	tail = new LinkNode<T>;
	head->setNext(tail);
	tail->setPrev(head);
	length = 0;
	
}

template <typename T>
LinkNode<T> *LinkList<T>::GetHead(void) const
{
        return head;
}

template <typename T>
LinkNode<T> *LinkList<T>::GetTail(void) const
{
        return tail;
}

template <typename T>
unsigned int LinkList<T>::GetLength(void) const
{
        return length;
}

template <typename T>
void LinkList<T>::SetHead(LinkNode<T> *aNode)
{
        head = aNode;
}

template <typename T>
void LinkList<T>::SetTail(LinkNode<T> *aNode)
{
        tail = aNode;
}

template <typename T>
LinkNode<T> *LinkList<T>::Front(void) const
{
	return (head->getNext());

}

template <typename T>
LinkNode<T> *LinkList<T>::Back(void) const
{
	return (tail->getPrev());

}

template <typename T>
void LinkList<T>::InsertAfter(LinkNode<T>* prevNode,const T &aObject)
{
	LinkNode<T>* nextNode = prevNode->getNext();
	LinkNode<T>* newNode = new LinkNode<T>(aObject);

	newNode->setPrev(prevNode);
	newNode->setNext(nextNode);

	prevNode->setNext(newNode);
	nextNode->setPrev(newNode);	
	length++;
}

template <typename T>
void LinkList<T>::InsertBefore(LinkNode<T>* nextNode,const T &aObject)
{
	LinkNode<T>* newNode = new LinkNode<T>(aObject);
	LinkNode<T>* prevNode = nextNode->getPrev();

	newNode->setPrev(prevNode);
	newNode->setNext(nextNode);

	prevNode->setNext(newNode);
	nextNode->setPrev(newNode);
	length++;
}

template <typename T>
void LinkList<T>::PushFront(const T &aObject)
{
	InsertBefore(Front(),aObject);
}

template <typename T>
void LinkList<T>::PushBack(const T &aObject)
{
	InsertAfter(Back(),aObject);

}

template <typename T>
void LinkList<T>::RemoveNode(LinkNode<T>* aNode)
{
        LinkNode<T>* aPrevNode = aNode->getPrev();
        LinkNode<T>* aNextNode = aNode->getNext();

        if(aPrevNode)
        {
                aPrevNode->setNext(aNextNode);
        }
        else
        {
                head = aNextNode;
        }

        if(aNextNode)
        {
                aNextNode->setPrev(aPrevNode);
        }
        else
        {
                tail = aPrevNode;
        }

        delete aNode;
        aNode = NULL;
	length--;
}

template <typename T>
void LinkList<T>::Print()
{
	LinkList<T>::iterator it = begin();
	int i = 0;
	while(it != end())
	{
		cout << *it << "->" ;
		it++;
		i++;
	}
	cout << "NULL"<< endl ;
}

template <typename T>
void LinkList<T>::ListPrint()
{
        LinkList<T>::iterator it = begin();
        int i = 0;
        while(it != end())
        {
                cout << "List[" << i << "]=" << *it << endl ;
                it++;
                i++;
        }
        cout << endl ;
}


template <typename T>
void LinkList<T>::PrintReverse()
{
	LinkList<T>::iterator it = end();
	it--;
	do
	{
		cout << *it << " " ;
		it--;
	}
	while( it != begin());
	cout << endl ; 
}

template <typename T>
void LinkList<T>::PopFront()
{
	RemoveNode(Front());
}

template <typename T>
void LinkList<T>::PopBack()
{
        RemoveNode(Back());
}

template <typename T>
bool LinkList<T>::IsEmpty(void)
{
        return (length == 0);
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::begin()
{
	return iterator(Front());
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::end()
{
        return iterator(tail);
}

template <typename T>
T LinkList<T>::Print(int pos)
{
	int count = 0 ;
	if(pos > length )	
		return T(-1);
	LinkNode<T>* aNode = head->getNext();
	while(count < pos )
	{
		aNode = aNode->getNext();
		count++;
	}
	
	return aNode->getData();

}

template <typename T>
LinkNode<T>* LinkList<T>::operator[](int pos)
{
	 int count = 0 ;
        if(pos > length )
                return NULL;
        LinkNode<T>* aNode = head->getNext();
        while(count < pos )
        {
                aNode = aNode->getNext();
                count++;
        }
        return aNode;
}

template <typename T>
void LinkList<T>::Remove(int pos)
{
	LinkList<T>::iterator it = begin();
	while(pos--)
		it++;
	RemoveNode(it.current);
}

#endif 
