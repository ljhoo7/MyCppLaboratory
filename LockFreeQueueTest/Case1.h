///////////////////////////////////////////////////////////////
//
// 락프리 큐 1
//
// 출처: https://kksuny.tistory.com/21 [생각이 없는 프로그래밍]
//
///////////////////////////////////////////////////////////////

// Debug에서는 잘되나, Release에서 access violation 발생.

#pragma once

#include <windows.h>
#include <typeinfo>
#include <iostream>
#include <thread>

#include "CaseBase.h"

template<typename T>
class QueueT;

extern QueueT<int> g_queue;

class Case1 : public CaseBase
{
public:
	Case1();

	void EnqueueWrap(int) override;
	void DequeueWrap(int&) override;
};

template <typename T>
class QueueT
{
private:
    long _size;
    // NODE데이타를 저장할 구조체
    struct Node
    {
        T data;
        Node* next = nullptr;

        Node& operator=(const Node& ot)
        {
            data = ot.data;
            next = ot.next;
            return *this;
        }

        bool operator==(const Node& ot)
        {
            return (data == ot.data && next == ot.next);
        }
    };

    Node* _head = nullptr;
    Node* _tail = nullptr;

public:
	QueueT()
	{
		_size = 0;
		_head = new Node();
		_head->next = NULL;
		_tail = _head;
	}

    void Enqueue(T t);
    int Dequeue(T& t);
};


template<typename T>
void QueueT<T>::Enqueue(T t)
{
	Node* node = new Node();
	node->data = t;
	node->next = NULL;

	while (true)
	{
		Node* tail = _tail;
		Node* next = tail->next;

		if (tail == _tail)
		{
			if (next == NULL)
			{
				if (InterlockedCompareExchangePointer((PVOID*)&tail->next, node, next) == next)
				{
					InterlockedCompareExchangePointer((PVOID*)&_tail, node, tail);
					break;
				}
			}
			else
			{
				InterlockedCompareExchangePointer((PVOID*)&_tail, next, tail);
			}

		}
	}

	InterlockedExchangeAdd(&_size, 1);
}

template<typename T>
int QueueT<T>::Dequeue(T& t)
{
	if (_size == 0)
		return -1;

	while (true)
	{
		Node* head = _head;
		Node* tail = _tail;
		Node* next = head->next;
		if (head == _head)
		{
			if (head == tail)
			{
				if (next == NULL)
					return -1;
			}
			else
			{
				t = next->data;
				if (InterlockedCompareExchangePointer((PVOID*)&_head, next, head) == head)
				{
					delete head;
					break;
				}
			}
		}
	}
	InterlockedExchangeAdd(&_size, -1);
	return 0;
}