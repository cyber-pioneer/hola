#include <chrono>
#include <iostream>
#include <vector>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    // 执行一些操作
    std::vector<int> aa(100000000);
    for (int i = 0;i<aa.size();i++){
        aa[i] = i*i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "vector [] Time taken: " << diff.count() << " s\n";

    auto start2 = std::chrono::high_resolution_clock::now();
    // 执行一些操作
    std::vector<int> bb(100000000);
    for (int i = 0;i<bb.size();i++){
        bb.at(i) = i*i;
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    std::cout << "vector .at Time taken: " << diff2.count() << " s\n";

    return 0;
}

// vector [] Time taken: 1.06215 s
// vector .at Time taken: 1.99124 s
