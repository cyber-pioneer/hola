/**
 * @nc app=nowcoder id=5dfded165916435d9defb053c63f1e84 topic=295 question=2427094 lang=C++
 * 2024-06-26 13:03:37
 * https://www.nowcoder.com/practice/5dfded165916435d9defb053c63f1e84?tpId=295&tqId=2427094
 * [BM100] 设计LRU缓存结构
 */

/** @nc code=start */

class Solution {
    
    int capacity_;
    list<pair<int, int>> order;
    unordered_map<int, list<pair<int, int>>::iterator> record;

public:

 Solution(int capacity){
    capacity_ = capacity;
 // write code here
 }
 
 int get(int key) {
    if (!record.count(key)) {return -1;}
    auto it = *record[key];
    order.erase(record[key]);
    order.push_front(pair<int, int>(it.first, it.second));
    auto item = order.begin();
    record[key] = item;
    return it.second;


 // write code here
 }
 
 void set(int key, int value){
    if (record.count(key)) {
        order.erase(record[key]);
    } else if (capacity_ == order.size()) {
        record.erase(order.back().first);
        order.pop_back();
    }

    order.push_front(pair<int, int>(key, value));
    record[key] = order.begin();

 // write code here
 }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */

/** @nc code=end */
