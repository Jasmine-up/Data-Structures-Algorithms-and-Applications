/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��22��09��17��
Last Version:			V1.0
Descriptions:			ʹ������ʵ�ֵ��ֵ��cpp�ļ�
*/
#include "_23dictionaryChain.h"
using namespace std;
void dictionaryChainTest()
{
    cout << endl << "******************************dictionaryChainTest()������ʼ***********************************" << endl;
    dictionaryChain<int, int> a;
    //������������
    cout << endl << "�����������*******************************************" << endl;
    cout << "�������************************" << endl;
    cin >> a;
    cout << "dictionaryChain a is:" << a;
    cout << endl << "���Գ�Ա����*******************************************" << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "find()**************************" << endl;
    cout << "a.find(1)->second = " << a.find(1)->second << endl;
    cout << "insert()************************" << endl;
    pair<const int, int> insertData(3,4);
    a.insert(insertData);
    cout << "dictionaryChain a is:" << a;
    cout << "erase()*************************" << endl;
    a.erase(1);
    cout << "dictionaryChain a is:" << a;

    cout << "******************************dictionaryChainTest()��������***********************************" << endl;
}