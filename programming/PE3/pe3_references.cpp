#include <iostream>

// Name:
//

// Write any functions you need here!
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
using namespace std;

class Display{
    private:
        int anum;
    public:
        void setAnum(int in){anum = in;}
        int getAnum(){return this->anum;}
        Display(){anum = 0;}
        Display(int num){
            anum = num;
        }


        Display operator +(const Display &curr){
            Display dis;
            dis.anum = this->anum+curr.anum;
            return dis;
            }

        bool operator ==(const Display &curr){
            Display check;
            if (check.anum == this->anum)
            {
                return true;
            }
            else{return false;}
        }
};


void takePoint(int *param)
{
    cout << "parameter: " << *param << endl;
    (*param)++;
}

void functionExample(int &needs_the_amp)
{
    cout << "variable passed: " << needs_the_amp << endl;
    needs_the_amp++;
}

int inoutFunction(const int &inparam, int *returnthis)
{
    *returnthis = inparam;
    cout << "*returnthis: " << *returnthis << endl;
    (*returnthis)--;
    return *returnthis;
}



int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int test = 10;
    cout << "int test = 10: " << test << endl;

    // 2) Declare a pointer to that int
    int *point = &test;
    //point should = 10
    // 3) Increment the int via the pointer
    cout << "q3 before increment: " << (test) << endl;
    (*point)++;
    cout << "test after increment: " << (test) << endl;
    // 4) Declare a reference to your int
    int &ref = test;
    cout << "current ref: " << ref << endl;
    cout << "q4 test before increment: " << test << endl;
    // 5) Increment the int via the reference
    ref++;
    cout << "test after ref increment: " << test << endl;
    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: both
    cout << "Test: " << test << endl;
    test++;
    cout << "Test+1: " << test << endl;
    cout << "Point: " << (*point) << endl;
    cout << "Reference: " << ref << endl;
    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: Both
    cout << "Pointer: " << *point << endl;
    (*point)++;
    cout << "Pointer+1: " << test << endl;
    cout << "Test: " << test << endl;
    cout << "Reference: " << ref << endl;
    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer:  both
    cout << "Ref: " << ref << endl;
    ref++;
    cout << "Ref+1: " << ref << endl;
    cout << "Point: " << *point << endl;
    cout << "Test: " << test << endl;
    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    void takePoint(int *param);
    takePoint(&test);
    cout << "test after function: " << test << endl;
    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: NO
    takePoint(&ref);
    cout << "ref after function: " << ref << endl;

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)
    void functionExample(int &needs_the_amp);
    functionExample(test);
    cout << "after the function call: " << test << endl;
    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: NO
    functionExample(*point);
    cout << "after the function call: " << *point << endl;
    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer: YES
    functionExample(ref);
    cout << "after the function call: " << ref << endl;

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.

    cout << endl << "=========================" << endl << "    onto the big ones   " << endl << "=========================" << endl << endl;



    int constref = -1;
    int *returnthis = &constref;
    int inoutFunction(const int &inparam, int *returnthis);
    int outtest = inoutFunction(constref, returnthis);
    cout << "after function call *returnthis: " << outtest << endl;

    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: Very little, it just depends on what the developer or user want the variable to do. The literal return values may not 
    //          be used again while output parameters may have more actions taken with them later in a file.

    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:
    Display five = Display(5);
    Display six = Display(6);
    Display eleven = Display();
    cout << "Obj1: " << five.getAnum() << endl;
    cout << "Obj2: " << six.getAnum() << endl;
    eleven = five + six;
    cout << "obj2 + Obj1: " << eleven.getAnum() << endl;
    cout << "are they equal? ";
    if (five == six)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

}

