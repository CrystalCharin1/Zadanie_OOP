#ifndef WAGON_H	
#define WAGON_H

#include <string>

class Wagon {
	std::string type;
public:
	Wagon(const std::string t);
	std::string getType() const;
};

#endif
