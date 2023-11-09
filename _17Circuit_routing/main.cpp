#include <iostream>
#include <queue>
using namespace std;

/*用于存储迷宫地址的结构体*/
struct Position
{
    int row,  //行
    col;  //列
    Position() {}
    Position(int prow, int pcol):row(prow),col(pcol){}
    operator int() const { return row; }
    friend ostream& operator<<(ostream& out, const Position x)
    {
        out << "(" << x.row << "," << x.col << ")";
        return out;
    }
};
/*创建二维数组*/
template <class T>
bool make2dArray(T**& x, int numberOfRows, int numberOfColumns)
{
    try {
        //行指针
        x = new T * [numberOfRows];
        //为每一行分配内存
        for (int i = 0; i < numberOfRows; i++)
            x[i] = new int[numberOfColumns];
        return true;
    }
    catch (bad_alloc) { return false; }
}

/*遍历二维数组*/
template<class T>
void traverse2dArray(T**& x, int numberOfRows, int numberOfColumns)
{
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            cout.width(4);
            cout << x[i][j] << "  ";
        }
        cout << endl;
    }
}

/*电路布线问题全局变量*/
int** Grid;//二维方阵
int GridSize;//方阵大小
queue<Position> path;//记录路径的队列
/*电路布线---和迷宫老鼠问题有点像*/
/*方格元素为1表示为障碍，方格元素为0表示无障碍*/
/*方格标记为2表示是起点，方格标记为大于2的整数m表示该方格距离起点m-2步*/
void inputGridQueue()//输入迷宫
{
    cout << "Please enter the size of Grid-Matrix:";
    while (!(cin >> GridSize))
    {
        cin.clear();//清空标志位
        while (cin.get() != '\n')//删除无效的输入
            continue;
        cout << "Please enter the size of Grid-Matrix:";
    }
    //+2的原因是为了避免在处理内部位置和边界位置时存在差别
    make2dArray<int>(Grid, GridSize + 2, GridSize + 2);
    //初始化边界位置的数值
    for (int i = 0; i <= GridSize + 1; i++)
    {
        Grid[i][0] = 1;
        Grid[0][i] = 1;
        Grid[i][GridSize + 1] = 1;
        Grid[GridSize + 1][i] = 1;
    }
    //初始化迷宫
    for (int i = 1; i <= GridSize; i++)
        for (int j = 1; j <= GridSize; j++)
        {
            int positionij;
            cout << "Please enter Grid[" << i << "," << j << "]:";
            while (!(cin >> positionij))
            {
                cin.clear();//清空标志位
                while (cin.get() != '\n')//删除无效的输入
                    continue;
                cout << "Please enter Grid[" << i << "," << j << "]:";
            }
            Grid[i][j] = positionij;
        }
    cout << "The Grid = " << endl;
    traverse2dArray<int>(Grid, GridSize + 2, GridSize + 2);
}
bool findPathQueue(Position start,Position end)//寻找从起点到终点的最短路径，如找到返回true，如没找到则返回false
{
    if ((start.row == end.row) && (start.col == end.col))
        return true;
    //初始化偏移量
    Position offset[4];
    offset[0].row = 0; offset[0].col = 1;//右
    offset[1].row = 1; offset[1].col = 0;//下
    offset[2].row = 0; offset[2].col = -1;//左
    offset[3].row = -1; offset[3].col = 0;//上
    Position here = start;
    Grid[start.row][start.col] = 2;//标记起点为2
    int numOfNbrs = 4;//一个方格的相邻位置数
    /*标记各个方格*/
    queue<Position> q;//将需要标记的方格入栈q
    Position nbr;//邻居方格
    while (true)
    {
        //给相邻位置做标记
        for (int i = 0; i < numOfNbrs; i++)
        {
            nbr.row = here.row + offset[i].row;
            nbr.col = here.col + offset[i].col;
            if (Grid[nbr.row][nbr.col] == 0)//只有方格为0时表示方格无障碍和未标记
            {
                Grid[nbr.row][nbr.col] = Grid[here.row][here.col] + 1;
                if ((nbr.row == end.row) && (nbr.col == end.col))
                    break;//如果标记到终点，则标记完成
                q.push(nbr);//把邻居结点插入队列，以备后面标记，也就是找邻居的邻居
            }
        }
        if ((nbr.row == end.row) && (nbr.col == end.col))
            break;//如果标记到终点，则标记完成
        if (q.empty())
            return false;//没有找到终点，则不可达，返回false
        here = q.front();//取队首元素作为下一节点，以备标记其邻居节点
        q.pop();//删除队首节点
    }

    /*标记完成，构造路径*/
    int pathLength = Grid[end.row][end.col] - 2;
    here = end;//从终点开始回溯
    for (int i = pathLength - 1; i >= 0; i--)
    {
        path.push(here);
        for (int j = 0; j < numOfNbrs; j++)//在周边寻找父节点
        {
            nbr.row = here.row + offset[j].row;
            nbr.col = here.col + offset[j].col;
            if (Grid[nbr.row][nbr.col] == i + 2)
                break;
        }
        here = nbr;
    }
    path.push(start);
    return true;
}
void outputPathQueue()//输出路径
{
    int i = 0;
    cout << "The path = ";
    while(!path.empty()){
        cout << path.front() << ", ";
        path.pop();
    }
    cout << endl;
}

void routingOfCircuit()//测试函数
{
    inputGridQueue();//输入迷宫
    /*输入起始值点和终点*/
    Position start, end;
    cout << "Please enter the start node:";
    while (!(cin >> start.row >> start.col))
    {
        cin.clear();//清空标志位
        while (cin.get() != '\n')//删除无效的输入
            continue;
        cout << "Please enter the start node:";
    }
    cout << "Please enter the end node:";
    while (!(cin >> end.row >> end.col))
    {
        cin.clear();//清空标志位
        while (cin.get() != '\n')//删除无效的输入
            continue;
        cout << "Please enter the end node:";
    }
    findPathQueue(start, end);//寻找最短路径，如找到返回true，如没找到则返回false
    outputPathQueue();//输出路径
}

int main()
{
    cout << "电路布线问题********************" << endl;
    routingOfCircuit();

    return 0;
}
