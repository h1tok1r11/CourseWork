#include "Node.h"

template <typename T>
class OneLinkedList
{
public:
	Node* phead, *ptail;
public:
	OneLinkedList(): phead(nullptr), ptail(nullptr) {};
	~OneLinkedList() {
		while (phead != nullptr)
			popFront();
	};

	void popFront() {
		if (phead == nullptr)
			return;
		if (phead == ptail) {
			delete ptail;
			phead = ptail = nullptr;
			return;
		}
		Node* pcur = phead;
		phead = pcur->pnext;
		delete pcur;
	}

	void pushBack(Subject subject) {
		Node* pnew = new Node(subject);
		if (phead == nullptr)
			phead = pnew;
		if (ptail != nullptr) {
			ptail->pnext = pnew;
			ptail = pnew;
		}
	}

	void pushFront(Subject subject) {
		Node* pnew = new Node(subject);
		pnew->pnext = phead;
		phead = pnew;
		if (ptail == nullptr)
			ptail = pnew;
	}

	void popBack() {
		if (ptail == nullptr)
			return;
		if (phead = ptail) {
			delete ptail;
			phead = ptail = nullptr;
			return;
		}
		Node* pcur = phead;
		for (; pcur->pnext != ptail; pcur = pcur->pnext);
		pcur->pnext = nullptr;
		delete ptail;
		ptail = pcur;

	}

	Node* getAt(int idx) {
		if (idx < 0)
			return nullptr;
		Node* pcur = phead;
		int cnt = 0;
		while (pcur && pcur->pnext && cnt != idx) {
			pcur = pcur->pnext;
			cnt++;
		}
		return (cnt == idx) ? pcur : nullptr;
	}

	void insert(int idx, Subject subject) {
		Node* pleft = getAt(idx);
		if (pleft == nullptr)
			return;
		Node* pright = pleft->pnext;
		Node* pcur = new Node(subject);
		pcur->pnext = pright;
		pleft->pnext = pcur;
		if (pright == nullptr)
			ptail = pcur;
	}

	void erase(int idx) {
		if (idx < 0)
			return;
		if (idx == 0) {
			popFront();
			return;
		}
		Node* pleft = getAt(idx - 1);
		Node* pcur = pleft->pnext;
		if (pcur == nullptr)
			return;
		Node* pright = pcur->pnext;
		pleft->pnext = pright;
		if (pcur == ptail)
			ptail = pleft;
		delete pcur;
	}
};