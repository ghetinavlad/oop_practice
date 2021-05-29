#include "repository.h"
#include <fstream>

Repository::Repository() {
	;
}

std::vector <Product> Repository::getAllProducts() {
	return this->products;
}


void Repository::loadProductsFromFile() {
	const int ID_POSITION = 0;
	const int NAME_POSITION = 1;
	const int TYPE_POSITION = 2;

	std::fstream inputStream(PRODUCTS_FILE_PATH);
	std::string currentLine;

	std::string name;
	std::string type;
	int id;
	double price;

	this->products.clear();

	while (std::getline(inputStream, currentLine)) {
		int separatorPosition = currentLine.find("|");
		int propertyPosition = 0;

		while (separatorPosition != std::string::npos) {
			// subtract 1 from the separator position because there is a space between the property and the separator;
			// this substr will stop just before "separatorPosition - 1" => it will include the entire property
			// and nothing else
			std::string currentProperty = currentLine.substr(0, separatorPosition - 1);

			// add 2 to the separator position because there is a space between the separator and the next property
			// we then subtract 1 from "currentLine.length() - separatorPosition" in order to avoid that space
			currentLine = currentLine.substr(separatorPosition + 2, currentLine.length() - separatorPosition - 1);
			separatorPosition = currentLine.find("|");

			if (propertyPosition == ID_POSITION) {
				id = stoi(currentProperty);
			}
			else if (propertyPosition == NAME_POSITION) {
				name = currentProperty;
			}
			else if (propertyPosition == TYPE_POSITION) {
				type = currentProperty;
			}

			propertyPosition++;
		}

		// the last property remains outside the while loop, we treat it separately
		price = stod(currentLine);

		this->products.push_back(Product(id, name, type, price));
	}

	inputStream.close();
}


void Repository::addProduct(Product newProduct) {
	if (newProduct.getPrice() < 1 || newProduct.getPrice() > 100 || newProduct.getName() == "") {
		throw std::exception("Invalid price or name");
	}

	for (auto product : this->products) {
		if (product.getID() == newProduct.getID()) {
			throw std::exception("Product already exists");
		}
	}

	this->products.push_back(newProduct);
}

Repository::~Repository() {
	;
}