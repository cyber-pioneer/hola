/**
 * @nc app=nowcoder id=93aacb4a887b46d897b00823f30bfea1 topic=295 question=1006014 lang=C++
 * 2024-06-28 12:57:17
 * https://www.nowcoder.com/practice/93aacb4a887b46d897b00823f30bfea1?tpId=295&tqId=1006014
 * [BM101] 设计LFU缓存结构
 */

/** @nc code=start */

class Solution {
    int cap;
    int min_freq;
    std::unordered_map<int, std::pair<int, int> > key_val_freq;
    std::unordered_map<int, std::list<int> > freq_key;
    std::unordered_map<int, std::list<int>::iterator> key_it;

public:

    int get(int key) {
        // If key doesn't exist
        if (key_val_freq.find(key) == key_val_freq.end() ) {
            return -1;
        }
        // if key exists, increse frequency and reorder
        increaseFreq(key);
        return key_val_freq[key].first;
    }

    void set(int key, int value) {
        if (cap <= 0) { return; }
        // if key exists
        if (key_val_freq.count(key) ) {
            key_val_freq[key].first = value;
            increaseFreq(key);
            return;
        }
        // if key doesn't exist
        // if reached hashmap's max capacity, remove the LFU (LRU if tie)
        if (key_val_freq.size() >= cap) {
            int keyToRmove = freq_key[min_freq].back();
            freq_key[min_freq].pop_back();
            key_it.erase(keyToRmove);
            key_val_freq.erase(keyToRmove);
        }
        // Then add new item with frequency = 1
        addNewTask(key, value);
    }

    void increaseFreq(int key) {
        // Update the freq in the pair
        int oldFreq = key_val_freq[key].second++;

        // Detele the old freq by itr
        freq_key[oldFreq].erase(key_it[key]);
        // Add the new freq and re-assign the itr
        freq_key[oldFreq + 1].emplace_front(key);
        key_it[key] = freq_key[oldFreq + 1].begin();

        // Update minFreq
        if (freq_key[min_freq].empty() ) {
            min_freq = oldFreq + 1;
        }
    }

    void addNewTask(int key, int value) {
        // Add new key-value/freq to all hashmaps
        min_freq = 1;
        key_val_freq[key] = std::make_pair(value, min_freq);
        freq_key[min_freq].emplace_front(key);
        key_it[key] = freq_key[min_freq].begin();
    }

// n = item number of the LFU, aka capacity
// Time: O(1)
// Space: O(n)


    vector<int> LFU(vector<vector<int> >& operators, int k) {
        cap = k;
        vector<int> res;
        int i=0;
        for (auto &item: operators){

            if (item[0] == 1) {
                set(item[1], item[2]);
            } else {
                res.push_back(get(item[1]));
            }
            i++;
        }
        return res;

        // write code here
    }
};

/** @nc code=end */
