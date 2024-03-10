#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>

const std::string UUID_CHARS {"0123456789abcdef"};
const signed short UUID_LENGTH {32};

void generate_time_based_uuid(std::string &uuid) {}
void generate_name_based_uuid(std::string &uuid) {}
void generate_random_uuid(std::string &uuid);
void insert_uuid_separators(std::string &uuid);
void print_usage(const char* argv0);

int main (int argc, char *argv[]) {
  std::srand(std::time(nullptr));

  std::string uuid ("", UUID_LENGTH);

  if (argc != 2) {
    print_usage(argv[0]);
    return 0;
  }

  if (std::strcmp(argv[1], "-r") == 0)
    generate_random_uuid(uuid);
  else {
    print_usage(argv[0]);
    return 0;
  }

  insert_uuid_separators(uuid);
  std::cout << uuid << std::endl;
  
  return 0;
}

void generate_random_uuid(std::string &uuid) {
  for (size_t i {0}; i < UUID_LENGTH; ++i)
    uuid.at(i) = UUID_CHARS.at(std::rand() /  ((RAND_MAX + 1u) / 16));
}

void insert_uuid_separators(std::string &uuid) {
  uuid.insert(20, "-");
  uuid.insert(16, "-");
  uuid.insert(12, "-");
  uuid.insert(8, "-");
}

void print_usage(const char* argv0) {
  std::cout << ""
    "Usage: " << argv0 << " [OPTION]\n"
    "Generates a UUID as defined in RFC4122"
    "\n\n"
    "  -h  Display this help"
    "\n"
    "  -n  Generate a Name-Based UUID"
    "\n"
    "  -r  Generate a UUID from Psuedo-Random Numbers"
    "\n"
    "  -t  Generate a Time-Based UUID"
    "\n";
}
