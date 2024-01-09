/*
Project name :			_35Red_black_tree
Last modified Date:		2024��1��6��18��17��
Last Version:			V1.0
Descriptions:			�����ģ����
*/

#ifndef _35RED_BLACK_TREE_REDBLACKTREE_H
#define _35RED_BLACK_TREE_REDBLACKTREE_H

#include "RedBlackTreeNode.h"
#include "dictionary.h"
#include <stack>

void RedBlackTreeTest();

using namespace std;

template<class K, class E>
class RedBlackTree : public dictionary<K, E> {
public:
    RedBlackTree() {
        root = nullptr;
        treeSize = 0;
    }

    [[nodiscard]] bool empty() const { return treeSize == 0; }

    [[nodiscard]] int size() const { return treeSize; }

    pair<K, E> *find(K theKey) const;

    void insert(pair<K, E> &thePair);

    void erase(K theKey);

    /*���������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void inOrder(void(*theVisit)(RedBlackTreeNode<pair<K, E>> *)) {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        inOrder(root);/*������õ��Ǿ�̬��Ա����inOrder()*/
    }

    /*�������---���endl*/
    void inOrderOutput() {
        inOrder(output);
        cout << endl;
    }

    /*ǰ�������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void preOrder(void(*theVisit)(RedBlackTreeNode<pair<K, E>> *)) {
        visit = theVisit;
        int num = 0;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        preOrder(root, num);/*������õ��Ǿ�̬��Ա����preOrder()*/
        cout << "num = " << num << endl;
    }

    /*�������---���endl*/
    void preOrderOutput() {
        preOrder(output);
        cout << endl;
    }
    bool ISRBTree();

private:
    RedBlackTreeNode<pair<K, E>> *root;// ָ�����ָ��
    int treeSize;// ���Ľ�����
    static void (*visit)(RedBlackTreeNode<pair<K, E>> *);//��һ������ָ��,����ֵΪvoid ��������ΪbinaryTreeNode<pair<K, E>>*
    static void output(RedBlackTreeNode<pair<K, E>> *t) { cout << *t << endl; }

    static void inOrder(RedBlackTreeNode<pair<K, E>> *t);

    static void preOrder(RedBlackTreeNode<pair<K, E>> *t, int& num);

    void rotateLL(RedBlackTreeNode<pair<K, E>> *&x);

    void rotateLR(RedBlackTreeNode<pair<K, E>> *&x);

    void rotateRR(RedBlackTreeNode<pair<K, E>> *&x);

    void rotateRL(RedBlackTreeNode<pair<K, E>> *&x);

    void rotateRr1_2and2(RedBlackTreeNode<pair<K, E>> *&pp);

    void rotateLr1_2and2(RedBlackTreeNode<pair<K, E>> *&pp);

    bool _ISRBTree(RedBlackTreeNode<pair<K, E> > * root, int count, int BlackCount);
};

/*˽�о�̬��Ա��ʼ��*/
/*�����Ǿ�̬����ָ���Ա�ĳ�ʼ��������ʼ��������LINK����*/
template<class K, class E>
void (*RedBlackTree<K, E>::visit)(RedBlackTreeNode<pair<K, E>> *) = 0;      // visit function

/*������� �ݹ�*/
template<class K, class E>
void RedBlackTree<K, E>::inOrder(RedBlackTreeNode<pair<K, E>> *t) {
    if (t != nullptr) {
        inOrder(t->leftChild);/*�������������*/
        visit(t);/*��������*/
        inOrder(t->rightChild);/*�������������*/
    }
}

/*ǰ����� �ݹ�*/
template<class K, class E>
void RedBlackTree<K, E>::preOrder(RedBlackTreeNode<pair<K, E>> *t, int& num) {
    if (t != nullptr) {
        visit(t);/*��������*/
        num++;
        preOrder(t->leftChild, num);/*�������������*/
        preOrder(t->rightChild, num);/*�������������*/
    }
}

/*  ����Ԫ��
 *  ���룺theKey��ʾ��Ҫ����Ԫ�صļ�ֵ
 *  �������ֵΪtheKey�Ľڵ��pair��ַ
 *  ʱ�临�Ӷȣ�O(logn)��n��ʾ�ڵ����
 */
template<class K, class E>
pair<K, E> *RedBlackTree<K, E>::find(K theKey) const {
    // ����ֵ��ƥ�����Ե�ָ��
    // ���û��ƥ������ԣ�����ֵΪnullptr
    // p�Ӹ��ڵ㿪ʼ������Ѱ�ҹؼ��ֵ���theKey��һ��Ԫ��
    RedBlackTreeNode<pair<K, E> > *p = root;
    while (p != nullptr)
        // ���Ԫ�� p->element
        if (theKey < p->element.first)
            p = p->leftChild;
        else if (theKey > p->element.first)
            p = p->rightChild;
        else // �ҵ�ƥ���Ԫ��
            return &p->element;

    // û�ҵ�ƥ���Ԫ��
    return nullptr;
}

/*
 *  LL��ת
 *  ���룺x�ǵ�һ��L�ĸ��׽ڵ㣬����Ԫ�غ�ɾ��Ԫ�ض����õ�
 *  �����void
 *  ʱ�临�Ӷȣ�O(1)
 *  ע�����ִ�б�����ǰ��xָ���Ԫ�ػ�ı�Ϊ�µĸ������ĸ��ڵ�
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateLL(RedBlackTreeNode<pair<K, E>> *&x) {
    // ��¼�游�ڵ�ĸ��׽ڵ�
    RedBlackTreeNode<pair<K, E>> *Parent = x->parent;
    RedBlackTreeNode<pair<K, E>> *b = x->leftChild;
    x->leftChild = b->rightChild;
    if(b->rightChild)
        b->rightChild->parent = x;

    b->rightChild = x;
    // x�ĸ��׽ڵ��Ϊb
    x->parent = b;
    // b�ĸ��׽ڵ��Ϊԭ��x�ĸ��׽ڵ�
    b->parent = Parent;
    // �������ԭ���游�ڵ�ĸ���������Ҫ��Ϊb�ĸ��ף�ǰ�����游�ڵ�ĸ��״���
    if (Parent != nullptr) {
        if (x == Parent->leftChild)
            Parent->leftChild = b;
        else
            Parent->rightChild = b;
    } else
        root = b;// �游�ڵ����û�и��׵Ļ����Ǹ��ڵ�
    x = b;// b�ڵ㽫�滻x�ڵ�
}

/*
 *  RR��ת
 *  ���룺x��ʾ��һ��R�ĸ��׽ڵ㣬�ڲ����ɾ��ʱ�����õ�
 *  �����void
 *  ʱ�临�Ӷȣ�O(1)
 *  ע�����ִ�б�����ǰ��xָ���Ԫ�ػ�ı�Ϊ�µĸ������ĸ��ڵ�
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateRR(RedBlackTreeNode<pair<K, E>> *&x) {
    // ��¼�游�ڵ�ĸ��׽ڵ�
    RedBlackTreeNode<pair<K, E>> *Parent = x->parent;
    RedBlackTreeNode<pair<K, E>> *b = x->rightChild;
    x->rightChild = b->leftChild;
    if(b->leftChild)
        b->leftChild->parent = x;

    b->leftChild = x;
    x->parent = b;// x�ĸ��׽ڵ�Ϊb
    // b�ĸ��׽ڵ�Ϊ�游�ڵ�ĸ��׽ڵ�
    b->parent = Parent;
    // �������ԭ���游�ڵ�ĸ���������Ҫ��Ϊb�ĸ��ף�ǰ�����游�ڵ�ĸ��״���
    if (Parent != nullptr) {
        if (x == Parent->leftChild)
            Parent->leftChild = b;
        else
            Parent->rightChild = b;
    } else
        root = b;// �游�ڵ����û�и��׵Ļ����Ǹ��ڵ�
    x = b;
}

/*
 *  LR��ת
 *  ���룺x��ʾL�ĸ��׽ڵ㣬����Ԫ�غ�ɾ��Ԫ��ʱ�����õ�
 *  �����void
 *  ʱ�临�Ӷȣ�O(1)
 *  ע�����ִ�б�����ǰ��xָ���Ԫ�ػ�ı�Ϊ�µĸ������ĸ��ڵ�
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateLR(RedBlackTreeNode<pair<K, E>> *&x) {
    rotateRR(x->leftChild);
    rotateLL(x);
}

/*
 *  RL��ת
 *  ���룺x��ʾR�ĸ��׽ڵ㣬����Ԫ�غ�ɾ��Ԫ�ض����õ�
 *  �����void
 *  ʱ�临�Ӷȣ�O(1)
 *  ע�����ִ�б�����ǰ��xָ���Ԫ�ػ�ı�Ϊ�µĸ������ĸ��ڵ�
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateRL(RedBlackTreeNode<pair<K, E>> *&x) {
    rotateLL(x->rightChild);
    rotateRR(x);
}

/*
 * ɾ���ڵ�ʱ������Rr1(2)�ͺ�Rr2�͵���תʹ��
 * ���룺�滻��ɾ���ڵ��y�ڵ�ĸ��׽ڵ�
 * �����void
 * ʱ�临�Ӷȣ�O(1)
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateRr1_2and2(RedBlackTreeNode<pair<K, E>> *&pp) {
    RedBlackTreeNode<pair<K, E>> *Parent = pp->parent;
    RedBlackTreeNode<pair<K, E>> *w = pp->leftChild->rightChild;
    RedBlackTreeNode<pair<K, E>> *x = w->rightChild;
    if(x != nullptr){
        w->rightChild = x->leftChild;
        if(x->leftChild)
            x->leftChild->parent = w;// ���׽ڵ�Ҫ��ʱ����
    }
    else{
        cout << "rotateRr1_2and2 error!" << endl;
    }
    x->leftChild = pp->leftChild;
    pp->leftChild->parent = x;

    pp->leftChild = x->rightChild;
    if(x->rightChild)
        x->rightChild->parent = pp;
    x->rightChild = pp;
    pp->parent = x;
    if(Parent->leftChild == pp)
        Parent->leftChild = x;
    else
        Parent->rightChild = x;
    x->parent = Parent;
    pp = x;
}

/*
 * ɾ���ڵ�ʱ������Lr1(2)�ͺ�Lr2�͵���תʹ��
 * ���룺�滻��ɾ���ڵ��y�ڵ�ĸ��׽ڵ�
 * �����void
 * ʱ�临�Ӷȣ�O(1)
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateLr1_2and2(RedBlackTreeNode<pair<K, E>> *&pp) {
    RedBlackTreeNode<pair<K, E>> *Parent = pp->parent;
    RedBlackTreeNode<pair<K, E>> *w = pp->rightChild->leftChild;
    RedBlackTreeNode<pair<K, E>> *x = w->leftChild;
    if(x != nullptr){
        w->leftChild = x->rightChild;
        if(x->rightChild)
            x->rightChild->parent = w;// ���׽ڵ�Ҫ��ʱ����
    }
    else{
        cout << "rotateLr1_2and2 error!" << endl;
    }
    x->rightChild = pp->rightChild;
    pp->rightChild->parent = x;

    pp->rightChild = x->leftChild;
    if(x->leftChild)
        x->leftChild->parent = pp;
    x->leftChild = pp;
    pp->parent = x;
    if(Parent->leftChild == pp)
        Parent->leftChild = x;
    else
        Parent->rightChild = x;
    x->parent = Parent;
    pp = x;
}

/*
 *  ����Ԫ��
 *  ���룺const pair<K, E> thePair��ʾ��Ҫ����ļ�ֵ��
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)����ʾ�ڵ����
 */
template<class K, class E>
void RedBlackTree<K, E>::insert(pair<K, E> &thePair) {

    // �������Ϊ��ʱ������ڵ�ֱ����Ϊ���ڵ㣬������ɫΪ��ɫ
    if (root == nullptr) {
        root = new RedBlackTreeNode<pair<K, E> >(thePair, nullptr, nullptr, nullptr, false);
        treeSize++;
        return;
    }
    // ������ǿ�. ����ü�ֵ�����򸲸�Ԫ��
    // Ѱ�Ҳ���λ��
    RedBlackTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    while (p != nullptr) {// ���Ԫ�� p->element
        pp = p;
        // �����ǰ��ֵС��p�ļ�ֵ�����Ƶ�p������
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else// �����ǰ��ֵ����p�ļ�ֵ�����Ƶ�p���Һ���
        if (thePair.first > p->element.first)
            p = p->rightChild;
        else {// �����ֵ��ȣ����Ǿɵ�ֵ
            p->element.second = thePair.second;
            return;
        }
    }

    // ΪthePair����һ���ڵ㣬Ȼ����pp���ӣ���ʱpp��Ҷ�ӽڣ�Ĭ�ϲ���Ϊ��ɫ�ڵ�
    auto *newNode = new RedBlackTreeNode<pair<K, E> >(thePair);
    // ���thePair�ļ�ֵС��pp�ļ�ֵ����thePair��Ϊpp�����ӣ���֮������Ϊ�Һ���
    if (thePair.first < pp->element.first) {
        pp->leftChild = newNode;
        newNode->parent = pp;
    } else {
        pp->rightChild = newNode;
        newNode->parent = pp;
    }
    treeSize++;
    p = newNode;
    // ������׽ڵ�����Ҹ��׽ڵ��Ǻ�ɫ�ģ�����Ҫ�Ժ�������е���
    while (pp && pp->isRed == true) {
        // parent�Ǻ�ɫ�����丸�ڵ�һ������
        RedBlackTreeNode<pair<K, E> > *grandfather = pp->parent;
        if (pp == grandfather->leftChild) {// parent��grandfather������
            // LYr(Y������L��R)�����
            RedBlackTreeNode<pair<K, E> > *uncle = grandfather->rightChild;// �ҵ�grandfather���Һ��ӣ����Գ�Ϊ����
            if (uncle && uncle->isRed == true) {// ������������Ϊ��ɫ
                // �����׽ڵ��������ڵ����ɫ����Ϊ��ɫ
                pp->isRed = uncle->isRed = false;
                // ֻ�����游�ڵ㲻Ϊ���ڵ�ʱ�����游�ڵ����ɫ����Ϊ��ɫ
                if (grandfather != root)
                    grandfather->isRed = true;
                else // ����游�ڵ��Ѿ��Ǹ��ڵ��ˣ���ô��ֱ����ֹѭ������Ϊ�����������ϴ�����
                    break;
                // �������ϴ���
                p = grandfather;
                pp = p->parent;
            } else {// uncle�����ڻ���uncle������Ϊ��ɫ
                // �����ǰ�ڵ����丸�׽ڵ������
                // LLb����������ӵ�����
                if (p == pp->leftChild) {
                    rotateLL(grandfather);// LL����
                    // ������ɫ
                    // ���ڵ�grandfatherָ�����ԭ���ĸ��׽ڵ㣬grandfather���Һ���ָ�����ԭ�游�ڵ�
                    grandfather->isRed = false;
                    grandfather->rightChild->isRed = true;
                } else {// LRb�����
                    rotateLR(grandfather);
                    // ������ɫ
                    // ���ڵ�grandfatherָ�����ԭ�����½ڵ�u��u��������ԭ���ĸ��׽ڵ�pu��u���Һ�����ԭ�����游�ڵ�gu
                    grandfather->isRed = false;
                    grandfather->rightChild->isRed = true;
                }
                break;// ����������Ͻ��д���
            }
        } else {// parent��grandfather���Һ���
            // RYr(Y������L��R)�����
            RedBlackTreeNode<pair<K, E> > *uncle = grandfather->leftChild;// �ҵ�grandfather�����ӣ����Գ�Ϊ����
            if (uncle && uncle->isRed == true) {// ������������Ϊ��ɫ
                // �����׽ڵ��������ڵ����ɫ����Ϊ��ɫ
                pp->isRed = uncle->isRed = false;
                // ֻ�����游�ڵ㲻Ϊ���ڵ�ʱ�����游�ڵ����ɫ����Ϊ��ɫ
                if (grandfather != root)
                    grandfather->isRed = true;
                else // ����游�ڵ��Ѿ��Ǹ��ڵ��ˣ���ô��ֱ����ֹѭ������Ϊ�����������ϴ�����
                    break;
                // �������ϴ���
                p = grandfather;
                pp = p->parent;
            } else {// uncle�����ڻ���uncle������Ϊ��ɫ
                // �����ǰ�ڵ����丸�׽ڵ���Һ���
                // RRb��������Һ��ӵ��Һ���
                if (p == pp->rightChild) {
                    rotateRR(grandfather);// RR����
                    // ������ɫ
                    // ���ڵ�grandfatherָ�����ԭ���ĸ��׽ڵ㣬grandfather������ָ�����ԭ�游�ڵ�
                    grandfather->isRed = false;
                    grandfather->leftChild->isRed = true;
                } else {// LRb�����
                    rotateRL(grandfather);
                    // ������ɫ
                    // ���ڵ�grandfatherָ�����ԭ�����½ڵ�u��u���Һ�����ԭ���ĸ��׽ڵ�pu��u��������ԭ�����游�ڵ�gu
                    grandfather->isRed = false;
                    grandfather->leftChild->isRed = true;
                }
                break;// ����������Ͻ��д���
            }
        }

    }
}

/*
 *  ɾ��Ԫ��
 *  ���룺const K theKey��ʾ��Ҫɾ��Ԫ�صļ�ֵ
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)��n��ʾ�ڵ����
 */
template<class K, class E>
void RedBlackTree<K, E>::erase(K theKey) {
    // ɾ���ؼ��ֵ���theKey������
    // ���ҹؼ���ΪtheKey�Ľڵ�
    RedBlackTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    while (p != nullptr && p->element.first != theKey)
    {
        pp = p;
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            p = p->rightChild;
    }
    if (p == nullptr){
        cout << theKey << " not exist!" << endl;
        return; // ��������ؼ���theKeyƥ�������
    }

    // ������֯���ṹ
    // ��p����������ʱ�Ĵ���
    if (p->leftChild != nullptr && p->rightChild != nullptr)
    {
        // ��������
        // ��P����������Ѱ�����Ԫ��
        RedBlackTreeNode<pair<K, E> > *s = p->leftChild,
                *ps = p;  // s�ĸ��ڵ�
        while (s->rightChild != nullptr)
        {// �ƶ��������pair
            ps = s;
            s = s->rightChild;// �Һ��ӱȽϴ�
        }

        // �����Ԫ��s�Ƶ�p
        // p->element = s->element �ļ�ֵ�� const
        // �����ֵ����p������ʱ��new��Ԫ�ز���ֱ��ָ��p�����ӣ���Ҫָ��p�����ӵ�����(��ʱp������û���Һ���)����Ϊ��ʱ��s�ᱻdelete��,��������ں����p������һ��������������
        RedBlackTreeNode<pair<K, E> >* q = nullptr;
        // ֵ��s��ֵ�滻����ɫ������ָ���ָ����p��
        q = new RedBlackTreeNode<pair<K, E> >(s->element, p->leftChild, p->rightChild, p->parent, p->isRed);
        if(p->leftChild)
            p->leftChild->parent = q;
        if(p->rightChild)
            p->rightChild->parent = q;
        // pp��p�ĸ��ڵ�
        // ���pû�и��ڵ�
        if (pp == nullptr)
            root = q;
        else if (p == pp->leftChild)// ���p��pp������
            pp->leftChild = q;
        else// ���p��pp���Һ���
            pp->rightChild = q;
        // ���s�ĸ��ڵ����p��˵��p�ڵ��������ֻ��������û��������
        // ��ôɾ��p��pp�����丸�ڵ�
        if (ps == p) pp = q;
        else pp = ps;// ��֮ps���丸�ڵ�
        delete p;
        p = s;
    }

    // p����ֻ��һ������
    // �Ѻ��ӵ�ָ���ŵ�c
    RedBlackTreeNode<pair<K, E> > *c;
    if (p->leftChild != nullptr)
        c = p->leftChild;
    else
        c = p->rightChild;

    // ɾ��p
    bool isLeft = false;// ��¼p�ڵ������ӻ����Һ���
    if (p == root)
        root = c;
    else
    {// p��pp�����ӻ����Һ���
        if (p == pp->leftChild){
            pp->leftChild = c;
            // ����һ��c�ڵ�ĸ��׽ڵ�
            if(c != nullptr)
                c->parent = pp;
            isLeft = true;
        }
        else{
            pp->rightChild = c;
            // ����һ��c�ڵ�ĸ��׽ڵ�
            if(c != nullptr)
                c->parent = pp;
        }
    }
    treeSize--;

    // ֮ǰ���ҵ���y�ڵ�ĸ��׽ڵ�pp
    // �����ɾ���ڵ��Ǻ�ɫ�ģ�����������ƽ��ģ������ɾ���ڵ��Ǻ�ɫ�ģ���������Ҫ����
    if(p->isRed == false){
        // ���׽ڵ㲻Ϊ�գ�˵������Ҫ��������
        while(pp){
            // ���c�ڵ㲻Ϊ�գ�����Ҫ�ж�c�ڵ������ӻ����Һ���
            // �����Ҫ�����ڵڶ��ֵ���ƽ�⣬Ҳ����c�ڵ��ʱ������p�ĺ��ӽڵ�
            if(c){
                if(c == pp->leftChild)
                    isLeft = true;
                else
                    isLeft = false;
            }

            if(isLeft){
                // �ҵ���ɾ���ڵ���ֵ�
                RedBlackTreeNode<pair<K, E> > *v = pp->rightChild;
                // ����ֵܽڵ��Ǻ�ɫ�ڵ� Lb��
                // ���c��v��Ϊ�յĻ�����ô���õ���ƽ��
                if(!c && !v)
                    break;
                if(!v->isRed){
                    // ���v�����Һ��Ӷ��Ǻ�ɫ�ڵ㣬Lb2��;����v�������Ǻ�ɫ�ڵ㣬Lb1(2)��
                    if(v->leftChild && v->leftChild->isRed){
                        rotateRL(pp);// OK1
                        pp->isRed = pp->leftChild->isRed;
                        pp->leftChild->isRed = false;
                        break;
                    }
                    else if(v->rightChild && v->rightChild->isRed){// ���v�������Ǻ�ɫ�ڵ㣬Lb1(1)��
                        rotateRR(pp);// OK1
                        pp->isRed = pp->leftChild->isRed;// ����ڵ����ɫ����
                        pp->leftChild->isRed = false;// ԭ�������Ƚڵ����ɫ��Ϊ��ɫ�ڵ�
                        v->rightChild->isRed = false;// ��v�����Ӹ���Ϊ��ɫ�ڵ�
                        break;// ����Ҫ����������
                    }
                    else{// ���v�����Һ��Ӷ��Ǻ�ɫ�ڵ㣬Lb0��
                        // pp�Ǻ�ɫ�ڵ㣬�ı�ppΪ��ɫ�ڵ㣬�ı�vΪ��ɫ�ڵ�
                        if(pp->isRed){
                            pp->isRed = false;// OK1
                            v->isRed = true;
                            break;// ��ֹѭ��������Ҫ�ټ���������
                        }
                        else{// pp�Ǻ�ɫ�ڵ㣬��v�ڵ�ı�Ϊ��ɫ�ڵ㣬Ȼ��pp�ڵ���Ϊ�µ�y�ڵ㣬Ҳ���ǳ����е�p�ڵ�
                            v->isRed = true;//OK1
                            // ��������ƽ��
                            c = pp;
                            pp = c->parent;
                        }
                    }
                }
                else{// ����ֵܽڵ��Ǻ�ɫ�ڵ� Lr�ͣ����ֵܽڵ�һ�������Һ���
                    // �ҵ���ɾ���ڵ���ֵܵ�����
                    RedBlackTreeNode<pair<K, E> > *vL = v->leftChild;
                    // ���vL�����Һ��Ӷ��Ǻ�ɫ�ڵ㣬Lr2�� ���� ���v�������Ǻ�ɫ�ڵ㣬Lr1(2)��
                    if(vL && vL->leftChild && vL->leftChild->isRed){
                        rotateLr1_2and2(pp);// OK1
                        pp->isRed = false;
                        break;
                    }
                    else if(vL && vL->rightChild && vL->rightChild->isRed){// ���v���Һ����Ǻ�ɫ�ڵ㣬Lr1(1)��
                        rotateRL(pp);// OK1
                        if(vL->rightChild->leftChild)
                            vL->rightChild->leftChild->isRed = false;
                        break;
                    }
                    else{// ���v�����Һ��Ӷ��Ǻ�ɫ�ڵ㣬Lr0��
                        rotateRR(pp);// OK1
                        pp->isRed = false;// ����ԭ����v�ڵ�Ϊ��ɫ�ڵ�
                        if(pp->leftChild->rightChild)
                            pp->leftChild->rightChild->isRed = true;
                        break;
                    }
                }
            }
            else{// ������R��
                // �ҵ���ɾ���ڵ���ֵ�
                RedBlackTreeNode<pair<K, E> > *v = pp->leftChild;
                // ���c��v��Ϊ�յĻ�����ô���������ƽ���
                if((!c && !v))
                    break;
                // ����ֵܽڵ��Ǻ�ɫ�ڵ� Rb��
                if(!v->isRed){
                    // ���v�����Һ��Ӷ��Ǻ�ɫ�ڵ㣬Rb2�ͣ�����v���Һ����Ǻ�ɫ�ڵ㣬Rb1(2)��
                    if(v->rightChild && v->rightChild->isRed){
                        rotateLR(pp);// OK1
                        pp->isRed = pp->rightChild->isRed;
                        pp->rightChild->isRed = false;
                        break;
                    }
                    else if(v->leftChild && v->leftChild->isRed){// ���v�������Ǻ�ɫ�ڵ㣬Rb1(1)��
                        rotateLL(pp);// OK1
                        pp->isRed = pp->rightChild->isRed;// ����ڵ����ɫ����
                        pp->rightChild->isRed = false;// ԭ�������Ƚڵ����ɫ��Ϊ��ɫ�ڵ�
                        v->leftChild->isRed = false;// ��v�����Ӹ���Ϊ��ɫ�ڵ�
                        break;// ����Ҫ����������
                    }
                    else{// ���v�����Һ��Ӷ��Ǻ�ɫ�ڵ㣬Rb0��
                        // pp�Ǻ�ɫ�ڵ㣬�ı�ppΪ��ɫ�ڵ㣬�ı�vΪ��ɫ�ڵ�
                        if(pp->isRed){
                            pp->isRed = false;// OK1
                            v->isRed = true;
                            break;// ��ֹѭ��������Ҫ�ټ���������
                        }
                        else{// pp�Ǻ�ɫ�ڵ㣬��v�ڵ�ı�Ϊ��ɫ�ڵ㣬Ȼ��pp�ڵ���Ϊ�µ�y�ڵ㣬Ҳ���ǳ����е�p�ڵ�
                            // ���û���ҵ����ʵĽڵ�ȥ����
                            v->isRed = true;//OK1
                            c = pp;
                            pp = c->parent;
                        }
                    }
                }
                else{// ����ֵܽڵ�v�Ǻ�ɫ�ڵ� Rr�ͣ����ֵܽڵ�vһ�������Һ���
                    // �ҵ���ɾ���ڵ���ֵܵ��Һ���
                    RedBlackTreeNode<pair<K, E> > *vR = v->rightChild;
                    // ���vR�����Һ��Ӷ��Ǻ�ɫ�ڵ㣬Rr2�� ���� vR���Һ����Ǻ�ɫ�ڵ㣬Rr1(2)�� ��������������vR���Һ��Ӵ������Ǻ�ɫ�ڵ�
                    // ���ֲ�������һ����
                    if(vR && vR->rightChild && vR->rightChild->isRed){
                        rotateRr1_2and2(pp);// OK1
                        pp->isRed = false;
                        break;
                    }
                    else if(vR && vR->leftChild && vR->leftChild->isRed){// ���vR�������Ǻ�ɫ�ڵ㣬Rr1(1)��
                        rotateLR(pp);// OK1
                        if(vR->leftChild->rightChild)
                            vR->leftChild->rightChild->isRed = false;
                        break;
                    }
                    else{// ���v�����Һ��Ӷ��Ǻ�ɫ�ڵ㣬Rr0�ͣ�û�ҵ����ʵ���������
                        // ���c�ڵ���nullptr�Ļ�������������ƽ��ģ�����Ҫ������
                        // OK1
                        rotateLL(pp);
                        pp->isRed = false;// ����ԭ����v�ڵ�Ϊ��ɫ�ڵ�
                        if(pp->rightChild->leftChild)
                            pp->rightChild->leftChild->isRed = true;
                        break;
                    }
                }
            }
        }

    }
    if(root && root->isRed == true)
        root->isRed = false;
    delete p;
}

//�ж��Ƿ�Ϊ�����
template<class K, class E>
bool RedBlackTree<K, E>::ISRBTree()
{
    if (root == nullptr) //�����Ǻ����
    {
        return true;
    }
    if (root->isRed == true)
    {
        cout << "error: root is red" << endl;
        return false;
    }

    //������·����Ϊ��ɫ�����Ŀ�Ĳο�ֵ
    RedBlackTreeNode<pair<K, E> > *cur = root;
    int BlackCount = 0;
    while (cur)
    {
        if (cur->isRed == false)
            BlackCount++;
        cur = cur->leftChild;
    }

    int count = 0;
    return _ISRBTree(root, count, BlackCount);
}
//�ж��Ƿ�Ϊ��������Ӻ���
template<class K, class E>
bool RedBlackTree<K, E>::_ISRBTree(RedBlackTreeNode<pair<K, E> > * cur, int count, int BlackCount)
{
    if (cur == nullptr) //��·���Ѿ�������
    {
        if (count != BlackCount)
        {
            cout << "error: black nodes nums not equal" << endl;
            return false;
        }
        return true;
    }

    if (cur->isRed == true && cur->parent->isRed == true)
    {
        cout << "error: red and red nodes together" << endl;
        return false;
    }
    if (cur->isRed == false)
    {
        count++;
    }
    return _ISRBTree(cur->leftChild, count, BlackCount) && _ISRBTree(cur->rightChild, count, BlackCount);
}


// overload << for pair
template<class K, class E>
ostream &operator<<(ostream &out, const pair<K, E> &x) {
    out << x.first << ":" << x.second;
    return out;
}

template<class K, class E>
ostream &operator<<(ostream &out, const RedBlackTreeNode<pair<K, E>> &x) {
    out << x.element.first << ":" << x.element.second << "  isRed = " << x.isRed;
    return out;
}

#endif //_35RED_BLACK_TREE_REDBLACKTREE_H
