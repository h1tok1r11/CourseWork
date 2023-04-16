#pragma once

template <typename T>
class Node
{
public:
	T data;
	Node* pnext;

	Node(T data) :
		data(data), pnext(nullptr) {}
};