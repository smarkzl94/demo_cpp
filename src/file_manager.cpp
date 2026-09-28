#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>

class FileManager {
public:
  FileManager(const std::string &filename, const char *mode = "r")
      : file_(std::fopen(filename.c_str(), mode), &std::fclose) {
    if (!file_) {
      throw std::runtime_error("Failed to open file: " + filename);
    }
  }

private:
  std::unique_ptr<FILE, int (*)(FILE *)> file_;
};

int main() {
  return 0;
}
