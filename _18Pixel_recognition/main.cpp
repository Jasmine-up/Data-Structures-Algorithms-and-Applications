#include <iostream>
#include <queue>
using namespace std;

/*用于存储迷宫地址的结构体*/
struct position
{
    int row,  //行
    col;  //列
    position() {}
    position(int prow, int pcol):row(prow),col(pcol){}
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

/*图元识别问题全局变量*/
int** pixel;//二维方阵
int pixelSize;//方阵大小

/*图元识别*/
/*方格元素为1表示为有像素，方格元素为0表示无像素*/
/*标记为n(n>1)表示为第n个图元*/
void inputPixelQueue()//输入像素矩阵
{
    cout << "Please enter the size of pixel-Matrix:";
    while (!(cin >> pixelSize))
    {
        cin.clear();//清空标志位
        while (cin.get() != '\n')//删除无效的输入
            continue;
        cout << "Please enter the size of pixel-Matrix:";
    }
    //+2的原因是为了避免在处理内部位置和边界位置时存在差别
    make2dArray<int>(pixel, pixelSize + 2, pixelSize + 2);
    //初始化边界位置的数值
    for (int i = 0; i <= pixelSize + 1; i++)
    {
        pixel[i][0] = 0;
        pixel[0][i] = 0;
        pixel[i][pixelSize + 1] = 0;
        pixel[pixelSize + 1][i] = 0;
    }
    //初始化像素
    for (int i = 1; i <= pixelSize; i++)
        for (int j = 1; j <= pixelSize; j++)
        {
            int positionij;
            cout << "Please enter pixel[" << i << "," << j << "]:";
            while (!(cin >> positionij))
            {
                cin.clear();//清空标志位
                while (cin.get() != '\n')//删除无效的输入
                    continue;
                cout << "Please enter pixel[" << i << "," << j << "]:";
            }
            pixel[i][j] = positionij;
        }
    cout << "The pixel = " << endl;
    traverse2dArray<int>(pixel, pixelSize + 2, pixelSize + 2);
}
void labelComponents()
{
    inputPixelQueue();//输入迷宫，Grid二维数组和数组大小GridSize和电路布线共享
    //初始化偏移量
    position offset[4];
    offset[0].row = 0; offset[0].col = 1;//右
    offset[1].row = 1; offset[1].col = 0;//下
    offset[2].row = 0; offset[2].col = -1;//左
    offset[3].row = -1; offset[3].col = 0;//上
    int numberOfNbrs = 4;//一个像素的相邻位置数
    //扫描所有像素，标记图元
    queue<position> q;
    int id = 1;
    position here, nbr;
    for(int i = 1;i <= pixelSize;i++)
        for (int j = 1; j <= pixelSize; j++)
        {
            if (pixel[i][j] == 1)//新图元
            {
                pixel[i][j] = ++id;
                here.row = i;
                here.col = j;

                while (true)
                {
                    for (int k = 0; k < numberOfNbrs; k++)
                    {
                        nbr.row = here.row + offset[k].row;
                        nbr.col = here.col + offset[k].col;
                        if (pixel[nbr.row][nbr.col] == 1)
                        {
                            pixel[nbr.row][nbr.col] = id;
                            q.push(nbr);
                        }
                    }
                    //图元中无未考察的像素
                    if (q.empty()) break;
                    here = q.front();
                    q.pop();
                }
            }
        }
    cout << "The pixel = " << endl;
    traverse2dArray<int>(pixel, pixelSize+1, pixelSize+2);
}

int main()
{
    cout << "图元识别问题********************" << endl;
    labelComponents();

    return 0;
}
