/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月17日09点22分
Last Version:			V1.0
Descriptions:			事件
*/
#pragma once
#ifndef _EVENTLIST_H_
#define _EVENTLIST_H_
class eventList
{
public:
    /*为m台机器，初始化其完成时间*/
    eventList(int theNumMachines, int theLargeTime)
    {
        if (theNumMachines < 1)
            throw illegalParameterValue("number of machines must be >= 1");
        numMachines = theNumMachines;
        finishTime = new int[numMachines + 1];
        //所有机器都空闲，用大的完成时间初始化
        for (int i = 1; i <= numMachines; i++)
            finishTime[i] = theLargeTime;
    }

    /*返回值是处理下一项工序的机器,某个机器完成了*/
    int nextEventMachine()
    {
        int p = 1;
        int t = finishTime[1];
        for (int i = 2; i <= numMachines; i++)
        {
            if (finishTime[i] < t)
            {
                p = i;
                t = finishTime[i];
            }
        }
        return p;
    }
    /*知道处理下一项工序的机器，获取该机器的完成时间*/
    int nextEventTime(int theMachine)
    {
        return finishTime[theMachine];
    }
    /*设置机器的完成时间*/
    void setFinishTime(int theMachine, int theTime)
    {
        finishTime[theMachine] = theTime;
    }
private:
    int* finishTime;//机器完成时间数组
    int numMachines;//机器数量
};
#endif