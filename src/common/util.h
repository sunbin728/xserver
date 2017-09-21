#ifndef _UTIL_H_
#define _UTIL_H_

#include <string>

namespace util{
    std::string ToBinaryString(const char* buf,int len);
    std::string ToHexString(const char* buf,int len);
    std::string ToHexString_Simple(const char* buf,int len);
    std::string ToDecString(const char* buf,int len);

    int code_convert(std::string from_charset,std::string to_charset,char *inbuf,size_t inlen,char *outbuf,size_t outlen);
    int u2g(char *inbuf,int inlen,char *outbuf,size_t outlen);
    int g2u(char *inbuf,size_t inlen,char *outbuf,size_t outlen);
    template <typename type>
        inline type Atoi(const std::string& val)
        {
            return static_cast<type>(atoi(val.c_str()));
        }
}

#endif /* _UTIL_H_ */
