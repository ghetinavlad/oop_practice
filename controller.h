#pragma once
#include "repository.h"
#include <vector>
#include "Subject.h"

class Controller : public Subject {
private:
	Repository repository;
	int sliderValue = 0;

public:
	Controller();
	std::vector<Product> getAllProducts();
	std::vector<Product> getAllProductsByPrice(int price);
	void loadProductsFromFile();
	void addProduct(int id, std::string name, std::string type, double price);
	int getSliderValue();
	int getTypeCounter(std::string type);
	void setSliderValue(int value);
	~Controller();
};