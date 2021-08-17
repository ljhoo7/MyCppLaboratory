#include <windows.h>
#include <typeinfo>
#include <iostream>
#include "CaseBase.h"

class Case1 : public CaseBase
{
public:
	Case1();

	void Run() override;
};

// ��ó: https://kksuny.tistory.com/21 [������ ���� ���α׷���]
template <typename T>
class QueueT
{
private:
    long _size;
    // NODE����Ÿ�� ������ ����ü
    struct Node
    {
        T data;
        Node* next;

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

    Node* _head;        // ���۳�带 ����Ʈ�Ѵ�.
    Node* _tail;        // ��������带 ����Ʈ�Ѵ�.

public:
	QueueT()
	{
		_size = 0;
		_head = new Node;
		_head->next = NULL;
		_tail = _head;
	}

    void Enqueue(T t);
    int Dequeue(T& t);
};


template<typename T>
void QueueT<T>::Enqueue(T t)
{
	Node* node = new Node;
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