/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月17日09点22分
Last Version:			V1.0
Descriptions:			任务
*/
#pragma once
#ifndef _JOB_H_
#define _JOB_H_
#include <queue>
#include "_22task.h"
/*任务*/
struct job
{
    queue<task> taskQ;//任务的工序队列
    int length;//被调度的工序时间之和
    int arrivalTime;//到达当前队列的时间
    int id;//任务标识符
    job(int theId = 0)
    {
        id = theId;
        length = 0;
        arrivalTime = 0;
    }
    void addTask(int theMachine, int theTime)
    {//添加任务
        task theTask(theMachine, theTime);
        taskQ.push(theTask);
    }
    /*删除任务的下一道工序，返回它的时间；更新长度*/
    int removeNextTask()
    {
        int theTime = taskQ.front().time;
        taskQ.pop();
        length += theTime;
        return theTime;
    }
};
#endif