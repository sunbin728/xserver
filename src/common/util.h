#ifndef _UTIL_H_
#define _UTIL_H_

#include <string>

namespace util{
    std::string ToBinaryString(const char* buf,int len);
    std::string ToHexString(const char* buf,int len);
    std::string ToHexString_Simple(const char* buf,int len);
    std::string ToDecString(const char* buf,int len);
}

#endif /* _UTIL_H_ */
