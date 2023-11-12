/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月17日09点22分
Last Version:			V1.0
Descriptions:			工厂仿真头文件
*/
#pragma once
#include <iostream>
#include "_1myExceptions.h"
#include "_22task.h"
#include "_22job.h"
#include "_22machine.h"
#include "_22eventList.h"
#ifndef _FACTORYSIM_H_
#define _FACTORYSIM_H_
/*测试函数*/
void factorySimTest();
/*输入工厂数据*/
void inputData();
/*启动仿真*/
void startShop();
/*修改机器状态*/
job* changeState(int theMachine);
/*处理所有任务*/
void simulate();
/*把一项任务移至下一道工序对应的机器*/
bool moveToNextMachine(job* theJob);
/*输出每台机器的等待时间*/
void outputStatistics();
#endif