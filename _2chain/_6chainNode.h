/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��22��06��
Last Version:			V1.0
Descriptions:			����Ľ��
*/
#pragma once
#ifndef _CHAINNODE_H_
#define _CHAINNODE_H_
template <class T>
struct chainNode
{
	//���ݳ�Ա
	T element;
	chainNode<T>* next;
	//����
	chainNode() {}
	chainNode(const T& element)
	{
		this->element = element;
		this->next = nullptr;
	}

	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};
#endif