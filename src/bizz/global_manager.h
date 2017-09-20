#ifndef __GLOBALMANAGER_H__
#define __GLOBALMANAGER_H__

#include "base/pwtime.h"

class GlobalManager
{
    private:
        GlobalManager();
        ~GlobalManager();
        GlobalManager(const GlobalManager &sceneMgr);
        GlobalManager& operator=(const GlobalManager &sceneMgr);

    public:
        static GlobalManager& Instance();

        bool Init();

        inline void setPwTime(UInt64 ts,UInt32 multiple)
        {
            m_pwTime.setPwTime(ts,multiple);
        }

		inline uint64_t getPwTime()
		{
			return m_pwTime.pwNowTs();
		}

        inline uint32_t getPwTimeMultiple()
        {
            return m_pwTime._multiple;
        }

    private:
    PwTime m_pwTime;
};

#endif /* __GLOBALMANAGER_H__ */
