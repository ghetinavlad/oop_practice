#pragma once
#include <string>

class Product {
private:
	int id;
	std::string name;
	std::string type;
	double price;
	int vowels;

public:
	Product();
	Product(int id, std::string name, std::string type, double price);
	std::string toString();
	int getID() const;
	std::string getName() const;
	std::string getType() const;
	int getVowels() const;
	double getPrice() const;
};