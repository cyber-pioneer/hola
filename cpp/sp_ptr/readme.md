一般不建议使用new创建对象指针，因为需要手动调delete （或delete[]）销毁内存
推荐使用智能指针，常见智能指针有：
shared_ptr
unique_ptr
weak_ptr （使用频率较低）
