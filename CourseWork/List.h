#pragma once
#include "Node.h"

template <typename T>
class List
{
private:
	int Size;
	Node<T>* pHead, *pTail;
public:
	List();
	~List();

	void push_back(T data);
	int getSize() { return Size }
	T& operator[](const int idx);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int idx);
	void removeAt(int idx);
	void pop_back();
};

template <typename T>
inline List<T>::List()
{
	std::cout << "Вызвался конструктор" << endl;
	Size = 0;
	pHead = pTail = nullptr;
}
 
template<typename T>
inline List<T>::~List()
{
	std::cout << "Вызвался деструктор" << endl;
	clear();
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

template<typename T>
void List<T>::pop_front()
{
	Node* pTemp = pHead;
	pHead = pHead->pNext;
	delete pTemp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	pHead = new Node<T>(data, pHead);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int idx)
{
	if (idx == 0)
		push_front(T data);
	else
	{
		Node<T>* pLeft = this->pHead;
		for (int i = 0; i < idx - 1, i++)
		{
			pLeft = pLeft->pNext;
		}
		pLeft->pNext = new Node(data, pLeft->pNext);
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int idx)
{
	if (idx == 0)
		pop_front();
	else
	{
		Node<T>* pLeft = this->pHead;
		for (int i = 0; i < idx - 1, i++)
		{
			pLeft = pLeft->pNext;
		}
		Node<T>* ptoDelete = pLeft->pNext;
		pLeft->pNext = ptoDelete->pNext;
		delete ptoDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}
