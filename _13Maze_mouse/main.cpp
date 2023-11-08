#include <iostream>
#include <stack>
using namespace std;

/*用于存储迷宫地址的结构体*/
struct position
{
    int row,  //行
    col;  //列
    operator int() const { return row; }
    friend ostream& operator<<(ostream& out, const position x)
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

/*迷宫老鼠全局变量*/
int** maze,mazeSize;
stack<position> path;//存储路径的数组栈
/*迷宫老鼠问题*/
/*展示界面*/
void welcome()
{
    cout << "******Welcome To RAT IN A MAZE******" << endl;
    cout << "************Jasmine,2022************" << endl;
}
/*输入迷宫*/
void inputMaze()
{
    cout << "Please enter the size of Maze-Matrix:";
    while (!(cin >> mazeSize))
    {
        cin.clear();//清空标志位
        while (cin.get() != '\n')//删除无效的输入
            continue;
        cout << "Please enter the size of Maze-Matrix:";
    }
    //+2的原因是为了避免在处理内部位置和边界位置时存在差别
    make2dArray<int>(maze, mazeSize + 2, mazeSize + 2);
    //初始化边界位置的数值
    for (int i = 0; i <= mazeSize + 1; i++)
    {
        maze[i][0] = 1;
        maze[0][i] = 1;
        maze[i][mazeSize + 1] = 1;
        maze[mazeSize + 1][i] = 1;
    }
    //初始化迷宫
    for (int i = 1; i <= mazeSize; i++)
        for(int j = 1; j <= mazeSize; j++)
        {
            int positionij;
            cout << "Please enter maze[" << i << "," << j << "]:";
            while (!(cin >> positionij))
            {
                cin.clear();//清空标志位
                while (cin.get() != '\n')//删除无效的输入
                    continue;
                cout << "Please enter maze[" << i << "," << j << "]:";
            }
            maze[i][j] = positionij;
        }
    cout << "The maze = " << endl;
    traverse2dArray<int>(maze, mazeSize + 2, mazeSize + 2);
}
/*寻找迷宫路径入口(1,1),出口(size,size)，如找到返回true，如没找到则返回false*/
bool findPath()
{
    path = stack<position>();//存储路径
    //初始化偏移量
    position offset[4];
    offset[0].row = 0; offset[0].col = 1;//右
    offset[1].row = 1; offset[1].col = 0;//下
    offset[2].row = 0; offset[2].col = -1;//左
    offset[3].row = -1; offset[3].col = 0;//上
    //入口
    position here;
    here.row = 1;
    here.col = 1;
    maze[1][1] = 1;//防止回到入口
    int option = 0;//下一步
    int lastOption = 3;

    //寻找一条路径
    while ((here.row != mazeSize) || (here.col != mazeSize))
    {
        int r, c;
        while (option <= lastOption)
        {
            r = here.row + offset[option].row;
            c = here.col + offset[option].col;
            if (maze[r][c] == 0) break;
            option++;//下一个选择
        }
        // 相邻的下一步是否找到
        if (option <= lastOption)
        {//移到maze[r][c]
            path.push(here);
            here.row = r;
            here.col = c;
            maze[r][c] = 1;//防止重复访问该节点
            option = 0;
        }
        else//如果没找到
        {
            if (path.empty())
                return false;
            position next = path.top();
            path.pop();
            if (here.row == next.row) // 说明是移动的左右
                option = 2 + next.col - here.col; // 如果是左的话，op = 3就是上；如果是右的话，op = 1，就是下
            else // 此时移动的是上下
                option = 3 + next.row - here.row; // 如果是上的话，op = 4；如果是下的话，op = 2，就是左
            here = next;
        }
    }
    path.push(here);
    return true;
}
/*输出迷宫路径*/
void outputPath()
{
    int i = 0;
    cout << "The path = ";
    stack<position> temp;
    while(!path.empty()){
        cout << path.top() << "->";
        temp.push(path.top());
        path.pop();
    }
    while(!temp.empty() && temp.size() > 1){
        cout << temp.top() << "->";
        temp.pop();
    }
    cout << temp.top() << endl;
    temp.pop();
}

int main()
{
    cout << "RAT IN A MAZE********************" << endl;
    welcome();
    inputMaze();
    findPath();
    outputPath();
    return 0;
}
