一般不建议使用new创建对象指针，因为需要手动调delete （或delete[]）销毁内存
推荐使用智能指针，常见智能指针有：
shared_ptr
unique_ptr
weak_ptr （使用频率较低）

在C++中，常见的智能指针类型主要包括std::unique_ptr、std::shared_ptr和std::weak_ptr。这些智能指针类型的主要区别体现在所有权管理、内存管理、安全性和性能等方面。以下是它们之间的详细区别：

所有权管理：

std::unique_ptr：独占式智能指针，对资源拥有唯一所有权。一旦创建unique_ptr，就不能创建指向同一资源的另一个unique_ptr。
std::shared_ptr：共享式智能指针，允许多个shared_ptr共同拥有同一个资源。通过引用计数来跟踪资源的引用次数，当最后一个shared_ptr销毁时，资源才会被释放。
std::weak_ptr：弱引用智能指针，不拥有资源，但可以观测一个被shared_ptr管理的资源。不会增加引用计数，也不会影响资源的生命周期。
内存管理：

std::unique_ptr：通过独占所有权，确保资源的释放。在unique_ptr超出作用域或被显式地删除时，会自动释放所拥有的资源。
std::shared_ptr：通过引用计数来管理资源的生命周期。当最后一个shared_ptr销毁且引用计数为零时，资源会被释放。
std::weak_ptr：不参与资源的内存管理，只是提供对资源的弱引用。
安全性：

std::unique_ptr和std::shared_ptr都提供了自动内存管理，能够避免内存泄漏和悬空指针的问题。
std::weak_ptr用于解决std::shared_ptr的循环引用问题，避免造成资源无法释放的情况。
性能：

std::unique_ptr：最轻量级的智能指针，没有引用计数的开销，性能开销较低。
std::shared_ptr：使用引用计数，需要维护引用计数的增加和减少，可能引入一定的性能开销。
std::weak_ptr：只是观测和提供访问资源的方式，对性能影响较小，但由于不直接参与内存管理，其性能开销通常可以忽略不计。
使用场景：

std::unique_ptr：适用于独占且无需共享的资源，确保资源在超出作用域时被正确释放。
std::shared_ptr：适用于需要共享资源的场景，如多个对象需要访问同一个资源时。
std::weak_ptr：通常与std::shared_ptr一起使用，用于解决循环引用问题，以及在不增加引用计数的情况下观察资源的存在性。
成员函数：

std::unique_ptr：提供release、reset、get等成员函数，用于管理所有权和访问原始指针。
std::shared_ptr：提供reset、use_count、unique等成员函数，用于管理引用计数和访问资源。
std::weak_ptr：提供lock、expired、use_count等成员函数，用于安全检查资源和转换为std::shared_ptr。
