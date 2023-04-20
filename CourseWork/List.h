#pragma once
#include "Node.h"

template <typename T>
class List
{
private:
	int Size;
	Node<T>* pHead;
public:
	List();
	~List();

	void push_back(T data);
	int getSize() { return Size }
	T& operator[](const int idx);
};

template <typename T>
inline List<T>::List()
{
	Size = 0;
	pHead = nullptr;
}
 
template<typename T>
inline List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* pNew = new Node<T>(data);
	if (pHead == nullptr)
		pHead = pNew;
	else {
		Node<T>* pCur = this->pHead;
		while (pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = pNew;
	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int idx)
{
	Node<T>* pCur = this->pHead;
	int cnt = 0;
	while (pCur != nullptr)
	{
		if (cnt == idx)
			return pCur->data;
		pCur = pCur->pNext;
		cnt++;
	}
}