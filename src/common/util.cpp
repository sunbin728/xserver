#include "util.h"
#include <memory.h>
#include <iconv.h>

namespace util{
    std::string ToBinaryString(const char* buf,int len){
        int output_len = len*8;
        std::string output;
        const char* m[] = {"0","1"};

        for(int i = output_len - 1,j = 0; i >=0 ; --i,++j){
            output.append(m[((uint8_t)buf[j/8] >> (i % 8)) & 0x01],1);
        }
        return output;
    }

    std::string ToHexString_Simple(const char* buf,int len){
        std::string output;
        char temp[8];
        for (int i = 0; i < len; ++i){
            sprintf(temp,"%.2X",(uint8_t)buf[i]);
            output.append(temp,2);
        }
        return output;
    }

    std::string ToHexString(const char* buf,int len){
        std::string output = "0X[";
        char temp[8];
        for (int i = 0; i < len; ++i){
            int len = sprintf(temp,"%.2X ",(uint8_t)buf[i]);
            output.append(temp,len);
        }
        return output+"]";
    }

    std::string ToDecString(const char* buf,int len){
        std::string output = "[";
        char temp[8];
        for (int i = 0; i < len; ++i){
            int len = sprintf(temp,"%.2d ",(uint8_t)buf[i]);
            output.append(temp,len);
        }
        return output+"]";
    }


    int code_convert(std::string from_charset,std::string to_charset,char *inbuf,size_t inlen,char *outbuf,size_t outlen){
        iconv_t cd;
        //int rc;
        char **pin = &inbuf;
        char **pout = &outbuf;
        cd = iconv_open(to_charset.c_str(),from_charset.c_str());
        if (cd==0)
            return -1;
        memset(outbuf,0,outlen);
        if (iconv(cd,pin,&inlen,pout,&outlen) == -1)
            return -1;
        iconv_close(cd);
        return 0;
    }

    int u2g(char *inbuf,int inlen,char *outbuf,size_t outlen){
        return code_convert("utf-8","gb2312",inbuf,inlen,outbuf,outlen);
    }

    int g2u(char *inbuf,size_t inlen,char *outbuf,size_t outlen){
        return code_convert("gb2312","utf-8",inbuf,inlen,outbuf,outlen);
    }
}
