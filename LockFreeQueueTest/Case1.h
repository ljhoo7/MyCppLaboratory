#include <windows.h>
#include "CaseBase.h"

class Case1 : public CaseBase
{
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
    QueueT();

    void Enqueue(T t);
    int Dequeue(T& t);
};

#include "Case1.cpp"