#include <iostream>
#include <vector>


void fn(std::vector<int> &a, int n)

{
	int i,j,m;

for(i=1; i<n; i++) {
    for(j=0; j<i; j++)

        { 
            m=a[i*n+j];  // a[i*n+j]与A[j*n+i]值交换

            a[i*n+j]=a[j*n+i]; 

            a[j*n+i]=m; 

        }
    }

}

int main() {
    std::vector<int> x = {0,1,2,3,4,5,6,7,8,9,10,11};
    fn(x, 4);
    for (auto &i: x) {
        std::cout<<i<<" ";
    }
}
