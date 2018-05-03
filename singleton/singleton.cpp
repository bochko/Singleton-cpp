#include "singleton.hpp"

bochko::patterns::singleton* bochko::patterns::singleton::instance = nullptr;

bochko::patterns::singleton::singleton() = default;

bochko::patterns::singleton::~singleton() {
	if (bochko::patterns::singleton::instance == nullptr) return;
	delete bochko::patterns::singleton::instance;
}

bochko::patterns::singleton *bochko::patterns::singleton::get_instance() {
	if (bochko::patterns::singleton::instance == nullptr) {
		bochko::patterns::singleton::instance = new singleton();
	}
	return bochko::patterns::singleton::instance;
}


