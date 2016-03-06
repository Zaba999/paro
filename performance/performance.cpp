//Przeanalizować wydajność za pomocą valgrind'a - valgrind--tool=callgrind --help
//(opcjonalnie)Przeanalizować wydajność za pomocą perf'a+FlameGrapha'a - perf record -F 99 -p [PID] -g --sleep 2
//Flamegraph do pobrania https://github.com/brendangregg/FlameGraph.git
#include <iostream>
#include <memory>
#include <fstream>
#include <stdlib.h>

class BaseClass
{
public:
    void fastFunction()
    {
        for (size_t i = 0; i < 20; ++i)
        {
            std::cout << i << std::endl;
        }
    }

    virtual ~BaseClass(){}

    size_t timeConsumingJob()
    {
        size_t result;

        if (result > 0)
        {
            result = 0;
        }

        for (size_t i = 0; i < 300; ++i)
        {
            result += i;
        }

        if (true)
        {
            ++result;
        }

        return result;
    }
};


class SpecialClass : public BaseClass
{
public:
    SpecialClass()
    {
        char * privMember = new char[10];
        void * uninti = new int[10];
    }

    virtual ~SpecialClass()
    {
        // delete privMember;
    }

private:
    char * privMember;
};






int executeMainLoop()
{
    BaseClass * base = new SpecialClass;
    base->fastFunction();
    return (base->timeConsumingJob() > 0)? 0 : -1;
}


int main(int argc, char *argv[])
{
    int retval = 0;
    for(size_t i = 0; i < 1000; ++i)
    {
        retval = executeMainLoop();
    }

    int i = 0;
    return i + 2 + retval;
}
