#include <iostream>
using namespace std;

class MyInt {
public:
    MyInt(int* pdNum) {
        cout<<"in MyInt(int*)"<<endl;
        m_pdNum=pdNum;
    }
    int getMyInt() const {
        return *m_pdNum;
    }
    ~MyInt() {
        cout<<"in ~MyInt()"<<endl;
        if(m_pdNum) {
            delete m_pdNum;
        }
    }
private:
    int* m_pdNum;
};

void print(MyInt objMyInt) {
    cout<<"in print_MyInt"<<endl;
    cout<<objMyInt.getMyInt()<<endl;
}

int main() {
    int* pdNum = new int(666);
    print(pdNum);               // 意外的被隐式转换为 MyInt 对象。
    cout<<" pdNum " << pdNum<<" "<<*pdNum<<endl;
    // delete pdNum;
    int* pdNewNum=new int(888);
    cout<<" pdNewNum " << pdNewNum<<" "<<*pdNewNum<<endl;
    // cout<<"=========== "<<endl;
    // *pdNum=16;
    // cout<<*pdNewNum<<endl;      // 应该输出 888，结果为 16。
}
