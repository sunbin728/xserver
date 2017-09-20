#ifndef __GLOBALINFO_H__
#define __GLOBALINFO_H__

class GlobalInfo
{
    private:
        GlobalInfo();
        ~GlobalInfo();
        GlobalInfo(const GlobalInfo &sceneMgr);
        GlobalInfo& operator=(const GlobalInfo &sceneMgr);

    public:
        static GlobalInfo& Instance();

        bool Init();


    private:
};

#endif /* __GLOBALINFO_H__ */
