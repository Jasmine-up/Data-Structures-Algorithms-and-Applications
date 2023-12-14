/*
Project name :			_26maxHblt
Last modified Date:		2023��12��14��10��20��
Last Version:			V1.0
Descriptions:			���߶��������������ģ��ͷ�ļ�
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

    const T &top() {// �������Ԫ��
        if (treeSize == 0)
            throw queueEmpty();
        return root->element;
    }

    void pop();

    void push(const T &);

    void initialize(T *, int);

    void meld(maxHblt<T> &theHblt) {// �ϲ� *this �� theHblt
        meld(root, theHblt.root);
        treeSize += theHblt.treeSize;
        theHblt.root = nullptr;
        theHblt.treeSize = 0;
    }

    void erase() {// �����
        postOrder(dispose);
        root = nullptr;
        treeSize = 0;
    }

    void postOrderOutput() {// ��������������Ԫ��
        postOrder(hbltOutput);
        cout << endl;
    }

    void postOrder(void(*theVisit)(maxHbltTreeNode<T> *)) {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        postOrder(root);/*������õ��Ǿ�̬��Ա����inOrder()*/
    }

private:
    maxHbltTreeNode<T> *root;//ָ�����ָ��
    int treeSize;//���Ľ�����
    void meld(maxHbltTreeNode<T> *&,
              maxHbltTreeNode<T> *&);// �ϲ�������

    static void (*visit)(maxHbltTreeNode<T> *);//��һ������ָ��,����ֵΪvoid ��������ΪmaxHbltTreeNode<T>*
    static void dispose(maxHbltTreeNode<T> *t) { delete t; }

    static void postOrder(maxHbltTreeNode<T> *t);

    static void hbltOutput(maxHbltTreeNode<T> *t) { cout << t->element << ' '; }
};

template<class T>
void (*maxHblt<T>::visit)(maxHbltTreeNode<T> *) = 0;      // visit function

template<class T>
void maxHblt<T>::meld(maxHbltTreeNode<T> *&x,
                      maxHbltTreeNode<T> *&y) {// �ϲ��������߶����������
    // x�Ǻϲ������
    if (y == nullptr)   // y�ǿ�����ֱ�ӷ���
        return;
    if (x == nullptr)   // x�ǿ�������y��ֵ��x������
    {
        x = y;
        return;
    }
    // x����Զ���ṩ������
    // x��y�����ǿ��������x��Ԫ��С��y��Ԫ�أ��򽻻�x����y��
    if (x->element < y->element)
        swap(x, y);

    // ���� x->element.second >= y->element.second
    // �ϲ�x����������y��,x�ĸ�����������Ϊ�ϲ����ĸ���������
    meld(x->rightChild, y);// �õ���x������������x����������y���ϲ������߶����������

    // �����Ҫ������x������������������ֵ
    if (x->leftChild == nullptr) {// ���x��������Ϊ��, ��x��������������������������֤x������������������
        x->leftChild = x->rightChild;
        x->rightChild = nullptr;
        x->height = 1;
    } else {// ���x����������weightС����������weight����Ҫ��������������ֵ
        if (x->leftChild->height < x->rightChild->height)
            swap(x->leftChild, x->rightChild);
        x->height = x->rightChild->height + 1;// �洢С����һ��
    }
}

template<class T>
void maxHblt<T>::push(const T &theElement) {// �����в���Ԫ��
    // ����һ���µĽڵ�
    maxHbltTreeNode<T> *q = new maxHbltTreeNode<T>(theElement, 1);

    // ���½ڵ���root���ϲ�
    meld(root, q);
    treeSize++;
}

template<class T>
void maxHblt<T>::pop() {// ɾ�����Ԫ��
    if (root == nullptr)
        throw queueEmpty();

    // ������Ϊ��ʱ
    maxHbltTreeNode<T> *left = root->leftChild,
            *right = root->rightChild;
    delete root;
    root = left;
    meld(root, right);
    treeSize--;
}

template<class T>
void maxHblt<T>::initialize(T *theElements, int theSize) {// ��ʼ��hblt ʹ��theElements[1:theSize].
    queue<maxHbltTreeNode<T> *> q;
    erase();  // ��������

    for (int i = 1; i <= theSize; i++)
        // �����ڵ㣬ȫ�����������
        q.push(new maxHbltTreeNode<T>(theElements[i]));

    // ����ȡ�������ڵ���кϲ�
    for (int i = 1; i <= theSize - 1; i++) {
        maxHbltTreeNode<T> *b = q.front();
        q.pop();
        maxHbltTreeNode<T> *c = q.front();
        q.pop();
        meld(b, c);
        // �ϲ����ɵ����ŵ�������
        q.push(b);
    }

    if (theSize > 0)
        root = q.front();
    treeSize = theSize;
}

/*������� �ݹ�*/
template<class T>
void maxHblt<T>::postOrder(maxHbltTreeNode<T> *t) {
    if (t != nullptr) {
        postOrder(t->leftChild);/*�������������*/
        postOrder(t->rightChild);/*�������������*/
        visit(t);/*��������*/
    }
}

#endif //_26MAXHBLT_MAXHBLT_H
