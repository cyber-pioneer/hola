#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
public:
  Graph(int V);               // 构造函数，初始化顶点数量
  void addEdge(int v, int w); // 添加边
  bool hasCycle();            // 判断图中是否有环

private:
  vector<vector<int>> adj; // 邻接表表示图
  bool *visited;           // 访问标记数组
  bool *recStack;          // 递归栈标记数组

  bool isCyclicUtil(int v); // 递归辅助函数
};

Graph::Graph(int V) {
  adj.resize(V);
  visited = new bool[V];
  recStack = new bool[V];
  for (int i = 0; i < V; ++i) {
    visited[i] = false;
    recStack[i] = false;
  }
}

// Graph::~Graph() {
//     delete[] visited;
//     delete[] recStack;
// }

void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

bool Graph::isCyclicUtil(int v) {
  if (!visited[v]) {
    visited[v] = true;
    recStack[v] = true;

    for (int w : adj[v]) {
      if (!visited[w] && isCyclicUtil(w))
        return true;
      else if (recStack[w])
        return true;
    }
  }

  recStack[v] = false; // 回溯时标记为不在递归栈中
  return false;
}

bool Graph::hasCycle() {
  for (int i = 0; i < adj.size(); ++i) {
    if (!visited[i] && isCyclicUtil(i))
      return true;
  }
  return false;
}

int main() {
  Graph g(5); // 假设有5个顶点
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  g.addEdge(2, 1);
  g.addEdge(1, 2); // 添加一个环

  if (g.hasCycle()) {
    cout << "Graph contains cycle" << endl;
  } else {
    cout << "Graph does not contain cycle" << endl;
  }

  return 0;
}
