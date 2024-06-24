#include <iostream>
#include <queue>
using namespace std;

// 二叉树节点定义
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 层序遍历函数
void levelOrderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  queue<TreeNode *> q;
  q.push(root); // 将根节点入队

  while (!q.empty()) {
    TreeNode *node = q.front(); // 获取队首节点
    q.pop();                    // 出队
    cout << node->val << " ";   // 处理当前节点

    if (node->left) {
      q.push(node->left); // 左子节点入队
    }
    if (node->right) {
      q.push(node->right); // 右子节点入队
    }
  }
}

// 测试代码
int main() {
  // 构建一个简单的二叉树作为示例
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // 执行层序遍历
  cout << "Level order traversal: ";
  levelOrderTraversal(root);
  cout << endl;

  // 清理内存（在实际应用中需要适当释放动态分配的内存）
  // ...

  return 0;
}
