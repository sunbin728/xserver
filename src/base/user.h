#include <string>

using namespace std;

class User{
    public:
        User():uid(0),uname(),password(),createtime(0){}
        int64_t uid;
        string uname;
        string password;
        uint64_t createtime;
};

