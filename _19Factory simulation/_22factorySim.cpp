/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月17日09点22分
Last Version:			V1.0
Descriptions:			工厂仿真cpp文件，使用了数组队列
*/
#include "_22factorySim.h"
using namespace std;
/*全局变量*/
int timeNow = 0;//当前时间,初始状态为0
int numMachines;//机器数量
int numJobs;//任务数量
eventList* eList;//事件表的指针
machine* mArray;//机器数组
int largeTime = 10000;//在这个时间之前所有机器都已经完成工作

void factorySimTest()
{
    inputData();//获取机器和任务的数据
    startShop();//装入初始任务
    simulate();//执行所有任务
    outputStatistics();//输出在每台机器上的等待时间
}

/*输入工厂数据*/
void inputData()
{
    //输入工厂数据
    cout << "Enter number of machines and jobs:";
    while (!(cin >> numMachines>>numJobs))
    {
        cin.clear();//清空标志位
        while (cin.get() != '\n')//删除无效的输入
            continue;
        cout << "Enter number of machines and jobs:";
    }
    if (numMachines < 1 || numJobs < 1)
        throw illegalInputData("number of machines and jobs must be >=1");

    //生成事件和机器队列
    eList = new eventList(numMachines, largeTime);//初始化时所有机器都空闲
    mArray = new machine[numMachines + 1];//mArray[0]未使用

    //输入机器的转换时间
    int ct;
    for (int j = 1; j <= numMachines; j++)
    {
        cout << "Enter change-over times for machines " << j << " :";
        while (!(cin >> ct))
        {
            cin.clear();//清空标志位
            while (cin.get() != '\n')//删除无效的输入
                continue;
            cout << "Enter change-over times for machines " << j << " :" ;
        }
        if (ct < 0)
            throw illegalInputData("change-over time must be >= 0");
        mArray[j].changeTime = ct;//这里没问题，但是警告我也不知道为什么
    }
    //输入任务
    job* theJob;
    int numTasks, firstMachine, theMachine, theTaskTime;
    for (int i = 1; i <= numJobs; i++)
    {
        cout << "Enter number of tasks for job " << i << " :";
        while (!(cin >> numTasks))
        {
            cin.clear();//清空标志位
            while (cin.get() != '\n')//删除无效的输入
                continue;
            cout << "Enter number of tasks for job " << i << " :";
        }
        firstMachine = 0;//第一道工序的机器
        if (numTasks < 1)
            throw illegalInputData("each job must have > 1 task");
        //生成任务
        theJob = new job(i);//job的id为i
        cout << "Enter the tasks (machine,time) in process order" << endl;
        for (int j = 1; j <= numTasks; j++)
        {
            while (!(cin >> theMachine>>theTaskTime))
            {
                cin.clear();//清空标志位
                while (cin.get() != '\n')//删除无效的输入
                    continue;
                cout << "Error!Please re-enter:" << endl;
            }
            if (theMachine < 1 || theTaskTime<1 || theMachine>numMachines)
                throw illegalInputData("bad machines number or task time");
            if (j == 1)
                firstMachine = theMachine;//处理任务的第一台机器
            theJob->addTask(theMachine, theTaskTime);
        }
        mArray[firstMachine].jobQ.push(theJob);//将任务输入到机器的队列中
    }
}
/*启动仿真*/
void startShop()
{
    //在每台机器上装载其第一个任务
    for (int p = 1; p <= numMachines; p++)
        changeState(p);
}
/*修改机器状态*/
job* changeState(int theMachine)
{
    //机器theMachine上的工序完成了，调度下一道工序
    //返回值是在机器theMachine上刚刚完成的任务
    job* lastJob;
    if (mArray[theMachine].activeJob == nullptr)
    {
        //处于空闲或转换状态
        lastJob = nullptr;
        if (mArray[theMachine].jobQ.empty())//没有等待执行的任务
            eList->setFinishTime(theMachine, largeTime);
        else
        {
            //从队列中提取任务，在机器上执行
            mArray[theMachine].activeJob = mArray[theMachine].jobQ.front();
            mArray[theMachine].jobQ.pop();
            mArray[theMachine].totalWait += (timeNow - mArray[theMachine].activeJob->arrivalTime);
            mArray[theMachine].numTasks++;
            cout << "(" << mArray[theMachine].activeJob->taskQ.front().machine << "," << mArray[theMachine].activeJob->taskQ.front().time << ")" << "finished!" << endl;
            //cout << "timeNow = " << timeNow << endl;
            int t = mArray[theMachine].activeJob->removeNextTask();
            eList->setFinishTime(theMachine, timeNow + t);
        }
    }
    else
    {
        //在机器theMachine上刚刚完成一道工序
        //设置转换时间
        lastJob = mArray[theMachine].activeJob;
        mArray[theMachine].activeJob = nullptr;
        eList->setFinishTime(theMachine, timeNow + mArray[theMachine].changeTime);
    }
    return lastJob;
}
/*处理所有任务*/
void simulate()
{
    //处理所有未处理的任务
    while (numJobs > 0)
    {
        //至少有一个任务未处理
        int nextToFinish = eList->nextEventMachine();
        timeNow = eList->nextEventTime(nextToFinish);
        //cout << "sim timeNow = " << timeNow << endl;
        //改变机器nextToFinist上的任务
        job* theJob = changeState(nextToFinish);
        //把任务theJob调度到下一台机器
        //如果任务theJob完成，则减少任务数
        if (theJob != nullptr && !moveToNextMachine(theJob))
            numJobs--;
    }
}
/*把一项任务移至下一道工序对应的机器*/
bool moveToNextMachine(job* theJob)
{
    //调度任务theJob到执行其下一道工序的机器
    //如果任务已经完成，则返回false
    if (theJob->taskQ.empty())
    {
        cout << "Job " << theJob->id << " has completed at " << timeNow <<
             " Total wait was " << (timeNow - theJob->length) << endl;
        return false;
    }
    else
    {
        //任务theJob有下一道工序
        //确定执行下一道工序的机器
        int p = theJob->taskQ.front().machine;
        //把任务插入机器p的等待任务队列
        mArray[p].jobQ.push(theJob);
        theJob->arrivalTime = timeNow;
        //如果机器p空闲，则改变它的状态
        if (eList->nextEventTime(p) == largeTime)
            changeState(p);
        return true;
    }
}
/*输出每台机器的等待时间*/
void outputStatistics()
{
    cout << "Finish time = " << timeNow << endl;
    for (int p = 1; p <= numMachines; p++)
    {
        cout << "Machine " << p << " completed " << mArray[p].numTasks << " tasks" << endl;
        cout << "The total wait time was " << mArray[p].totalWait << endl;
        cout << endl;
    }
}