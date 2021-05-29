#pragma once
#include "controller.h"
#include <algorithm>
#include <fstream>

Controller::Controller() {
	;
}

std::vector <Product> Controller::getAllProducts() {
	std::vector<Product>allProducts = this->repository.getAllProducts();
	sort(allProducts.begin(), allProducts.end(), [](Product first, Product second)
		{

			return first.getPrice() < second.getPrice();

		}
	);
	return allProducts;
}

std::vector<Product> Controller::getAllProductsByPrice(int price ) {
	std::vector<Product> allProducts = this->repository.getAllProducts();
	std::vector<Product> filteredProducts;
	for (auto product : allProducts) {
		if (product.getPrice() >= price) { 
			filteredProducts.push_back(product);
		}
	}

	sort(filteredProducts.begin(), filteredProducts.end(), [](Product first, Product second)
		{

			return first.getPrice() < second.getPrice();

		}
	);
	return filteredProducts;
}


void Controller::loadProductsFromFile() {
	this->repository.loadProductsFromFile();
}

void Controller::addProduct(int id , std::string name, std::string type, double price) {

	this->repository.addProduct(Product(id, name , type, price));
}

int Controller::getSliderValue() {
	return this->sliderValue;
}

void Controller::setSliderValue(int value) {
	this->sliderValue = value;
}

int Controller::getTypeCounter(std::string type) {
	int counter = 0;

	std::vector<Product>allProducts = this->repository.getAllProducts();
	for (auto product : allProducts) {
		if (product.getType() == type)
			counter++;
	}

	return counter;
}


Controller::~Controller() {
	
}