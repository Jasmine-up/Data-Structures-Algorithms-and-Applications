/*
Project name :			_33Search_tree
Last modified Date:		2023��12��21��11��13��
Last Version:			V1.0
Descriptions:			��������������������������ģ����
*/

#ifndef _33SEARCH_TREE_INDEXEDBINARYSEARCHTREE_H
#define _33SEARCH_TREE_INDEXEDBINARYSEARCHTREE_H

#include "indexedBSTree.h"
#include "indexedBinarySearchTreeNode.h"

using namespace std;

void indexedBinarySearchTreeTest();

template<class K, class E>
class indexedBinarySearchTree : public indexedBSTree<K, E> {
public:
    indexedBinarySearchTree() {
        root = nullptr;
        treeSize = 0;
    }

    // �ֵ���صķ���
    [[nodiscard]] bool empty() const { return treeSize == 0; }

    [[nodiscard]] int size() const { return treeSize; }

    pair<K, E> *find(const K theKey) const;

    // index��0��ʼ
    [[nodiscard]] pair<K, E>* get(int index) const;

    void insert(const pair<K, E> thePair);

    void erase(const K theKey);

    /*���������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void inOrder(void(*theVisit)(indexedBinarySearchTreeNode<pair<K, E>> *)) {
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
    void preOrder(void(*theVisit)(indexedBinarySearchTreeNode<pair<K, E>> *))
    {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        preOrder(root);/*������õ��ǳ�Ա������preOrder()*/
    }
    /*ǰ�����---���endl*/
    void preOrderOutput() { preOrder(output); cout << endl; }

    // additional method of bsTree
    void ascend() { inOrderOutput(); }

private:
    indexedBinarySearchTreeNode<pair<K, E>> *root;//ָ�����ָ��
    int treeSize;//���Ľ�����
    static void (*visit)(indexedBinarySearchTreeNode<pair<K, E>> *);//��һ������ָ��,����ֵΪvoid ��������ΪindexedBinarySearchTreeNode<pair<K, E>>
    static void output(indexedBinarySearchTreeNode<pair<K, E>> *t) { cout << *t << " "; }

    static void inOrder(indexedBinarySearchTreeNode<pair<K, E>> *t);
    static void preOrder(indexedBinarySearchTreeNode<pair<K, E>> *t);
};

/*˽�о�̬��Ա��ʼ��*/
/*�����Ǿ�̬����ָ���Ա�ĳ�ʼ��������ʼ��������LINK����*/
template<class K, class E>
void
(*indexedBinarySearchTree<K, E>::visit)(indexedBinarySearchTreeNode<pair<K, E>> *) = 0;      // visit function

/*������� �ݹ�*/
template<class K, class E>
void indexedBinarySearchTree<K, E>::inOrder(indexedBinarySearchTreeNode<pair<K, E>> *t) {
    if (t != nullptr) {
        inOrder(t->leftChild);/*�������������*/
        visit(t);/*��������*/
        inOrder(t->rightChild);/*�������������*/
    }
}
/*����������ͨ��Ա����*/
/*ǰ����� �ݹ�*/
template<class K, class E>
void indexedBinarySearchTree<K, E>::preOrder(indexedBinarySearchTreeNode<pair<K, E>> *t)
{
    if (t != nullptr)
    {
        visit(t);/*��������*/
        preOrder(t->leftChild);/*ǰ�����������*/
        preOrder(t->rightChild);/*ǰ�����������*/
    }
}

/*  ���ݼ�ֵ����Ԫ��
 *  ���룺theKey��ʾ��Ҫ����Ԫ�صļ�ֵ
 *  �������ֵΪtheKey�Ľڵ��pair��ַ
 *  ʱ�临�Ӷȣ�O(logn)��n��ʾ�ڵ����
 */
template<class K, class E>
pair<K, E> *indexedBinarySearchTree<K, E>::find(K theKey) const {
    // ����ֵ��ƥ�����Ե�ָ��
    // ���û��ƥ������ԣ�����ֵΪnullptr
    // p�Ӹ��ڵ㿪ʼ������Ѱ�ҹؼ��ֵ���theKey��һ��Ԫ��
    indexedBinarySearchTreeNode<pair<K, E> > *p = root;
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
 *  ������������Ԫ��
 *  ���룺int index��ʾ���ҽڵ������
 *  ���������Ϊindex�Ľڵ��pair��ַ
 */
template<class K, class E>
pair<K, E>* indexedBinarySearchTree<K, E>::get(int index) const {
    indexedBinarySearchTreeNode<pair<K, E> >* cur = root;
    while(cur != nullptr && cur->leftSize != index){
        // ��ǰ�ڵ����������index���ƶ�������
        if(cur->leftSize > index)
            cur = cur->leftChild;
        else{// ��ǰ�ڵ������С��index���ƶ����Һ���
            index = index - (cur->leftSize + 1);
            cur = cur->rightChild;
        }
    }
    if(cur == nullptr)
        return nullptr;
    else
        return &(cur->element);
}

/*
 *  ����Ԫ��
 *  ���룺const pair<K, E> thePair��ʾ��Ҫ����ļ�ֵ��
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)����ʾ�ڵ����
 */
template<class K, class E>
void indexedBinarySearchTree<K, E>::insert(const pair<K, E> thePair) {
    // ����thePair. ����ü�ֵ�����򸲸�Ԫ��
    // Ѱ�Ҳ���λ��
    indexedBinarySearchTreeNode<pair<K, E> > *p = root,
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

    // ΪthePair����һ���ڵ㣬Ȼ����pp���ӣ���ʱpp��Ҷ�ӽڵ�
    auto *newNode = new indexedBinarySearchTreeNode<pair<K, E> >(thePair);
    if (root != nullptr) // ���ǿ�
        // ���thePair�ļ�ֵС��pp�ļ�ֵ����thePair��Ϊpp�����ӣ���֮������Ϊ�Һ���
        if (thePair.first < pp->element.first) {
            pp->leftChild = newNode;// pp������ָ������Ԫ�أ����pp������Ҫ����Ϊ1
        } else
            pp->rightChild = newNode;
    else// ����
        root = newNode; // ֱ�ӽ�thePair�ڵ���Ϊ���ڵ�
    treeSize++;

    // �޸�������ֵ����ʱ�ռ����Ԫ�ص�leftSize��Ҫ����
    p = root;
    while (p != nullptr) {// ���Ԫ�� p->element
        pp = p;
        // �����ǰ��ֵС��p�ļ�ֵ�����Ƶ�p������
        if (thePair.first < p->element.first){
            pp->leftSize++;
            p = p->leftChild;
        }
        else // �����ǰ��ֵС�ڵ���p�ļ�ֵ�����Ƶ�p���Һ���
            p = p->rightChild;
    }
}

/*
 *  ɾ��Ԫ��
 *  ���룺const K theKey��ʾ��Ҫɾ��Ԫ�صļ�ֵ
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)��n��ʾ�ڵ����
 */
template<class K, class E>
void indexedBinarySearchTree<K, E>::erase(const K theKey) {
    // ɾ���ؼ��ֵ���theKey������
    // ���ҹؼ���ΪtheKey�Ľڵ�
    indexedBinarySearchTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    bool flag = false; // ������¼�Ƿ���Ҫ������֯����
    while (p != nullptr && p->element.first != theKey) {
        pp = p;
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            p = p->rightChild;
    }
    if (p == nullptr)
        return; // ��������ؼ���theKeyƥ�������

    // ���ɾ���ڵ���Ǹ��ڵ㣬�������ڵ����������ı�
    if(p != root)
        flag = true;

    // bigger�洢��p�����С�ļ�ֵ����������ɾ��Ԫ�غ������ĸ���
    K bigger = p->element.first;
    if(pp != nullptr){
        if(p == pp->leftChild){
            if(p->rightChild == nullptr)
                bigger = pp->element.first;
            else
                bigger = p->rightChild->element.first;
        }
        else if(p->rightChild != nullptr)
            bigger = p->rightChild->element.first;
        else
            bigger = p->element.first;// ��ʱ��¼Ϊp�ļ�ֵ��Ŀ���ǲ�����p���Һ��ӵ�����
    }
    cout << "bigger = " << bigger << endl;

    // ������֯���ṹ
    // ��p����������ʱ�Ĵ���
    if (p->leftChild != nullptr && p->rightChild != nullptr) {
        // ��������
        // ��P����������Ѱ�����Ԫ��
        indexedBinarySearchTreeNode<pair<K, E> > *s = p->leftChild,
                *ps = p;  // s�ĸ��ڵ�
        while (s->rightChild != nullptr) {// �ƶ��������pair
            ps = s;
            s = s->rightChild;// �Һ��ӱȽϴ�
        }

        // �����Ԫ��s�Ƶ�p
        // p->element = s->element �ļ�ֵ�� const
        // �����ֵ����p������ʱ��new��Ԫ�ز���ֱ��ָ��p�����ӣ���Ҫָ��p�����ӵ�����(��ʱp������û���Һ���)����Ϊ��ʱ��s�ᱻdelete��,��������ں����p������һ��������������
        indexedBinarySearchTreeNode<pair<K, E> > *q = nullptr;
        q = new indexedBinarySearchTreeNode<pair<K, E> >(s->element, s->leftSize, p->leftChild, p->rightChild);
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
    indexedBinarySearchTreeNode<pair<K, E> > *c;
    if (p->leftChild != nullptr)
        c = p->leftChild;
    else
        c = p->rightChild;

    // ɾ��p
    if (p == root)
        root = c;
    else {// p��pp�����ӻ����Һ���
        if (p == pp->leftChild)
            pp->leftChild = c;
        else pp->rightChild = c;
    }
    treeSize--;
    delete p;

    // �޸�������ֵ��ֻ�б�ɾ����ֵ���Ǹ��ڵ�ʱ������Ҫ�������
    // ��ʱ��ֵΪbigger��Ԫ�ز���Ҫ�޸�����������С��bigger��Ԫ����Ҫ
    if(flag){
        indexedBinarySearchTreeNode<pair<K, E> > *temp = root;
        while (temp != nullptr) {
            pp = temp;
            cout << *temp << endl;
            // �����ǰ��ֵС��temp�ļ�ֵ�����Ƶ�temp������
            if (bigger < temp->element.first){
                pp->leftSize--;
                temp = temp->leftChild;
            }
            else // �����ǰ��ֵС�ڵ���p�ļ�ֵ�����Ƶ�p���Һ���
            if(bigger > temp->element.first)
                temp = temp->rightChild;
            else //��ǰ��ֵ����p��ֵ������ֹ
                break;
        }
    }

}

#endif //_33SEARCH_TREE_INDEXEDBINARYSEARCHTREE_H
