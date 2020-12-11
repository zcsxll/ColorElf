#ifndef ZCSSEMAPHORE_H
#define ZCSSEMAPHORE_H

#include <QSemaphore>
#include <QMutex>

#include <vector>
#include <string>

using namespace std;

class ZcsSemaphore : public QSemaphore
{
private:
    QMutex mtx_;
    vector<string> v_s_;
    vector<int> v_i_;

public:
    ZcsSemaphore();
    pair<string, int> acquire();
    void release(const string &s, int i);
};

#endif // ZCSSEMAPHORE_H
