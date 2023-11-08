#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*开关盒布线问题*/
/*确定开关盒是否可布线；数组net[0,n-1]管脚数组，用以形成网组；n是管脚个数*/
bool checkBox(int net[], int n)
{
    stack<int>* s = new stack<int>();
    //按顺时针扫描网组
    for (int i = 0; i < n; i++)
    {
        //处理管脚i
        if (!s->empty())
        {
            //检查栈的顶部管脚
            if (net[i] == net[s->top()])
                //管脚net[i]是可布线的，从栈中删除
                s->pop();
            else s->push(i);
        }
        else s->push(i);
    }
    //检查是否有剩余的不可布线的管脚
    if (s->empty())
    {
        //没有剩余的管脚
        cout << "Switch box is routable." << endl;
        return true;
    }
    else
    {
        //有剩余的管脚
        while(!s->empty()){
            cout << s->top() << " ";
            s->pop();
        }
        cout << endl << "Switch box is not routable." << endl;
        return false;
    }
}

int main()
{
    cout << "checkBox()**********************" << endl;
    int net[8] = { 1,2,2,1,3,3,4,4 };
    cout << "checkBox(net, 8) = " << endl;
    checkBox(net, 8);
    return 0;
}
