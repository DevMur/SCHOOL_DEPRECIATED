#include <iostream>
#include <string>
#include <vector>

// Names: Devin
//
//


// 1) implement two functions, AddToValues(std::vector<int> v1, int v2)
// and AddToValues(std::vector<double> v1, double v2)
std::vector<int> AddToValues(std::vector<int> v1, int v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] += v2;
    }
    return v1;
}
std::vector<double> AddToValues(std::vector<double> v1, double v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] += v2;
    }
    return v1;
}
// 2) Do your AddToValues functions have return values? why/ why not?
// Answer: Yes because the changed values can be returned to manipulate. This means a temp can be sent as a parameter


int main() {
    // 3) Instantiate an int vector
    std::vector<int> vec = {1, 2, 3, 4};
    std::vector<int> solution = {2, 2, 2, 4};
    // 4) call AddToValues, passing in your int vector and another int.
    vec = AddToValues(vec, 3);


    // 5) compile this file to object code
    // g++ -std=c++17 -Wall exercises.cpp -c

    // then run the command: nm -C exercises.o | grep "AddToValues"
    // How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here: 2
    // 00000000000002e0 T AddToValues(std::__1::vector<double, std::__1::allocator<double> >, double)
    // 0000000000000000 T AddToValues(std::__1::vector<int, std::__1::allocator<int> >, int)
    //
    // If the -C flag isn't working, you can omit it and still complete the exercise--this flag
    // makes the output easier to read but isn't strictly necessary
    return 0;
}
