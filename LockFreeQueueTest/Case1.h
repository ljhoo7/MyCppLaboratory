#include <windows.h>
#include "CaseBase.h"

class Case1 : public CaseBase
{
	void Run() override;
};

// 출처: https://kksuny.tistory.com/21 [생각이 없는 프로그래밍]
template <typename T>
class QueueT
{
private:
    long _size;
    // NODE데이타를 저장할 구조체
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

    Node* _head;        // 시작노드를 포인트한다.
    Node* _tail;        // 마지막노드를 포인트한다.

public:
    QueueT();

    void Enqueue(T t);
    int Dequeue(T& t);
};

#include "Case1.cpp"