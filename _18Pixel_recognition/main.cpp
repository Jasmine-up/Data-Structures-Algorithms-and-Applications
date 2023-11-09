#include <iostream>
#include <queue>
using namespace std;

/*���ڴ洢�Թ���ַ�Ľṹ��*/
struct position
{
    int row,  //��
    col;  //��
    position() {}
    position(int prow, int pcol):row(prow),col(pcol){}
    operator int() const { return row; }
    friend ostream& operator<<(ostream& out, const position x)
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

/*ͼԪʶ������ȫ�ֱ���*/
int** pixel;//��ά����
int pixelSize;//�����С

/*ͼԪʶ��*/
/*����Ԫ��Ϊ1��ʾΪ�����أ�����Ԫ��Ϊ0��ʾ������*/
/*���Ϊn(n>1)��ʾΪ��n��ͼԪ*/
void inputPixelQueue()//�������ؾ���
{
    cout << "Please enter the size of pixel-Matrix:";
    while (!(cin >> pixelSize))
    {
        cin.clear();//��ձ�־λ
        while (cin.get() != '\n')//ɾ����Ч������
            continue;
        cout << "Please enter the size of pixel-Matrix:";
    }
    //+2��ԭ����Ϊ�˱����ڴ����ڲ�λ�úͱ߽�λ��ʱ���ڲ��
    make2dArray<int>(pixel, pixelSize + 2, pixelSize + 2);
    //��ʼ���߽�λ�õ���ֵ
    for (int i = 0; i <= pixelSize + 1; i++)
    {
        pixel[i][0] = 0;
        pixel[0][i] = 0;
        pixel[i][pixelSize + 1] = 0;
        pixel[pixelSize + 1][i] = 0;
    }
    //��ʼ������
    for (int i = 1; i <= pixelSize; i++)
        for (int j = 1; j <= pixelSize; j++)
        {
            int positionij;
            cout << "Please enter pixel[" << i << "," << j << "]:";
            while (!(cin >> positionij))
            {
                cin.clear();//��ձ�־λ
                while (cin.get() != '\n')//ɾ����Ч������
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
    inputPixelQueue();//�����Թ���Grid��ά����������СGridSize�͵�·���߹���
    //��ʼ��ƫ����
    position offset[4];
    offset[0].row = 0; offset[0].col = 1;//��
    offset[1].row = 1; offset[1].col = 0;//��
    offset[2].row = 0; offset[2].col = -1;//��
    offset[3].row = -1; offset[3].col = 0;//��
    int numberOfNbrs = 4;//һ�����ص�����λ����
    //ɨ���������أ����ͼԪ
    queue<position> q;
    int id = 1;
    position here, nbr;
    for(int i = 1;i <= pixelSize;i++)
        for (int j = 1; j <= pixelSize; j++)
        {
            if (pixel[i][j] == 1)//��ͼԪ
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
                    //ͼԪ����δ���������
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
    cout << "ͼԪʶ������********************" << endl;
    labelComponents();

    return 0;
}
