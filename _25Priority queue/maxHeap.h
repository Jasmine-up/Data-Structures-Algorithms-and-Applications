/*
Project name :			_25Priority_queue
Last modified Date:		2023年11月29日21点08分
Last Version:			V1.0
Descriptions:			优先级队列——大根堆模板头文件
*/
/*[[nodiscard]]标记符可以用于提示程序员在调用有返回值的函数时不要忘记接收改函数的返回值*/

#ifndef _25PRIORITY_QUEUE_MAXHEAP_H
#define _25PRIORITY_QUEUE_MAXHEAP_H
#include "maxPriorityQueue.h"
#include "_1myExceptions.h"
#include "_2myFunctions.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <memory>

using namespace std;
int maxHeapTest();
template<class T>
class maxHeap : public maxPriorityQueue<T>
{
public:
    explicit maxHeap(int initialCapacity = 10);
    ~maxHeap() {heap = nullptr;}
    [[nodiscard]] bool empty() const {return heapSize == 0;}
    [[nodiscard]] int size() const {return heapSize;}
    const T& top()
    {// 返回最大元素，也就是堆顶的值
        if (heapSize == 0)
            throw queueEmpty();
        return heap[1];
    }
    void pop();// 向堆中弹出元素
    void push(const T&);// 向堆中插入元素
    void initialize(T *, int);// 初始化堆
    void deactivateArray()// 禁用数组，这个还没搞清楚怎么用
    {heap = nullptr; arrayLength = heapSize = 0;}
    void output(ostream& out) const;// 输出大根堆的所有元素
private:
    int heapSize;       // 存储大根堆中有多少元素
    int arrayLength;    // 存储大根堆的容量大小
    T* heap;            // 存储大根堆元素的数组
};

template<class T>
maxHeap<T>::maxHeap(int initialCapacity)
{// 构造函数，容量必须>=1
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity + 1;
    heap = new T(arrayLength);
    heapSize = 0;
}

// 向大顶堆中插入元素
template<class T>
void maxHeap<T>::push(const T& theElement)
{
    // 如果容量不够的话需要增加容量
    if (heapSize == arrayLength - 1)
    {
        changeLength1D(heap, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    // 从叶子节点开始起泡，将元素插入
    int currentNode = ++heapSize;
    // 如果编号i不是根节点，则其父节点的编号为[i/2](向下取整)
    while (currentNode != 1 && heap[currentNode / 2] < theElement)
    {
        // 父节点小于子节点，不能将元素放到此处
        heap[currentNode] = heap[currentNode / 2]; // 将父节点放到currentNode出
        currentNode /= 2;                          // 当前节点的index转移到父节点
    }
    // 直到父节点大于等于theElement，将theElement放到当前位置
    heap[currentNode] = theElement;
}

// 删除大顶堆的最大元素
// 在大根堆是二叉树时可以这样弄
template<class T>
void maxHeap<T>::pop()
{
    // 如果大顶堆元素个数为0，那么抛出queueEmpty异常
    if (heapSize == 0)
        throw queueEmpty();

    // 删除数组中第一个元素，也就是根节点的元素
    heap[1].~T();

    // 找到大顶堆的最后一排的最后一个元素
    T lastElement = heap[heapSize--];
    // 当前节点与其孩子节点的index
    int currentNode = 1,
            child = 2;
    while (child <= heapSize)
    {
        // 找到孩子节点中的较大者
        if (child < heapSize && heap[child] < heap[child + 1]) // 这里只考虑了两个孩子，因此大根堆是二叉树
            child++;
        // 如果lastElement大于等于孩子节点的较大者，就终止循环，说明找到了lastElement可以放置的位置
        if (lastElement >= heap[child])
            break;

        // 如果没找到放置lastElement的位置，就在currentNode放置孩子节点中的较大者
        heap[currentNode] = heap[child];
        currentNode = child;// 现在空位就变成了刚刚移动的孩子节点
        child *= 2;// 其孩子的index就是2倍的child
    }
    heap[currentNode] = lastElement;// 如果找到位置了就直接将最后一个元素放置到找到的位置上
}

template<class T>
void maxHeap<T>::initialize(T *theHeap, int theSize)
{
    delete [] heap;// 数组已经指定了
    heap = theHeap;
    heapSize = theSize;
    // 从最后一个有孩子节点的节点开始
    for (int root = heapSize / 2; root >= 1; root--)
    {
        T rootElement = heap[root];

        int child = 2 * root; // 当前节点的左孩子节点
        while (child <= heapSize)
        {
            // 找到孩子节点中的较大者
            if (child < heapSize && heap[child] < heap[child + 1])
                child++;

            // 如果rootElement大于等于孩子节点的较大者，那么就终止循环
            if (rootElement >= heap[child])
                break;

            // 如果rootElement小于孩子节点的较大者，就在父亲节点放置孩子节点
            heap[child / 2] = heap[child];
            child *= 2;// 找到较大孩子节点的孩子节点
        }
        // 如果孩子节点的较大者小于rootElement，就将rootElement作为孩子节点的父亲
        heap[child / 2] = rootElement;
    }
}

template<class T>
void maxHeap<T>::output(ostream& out) const
{// 输出大顶堆中的所有元素
    for(T* i = heap + 1; i < heap + heapSize + 1; i++)
        cout << *i << " ";
    cout << endl;
}

// 重载输出操作符 <<
template <class T>
ostream& operator<<(ostream& out, const maxHeap<T>& x)
{x.output(out); return out;}

#endif //_25PRIORITY_QUEUE_MAXHEAP_H
