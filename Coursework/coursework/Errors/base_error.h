#ifndef BASEERROR_H
#define BASEERROR_H

#include <exception>
#include <string>
#include <time.h>

using namespace std;

namespace  error{

class BaseError : public exception
{
public:
    BaseError(string filename, string classname, int num_line, string msg);
    virtual ~BaseError() override;

    virtual const char* what() const noexcept override;
protected:
    string errormsg;
};

}

#endif // BASEERROR_H
