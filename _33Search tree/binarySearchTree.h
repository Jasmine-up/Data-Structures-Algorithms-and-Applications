/*
Project name :			_33Search_tree
Last modified Date:		2023年12月21日11点13分
Last Version:			V1.0
Descriptions:			二叉搜索树——模板类实现
*/

#ifndef _33SEARCH_TREE_BINARYSEARCHTREE_H
#define _33SEARCH_TREE_BINARYSEARCHTREE_H
#include "bsTree.h"
#include "binaryTreeNode.h"
using namespace std;

void binarySearchTreeTest();

/*二叉搜索树的应用*/
/*直方图*/
void SimpleHistogramSolution();
void binarySearchTreeHistogramSolution();
/*分布交叉*/
void SimpleCrossDistribution();

template<class K, class E>
class binarySearchTree : public bsTree<K,E>
{
public:
    binarySearchTree(){
        root = nullptr;
        treeSize = 0;
    }
    // 字典相关的方法
    bool empty() const {return treeSize == 0;}
    int size() const {return treeSize;}
    pair<K, E>* find(const K theKey) const;
    void insert(const pair<K, E> thePair);
    void insert(const pair<K, E>&, void(*fun)(E& u));// 这是为了求解直方图所作的努力
    void erase(const K theKey);
    /*中序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void inOrder(void(*theVisit)(binaryTreeNode<pair<K, E>>*))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        inOrder(root);/*这里调用的是静态成员函数inOrder()*/
    }
    /*中序遍历---输出endl*/
    void inOrderOutput() { inOrder(output); cout << endl; }

    // additional method of bsTree
    void ascend() {inOrderOutput();}
private:
    binaryTreeNode<pair<K, E>>* root;//指向根的指针
    int treeSize;//树的结点个数
    static void (*visit)(binaryTreeNode<pair<K, E>>*);//是一个函数指针,返回值为void 函数参数为binaryTreeNode<pair<K, E>>*
    static void output(binaryTreeNode<pair<K, E>>* t) { cout << t->element << " "; }
    static void inOrder(binaryTreeNode<pair<K, E>>* t);
};

/*私有静态成员初始化*/
/*这里是静态函数指针成员的初始化，不初始化会引发LINK错误*/
template<class K, class E>
void (*binarySearchTree<K,E>::visit)(binaryTreeNode<pair<K, E>>*) = 0;      // visit function

/*中序遍历 递归*/
template<class K, class E>
void binarySearchTree<K,E>::inOrder(binaryTreeNode<pair<K, E>>* t)
{
    if (t != nullptr)
    {
        inOrder(t->leftChild);/*中序遍历左子树*/
        visit(t);/*访问树根*/
        inOrder(t->rightChild);/*中序遍历右子树*/
    }
}

/*  查找元素
 *  输入：theKey表示需要查找元素的键值
 *  输出：键值为theKey的节点的pair地址
 *  时间复杂度：O(logn)，n表示节点个数
 */
template<class K, class E>
pair<K, E>* binarySearchTree<K,E>::find(K theKey) const
{
    // 返回值是匹配数对的指针
    // 如果没有匹配的数对，返回值为nullptr
    // p从根节点开始搜索，寻找关键字等于theKey的一个元素
    binaryTreeNode<pair<K, E> > *p = root;
    while (p != nullptr)
        // 检查元素 p->element
        if (theKey < p->element.first)
            p = p->leftChild;
        else
        if (theKey > p->element.first)
            p = p->rightChild;
        else // 找到匹配的元素
            return &p->element;

    // 没找到匹配的元素
    return nullptr;
}
/*
 *  插入元素
 *  输入：const pair<K, E> thePair表示需要插入的键值对
 *  输出：void
 *  时间复杂度：O(logn)，表示节点个数
 */
template<class K, class E>
void binarySearchTree<K,E>::insert(const pair<K, E> thePair)
{
    // 插入thePair. 如果该键值存在则覆盖元素
    // 寻找插入位置
    binaryTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    while (p != nullptr)
    {// 检查元素 p->element
        pp = p;
        // 如果当前键值小于p的键值，则移到p的左孩子
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else// 如果当前键值大于p的键值，则移到p的右孩子
        if (thePair.first > p->element.first)
            p = p->rightChild;
        else
        {// 如果键值相等，覆盖旧的值
            p->element.second = thePair.second;
            return;
        }
    }

    // 为thePair建立一个节点，然后与pp链接，此时pp是叶子节点
    auto *newNode = new binaryTreeNode<pair<K, E> > (thePair);
    if (root != nullptr) // 树非空
        // 如果thePair的键值小于pp的键值，则将thePair作为pp的左孩子，反之将其作为右孩子
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else// 树空
        root = newNode; // 直接将thePair节点作为根节点
    treeSize++;
}
/*
 *  插入元素
 *  输入：const pair<K, E> thePair表示需要插入的键值对
 *  输出：void
 *  时间复杂度：O(logn)，表示节点个数
 *  目的：为了应用于直方图求解所作的努力
 */
template<class K, class E>
void binarySearchTree<K,E>::insert(const pair<K, E>& thePair, void(*fun)(E& u))
{
    // 插入thePair. 如果该键值存在则覆盖元素
    // 寻找插入位置
    binaryTreeNode<pair<K, E> > *p = root,
    *pp = 0;   // p的父亲节点
    while (p != nullptr)
    {
        pp = p;
        // 移到p的孩子节点
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else
        if (thePair.first > p->element.first)
            p = p->rightChild;
        else
        {// 访问这个元素
            fun(p->element.second);
            return;
        }
    }

    // 为thePair建立一个节点，然后与pp链接，此时pp是叶子节点
    auto *newNode = new binaryTreeNode<pair<K, E> > (thePair);
    if (root != nullptr) // 不是空树
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else
        root = newNode; // 是空树
    treeSize++;
}

/*
 *  删除元素
 *  输入：const K theKey表示需要删除元素的键值
 *  输出：void
 *  时间复杂度：O(logn)，n表示节点个数
 */
template<class K, class E>
void binarySearchTree<K,E>::erase(const K theKey)
{
    // 删除关键字等于theKey的数对
    // 查找关键字为theKey的节点
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
        return; // 不存在与关键字theKey匹配的数对

    // 重新组织树结构
    // 当p有两个孩子时的处理
    if (p->leftChild != nullptr && p->rightChild != nullptr)
    {
        // 两个孩子
        // 在P的左子树中寻找最大元素
        binaryTreeNode<pair<K, E> > *s = p->leftChild,
                *ps = p;  // s的父节点
        while (s->rightChild != nullptr)
        {// 移动到更大的pair
            ps = s;
            s = s->rightChild;// 右孩子比较大
        }

        // 将最大元素s移到p
        // p->element = s->element 的键值是 const
        // 当最大值就是p的左孩子时，new的元素不能直接指向p的左孩子，而要指向p的左孩子的左孩子(此时p的左孩子没有右孩子)，因为到时候s会被delete掉,这个问题在后面的p至多有一个孩子那里解决的
        binaryTreeNode<pair<K, E> >* q = nullptr;
        q = new binaryTreeNode<pair<K, E> >(s->element, p->leftChild, p->rightChild);
        // pp是p的父节点
        // 如果p没有父节点
        if (pp == nullptr)
            root = q;
        else if (p == pp->leftChild)// 如果p是pp的左孩子
            pp->leftChild = q;
        else// 如果p是pp的右孩子
            pp->rightChild = q;
        // 如果s的父节点就是p，说明p节点的左子树只有左子树没有右子树
        // 那么删除p后pp就是其父节点
        if (ps == p) pp = q;
        else pp = ps;// 反之ps是其父节点
        delete p;
        p = s;
    }

    // p至多只有一个孩子
    // 把孩子的指针存放到c
    binaryTreeNode<pair<K, E> > *c;
    if (p->leftChild != nullptr)
        c = p->leftChild;
    else
        c = p->rightChild;

    // 删除p
    if (p == root)
        root = c;
    else
    {// p是pp的左孩子还是右孩子
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
