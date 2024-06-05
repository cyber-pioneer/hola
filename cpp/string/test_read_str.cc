#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string getFileContent(const std::string &filePath) {
  std::ifstream file(filePath); // 创建输入文件流对象并打开文件

  if (!file.is_open()) { // 检查文件是否成功打开
    std::cerr << "Unable to open file: " << filePath << std::endl;
    return ""; // 返回空字符串表示失败
  }

  std::ostringstream contentStream; // 创建输出字符串流对象用于存储文件内容
  contentStream << file.rdbuf(); // 将整个文件内容读入到字符串流中
  std::string content = contentStream.str(); // 从字符串流中获取字符串

  file.close();   // 关闭文件
  return content; // 返回文件内容
}

int main() {
  std::string filePath =
      "/mnt/pd/verify/mine/hola/cpp/string/tr.log"; // 替换为你的文件路径
  std::string content = getFileContent(filePath);

  if (!content.empty()) {
    std::cout << "File content:\n" << content << std::endl;
  } else {
    std::cout << "Failed to read file content." << std::endl;
  }

  return 0;
}
