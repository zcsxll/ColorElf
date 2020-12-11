#include "zcs_semaphore.h"

ZcsSemaphore::ZcsSemaphore()
{
}

pair<string, int> ZcsSemaphore::acquire()
{
    QSemaphore::acquire();
    mtx_.lock();
    string s = *v_s_.begin();
    v_s_.erase(v_s_.begin());
    int i = *v_i_.begin();
    v_i_.erase(v_i_.begin());
    mtx_.unlock();
    return make_pair(s, i);
}

void ZcsSemaphore::release(const string &s, int i)
{
    mtx_.lock();
    v_s_.push_back(s);
    v_i_.push_back(i);
    QSemaphore::release();
    mtx_.unlock();
}
