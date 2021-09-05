#ifndef ANIMAL_H
#define ANIMAL_H

// Name(s): Devin Murray
//

class Animal {
public:
	Animal(std::string sound):
	sound_(sound)
	{}

	std::string MakeSound() const {return sound_; }

	void Fight(Animal &opponent);

	virtual int GetPower() { return 0; };

private:
	std::string sound_;
};

class Reptile : public Animal {
public:
	Reptile(std::string sound):
	Animal(sound + " rawr!")
	{}


	int GetPower() { return 2; };

};

class Mammal: public Animal {
public: 
	Mammal(std::string type, std::string sound)	:	Animal(type + " " + sound){}
	int GetPower(){return 3; }
};

class Dog: public Mammal {
public:
	Dog(std::string type, std::string sound)	:	Mammal(type, sound){}
	int GetPower(){return 5; }
};
// Define your animals here.
// Define one class that inherits from Animal and
// one class that inherits from a child class of Animal

#endif ANIMAL_H
