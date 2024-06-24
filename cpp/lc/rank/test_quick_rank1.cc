#include <iostream>
#include <vector>
#include <algorithm>


void dfs(std::vector<int> &res, int l, int r){
    if (l == r ) return;
    int mid = 0;
    while (l<r)
    dfs(res, l, mid);
    dfs(res, mid, r);
}

void rank(std::vector<int> &x) {

 return;
}

int main() {
    std::vector<int> x = {2,3,8,6,4,9, 1,3,5, 8};
    rank(x);
    for (int &item: x) {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
    
}

2,3,6,8,4,2
2,3,8,6,4,2
2,3,