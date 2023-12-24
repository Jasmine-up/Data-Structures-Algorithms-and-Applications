/*
Project name :			_33Search_tree
Last modified Date:		2023年12月21日11点13分
Last Version:			V1.0
Descriptions:			二叉搜索树——索引二叉树的模板类
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

    // 字典相关的方法
    [[nodiscard]] bool empty() const { return treeSize == 0; }

    [[nodiscard]] int size() const { return treeSize; }

    pair<K, E> *find(const K theKey) const;

    // index从0开始
    [[nodiscard]] pair<K, E>* get(int index) const;

    void insert(const pair<K, E> thePair);

    void erase(const K theKey);

    /*中序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void inOrder(void(*theVisit)(indexedBinarySearchTreeNode<pair<K, E>> *)) {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        inOrder(root);/*这里调用的是静态成员函数inOrder()*/
    }

    /*中序遍历---输出endl*/
    void inOrderOutput() {
        inOrder(output);
        cout << endl;
    }

    /*前序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void preOrder(void(*theVisit)(indexedBinarySearchTreeNode<pair<K, E>> *))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        preOrder(root);/*这里调用的是成员函数，preOrder()*/
    }
    /*前序遍历---输出endl*/
    void preOrderOutput() { preOrder(output); cout << endl; }

    // additional method of bsTree
    void ascend() { inOrderOutput(); }

private:
    indexedBinarySearchTreeNode<pair<K, E>> *root;//指向根的指针
    int treeSize;//树的结点个数
    static void (*visit)(indexedBinarySearchTreeNode<pair<K, E>> *);//是一个函数指针,返回值为void 函数参数为indexedBinarySearchTreeNode<pair<K, E>>
    static void output(indexedBinarySearchTreeNode<pair<K, E>> *t) { cout << *t << " "; }

    static void inOrder(indexedBinarySearchTreeNode<pair<K, E>> *t);
    static void preOrder(indexedBinarySearchTreeNode<pair<K, E>> *t);
};

/*私有静态成员初始化*/
/*这里是静态函数指针成员的初始化，不初始化会引发LINK错误*/
template<class K, class E>
void
(*indexedBinarySearchTree<K, E>::visit)(indexedBinarySearchTreeNode<pair<K, E>> *) = 0;      // visit function

/*中序遍历 递归*/
template<class K, class E>
void indexedBinarySearchTree<K, E>::inOrder(indexedBinarySearchTreeNode<pair<K, E>> *t) {
    if (t != nullptr) {
        inOrder(t->leftChild);/*中序遍历左子树*/
        visit(t);/*访问树根*/
        inOrder(t->rightChild);/*中序遍历右子树*/
    }
}
/*二叉树的普通成员函数*/
/*前序遍历 递归*/
template<class K, class E>
void indexedBinarySearchTree<K, E>::preOrder(indexedBinarySearchTreeNode<pair<K, E>> *t)
{
    if (t != nullptr)
    {
        visit(t);/*访问树根*/
        preOrder(t->leftChild);/*前序遍历左子树*/
        preOrder(t->rightChild);/*前序遍历右子树*/
    }
}

/*  根据键值查找元素
 *  输入：theKey表示需要查找元素的键值
 *  输出：键值为theKey的节点的pair地址
 *  时间复杂度：O(logn)，n表示节点个数
 */
template<class K, class E>
pair<K, E> *indexedBinarySearchTree<K, E>::find(K theKey) const {
    // 返回值是匹配数对的指针
    // 如果没有匹配的数对，返回值为nullptr
    // p从根节点开始搜索，寻找关键字等于theKey的一个元素
    indexedBinarySearchTreeNode<pair<K, E> > *p = root;
    while (p != nullptr)
        // 检查元素 p->element
        if (theKey < p->element.first)
            p = p->leftChild;
        else if (theKey > p->element.first)
            p = p->rightChild;
        else // 找到匹配的元素
            return &p->element;

    // 没找到匹配的元素
    return nullptr;
}

/*
 *  根据索引查找元素
 *  输入：int index表示查找节点的索引
 *  输出：索引为index的节点的pair地址
 */
template<class K, class E>
pair<K, E>* indexedBinarySearchTree<K, E>::get(int index) const {
    indexedBinarySearchTreeNode<pair<K, E> >* cur = root;
    while(cur != nullptr && cur->leftSize != index){
        // 当前节点的索引大于index，移动到左孩子
        if(cur->leftSize > index)
            cur = cur->leftChild;
        else{// 当前节点的索引小于index，移动到右孩子
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
 *  插入元素
 *  输入：const pair<K, E> thePair表示需要插入的键值对
 *  输出：void
 *  时间复杂度：O(logn)，表示节点个数
 */
template<class K, class E>
void indexedBinarySearchTree<K, E>::insert(const pair<K, E> thePair) {
    // 插入thePair. 如果该键值存在则覆盖元素
    // 寻找插入位置
    indexedBinarySearchTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    while (p != nullptr) {// 检查元素 p->element
        pp = p;
        // 如果当前键值小于p的键值，则移到p的左孩子
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else// 如果当前键值大于p的键值，则移到p的右孩子
        if (thePair.first > p->element.first)
            p = p->rightChild;
        else {// 如果键值相等，覆盖旧的值
            p->element.second = thePair.second;
            return;
        }
    }

    // 为thePair建立一个节点，然后与pp链接，此时pp是叶子节点
    auto *newNode = new indexedBinarySearchTreeNode<pair<K, E> >(thePair);
    if (root != nullptr) // 树非空
        // 如果thePair的键值小于pp的键值，则将thePair作为pp的左孩子，反之将其作为右孩子
        if (thePair.first < pp->element.first) {
            pp->leftChild = newNode;// pp的左孩子指向插入的元素，因此pp的索引要更改为1
        } else
            pp->rightChild = newNode;
    else// 树空
        root = newNode; // 直接将thePair节点作为根节点
    treeSize++;

    // 修改索引的值，此时刚加入的元素的leftSize需要调整
    p = root;
    while (p != nullptr) {// 检查元素 p->element
        pp = p;
        // 如果当前键值小于p的键值，则移到p的左孩子
        if (thePair.first < p->element.first){
            pp->leftSize++;
            p = p->leftChild;
        }
        else // 如果当前键值小于等于p的键值，则移到p的右孩子
            p = p->rightChild;
    }
}

/*
 *  删除元素
 *  输入：const K theKey表示需要删除元素的键值
 *  输出：void
 *  时间复杂度：O(logn)，n表示节点个数
 */
template<class K, class E>
void indexedBinarySearchTree<K, E>::erase(const K theKey) {
    // 删除关键字等于theKey的数对
    // 查找关键字为theKey的节点
    indexedBinarySearchTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    bool flag = false; // 用来记录是否需要重新组织索引
    while (p != nullptr && p->element.first != theKey) {
        pp = p;
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            p = p->rightChild;
    }
    if (p == nullptr)
        return; // 不存在与关键字theKey匹配的数对

    // 如果删除节点就是根节点，则其他节点的索引无需改变
    if(p != root)
        flag = true;

    // bigger存储比p大的最小的键值，后面用于删除元素后索引的更新
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
            bigger = p->element.first;// 此时记录为p的键值的目的是不更新p的右孩子的索引
    }
    cout << "bigger = " << bigger << endl;

    // 重新组织树结构
    // 当p有两个孩子时的处理
    if (p->leftChild != nullptr && p->rightChild != nullptr) {
        // 两个孩子
        // 在P的左子树中寻找最大元素
        indexedBinarySearchTreeNode<pair<K, E> > *s = p->leftChild,
                *ps = p;  // s的父节点
        while (s->rightChild != nullptr) {// 移动到更大的pair
            ps = s;
            s = s->rightChild;// 右孩子比较大
        }

        // 将最大元素s移到p
        // p->element = s->element 的键值是 const
        // 当最大值就是p的左孩子时，new的元素不能直接指向p的左孩子，而要指向p的左孩子的左孩子(此时p的左孩子没有右孩子)，因为到时候s会被delete掉,这个问题在后面的p至多有一个孩子那里解决的
        indexedBinarySearchTreeNode<pair<K, E> > *q = nullptr;
        q = new indexedBinarySearchTreeNode<pair<K, E> >(s->element, s->leftSize, p->leftChild, p->rightChild);
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
    indexedBinarySearchTreeNode<pair<K, E> > *c;
    if (p->leftChild != nullptr)
        c = p->leftChild;
    else
        c = p->rightChild;

    // 删除p
    if (p == root)
        root = c;
    else {// p是pp的左孩子还是右孩子
        if (p == pp->leftChild)
            pp->leftChild = c;
        else pp->rightChild = c;
    }
    treeSize--;
    delete p;

    // 修改索引的值，只有被删除的值不是根节点时，才需要这个操作
    // 此时键值为bigger的元素不需要修改索引，但是小于bigger的元素需要
    if(flag){
        indexedBinarySearchTreeNode<pair<K, E> > *temp = root;
        while (temp != nullptr) {
            pp = temp;
            cout << *temp << endl;
            // 如果当前键值小于temp的键值，则移到temp的左孩子
            if (bigger < temp->element.first){
                pp->leftSize--;
                temp = temp->leftChild;
            }
            else // 如果当前键值小于等于p的键值，则移到p的右孩子
            if(bigger > temp->element.first)
                temp = temp->rightChild;
            else //当前键值等于p的值，则终止
                break;
        }
    }

}

#endif //_33SEARCH_TREE_INDEXEDBINARYSEARCHTREE_H
