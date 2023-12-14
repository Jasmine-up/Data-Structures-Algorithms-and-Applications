/*
Project name :			_26maxHblt
Last modified Date:		2023年12月14日10点20分
Last Version:			V1.0
Descriptions:			优先级队列——虚基类
*/

#ifndef _26MAXHBLT_MAXPRIORITYQUEUE_H
#define _26MAXHBLT_MAXPRIORITYQUEUE_H
using namespace std;

template<class T>
class maxPriorityQueue
{
public:
    virtual ~maxPriorityQueue() {}
    virtual bool empty() const = 0;
    // return true iff queue is empty
    virtual int size() const = 0;
    // return number of elements in queue
    virtual const T& top() = 0;
    // return reference to the max element
    virtual void pop() = 0;
    // remove the top element
    virtual void push(const T& theElement) = 0;
    // add theElement to the queue
};
#endif //_26MAXHBLT_MAXPRIORITYQUEUE_H
