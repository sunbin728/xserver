#ifndef	_COMMON_H_
#define	_COMMON_H_

#include <algorithm>

struct DeletePtrs
{
    template<typename T>
        inline void operator()(const T *ptr) const
        {
            if(ptr)
                delete ptr;
        }
};


struct DeletePair
{
    template<typename Ty1, typename Ty2>
        inline void operator() (const std::pair<Ty1, Ty2> &ptr) const
        {
            if (ptr.second)
                delete ptr.second;
        }
};


#define CLEAR_MAP_DATA(m) \
std::for_each(m.begin(),m.end(),DeletePair()); \
m.clear();

#endif /* _COMMON_H_ */
