#include <iostream>

#include "Animal.h"

// Name(s): 

int main() {

  Reptile ralph("alligator");
  std::cout << ralph.MakeSound() << std::endl;
  
  // 1) Instantiate another animal 
  Dog spike("Husky", "Bark");
  std::cout << spike.MakeSound() << std::endl;
  // 2) Call the Fight method of animal
  //ralph.Fight(spike);
  // 3) Go to the Animal.h file and define some new subclasses of animal
  // Define one class that inherits from Animal and
  // one class that inherits from a child class of Animal

  // 4) Instantiate at least one object of each class you defined for #3
  Mammal joey("Dolphin", "click!");
  // 5) Have a tournament between the animals that you have instantiated 
  joey.Fight(ralph);
  joey.Fight(spike);
  ralph.Fight(spike);
  // 6) turn in Animal.h and main.cpp on canvas
    
	return 0;
}
