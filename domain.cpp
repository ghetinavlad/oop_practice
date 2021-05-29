#include "domain.h"

Product::Product() {
	this->id = 0;
	this->name = "";
	this->type = "";
	this->price = 0;
	this->vowels = 0;
}

Product::Product(int id, std::string name, std::string type, double price) {
	this->id = id;
	this->name = name;
	this->type = type;
	this->price = price;
	this->vowels = 0;
	for (int i = 0; i < name.size(); i++)
		if (this->name[i] == 'a' || this->name[i] == 'e' ||
			this->name[i] == 'i' || this->name[i] == 'o' || this->name[i] == 'u')
			this->vowels++;


}

std::string Product::toString() {
	std::string representation;

	representation += (std::to_string(this->id) + " | ");
	representation += (this->name + " | ");
	representation += (this->type + " | ");
	representation += (std::to_string(this->price) + " | ");
	representation += (std::to_string(this->vowels));

	return representation;
}

std::string Product::getName() const {
	return this->name;
}

int Product::getID() const {
	return this->id;
}

std::string Product::getType() const {
	return this->type;
}

double Product::getPrice() const {
	return this->price;
}

int Product::getVowels() const {
	return this->vowels;
}


