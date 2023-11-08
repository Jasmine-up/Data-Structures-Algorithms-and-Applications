#include <iostream>
#include <vector>
using namespace std;
/*使用数组模拟栈*/
/*汉诺塔问题全局变量*/
vector<int> tower[4];//全局变量，tower[1:3]表示三个塔
/*汉诺塔问题*/
/*使用数组存储也是为了实现可视化*/
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
        moveAndShow(n - 1, x, z, y);/*首先把x上的盘子搬到z上*/
        int d = tower[x][tower[x].size() - 1];
        tower[x].pop_back();
        tower[y].push_back(d);
        cout << "Move dish " << d << " from tower " << x << " to top of tower " << y << endl;
        HanoiShowState();
        moveAndShow(n - 1, z, y, x);/*把z上的盘子搬到y上*/
    }
}

void towersOfHanoiStack(int n, int x, int y, int z)
{
    for (int i = n; i > 0; i--)
        tower[1].push_back(i);//初始状态碟子全部在塔1上
    moveAndShow(n, x, y, z);
}



// 若n为偶数，则中位数为(a[n/2]+a[n/2-1])/2，若n为奇数，则中位数为a[n/2]
int main()
{
    towersOfHanoiStack(2, 1, 2, 3);
    return 0;
}
