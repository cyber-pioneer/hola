#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
public:
  Graph(int V);               // 构造函数，初始化顶点数量
  void addEdge(int v, int w); // 添加边
  bool hasCycleUtil(int v, unordered_set<int> &visited); // 递归辅助函数
  bool hasCycle(); // 判断图中是否有环

private:
  vector<vector<int>> adj; // 邻接表表示图
};

Graph::Graph(int V) { adj.resize(V); }

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  // 无向图的话，需要添加反向边
  // adj[w].push_back(v);
}

bool Graph::hasCycleUtil(int v, unordered_set<int> &visited) {
  if (visited.find(v) != visited.end()) {
    // 如果节点已经被访问过，则存在环
    return true;
  }
  std::cout << "visit node **** " << v << std::endl;
  visited.insert(v); // 标记节点为已访问

  // 遍历邻接节点
  for (int neighbour : adj[v]) {
    if (hasCycleUtil(neighbour, visited)) {
      // 如果邻接节点中存在环，则当前节点所在的图也存在环
      return true;
    }
  }

  // 如果没有找到环，返回false
  return false;
}

bool Graph::hasCycle() {
  unordered_set<int> visited;
  for (int i = 0; i < adj.size(); ++i) {
    if (!visited.count(i) && hasCycleUtil(i, visited)) {
      // 如果图中任一未访问过的节点开始搜索能找到环，则返回true
      return true;
    }
  }
  // 所有节点都访问过且未找到环，则返回false
  return false;
}

int main() {
  Graph g(4); // 假设有5个顶点
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  // g.addEdge(1, 0);// 添加一个环
  g.addEdge(1, 3);
  // g.addEdge(2, 3);
  // g.addEdge(2, 1);
  // g.addEdge(4, 0); // 添加一个环

  if (g.hasCycle()) {
    cout << "Graph contains cycle" << endl;
  } else {
    cout << "Graph does not contain cycle" << endl;
  }

  return 0;
}
