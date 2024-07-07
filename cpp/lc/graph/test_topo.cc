#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

// 使用邻接表表示图
vector<list<int>> graph;
// 存储每个顶点的入度
vector<int> indegree;

// 拓扑排序函数
bool topologicalSortUtil(int v, vector<int>& sortOrder) {
    // 标记当前节点为已访问
    indegree[v] = -1;

    // 遍历所有邻接节点
    for (auto it = graph[v].begin(); it != graph[v].end(); ++it) {
        int node = *it;

        // 如果邻接节点未被访问且存在环（入度未减到0）
        if (indegree[node] >= 0 && !topologicalSortUtil(node, sortOrder)) {
            return false;
        }
    }

    // 将当前节点添加到结果排序中
    sortOrder.push_back(v);
    return true;
}

// 拓扑排序主函数
bool topologicalSort(int V) {
    // 初始化入度数组和结果排序数组
    indegree.resize(V, 0);
    vector<int> sortOrder;

    // 遍历所有边，计算每个节点的入度
    for (int i = 0; i < V; ++i) {
        for (auto it = graph[i].begin(); it != graph[i].end(); ++it) {
            indegree[*it]++;
        }
    }

    // 遍历所有节点，如果节点入度为0，则递归访问其邻接节点
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0 && !topologicalSortUtil(i, sortOrder)) {
            return false; // 如果图中存在环，则返回false
        }
    }

    // 如果排序数组的长度与节点数相同，说明没有环，输出排序结果
    if (sortOrder.size() == V) {
        for (int i = sortOrder.size() - 1; i >= 0; --i) {
            cout << sortOrder[i] << " ";
        }
        cout << endl;
        return true;
    }

    return false; // 图中存在环
}

int main() {
    // 创建一个有5个节点的图
    int V = 5;
    graph.resize(V);

    // 添加边（注意：拓扑排序的边是从尾指向头）
    graph[1].push_back(0);
    graph[2].push_back(0);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[4].push_back(2);

    // 调用拓扑排序函数
    if (topologicalSort(V)) {
        cout << "Topological Sort: ";
    } else {
        cout << "Graph contains cycle!";
    }

    return 0;
}