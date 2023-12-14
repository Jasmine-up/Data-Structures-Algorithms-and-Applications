/*
Project name :			_26maxHblt
Last modified Date:		2023年12月14日10点20分
Last Version:			V1.0
Descriptions:			最大高度优先左高树——模板头文件
*/

#ifndef _26MAXHBLT_MAXHBLT_H
#define _26MAXHBLT_MAXHBLT_H

#include "maxPriorityQueue.h"
#include "maxHbltTreeNode.h"
#include "myExceptions.h"
#include <queue>
#include <sstream>

void maxhbltTest();

using namespace std;

template<class T>
class maxHblt : public maxPriorityQueue<T> {
public:
    maxHblt() {
        root = nullptr;
        treeSize = 0;
    }

    bool empty() const { return treeSize == 0; }

    int size() const { return treeSize; }

    const T &top() {// 返回最大元素
        if (treeSize == 0)
            throw queueEmpty();
        return root->element;
    }

    void pop();

    void push(const T &);

    void initialize(T *, int);

    void meld(maxHblt<T> &theHblt) {// 合并 *this 和 theHblt
        meld(root, theHblt.root);
        treeSize += theHblt.treeSize;
        theHblt.root = nullptr;
        theHblt.treeSize = 0;
    }

    void erase() {// 清空树
        postOrder(dispose);
        root = nullptr;
        treeSize = 0;
    }

    void postOrderOutput() {// 后序遍历输出树的元素
        postOrder(hbltOutput);
        cout << endl;
    }

    void postOrder(void(*theVisit)(maxHbltTreeNode<T> *)) {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        postOrder(root);/*这里调用的是静态成员函数inOrder()*/
    }

private:
    maxHbltTreeNode<T> *root;//指向根的指针
    int treeSize;//树的结点个数
    void meld(maxHbltTreeNode<T> *&,
              maxHbltTreeNode<T> *&);// 合并两颗树

    static void (*visit)(maxHbltTreeNode<T> *);//是一个函数指针,返回值为void 函数参数为maxHbltTreeNode<T>*
    static void dispose(maxHbltTreeNode<T> *t) { delete t; }

    static void postOrder(maxHbltTreeNode<T> *t);

    static void hbltOutput(maxHbltTreeNode<T> *t) { cout << t->element << ' '; }
};

template<class T>
void (*maxHblt<T>::visit)(maxHbltTreeNode<T> *) = 0;      // visit function

template<class T>
void maxHblt<T>::meld(maxHbltTreeNode<T> *&x,
                      maxHbltTreeNode<T> *&y) {// 合并两棵最大高度优先左高树
    // x是合并后的树
    if (y == nullptr)   // y是空树，直接返回
        return;
    if (x == nullptr)   // x是空树，将y赋值给x，返回
    {
        x = y;
        return;
    }
    // x树永远是提供根的树
    // x和y都不是空树，如果x的元素小于y的元素，则交换x树和y树
    if (x->element < y->element)
        swap(x, y);

    // 现在 x->element.second >= y->element.second
    // 合并x的右子树和y树,x的根和左子树作为合并树的根和左子树
    meld(x->rightChild, y);// 得到的x的右子树就是x的右子树与y树合并的最大高度优先左高树

    // 如果需要，交换x的左子树和右子树的值
    if (x->leftChild == nullptr) {// 如果x的左子树为空, 则将x的左子树和右子树做交换，保证x的左子树比右子树高
        x->leftChild = x->rightChild;
        x->rightChild = nullptr;
        x->height = 1;
    } else {// 如果x的左子树的weight小于右子树的weight，则要交换左右子树的值
        if (x->leftChild->height < x->rightChild->height)
            swap(x->leftChild, x->rightChild);
        x->height = x->rightChild->height + 1;// 存储小的那一个
    }
}

template<class T>
void maxHblt<T>::push(const T &theElement) {// 向树中插入元素
    // 创建一个新的节点
    maxHbltTreeNode<T> *q = new maxHbltTreeNode<T>(theElement, 1);

    // 将新节点与root树合并
    meld(root, q);
    treeSize++;
}

template<class T>
void maxHblt<T>::pop() {// 删除最大元素
    if (root == nullptr)
        throw queueEmpty();

    // 当树不为空时
    maxHbltTreeNode<T> *left = root->leftChild,
            *right = root->rightChild;
    delete root;
    root = left;
    meld(root, right);
    treeSize--;
}

template<class T>
void maxHblt<T>::initialize(T *theElements, int theSize) {// 初始化hblt 使用theElements[1:theSize].
    queue<maxHbltTreeNode<T> *> q;
    erase();  // 清空左高树

    for (int i = 1; i <= theSize; i++)
        // 创建节点，全部放入队列中
        q.push(new maxHbltTreeNode<T>(theElements[i]));

    // 不断取出两个节点进行合并
    for (int i = 1; i <= theSize - 1; i++) {
        maxHbltTreeNode<T> *b = q.front();
        q.pop();
        maxHbltTreeNode<T> *c = q.front();
        q.pop();
        meld(b, c);
        // 合并生成的树放到队列中
        q.push(b);
    }

    if (theSize > 0)
        root = q.front();
    treeSize = theSize;
}

/*后序遍历 递归*/
template<class T>
void maxHblt<T>::postOrder(maxHbltTreeNode<T> *t) {
    if (t != nullptr) {
        postOrder(t->leftChild);/*后序遍历左子树*/
        postOrder(t->rightChild);/*后序遍历右子树*/
        visit(t);/*访问树根*/
    }
}

#endif //_26MAXHBLT_MAXHBLT_H
