/*
Project name :			_35Red_black_tree
Last modified Date:		2024年1月6日18点17分
Last Version:			V1.0
Descriptions:			红黑树模板类
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

    /*中序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void inOrder(void(*theVisit)(RedBlackTreeNode<pair<K, E>> *)) {
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
    void preOrder(void(*theVisit)(RedBlackTreeNode<pair<K, E>> *)) {
        visit = theVisit;
        int num = 0;
        /*是因为递归，所以才要这样的*/
        preOrder(root, num);/*这里调用的是静态成员函数preOrder()*/
        cout << "num = " << num << endl;
    }

    /*中序遍历---输出endl*/
    void preOrderOutput() {
        preOrder(output);
        cout << endl;
    }
    bool ISRBTree();

private:
    RedBlackTreeNode<pair<K, E>> *root;// 指向根的指针
    int treeSize;// 树的结点个数
    static void (*visit)(RedBlackTreeNode<pair<K, E>> *);//是一个函数指针,返回值为void 函数参数为binaryTreeNode<pair<K, E>>*
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

/*私有静态成员初始化*/
/*这里是静态函数指针成员的初始化，不初始化会引发LINK错误*/
template<class K, class E>
void (*RedBlackTree<K, E>::visit)(RedBlackTreeNode<pair<K, E>> *) = 0;      // visit function

/*中序遍历 递归*/
template<class K, class E>
void RedBlackTree<K, E>::inOrder(RedBlackTreeNode<pair<K, E>> *t) {
    if (t != nullptr) {
        inOrder(t->leftChild);/*中序遍历左子树*/
        visit(t);/*访问树根*/
        inOrder(t->rightChild);/*中序遍历右子树*/
    }
}

/*前序遍历 递归*/
template<class K, class E>
void RedBlackTree<K, E>::preOrder(RedBlackTreeNode<pair<K, E>> *t, int& num) {
    if (t != nullptr) {
        visit(t);/*访问树根*/
        num++;
        preOrder(t->leftChild, num);/*中序遍历左子树*/
        preOrder(t->rightChild, num);/*中序遍历右子树*/
    }
}

/*  查找元素
 *  输入：theKey表示需要查找元素的键值
 *  输出：键值为theKey的节点的pair地址
 *  时间复杂度：O(logn)，n表示节点个数
 */
template<class K, class E>
pair<K, E> *RedBlackTree<K, E>::find(K theKey) const {
    // 返回值是匹配数对的指针
    // 如果没有匹配的数对，返回值为nullptr
    // p从根节点开始搜索，寻找关键字等于theKey的一个元素
    RedBlackTreeNode<pair<K, E> > *p = root;
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
 *  LL旋转
 *  输入：x是第一个L的父亲节点，插入元素和删除元素都会用到
 *  输出：void
 *  时间复杂度：O(1)
 *  注意事项：执行本函数前后x指向的元素会改变为新的该子树的根节点
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateLL(RedBlackTreeNode<pair<K, E>> *&x) {
    // 记录祖父节点的父亲节点
    RedBlackTreeNode<pair<K, E>> *Parent = x->parent;
    RedBlackTreeNode<pair<K, E>> *b = x->leftChild;
    x->leftChild = b->rightChild;
    if(b->rightChild)
        b->rightChild->parent = x;

    b->rightChild = x;
    // x的父亲节点变为b
    x->parent = b;
    // b的父亲节点变为原来x的父亲节点
    b->parent = Parent;
    // 这里就是原来祖父节点的父亲现在需要作为b的父亲，前提是祖父节点的父亲存在
    if (Parent != nullptr) {
        if (x == Parent->leftChild)
            Parent->leftChild = b;
        else
            Parent->rightChild = b;
    } else
        root = b;// 祖父节点如果没有父亲的话就是根节点
    x = b;// b节点将替换x节点
}

/*
 *  RR旋转
 *  输入：x表示第一个R的父亲节点，在插入和删除时都会用到
 *  输出：void
 *  时间复杂度：O(1)
 *  注意事项：执行本函数前后x指向的元素会改变为新的该子树的根节点
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateRR(RedBlackTreeNode<pair<K, E>> *&x) {
    // 记录祖父节点的父亲节点
    RedBlackTreeNode<pair<K, E>> *Parent = x->parent;
    RedBlackTreeNode<pair<K, E>> *b = x->rightChild;
    x->rightChild = b->leftChild;
    if(b->leftChild)
        b->leftChild->parent = x;

    b->leftChild = x;
    x->parent = b;// x的父亲节点为b
    // b的父亲节点为祖父节点的父亲节点
    b->parent = Parent;
    // 这里就是原来祖父节点的父亲现在需要作为b的父亲，前提是祖父节点的父亲存在
    if (Parent != nullptr) {
        if (x == Parent->leftChild)
            Parent->leftChild = b;
        else
            Parent->rightChild = b;
    } else
        root = b;// 祖父节点如果没有父亲的话就是根节点
    x = b;
}

/*
 *  LR旋转
 *  输入：x表示L的父亲节点，插入元素和删除元素时都会用到
 *  输出：void
 *  时间复杂度：O(1)
 *  注意事项：执行本函数前后x指向的元素会改变为新的该子树的根节点
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateLR(RedBlackTreeNode<pair<K, E>> *&x) {
    rotateRR(x->leftChild);
    rotateLL(x);
}

/*
 *  RL旋转
 *  输入：x表示R的父亲节点，插入元素和删除元素都会用到
 *  输出：void
 *  时间复杂度：O(1)
 *  注意事项：执行本函数前后x指向的元素会改变为新的该子树的根节点
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateRL(RedBlackTreeNode<pair<K, E>> *&x) {
    rotateLL(x->rightChild);
    rotateRR(x);
}

/*
 * 删除节点时：对于Rr1(2)型和Rr2型的旋转使用
 * 输入：替换被删除节点的y节点的父亲节点
 * 输出：void
 * 时间复杂度：O(1)
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateRr1_2and2(RedBlackTreeNode<pair<K, E>> *&pp) {
    RedBlackTreeNode<pair<K, E>> *Parent = pp->parent;
    RedBlackTreeNode<pair<K, E>> *w = pp->leftChild->rightChild;
    RedBlackTreeNode<pair<K, E>> *x = w->rightChild;
    if(x != nullptr){
        w->rightChild = x->leftChild;
        if(x->leftChild)
            x->leftChild->parent = w;// 父亲节点要及时更改
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
 * 删除节点时，对于Lr1(2)型和Lr2型的旋转使用
 * 输入：替换被删除节点的y节点的父亲节点
 * 输出：void
 * 时间复杂度：O(1)
 */
template<class K, class E>
void RedBlackTree<K, E>::rotateLr1_2and2(RedBlackTreeNode<pair<K, E>> *&pp) {
    RedBlackTreeNode<pair<K, E>> *Parent = pp->parent;
    RedBlackTreeNode<pair<K, E>> *w = pp->rightChild->leftChild;
    RedBlackTreeNode<pair<K, E>> *x = w->leftChild;
    if(x != nullptr){
        w->leftChild = x->rightChild;
        if(x->rightChild)
            x->rightChild->parent = w;// 父亲节点要及时更改
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
 *  插入元素
 *  输入：const pair<K, E> thePair表示需要插入的键值对
 *  输出：void
 *  时间复杂度：O(logn)，表示节点个数
 */
template<class K, class E>
void RedBlackTree<K, E>::insert(pair<K, E> &thePair) {

    // 当红黑树为空时，插入节点直接作为根节点，且其颜色为黑色
    if (root == nullptr) {
        root = new RedBlackTreeNode<pair<K, E> >(thePair, nullptr, nullptr, nullptr, false);
        treeSize++;
        return;
    }
    // 如果树非空. 如果该键值存在则覆盖元素
    // 寻找插入位置
    RedBlackTreeNode<pair<K, E> > *p = root,
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

    // 为thePair建立一个节点，然后与pp链接，此时pp是叶子节，默认插入为红色节点
    auto *newNode = new RedBlackTreeNode<pair<K, E> >(thePair);
    // 如果thePair的键值小于pp的键值，则将thePair作为pp的左孩子，反之将其作为右孩子
    if (thePair.first < pp->element.first) {
        pp->leftChild = newNode;
        newNode->parent = pp;
    } else {
        pp->rightChild = newNode;
        newNode->parent = pp;
    }
    treeSize++;
    p = newNode;
    // 如果父亲节点存在且父亲节点是红色的，则需要对红黑树进行调整
    while (pp && pp->isRed == true) {
        // parent是红色，则其父节点一定存在
        RedBlackTreeNode<pair<K, E> > *grandfather = pp->parent;
        if (pp == grandfather->leftChild) {// parent是grandfather的左孩子
            // LYr(Y可以是L或R)的情况
            RedBlackTreeNode<pair<K, E> > *uncle = grandfather->rightChild;// 找到grandfather的右孩子，可以称为叔叔
            if (uncle && uncle->isRed == true) {// 如果叔叔存在且为红色
                // 将父亲节点和其叔叔节点的颜色更改为黑色
                pp->isRed = uncle->isRed = false;
                // 只有在祖父节点不为根节点时，将祖父节点的颜色更改为红色
                if (grandfather != root)
                    grandfather->isRed = true;
                else // 如果祖父节点已经是根节点了，那么就直接终止循环，因为不可能再向上处理了
                    break;
                // 继续往上处理
                p = grandfather;
                pp = p->parent;
            } else {// uncle不存在或者uncle存在且为黑色
                // 如果当前节点是其父亲节点的左孩子
                // LLb的情况：左孩子的左孩子
                if (p == pp->leftChild) {
                    rotateLL(grandfather);// LL单旋
                    // 调整颜色
                    // 现在的grandfather指向的是原来的父亲节点，grandfather的右孩子指向的是原祖父节点
                    grandfather->isRed = false;
                    grandfather->rightChild->isRed = true;
                } else {// LRb的情况
                    rotateLR(grandfather);
                    // 调整颜色
                    // 现在的grandfather指向的是原来的新节点u，u的左孩子是原来的父亲节点pu，u的右孩子是原来的祖父节点gu
                    grandfather->isRed = false;
                    grandfather->rightChild->isRed = true;
                }
                break;// 无需继续向上进行处理
            }
        } else {// parent是grandfather的右孩子
            // RYr(Y可以是L或R)的情况
            RedBlackTreeNode<pair<K, E> > *uncle = grandfather->leftChild;// 找到grandfather的左孩子，可以称为叔叔
            if (uncle && uncle->isRed == true) {// 如果叔叔存在且为红色
                // 将父亲节点和其叔叔节点的颜色更改为黑色
                pp->isRed = uncle->isRed = false;
                // 只有在祖父节点不为根节点时，将祖父节点的颜色更改为红色
                if (grandfather != root)
                    grandfather->isRed = true;
                else // 如果祖父节点已经是根节点了，那么就直接终止循环，因为不可能再向上处理了
                    break;
                // 继续往上处理
                p = grandfather;
                pp = p->parent;
            } else {// uncle不存在或者uncle存在且为黑色
                // 如果当前节点是其父亲节点的右孩子
                // RRb的情况：右孩子的右孩子
                if (p == pp->rightChild) {
                    rotateRR(grandfather);// RR单旋
                    // 调整颜色
                    // 现在的grandfather指向的是原来的父亲节点，grandfather的左孩子指向的是原祖父节点
                    grandfather->isRed = false;
                    grandfather->leftChild->isRed = true;
                } else {// LRb的情况
                    rotateRL(grandfather);
                    // 调整颜色
                    // 现在的grandfather指向的是原来的新节点u，u的右孩子是原来的父亲节点pu，u的左孩子是原来的祖父节点gu
                    grandfather->isRed = false;
                    grandfather->leftChild->isRed = true;
                }
                break;// 无需继续向上进行处理
            }
        }

    }
}

/*
 *  删除元素
 *  输入：const K theKey表示需要删除元素的键值
 *  输出：void
 *  时间复杂度：O(logn)，n表示节点个数
 */
template<class K, class E>
void RedBlackTree<K, E>::erase(K theKey) {
    // 删除关键字等于theKey的数对
    // 查找关键字为theKey的节点
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
        return; // 不存在与关键字theKey匹配的数对
    }

    // 重新组织树结构
    // 当p有两个孩子时的处理
    if (p->leftChild != nullptr && p->rightChild != nullptr)
    {
        // 两个孩子
        // 在P的左子树中寻找最大元素
        RedBlackTreeNode<pair<K, E> > *s = p->leftChild,
                *ps = p;  // s的父节点
        while (s->rightChild != nullptr)
        {// 移动到更大的pair
            ps = s;
            s = s->rightChild;// 右孩子比较大
        }

        // 将最大元素s移到p
        // p->element = s->element 的键值是 const
        // 当最大值就是p的左孩子时，new的元素不能直接指向p的左孩子，而要指向p的左孩子的左孩子(此时p的左孩子没有右孩子)，因为到时候s会被delete掉,这个问题在后面的p至多有一个孩子那里解决的
        RedBlackTreeNode<pair<K, E> >* q = nullptr;
        // 值用s的值替换，颜色和其他指针的指向都是p的
        q = new RedBlackTreeNode<pair<K, E> >(s->element, p->leftChild, p->rightChild, p->parent, p->isRed);
        if(p->leftChild)
            p->leftChild->parent = q;
        if(p->rightChild)
            p->rightChild->parent = q;
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
    RedBlackTreeNode<pair<K, E> > *c;
    if (p->leftChild != nullptr)
        c = p->leftChild;
    else
        c = p->rightChild;

    // 删除p
    bool isLeft = false;// 记录p节点是左孩子还是右孩子
    if (p == root)
        root = c;
    else
    {// p是pp的左孩子还是右孩子
        if (p == pp->leftChild){
            pp->leftChild = c;
            // 更新一下c节点的父亲节点
            if(c != nullptr)
                c->parent = pp;
            isLeft = true;
        }
        else{
            pp->rightChild = c;
            // 更新一下c节点的父亲节点
            if(c != nullptr)
                c->parent = pp;
        }
    }
    treeSize--;

    // 之前就找到了y节点的父亲节点pp
    // 如果被删除节点是红色的，则红黑树还是平衡的；如果被删除节点是黑色的，则红黑树需要调整
    if(p->isRed == false){
        // 父亲节点不为空，说明还需要继续调整
        while(pp){
            // 如果c节点不为空，则需要判断c节点是左孩子还是右孩子
            // 这个主要是用于第二轮调整平衡，也就是c节点此时不再是p的孩子节点
            if(c){
                if(c == pp->leftChild)
                    isLeft = true;
                else
                    isLeft = false;
            }

            if(isLeft){
                // 找到被删除节点的兄弟
                RedBlackTreeNode<pair<K, E> > *v = pp->rightChild;
                // 如果兄弟节点是黑色节点 Lb型
                // 如果c和v都为空的话，那么不用调整平衡
                if(!c && !v)
                    break;
                if(!v->isRed){
                    // 如果v的左右孩子都是红色节点，Lb2型;或者v的左孩子是红色节点，Lb1(2)型
                    if(v->leftChild && v->leftChild->isRed){
                        rotateRL(pp);// OK1
                        pp->isRed = pp->leftChild->isRed;
                        pp->leftChild->isRed = false;
                        break;
                    }
                    else if(v->rightChild && v->rightChild->isRed){// 如果v的左孩子是红色节点，Lb1(1)型
                        rotateRR(pp);// OK1
                        pp->isRed = pp->leftChild->isRed;// 这个节点的颜色不变
                        pp->leftChild->isRed = false;// 原来的祖先节点的颜色变为黑色节点
                        v->rightChild->isRed = false;// 将v的左孩子更改为黑色节点
                        break;// 不需要继续调整了
                    }
                    else{// 如果v的左右孩子都是黑色节点，Lb0型
                        // pp是红色节点，改变pp为黑色节点，改变v为红色节点
                        if(pp->isRed){
                            pp->isRed = false;// OK1
                            v->isRed = true;
                            break;// 终止循环，不需要再继续调整了
                        }
                        else{// pp是黑色节点，将v节点改变为红色节点，然后将pp节点作为新的y节点，也就是程序中的p节点
                            v->isRed = true;//OK1
                            // 继续调整平衡
                            c = pp;
                            pp = c->parent;
                        }
                    }
                }
                else{// 如果兄弟节点是红色节点 Lr型，则兄弟节点一定有左右孩子
                    // 找到被删除节点的兄弟的左孩子
                    RedBlackTreeNode<pair<K, E> > *vL = v->leftChild;
                    // 如果vL的左右孩子都是红色节点，Lr2型 或者 如果v的左孩子是红色节点，Lr1(2)型
                    if(vL && vL->leftChild && vL->leftChild->isRed){
                        rotateLr1_2and2(pp);// OK1
                        pp->isRed = false;
                        break;
                    }
                    else if(vL && vL->rightChild && vL->rightChild->isRed){// 如果v的右孩子是红色节点，Lr1(1)型
                        rotateRL(pp);// OK1
                        if(vL->rightChild->leftChild)
                            vL->rightChild->leftChild->isRed = false;
                        break;
                    }
                    else{// 如果v的左右孩子都是黑色节点，Lr0型
                        rotateRR(pp);// OK1
                        pp->isRed = false;// 更改原来的v节点为黑色节点
                        if(pp->leftChild->rightChild)
                            pp->leftChild->rightChild->isRed = true;
                        break;
                    }
                }
            }
            else{// 否则是R型
                // 找到被删除节点的兄弟
                RedBlackTreeNode<pair<K, E> > *v = pp->leftChild;
                // 如果c和v都为空的话，那么树本身就是平衡的
                if((!c && !v))
                    break;
                // 如果兄弟节点是黑色节点 Rb型
                if(!v->isRed){
                    // 如果v的左右孩子都是红色节点，Rb2型；或者v的右孩子是红色节点，Rb1(2)型
                    if(v->rightChild && v->rightChild->isRed){
                        rotateLR(pp);// OK1
                        pp->isRed = pp->rightChild->isRed;
                        pp->rightChild->isRed = false;
                        break;
                    }
                    else if(v->leftChild && v->leftChild->isRed){// 如果v的左孩子是红色节点，Rb1(1)型
                        rotateLL(pp);// OK1
                        pp->isRed = pp->rightChild->isRed;// 这个节点的颜色不变
                        pp->rightChild->isRed = false;// 原来的祖先节点的颜色变为黑色节点
                        v->leftChild->isRed = false;// 将v的左孩子更改为黑色节点
                        break;// 不需要继续调整了
                    }
                    else{// 如果v的左右孩子都是黑色节点，Rb0型
                        // pp是红色节点，改变pp为黑色节点，改变v为红色节点
                        if(pp->isRed){
                            pp->isRed = false;// OK1
                            v->isRed = true;
                            break;// 终止循环，不需要再继续调整了
                        }
                        else{// pp是黑色节点，将v节点改变为红色节点，然后将pp节点作为新的y节点，也就是程序中的p节点
                            // 这个没有找到合适的节点去测试
                            v->isRed = true;//OK1
                            c = pp;
                            pp = c->parent;
                        }
                    }
                }
                else{// 如果兄弟节点v是红色节点 Rr型，则兄弟节点v一定有左右孩子
                    // 找到被删除节点的兄弟的右孩子
                    RedBlackTreeNode<pair<K, E> > *vR = v->rightChild;
                    // 如果vR的左右孩子都是红色节点，Rr2型 或者 vR的右孩子是红色节点，Rr1(2)型 两个合起来就是vR的右孩子存在且是红色节点
                    // 两种操作都是一样的
                    if(vR && vR->rightChild && vR->rightChild->isRed){
                        rotateRr1_2and2(pp);// OK1
                        pp->isRed = false;
                        break;
                    }
                    else if(vR && vR->leftChild && vR->leftChild->isRed){// 如果vR的左孩子是红色节点，Rr1(1)型
                        rotateLR(pp);// OK1
                        if(vR->leftChild->rightChild)
                            vR->leftChild->rightChild->isRed = false;
                        break;
                    }
                    else{// 如果v的左右孩子都是黑色节点，Rr0型，没找到合适的树来测试
                        // 如果c节点是nullptr的话，树本来就是平衡的，不需要调整了
                        // OK1
                        rotateLL(pp);
                        pp->isRed = false;// 更改原来的v节点为黑色节点
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

//判断是否为红黑树
template<class K, class E>
bool RedBlackTree<K, E>::ISRBTree()
{
    if (root == nullptr) //空树是红黑树
    {
        return true;
    }
    if (root->isRed == true)
    {
        cout << "error: root is red" << endl;
        return false;
    }

    //找最左路径作为黑色结点数目的参考值
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
//判断是否为红黑树的子函数
template<class K, class E>
bool RedBlackTree<K, E>::_ISRBTree(RedBlackTreeNode<pair<K, E> > * cur, int count, int BlackCount)
{
    if (cur == nullptr) //该路径已经走完了
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
