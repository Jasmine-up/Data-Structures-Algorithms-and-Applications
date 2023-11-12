/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月17日09点22分
Last Version:			V1.0
Descriptions:			工序：包括执行该工序的机器machine和完成该工序所需要的时间time
*/
#pragma once
#ifndef _TASK_H_
#define _TASK_H_
#include<iostream>
using std::ostream;
/*工序：包括执行该工序的机器machine和完成该工序所需要的时间time*/
struct task
{
    int machine;
    int time;
    task(int theMachine = 0, int theTime = 0)
    {
        machine = theMachine;
        time = theTime;
    }
    friend ostream& operator<<(ostream& out, const task x)
    {
        out << "(" << x.machine << "," << x.time << ")";
        return out;
    }
};
#endif