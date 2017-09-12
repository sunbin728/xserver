#include <string>

namespace util{
    std::string ToBinaryString(const char* buf,int len);
    std::string ToHexString(const char* buf,int len);
    std::string ToDecString(const char* buf,int len);
}
