#include <iostream>
#include <vector>
using namespace std;
/*ʹ������ģ��ջ*/
/*��ŵ������ȫ�ֱ���*/
vector<int> tower[4];//ȫ�ֱ�����tower[1:3]��ʾ������
/*��ŵ������*/
/*ʹ������洢Ҳ��Ϊ��ʵ�ֿ��ӻ�*/
void HanoiShowState()
{
    cout << "tower[1] = ";
    for(int& data : tower[1])
        cout << data << " ";
    cout << endl;
    cout << "tower[2] = ";
    for(int& data : tower[2])
        cout << data << " ";
    cout << endl;
    cout << "tower[3] = ";
    for(int& data : tower[3])
        cout << data << " ";
    cout << endl;
}

void moveAndShow(int n, int x, int y, int z)
{
    if (n > 0)
    {
        moveAndShow(n - 1, x, z, y);/*���Ȱ�x�ϵ����Ӱᵽz��*/
        int d = tower[x][tower[x].size() - 1];
        tower[x].pop_back();
        tower[y].push_back(d);
        cout << "Move dish " << d << " from tower " << x << " to top of tower " << y << endl;
        HanoiShowState();
        moveAndShow(n - 1, z, y, x);/*��z�ϵ����Ӱᵽy��*/
    }
}

void towersOfHanoiStack(int n, int x, int y, int z)
{
    for (int i = n; i > 0; i--)
        tower[1].push_back(i);//��ʼ״̬����ȫ������1��
    moveAndShow(n, x, y, z);
}



// ��nΪż��������λ��Ϊ(a[n/2]+a[n/2-1])/2����nΪ����������λ��Ϊa[n/2]
int main()
{
    towersOfHanoiStack(2, 1, 2, 3);
    return 0;
}
