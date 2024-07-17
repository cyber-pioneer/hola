#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>

std::unordered_map<int, int> key_indegree;
std::unordered_map<int, std::set<int>> indegree_keys;
std::unordered_map<int, std::set<int>> key_nexts;
std::list<std::pair<int, int>> link;

std::vector<int> res;

void prepare() {
  for (auto it : link) {
    int src = it.first;
    int next = it.second;
    key_nexts[src].insert(next);
    if (!key_indegree.count(src)) {
      key_indegree[src] = 0;
      indegree_keys[0].insert(src);
    }
    if (key_indegree.count(next)) {
      int cur_indegree = key_indegree[next];
      indegree_keys[cur_indegree].erase(next);
      indegree_keys[cur_indegree + 1].insert(next);
      key_indegree[next] = cur_indegree + 1;
    } else {
      key_indegree[next] = 1;
      indegree_keys[1].insert(next);
    }
  }
}

void sort(std::set<int> nodes) {
  if (!nodes.size()) {
    if (res.size() != key_indegree.size()) {
      std::cout << "exist cycle ***** " << std::endl;
      std::cout << "finished nodes: ";
      for (auto val : res) {
        std::cout << val << " ";
      }
      std::cout << std::endl;
      std::cout << "remained nodes: " << std::endl;
      for (auto it : indegree_keys) {
        std::cout << "indegree: node  " << it.first << " : ";
        for (auto remain : it.second) {
          std::cout << remain << " ";
        }
        std::cout << std::endl;
      }
    }
    return;
  };
  for (auto node : nodes) {

    res.push_back(node);
    if (key_nexts.count(node)) {

      for (auto next : key_nexts[node]) {
        int cur_indegree = key_indegree[next];
        key_indegree[next] = cur_indegree - 1;
        indegree_keys[cur_indegree].erase(next);
        indegree_keys[cur_indegree - 1].insert(next);
      }
    }
    indegree_keys[0].erase(node);
  }

  sort(indegree_keys[0]);
}

int main() {
  // src-->next
  // link = {{1, 2}, {1, 3}, {3, 2}, {2, 6}, {3, 6}, {2, 3}};
  link = {{1, 2}, {1, 3}, {3, 2}, {2, 6}, {3, 6}};
  prepare();

  sort(indegree_keys[0]);
  std::cout << "topo sort res: ";
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  return 0;
}
