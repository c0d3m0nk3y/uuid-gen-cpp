#ifndef _UUID_H_
#define _UUID_H_

#include <string>

const std::string UUID_CHARS {"0123456789abcdef"};
const signed short UUID_LENGTH {32};

class Uuid {
  private:
    typedef unsigned long    unsigned32;
    typedef unsigned short   unsigned16;
    typedef unsigned char    unsigned8;
    typedef unsigned char    byte;

  protected:
    unsigned32        time_low {0};
    unsigned16        time_mid {0};
    unsigned16        time_high_and_version {0};
    unsigned8         clock_seq_and_reserved {0};
    unsigned8         clock_seq_low {0};
    byte              node[6] = {0};

  public:
    std::string asString(void);

};

std::string    generate_naive_uuid(void);
void           generate_random_uuid(Uuid *uuid);

#endif  // !_UUID_H_

