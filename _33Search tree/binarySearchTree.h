/*
Project name :			_33Search_tree
Last modified Date:		2023��12��21��11��13��
Last Version:			V1.0
Descriptions:			��������������ģ����ʵ��
*/

#ifndef _33SEARCH_TREE_BINARYSEARCHTREE_H
#define _33SEARCH_TREE_BINARYSEARCHTREE_H
#include "bsTree.h"
#include "binaryTreeNode.h"
using namespace std;

void binarySearchTreeTest();

/*������������Ӧ��*/
/*ֱ��ͼ*/
void SimpleHistogramSolution();
void binarySearchTreeHistogramSolution();
/*�ֲ�����*/
void SimpleCrossDistribution();

template<class K, class E>
class binarySearchTree : public bsTree<K,E>
{
public:
    binarySearchTree(){
        root = nullptr;
        treeSize = 0;
    }
    // �ֵ���صķ���
    bool empty() const {return treeSize == 0;}
    int size() const {return treeSize;}
    pair<K, E>* find(const K theKey) const;
    void insert(const pair<K, E> thePair);
    void insert(const pair<K, E>&, void(*fun)(E& u));// ����Ϊ�����ֱ��ͼ������Ŭ��
    void erase(const K theKey);
    /*���������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void inOrder(void(*theVisit)(binaryTreeNode<pair<K, E>>*))
    {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        inOrder(root);/*������õ��Ǿ�̬��Ա����inOrder()*/
    }
    /*�������---���endl*/
    void inOrderOutput() { inOrder(output); cout << endl; }

    // additional method of bsTree
    void ascend() {inOrderOutput();}
private:
    binaryTreeNode<pair<K, E>>* root;//ָ�����ָ��
    int treeSize;//���Ľ�����
    static void (*visit)(binaryTreeNode<pair<K, E>>*);//��һ������ָ��,����ֵΪvoid ��������ΪbinaryTreeNode<pair<K, E>>*
    static void output(binaryTreeNode<pair<K, E>>* t) { cout << t->element << " "; }
    static void inOrder(binaryTreeNode<pair<K, E>>* t);
};

/*˽�о�̬��Ա��ʼ��*/
/*�����Ǿ�̬����ָ���Ա�ĳ�ʼ��������ʼ��������LINK����*/
template<class K, class E>
void (*binarySearchTree<K,E>::visit)(binaryTreeNode<pair<K, E>>*) = 0;      // visit function

/*������� �ݹ�*/
template<class K, class E>
void binarySearchTree<K,E>::inOrder(binaryTreeNode<pair<K, E>>* t)
{
    if (t != nullptr)
    {
        inOrder(t->leftChild);/*�������������*/
        visit(t);/*��������*/
        inOrder(t->rightChild);/*�������������*/
    }
}

/*  ����Ԫ��
 *  ���룺theKey��ʾ��Ҫ����Ԫ�صļ�ֵ
 *  �������ֵΪtheKey�Ľڵ��pair��ַ
 *  ʱ�临�Ӷȣ�O(logn)��n��ʾ�ڵ����
 */
template<class K, class E>
pair<K, E>* binarySearchTree<K,E>::find(K theKey) const
{
    // ����ֵ��ƥ�����Ե�ָ��
    // ���û��ƥ������ԣ�����ֵΪnullptr
    // p�Ӹ��ڵ㿪ʼ������Ѱ�ҹؼ��ֵ���theKey��һ��Ԫ��
    binaryTreeNode<pair<K, E> > *p = root;
    while (p != nullptr)
        // ���Ԫ�� p->element
        if (theKey < p->element.first)
            p = p->leftChild;
        else
        if (theKey > p->element.first)
            p = p->rightChild;
        else // �ҵ�ƥ���Ԫ��
            return &p->element;

    // û�ҵ�ƥ���Ԫ��
    return nullptr;
}
/*
 *  ����Ԫ��
 *  ���룺const pair<K, E> thePair��ʾ��Ҫ����ļ�ֵ��
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)����ʾ�ڵ����
 */
template<class K, class E>
void binarySearchTree<K,E>::insert(const pair<K, E> thePair)
{
    // ����thePair. ����ü�ֵ�����򸲸�Ԫ��
    // Ѱ�Ҳ���λ��
    binaryTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    while (p != nullptr)
    {// ���Ԫ�� p->element
        pp = p;
        // �����ǰ��ֵС��p�ļ�ֵ�����Ƶ�p������
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else// �����ǰ��ֵ����p�ļ�ֵ�����Ƶ�p���Һ���
        if (thePair.first > p->element.first)
            p = p->rightChild;
        else
        {// �����ֵ��ȣ����Ǿɵ�ֵ
            p->element.second = thePair.second;
            return;
        }
    }

    // ΪthePair����һ���ڵ㣬Ȼ����pp���ӣ���ʱpp��Ҷ�ӽڵ�
    auto *newNode = new binaryTreeNode<pair<K, E> > (thePair);
    if (root != nullptr) // ���ǿ�
        // ���thePair�ļ�ֵС��pp�ļ�ֵ����thePair��Ϊpp�����ӣ���֮������Ϊ�Һ���
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else// ����
        root = newNode; // ֱ�ӽ�thePair�ڵ���Ϊ���ڵ�
    treeSize++;
}
/*
 *  ����Ԫ��
 *  ���룺const pair<K, E> thePair��ʾ��Ҫ����ļ�ֵ��
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)����ʾ�ڵ����
 *  Ŀ�ģ�Ϊ��Ӧ����ֱ��ͼ���������Ŭ��
 */
template<class K, class E>
void binarySearchTree<K,E>::insert(const pair<K, E>& thePair, void(*fun)(E& u))
{
    // ����thePair. ����ü�ֵ�����򸲸�Ԫ��
    // Ѱ�Ҳ���λ��
    binaryTreeNode<pair<K, E> > *p = root,
    *pp = 0;   // p�ĸ��׽ڵ�
    while (p != nullptr)
    {
        pp = p;
        // �Ƶ�p�ĺ��ӽڵ�
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else
        if (thePair.first > p->element.first)
            p = p->rightChild;
        else
        {// �������Ԫ��
            fun(p->element.second);
            return;
        }
    }

    // ΪthePair����һ���ڵ㣬Ȼ����pp���ӣ���ʱpp��Ҷ�ӽڵ�
    auto *newNode = new binaryTreeNode<pair<K, E> > (thePair);
    if (root != nullptr) // ���ǿ���
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else
        root = newNode; // �ǿ���
    treeSize++;
}

/*
 *  ɾ��Ԫ��
 *  ���룺const K theKey��ʾ��Ҫɾ��Ԫ�صļ�ֵ
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)��n��ʾ�ڵ����
 */
template<class K, class E>
void binarySearchTree<K,E>::erase(const K theKey)
{
    // ɾ���ؼ��ֵ���theKey������
    // ���ҹؼ���ΪtheKey�Ľڵ�
    binaryTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    while (p != nullptr && p->element.first != theKey)
    {
        pp = p;
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            p = p->rightChild;
    }
    if (p == nullptr)
        return; // ��������ؼ���theKeyƥ�������

    // ������֯���ṹ
    // ��p����������ʱ�Ĵ���
    if (p->leftChild != nullptr && p->rightChild != nullptr)
    {
        // ��������
        // ��P����������Ѱ�����Ԫ��
        binaryTreeNode<pair<K, E> > *s = p->leftChild,
                *ps = p;  // s�ĸ��ڵ�
        while (s->rightChild != nullptr)
        {// �ƶ��������pair
            ps = s;
            s = s->rightChild;// �Һ��ӱȽϴ�
        }

        // �����Ԫ��s�Ƶ�p
        // p->element = s->element �ļ�ֵ�� const
        // �����ֵ����p������ʱ��new��Ԫ�ز���ֱ��ָ��p�����ӣ���Ҫָ��p�����ӵ�����(��ʱp������û���Һ���)����Ϊ��ʱ��s�ᱻdelete��,��������ں����p������һ��������������
        binaryTreeNode<pair<K, E> >* q = nullptr;
        q = new binaryTreeNode<pair<K, E> >(s->element, p->leftChild, p->rightChild);
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
    binaryTreeNode<pair<K, E> > *c;
    if (p->leftChild != nullptr)
        c = p->leftChild;
    else
        c = p->rightChild;

    // ɾ��p
    if (p == root)
        root = c;
    else
    {// p��pp�����ӻ����Һ���
        if (p == pp->leftChild)
            pp->leftChild = c;
        else pp->rightChild = c;
    }
    treeSize--;
    delete p;
}

// overload << for pair
template <class K, class E>
ostream& operator<<(ostream& out, const pair<K, E>& x)
{out << x.first << ":" << x.second; return out;}
#endif //_33SEARCH_TREE_BINARYSEARCHTREE_H