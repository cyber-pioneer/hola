#include <vector>
#include <iostream>
 
void merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
 
    while(i <= mid && j <= right)
        temp[k++] = vec[i] <= vec[j] ? vec[i++] : vec[j++];
 
    while(i <= mid)
        temp[k++] = vec[i++];
    
    while(j <= right)
        temp[k++] = vec[j++];
    
    for(k = 0, i = left; i <= right; ++i, ++k)
        vec[i] = temp[k];
}
 
void mergeSort(std::vector<int>& vec, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
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