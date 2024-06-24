#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据层序遍历数组构建二叉树的函数
TreeNode *buildTreeFromLevelOrder(const vector<int> &levelOrder) {
  if (levelOrder.empty()) {
    return nullptr;
  }

  TreeNode *root = new TreeNode(levelOrder[0]); // 创建根节点
  queue<TreeNode *> q;
  q.push(root); // 将根节点加入队列

  int i = 1; // 从数组的第二个元素开始构建子树
  while (i < levelOrder.size()) {
    TreeNode *currentNode = q.front();
    q.pop();

    // 左子节点
    if (i < levelOrder.size() && levelOrder[i] != -1) { // 假设-1表示空节点
      currentNode->left = new TreeNode(levelOrder[i]);
      q.push(currentNode->left);
    }
    i++;

    // 右子节点
    if (i < levelOrder.size() && levelOrder[i] != -1) { // 假设-1表示空节点
      currentNode->right = new TreeNode(levelOrder[i]);
      q.push(currentNode->right);
    }
    i++;
  }

  return root; // 返回构建好的二叉树的根节点
}

// 用于测试的二叉树遍历函数（前序遍历）
void preorderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->val << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

int main() {
  // 层序遍历数组，其中-1表示空节点
  vector<int> levelOrder = {1, 2, 3, -1, -1, 4, 5};
  TreeNode *root = buildTreeFromLevelOrder(levelOrder);

  // 测试构建的二叉树是否正确（前序遍历输出）
  cout << "Preorder traversal of the constructed tree: ";
  preorderTraversal(root);
  cout << endl;

  // 注意：在实际应用中，需要适当地释放动态分配的内存。

  return 0;
}
