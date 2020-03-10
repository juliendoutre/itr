#include "PosixThread.hpp"

class Thread : public PosixThread
{
public:
    Thread();
    ~Thread();
    void start();
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();

protected:
    virtual void run() = 0;

private:
    static void *call_run(void *v_thread);
};
