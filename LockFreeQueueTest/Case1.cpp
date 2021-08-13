template<typename T>
QueueT::QueueT()
{
    _size = 0;
    _head = new Node;
    _head->next = NULL;
    _tail = _head;
}

template<typename T>
void QueueT::Enqueue(T t)
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

int Dequeue(T& t)
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