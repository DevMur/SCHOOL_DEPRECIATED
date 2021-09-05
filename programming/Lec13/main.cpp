#include <iostream>
#include "Earth.h"

// Names: Devin Murray
//

int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp
    //fin
    // 1) Get an instance of your earth object
    Earth &first = Earth::GetInstance();
    // 2) Get another instance of your earth object
    Earth &second = Earth::GetInstance();
    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory. YES they are stored in the same place. Incrementing one increments
    // the other.
    std::cout << "Memory location of first planet: " << &first << std::endl;
    std::cout << "Memory location of second planet: " << &second << std::endl;
    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance? YES
    first.IncreasePopulation();
    std::cout << "Population of planet 1: " << first.get_population() << std::endl;
    std::cout << "Population of planet 2: " << second.get_population() << std::endl;
    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?
    //Earth third = first;
    //std::cout << radius << std::endl;
    std::cout << "Radius using public field: " << first.radius << std::endl;
    std::cout << "Number of continents: " << Earth::NUM_CONTINENTS << std::endl;
	return 0;
}
