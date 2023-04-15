#pragma once
#include "Subject.h"

//template <typename T>

class Node
{
public:
	Subject subject;
	Node* pnext;

	Node(Subject subject) :
		subject(subject), pnext(nullptr) {}
};