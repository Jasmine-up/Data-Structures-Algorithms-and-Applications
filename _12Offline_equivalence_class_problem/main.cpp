#include <iostream>
#include <stack>
using namespace std;

/*离线等价类问题*/
void offlineEquivalenceClass()
{
    int n,//元素个数
    r;//关系个数
    /*输入元素个数n*/
    /*首先成功输入一次*/
    cout << "Enter number of elements(n >= 2):";
    while (!(cin >> n)) {//如果输入类型不匹配，则执行循环体
        cin.clear(); // reset input设置标志位为有效
        while (cin.get() != '\n') //删除没有用的输入
            continue; // get rid of bad input
        cout << "Enter number of elements(n >= 2):";
    }
    /*成功输入一次后检查是否符合要求*/
    while (n < 2) {//如果元素个数小于2，则出错
        cout << "n must be equal or bigger than 2!" << endl;
        cout << "Enter number of elements(n >= 2):";
        while (!(cin >> n)) {//如果输入类型不匹配，则执行循环体
            cin.clear(); // reset input设置标志位为有效
            while (cin.get() != '\n') //删除没有用的输入
                continue; // get rid of bad input
            cout << "Enter number of elements(n >= 2):";
        }
    }

    /*输入关系个数r*/
    /*首先成功输入一次*/
    cout << "Enter number of relations(r >= 1):";
    while (!(cin >> r)) {//如果输入类型不匹配，则执行循环体
        cin.clear(); // reset input设置标志位为有效
        while (cin.get() != '\n') //删除没有用的输入
            continue; // get rid of bad input
        cout << "Enter number of relations(r >= 1):";
    }
    /*成功输入一次后检查是否符合要求*/
    while (r < 1) {//如果元素个数小于2，则出错
        cout << "r must be equal or bigger than 1!" << endl;
        cout << "Enter number of relations(r >= 1):";
        while (!(cin >> r)) {//如果输入类型不匹配，则执行循环体
            cin.clear(); // reset input设置标志位为有效
            while (cin.get() != '\n') //删除没有用的输入
                continue; // get rid of bad input
            cout << "Enter number of relations(r >= 1):";
        }
    }

    /*建立空栈组成的数组，stack[0]不用，用于存储表格*/
    stack<int>* list = new stack<int>[n + 1];

    /*输入r个关系，存储在表中*/
    int a, b;//(a,b)是一个关系
    for (int i = 1; i <= r; i++)
    {
        cout << "Enter next relation/pair:";
        while (!(cin >> a >> b)) {//如果输入类型不匹配，则执行循环体
            cin.clear(); // reset input设置标志位为有效
            while (cin.get() != '\n') //删除没有用的输入
                continue; // get rid of bad input
            cout << "Enter error!Enter current relation/pair:";
        }
        list[a].push(b);
        list[b].push(a);
    }

    /*初始化已输出等价类*/
    stack<int> unprossedList;
    bool* out = new bool[n + 1];//判断该元素是否输出
    for (int i = 1; i <= n; i++)
        out[i] = false;

    /*输出等价类*/
    for (int i = 1; i <= n; i++)
    {
        if (!out[i])
        {
            cout << "Next class is:" << i << " ";
            out[i] = true;
            unprossedList.push(i);
            //从unprossedList中取类的剩余元素
            while (!unprossedList.empty())
            {
                int j = unprossedList.top();
                unprossedList.pop();
                while (!list[j].empty())
                {
                    int q = list[j].top();
                    list[j].pop();
                    if (!out[q]) //未输出
                    {
                        cout << q << " ";
                        out[q] = true;
                        unprossedList.push(q);
                    }
                }
            }
            cout << endl;
        }
    }
    cout << "End of list of eqivalence classes." << endl;
}


int main()
{
    cout << "offlineEquivalenceClass()*******" << endl;
    offlineEquivalenceClass();
    return 0;
}
