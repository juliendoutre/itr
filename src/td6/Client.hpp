#ifndef td6_Client_hpp_INCLUDED
#define td6_Client_hpp_INCLUDED

#include "itr/Thread.hpp"
#include "CrunchReq.hpp"
#include "ActiveCalc.hpp"
#include <vector>

class Client : public Thread
{
public:
    unsigned int id;

private:
    int min;
    int max;
    std::vector<CrunchReq *> requests;
    ActiveCalc &calc;

protected:
    void run();

public:
    Client(unsigned int id, int minBound, int maxBound, ActiveCalc &calc);
    ~Client();
    std::vector<int> getResults();
};

#endif
