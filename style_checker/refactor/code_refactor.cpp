//Poprawić kod, używając clang-refactor
#include <vector>
#include <iostream>

int
            main (    int argc, char *argv[]) {
                    std::vector<int> v;
        v.push_back(34);
    for (auto      & elem : v) 
{
        std::cout << elem;          }
    return 0;
}

