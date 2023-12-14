#include <iostream>
#include <queue>
#include <vector>

// 表示机器，id表示机器的id，avail表示机器什么时候有空
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

// 表示任务，id表示任务的id，time表示作业需要的处理时间
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
    // 整个算法的时间复杂度为O(logn)
    // 初始化任务大根堆,初始化时间为O(taskVec.size()==n)
    const std::vector<jobNode> taskVec = {jobNode(1, 2), jobNode(2, 14), jobNode(3, 4), jobNode(4, 16), jobNode(5, 6),
                                          jobNode(6, 5), jobNode(7, 3)};
    std::priority_queue<jobNode, std::vector<jobNode>> tasks(taskVec.begin(), taskVec.end());
    // 初始化机器小根堆，初始化时间为O(machineVec.size()==m)
    const std::vector<machineNode> machineVec = {machineNode{1, 0}, machineNode{2, 0}, machineNode{3, 0}};
    std::priority_queue<machineNode, std::vector<machineNode>, std::greater<>> machines(machineVec.begin(),
                                                                             machineVec.end());
    // 执行了2n次top、2n次 pop和2n次 push操作，每次top的时间是0(1)，machines的pop和push的时间是O(logm)，tasks的pop和push的时间是O(logn)。
    // 因此此for循环的时间复杂度为O(nlogn)
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
