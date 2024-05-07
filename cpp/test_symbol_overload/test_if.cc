// Copyright (c) 2024 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>

class MyClass {
 public:
  explicit MyClass(int data = 0) : some_condition(data) {}
  // if operator bool not defined, it will raise error: could not convert ‘a’
  // from ‘MyClass’ to ‘bool’
  explicit operator bool() const { return some_condition > 0; }

 private:
  int some_condition;
};

int main() {
  MyClass a(2);
  if (a) {
    std::cout << " true ====" << std::endl;
    // 如果 a 的 some_condition 为 true，则执行此代码块
  } else {
    std::cout << " false ====" << std::endl;
  }

  MyClass b(-1);
  if (b) {
    std::cout << " true ====" << std::endl;
    // 如果 a 的 some_condition 为 true，则执行此代码块
  } else {
    std::cout << " false ====" << std::endl;
  }

  return 0;
}
