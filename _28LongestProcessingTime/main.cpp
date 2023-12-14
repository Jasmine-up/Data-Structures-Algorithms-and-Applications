#include <iostream>
#include <queue>
#include <vector>

// ��ʾ������id��ʾ������id��avail��ʾ����ʲôʱ���п�
struct machineNode {
    int avail;
    int id;

    machineNode() {
        avail = 0;
        id = 0;
    }

    machineNode(int pid, int pavail) {
        avail = pavail;
        id = pid;
    }

    explicit operator int() const { return avail; }

    bool operator>(const machineNode &a) const { return avail > a.avail; }
};

// ��ʾ����id��ʾ�����id��time��ʾ��ҵ��Ҫ�Ĵ���ʱ��
struct jobNode {
    int id;
    int time;

    jobNode() {
        id = 0;
        time = 0;
    }

    jobNode(int pid, int ptime) {
        id = pid;
        time = ptime;
    };

    explicit operator int() const { return time; }

    bool operator<(const jobNode &a) const { return time < a.time; }
};

int main() {
    // �����㷨��ʱ�临�Ӷ�ΪO(logn)
    // ��ʼ����������,��ʼ��ʱ��ΪO(taskVec.size()==n)
    const std::vector<jobNode> taskVec = {jobNode(1, 2), jobNode(2, 14), jobNode(3, 4), jobNode(4, 16), jobNode(5, 6),
                                          jobNode(6, 5), jobNode(7, 3)};
    std::priority_queue<jobNode, std::vector<jobNode>> tasks(taskVec.begin(), taskVec.end());
    // ��ʼ������С���ѣ���ʼ��ʱ��ΪO(machineVec.size()==m)
    const std::vector<machineNode> machineVec = {machineNode{1, 0}, machineNode{2, 0}, machineNode{3, 0}};
    std::priority_queue<machineNode, std::vector<machineNode>, std::greater<>> machines(machineVec.begin(),
                                                                             machineVec.end());
    // ִ����2n��top��2n�� pop��2n�� push������ÿ��top��ʱ����0(1)��machines��pop��push��ʱ����O(logm)��tasks��pop��push��ʱ����O(logn)��
    // ��˴�forѭ����ʱ�临�Ӷ�ΪO(nlogn)
    for (int i = 0; i < taskVec.size(); i++) {
        machineNode temp = machines.top();
        machines.pop();
        jobNode taskNode = tasks.top();
        tasks.pop();
        std::cout << "Schedule job " << taskNode.id << " on machine " << temp.id << " from " << temp.avail << " to "
                  << (temp.avail + taskNode.time) << std::endl;
        temp.avail += taskNode.time;
        machines.push(temp);
    }
    std::cout << std::endl;
    return 0;
}
