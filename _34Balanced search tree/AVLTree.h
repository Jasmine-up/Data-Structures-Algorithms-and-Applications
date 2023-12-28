/*
Project name :			_34Balanced_search_tree
Last modified Date:		2023��12��27��10��57��
Last Version:			V1.0
Descriptions:			AVL��ģ����
*/

#ifndef _34BALANCED_SEARCH_TREE_AVLTREE_H
#define _34BALANCED_SEARCH_TREE_AVLTREE_H
#include "AVLTreeNode.h"
#include "dictionary.h"
#include <stack>
using namespace std;

void AVLTreeTest();

template<class K, class E>
class AVLTree : public dictionary<K,E>{
public:
    AVLTree(){
        root = nullptr;
        treeSize = 0;
    }
    [[nodiscard]] bool empty() const {return treeSize == 0;}
    [[nodiscard]] int size() const {return treeSize;}
    pair<K, E>* find(K theKey) const;
    void insert(pair<K, E>& thePair) {
        insert(thePair, root);
    }
    void erase(K theKey);

    /*���������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void inOrder(void(*theVisit)(AVLTreeNode<pair<K, E>>*))
    {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        inOrder(root);/*������õ��Ǿ�̬��Ա����inOrder()*/
    }
    /*�������---���endl*/
    void inOrderOutput() { inOrder(output); cout << endl; }

    /*ǰ�������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void preOrder(void(*theVisit)(AVLTreeNode<pair<K, E>>*))
    {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        preOrder(root);/*������õ��Ǿ�̬��Ա����preOrder()*/
    }
    /*�������---���endl*/
    void preOrderOutput() { preOrder(output); cout << endl; }

private:
    AVLTreeNode<pair<K, E>>* root;// ָ�����ָ��
    int treeSize;// ���Ľ�����
    static void (*visit)(AVLTreeNode<pair<K, E>>*);//��һ������ָ��,����ֵΪvoid ��������ΪbinaryTreeNode<pair<K, E>>*
    static void output(AVLTreeNode<pair<K, E>>* t) { cout << *t << endl; }
    static void inOrder(AVLTreeNode<pair<K, E>>* t);
    static void preOrder(AVLTreeNode<pair<K, E>>* t);
    void rotateLL(AVLTreeNode<pair<K, E>>*& x);
    void rotateLR(AVLTreeNode<pair<K, E>>*& x);
    void rotateRR(AVLTreeNode<pair<K, E>>*& x);
    void rotateRL(AVLTreeNode<pair<K, E>>*& x);
    void insert(pair<K, E>& thePair, AVLTreeNode<pair<K, E>>*& cur);
};

/*˽�о�̬��Ա��ʼ��*/
/*�����Ǿ�̬����ָ���Ա�ĳ�ʼ��������ʼ��������LINK����*/
template<class K, class E>
void (*AVLTree<K,E>::visit)(AVLTreeNode<pair<K, E>>*) = 0;      // visit function

/*������� �ݹ�*/
template<class K, class E>
void AVLTree<K,E>::inOrder(AVLTreeNode<pair<K, E>>* t)
{
    if (t != nullptr)
    {
        inOrder(t->leftChild);/*�������������*/
        visit(t);/*��������*/
        inOrder(t->rightChild);/*�������������*/
    }
}

/*ǰ����� �ݹ�*/
template<class K, class E>
void AVLTree<K,E>::preOrder(AVLTreeNode<pair<K, E>>* t)
{
    if (t != nullptr)
    {
        visit(t);/*��������*/
        preOrder(t->leftChild);/*�������������*/
        preOrder(t->rightChild);/*�������������*/
    }
}

/*  ����Ԫ��
 *  ���룺theKey��ʾ��Ҫ����Ԫ�صļ�ֵ
 *  �������ֵΪtheKey�Ľڵ��pair��ַ
 *  ʱ�临�Ӷȣ�O(logn)��n��ʾ�ڵ����
 */
template<class K, class E>
pair<K, E>* AVLTree<K,E>::find(K theKey) const
{
    // ����ֵ��ƥ�����Ե�ָ��
    // ���û��ƥ������ԣ�����ֵΪnullptr
    // p�Ӹ��ڵ㿪ʼ������Ѱ�ҹؼ��ֵ���theKey��һ��Ԫ��
    AVLTreeNode<pair<K, E> > *p = root;
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
 *  LL��ת����x�����ӵ����Ӳ���Ԫ�ص�ʱ��ʹ��
 *  ���룺AVLTreeNode<pair<K, E>>* x��x��ʾ�Ӹ��ڵ������ƶ�Ѱ�Ҳ�����Ԫ�ص�λ��ʱ�����һ������-1��1ƽ�����ӵĽڵ㡣
 *  �����void
 *  ʱ�临�Ӷȣ�O(1)
 */
template<class K, class E>
void AVLTree<K,E>::rotateLL(AVLTreeNode<pair<K, E>>*& x){
    AVLTreeNode<pair<K, E>>* b = x->leftChild;
    x->leftChild = b->rightChild;
    b->rightChild = x;

    // ����x�ĸ߶�
    if(x->leftChild != nullptr && x->rightChild != nullptr)
        x->height = max(x->leftChild->height, x->rightChild->height) + 1;
    else if(x->leftChild != nullptr)
        x->height = x->leftChild->height + 1;
    else if(x->rightChild != nullptr)
        x->height = x->rightChild->height + 1;
    else
        x->height = 1;
    // ����b�ĸ߶�
    if(b->leftChild != nullptr && b->rightChild != nullptr)
        b->height = max(b->leftChild->height, b->rightChild->height) + 1;
    else if(b->leftChild != nullptr)
        b->height = b->leftChild->height + 1;
    else if(x->rightChild != nullptr)
        b->height = b->rightChild->height + 1;
    else
        b->height = 1;
    x = b;
}
/*
 *  RR��ת����x���Һ��ӵ��Һ��Ӳ���Ԫ�ص�ʱ��ʹ��
 *  ���룺AVLTreeNode<pair<K, E>>* x��x��ʾ�Ӹ��ڵ������ƶ�Ѱ�Ҳ�����Ԫ�ص�λ��ʱ�����һ������-1��1ƽ�����ӵĽڵ㡣
 *  �����void
 *  ʱ�临�Ӷȣ�O(1)
 */
template<class K, class E>
void AVLTree<K,E>::rotateRR(AVLTreeNode<pair<K, E>>*& x){
    AVLTreeNode<pair<K, E>>* b = x->rightChild;
    x->rightChild = b->leftChild;
    b->leftChild = x;

    // ����x�ĸ߶�
    if(x->leftChild != nullptr && x->rightChild != nullptr)
        x->height = max(x->leftChild->height, x->rightChild->height) + 1;
    else if(x->leftChild != nullptr)
        x->height = x->leftChild->height + 1;
    else if(x->rightChild != nullptr)
        x->height = x->rightChild->height + 1;
    else
        x->height = 1;

    // ����b�ĸ߶�
    if(b->leftChild != nullptr && b->rightChild != nullptr)
        b->height = max(b->leftChild->height, b->rightChild->height) + 1;
    else if(b->leftChild != nullptr)
        b->height = b->leftChild->height + 1;
    else if(x->rightChild != nullptr)
        b->height = b->rightChild->height + 1;
    else
        b->height = 1;
    x = b;
}
/*
 *  LR��ת:��x�����ӵ��Һ��Ӳ���Ԫ�ص�ʱ��ʹ��
 *  ���룺AVLTreeNode<pair<K, E>>* x��x��ʾ�Ӹ��ڵ������ƶ�Ѱ�Ҳ�����Ԫ�ص�λ��ʱ�����һ������-1��1ƽ�����ӵĽڵ㡣
 *  �����void
 *  ʱ�临�Ӷȣ�O(1)
 */
template<class K, class E>
void AVLTree<K,E>::rotateLR(AVLTreeNode<pair<K, E>>*& x){
    rotateRR(x->leftChild);
    rotateLL(x);
}

/*
 *  RL��ת����x���Һ��ӵ����Ӳ���Ԫ�ص�ʱ��ʹ��
 *  ���룺AVLTreeNode<pair<K, E>>* x��x��ʾ�Ӹ��ڵ������ƶ�Ѱ�Ҳ�����Ԫ�ص�λ��ʱ�����һ������-1��1ƽ�����ӵĽڵ㡣
 *  �����void
 *  ʱ�临�Ӷȣ�O(1)
 */
template<class K, class E>
void AVLTree<K,E>::rotateRL(AVLTreeNode<pair<K, E>>*& x){
    rotateLL(x->rightChild);
    rotateRR(x);
}

/*
 *  ����Ԫ��
 *  ���룺const pair<K, E> thePair��ʾ��Ҫ����ļ�ֵ��
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)����ʾ�ڵ����
 */
template<class K, class E>
void AVLTree<K,E>::insert(pair<K, E>& thePair, AVLTreeNode<pair<K, E>>*& cur)
{
    if(cur == nullptr)
    {
        cur = new AVLTreeNode<pair<K, E> > (thePair, nullptr, nullptr);
        treeSize++;
    }

    else if(thePair.first < cur->element.first){
        insert(thePair, cur->leftChild);

        // ����bf�����bf�Ƿ� == 2���������Ҫ����ƽ��
        int bf = 0;
        if(cur->leftChild != nullptr && cur->rightChild != nullptr)
            bf = cur->leftChild->height - cur->rightChild->height;
        else if(cur->leftChild != nullptr)
            bf = cur->leftChild->height;
        else if(cur->rightChild != nullptr)
            bf = 0 - cur->rightChild->height;
        else
            bf = 0;

        if(bf == 2){
            if(thePair.first < cur->leftChild->element.first)// �������
                rotateLL(cur);// ����ת
            else // ���Ҳ���
            {
                if(cur->leftChild->rightChild == nullptr)
                    rotateLL(cur);// ����ǰ�ڵ�����ӵ��Һ���Ϊ��ʱ���Ҳ���ʾ��ͼ���滻��C�ڵ�
                else
                    rotateLR(cur);
            }
        }
    }
    else if(thePair.first > cur->element.first){
        insert(thePair, cur->rightChild);

        // ����bf�����bf�Ƿ����-2���������Ҫ����ƽ��
        int bf = 0;
        if(cur->leftChild != nullptr && cur->rightChild != nullptr)
            bf = cur->leftChild->height - cur->rightChild->height;
        else if(cur->leftChild != nullptr)
            bf = cur->leftChild->height;
        else if(cur->rightChild != nullptr)
            bf = 0 - cur->rightChild->height;
        else
            bf = 0;

        if(bf == -2){
            if(thePair.first > cur->rightChild->element.first) // ���Ҳ���
                rotateRR(cur);// ����ת
            else // �������
            {
                if(cur->rightChild->leftChild == nullptr)
                    rotateRR(cur);// ����ǰ�ڵ�����ӵ��Һ���Ϊ��ʱ���Ҳ���ʾ��ͼ���滻��C�ڵ�
                else
                    rotateRL(cur);
            }
        }
    }
    else// �����ֵ�Ѿ����ڵĻ����͸���Ԫ��
        cur->element.second = thePair.second;

    // ����cur�ڵ�ĸ߶�
    if(cur->leftChild != nullptr && cur->rightChild != nullptr)
        cur->height = max(cur->leftChild->height, cur->rightChild->height) + 1;
    else if(cur->leftChild != nullptr)
        cur->height = cur->leftChild->height + 1;
    else if(cur->rightChild !=nullptr)
        cur->height = cur->rightChild->height + 1;
    else
        cur->height = 1;
}
/*
 *  ɾ��Ԫ��
 *  ���룺const K theKey��ʾ��Ҫɾ��Ԫ�صļ�ֵ
 *  �����void
 *  ʱ�临�Ӷȣ�O(logn)��n��ʾ�ڵ����
 */
template<class K, class E>
void AVLTree<K,E>::erase(K theKey)
{
    // ɾ���ؼ��ֵ���theKey������
    // ���ҹؼ���ΪtheKey�Ľڵ�

    // ǰ���ɾ���ڵ�Ĳ����������������һ�£�����Ҫ��¼һ��·��st
    AVLTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    stack<AVLTreeNode<pair<K, E> > *> st;// ��¼�켣
    while (p != nullptr && p->element.first != theKey)
    {
        pp = p;
        st.push(pp);// ��¼�켣
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
        AVLTreeNode<pair<K, E> > *s = p->leftChild,
                *ps = p;  // s�ĸ��ڵ�
        while (s->rightChild != nullptr)
        {// �ƶ��������pair
            ps = s;
            st.push(ps);// ��¼�켣
            s = s->rightChild;// �Һ��ӱȽϴ�
        }

        // �����Ԫ��s�Ƶ�p
        // p->element = s->element �ļ�ֵ�� const
        // �����ֵ����p������ʱ��new��Ԫ�ز���ֱ��ָ��p�����ӣ���Ҫָ��p�����ӵ�����(��ʱp������û���Һ���)����Ϊ��ʱ��s�ᱻdelete��,��������ں����p������һ��������������
        AVLTreeNode<pair<K, E> >* q = nullptr;
        q = new AVLTreeNode<pair<K, E> >(s->element, p->leftChild, p->rightChild, p->height);
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
    AVLTreeNode<pair<K, E> > *c;
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

    // ����ƽ��
    int bf = 0;
    bool isRoot = false;// �����ǰ�ڵ��Ǹ��ڵ㣬��������֮����Ҫ����rootָ��Ľڵ�
    while(!st.empty()){
        p = st.top();
        st.pop();
        // ����p�ڵ�ĸ߶Ⱥ���bfֵ
        if(p->leftChild != nullptr && p->rightChild != nullptr)
        {
            p->height = max(p->leftChild->height, p->rightChild->height) + 1;
            bf = p->leftChild->height - p->rightChild->height;
        }
        else if(p->leftChild != nullptr){
            p->height = p->leftChild->height + 1;
            bf = p->leftChild->height;
        }
        else if(p->rightChild != nullptr){
            p->height = p->rightChild->height + 1;
            bf = 0 - p->rightChild->height;
        }
        else{
            p->height = 1;// ֻ�����Լ�
            bf = 0;
        }
        if(bf == 2)  //  ˵����ɾ���ڵ��ڵ�ǰ�ڵ������������R�Ͳ�ƽ��
        {
            // ���㵱ǰ�ڵ����ӵ�bfֵ
            int bfL = 0;
            // p������һ������
            if(p->leftChild->leftChild != nullptr && p->leftChild->rightChild != nullptr)
                bfL = p->leftChild->leftChild->height - p->leftChild->rightChild->height;
            else if(p->leftChild->leftChild != nullptr)
                bfL = p->leftChild->leftChild->height;
            else if(p->leftChild->rightChild != nullptr)
                bfL = 0 - p->leftChild->rightChild->height;
            else
                bfL = 0;
            // R0��
            if(bfL == 0){
                if(p == root)
                    isRoot = true;
                rotateLL(p);
                if(isRoot)
                    root = p;
                break;// ���ü���丸�ڵ���
            }
            else if(bfL == 1)// R1��
            {
                if(p == root)
                    isRoot = true;
                rotateLL(p);// ��Ҫ��������丸�ڵ�
                if(isRoot)
                    root = p;
            }
            else if(bfL == -1)// R-1��
            {
                if(p == root)
                    isRoot = true;
                if(p->leftChild->rightChild == nullptr)
                    rotateLL(p);// ����ǰ�ڵ�����ӵ��Һ���Ϊ��ʱ���Ҳ���ʾ��ͼ���滻��C�ڵ�
                else
                    rotateLR(p);//��Ҫ��������丸�ڵ�
                if(isRoot)
                    root = p;
            }
            else{}// �����������ϲ����ڱ��ʲô�����
        }
        else if(bf == -2) //  ˵����ɾ���ڵ��ڵ�ǰ�ڵ������������L�Ͳ�ƽ��
        {
            // ���㵱ǰ�ڵ����ӵ�bfֵ
            int bfR = 0;
            // p���Һ���һ������
            if(p->rightChild->leftChild != nullptr && p->rightChild->rightChild != nullptr)
                bfR = p->rightChild->leftChild->height - p->rightChild->rightChild->height;
            else if(p->rightChild->leftChild != nullptr)
                bfR = p->rightChild->leftChild->height;
            else if(p->rightChild->rightChild != nullptr)
                bfR = 0 - p->rightChild->rightChild->height;
            else
                bfR = 0;
            // L0��
            if(bfR == 0){
                if(p == root)
                    isRoot = true;
                rotateRR(p);//��Ҫ��������丸�ڵ�
                if(isRoot)
                    root = p;
                break;// ���ü���丸�ڵ���
            }
            else if(bfR == 1)// L1��
            {
                if(p == root)
                    isRoot = true;
                rotateRR(p);//��Ҫ��������丸�ڵ�
                if(isRoot)
                    root = p;
            }
            else if(bfR == -1)// L-1��
            {
                if(p == root)
                    isRoot = true;
                if(p->rightChild->leftChild == nullptr)
                    rotateRR(p); // ����ǰ�ڵ���Һ��ӵ�����Ϊ��ʱ���Ҳ���ʾ��ͼ���滻��C�ڵ�
                else
                    rotateRL(p);//��Ҫ��������丸�ڵ�
                if(isRoot)
                    root = p;
            }
            else{}// �����������ϲ����ڱ��ʲô�����
        }
        else{}// ����������
    }
}
// overload << for pair
template <class K, class E>
ostream& operator<<(ostream& out, const pair<K, E>& x)
{out << x.first << ":" << x.second; return out;}

template <class K, class E>
ostream& operator<<(ostream& out, const AVLTreeNode<pair<K, E>>& x)
{out << x.element.first << ":" << x.element.second << "  h = " << x.height; return out;}
#endif //_34BALANCED_SEARCH_TREE_AVLTREE_H
