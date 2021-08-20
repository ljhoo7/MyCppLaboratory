#include "Case1.h"

QueueT<int> g_queue;

Case1::Case1()
{
	m_caseName = typeid(*this).name();
}

void Case1::EnqueueWrap(int value)
{
	g_queue.Enqueue(value);
}

void Case1::DequeueWrap(int& outValue)
{
	g_queue.Dequeue(outValue);
}