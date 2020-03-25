#include "itr/Request.hpp"
#include "Calculator.hpp"

class CrunchReq : public Request
{
private:
    double param, result;
    Calculator &calc;

public:
    void execute();
    double waitReturn();
};
