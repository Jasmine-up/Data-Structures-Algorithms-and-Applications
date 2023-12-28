/*
Project name :			_34Balanced_search_tree
Last modified Date:		2023年12月27日10点57分
Last Version:			V1.0
Descriptions:			AVL树模板类
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

    /*中序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void inOrder(void(*theVisit)(AVLTreeNode<pair<K, E>>*))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        inOrder(root);/*这里调用的是静态成员函数inOrder()*/
    }
    /*中序遍历---输出endl*/
    void inOrderOutput() { inOrder(output); cout << endl; }

    /*前序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void preOrder(void(*theVisit)(AVLTreeNode<pair<K, E>>*))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        preOrder(root);/*这里调用的是静态成员函数preOrder()*/
    }
    /*中序遍历---输出endl*/
    void preOrderOutput() { preOrder(output); cout << endl; }

private:
    AVLTreeNode<pair<K, E>>* root;// 指向根的指针
    int treeSize;// 树的结点个数
    static void (*visit)(AVLTreeNode<pair<K, E>>*);//是一个函数指针,返回值为void 函数参数为binaryTreeNode<pair<K, E>>*
    static void output(AVLTreeNode<pair<K, E>>* t) { cout << *t << endl; }
    static void inOrder(AVLTreeNode<pair<K, E>>* t);
    static void preOrder(AVLTreeNode<pair<K, E>>* t);
    void rotateLL(AVLTreeNode<pair<K, E>>*& x);
    void rotateLR(AVLTreeNode<pair<K, E>>*& x);
    void rotateRR(AVLTreeNode<pair<K, E>>*& x);
    void rotateRL(AVLTreeNode<pair<K, E>>*& x);
    void insert(pair<K, E>& thePair, AVLTreeNode<pair<K, E>>*& cur);
};

/*私有静态成员初始化*/
/*这里是静态函数指针成员的初始化，不初始化会引发LINK错误*/
template<class K, class E>
void (*AVLTree<K,E>::visit)(AVLTreeNode<pair<K, E>>*) = 0;      // visit function

/*中序遍历 递归*/
template<class K, class E>
void AVLTree<K,E>::inOrder(AVLTreeNode<pair<K, E>>* t)
{
    if (t != nullptr)
    {
        inOrder(t->leftChild);/*中序遍历左子树*/
        visit(t);/*访问树根*/
        inOrder(t->rightChild);/*中序遍历右子树*/
    }
}

/*前序遍历 递归*/
template<class K, class E>
void AVLTree<K,E>::preOrder(AVLTreeNode<pair<K, E>>* t)
{
    if (t != nullptr)
    {
        visit(t);/*访问树根*/
        preOrder(t->leftChild);/*中序遍历左子树*/
        preOrder(t->rightChild);/*中序遍历右子树*/
    }
}

/*  查找元素
 *  输入：theKey表示需要查找元素的键值
 *  输出：键值为theKey的节点的pair地址
 *  时间复杂度：O(logn)，n表示节点个数
 */
template<class K, class E>
pair<K, E>* AVLTree<K,E>::find(K theKey) const
{
    // 返回值是匹配数对的指针
    // 如果没有匹配的数对，返回值为nullptr
    // p从根节点开始搜索，寻找关键字等于theKey的一个元素
    AVLTreeNode<pair<K, E> > *p = root;
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
 *  LL旋转：在x的左孩子的左孩子插入元素的时候使用
 *  输入：AVLTreeNode<pair<K, E>>* x，x表示从根节点往下移动寻找插入新元素的位置时，最后一个具有-1或1平衡因子的节点。
 *  输出：void
 *  时间复杂度：O(1)
 */
template<class K, class E>
void AVLTree<K,E>::rotateLL(AVLTreeNode<pair<K, E>>*& x){
    AVLTreeNode<pair<K, E>>* b = x->leftChild;
    x->leftChild = b->rightChild;
    b->rightChild = x;

    // 更新x的高度
    if(x->leftChild != nullptr && x->rightChild != nullptr)
        x->height = max(x->leftChild->height, x->rightChild->height) + 1;
    else if(x->leftChild != nullptr)
        x->height = x->leftChild->height + 1;
    else if(x->rightChild != nullptr)
        x->height = x->rightChild->height + 1;
    else
        x->height = 1;
    // 更新b的高度
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
 *  RR旋转：在x的右孩子的右孩子插入元素的时候使用
 *  输入：AVLTreeNode<pair<K, E>>* x，x表示从根节点往下移动寻找插入新元素的位置时，最后一个具有-1或1平衡因子的节点。
 *  输出：void
 *  时间复杂度：O(1)
 */
template<class K, class E>
void AVLTree<K,E>::rotateRR(AVLTreeNode<pair<K, E>>*& x){
    AVLTreeNode<pair<K, E>>* b = x->rightChild;
    x->rightChild = b->leftChild;
    b->leftChild = x;

    // 更新x的高度
    if(x->leftChild != nullptr && x->rightChild != nullptr)
        x->height = max(x->leftChild->height, x->rightChild->height) + 1;
    else if(x->leftChild != nullptr)
        x->height = x->leftChild->height + 1;
    else if(x->rightChild != nullptr)
        x->height = x->rightChild->height + 1;
    else
        x->height = 1;

    // 更新b的高度
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
 *  LR旋转:在x的左孩子的右孩子插入元素的时候使用
 *  输入：AVLTreeNode<pair<K, E>>* x，x表示从根节点往下移动寻找插入新元素的位置时，最后一个具有-1或1平衡因子的节点。
 *  输出：void
 *  时间复杂度：O(1)
 */
template<class K, class E>
void AVLTree<K,E>::rotateLR(AVLTreeNode<pair<K, E>>*& x){
    rotateRR(x->leftChild);
    rotateLL(x);
}

/*
 *  RL旋转：在x的右孩子的左孩子插入元素的时候使用
 *  输入：AVLTreeNode<pair<K, E>>* x，x表示从根节点往下移动寻找插入新元素的位置时，最后一个具有-1或1平衡因子的节点。
 *  输出：void
 *  时间复杂度：O(1)
 */
template<class K, class E>
void AVLTree<K,E>::rotateRL(AVLTreeNode<pair<K, E>>*& x){
    rotateLL(x->rightChild);
    rotateRR(x);
}

/*
 *  插入元素
 *  输入：const pair<K, E> thePair表示需要插入的键值对
 *  输出：void
 *  时间复杂度：O(logn)，表示节点个数
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

        // 计算bf，检查bf是否 == 2，如果是需要调整平衡
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
            if(thePair.first < cur->leftChild->element.first)// 左左插入
                rotateLL(cur);// 单旋转
            else // 左右插入
            {
                if(cur->leftChild->rightChild == nullptr)
                    rotateLL(cur);// 当当前节点的左孩子的右孩子为空时，找不到示意图中替换的C节点
                else
                    rotateLR(cur);
            }
        }
    }
    else if(thePair.first > cur->element.first){
        insert(thePair, cur->rightChild);

        // 计算bf，检查bf是否等于-2，如果是需要调整平衡
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
            if(thePair.first > cur->rightChild->element.first) // 右右插入
                rotateRR(cur);// 单旋转
            else // 右左插入
            {
                if(cur->rightChild->leftChild == nullptr)
                    rotateRR(cur);// 当当前节点的左孩子的右孩子为空时，找不到示意图中替换的C节点
                else
                    rotateRL(cur);
            }
        }
    }
    else// 如果键值已经存在的话，就更新元素
        cur->element.second = thePair.second;

    // 更新cur节点的高度
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
 *  删除元素
 *  输入：const K theKey表示需要删除元素的键值
 *  输出：void
 *  时间复杂度：O(logn)，n表示节点个数
 */
template<class K, class E>
void AVLTree<K,E>::erase(K theKey)
{
    // 删除关键字等于theKey的数对
    // 查找关键字为theKey的节点

    // 前面的删除节点的步骤与二叉搜索树的一致；但是要记录一下路径st
    AVLTreeNode<pair<K, E> > *p = root,
            *pp = nullptr;
    stack<AVLTreeNode<pair<K, E> > *> st;// 记录轨迹
    while (p != nullptr && p->element.first != theKey)
    {
        pp = p;
        st.push(pp);// 记录轨迹
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
        AVLTreeNode<pair<K, E> > *s = p->leftChild,
                *ps = p;  // s的父节点
        while (s->rightChild != nullptr)
        {// 移动到更大的pair
            ps = s;
            st.push(ps);// 记录轨迹
            s = s->rightChild;// 右孩子比较大
        }

        // 将最大元素s移到p
        // p->element = s->element 的键值是 const
        // 当最大值就是p的左孩子时，new的元素不能直接指向p的左孩子，而要指向p的左孩子的左孩子(此时p的左孩子没有右孩子)，因为到时候s会被delete掉,这个问题在后面的p至多有一个孩子那里解决的
        AVLTreeNode<pair<K, E> >* q = nullptr;
        q = new AVLTreeNode<pair<K, E> >(s->element, p->leftChild, p->rightChild, p->height);
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
    AVLTreeNode<pair<K, E> > *c;
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

    // 调整平衡
    int bf = 0;
    bool isRoot = false;// 如果当前节点是根节点，当调整树之后，需要更新root指向的节点
    while(!st.empty()){
        p = st.top();
        st.pop();
        // 更新p节点的高度和其bf值
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
            p->height = 1;// 只有它自己
            bf = 0;
        }
        if(bf == 2)  //  说明被删除节点在当前节点的右子树，是R型不平衡
        {
            // 计算当前节点左孩子的bf值
            int bfL = 0;
            // p的左孩子一定存在
            if(p->leftChild->leftChild != nullptr && p->leftChild->rightChild != nullptr)
                bfL = p->leftChild->leftChild->height - p->leftChild->rightChild->height;
            else if(p->leftChild->leftChild != nullptr)
                bfL = p->leftChild->leftChild->height;
            else if(p->leftChild->rightChild != nullptr)
                bfL = 0 - p->leftChild->rightChild->height;
            else
                bfL = 0;
            // R0型
            if(bfL == 0){
                if(p == root)
                    isRoot = true;
                rotateLL(p);
                if(isRoot)
                    root = p;
                break;// 不用检查其父节点了
            }
            else if(bfL == 1)// R1型
            {
                if(p == root)
                    isRoot = true;
                rotateLL(p);// 需要继续检查其父节点
                if(isRoot)
                    root = p;
            }
            else if(bfL == -1)// R-1型
            {
                if(p == root)
                    isRoot = true;
                if(p->leftChild->rightChild == nullptr)
                    rotateLL(p);// 当当前节点的左孩子的右孩子为空时，找不到示意图中替换的C节点
                else
                    rotateLR(p);//需要继续检查其父节点
                if(isRoot)
                    root = p;
            }
            else{}// 其他，基本上不存在别的什么情况了
        }
        else if(bf == -2) //  说明被删除节点在当前节点的左子树，是L型不平衡
        {
            // 计算当前节点左孩子的bf值
            int bfR = 0;
            // p的右孩子一定存在
            if(p->rightChild->leftChild != nullptr && p->rightChild->rightChild != nullptr)
                bfR = p->rightChild->leftChild->height - p->rightChild->rightChild->height;
            else if(p->rightChild->leftChild != nullptr)
                bfR = p->rightChild->leftChild->height;
            else if(p->rightChild->rightChild != nullptr)
                bfR = 0 - p->rightChild->rightChild->height;
            else
                bfR = 0;
            // L0型
            if(bfR == 0){
                if(p == root)
                    isRoot = true;
                rotateRR(p);//需要继续检查其父节点
                if(isRoot)
                    root = p;
                break;// 不用检查其父节点了
            }
            else if(bfR == 1)// L1型
            {
                if(p == root)
                    isRoot = true;
                rotateRR(p);//需要继续检查其父节点
                if(isRoot)
                    root = p;
            }
            else if(bfR == -1)// L-1型
            {
                if(p == root)
                    isRoot = true;
                if(p->rightChild->leftChild == nullptr)
                    rotateRR(p); // 当当前节点的右孩子的左孩子为空时，找不到示意图中替换的C节点
                else
                    rotateRL(p);//需要继续检查其父节点
                if(isRoot)
                    root = p;
            }
            else{}// 其他，基本上不存在别的什么情况了
        }
        else{}// 其他不操作
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
