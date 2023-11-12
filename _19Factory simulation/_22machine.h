/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月17日09点22分
Last Version:			V1.0
Descriptions:			机器
*/
#pragma once
#ifndef _MACHINE_H_
#define _MACHINE_H_
#include<queue>
#include "_22job.h"
/*机器*/
struct machine
{
    queue<job*> jobQ;//本机器的等待处理的任务队列
    int changeTime;//本机器的转换时间
    int totalWait;//本机器的总体延时
    int numTasks;//本机器处理的工序数量
    job* activeJob;//本机器当前处理的任务
    machine()
    {
        changeTime = 0;
        totalWait = 0;
        numTasks = 0;
        activeJob = nullptr;
    }
};
#endif