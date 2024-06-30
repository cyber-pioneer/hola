// https://www.jb51.net/article/222719.htm#_label1


/**
 * @nc app=nowcoder id=93aacb4a887b46d897b00823f30bfea1 topic=295 question=1006014 lang=C++
 * 2024-06-28 12:57:17
 * https://www.nowcoder.com/practice/93aacb4a887b46d897b00823f30bfea1?tpId=295&tqId=1006014
 * [BM101] 设计LFU缓存结构
 */

/** @nc code=start */

class Solution {
    unordered_map<int, pair<int, int>> key_val_freq;
    unordered_map<int, list<int>> freq_key;
    unordered_map<int, list<int>::iterator> key_it;
    int cap;
    int min_freq=0;

public:
    void set(int &key, int &value) {
        if (key_val_freq.count(key)) {
            auto it = key_it[key];
            auto detail = key_val_freq[key];
            freq_key[detail.second].erase(it);
            freq_key[detail.second+1].push_front(key);
            key_val_freq[key] = pair<int, int>(value, detail.second+1);
            key_it[key] = freq_key[detail.second+1].begin();
            if (min_freq == detail.second && freq_key[detail.second].empty()) {
                min_freq++;
            }
            return;
        } 
        if (cap == key_val_freq.size()) {
            auto rm_key = freq_key[min_freq].back();
            freq_key[min_freq].pop_back();
            key_it.erase(rm_key);
            key_val_freq.erase(rm_key);
        }
        min_freq = 1;
        freq_key[min_freq].push_front(key);
        key_it[key] = freq_key[min_freq].begin();
        key_val_freq[key] = pair<int, int>(key, min_freq); 
        


    }

    int get(int &key) {

        if (!key_val_freq.count(key)) {
            return -1;
        } else {
            auto it = key_it[key];
            auto detail = key_val_freq[key];
            
            freq_key[detail.second].erase(it);
            if (min_freq == detail.second && freq_key[detail.second].empty()) {
                min_freq++;
            }
            freq_key[detail.second+1].push_front(key);
            key_val_freq[key] = pair<int, int>(detail.first, detail.second+1);
            key_it[key] = freq_key[detail.second+1].begin();
            return detail.first;
        }

    }
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

