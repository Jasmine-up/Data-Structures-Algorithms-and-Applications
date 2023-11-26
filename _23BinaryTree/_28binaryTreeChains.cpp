/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��27��09��44��
Last Version:			V1.0
Descriptions:			�������ʾ�Ķ�����.cpp
�ʼǣ�
	1.��̬����ָ���ʼ����ʽ��void (*binaryTreeChains<E>::visit)(binaryTreeNode<E>*) = 0;
	2.���ܵ���ר�Ż���Աģ�庯����ֻ�����������ר�Ż���
	3.��ģ�庯���п���ʹ��typeid()����Դ��ض��������͡�
������ע�����
	1.���й���ǰ׺����׺����׺���ʽ��ȫ��ʹ����char���ʹ���Ԫ�أ�char��������洢�������ʽ
*/
#include "_2myFunctions.h"
#include "_28binaryTreeChains.h"
/*������Ӧ�õ�ȫ�ֱ���*/
/*�����źŷŴ���*/
int tolerance = 3;//��������ֵΪ3
/*���鼯*/
treeUnionFindNode* node;

void binaryTreeChainsTest()
{
    cout << endl << "******************************binaryTreeChainsTest()������ʼ**********************************" << endl;
    cout << endl << "���Գ�Ա����*******************************************" << endl;
    cout << "����****************************" << endl;
    cout << "Ĭ�Ϲ��캯��********************" << endl;
    binaryTreeChains<int> a;
    a.input();
    cout << "a.preOrderOutput() = ";
    a.preOrderOutput();
    cout << "���ƹ��캯��********************" << endl;
    binaryTreeChains<int> b(a);
    cout << "b.preOrderOutput() = ";
    b.preOrderOutput();
    cout << "ǰ�������캯��****************" << endl;
    int preOrder[] = { 1, 2, 4, 5, 3,7, 6 };
    int inOrder[] = { 4, 2, 5, 1, 7, 3,6 };
    binaryTreeChains<int>e(preOrder, inOrder, 7,false);
    cout << "e.preOrderOutput() = ";
    e.preOrderOutput();
    cout << "e.inOrderOutput() = ";
    e.inOrderOutput();
    cout << "e.postOrderOutput() = ";
    e.postOrderOutput();
    cout << "���������캯��****************" << endl;
    int postOrder[] = { 4,5,2,7,6,3,1 };
    binaryTreeChains<int>f(postOrder, inOrder, 7,true);
    cout << "f.preOrderOutput() = ";
    f.preOrderOutput();
    cout << "f.inOrderOutput() = ";
    f.inOrderOutput();
    cout << "f.postOrderOutput() = ";
    f.postOrderOutput();
    cout << "���****************************" << endl;
    cout << "ǰ�����************************" << endl;
    cout << "a.preOrderOutput() = ";
    a.preOrderOutput();
    cout << "b.preOrderOutput() = ";
    b.preOrderOutput();
    //������������
    cout << "a.iterativePreOrder() = ";
    vector<int> result = a.iterativePreOrder();
    vector<int>::iterator ite;
    ite = result.begin();
    for (; ite != result.end(); ite++) {
        cout << *ite << " ";
    }
    cout << endl;
    cout << "�������************************" << endl;
    //�ݹ����
    cout << "a.inOrderOutput() = ";
    a.inOrderOutput();
    cout << "b.inOrderOutput() = ";
    b.inOrderOutput();
    //������������
    cout << "a.iterativeInOrder() = ";
    result = a.iterativeInOrder();
    ite = result.begin();
    for (; ite != result.end(); ite++) {
    	cout << *ite << " ";
    }
    cout << endl;
    cout << "�������************************" << endl;
    cout << "a.postOrderOutput() = ";
    a.postOrderOutput();
    cout << "b.postOrderOutput() = ";
    b.postOrderOutput();
    //������������
    cout << "a.iterativePostOrder() = ";
    result = a.iterativePostOrder();
    ite = result.begin();
    for (; ite != result.end(); ite++) {
    	cout << *ite << " ";
    }
    cout << endl;
    cout << "�������************************" << endl;
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

    cout << "******************************binaryTreeChainsTest()��������**********************************" << endl;


}

void treeExpressionsTest()
{
    cout << endl << "*******************************treeExpressionTest()������ʼ***********************************" << endl;
    cout << endl << "���������ʽ����***************************************" << endl;
    /*ʹ��ǰ׺���ʽ����������*/
    cout << "ǰ׺���ʽ���캯��**************" << endl;
    char preExpression[] = { '/','+','-','1','2','+','3','4','*','+','5','6','*','7','8'};
    binaryTreeChains<char>g(preExpression, 15, 1);
    cout << "g.preOrderOutput() = ";
    g.preOrderOutput();
    cout << "g.inOrderOutput() = ";
    g.inOrderOutput();
    cout << "g.postOrderOutput() = ";
    g.postOrderOutput();
    /*ʹ����׺���ʽ����������*/
    cout << "��׺���ʽ���캯��**************" << endl;
    char inExpression[] = { '(','(','1','-','2',')','+','(','3','+','4',')',')','/','(','(','5','+','6',')','*','(','7','*','8',')',')' };
    /*����ĳ���11�ǰ������ŵĳ���*/
    binaryTreeChains<char>i(inExpression, 27, 2);
    cout << "i.preOrderOutput() = ";
    i.preOrderOutput();
    cout << "i.inOrderOutput() = ";
    i.inOrderOutput();
    cout << "i.postOrderOutput() = ";
    i.postOrderOutput();
    /*ʹ�ú�׺���ʽ����������*/
    cout << "��׺���ʽ���캯��**************" << endl;
    char postExpression[] = { '1','2','-','3','4','+','+','5','6','+','7','8','*','*','/'};
    binaryTreeChains<char>h(postExpression, 15, 3);
    cout << "h.preOrderOutput() = ";
    h.preOrderOutput();
    cout << "h.inOrderOutput() = ";
    h.inOrderOutput();
    cout << "h.postOrderOutput() = ";
    h.postOrderOutput();
    /*���������ʽ��ֵ*/
    cout << "���������ʽ��ֵ****************" << endl;
    cout << "compulateTree()*****************" << endl;
    binaryTreeChains<char> d;
    d.input();
    cout << "d.preOrderOutput() = ";
    d.preOrderOutput();
    cout << "d.compulateTree() = " << d.compulateTree() << endl;
    /*����׺���ʽת��Ϊ��׺���ʽ*/
    cout << "����׺���ʽת��Ϊ��׺���ʽ****" << endl;
    cout << "postExprToIn()******************" << endl;
    char postExpr1[9] = { '1','2','3','+','4','*','5','-','+' };
    string inExpr1;
    postExprToIn(postExpr1, inExpr1, 9);
    cout << "postExpr1[9] = ";
    traverse1dArray<char>(postExpr1, 9);
    cout << "inExpr1 = " << inExpr1 << endl;
    /*��ǰ׺���ʽת��Ϊ��׺���ʽ*/
    cout << "��ǰ׺���ʽת��Ϊ��׺���ʽ****" << endl;
    cout << "preExprToIn()*******************" << endl;
    char preExpr1[9] = { '+','1','-','*','+','2','3','4','5' };
    string inExpr2;
    preExprToIn(preExpr1, inExpr2, 9);
    cout << "preExpr1[9] = ";
    traverse1dArray<char>(preExpr1, 9);
    cout << "inExpr1 = " << inExpr2 << endl;
    /*����׺���ʽת��Ϊ��׺���ʽ����Ҫע����ǣ�һ��Ҫʹ�����ű�����ȼ�*/
    cout << "����׺���ʽת��Ϊ��׺���ʽ****" << endl;
    cout << "inExprToPost()******************" << endl;
    char inExpr[25] = { '(','(','-','1',')','+','(','2','+','3',')',')','/','(','(','+','4',')','*','(','5','*','6',')',')' };
    char postExpr[13];//����ĳ���13�Ǻ�׺���ʽ�ĳ���
    inExprToPost(inExpr, postExpr, 25);//����ĳ���25�Ǵ������ŵ���׺���ʽ�ĳ���
    cout << "inExpr[25] = ";
    traverse1dArray<char>(inExpr, 25);
    cout << "postExpr[13] = ";
    traverse1dArray<char>(postExpr, 13);
    cout << "����׺���ʽת��Ϊǰ׺���ʽ****" << endl;
    /*����׺���ʽת��Ϊǰ׺���ʽ����Ҫע����ǣ�һ��Ҫʹ�����ű�����ȼ�*/
    cout << "inExprToPre()******************" << endl;
    char preExpr[13];//����ĳ���13��ǰ׺���ʽ�ĳ���
    inExprToPre(inExpr, preExpr, 25,13);//����ĳ���25�Ǵ������ŵ���׺���ʽ�ĳ���
    cout << "inExpr[25] = ";
    traverse1dArray<char>(inExpr, 25);
    cout << "preExpr[13] = ";
    traverse1dArray<char>(preExpr, 13);

    /*������ʽ��ֵ*/
    /*����ǰ׺���ʽ��ֵ*/
    cout << "����ǰ׺���ʽ��ֵ**************" << endl;
    cout << "preCalculate()******************" << endl;
    char preExpr2[9] = { '+','1','-','*','+','2','3','4','5' };
    int result = preCalculate(preExpr2, 9);
    cout << "result = " << result << endl;
    /*������׺���ʽ��ֵ*/
    cout << "������׺���ʽ��ֵ**************" << endl;
    cout << "inCalculate()******************" << endl;
    char inExpr3[17] = {'(','1','+','(','(','(','2','+','3',')','*','4',')','-','5',')',')'};
    result = inCalculate(inExpr3, 17);
    cout << "result = " << result << endl;
    char inExpr4[27] = { '(','(','5','-','2',')','+','(','3','+','4',')',')','/','(' ,'(','1','+','1',')','*','(','1','*','1',')',')' };
    result = inCalculate(inExpr4, 27);
    cout << "result = " << result << endl;
    /*��ϰ43�������׺���ʽ��ֵ*/
    cout << "�����׺���ʽ��ֵ**************" << endl;
    cout << "postCalculate()*****************" << endl;
    char postExpr2[9] = { '1','2','3','+','4','*','5','-','+' };
    result = postCalculate(postExpr2, 9);
    cout << "result = " << result << endl;
    cout << "*******************************treeExpressionTest()��������***********************************" << endl;
}

void treeApplicationTest()
{
    cout << endl << "******************************treeApplicationTest()������ʼ***********************************" << endl;
    cout << endl << "������Ӧ�ò���*****************************************" << endl;
    cout << "�����źŷŴ���******************" << endl;
    booster a, b;
    /*����*/
    cin >> a;// ��������0��1
    cin >> b;// ��������0��2
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
    cout << "���鼯**************************" << endl;
    initialize(10);
    unite(1, 2);
    unite(3, 4);
    unite(1, 3);
    cout << "find(1) = " << find(1) << " find(2) = " << find(2) << endl;
    cout << "find(3) = " << find(3) << " find(4) = " << find(4) << endl;
    cout << "find(5) = " << find(5) << " find(6) = " << find(6) << endl;
    cout << "******************************treeApplicationTest()��������***********************************" << endl;
}

/*�ǳ�Ա����*/
/*����Ԫ��data�������е�λ��,�ҵ��򷵻ظ�Ԫ�ص�λ�ã�δ�ҵ��򷵻�-1*/
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
/*��ȡ���ȼ�---inExprToPost��ʹ��*/
int getPriority(char op)
{
    switch (op)
    {
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        case'(':return 0;
        case ')':return 0;//�����ŵ����ȼ���0
        default:break;
    }
}
/*��ϰ38������׺���ʽת��Ϊ��ȫ���Ż�����׺���ʽ ��ȫ���Ż�����׺���ʽ��((a)+(b))*/
/*����˵����postExpr�Ǻ�׺���ʽ�����ָ�룬inExpr���ڴ洢���ɵ�ǰ׺���ʽ��length�Ǻ�׺���ʽ�ĳ���*/
void postExprToIn(char postExpr[], string& inExpr, int length)
{
    inExpr.clear();
    stack<string> st;/*���ڴ洢�м���*/
    string a, b, c;
    char data;
    for (int i = 0; i < length; i++)
    {
        data = postExpr[i];
        /*����������ʱ��ֱ����ջ*/
        if (data >= '0' && data <= '9')
            st.push({ data,'\0' });
        else
        {
            /*ÿִ��һ�μ����������ţ�ÿ�����ݶ�������ʵ�ڲ���Ҫ��������������*/
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
        inExpr = "��׺���ʽ�Ƿ���ת��ʧ�ܣ�";
}
/*��ϰ40������׺���ʽת��Ϊ��׺���ʽ*/
/*����������Ҫ��������---�����������ȼ�*/
/*���������������Ϊ��������˳������׺��ǰ׺����׺���ʽ����һ���ģ������ڴ���׺��ǰ׺���׺ת��ʱ������Ҫ������ɨ����׺���ʽ*/
/*
�������������
	�����ǰ���������ȼ����ڲ�����ջ�Ķ���Ԫ�أ�ֱ����ջ
	�����ǰ���������ȼ�С�ڻ���ڲ�����ջ�Ķ���Ԫ�أ��Ƚ�����Ԫ�س�ջ�ٽ���ǰ��������ջ
	��ǰ������Ϊ������ʱֱ����ջ
	��ǰ������Ϊ������ʱ����ջ����������Ϊֹ�Ĳ�������ջ�����Ų������ں�׺���ʽ��
*/
/*��ɨ�赽�Ĳ�����ֱ��������������Ĳ�����������ջ�У����ݲ������������ŵ����ȼ���ȷ�����*/
/*+-�����ȼ�Ϊ1��*��/�����ȼ�Ϊ2,ջ�������ŵ����ȼ�Ϊ3��ջ�������ŵ����ȼ�Ϊ0*/
/*���غ�׺���ʽ---ʹ��postExpr[]���鷵��*/
/*����˵����inExprΪָ����׺���ʽ��ָ�룬postExprΪָ�����ɵĺ�����ʽ��ָ�룬length��ʾ��׺���ʽ�ĳ���*/
void inExprToPost(char inExpr[], char postExpr[], int length)
{
    int postLoc = 0;//��¼��׺���ʽ�ĵ�ǰλ��
    char data = 0;//��¼��ȡ��ǰ׺���ʽ��Ԫ��
    stack<char> opStack;//���ڴ洢�м���̵ķ���
    /*˳�������׺���ʽ*/
    for (int i = 0; i < length; i++)
    {
        data = inExpr[i];
        /*����������ʱ��ֱ�ӽ���洢����׺���ʽ��*/
        if (data >= '0' && data <= '9')
        {
            postExpr[postLoc] = data;
            postLoc++;//��׺���ʽ�洢һ��ֵ����ǰλ��+1
        }
        else/*���������Ƿ���ʱ*/
        {
            if (opStack.empty())
                opStack.push(data);
            else
                switch (data)
                {
                    case '(':opStack.push('('); break;//������������ʱ��ֱ�ӽ�����ջ
                    case ')'://������������ʱ����ջ���������ŵĲ�������ջ
                        while (opStack.top() != '(')
                        {
                            postExpr[postLoc] = opStack.top();
                            postLoc++;
                            opStack.pop();
                        }
                        opStack.pop();//��(��ջ
                        break;
                        /*������+ - * /ʱ,�������ȼ�����ջ��Ԫ��ʱ����ջ�������Ƚ�ջ��Ԫ�س�ջ���ٽ���ǰԪ����ջ*/
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
            /*����鵽��׺���ʽ�����һ��Ԫ����ջ�ǿ�ʱ����ջ�е�Ԫ��ȫ���������׺���ʽ*/
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
/*��ϰ41������׺���ʽת��Ϊǰ׺���ʽ---�Ӻ���ǰ����ǰ׺���ʽ*/
/*
�����趨һ��������ջ�����ҵ���˳��ɨ��������׺���ʽ������ǲ���������ֱ�ӹ���ǰ׺���ʽ��
����ǲ�������
	1.����������ţ���ֱ�ӽ�����ջ��
	2.����������ţ��򽫲�����ջ�еĲ��������ε�ջ������ǰ׺���ʽ��ֱ�����������ţ��������ŵ�ջ�����������
	3.��������������������ջ�����������ȼ����ڵ�ǰ�����������ȼ�����ջ��������ǰ׺���ʽ��
	ֱ��ջ�����������ȼ�С�ڵ��ڵ�ǰ���������ȼ�����ʱ����ǰ������ѹջ��
*/
/*����˵����inExprΪָ����׺���ʽ��ָ�룬preExprΪָ�����ɵĺ�����ʽ�����ָ�룬inLength��ʾ��׺���ʽ�ĳ���,preLength��ʾǰ׺���ʽ�ĳ���*/
void inExprToPre(char inExpr[], char preExpr[], int inLength, int preLength)
{
    int postLoc = preLength - 1;//��¼ǰ׺���ʽ�ĵ�ǰλ��
    char data = 0;//��¼��ȡ����׺���ʽ��Ԫ��
    stack<char> opStack;//���ڴ洢�м���̵ķ���
    /*˳�������׺���ʽ*/
    for (int i = inLength - 1; i >= 0; i--)
    {
        data = inExpr[i];
        /*����������ʱ��ֱ�ӽ���洢��ǰ׺���ʽ��*/
        if (data >= '0' && data <= '9')
        {
            preExpr[postLoc] = data;
            postLoc--;//ǰ׺���ʽ�洢һ��ֵ����ǰλ��-1
        }
        else/*���������Ƿ���ʱ*/
        {
            /*��������ջΪ��ʱ��ֱ�ӽ���ǰ��������ջ*/
            if (opStack.empty())
                opStack.push(data);
            else
                switch (data)
                {
                    case ')':opStack.push(')'); break;//������������ʱ��ֱ�ӽ�����ջ
                    case '('://������������ʱ����ջ���������ŵĲ�������ջ
                        while (opStack.top() != ')')
                        {
                            preExpr[postLoc] = opStack.top();
                            postLoc--;
                            opStack.pop();
                        }
                        opStack.pop();//��')'��ջ
                        break;
                        /*������+ - * /ʱ,��ջ��Ԫ�����ȼ����ڵ�ǰ���������ȼ�ʱ����ջ��
                        ���򣬽�ջ��Ԫ�س�ջ����ջֱ����ǰ���������ȼ�����ջ��Ԫ�����ȼ�����󽫵�ǰԪ����ջ*/
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        while (getPriority(opStack.top()) > getPriority(data))/*ջ��Ԫ�ز��������ȼ����ڵ�ǰ���������ȼ����ͳ�ջ*/
                        {
                            preExpr[postLoc] = opStack.top();
                            postLoc--;
                            opStack.pop();
                        }
                        opStack.push(data);/*ֱ����������������������ջ*/
                        break;
                    default:break;
                }
            /*����鵽��׺���ʽ�����һ��Ԫ����ջ�ǿ�ʱ����ջ�е�Ԫ��ȫ�������ǰ׺���ʽ*/
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

/*��ϰ39����ǰ׺���ʽת��Ϊ�����ŵ���׺���ʽ ��((a+b)+(c*d))*/
/*����˵����postExpr�Ǻ�׺���ʽ�����ָ�룬inExpr���ڴ洢���ɵ�ǰ׺���ʽ��length�Ǻ�׺���ʽ�ĳ���*/
void preExprToIn(char preExpr[], string& inExpr, int length)
{
    inExpr.clear();
    stack<string> st;/*���ڴ洢�м���*/
    string a, b, c;
    char data;
    for (int i = length-1; i >= 0; i--)
    {
        data = preExpr[i];
        /*����������ʱ��ֱ����ջ*/
        if (data >= '0' && data <= '9')
            st.push({ data,'\0' });
        else
        {
            /*ÿִ��һ�μ����������ţ�ÿ�����ݶ�������ʵ�ڲ���Ҫ��������������*/
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
        inExpr = "��׺���ʽ�Ƿ���ת��ʧ�ܣ�";
}

/*������ʽ��ֵ*/
/*ǰ׺���ʽ������ʽ��ֵ*/
/*����˵����preExpr��ʾָ��ǰ׺���ʽ�����ָ�룬length��ʾǰ׺���ʽ�ĳ��ȣ�����ֵΪ����Ľ��*/
int preCalculate(char preExpr[], int length)
{
    stack<int> st;/*���ڴ洢�м���*/
    char data;
    int a, b;
    for (int i = length - 1; i >= 0; i--)
    {
        data = preExpr[i];
        /*����������ʱ��ֱ����ջ*/
        if (data >= '0' && data <= '9')
            st.push(data-'0');
        else
        {
            switch (data)//��ǰ��㲻��Ҷ�ӽڵ�ʱ��˵�����Ƿ��Ž��
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
                        throw illegalParameterValue("��������Ϊ0��");
                    break;
                default:break;
            }
        }
    }
    if (st.size() == 1)
        return st.top();
    else
        cout << "ǰ׺���ʽ�Ƿ�������ʧ�ܣ�" << endl;
    return 0;
}
/*��Բ�ͬ�Ĳ�������ִ�в�ͬ������*/
/*����˵����op��Ϊ��������a�����������b���Ҳ�����������ֵΪ����Ľ��*/
int calculate(char op, int a, int b)
{
    switch (op)
    {
        case '+':return a + b;
        case '-':return a - b;
        case '*':return a * b;
        case '/':
            if (b == 0)
                throw illegalParameterValue("��������Ϊ0��");
            else
                return a / b;
    }
}
/*��׺���ʽ������ʽ��ֵ*/
/*����˵����inExpr��ʾָ����׺���ʽ�����ָ�룬length��ʾ��׺���ʽ�ĳ��ȣ�����ֵΪ����Ľ��*/
int inCalculate(char inExpr[], int length)
{
    stack<int> st;/*���ڴ洢�м���*/
    stack<char> opStack;/*���ڴ洢������*/
    char data;
    int a, b;
    for (int i = 0; i < length; i++)
    {
        data = inExpr[i];
        /*��������ݣ������ɶ����������ջ*/
        if (data >= '0' && data <= '9')
            st.push(data - '0');
        else
        {
            if (opStack.empty())
                opStack.push(data);
            else
                switch (data)
                {
                    case '(':opStack.push(data); break;//������������ʱ��ֱ�ӽ�����ջ
                    case ')'://������������ʱ����ջ���������ŵĲ�������ջ
                        while (opStack.top() != '(')
                        {
                            /*��ȡ����*/
                            b = st.top();
                            st.pop();
                            a = st.top();
                            st.pop();
                            /*��ȡ����*/
                            data = opStack.top();
                            opStack.pop();
                            /*����������ջ*/
                            st.push(calculate(data, a, b));
                        }
                        opStack.pop();//��(��ջ
                        break;
                        /*������+ - * /ʱ,�������ȼ�����ջ��Ԫ��ʱ����ջ�������Ƚ�ջ��Ԫ�س�ջ���ٽ���ǰԪ����ջ*/
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
        /*����鵽��׺���ʽ�����һ��Ԫ����ջ�ǿ�ʱ����������ջ�е�Ԫ�ص��������������ֵ*/
        if (!opStack.empty() && i == length - 1)
            while (!opStack.empty())
            {
                /*��ȡ����*/
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                /*��ȡ����*/
                data = opStack.top();
                opStack.pop();
                /*����������ջ*/
                st.push(calculate(data, a, b));
            }
    }
    return st.top();
}
/*��ϰ43����׺���ʽ������ʽ��ֵ*/
/*����˵����postExpr��ʾָ���׺���ʽ�����ָ�룬length��ʾ��׺���ʽ�ĳ��ȣ�����ֵΪ����Ľ��*/
int postCalculate(char postExpr[], int length)
{
    stack<int> st;/*���ڴ洢�м���*/
    char data;
    int a, b;
    for (int i = 0; i < length; i++)
    {
        data = postExpr[i];
        /*����������ʱ��ֱ����ջ*/
        if (data >= '0' && data <= '9')
            st.push(data - '0');
        else
        {
            switch (data)//��ǰ��㲻��Ҷ�ӽڵ�ʱ��˵�����Ƿ��Ž��
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
                        throw illegalParameterValue("��������Ϊ0��");
                    break;
                default:break;
            }
        }
    }
    if (st.size() == 1)
        return st.top();
    else
        cout << "��׺���ʽ�Ƿ�������ʧ�ܣ�" << endl;
    return 0;
}

/*��������Ӧ��---�����źŷŴ���*/
void placeBoosters(binaryTreeNode<booster>* x)
{//����ڵ�x��˥��ֵ�����˥��ֵ��������ֵ������÷Ŵ���
    x->element.degradeToLeaf = 0;  //��ʼ���ڵ�x�� ��Ҷ�ӽڵ��˥��ֵΪ0
    //����x����������˥��ֵ������������÷Ŵ���

    //Ϊʲô����������������Ҷ�ӵ�˥��ֵʱ������һ����ԭ����������������ʱû�й�����������Ҷ�ӵ�˥��ֵ�Ƿ����
    //������ÿ�����ڵ㶼�������������������ø��ڵ㵽Ҷ�ӵ�˥��ֵ����Ϊ�������������˥��ֵ�����������������ʱ
    //�ͱ��뿼����������Ҷ�ӵ�˥���Ƿ����������
    binaryTreeNode<booster>* y = x->leftChild;
    if (y != nullptr)
    {//���x��������Ϊ�գ��򲻹�
        //����x��Ҷ�ӽڵ��˥��ֵ
        int degradation = y->element.degradeToLeaf + y->element.degradeFromParent;
        //���˥��ֵ��������ֵ
        if (degradation > tolerance)
        {//����x�����������÷Ŵ���
            y->element.boosterHere = true;
            x->element.degradeToLeaf = y->element.degradeFromParent;
        }
        else  //����Ҫ�Ŵ���
            x->element.degradeToLeaf = degradation;//��x��Ҷ�ӽڵ��˥��ֵ����Ϊdegradation
    }

    //����ڵ�x��˥��ֵ�����˥��ֵ��������ֵ������÷Ŵ���
    y = x->rightChild;
    if (y != nullptr)
    {	//��x����������Ϊ��ʱ
        int degradation = y->element.degradeToLeaf + y->element.degradeFromParent;
        if (degradation > tolerance)
        {//��x�����������÷Ŵ���
            y->element.boosterHere = true;
            degradation = y->element.degradeFromParent;
        }
        if (x->element.degradeToLeaf < degradation)
            x->element.degradeToLeaf = degradation;
    }
}

/*��������Ӧ��---���鼯*/
void initialize(int numberOfElements)
{//��ʼ��numberOfElements������ÿ��������һ��Ԫ��
    node = new treeUnionFindNode[numberOfElements + 1];
}

int find(int theElement)
{
    //����Ԫ��theElement�������ĸ�
    while (!node[theElement].root)//ֻҪ�ڵ��root��Ϊtrue,��һֱ�����ĸ��ڵ�
        theElement = node[theElement].parent;  // move up one level
    return theElement;
}
/*rootA��rootB������*/
void unite(int rootA, int rootB)
{
    //ʹ���������򣬺ϲ������ͬ����
    //���������Ϊ���ڵ�
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