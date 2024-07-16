#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<set>


std::unordered_map<int, int> key_freq;
std::unordered_map<int, std::set<int>> freq_keys;
std::unordered_map<int, std::set<int>> key_nexts;
std::list<std::pair<int, int>> link;

std::vector<int> res;

void prepare() {
    for (auto it: link) {
        int src = it.first;
        int next = it.second;
        key_nexts[src].insert(next);
        if (!key_freq.count(src)) {
            key_freq[src] = 0;
            freq_keys[0].insert(src);
        }
        if (key_freq.count(next)) {
            int cur_freq = key_freq[next];
            freq_keys[cur_freq].erase(next);
            freq_keys[cur_freq+1].insert(next);
            key_freq[next] = cur_freq+1;
        } else {
            key_freq[next] = 1;
            freq_keys[1].insert(next);
        }
    }
}

void sort(std::set<int> &nodes) {
    std::cout<<key_freq.size()<<freq_keys.size()<<key_nexts.size()<<std::endl;
    if (!nodes.size()) {
        if (res.size() != key_freq.size()) {
            std::cout<<"exist cycle ***** "<< std::endl;
        }
        std::cout<<"res.size ***** "<< res.size()<<std::endl;
        return;
    };
    std::cout<<"nodes.size ***** "<< nodes.size()<<std::endl;
    for (auto node: nodes) {
        std::cout<<"res.size *****-1 "<< res.size()<<std::endl;
    
        res.push_back(node);
        if (key_nexts.count(node)) {
            
            for (auto next: key_nexts[node]) {
                std::cout<<"res.size *****0 "<< res.size()<<std::endl;
                int cur_freq = key_freq[next];
                key_freq[next] = cur_freq-1;
                freq_keys[cur_freq].erase(next);
                freq_keys[cur_freq-1].insert(next);
                std::cout<<"res.size *****1 "<< res.size()<<std::endl;
            }
        }
        std::cout<<"res.size *****2 "<< res.size()<<std::endl;
        freq_keys[0].erase(node);
        std::cout<<"res.size *****3 "<< res.size()<<std::endl;

    }
    std::cout<<"res.size *****4 "<< res.size()<<std::endl;
    sort(freq_keys[0]);
}




int main() {
    link = {{1,2}, {1,3}, {3,2},{2,6},{3,6}};
    prepare();
    for (auto item: res) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;

    sort(freq_keys[0]);
    return 0;
}



