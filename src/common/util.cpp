#include "util.h"

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


}
