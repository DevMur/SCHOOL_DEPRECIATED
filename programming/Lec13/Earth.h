#ifndef EARTH_H
#define EARTH_H


class Earth {
public:
	
	static Earth& GetInstance() {
		// gets instantiated the first time
		static Earth instance; // guaranteed to be destroyed

		return instance;
	}

    int get_population() { return population_; };

    void IncreasePopulation() { population_ += 1; };

	// Delete the methods we don't want
	Earth(Earth const&) = delete; // copy constructor
	void operator=(Earth const&) = delete; // assignment operator
	int radius; //public field
	static const int NUM_CONTINENTS; //static constant public field
 private:
 	Earth();  // private constructor

    int population_;
  
};  // class Earth

#endif  // EARTH_H

