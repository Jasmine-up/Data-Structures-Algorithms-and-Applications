/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月27日09点44分
Last Version:			V1.0
Descriptions:			用链表表示的二叉树.cpp
笔记：
	1.静态函数指针初始化格式：void (*binaryTreeChains<E>::visit)(binaryTreeNode<E>*) = 0;
	2.不能单独专门化成员模板函数，只能针对整个类专门化。
	3.在模板函数中可以使用typeid()区别对待特定数据类型。
本程序注意事项：
	1.所有关于前缀、后缀、中缀表达式的全部使用了char类型代表元素，char类型数组存储整个表达式
*/
#include "_2myFunctions.h"
#include "_28binaryTreeChains.h"
/*二叉树应用的全局变量*/
/*设置信号放大器*/
int tolerance = 3;//设置容忍值为3
/*并查集*/
treeUnionFindNode* node;

void binaryTreeChainsTest()
{
    cout << endl << "******************************binaryTreeChainsTest()函数开始**********************************" << endl;
    cout << endl << "测试成员函数*******************************************" << endl;
    cout << "输入****************************" << endl;
    cout << "默认构造函数********************" << endl;
    binaryTreeChains<int> a;
    a.input();
    cout << "a.preOrderOutput() = ";
    a.preOrderOutput();
    cout << "复制构造函数********************" << endl;
    binaryTreeChains<int> b(a);
    cout << "b.preOrderOutput() = ";
    b.preOrderOutput();
    cout << "前序中序构造函数****************" << endl;
    int preOrder[] = { 1, 2, 4, 5, 3,7, 6 };
    int inOrder[] = { 4, 2, 5, 1, 7, 3,6 };
    binaryTreeChains<int>e(preOrder, inOrder, 7,false);
    cout << "e.preOrderOutput() = ";
    e.preOrderOutput();
    cout << "e.inOrderOutput() = ";
    e.inOrderOutput();
    cout << "e.postOrderOutput() = ";
    e.postOrderOutput();
    cout << "后序中序构造函数****************" << endl;
    int postOrder[] = { 4,5,2,7,6,3,1 };
    binaryTreeChains<int>f(postOrder, inOrder, 7,true);
    cout << "f.preOrderOutput() = ";
    f.preOrderOutput();
    cout << "f.inOrderOutput() = ";
    f.inOrderOutput();
    cout << "f.postOrderOutput() = ";
    f.postOrderOutput();
    cout << "输出****************************" << endl;
    cout << "前序输出************************" << endl;
    cout << "a.preOrderOutput() = ";
    a.preOrderOutput();
    cout << "b.preOrderOutput() = ";
    b.preOrderOutput();
    //迭代函数遍历
    cout << "a.iterativePreOrder() = ";
    vector<int> result = a.iterativePreOrder();
    vector<int>::iterator ite;
    ite = result.begin();
    for (; ite != result.end(); ite++) {
        cout << *ite << " ";
    }
    cout << endl;
    cout << "中序输出************************" << endl;
    //递归遍历
    cout << "a.inOrderOutput() = ";
    a.inOrderOutput();
    cout << "b.inOrderOutput() = ";
    b.inOrderOutput();
    //迭代函数遍历
    cout << "a.iterativeInOrder() = ";
    result = a.iterativeInOrder();
    ite = result.begin();
    for (; ite != result.end(); ite++) {
    	cout << *ite << " ";
    }
    cout << endl;
    cout << "后序输出************************" << endl;
    cout << "a.postOrderOutput() = ";
    a.postOrderOutput();
    cout << "b.postOrderOutput() = ";
    b.postOrderOutput();
    //迭代函数遍历
    cout << "a.iterativePostOrder() = ";
    result = a.iterativePostOrder();
    ite = result.begin();
    for (; ite != result.end(); ite++) {
    	cout << *ite << " ";
    }
    cout << endl;
    cout << "层序输出************************" << endl;
    cout << "a.levelOrderOutput() = ";
    a.levelOrderOutput();
    cout << "b.levelOrderOutput() = ";
    b.levelOrderOutput();
    cout << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "b.empty() = " << b.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "b.size() = " << b.size() << endl;
    cout << "compare()***********************" << endl;
    cout << "a.compare(b) = " << a.compare(b) << endl;
    binaryTreeChains<int> c;
    c.input();
    cout << "a.compare(c) = " << a.compare(c) << endl;
    cout << "swapTrees()*********************" << endl;
    cout << "a.preOrderOutput() = ";
    a.preOrderOutput();
    a.swapTrees();
    cout << "a.preOrderOutput() = ";
    a.preOrderOutput();
    cout << "height()************************" << endl;
    cout << "a.height() = " << a.height() << endl;
    cout << "maxHeightDifference()***********" << endl;
    cout << "a.maxHeightDifference() = " << a.maxHeightDifference() << endl;
    cout << "layerMaxNumOfNode()*************" << endl;
    cout << "a.layerMaxNumOfNode() = " << a.layerMaxNumOfNode() << endl;
    cout << "maxNumOfNodeInLayer()***********" << endl;
    cout << "a.maxNumOfNodeInLayer() = " << a.maxNumOfNodeInLayer() << endl;

    cout << "******************************binaryTreeChainsTest()函数结束**********************************" << endl;


}

void treeExpressionsTest()
{
    cout << endl << "*******************************treeExpressionTest()函数开始***********************************" << endl;
    cout << endl << "二叉树表达式测试***************************************" << endl;
    /*使用前缀表达式创建二叉树*/
    cout << "前缀表达式构造函数**************" << endl;
    char preExpression[] = { '/','+','-','1','2','+','3','4','*','+','5','6','*','7','8'};
    binaryTreeChains<char>g(preExpression, 15, 1);
    cout << "g.preOrderOutput() = ";
    g.preOrderOutput();
    cout << "g.inOrderOutput() = ";
    g.inOrderOutput();
    cout << "g.postOrderOutput() = ";
    g.postOrderOutput();
    /*使用中缀表达式创建二叉树*/
    cout << "中缀表达式构造函数**************" << endl;
    char inExpression[] = { '(','(','1','-','2',')','+','(','3','+','4',')',')','/','(','(','5','+','6',')','*','(','7','*','8',')',')' };
    /*这里的长度11是包含括号的长度*/
    binaryTreeChains<char>i(inExpression, 27, 2);
    cout << "i.preOrderOutput() = ";
    i.preOrderOutput();
    cout << "i.inOrderOutput() = ";
    i.inOrderOutput();
    cout << "i.postOrderOutput() = ";
    i.postOrderOutput();
    /*使用后缀表达式创建二叉树*/
    cout << "后缀表达式构造函数**************" << endl;
    char postExpression[] = { '1','2','-','3','4','+','+','5','6','+','7','8','*','*','/'};
    binaryTreeChains<char>h(postExpression, 15, 3);
    cout << "h.preOrderOutput() = ";
    h.preOrderOutput();
    cout << "h.inOrderOutput() = ";
    h.inOrderOutput();
    cout << "h.postOrderOutput() = ";
    h.postOrderOutput();
    /*计算树表达式的值*/
    cout << "计算树表达式的值****************" << endl;
    cout << "compulateTree()*****************" << endl;
    binaryTreeChains<char> d;
    d.input();
    cout << "d.preOrderOutput() = ";
    d.preOrderOutput();
    cout << "d.compulateTree() = " << d.compulateTree() << endl;
    /*将后缀表达式转换为中缀表达式*/
    cout << "将后缀表达式转换为中缀表达式****" << endl;
    cout << "postExprToIn()******************" << endl;
    char postExpr1[9] = { '1','2','3','+','4','*','5','-','+' };
    string inExpr1;
    postExprToIn(postExpr1, inExpr1, 9);
    cout << "postExpr1[9] = ";
    traverse1dArray<char>(postExpr1, 9);
    cout << "inExpr1 = " << inExpr1 << endl;
    /*将前缀表达式转换为中缀表达式*/
    cout << "将前缀表达式转换为中缀表达式****" << endl;
    cout << "preExprToIn()*******************" << endl;
    char preExpr1[9] = { '+','1','-','*','+','2','3','4','5' };
    string inExpr2;
    preExprToIn(preExpr1, inExpr2, 9);
    cout << "preExpr1[9] = ";
    traverse1dArray<char>(preExpr1, 9);
    cout << "inExpr1 = " << inExpr2 << endl;
    /*将中缀表达式转换为后缀表达式，需要注意的是，一定要使用括号标出优先级*/
    cout << "将中缀表达式转换为后缀表达式****" << endl;
    cout << "inExprToPost()******************" << endl;
    char inExpr[25] = { '(','(','-','1',')','+','(','2','+','3',')',')','/','(','(','+','4',')','*','(','5','*','6',')',')' };
    char postExpr[13];//这里的长度13是后缀表达式的长度
    inExprToPost(inExpr, postExpr, 25);//这里的长度25是带有括号的中缀表达式的长度
    cout << "inExpr[25] = ";
    traverse1dArray<char>(inExpr, 25);
    cout << "postExpr[13] = ";
    traverse1dArray<char>(postExpr, 13);
    cout << "将中缀表达式转换为前缀表达式****" << endl;
    /*将中缀表达式转换为前缀表达式，需要注意的是，一定要使用括号标出优先级*/
    cout << "inExprToPre()******************" << endl;
    char preExpr[13];//这里的长度13是前缀表达式的长度
    inExprToPre(inExpr, preExpr, 25,13);//这里的长度25是带有括号的中缀表达式的长度
    cout << "inExpr[25] = ";
    traverse1dArray<char>(inExpr, 25);
    cout << "preExpr[13] = ";
    traverse1dArray<char>(preExpr, 13);

    /*计算表达式的值*/
    /*计算前缀表达式的值*/
    cout << "计算前缀表达式的值**************" << endl;
    cout << "preCalculate()******************" << endl;
    char preExpr2[9] = { '+','1','-','*','+','2','3','4','5' };
    int result = preCalculate(preExpr2, 9);
    cout << "result = " << result << endl;
    /*计算中缀表达式的值*/
    cout << "计算中缀表达式的值**************" << endl;
    cout << "inCalculate()******************" << endl;
    char inExpr3[17] = {'(','1','+','(','(','(','2','+','3',')','*','4',')','-','5',')',')'};
    result = inCalculate(inExpr3, 17);
    cout << "result = " << result << endl;
    char inExpr4[27] = { '(','(','5','-','2',')','+','(','3','+','4',')',')','/','(' ,'(','1','+','1',')','*','(','1','*','1',')',')' };
    result = inCalculate(inExpr4, 27);
    cout << "result = " << result << endl;
    /*练习43：计算后缀表达式的值*/
    cout << "计算后缀表达式的值**************" << endl;
    cout << "postCalculate()*****************" << endl;
    char postExpr2[9] = { '1','2','3','+','4','*','5','-','+' };
    result = postCalculate(postExpr2, 9);
    cout << "result = " << result << endl;
    cout << "*******************************treeExpressionTest()函数结束***********************************" << endl;
}

void treeApplicationTest()
{
    cout << endl << "******************************treeApplicationTest()函数开始***********************************" << endl;
    cout << endl << "二叉树应用测试*****************************************" << endl;
    cout << "设置信号放大器******************" << endl;
    booster a, b;
    /*输入*/
    cin >> a;// 这里输入0和1
    cin >> b;// 这里输入0和2
    binaryTreeChains<booster> t, u, v, w, x, y;
    u.makeTree(a, x, x);
    v.makeTree(b, u, x);
    u.makeTree(a, x, x);
    w.makeTree(a, u, x);
    b.degradeFromParent = 3;
    u.makeTree(b, v, w);
    v.makeTree(a, x, x);
    b.degradeFromParent = 3;
    w.makeTree(b, x, x);
    y.makeTree(a, v, w);
    w.makeTree(a, x, x);
    t.makeTree(b, y, w);
    b.degradeFromParent = 0;
    v.makeTree(b, t, u);
    v.postOrder(placeBoosters);
    v.postOrderOutput();
    v.preOrderOutput();
    v.inOrderOutput();
    cout << "并查集**************************" << endl;
    initialize(10);
    unite(1, 2);
    unite(3, 4);
    unite(1, 3);
    cout << "find(1) = " << find(1) << " find(2) = " << find(2) << endl;
    cout << "find(3) = " << find(3) << " find(4) = " << find(4) << endl;
    cout << "find(5) = " << find(5) << " find(6) = " << find(6) << endl;
    cout << "******************************treeApplicationTest()函数结束***********************************" << endl;
}

/*非成员函数*/
/*返回元素data在数组中的位置,找到则返回该元素的位置，未找到则返回-1*/
template<class E>
int findRootLoc(E list[], E data, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (list[i] == data)
            return i;
    }
    return -1;
}
/*获取优先级---inExprToPost中使用*/
int getPriority(char op)
{
    switch (op)
    {
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        case'(':return 0;
        case ')':return 0;//右括号的优先级是0
        default:break;
    }
}
/*练习38：将后缀表达式转换为完全括号化的中缀表达式 完全括号化的中缀表达式如((a)+(b))*/
/*参数说明：postExpr是后缀表达式数组的指针，inExpr用于存储生成的前缀表达式，length是后缀表达式的长度*/
void postExprToIn(char postExpr[], string& inExpr, int length)
{
    inExpr.clear();
    stack<string> st;/*用于存储中间结果*/
    string a, b, c;
    char data;
    for (int i = 0; i < length; i++)
    {
        data = postExpr[i];
        /*当遇到数字时，直接入栈*/
        if (data >= '0' && data <= '9')
            st.push({ data,'\0' });
        else
        {
            /*每执行一次计算就添加括号，每个数据都加括号实在不需要，看起来很冗余*/
            b = st.top() + '\0';
            st.pop();
            a = st.top() + '\0';
            st.pop();
            c = '(' + a + data + b + ')';
            st.push(c);
        }
    }
    if (st.size() == 1)
        inExpr = st.top();
    else
        inExpr = "后缀表达式非法，转换失败！";
}
/*练习40：将中缀表达式转换为后缀表达式*/
/*条件：必须要包含括号---用于区分优先级*/
/*操作数处理规则：因为操作数的顺序在中缀、前缀、后缀表达式中是一样的，所以在从中缀向前缀或后缀转换时，仅需要从左到右扫描中缀表达式*/
/*
操作符处理规则：
	如果当前操作符优先级大于操作符栈的顶部元素，直接入栈
	如果当前操作符优先级小于或等于操作符栈的顶部元素，先将顶部元素出栈再将当前操作符入栈
	当前操作符为左括号时直接入栈
	当前操作符为右括号时，让栈顶到左括号为止的操作符出栈，括号不出现在后缀表达式中
*/
/*把扫描到的操作数直接输出，而遇到的操作符保留在栈中，根据操作符和左括号的优先级来确定输出*/
/*+-的优先级为1，*和/的优先级为2,栈外左括号的优先级为3，栈内左括号的优先级为0*/
/*返回后缀表达式---使用postExpr[]数组返回*/
/*参数说明：inExpr为指向中缀表达式的指针，postExpr为指向生成的后序表达式的指针，length表示中缀表达式的长度*/
void inExprToPost(char inExpr[], char postExpr[], int length)
{
    int postLoc = 0;//记录后缀表达式的当前位置
    char data = 0;//记录读取的前缀表达式的元素
    stack<char> opStack;//用于存储中间过程的符号
    /*顺序访问中缀表达式*/
    for (int i = 0; i < length; i++)
    {
        data = inExpr[i];
        /*当遇到数字时，直接将其存储到后缀表达式中*/
        if (data >= '0' && data <= '9')
        {
            postExpr[postLoc] = data;
            postLoc++;//后缀表达式存储一个值，当前位置+1
        }
        else/*当遇到的是符号时*/
        {
            if (opStack.empty())
                opStack.push(data);
            else
                switch (data)
                {
                    case '(':opStack.push('('); break;//当遇到左括号时，直接将其入栈
                    case ')'://当遇到右括号时，让栈顶到左括号的操作符出栈
                        while (opStack.top() != '(')
                        {
                            postExpr[postLoc] = opStack.top();
                            postLoc++;
                            opStack.pop();
                        }
                        opStack.pop();//让(出栈
                        break;
                        /*当遇到+ - * /时,当其优先级大于栈顶元素时，入栈；否则，先将栈顶元素出栈，再将当前元素入栈*/
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        if (getPriority(data) > getPriority(opStack.top()))
                            opStack.push(data);
                        else
                        {
                            postExpr[postLoc] = opStack.top();
                            postLoc++;
                            opStack.pop();
                            opStack.push(data);
                        }
                        break;
                    default:break;
                }
            /*当检查到中缀表达式的最后一个元素且栈非空时，将栈中的元素全部输出到后缀表达式*/
            if (!opStack.empty() && i == length - 1)
                while (!opStack.empty())
                {
                    postExpr[postLoc] = opStack.top();
                    postLoc++;
                    opStack.pop();
                }
        }
    }
}
/*练习41：将中缀表达式转换为前缀表达式---从后往前归入前缀表达式*/
/*
首先设定一个操作符栈，从右到左顺序扫描整个中缀表达式，如果是操作数，则直接归入前缀表达式；
如果是操作符：
	1.如果是右括号，则直接将其入栈；
	2.如果是左括号，则将操作符栈中的操作符依次弹栈，归入前缀表达式，直至遇到右括号，将右括号弹栈，处理结束；
	3.如果是其他操作符，如果栈顶操作符优先级大于当前操作符的优先级，则弹栈，并归入前缀表达式，
	直至栈顶操作符优先级小于等于当前操作符优先级，这时将当前操作符压栈。
*/
/*参数说明：inExpr为指向中缀表达式的指针，preExpr为指向生成的后序表达式数组的指针，inLength表示中缀表达式的长度,preLength表示前缀表达式的长度*/
void inExprToPre(char inExpr[], char preExpr[], int inLength, int preLength)
{
    int postLoc = preLength - 1;//记录前缀表达式的当前位置
    char data = 0;//记录读取的中缀表达式的元素
    stack<char> opStack;//用于存储中间过程的符号
    /*顺序访问中缀表达式*/
    for (int i = inLength - 1; i >= 0; i--)
    {
        data = inExpr[i];
        /*当遇到数字时，直接将其存储到前缀表达式中*/
        if (data >= '0' && data <= '9')
        {
            preExpr[postLoc] = data;
            postLoc--;//前缀表达式存储一个值，当前位置-1
        }
        else/*当遇到的是符号时*/
        {
            /*当操作符栈为空时，直接将当前操作符入栈*/
            if (opStack.empty())
                opStack.push(data);
            else
                switch (data)
                {
                    case ')':opStack.push(')'); break;//当遇到右括号时，直接将其入栈
                    case '('://当遇到左括号时，让栈顶到右括号的操作符出栈
                        while (opStack.top() != ')')
                        {
                            preExpr[postLoc] = opStack.top();
                            postLoc--;
                            opStack.pop();
                        }
                        opStack.pop();//让')'出栈
                        break;
                        /*当遇到+ - * /时,当栈顶元素优先级大于当前操作符优先级时，入栈；
                        否则，将栈顶元素出栈，出栈直到当前操作符优先级大于栈顶元素优先级，最后将当前元素入栈*/
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        while (getPriority(opStack.top()) > getPriority(data))/*栈顶元素操作符优先级大于当前操作符优先级，就出栈*/
                        {
                            preExpr[postLoc] = opStack.top();
                            postLoc--;
                            opStack.pop();
                        }
                        opStack.push(data);/*直到上述条件不成立，就入栈*/
                        break;
                    default:break;
                }
            /*当检查到中缀表达式的最后一个元素且栈非空时，将栈中的元素全部输出到前缀表达式*/
            if (!opStack.empty() && i == 0)
                while (!opStack.empty())
                {
                    preExpr[postLoc] = opStack.top();
                    postLoc--;
                    opStack.pop();
                }
        }
    }
}

/*练习39：将前缀表达式转换为带括号的中缀表达式 如((a+b)+(c*d))*/
/*参数说明：postExpr是后缀表达式数组的指针，inExpr用于存储生成的前缀表达式，length是后缀表达式的长度*/
void preExprToIn(char preExpr[], string& inExpr, int length)
{
    inExpr.clear();
    stack<string> st;/*用于存储中间结果*/
    string a, b, c;
    char data;
    for (int i = length-1; i >= 0; i--)
    {
        data = preExpr[i];
        /*当遇到数字时，直接入栈*/
        if (data >= '0' && data <= '9')
            st.push({ data,'\0' });
        else
        {
            /*每执行一次计算就添加括号，每个数据都加括号实在不需要，看起来很冗余*/
            a = st.top() + '\0';
            st.pop();
            b = st.top() + '\0';
            st.pop();
            c = '(' + a + data + b + ')';
            st.push(c);
        }
    }
    if (st.size() == 1)
        inExpr = st.top();
    else
        inExpr = "后缀表达式非法，转换失败！";
}

/*计算表达式的值*/
/*前缀表达式计算表达式的值*/
/*参数说明：preExpr表示指向前缀表达式数组的指针，length表示前缀表达式的长度；返回值为计算的结果*/
int preCalculate(char preExpr[], int length)
{
    stack<int> st;/*用于存储中间结果*/
    char data;
    int a, b;
    for (int i = length - 1; i >= 0; i--)
    {
        data = preExpr[i];
        /*当遇到数字时，直接入栈*/
        if (data >= '0' && data <= '9')
            st.push(data-'0');
        else
        {
            switch (data)//当前结点不是叶子节点时，说明他是符号结点
            {
                case '+':
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(a + b);
                    break;
                case '-':
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(a - b);
                    break;
                case '*':
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(a * b);
                    break;
                case '/':
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    if (b != 0)
                        st.push(a / b);
                    else
                        throw illegalParameterValue("除数不能为0！");
                    break;
                default:break;
            }
        }
    }
    if (st.size() == 1)
        return st.top();
    else
        cout << "前缀表达式非法，计算失败！" << endl;
    return 0;
}
/*针对不同的操作符，执行不同的运算*/
/*参数说明：op即为操作符，a是左操作数，b是右操作数；返回值为运算的结果*/
int calculate(char op, int a, int b)
{
    switch (op)
    {
        case '+':return a + b;
        case '-':return a - b;
        case '*':return a * b;
        case '/':
            if (b == 0)
                throw illegalParameterValue("除数不能为0！");
            else
                return a / b;
    }
}
/*中缀表达式计算表达式的值*/
/*参数说明：inExpr表示指向中缀表达式数组的指针，length表示中缀表达式的长度；返回值为计算的结果*/
int inCalculate(char inExpr[], int length)
{
    stack<int> st;/*用于存储中间结果*/
    stack<char> opStack;/*用于存储操作符*/
    char data;
    int a, b;
    for (int i = 0; i < length; i++)
    {
        data = inExpr[i];
        /*如果是数据，则生成二叉树结点入栈*/
        if (data >= '0' && data <= '9')
            st.push(data - '0');
        else
        {
            if (opStack.empty())
                opStack.push(data);
            else
                switch (data)
                {
                    case '(':opStack.push(data); break;//当遇到左括号时，直接将其入栈
                    case ')'://当遇到右括号时，让栈顶到左括号的操作符出栈
                        while (opStack.top() != '(')
                        {
                            /*获取数据*/
                            b = st.top();
                            st.pop();
                            a = st.top();
                            st.pop();
                            /*获取符号*/
                            data = opStack.top();
                            opStack.pop();
                            /*计算结果并入栈*/
                            st.push(calculate(data, a, b));
                        }
                        opStack.pop();//让(出栈
                        break;
                        /*当遇到+ - * /时,当其优先级大于栈顶元素时，入栈；否则，先将栈顶元素出栈，再将当前元素入栈*/
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        if (getPriority(data) > getPriority(opStack.top()))
                            opStack.push(data);
                        else
                        {
                            b = st.top();
                            st.pop();
                            a = st.top();
                            st.pop();
                            st.push(calculate(data, a, b));
                        }
                        break;
                    default:break;
                }
        }
        /*当检查到中缀表达式的最后一个元素且栈非空时，将操作符栈中的元素弹出并计算运算的值*/
        if (!opStack.empty() && i == length - 1)
            while (!opStack.empty())
            {
                /*获取数据*/
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                /*获取符号*/
                data = opStack.top();
                opStack.pop();
                /*计算结果并入栈*/
                st.push(calculate(data, a, b));
            }
    }
    return st.top();
}
/*练习43：后缀表达式计算表达式的值*/
/*参数说明：postExpr表示指向后缀表达式数组的指针，length表示后缀表达式的长度；返回值为计算的结果*/
int postCalculate(char postExpr[], int length)
{
    stack<int> st;/*用于存储中间结果*/
    char data;
    int a, b;
    for (int i = 0; i < length; i++)
    {
        data = postExpr[i];
        /*当遇到数字时，直接入栈*/
        if (data >= '0' && data <= '9')
            st.push(data - '0');
        else
        {
            switch (data)//当前结点不是叶子节点时，说明他是符号结点
            {
                case '+':
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a + b);
                    break;
                case '-':
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a - b);
                    break;
                case '*':
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a * b);
                    break;
                case '/':
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    if (b != 0)
                        st.push(a / b);
                    else
                        throw illegalParameterValue("除数不能为0！");
                    break;
                default:break;
            }
        }
    }
    if (st.size() == 1)
        return st.top();
    else
        cout << "后缀表达式非法，计算失败！" << endl;
    return 0;
}

/*二叉树的应用---设置信号放大器*/
void placeBoosters(binaryTreeNode<booster>* x)
{//计算节点x的衰减值，如果衰减值超过容忍值，则放置放大器
    x->element.degradeToLeaf = 0;  //初始化节点x的 到叶子节点的衰减值为0
    //计算x的左子树的衰减值，根据需求放置放大器

    //为什么在设置左右子树到叶子的衰减值时方法不一样，原因是在设置左子树时没有管其右子树到叶子的衰减值是否更大；
    //但是呢每个根节点都有左子树和右子树，该根节点到叶子的衰减值设置为左右子树的最大衰减值；因此在设置右子树时
    //就必须考虑左子树到叶子的衰减是否大于右子树
    binaryTreeNode<booster>* y = x->leftChild;
    if (y != nullptr)
    {//如果x的左子树为空，则不管
        //计算x到叶子节点的衰减值
        int degradation = y->element.degradeToLeaf + y->element.degradeFromParent;
        //如果衰减值大于容忍值
        if (degradation > tolerance)
        {//则在x的左子树放置放大器
            y->element.boosterHere = true;
            x->element.degradeToLeaf = y->element.degradeFromParent;
        }
        else  //不需要放大器
            x->element.degradeToLeaf = degradation;//将x到叶子节点的衰减值设置为degradation
    }

    //计算节点x的衰减值，如果衰减值超过容忍值，则放置放大器
    y = x->rightChild;
    if (y != nullptr)
    {	//当x的右子树不为空时
        int degradation = y->element.degradeToLeaf + y->element.degradeFromParent;
        if (degradation > tolerance)
        {//在x的右子树放置放大器
            y->element.boosterHere = true;
            degradation = y->element.degradeFromParent;
        }
        if (x->element.degradeToLeaf < degradation)
            x->element.degradeToLeaf = degradation;
    }
}

/*二叉树的应用---并查集*/
void initialize(int numberOfElements)
{//初始化numberOfElements个树，每个树都是一个元素
    node = new treeUnionFindNode[numberOfElements + 1];
}

int find(int theElement)
{
    //返回元素theElement所在树的根
    while (!node[theElement].root)//只要节点的root不为true,就一直找他的父节点
        theElement = node[theElement].parent;  // move up one level
    return theElement;
}
/*rootA和rootB是索引*/
void unite(int rootA, int rootB)
{
    //使用重量规则，合并其根不同的树
    //重量大的作为根节点
    if (node[rootA].parent < node[rootB].parent)
    {
        node[rootB].parent += node[rootA].parent;
        node[rootA].parent = rootB;
        node[rootA].root = false;
    }
    else
    {
        node[rootA].parent += node[rootB].parent;
        node[rootB].parent = rootA;
        node[rootB].root = false;
    }
}