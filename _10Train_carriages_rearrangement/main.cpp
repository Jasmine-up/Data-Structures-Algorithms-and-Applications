#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*列车车厢重排全局变量*/
stack<int>* trackStack;//缓冲轨道数组
vector<int> outputTrackStack;//输出数组
int numberOfCarsStack;//需要重排的列车数目
int numberOfTracksStack;//缓冲轨道数目
int smallestCarStack;//在缓冲轨道中编号最小的车厢
int itsTrackStack;//停靠着最小编号车厢的缓冲轨道

/*列车车厢重排问题*/
/*将编号最小的车厢从缓冲轨道移到出轨道*/
void outputFromHoldingTrackStack()
{
    //从栈itsTrack中删除编号最小的车厢
    outputTrackStack.push_back(trackStack[itsTrackStack].top());
    trackStack[itsTrackStack].pop();
    cout << "Move car " << smallestCarStack << " from holding track " << itsTrackStack << " to output track" << endl;
    //检查所有的栈顶，寻找编号最小的车厢和它所属的栈itsTrack
    smallestCarStack = numberOfCarsStack + 2;
    for (int i = 1; i <= numberOfTracksStack; i++)
    {
        if (!trackStack[i].empty() && (trackStack[i].top() < smallestCarStack))
        {
            smallestCarStack = trackStack[i].top();
            itsTrackStack = i;
        }
    }
}
/*将车厢c移到一个缓冲轨道。返回false,当且仅当没有可用的缓冲轨道*/
bool putInHoldingTrackStack(int c)
{
    //为车厢c寻找最适合的缓冲轨道
    //初始化
    int bestTrack = 0;//目前没有适合的缓冲轨道
    int bestTop = numberOfCarsStack + 1;//取bestTrack中最顶部的车厢，便于比较
    //扫描缓冲轨道
    for (int i = 1; i <= numberOfTracksStack; i++)
    {
        //缓冲轨道i不为空
        // 是一个单调栈，栈底到栈顶的数据是从小到大
        if (!trackStack[i].empty())
        {
            if (c < trackStack[i].top() && trackStack[i].top() < bestTop)
            {//缓冲轨道i的栈顶具有编号更小的车厢
                bestTop = trackStack[i].top();
                bestTrack = i;
            }
        }
        else if (bestTrack == 0) bestTrack = i;
    }
    if (bestTrack == 0) return false;//没有可用的缓冲轨道
    //把车厢c移动到轨道bestTrack
    trackStack[bestTrack].push(c);
    cout << "Move car " << c << " from input track to holding track " << bestTrack << endl;
    //如果需要，更新smallestCar和itsTrack
    if (c < smallestCarStack)
    {
        smallestCarStack = c;
        itsTrackStack = bestTrack;
    }
    return true;
}
/*从初始顺序开始重排车厢；如果重排成功，返回true,否则返回false*/
bool railRoadStack(int inputOrder[], int theNumberOfCars, int theNumberOfTracks)
{
    numberOfCarsStack = theNumberOfCars;
    numberOfTracksStack = theNumberOfTracks;
    /*创建用于缓冲轨道的栈*/
    trackStack = new stack<int>[numberOfTracksStack + 1];
    smallestCarStack = numberOfCarsStack + 1;//缓冲轨道中无车厢

    int nextCarToOutput = 1;//当前需要被输出轨道的车厢编号
    //重排车厢
    for (int i = 0; i < numberOfCarsStack; i++)
    {
        if (inputOrder[i] == nextCarToOutput)
        {
            /*将车厢inputOrder[i]直接移到出轨道*/
            cout << "Move car " << inputOrder[i] << " from input track to output track" << endl;
            outputTrackStack.push_back(inputOrder[i]);
            nextCarToOutput++;
            /*从缓冲轨道移到出轨道*/
            while (smallestCarStack == nextCarToOutput)
            {
                outputFromHoldingTrackStack();
                nextCarToOutput++;
            }
        }
        else
        {
            if(!putInHoldingTrackStack(inputOrder[i]))
                return false;
        }
    }
    return true;
}

int main()
{
    // 列车车厢重排问题
    cout << "railRoadStack()*****************" << endl;
    int inputOrder[9] = { 5, 8, 1, 7, 4, 2, 9, 6, 3 };
    railRoadStack(inputOrder, 9, 3);
    for(int& data : outputTrackStack)
        cout << data << " ";
    cout << endl;
    return 0;
}
