#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> fn(std::vector<int> &data, int m, int n) {
    // if (x.size() != m*n) return {}
    std::vector<int> res(m*n);
    std::cout<<"res size*** "<<res.size()<<std::endl;
    for (int i=0; i<data.size(); i++) {
        int x = i/n;
        int y = i%n;
        res[y*m+x] = data[i];
        // std::swap(data[i], data[y*m+x]);
    }
    return res;
}


int main() {
    int m=3;
    int n=4;
    std::vector<int> data;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            data.push_back(i*n + j);
        }
    }
    for (auto &it: data) {
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;


    auto res = fn(data, m, n);

    std::cout<<std::endl;

    for (auto &it: res) {
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}

// [0 1 2 3 4 5 6 7 8 9 10 11] (m*n: 3*4)
// origin array point: (x, y) 
// 1-vector : idx = x * n + y
// after trans: [0 4 8 1 5 9 2 6 10 3 7 11] (n*m: 4*3)
// new point: (y,x)
// new idx: y * m + x
