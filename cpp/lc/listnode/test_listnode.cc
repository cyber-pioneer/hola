#include <iostream>
#include <vector>

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(const int &value) : val(value), next(nullptr) {}
};

ListNode *construct_ln(std::vector<int> &data) {
  if (data.empty()) {
    return nullptr;
  }
  ListNode *head = new ListNode(data[0]);
  ListNode *cur = head;
  for (size_t i = 1; i < data.size(); i++) {
    ListNode *tmp = new ListNode(data[i]);
    cur->next = tmp;
    cur = cur->next;
  }
  return head;
}

void read_ln(ListNode *head) {
  ListNode *cur = head;
  while (cur) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> a = {1, 2, 3, 4, 5};
  auto *head = construct_ln(a);
  read_ln(head);
  read_ln(head);
  while (head != nullptr) {
    auto *tmp = head->next;
    delete head;
    head = tmp;
  }
  return 0;
}
