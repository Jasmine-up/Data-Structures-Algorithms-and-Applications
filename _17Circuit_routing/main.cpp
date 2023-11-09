#include <iostream>
#include <queue>
using namespace std;

/*���ڴ洢�Թ���ַ�Ľṹ��*/
struct Position
{
    int row,  //��
    col;  //��
    Position() {}
    Position(int prow, int pcol):row(prow),col(pcol){}
    operator int() const { return row; }
    friend ostream& operator<<(ostream& out, const Position x)
    {
        out << "(" << x.row << "," << x.col << ")";
        return out;
    }
};
/*������ά����*/
template <class T>
bool make2dArray(T**& x, int numberOfRows, int numberOfColumns)
{
    try {
        //��ָ��
        x = new T * [numberOfRows];
        //Ϊÿһ�з����ڴ�
        for (int i = 0; i < numberOfRows; i++)
            x[i] = new int[numberOfColumns];
        return true;
    }
    catch (bad_alloc) { return false; }
}

/*������ά����*/
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

/*��·��������ȫ�ֱ���*/
int** Grid;//��ά����
int GridSize;//�����С
queue<Position> path;//��¼·���Ķ���
/*��·����---���Թ����������е���*/
/*����Ԫ��Ϊ1��ʾΪ�ϰ�������Ԫ��Ϊ0��ʾ���ϰ�*/
/*������Ϊ2��ʾ����㣬������Ϊ����2������m��ʾ�÷���������m-2��*/
void inputGridQueue()//�����Թ�
{
    cout << "Please enter the size of Grid-Matrix:";
    while (!(cin >> GridSize))
    {
        cin.clear();//��ձ�־λ
        while (cin.get() != '\n')//ɾ����Ч������
            continue;
        cout << "Please enter the size of Grid-Matrix:";
    }
    //+2��ԭ����Ϊ�˱����ڴ����ڲ�λ�úͱ߽�λ��ʱ���ڲ��
    make2dArray<int>(Grid, GridSize + 2, GridSize + 2);
    //��ʼ���߽�λ�õ���ֵ
    for (int i = 0; i <= GridSize + 1; i++)
    {
        Grid[i][0] = 1;
        Grid[0][i] = 1;
        Grid[i][GridSize + 1] = 1;
        Grid[GridSize + 1][i] = 1;
    }
    //��ʼ���Թ�
    for (int i = 1; i <= GridSize; i++)
        for (int j = 1; j <= GridSize; j++)
        {
            int positionij;
            cout << "Please enter Grid[" << i << "," << j << "]:";
            while (!(cin >> positionij))
            {
                cin.clear();//��ձ�־λ
                while (cin.get() != '\n')//ɾ����Ч������
                    continue;
                cout << "Please enter Grid[" << i << "," << j << "]:";
            }
            Grid[i][j] = positionij;
        }
    cout << "The Grid = " << endl;
    traverse2dArray<int>(Grid, GridSize + 2, GridSize + 2);
}
bool findPathQueue(Position start,Position end)//Ѱ�Ҵ���㵽�յ�����·�������ҵ�����true����û�ҵ��򷵻�false
{
    if ((start.row == end.row) && (start.col == end.col))
        return true;
    //��ʼ��ƫ����
    Position offset[4];
    offset[0].row = 0; offset[0].col = 1;//��
    offset[1].row = 1; offset[1].col = 0;//��
    offset[2].row = 0; offset[2].col = -1;//��
    offset[3].row = -1; offset[3].col = 0;//��
    Position here = start;
    Grid[start.row][start.col] = 2;//������Ϊ2
    int numOfNbrs = 4;//һ�����������λ����
    /*��Ǹ�������*/
    queue<Position> q;//����Ҫ��ǵķ�����ջq
    Position nbr;//�ھӷ���
    while (true)
    {
        //������λ�������
        for (int i = 0; i < numOfNbrs; i++)
        {
            nbr.row = here.row + offset[i].row;
            nbr.col = here.col + offset[i].col;
            if (Grid[nbr.row][nbr.col] == 0)//ֻ�з���Ϊ0ʱ��ʾ�������ϰ���δ���
            {
                Grid[nbr.row][nbr.col] = Grid[here.row][here.col] + 1;
                if ((nbr.row == end.row) && (nbr.col == end.col))
                    break;//�����ǵ��յ㣬�������
                q.push(nbr);//���ھӽ�������У��Ա������ǣ�Ҳ�������ھӵ��ھ�
            }
        }
        if ((nbr.row == end.row) && (nbr.col == end.col))
            break;//�����ǵ��յ㣬�������
        if (q.empty())
            return false;//û���ҵ��յ㣬�򲻿ɴ����false
        here = q.front();//ȡ����Ԫ����Ϊ��һ�ڵ㣬�Ա�������ھӽڵ�
        q.pop();//ɾ�����׽ڵ�
    }

    /*�����ɣ�����·��*/
    int pathLength = Grid[end.row][end.col] - 2;
    here = end;//���յ㿪ʼ����
    for (int i = pathLength - 1; i >= 0; i--)
    {
        path.push(here);
        for (int j = 0; j < numOfNbrs; j++)//���ܱ�Ѱ�Ҹ��ڵ�
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
void outputPathQueue()//���·��
{
    int i = 0;
    cout << "The path = ";
    while(!path.empty()){
        cout << path.front() << ", ";
        path.pop();
    }
    cout << endl;
}

void routingOfCircuit()//���Ժ���
{
    inputGridQueue();//�����Թ�
    /*������ʼֵ����յ�*/
    Position start, end;
    cout << "Please enter the start node:";
    while (!(cin >> start.row >> start.col))
    {
        cin.clear();//��ձ�־λ
        while (cin.get() != '\n')//ɾ����Ч������
            continue;
        cout << "Please enter the start node:";
    }
    cout << "Please enter the end node:";
    while (!(cin >> end.row >> end.col))
    {
        cin.clear();//��ձ�־λ
        while (cin.get() != '\n')//ɾ����Ч������
            continue;
        cout << "Please enter the end node:";
    }
    findPathQueue(start, end);//Ѱ�����·�������ҵ�����true����û�ҵ��򷵻�false
    outputPathQueue();//���·��
}

int main()
{
    cout << "��·��������********************" << endl;
    routingOfCircuit();

    return 0;
}
