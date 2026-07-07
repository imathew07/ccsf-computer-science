// Mateo Sanchez Sinche, CS 110C

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
    explicit PrecondViolatedExcep(const string& message = "");
};

#endif