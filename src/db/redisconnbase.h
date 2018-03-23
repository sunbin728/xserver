#ifndef _REDISCONNBASE_H_
#define _REDISCONNBASE_H_

#include <string>
#include <hiredis/hiredis.h>

using namespace std;

class RedisReply{
    public:
        RedisReply(redisReply* reply, int err=0, string errstr=""):
            m_reply(reply),
            m_err(err),
            m_errstr(errstr){

            }

        ~RedisReply(){
            if (m_reply!=NULL){
                freeReplyObject(m_reply);
            }
        }

        redisReply* operator->(){
            return m_reply;
        }

        int Err(){
            return m_err;
        }

        string ErrStr(){
            return m_errstr;
        }

    private:
        redisReply* m_reply;
        int m_err;
        string m_errstr;
};



class RedisConnBase{
    public:
        RedisConnBase();
        virtual ~RedisConnBase();
        RedisConnBase(const RedisConnBase &conn);
        RedisConnBase& operator=(const RedisConnBase &conn);

    public:
        virtual bool Init()=0;
        virtual RedisReply ExecCmd(string cmd)=0;
};

#endif /* _REDISCONNBASE_H_ */
