/*
Project name :			_25Priority_queue
Last modified Date:		2023年11月29日21点08分
Last Version:			V1.0
Descriptions:			优先级队列——大根堆抽象数据类型
*/

#ifndef _25PRIORITY_QUEUE_MAXPRIORITYQUEUE_H
#define _25PRIORITY_QUEUE_MAXPRIORITYQUEUE_H

template<class T>
class maxPriorityQueue
{
public:
    virtual ~maxPriorityQueue() = default;
    [[nodiscard]] virtual bool empty() const = 0;
    // return true iff queue is empty
    [[nodiscard]] virtual int size() const = 0;
    // return number of elements in queue
    virtual const T& top() = 0;
    // return reference to the max element
    virtual void pop() = 0;
    // remove the top element
    virtual void push(const T& theElement) = 0;
    // add theElement to the queue
};
#endif //_25PRIORITY_QUEUE_MAXPRIORITYQUEUE_H
