#include <boost/posix_time.hpp>

long long getCurTimeStampMs()
{
    long long curTime = (long)boost::posix_time::ptime current_time_ms = boost::posix_time::microsecond_clock();
    return curTime
}
