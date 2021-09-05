#include <iostream>
#include <string>
#include <vector>

// Names: Devin
//
//


// we'd like to write a function that is applicable to many types but
// we don't want to copy paste everything

// For example, here is a templated Add function
template <typename T>
T Add(T v1, T v2) {
    return v1 + v2;
}

// 6) implement a templated version of AddToValues, "AddToValues2".
template <typename T>
std::vector<T> AddToValues2(T v1, T v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i]+=v2;
    }
    return v1;
}

int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
    std::vector<int> test = {1,2,3,9,9,9};
    int add = 900;
    test = AddToValues2 <int>(test, add);
    // 8) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
// 1
// 00000000000002d0 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<std::__1::vector<int, std::__1::allocator<int> > >(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements
    std::vector<std::string> str = {"yes", "no", "maybe so"};
    str = AddToValues2 <std::string>(str, "yes");

    // 10) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of 
    // error is produced.

    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    
    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer:

    // 14) If there was an error, attempt to fix it.
}
