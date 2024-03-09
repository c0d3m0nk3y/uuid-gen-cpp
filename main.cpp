#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

const std::string UUID_CHARS {"0123456789abcdef"};
const signed short UUID_LENGTH {32};

int main (int argc, char *argv[]) {
  std::srand(std::time(nullptr));

  std::string uuid ("", UUID_LENGTH);
  for (size_t i {0}; i < UUID_LENGTH; ++i)
    uuid.at(i) = UUID_CHARS.at(std::rand() /  ((RAND_MAX + 1u) / 16));
  uuid.insert(20, "-");
  uuid.insert(16, "-");
  uuid.insert(12, "-");
  uuid.insert(8, "-");

  std::cout << uuid << std::endl;
  
  return 0;
}
