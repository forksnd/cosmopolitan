// -*-mode:c++;indent-tabs-mode:nil;c-basic-offset:4;tab-width:8;coding:utf-8-*-
// vi: set et ft=cpp ts=4 sts=4 sw=4 fenc=utf-8 :vi
#ifndef CTL_MUTEX_H_
#define CTL_MUTEX_H_
#include "libc/thread/thread.h"

namespace ctl {

class mutex
{
  public:
    mutex()
    {
        pthread_mutex_init(&m_, nullptr);
    }

    ~mutex()
    {
        pthread_mutex_destroy(&m_);
    }

    void lock()
    {
        pthread_mutex_lock(&m_);
    }

    bool try_lock()
    {
        return pthread_mutex_trylock(&m_) == 0;
    }

    void unlock()
    {
        pthread_mutex_unlock(&m_);
    }

    // Delete copy constructor and assignment operator
    mutex(const mutex&) = delete;
    mutex& operator=(const mutex&) = delete;

  private:
    pthread_mutex_t m_;
};

} // namespace ctl

#endif // CTL_MUTEX_H_