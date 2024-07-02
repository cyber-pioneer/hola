#include <vector>
#include <iostream>
 
 
void mergeSort(std::vector<int> &x, int l, int r) {
    
    if (l>=r) return;
    std::vector<int> tmp;
    int mid = (l+r)/2;
    int i = l;
    int j = mid+1;
    int k = 0;
    mergeSort(x, l, mid);
    mergeSort(x, mid+1, r);
    while (i <= mid && j<= r) {
        if (x[i]< x[j]) {
            tmp.push_back(x.at(i++));
        } else {
            tmp.push_back(x.at(j++));
        }
    }
    while (i<=mid) {
        tmp.push_back(x[i++]);
    }
    while (j<=r) {
        tmp.push_back(x[j++]);
    }
    std::cout<<"**** 0 "<<tmp.size()<<" "<<(r-l+1)<<std::endl;
    for (int m=0, n=l; m<tmp.size(); m++, n++) {
        x[n] = tmp[m];
    }
}


int main() {
    std::vector<int> data = {4, 3, 2, 10, 12, 1, 2,3,5, 6};
    mergeSort(data, 0, data.size() - 1);
 
    for(int num : data) {
        std::cout << num << " ";
    }
 
    return 0;
}