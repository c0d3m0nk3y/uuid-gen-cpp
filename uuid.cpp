#include "uuid.h"

std::string Uuid::asString(void) {
  std::string tl = std::to_string(time_low);
  std::string tm = std::to_string(time_mid);
  std::string th = std::to_string(time_high_and_version);
  std::string csr = std::to_string(clock_seq_and_reserved);
  std::string csl = std::to_string(clock_seq_low);
  std::string n {};
  for (byte b: node)
    n += b;

  return tl + "-" + tm + "-" + th + "-" + csr + csl + "-" + n;
}

std::string generate_naive_uuid(void) {
  std::string uuid ("", UUID_LENGTH);
  for (size_t i {0}; i < UUID_LENGTH; ++i)
    uuid.at(i) = UUID_CHARS.at(std::rand() /  ((RAND_MAX + 1u) / 16));
  uuid.insert(20, "-");
  uuid.insert(16, "-");
  uuid.insert(12, "-");
  uuid.insert(8, "-");
  return uuid;
}

void generate_random_uuid(Uuid *uuid) {

}
