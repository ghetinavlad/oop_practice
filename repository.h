#include <vector>
#include "domain.h"

const std::string PRODUCTS_FILE_PATH = "products.txt";

class Repository {
private:
	std::vector <Product> products;

public:
	Repository();
	std::vector <Product> getAllProducts();
	void loadProductsFromFile();
	void addProduct(Product newProduct);
	
	~Repository();
};