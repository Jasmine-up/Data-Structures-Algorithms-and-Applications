#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::vector<int> data = {1, 5, 6, 99, 88, 66};
    std::vector<int> res(data.size());
    // 使用数组初始化小根堆
    std::priority_queue<int, std::vector<int>, std::greater<>> pq(data.begin(), data.end());
    for(int i = 0; i < data.size(); i++){
        res[i] = pq.top();
        pq.pop();
    }
    for(int re : res)
        std::cout << re << " ";
    std::cout << std::endl;
    return 0;
}
